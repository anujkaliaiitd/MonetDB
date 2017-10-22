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

#define OVECCOUNT 30
#define WORCOUNT 100
#define EBUFLEN 128
#define BUFLEN 1024
#define COUNT_PARTITIONS true
#define MEASURE_TIME() ((rand() & 65535) == 65535)
#define DEBUG false

double total_time = 0;
time_t last_update_time = 0;
atomic_int acnt;

void get_time(struct timespec *start) {
  if (!DEBUG) return;
  clock_gettime(CLOCK_REALTIME, start);
}

void time_diff(struct timespec start, char *cmd) {
  struct timespec end;
  get_time(&end);
  if (!DEBUG) return;
  size_t tot_ns =
      (end.tv_sec - start.tv_sec) * 1000000000 + (end.tv_nsec - start.tv_nsec);
  printf("%s Overhead: Time per measurement = %.2f ns\n", cmd, (double)tot_ns);
}


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
  struct timespec fast_start;

  // assert calling sanity
  assert(ret != NULL);

  // handle NULL pointer
  if (src == NULL)
    throw(MAL, "batudf.hyperscanregex", SQLSTATE(HY002) RUNTIME_OBJECT_MISSING);

  // check tail type
  if (src->ttype != TYPE_str) {
    throw(MAL, "batudf.hyperscanregex",
          "tail-type of input BAT must be TYPE_str");
  }

  // allocate void-headed result BAT
  bn = COLnew(src->hseqbase, TYPE_int, BATcount(src), TRANSIENT);
  if (bn == NULL) {
    throw(MAL, "batudf.hyperscanregex", SQLSTATE(HY001) MAL_MALLOC_FAIL);
  }

  // create BAT iterator
  li = bat_iterator(src);
  get_time(&fast_start);
  int *tr = GDKmalloc(sizeof *tr);
  time_diff(fast_start, "GDKmalloc");

  // the core of the algorithm, expensive due to malloc/frees
  // get_time(&fast_start);
  BATloop(src, p, q) {
    int measure_time = DEBUG && MEASURE_TIME();
    char *err = NULL;
    if (measure_time) get_time(&fast_start);
    const char *t = (const char *)BUNtail(li, p);
    if (measure_time) time_diff(fast_start, "BUNtail");

    // revert tail value
    *tr = 0;
    if (measure_time) get_time(&fast_start);
    int subject_len = strlen(t);
    if (measure_time) time_diff(fast_start, "strlen");
    if (measure_time) get_time(&fast_start);
    // matching a 64-byte text against pattern: 200 cycles. 60 ns.
    if (hs_scan(database, t, subject_len, 0, scratch, eventHandler, tr) !=
        HS_SUCCESS) {
      hs_free_scratch(scratch);
      hs_free_database(database);
      throw(MAL, "udf.hyperscanregex", "Unable to scan input buffer\n");
    }
    if (measure_time) time_diff(fast_start, "hs_scan");

    if (measure_time) get_time(&fast_start);
    err = MAL_SUCCEED;
    if (err != MAL_SUCCEED) {
      BBPunfix(bn->batCacheid);
      return err;
    }
    if (measure_time) time_diff(fast_start, "BBPUnfix");

    // assert logical sanity
    assert(tr != NULL);

    if (measure_time) get_time(&fast_start);
    // append reversed tail in result BAT
    if (BUNappend(bn, tr, FALSE) != GDK_SUCCEED) {
      BBPunfix(bn->batCacheid);
      throw(MAL, "batudf.hyperscanregex", SQLSTATE(HY001) MAL_MALLOC_FAIL);
    }
    if (measure_time) time_diff(fast_start, "BUNappend");
  }

  time_diff(fast_start, "LOOP");
  get_time(&fast_start);
  GDKfree(tr);
  time_diff(fast_start, "free");
  *ret = bn;

  if (DEBUG) {
    last_update_time = time(NULL);
  }
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

  // Check size of BAT
  // Find time taken in this function - don't use globals
  // Time taken when no scan is done (just remove all hyperscan code)
  // Clean up this file - remove reverse(), fuse()

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

  int measure_time = DEBUG && MEASURE_TIME();

  if (dfa == 0)
    rc = pcre_exec(re, NULL, src, strlen(src), 0, 0, ovector, OVECCOUNT);
  else {
    int workspace[WORCOUNT];
    rc = pcre_dfa_exec(re, NULL, src, strlen(src), 0, PCRE_DFA_SHORTEST,
                       ovector, OVECCOUNT, workspace, WORCOUNT);
  }

  if (measure_time) {
    last_update_time = time(NULL);
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
  if (DEBUG) {
    acnt++;
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

