/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0.  If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * Copyright 1997 - July 2008 CWI, August 2008 - 2017 MonetDB B.V.
 */

/* monetdb_config.h must be the first include in each .c file */
#include "monetdb_config.h"
#include "udf.h"
#include <hs/hs.h>
#include <pcre.h>
#include <stdio.h>
#include <stdatomic.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define OVECCOUNT 30
#define WORCOUNT 100

#define BATCH_SIZE 8

/*******************/
static int eventHandler(unsigned int id, unsigned long long from,
                        unsigned long long to, unsigned int flags, void *ctx) {
  int *cur = (int *)ctx;
  *cur = 1;
  return 0;
}

static char *UDFBAThyperscanregex_(BAT **ret, BAT *src, hs_database_t *database,
                                   hs_scratch_t *scratch) {
  BATiter li;
  BAT *bn = NULL;
  BUN p = 0, q = 0;

  // allocate void-headed result BAT
  int len = BATcount(src);
  bn = COLnew(src->hseqbase, TYPE_int, len, TRANSIENT);

  // create BAT iterator
  li = bat_iterator(src);
  int *tr = GDKmalloc(sizeof *tr);
  int *res = NULL;
  res = (int *)Tloc(bn, 0);

  int i = 0;

  BATloop(src, p, q) {
    char *err = NULL;
    const char *t = (const char *)BUNtail(li, p);
    // revert tail value
    *tr = 0;
    int subject_len = strlen(t);
    if (hs_scan(database, t, subject_len, 0, scratch, eventHandler, tr) !=
        HS_SUCCESS) {
      hs_free_scratch(scratch);
      hs_free_database(database);
      throw(MAL, "udf.hyperscanregex", "Unable to scan input buffer\n");
    }
    // append reversed tail in result BAT
    res[i++] = *tr;
  }

  BATsetcount(bn, len);
  bn->tsorted = FALSE;
  bn->trevsorted = FALSE;
  bn->tdense = FALSE;
  BATkey(bn, FALSE);
  GDKfree(tr);
  *ret = bn;
  return MAL_SUCCEED;
}

/* MAL wrapper */
char *UDFBAThyperscanregex(bat *ret, const bat *arg, const char **pattern) {
  BAT *res = NULL, *src = NULL;
  char *msg = NULL;
  pcre *re = NULL;
  const char *error;
  int erroffset;

  // Check size of BAT
  /* assert calling sanity */
  assert(ret != NULL && arg != NULL && pattern != NULL);

  /* bat-id -> BAT-descriptor */
  if ((src = BATdescriptor(*arg)) == NULL)
    throw(MAL, "batudf.hyperscanregex", SQLSTATE(HY002) RUNTIME_OBJECT_MISSING);

  hs_database_t *database;
  hs_compile_error_t *compile_err;

  if (hs_compile(*pattern,
                 HS_FLAG_SINGLEMATCH | HS_FLAG_PREFILTER | HS_FLAG_DOTALL,
                 HS_MODE_BLOCK, NULL, &database, &compile_err) != HS_SUCCESS) {
    hs_free_compile_error(compile_err);
    throw(MAL, "udf.hyperscanregx", "Unable to compile pattern");
  }

  hs_scratch_t *scratch = NULL;
  if (hs_alloc_scratch(database, &scratch) != HS_SUCCESS) {
    hs_free_database(database);
    throw(MAL, "udf.hyperscanregex", "Uable to allocate scratch space\n");
  }

  /* do the work */
  msg = UDFBAThyperscanregex_(&res, src, database, scratch);

  hs_free_scratch(scratch);
  hs_free_database(database);

  /* release input BAT-descriptor */
  BBPunfix(src->batCacheid);

  if (msg == MAL_SUCCEED) {
    /* register result BAT in buffer pool */
    BBPkeepref((*ret = res->batCacheid));
  }

  return msg;
}

/***********************************/

/* actual implementation */
/* all non-exported functions must be declared static */

