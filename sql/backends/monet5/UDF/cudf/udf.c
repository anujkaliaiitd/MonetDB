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

#define OVECCOUNT 30
#define WORCOUNT 100
#define EBUFLEN 128
#define BUFLEN 1024

#include <math.h>
#include <time.h>

#define COUNT_PARTITIONS true
// pthread_lock

#define TIME_TYPE clock_t
#define GET_TIME(res) \
  { res = clock(); }
#define TIME_DIFF_IN_MS(begin, end) \
  (((double)(end - start)) * 1000 / CLOCKS_PER_SEC)

#define MEASURE_TIME() ((rand() & 65535) == 65535)
#define DEBUG false

double total_time = 0;
time_t last_update_time = 0;
atomic_int acnt;

void reset_total_time() {
  if (last_update_time == 0) {
    last_update_time = time(NULL);
    return;
  }
  time_t start = time(NULL);
  double interval = (double)(start - last_update_time);
  if (interval > 2) {
    if (DEBUG) {
      printf("reset time with interval %7.7f\n", interval);
    }
    total_time = 0;
    acnt = 0;
    last_update_time = start;
  }
}

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

  /* assert calling sanity */
  assert(ret != NULL);

  /* handle NULL pointer */
  if (src == NULL)
    throw(MAL, "batudf.hyperscanregex", SQLSTATE(HY002) RUNTIME_OBJECT_MISSING);

  /* check tail type */
  if (src->ttype != TYPE_str) {
    throw(MAL, "batudf.hyperscanregex",
          "tail-type of input BAT must be TYPE_str");
  }

  /* allocate void-headed result BAT */
  bn = COLnew(src->hseqbase, TYPE_int, BATcount(src), TRANSIENT);
  if (bn == NULL) {
    throw(MAL, "batudf.hyperscanregex", SQLSTATE(HY001) MAL_MALLOC_FAIL);
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
    int subject_len = strlen(t);
    TIME_TYPE start = 0, end = 0;

    int measure_time = DEBUG && MEASURE_TIME();
    if (measure_time) {
      GET_TIME(start);
    }

    // matching a 64-byte text against pattern: 200 cycles. 60 ns.
    if (hs_scan(database, t, subject_len, 0, scratch, eventHandler, tr) !=
        HS_SUCCESS) {
      hs_free_scratch(scratch);
      hs_free_database(database);
      throw(MAL, "udf.hyperscanregex", "Unable to scan input buffer\n");
    }
    if (measure_time) {
      GET_TIME(end);
      total_time += TIME_DIFF_IN_MS(start, end);
      last_update_time = time(NULL);
      // printf("hyperscan time spend %7.7f\n", total_time);
    }

    err = MAL_SUCCEED;
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
      throw(MAL, "batudf.hyperscanregex", SQLSTATE(HY001) MAL_MALLOC_FAIL);
    }
  }

  /* free memory allocated in UDFreverse_() */
  free(tr);

  *ret = bn;
  return MAL_SUCCEED;
}

