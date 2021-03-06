#include <hs/hs.h>
#include <stdio.h>
#include <string.h>
#include <cre2.h>



static int count = 0;
static int eventHandler(unsigned int id, unsigned long long from,
                        unsigned long long to, unsigned int flags, void *ctx) {
  count++;
  return 0;
}

int hs_find_all(char *pattern, const char *subject) {
  int subject_len = strlen(subject);
  hs_database_t *database;
  hs_compile_error_t *compile_err;
  if (hs_compile(pattern, 0, HS_MODE_BLOCK, NULL, &database,
                 &compile_err) != HS_SUCCESS) {
    fprintf(stderr, "ERROR: Unable to compile pattern \"%s\": %s\n", pattern,
            compile_err->message);
    hs_free_compile_error(compile_err);
    return -1;
  }

  //const void *rose;
  //hs_get_bytecode_my(database, &rose);
  hs_scratch_t *scratch = NULL;
  if (hs_alloc_scratch(database, &scratch) != HS_SUCCESS) {
    fprintf(stderr, "ERROR: Unable to allocate scratch space. Exiting.\n");
    hs_free_database(database);
    return -1;
  }

  if (hs_scan(database, subject, subject_len, 0, scratch, eventHandler,
              NULL) != HS_SUCCESS) {
    fprintf(stderr, "ERROR: Unable to scan input buffer. Exiting.\n");
    hs_free_scratch(scratch);
    return 0;
  }
  //hs_clean_rose(scratch, rose);
  hs_free_scratch(scratch);
  hs_free_database(database);
  return 1;
}

static
int onMatchEcho(unsigned int id, unsigned long long tmp1, unsigned long long to,
                unsigned int tmp2, void *ctx) {
    printf("Match :%llu for %u, t1:%llu, t2:%uu\n", to, id, tmp1, tmp2);
		count++;
    return 0;
}

int test_hs_scan_vector() {

  hs_database_t *db;
  hs_compile_error_t *compile_err;
	
  hs_compile("A", HS_FLAG_SOM_LEFTMOST, HS_MODE_VECTORED, NULL, &db, &compile_err);

  hs_scratch_t *scratch = NULL;
  if (hs_alloc_scratch(db, &scratch) != HS_SUCCESS) {
    fprintf(stderr, "ERROR: Unable to allocate scratch space. Exiting.\n");
    hs_free_database(db);
    return -1;
  }

  char *source_batch[8];
	
	int len[8], res[8];
   for (int i = 0; i < 8; i++) {
     source_batch[i] = (char *)malloc(64);
     for (int j = 0; j < 64; j++) {
       source_batch[i][j] = 'A';
     }
		len[i] = 64;
   }
	
	hs_scan_vector(db, (const char**)source_batch, len, 8, 0, scratch, onMatchEcho, &res);
	hs_free_scratch(scratch);
	return 0;
}

int main() {
  //const char *subject = "abc";
  //hs_find_all("^a.", subject);
  //printf("hs matches: %d\n", count);
	test_hs_scan_vector();
  printf("hs matches: %d\n", count);
  /*
  int re2_result = re2_find_all("^a.", subject);
  printf("re2 matched: %d\n", re2_result);
  cre2_string_t match;
  const char* rule = "^a";
  const char* source = "abc";
  int ret = cre2_easy_match(rule, strlen(rule), source, strlen(source),
                            &match, 1);
  cre2_regexp_t *	rex;
  cre2_options_t *	opt;
  const char *		pattern;
  pattern = "^a";
  opt     = cre2_opt_new();
  cre2_opt_set_posix_syntax(opt, 1);
  rex = cre2_new(pattern, strlen(pattern), opt);
  cre2_string_t	match;
  int			e;
  const char *	text = "bc";
  int			text_len = strlen(text);
  e = cre2_match(rex, text, text_len, 0, text_len, CRE2_UNANCHORED, NULL, 0);
  cre2_opt_delete(opt);

  printf("xxxxxxx%d\n",e);
  */
  return 0;
}