char *UDFregex_(int *ret, const char *src, pcre *re, int dfa) {
  int ovector[OVECCOUNT];
  int rc = -1;

  if (re == NULL) {
    throw(MAL, "udf.regex", "PCRE compilation failed");
  }

  if (dfa == 0) {
    rc = pcre_exec(re, NULL, src, strlen(src), 0, 0, ovector, OVECCOUNT);
  } else {
    int workspace[WORCOUNT];
    rc = pcre_dfa_exec(re, NULL, src, strlen(src), 0, PCRE_DFA_SHORTEST,
                       ovector, OVECCOUNT, workspace, WORCOUNT);
  }

  if (rc < 0) {
    if (rc == PCRE_ERROR_NOMATCH)
      *ret = 0;
    else {
      pcre_free(re);
      throw(MAL, "udf.regex", "match pattern is error");
    }
  } else
    *ret = 1;

  return MAL_SUCCEED;
}

/* actual implementation */
static char *UDFBATregex_(BAT **ret, BAT *src, pcre *re, int dfa) {
  BATiter li;
  BAT *bn = NULL;
  BUN p = 0, q = 0;

  /* assert calling sanity */
  assert(ret != NULL);

  /* handle NULL pointer */
  if (src == NULL)
    throw(MAL, "batudf.regex", SQLSTATE(HY002) RUNTIME_OBJECT_MISSING);

  /* check tail type */
  if (src->ttype != TYPE_str) {
    throw(MAL, "batudf.regex", "tail-type of input BAT must be TYPE_str");
  }

  /* allocate void-headed result BAT */
  bn = COLnew(src->hseqbase, TYPE_int, BATcount(src), TRANSIENT);
  if (bn == NULL) {
    throw(MAL, "batudf.regex", SQLSTATE(HY001) MAL_MALLOC_FAIL);
  }

  /* create BAT iterator */
  li = bat_iterator(src);
  int *tr = malloc(sizeof *tr);
  /* the core of the algorithm, expensive due to malloc/frees */
  BATloop(src, p, q) {
    char *err = NULL;
    const char *t = (const char *)BUNtail(li, p);
    /* revert tail value */
    *tr = 0;
    err = UDFregex_(tr, t, re, dfa);

    if (err != MAL_SUCCEED) {
      /* error -> bail out */
      BBPunfix(bn->batCacheid);
      return err;
    }

    /* assert logical sanity */
    assert(tr != NULL);

    /* append reversed tail in result BAT */
    if (BUNappend(bn, tr, FALSE) != GDK_SUCCEED) {
      BBPunfix(bn->batCacheid);
      throw(MAL, "batudf.regex", SQLSTATE(HY001) MAL_MALLOC_FAIL);
    }
  }

  /* free memory allocated in UDFreverse_() */
  free(tr);

  *ret = bn;

  return MAL_SUCCEED;
}

/* MAL wrapper */
static char *UDFBATcommenregex_(bat *ret, const bat *arg, const char **pattern,
                                int dfa) {
  BAT *res = NULL, *src = NULL;
  char *msg = NULL;
  pcre *re = NULL;
  const char *error;
  int erroffset;

  /* assert calling sanity */
  assert(ret != NULL && arg != NULL);

  /* bat-id -> BAT-descriptor */
  if ((src = BATdescriptor(*arg)) == NULL)
    throw(MAL, "batudf.regex", SQLSTATE(HY002) RUNTIME_OBJECT_MISSING);

  re = pcre_compile(*pattern, 0, &error, &erroffset, NULL);

  /* do the work */
  msg = UDFBATregex_(&res, src, re, dfa);

  /* release input BAT-descriptor */
  BBPunfix(src->batCacheid);

  if (msg == MAL_SUCCEED) {
    /* register result BAT in buffer pool */
    BBPkeepref((*ret = res->batCacheid));
  }

  return msg;
}

char *UDFBATregex(bat *ret, const bat *arg, const char **pattern) {
  return UDFBATcommenregex_(ret, arg, pattern, 0);
}

char *UDFBATdfaregex(bat *ret, const bat *arg, const char **pattern) {
  return UDFBATcommenregex_(ret, arg, pattern, 1);
}

char *UDFlvzixun_regex(int *ret, const char **rule, const char **source) {
  assert(ret != NULL && rule != NULL && source != NULL);
  struct reg_env *lvzixun_env = reg_open_env();
  struct fast_dfa_t *fast_dfa = lvzixun_regex_get_fast_dfa(lvzixun_env, *rule);
  *ret = 0;
  *ret = lvzixun_fast_dfa_reg_match(fast_dfa, *source);
  reg_close_env(lvzixun_env);
  return MAL_SUCCEED;
}