/* MAL wrapper */
char *UDFBAThyperscanregex(bat *ret, const bat *arg, const char **pattern) {
  reset_total_time();
  BAT *res = NULL, *src = NULL;
  char *msg = NULL;
  pcre *re = NULL;
  const char *error;
  int erroffset;

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

/* Reverse a string */

/* actual implementation */
/* all non-exported functions must be declared static */
static char *UDFreverse_(char **ret, const char *src) {
  size_t len = 0;
  char *dst = NULL;

  /* assert calling sanity */
  assert(ret != NULL);

  /* handle NULL pointer and NULL value */
  if (src == NULL || strcmp(src, str_nil) == 0) {
    *ret = GDKstrdup(str_nil);
    if (*ret == NULL)
      throw(MAL, "udf.reverse", "failed to create copy of str_nil");

    return MAL_SUCCEED;
  }

  /* allocate result string */
  len = strlen(src);
  *ret = dst = GDKmalloc(len + 1);
  if (dst == NULL)
    throw(MAL, "udf.reverse", "failed to allocate string of length " SZFMT,
          len + 1);

  /* copy characters from src to dst in reverse order */
  dst[len] = 0;
  while (len > 0) {
    *dst++ = src[--len];
  }
  return MAL_SUCCEED;
}

/* MAL wrapper */
char *UDFreverse(char **ret, const char **arg) {
  /* assert calling sanity */
  assert(ret != NULL && arg != NULL);

  return UDFreverse_(ret, *arg);
}

char *UDFregex_(int *ret, const char *src, pcre *re, int dfa) {
  int ovector[OVECCOUNT];
  int rc = -1;

  if (re == NULL) {
    throw(MAL, "udf.regex", "PCRE compilation failed");
  }

  TIME_TYPE start = 0, end = 0;
  int measure_time = DEBUG && MEASURE_TIME();

  if (measure_time) GET_TIME(start);

  if (dfa == 0)
    rc = pcre_exec(re, NULL, src, strlen(src), 0, 0, ovector, OVECCOUNT);
  else {
    int workspace[WORCOUNT];
    rc = pcre_dfa_exec(re, NULL, src, strlen(src), 0, PCRE_DFA_SHORTEST,
                       ovector, OVECCOUNT, workspace, WORCOUNT);
  }

  if (measure_time) {
    GET_TIME(end);
    double time_spend = TIME_DIFF_IN_MS(start, end);
    total_time += time_spend;
    last_update_time = time(NULL);
    // printf("pcre time spend %7.7f\n", total_time);
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

/************** ADD by me ***********/
/* actual implementation */
static char *UDFBATregex_(BAT **ret, BAT *src, pcre *re, int dfa) {
  BATiter li;
  BAT *bn = NULL;
  BUN p = 0, q = 0;
  acnt++;
  if (DEBUG) {
    printf("count and total partition up to now %d\n", acnt);
  }

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
  int cnt = 0;
  /* the core of the algorithm, expensive due to malloc/frees */
  BATloop(src, p, q) {
    char *err = NULL;
    cnt++;
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
  reset_total_time();
  return UDFBATcommenregex_(ret, arg, pattern, 0);
}

char *UDFBATdfaregex(bat *ret, const bat *arg, const char **pattern) {
  reset_total_time();
  return UDFBATcommenregex_(ret, arg, pattern, 1);
}

/***********/

/* Reverse a BAT of strings */
/*
 * Generic "type-oblivious" version,
 * using generic "type-oblivious" BAT access interface.
 */

/* actual implementation */
static char *UDFBATreverse_(BAT **ret, BAT *src) {
  BATiter li;
  BAT *bn = NULL;
  BUN p = 0, q = 0;

  /* assert calling sanity */
  assert(ret != NULL);

  /* handle NULL pointer */
  if (src == NULL)
    throw(MAL, "batudf.reverse", SQLSTATE(HY002) RUNTIME_OBJECT_MISSING);

  /* check tail type */
  if (src->ttype != TYPE_str) {
    throw(MAL, "batudf.reverse", "tail-type of input BAT must be TYPE_str");
  }

  /* allocate void-headed result BAT */
  bn = COLnew(src->hseqbase, TYPE_str, BATcount(src), TRANSIENT);
  if (bn == NULL) {
    throw(MAL, "batudf.reverse", SQLSTATE(HY001) MAL_MALLOC_FAIL);
  }

  /* create BAT iterator */
  li = bat_iterator(src);

  /* the core of the algorithm, expensive due to malloc/frees */
  BATloop(src, p, q) {
    char *tr = NULL, *err = NULL;

    const char *t = (const char *)BUNtail(li, p);

    /* revert tail value */
    err = UDFreverse_(&tr, t);
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
      throw(MAL, "batudf.reverse", SQLSTATE(HY001) MAL_MALLOC_FAIL);
    }

    /* free memory allocated in UDFreverse_() */
    GDKfree(tr);
  }

  *ret = bn;

  return MAL_SUCCEED;
}

/* MAL wrapper */
char *UDFBATreverse(bat *ret, const bat *arg) {
  BAT *res = NULL, *src = NULL;
  char *msg = NULL;

  /* assert calling sanity */
  assert(ret != NULL && arg != NULL);

  /* bat-id -> BAT-descriptor */
  if ((src = BATdescriptor(*arg)) == NULL)
    throw(MAL, "batudf.reverse", SQLSTATE(HY002) RUNTIME_OBJECT_MISSING);

  /* do the work */
  msg = UDFBATreverse_(&res, src);

  /* release input BAT-descriptor */
  BBPunfix(src->batCacheid);

  if (msg == MAL_SUCCEED) {
    /* register result BAT in buffer pool */
    BBPkeepref((*ret = res->batCacheid));
  }

  return msg;
}

/* fuse */

/* instantiate type-specific functions */

#define UI bte
#define UU unsigned char
#define UO sht
#include "udf_impl.h"
#undef UI
#undef UU
#undef UO

#define UI sht
#define UU unsigned short
#define UO int
#include "udf_impl.h"
#undef UI
#undef UU
#undef UO

#define UI int
#define UU unsigned int
#define UO lng
#include "udf_impl.h"
#undef UI
#undef UU
#undef UO

#ifdef HAVE_HGE
#define UI lng
#ifdef HAVE_LONG_LONG
#define UU unsigned long long
#else
#ifdef HAVE___INT64
#define UU unsigned __int64
#endif
#endif
#define UO hge
#include "udf_impl.h"
#undef UI
#undef UU
#undef UO
#endif

/* BAT fuse */

/* actual implementation */
static char *UDFBATfuse_(BAT **ret, const BAT *bone, const BAT *btwo) {
  BAT *bres = NULL;
  bit two_tail_sorted_unsigned = FALSE;
  bit two_tail_revsorted_unsigned = FALSE;
  BUN n;
  char *msg = NULL;

  /* assert calling sanity */
  assert(ret != NULL);

  /* handle NULL pointer */
  if (bone == NULL || btwo == NULL)
    throw(MAL, "batudf.fuse", SQLSTATE(HY002) RUNTIME_OBJECT_MISSING);

  /* check for aligned heads */
  if (BATcount(bone) != BATcount(btwo) || bone->hseqbase != btwo->hseqbase) {
    throw(MAL, "batudf.fuse", "heads of input BATs must be aligned");
  }
  n = BATcount(bone);

  /* check tail types */
  if (bone->ttype != btwo->ttype) {
    throw(MAL, "batudf.fuse", "tails of input BATs must be identical");
  }

  /* allocate result BAT */
  switch (bone->ttype) {
    case TYPE_bte:
      bres = COLnew(bone->hseqbase, TYPE_sht, n, TRANSIENT);
      break;
    case TYPE_sht:
      bres = COLnew(bone->hseqbase, TYPE_int, n, TRANSIENT);
      break;
    case TYPE_int:
      bres = COLnew(bone->hseqbase, TYPE_lng, n, TRANSIENT);
      break;
#ifdef HAVE_HGE
    case TYPE_lng:
      bres = COLnew(bone->hseqbase, TYPE_hge, n, TRANSIENT);
      break;
#endif
    default:
      throw(MAL, "batudf.fuse",
            "tails of input BATs must be one of {bte, sht, int"
#ifdef HAVE_HGE
            ", lng"
#endif
            "}");
  }
  if (bres == NULL) throw(MAL, "batudf.fuse", SQLSTATE(HY001) MAL_MALLOC_FAIL);

  /* call type-specific core algorithm */
  switch (bone->ttype) {
    case TYPE_bte:
      msg = UDFBATfuse_bte_sht(bres, bone, btwo, n, &two_tail_sorted_unsigned,
                               &two_tail_revsorted_unsigned);
      break;
    case TYPE_sht:
      msg = UDFBATfuse_sht_int(bres, bone, btwo, n, &two_tail_sorted_unsigned,
                               &two_tail_revsorted_unsigned);
      break;
    case TYPE_int:
      msg = UDFBATfuse_int_lng(bres, bone, btwo, n, &two_tail_sorted_unsigned,
                               &two_tail_revsorted_unsigned);
      break;
#ifdef HAVE_HGE
    case TYPE_lng:
      msg = UDFBATfuse_lng_hge(bres, bone, btwo, n, &two_tail_sorted_unsigned,
                               &two_tail_revsorted_unsigned);
      break;
#endif
    default:
      BBPunfix(bres->batCacheid);
      throw(MAL, "batudf.fuse",
            "tails of input BATs must be one of {bte, sht, int"
#ifdef HAVE_HGE
            ", lng"
#endif
            "}");
  }

  if (msg != MAL_SUCCEED) {
    BBPunfix(bres->batCacheid);
  } else {
    /* set number of tuples in result BAT */
    BATsetcount(bres, n);

    /* Result tail is sorted, if the left/first input tail is
     * sorted and key (unique), or if the left/first input tail is
     * sorted and the second/right input tail is sorted and the
     * second/right tail values are either all >= 0 or all < 0;
     * otherwise, we cannot tell.
     */
    if (BATtordered(bone) && (BATtkey(bone) || two_tail_sorted_unsigned))
      bres->tsorted = 1;
    else
      bres->tsorted = (BATcount(bres) <= 1);
    if (BATtrevordered(bone) && (BATtkey(bone) || two_tail_revsorted_unsigned))
      bres->trevsorted = 1;
    else
      bres->trevsorted = (BATcount(bres) <= 1);
    /* result tail is key (unique), iff both input tails are */
    BATkey(bres, BATtkey(bone) || BATtkey(btwo));

    *ret = bres;
  }

  return msg;
}

/* MAL wrapper */
char *UDFBATfuse(bat *ires, const bat *ione, const bat *itwo) {
  BAT *bres = NULL, *bone = NULL, *btwo = NULL;
  char *msg = NULL;

  /* assert calling sanity */
  assert(ires != NULL && ione != NULL && itwo != NULL);

  /* bat-id -> BAT-descriptor */
  if ((bone = BATdescriptor(*ione)) == NULL)
    throw(MAL, "batudf.fuse", SQLSTATE(HY002) RUNTIME_OBJECT_MISSING);

  /* bat-id -> BAT-descriptor */
  if ((btwo = BATdescriptor(*itwo)) == NULL) {
    BBPunfix(bone->batCacheid);
    throw(MAL, "batudf.fuse", SQLSTATE(HY002) RUNTIME_OBJECT_MISSING);
  }

  /* do the work */
  msg = UDFBATfuse_(&bres, bone, btwo);

  /* release input BAT-descriptors */
  BBPunfix(bone->batCacheid);
  BBPunfix(btwo->batCacheid);

  if (msg == MAL_SUCCEED) {
    /* register result BAT in buffer pool */
    BBPkeepref((*ires = bres->batCacheid));
  }

  return msg;
}
