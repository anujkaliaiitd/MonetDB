/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0.  If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * Copyright 1997 - July 2008 CWI, August 2008 - 2017 MonetDB B.V.
 */

/* In your own module, replace "UDF" & "udf" by your module's name */

#ifndef _SQL_UDF_H_
#define _SQL_UDF_H_
#include "sql.h"
#include <string.h>

/* This is required as-is (except from renaming "UDF" & "udf" as suggested
 * above) for all modules for correctly exporting function on Unix-like and
 * Windows systems. */

#ifdef WIN32
#ifndef LIBUDF
#define udf_export extern __declspec(dllimport)
#else
#define udf_export extern __declspec(dllexport)
#endif
#else
#define udf_export extern
#endif

/* export MAL wrapper functions */
udf_export char * UDFBATregex(bat *ret, const bat *arg, const char **pattern);
udf_export char * UDFBATdfaregex(bat *ret, const bat *arg, const char **pattern);
udf_export char * UDFBAThyperscanregex(bat *ret, const bat *arg, const char **pattern);
udf_export char * UDFlvzixun_regex(int *ret, const char **pattern, const char **src);
udf_export char * UDFcre2regex(int *ret, const char **pattern, const char **src);
udf_export char * UDFBATlvzixun_regex(bat *ret, const bat *arg, const char **pattern);

/*below is data structure for my regex*/

struct reg_env;
struct reg_pattern;
struct reg_env* reg_open_env();
void reg_close_env(struct reg_env* env);
struct reg_pattern* reg_new_pattern(struct reg_env* env, const char* rule);
void reg_free_pattern(struct reg_pattern* pattern);
struct reg_longjump** reg_get_exception(struct reg_env* env);
int reg_match(struct reg_pattern* pattern, const char* source, int len);
struct fast_dfa_t;
int lvzixun_fast_dfa_reg_match(struct fast_dfa_t* fast_dfa, const char* source);
struct fast_dfa_t* lvzixun_regex_get_fast_dfa(struct reg_env* env, const char* rule);


#endif /* _SQL_UDF_H_ */