static char *UDFBATlvzixun_single_regex_(BAT **ret, BAT *src,
                                         struct fast_dfa_t *re) {
  BATiter li;
  BAT *bn = NULL;
  BUN p = 0, q = 0;

  int len = BATcount(src);
  bn = COLnew(src->hseqbase, TYPE_int, BATcount(src), TRANSIENT);

  li = bat_iterator(src);
  int tr = 0;
  int *res = NULL;
  res = (int *)Tloc(bn, 0);
  int i = 0;

  BATloop(src, p, q) {
    char *err = NULL;
    const char *t = (const char *)BUNtail(li, p);
    tr = 0;
    tr = lvzixun_fast_dfa_reg_match(re, t);
    res[i++] = tr;
  }

  BATsetcount(bn, len);
  bn->tsorted = FALSE;
  bn->trevsorted = FALSE;
  bn->tdense = FALSE;
  BATkey(bn, FALSE);

  *ret = bn;
  return MAL_SUCCEED;
}

static char *UDFBATlvzixun_regex_(BAT **ret, BAT *src, struct fast_dfa_t *re) {
  const int kOnlySum = 0;

  BATiter li;
  BAT *bn = NULL;
  BUN p = 0, q = 0;

  int len = BATcount(src);
  bn = COLnew(src->hseqbase, TYPE_int, BATcount(src), TRANSIENT);

  li = bat_iterator(src);
  int tr = 0;
  int *res = NULL;
  res = (int *)Tloc(bn, 0);
  int i = 0, j = 0;

  char *source_batch[BATCH_SIZE];
  int bat_ret[BATCH_SIZE];

  for (q = BATcount(src), p = 0; p < q; p++) {
    char *err = NULL;
    const char *t = (const char *)BUNtail(li, p);

    if (kOnlySum == 0) {
      // Do pattern match
      __builtin_prefetch(t, 0, 2);
      source_batch[i & 7] = (char *)t;
      if ((i & 7) == 7) {
        // lvzixun_fast_dfa_state_match_batch_same_len(re, source_batch, bat_ret);
        lvzixun_fast_dfa_reg_match_batch(re, source_batch, bat_ret);
        int idx_start = (i >> 3) << 3;
        for (int j = 0; j < BATCH_SIZE; j++) {
          res[idx_start + j] = bat_ret[j];
        }
      }
    } else {
      // Just sum up the string
      int t_idx = 0;
      res[i] = 0;
      while (t[t_idx] != 0) {
        res[i]++;
        t_idx++;
      }

      // Set around 20% of res[i] to true so that we do similar work.
      if (res[i] > 0) {
        // res[i] > 0 is to force the compiler to do the above computation.
        // It's always true.
        res[i] = ((i % 1024) < 200);
      }
    }
    i++;
  }

  if (kOnlySum == 0) {
    // lvzixun_fast_dfa_state_match_batch_same_len(re, source_batch, bat_ret);
    lvzixun_fast_dfa_reg_match_batch(re, source_batch, bat_ret);
    int idx_start = i / 8 * 8;
    for (int j = 0; j < BATCH_SIZE && idx_start + j < i; j++) {
      res[idx_start + j] = bat_ret[j];
    }
  }

  BATsetcount(bn, len);
  bn->tsorted = FALSE;
  bn->trevsorted = FALSE;
  bn->tdense = FALSE;
  BATkey(bn, FALSE);

  *ret = bn;
  return MAL_SUCCEED;
}

char *UDFBATlvzixun_regex(bat *ret, const bat *arg, const char **pattern) {
  BAT *res = NULL, *src = NULL;
  char *msg = NULL;
  const char *error;
  int erroffset;

  assert(ret != NULL && arg != NULL);

  if ((src = BATdescriptor(*arg)) == NULL)
    throw(MAL, "batudf.lvzixun_regex", SQLSTATE(HY002) RUNTIME_OBJECT_MISSING);

  struct reg_env *lvzixun_env = reg_open_env();
  struct fast_dfa_t *re = lvzixun_regex_get_fast_dfa(lvzixun_env, *pattern);

  msg = UDFBATlvzixun_regex_(&res, src, re);

  // msg = UDFBATlvzixun_single_regex_(&res, src, re);
  reg_close_env(lvzixun_env);

  BBPunfix(src->batCacheid);
  if (msg == MAL_SUCCEED) {
    BBPkeepref((*ret = res->batCacheid));
  }
  return msg;
}
