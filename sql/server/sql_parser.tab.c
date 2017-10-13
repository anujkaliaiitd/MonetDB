/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         sqlparse
#define yylex           sqllex
#define yyerror         sqlerror
#define yydebug         sqldebug
#define yynerrs         sqlnerrs


/* Copy the first part of user declarations.  */
#line 9 "sql_parser.y" /* yacc.c:339  */

#include "monetdb_config.h"
#include <sql_mem.h>
#include "sql_parser.h"
#include "sql_symbol.h"
#include "sql_datetime.h"
#include "sql_decimal.h"	/* for decimal_from_str() */
#include "sql_semantic.h"	/* for sql_add_param() & sql_add_arg() */
#include "sql_env.h"
#include "rel_sequence.h"	/* for sql_next_seq_name() */
#ifdef HAVE_HGE
#include "mal.h"		/* for have_hge */
#endif

#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define SA 	m->sa
#define _symbol_create(t,d)         symbol_create( SA, t, d)
#define _symbol_create_list(t,d)    symbol_create_list( SA, t, d)
#define _symbol_create_int(t,d)     symbol_create_int( SA, t, d)
#define _symbol_create_lng(t,d)     symbol_create_lng( SA, t, d)
#define _symbol_create_symbol(t,d)  symbol_create_symbol( SA, t, d)
#define _symbol_create_hexa(t,d)    symbol_create_hexa( SA, t, d)
#define _newAtomNode(d)		    newAtomNode( SA, d)

#define L()                  dlist_create( SA )

#define append_list(l,d)     dlist_append_list( SA, l, d)
#define append_int(l,d)      dlist_append_int( SA, l, d)
#define append_lng(l,d)      dlist_append_lng( SA, l, d)
#define append_symbol(l,d)   dlist_append_symbol( SA, l, d)
#define append_string(l,d)   dlist_append_string( SA, l, d)
#define append_type(l,d)     dlist_append_type( SA, l, d)

#define _atom_string(t, v)   atom_string(SA, t, v)

#define YYMALLOC GDKmalloc
#define YYFREE GDKfree

#define YY_parse_LSP_NEEDED	/* needed for bison++ 1.21.11-3 */

#define SET_Z(info)(info = info | 0x02)
#define SET_M(info)(info = info | 0x01)

#ifdef HAVE_HGE
#define MAX_DEC_DIGITS (have_hge ? 38 : 18)
#define MAX_HEX_DIGITS (have_hge ? 32 : 16)
#else
#define MAX_DEC_DIGITS 18
#define MAX_HEX_DIGITS 16
#endif

static inline int
UTF8_strlen(const char *val)
{
	const unsigned char *s = (const unsigned char *) val;
	int pos = 0;

	while (*s) {
		int c = *s++;

		pos++;
		if (c < 0xC0)
			continue;
		if (*s++ < 0x80)
			return int_nil;
		if (c < 0xE0)
			continue;
		if (*s++ < 0x80)
			return int_nil;
		if (c < 0xF0)
			continue;
		if (*s++ < 0x80)
			return int_nil;
		if (c < 0xF8)
			continue;
		if (*s++ < 0x80)
			return int_nil;
		if (c < 0xFC)
			continue;
		if (*s++ < 0x80)
			return int_nil;
	}
	return pos;
}


#line 162 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_SQL_Y_TAB_H_INCLUDED
# define YY_SQL_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int sqldebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    STRING = 258,
    X_BODY = 259,
    IDENT = 260,
    aTYPE = 261,
    ALIAS = 262,
    AGGR = 263,
    AGGR2 = 264,
    RANK = 265,
    sqlINT = 266,
    OIDNUM = 267,
    HEXADECIMAL = 268,
    INTNUM = 269,
    APPROXNUM = 270,
    USING = 271,
    GLOBAL = 272,
    CAST = 273,
    CONVERT = 274,
    CHARACTER = 275,
    VARYING = 276,
    LARGE = 277,
    OBJECT = 278,
    VARCHAR = 279,
    CLOB = 280,
    sqlTEXT = 281,
    BINARY = 282,
    sqlBLOB = 283,
    sqlDECIMAL = 284,
    sqlFLOAT = 285,
    TINYINT = 286,
    SMALLINT = 287,
    BIGINT = 288,
    HUGEINT = 289,
    sqlINTEGER = 290,
    sqlDOUBLE = 291,
    sqlREAL = 292,
    PRECISION = 293,
    PARTIAL = 294,
    SIMPLE = 295,
    ACTION = 296,
    CASCADE = 297,
    RESTRICT = 298,
    BOOL_FALSE = 299,
    BOOL_TRUE = 300,
    CURRENT_DATE = 301,
    CURRENT_TIMESTAMP = 302,
    CURRENT_TIME = 303,
    LOCALTIMESTAMP = 304,
    LOCALTIME = 305,
    LEX_ERROR = 306,
    GEOMETRY = 307,
    GEOMETRYSUBTYPE = 308,
    GEOMETRYA = 309,
    USER = 310,
    CURRENT_USER = 311,
    SESSION_USER = 312,
    LOCAL = 313,
    LOCKED = 314,
    BEST = 315,
    EFFORT = 316,
    CURRENT_ROLE = 317,
    sqlSESSION = 318,
    sqlDELETE = 319,
    UPDATE = 320,
    SELECT = 321,
    INSERT = 322,
    LATERAL = 323,
    LEFT = 324,
    RIGHT = 325,
    FULL = 326,
    OUTER = 327,
    NATURAL = 328,
    CROSS = 329,
    JOIN = 330,
    INNER = 331,
    COMMIT = 332,
    ROLLBACK = 333,
    SAVEPOINT = 334,
    RELEASE = 335,
    WORK = 336,
    CHAIN = 337,
    NO = 338,
    PRESERVE = 339,
    ROWS = 340,
    START = 341,
    TRANSACTION = 342,
    READ = 343,
    WRITE = 344,
    ONLY = 345,
    ISOLATION = 346,
    LEVEL = 347,
    UNCOMMITTED = 348,
    COMMITTED = 349,
    sqlREPEATABLE = 350,
    SERIALIZABLE = 351,
    DIAGNOSTICS = 352,
    sqlSIZE = 353,
    STORAGE = 354,
    ASYMMETRIC = 355,
    SYMMETRIC = 356,
    ORDER = 357,
    ORDERED = 358,
    BY = 359,
    IMPRINTS = 360,
    EXISTS = 361,
    ESCAPE = 362,
    HAVING = 363,
    sqlGROUP = 364,
    sqlNULL = 365,
    FROM = 366,
    FOR = 367,
    MATCH = 368,
    EXTRACT = 369,
    SEQUENCE = 370,
    INCREMENT = 371,
    RESTART = 372,
    MAXVALUE = 373,
    MINVALUE = 374,
    CYCLE = 375,
    NOMAXVALUE = 376,
    NOMINVALUE = 377,
    NOCYCLE = 378,
    NEXT = 379,
    VALUE = 380,
    CACHE = 381,
    GENERATED = 382,
    ALWAYS = 383,
    IDENTITY = 384,
    SERIAL = 385,
    BIGSERIAL = 386,
    AUTO_INCREMENT = 387,
    SCOLON = 388,
    AT = 389,
    XMLCOMMENT = 390,
    XMLCONCAT = 391,
    XMLDOCUMENT = 392,
    XMLELEMENT = 393,
    XMLATTRIBUTES = 394,
    XMLFOREST = 395,
    XMLPARSE = 396,
    STRIP = 397,
    WHITESPACE = 398,
    XMLPI = 399,
    XMLQUERY = 400,
    PASSING = 401,
    XMLTEXT = 402,
    NIL = 403,
    REF = 404,
    ABSENT = 405,
    EMPTY = 406,
    DOCUMENT = 407,
    ELEMENT = 408,
    CONTENT = 409,
    XMLNAMESPACES = 410,
    NAMESPACE = 411,
    XMLVALIDATE = 412,
    RETURNING = 413,
    LOCATION = 414,
    ID = 415,
    ACCORDING = 416,
    XMLSCHEMA = 417,
    URI = 418,
    XMLAGG = 419,
    FILTER = 420,
    UNION = 421,
    EXCEPT = 422,
    INTERSECT = 423,
    CORRESPONDING = 424,
    UNIONJOIN = 425,
    WITH = 426,
    DATA = 427,
    FILTER_FUNC = 428,
    NOT = 429,
    ALL = 430,
    ANY = 431,
    NOT_BETWEEN = 432,
    BETWEEN = 433,
    NOT_IN = 434,
    sqlIN = 435,
    NOT_LIKE = 436,
    LIKE = 437,
    NOT_ILIKE = 438,
    ILIKE = 439,
    OR = 440,
    SOME = 441,
    AND = 442,
    COMPARISON = 443,
    LEFT_SHIFT = 444,
    RIGHT_SHIFT = 445,
    LEFT_SHIFT_ASSIGN = 446,
    RIGHT_SHIFT_ASSIGN = 447,
    CONCATSTRING = 448,
    SUBSTRING = 449,
    POSITION = 450,
    SPLIT_PART = 451,
    UMINUS = 452,
    GEOM_OVERLAP = 453,
    GEOM_OVERLAP_OR_ABOVE = 454,
    GEOM_OVERLAP_OR_BELOW = 455,
    GEOM_OVERLAP_OR_LEFT = 456,
    GEOM_OVERLAP_OR_RIGHT = 457,
    GEOM_BELOW = 458,
    GEOM_ABOVE = 459,
    GEOM_DIST = 460,
    GEOM_MBR_EQUAL = 461,
    TEMP = 462,
    TEMPORARY = 463,
    STREAM = 464,
    MERGE = 465,
    REMOTE = 466,
    REPLICA = 467,
    ASC = 468,
    DESC = 469,
    AUTHORIZATION = 470,
    CHECK = 471,
    CONSTRAINT = 472,
    CREATE = 473,
    TYPE = 474,
    PROCEDURE = 475,
    FUNCTION = 476,
    sqlLOADER = 477,
    AGGREGATE = 478,
    RETURNS = 479,
    EXTERNAL = 480,
    sqlNAME = 481,
    DECLARE = 482,
    CALL = 483,
    LANGUAGE = 484,
    ANALYZE = 485,
    MINMAX = 486,
    SQL_EXPLAIN = 487,
    SQL_PLAN = 488,
    SQL_DEBUG = 489,
    SQL_TRACE = 490,
    PREPARE = 491,
    EXECUTE = 492,
    DEFAULT = 493,
    DISTINCT = 494,
    DROP = 495,
    FOREIGN = 496,
    RENAME = 497,
    ENCRYPTED = 498,
    UNENCRYPTED = 499,
    PASSWORD = 500,
    GRANT = 501,
    REVOKE = 502,
    ROLE = 503,
    ADMIN = 504,
    INTO = 505,
    IS = 506,
    KEY = 507,
    ON = 508,
    OPTION = 509,
    OPTIONS = 510,
    PATH = 511,
    PRIMARY = 512,
    PRIVILEGES = 513,
    PUBLIC = 514,
    REFERENCES = 515,
    SCHEMA = 516,
    SET = 517,
    AUTO_COMMIT = 518,
    RETURN = 519,
    ALTER = 520,
    ADD = 521,
    TABLE = 522,
    COLUMN = 523,
    TO = 524,
    UNIQUE = 525,
    VALUES = 526,
    VIEW = 527,
    WHERE = 528,
    sqlDATE = 529,
    TIME = 530,
    TIMESTAMP = 531,
    INTERVAL = 532,
    YEAR = 533,
    QUARTER = 534,
    MONTH = 535,
    WEEK = 536,
    DAY = 537,
    HOUR = 538,
    MINUTE = 539,
    SECOND = 540,
    ZONE = 541,
    LIMIT = 542,
    OFFSET = 543,
    SAMPLE = 544,
    CASE = 545,
    WHEN = 546,
    THEN = 547,
    ELSE = 548,
    NULLIF = 549,
    COALESCE = 550,
    IF = 551,
    ELSEIF = 552,
    WHILE = 553,
    DO = 554,
    ATOMIC = 555,
    BEGIN = 556,
    END = 557,
    COPY = 558,
    RECORDS = 559,
    DELIMITERS = 560,
    STDIN = 561,
    STDOUT = 562,
    FWF = 563,
    INDEX = 564,
    REPLACE = 565,
    AS = 566,
    TRIGGER = 567,
    OF = 568,
    BEFORE = 569,
    AFTER = 570,
    ROW = 571,
    STATEMENT = 572,
    sqlNEW = 573,
    OLD = 574,
    EACH = 575,
    REFERENCING = 576,
    OVER = 577,
    PARTITION = 578,
    CURRENT = 579,
    EXCLUDE = 580,
    FOLLOWING = 581,
    PRECEDING = 582,
    OTHERS = 583,
    TIES = 584,
    RANGE = 585,
    UNBOUNDED = 586
  };
#endif
/* Tokens.  */
#define STRING 258
#define X_BODY 259
#define IDENT 260
#define aTYPE 261
#define ALIAS 262
#define AGGR 263
#define AGGR2 264
#define RANK 265
#define sqlINT 266
#define OIDNUM 267
#define HEXADECIMAL 268
#define INTNUM 269
#define APPROXNUM 270
#define USING 271
#define GLOBAL 272
#define CAST 273
#define CONVERT 274
#define CHARACTER 275
#define VARYING 276
#define LARGE 277
#define OBJECT 278
#define VARCHAR 279
#define CLOB 280
#define sqlTEXT 281
#define BINARY 282
#define sqlBLOB 283
#define sqlDECIMAL 284
#define sqlFLOAT 285
#define TINYINT 286
#define SMALLINT 287
#define BIGINT 288
#define HUGEINT 289
#define sqlINTEGER 290
#define sqlDOUBLE 291
#define sqlREAL 292
#define PRECISION 293
#define PARTIAL 294
#define SIMPLE 295
#define ACTION 296
#define CASCADE 297
#define RESTRICT 298
#define BOOL_FALSE 299
#define BOOL_TRUE 300
#define CURRENT_DATE 301
#define CURRENT_TIMESTAMP 302
#define CURRENT_TIME 303
#define LOCALTIMESTAMP 304
#define LOCALTIME 305
#define LEX_ERROR 306
#define GEOMETRY 307
#define GEOMETRYSUBTYPE 308
#define GEOMETRYA 309
#define USER 310
#define CURRENT_USER 311
#define SESSION_USER 312
#define LOCAL 313
#define LOCKED 314
#define BEST 315
#define EFFORT 316
#define CURRENT_ROLE 317
#define sqlSESSION 318
#define sqlDELETE 319
#define UPDATE 320
#define SELECT 321
#define INSERT 322
#define LATERAL 323
#define LEFT 324
#define RIGHT 325
#define FULL 326
#define OUTER 327
#define NATURAL 328
#define CROSS 329
#define JOIN 330
#define INNER 331
#define COMMIT 332
#define ROLLBACK 333
#define SAVEPOINT 334
#define RELEASE 335
#define WORK 336
#define CHAIN 337
#define NO 338
#define PRESERVE 339
#define ROWS 340
#define START 341
#define TRANSACTION 342
#define READ 343
#define WRITE 344
#define ONLY 345
#define ISOLATION 346
#define LEVEL 347
#define UNCOMMITTED 348
#define COMMITTED 349
#define sqlREPEATABLE 350
#define SERIALIZABLE 351
#define DIAGNOSTICS 352
#define sqlSIZE 353
#define STORAGE 354
#define ASYMMETRIC 355
#define SYMMETRIC 356
#define ORDER 357
#define ORDERED 358
#define BY 359
#define IMPRINTS 360
#define EXISTS 361
#define ESCAPE 362
#define HAVING 363
#define sqlGROUP 364
#define sqlNULL 365
#define FROM 366
#define FOR 367
#define MATCH 368
#define EXTRACT 369
#define SEQUENCE 370
#define INCREMENT 371
#define RESTART 372
#define MAXVALUE 373
#define MINVALUE 374
#define CYCLE 375
#define NOMAXVALUE 376
#define NOMINVALUE 377
#define NOCYCLE 378
#define NEXT 379
#define VALUE 380
#define CACHE 381
#define GENERATED 382
#define ALWAYS 383
#define IDENTITY 384
#define SERIAL 385
#define BIGSERIAL 386
#define AUTO_INCREMENT 387
#define SCOLON 388
#define AT 389
#define XMLCOMMENT 390
#define XMLCONCAT 391
#define XMLDOCUMENT 392
#define XMLELEMENT 393
#define XMLATTRIBUTES 394
#define XMLFOREST 395
#define XMLPARSE 396
#define STRIP 397
#define WHITESPACE 398
#define XMLPI 399
#define XMLQUERY 400
#define PASSING 401
#define XMLTEXT 402
#define NIL 403
#define REF 404
#define ABSENT 405
#define EMPTY 406
#define DOCUMENT 407
#define ELEMENT 408
#define CONTENT 409
#define XMLNAMESPACES 410
#define NAMESPACE 411
#define XMLVALIDATE 412
#define RETURNING 413
#define LOCATION 414
#define ID 415
#define ACCORDING 416
#define XMLSCHEMA 417
#define URI 418
#define XMLAGG 419
#define FILTER 420
#define UNION 421
#define EXCEPT 422
#define INTERSECT 423
#define CORRESPONDING 424
#define UNIONJOIN 425
#define WITH 426
#define DATA 427
#define FILTER_FUNC 428
#define NOT 429
#define ALL 430
#define ANY 431
#define NOT_BETWEEN 432
#define BETWEEN 433
#define NOT_IN 434
#define sqlIN 435
#define NOT_LIKE 436
#define LIKE 437
#define NOT_ILIKE 438
#define ILIKE 439
#define OR 440
#define SOME 441
#define AND 442
#define COMPARISON 443
#define LEFT_SHIFT 444
#define RIGHT_SHIFT 445
#define LEFT_SHIFT_ASSIGN 446
#define RIGHT_SHIFT_ASSIGN 447
#define CONCATSTRING 448
#define SUBSTRING 449
#define POSITION 450
#define SPLIT_PART 451
#define UMINUS 452
#define GEOM_OVERLAP 453
#define GEOM_OVERLAP_OR_ABOVE 454
#define GEOM_OVERLAP_OR_BELOW 455
#define GEOM_OVERLAP_OR_LEFT 456
#define GEOM_OVERLAP_OR_RIGHT 457
#define GEOM_BELOW 458
#define GEOM_ABOVE 459
#define GEOM_DIST 460
#define GEOM_MBR_EQUAL 461
#define TEMP 462
#define TEMPORARY 463
#define STREAM 464
#define MERGE 465
#define REMOTE 466
#define REPLICA 467
#define ASC 468
#define DESC 469
#define AUTHORIZATION 470
#define CHECK 471
#define CONSTRAINT 472
#define CREATE 473
#define TYPE 474
#define PROCEDURE 475
#define FUNCTION 476
#define sqlLOADER 477
#define AGGREGATE 478
#define RETURNS 479
#define EXTERNAL 480
#define sqlNAME 481
#define DECLARE 482
#define CALL 483
#define LANGUAGE 484
#define ANALYZE 485
#define MINMAX 486
#define SQL_EXPLAIN 487
#define SQL_PLAN 488
#define SQL_DEBUG 489
#define SQL_TRACE 490
#define PREPARE 491
#define EXECUTE 492
#define DEFAULT 493
#define DISTINCT 494
#define DROP 495
#define FOREIGN 496
#define RENAME 497
#define ENCRYPTED 498
#define UNENCRYPTED 499
#define PASSWORD 500
#define GRANT 501
#define REVOKE 502
#define ROLE 503
#define ADMIN 504
#define INTO 505
#define IS 506
#define KEY 507
#define ON 508
#define OPTION 509
#define OPTIONS 510
#define PATH 511
#define PRIMARY 512
#define PRIVILEGES 513
#define PUBLIC 514
#define REFERENCES 515
#define SCHEMA 516
#define SET 517
#define AUTO_COMMIT 518
#define RETURN 519
#define ALTER 520
#define ADD 521
#define TABLE 522
#define COLUMN 523
#define TO 524
#define UNIQUE 525
#define VALUES 526
#define VIEW 527
#define WHERE 528
#define sqlDATE 529
#define TIME 530
#define TIMESTAMP 531
#define INTERVAL 532
#define YEAR 533
#define QUARTER 534
#define MONTH 535
#define WEEK 536
#define DAY 537
#define HOUR 538
#define MINUTE 539
#define SECOND 540
#define ZONE 541
#define LIMIT 542
#define OFFSET 543
#define SAMPLE 544
#define CASE 545
#define WHEN 546
#define THEN 547
#define ELSE 548
#define NULLIF 549
#define COALESCE 550
#define IF 551
#define ELSEIF 552
#define WHILE 553
#define DO 554
#define ATOMIC 555
#define BEGIN 556
#define END 557
#define COPY 558
#define RECORDS 559
#define DELIMITERS 560
#define STDIN 561
#define STDOUT 562
#define FWF 563
#define INDEX 564
#define REPLACE 565
#define AS 566
#define TRIGGER 567
#define OF 568
#define BEFORE 569
#define AFTER 570
#define ROW 571
#define STATEMENT 572
#define sqlNEW 573
#define OLD 574
#define EACH 575
#define REFERENCING 576
#define OVER 577
#define PARTITION 578
#define CURRENT 579
#define EXCLUDE 580
#define FOLLOWING 581
#define PRECEDING 582
#define OTHERS 583
#define TIES 584
#define RANGE 585
#define UNBOUNDED 586

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 111 "sql_parser.y" /* yacc.c:355  */

	int		i_val,bval;
	lng		l_val,operation;
	double		fval;
	char *		sval;
	symbol*		sym;
	dlist*		l;
	sql_subtype	type;

#line 874 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int sqlparse (mvc *m);

#endif /* !YY_SQL_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */
#line 120 "sql_parser.y" /* yacc.c:358  */

extern int sqllex( YYSTYPE *yylval, void *m );
/* enable to activate debugging support
int yydebug=1;
*/

#line 896 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  229
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   17514

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  350
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  409
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1133
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  2105

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   586

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   208,   194,     2,
     173,   174,   206,   192,   344,   193,   345,   207,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   346,     2,
       2,   177,     2,   349,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   347,     2,   348,   196,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   195,     2,   209,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   175,   176,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,   335,   336,
     337,   338,   339,   340,   341,   342,   343
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   621,   621,   632,   632,   646,   646,   661,   661,   676,
     676,   686,   686,   692,   693,   694,   695,   696,   701,   704,
     705,   709,   710,   713,   714,   718,   721,   724,   728,   729,
     730,   731,   732,   733,   734,   735,   736,   743,   747,   748,
     752,   754,   758,   763,   772,   777,   782,   790,   798,   806,
     814,   820,   828,   837,   846,   850,   854,   861,   864,   865,
     869,   870,   874,   875,   879,   879,   879,   879,   879,   882,
     883,   887,   888,   892,   901,   912,   913,   918,   919,   923,
     924,   929,   930,   934,   942,   952,   953,   957,   958,   962,
     966,   973,   974,   979,   980,   984,   985,   986,   997,   998,
     999,  1003,  1004,  1009,  1010,  1011,  1012,  1013,  1014,  1018,
    1019,  1024,  1025,  1031,  1037,  1042,  1047,  1052,  1057,  1062,
    1067,  1072,  1077,  1090,  1096,  1102,  1112,  1117,  1121,  1125,
    1127,  1135,  1143,  1148,  1153,  1162,  1163,  1167,  1168,  1169,
    1170,  1171,  1172,  1173,  1174,  1190,  1201,  1218,  1228,  1229,
    1233,  1234,  1238,  1239,  1240,  1244,  1245,  1246,  1247,  1248,
    1252,  1253,  1254,  1255,  1256,  1257,  1258,  1259,  1266,  1276,
    1277,  1278,  1279,  1299,  1304,  1315,  1316,  1317,  1321,  1322,
    1326,  1338,  1345,  1356,  1367,  1381,  1392,  1408,  1409,  1410,
    1411,  1412,  1413,  1417,  1418,  1419,  1420,  1424,  1425,  1429,
    1439,  1440,  1441,  1445,  1447,  1451,  1451,  1452,  1452,  1452,
    1455,  1456,  1460,  1468,  1521,  1522,  1526,  1528,  1533,  1542,
    1544,  1548,  1548,  1548,  1551,  1555,  1559,  1568,  1597,  1635,
    1636,  1641,  1652,  1653,  1657,  1658,  1659,  1660,  1661,  1665,
    1669,  1673,  1674,  1675,  1676,  1677,  1681,  1682,  1683,  1684,
    1688,  1689,  1693,  1694,  1695,  1696,  1697,  1707,  1711,  1713,
    1715,  1730,  1734,  1736,  1741,  1745,  1757,  1758,  1762,  1763,
    1767,  1768,  1772,  1773,  1777,  1781,  1789,  1794,  1795,  1800,
    1814,  1828,  1874,  1888,  1902,  1948,  1961,  1974,  2000,  2002,
    2006,  2024,  2025,  2030,  2031,  2036,  2037,  2038,  2039,  2040,
    2041,  2042,  2043,  2044,  2045,  2046,  2047,  2051,  2052,  2053,
    2054,  2055,  2056,  2057,  2058,  2062,  2063,  2064,  2065,  2066,
    2067,  2080,  2084,  2088,  2097,  2100,  2101,  2102,  2108,  2112,
    2113,  2114,  2119,  2125,  2133,  2141,  2143,  2148,  2156,  2158,
    2163,  2164,  2171,  2185,  2186,  2188,  2199,  2220,  2221,  2225,
    2226,  2231,  2235,  2243,  2245,  2250,  2251,  2255,  2259,  2264,
    2313,  2327,  2328,  2333,  2334,  2335,  2336,  2340,  2341,  2345,
    2346,  2352,  2353,  2354,  2355,  2358,  2360,  2363,  2365,  2369,
    2377,  2378,  2382,  2383,  2387,  2388,  2392,  2394,  2400,  2406,
    2412,  2418,  2424,  2433,  2439,  2444,  2452,  2460,  2468,  2476,
    2484,  2490,  2495,  2496,  2497,  2498,  2502,  2503,  2504,  2508,
    2511,  2516,  2517,  2518,  2523,  2524,  2529,  2530,  2531,  2532,
    2536,  2543,  2545,  2547,  2549,  2553,  2555,  2557,  2562,  2563,
    2567,  2569,  2575,  2576,  2577,  2578,  2582,  2583,  2584,  2585,
    2589,  2590,  2594,  2595,  2596,  2600,  2601,  2605,  2619,  2633,
    2638,  2649,  2656,  2668,  2669,  2674,  2675,  2681,  2682,  2686,
    2687,  2691,  2695,  2704,  2708,  2713,  2718,  2727,  2728,  2732,
    2733,  2734,  2735,  2737,  2742,  2743,  2747,  2748,  2752,  2753,
    2757,  2758,  2762,  2763,  2767,  2768,  2773,  2782,  2824,  2832,
    2843,  2844,  2846,  2848,  2853,  2854,  2859,  2860,  2865,  2866,
    2871,  2888,  2892,  2893,  2897,  2898,  2902,  2903,  2904,  2908,
    2909,  2914,  2918,  2923,  2928,  2936,  2937,  2943,  2945,  2950,
    2958,  2966,  2977,  2978,  2979,  2983,  2984,  2988,  2989,  2990,
    2994,  2995,  3015,  3019,  3029,  3030,  3034,  3046,  3051,  3053,
    3057,  3068,  3079,  3110,  3111,  3116,  3120,  3129,  3138,  3146,
    3147,  3151,  3152,  3153,  3158,  3159,  3161,  3166,  3170,  3180,
    3181,  3185,  3186,  3191,  3195,  3201,  3207,  3217,  3229,  3234,
    3238,  3237,  3250,  3255,  3260,  3265,  3273,  3274,  3278,  3279,
    3283,  3285,  3291,  3292,  3297,  3302,  3306,  3311,  3315,  3316,
    3321,  3322,  3326,  3330,  3331,  3335,  3339,  3340,  3344,  3348,
    3352,  3353,  3358,  3367,  3368,  3369,  3373,  3374,  3375,  3376,
    3377,  3378,  3379,  3380,  3381,  3385,  3402,  3406,  3413,  3423,
    3430,  3440,  3441,  3442,  3446,  3453,  3460,  3467,  3477,  3481,
    3497,  3498,  3502,  3508,  3514,  3519,  3527,  3529,  3534,  3542,
    3552,  3553,  3554,  3558,  3562,  3563,  3567,  3571,  3581,  3582,
    3584,  3589,  3590,  3592,  3598,  3599,  3606,  3613,  3620,  3627,
    3634,  3641,  3648,  3655,  3662,  3669,  3676,  3682,  3689,  3696,
    3703,  3710,  3717,  3724,  3731,  3737,  3744,  3751,  3758,  3765,
    3767,  3789,  3793,  3794,  3798,  3799,  3801,  3803,  3804,  3805,
    3806,  3807,  3808,  3809,  3810,  3811,  3812,  3813,  3814,  3815,
    3819,  3889,  3895,  3896,  3900,  3905,  3906,  3911,  3912,  3917,
    3918,  3923,  3924,  3928,  3929,  3933,  3934,  3935,  3939,  3943,
    3948,  3949,  3950,  3954,  3958,  3959,  3960,  3961,  3962,  3966,
    3970,  3974,  4002,  4003,  4008,  4009,  4010,  4011,  4015,  4022,
    4027,  4032,  4037,  4042,  4050,  4051,  4055,  4065,  4075,  4082,
    4089,  4096,  4103,  4116,  4117,  4122,  4127,  4132,  4137,  4145,
    4146,  4150,  4172,  4173,  4178,  4179,  4184,  4185,  4191,  4197,
    4203,  4209,  4215,  4221,  4228,  4232,  4233,  4234,  4238,  4239,
    4250,  4252,  4256,  4258,  4262,  4263,  4269,  4278,  4279,  4280,
    4281,  4282,  4286,  4287,  4291,  4292,  4293,  4297,  4303,  4306,
    4312,  4315,  4321,  4324,  4329,  4349,  4350,  4351,  4355,  4361,
    4425,  4456,  4517,  4556,  4573,  4589,  4605,  4621,  4622,  4639,
    4656,  4673,  4694,  4698,  4705,  4750,  4751,  4755,  4766,  4769,
    4773,  4781,  4787,  4795,  4799,  4804,  4806,  4812,  4820,  4822,
    4827,  4831,  4837,  4845,  4847,  4852,  4860,  4862,  4867,  4868,
    4872,  4877,  4888,  4899,  4909,  4919,  4921,  4926,  4927,  4929,
    4931,  4940,  4941,  4950,  4951,  4952,  4953,  4954,  4956,  4957,
    4970,  4988,  4989,  5003,  5023,  5024,  5025,  5026,  5027,  5028,
    5029,  5031,  5032,  5034,  5046,  5060,  5074,  5081,  5096,  5111,
    5118,  5144,  5161,  5181,  5196,  5197,  5201,  5202,  5203,  5206,
    5207,  5210,  5212,  5215,  5216,  5217,  5218,  5219,  5220,  5224,
    5225,  5226,  5227,  5228,  5229,  5230,  5231,  5235,  5236,  5237,
    5238,  5239,  5240,  5241,  5242,  5243,  5244,  5245,  5246,  5247,
    5249,  5250,  5251,  5252,  5253,  5254,  5255,  5256,  5257,  5258,
    5259,  5260,  5261,  5262,  5264,  5265,  5266,  5267,  5268,  5269,
    5270,  5271,  5272,  5273,  5274,  5275,  5276,  5277,  5278,  5279,
    5280,  5282,  5283,  5284,  5285,  5286,  5287,  5288,  5289,  5291,
    5292,  5293,  5294,  5295,  5296,  5297,  5298,  5299,  5300,  5301,
    5302,  5303,  5304,  5305,  5306,  5307,  5308,  5309,  5310,  5311,
    5312,  5313,  5314,  5318,  5319,  5324,  5347,  5368,  5400,  5402,
    5410,  5417,  5422,  5437,  5438,  5442,  5445,  5448,  5452,  5454,
    5459,  5463,  5464,  5465,  5466,  5467,  5468,  5469,  5470,  5471,
    5472,  5476,  5484,  5492,  5499,  5513,  5514,  5518,  5522,  5526,
    5530,  5534,  5538,  5545,  5549,  5553,  5554,  5564,  5572,  5573,
    5577,  5581,  5585,  5592,  5594,  5599,  5603,  5604,  5608,  5609,
    5610,  5611,  5612,  5616,  5629,  5630,  5634,  5636,  5641,  5647,
    5651,  5652,  5656,  5661,  5670,  5671,  5675,  5686,  5690,  5691,
    5696,  5706,  5709,  5711,  5715,  5719,  5720,  5724,  5725,  5729,
    5733,  5736,  5738,  5742,  5743,  5747,  5755,  5764,  5765,  5769,
    5770,  5774,  5775,  5776,  5791,  5795,  5796,  5806,  5807,  5811,
    5815,  5819,  5829,  5833,  5836,  5838,  5842,  5843,  5846,  5848,
    5852,  5857,  5858,  5862,  5863,  5867,  5871,  5874,  5876,  5880,
    5884,  5888,  5891,  5893,  5897,  5898,  5902,  5904,  5908,  5912,
    5913,  5917,  5921,  5925
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRING", "X_BODY", "IDENT", "aTYPE",
  "ALIAS", "AGGR", "AGGR2", "RANK", "sqlINT", "OIDNUM", "HEXADECIMAL",
  "INTNUM", "APPROXNUM", "USING", "GLOBAL", "CAST", "CONVERT", "CHARACTER",
  "VARYING", "LARGE", "OBJECT", "VARCHAR", "CLOB", "sqlTEXT", "BINARY",
  "sqlBLOB", "sqlDECIMAL", "sqlFLOAT", "TINYINT", "SMALLINT", "BIGINT",
  "HUGEINT", "sqlINTEGER", "sqlDOUBLE", "sqlREAL", "PRECISION", "PARTIAL",
  "SIMPLE", "ACTION", "CASCADE", "RESTRICT", "BOOL_FALSE", "BOOL_TRUE",
  "CURRENT_DATE", "CURRENT_TIMESTAMP", "CURRENT_TIME", "LOCALTIMESTAMP",
  "LOCALTIME", "LEX_ERROR", "GEOMETRY", "GEOMETRYSUBTYPE", "GEOMETRYA",
  "USER", "CURRENT_USER", "SESSION_USER", "LOCAL", "LOCKED", "BEST",
  "EFFORT", "CURRENT_ROLE", "sqlSESSION", "sqlDELETE", "UPDATE", "SELECT",
  "INSERT", "LATERAL", "LEFT", "RIGHT", "FULL", "OUTER", "NATURAL",
  "CROSS", "JOIN", "INNER", "COMMIT", "ROLLBACK", "SAVEPOINT", "RELEASE",
  "WORK", "CHAIN", "NO", "PRESERVE", "ROWS", "START", "TRANSACTION",
  "READ", "WRITE", "ONLY", "ISOLATION", "LEVEL", "UNCOMMITTED",
  "COMMITTED", "sqlREPEATABLE", "SERIALIZABLE", "DIAGNOSTICS", "sqlSIZE",
  "STORAGE", "ASYMMETRIC", "SYMMETRIC", "ORDER", "ORDERED", "BY",
  "IMPRINTS", "EXISTS", "ESCAPE", "HAVING", "sqlGROUP", "sqlNULL", "FROM",
  "FOR", "MATCH", "EXTRACT", "SEQUENCE", "INCREMENT", "RESTART",
  "MAXVALUE", "MINVALUE", "CYCLE", "NOMAXVALUE", "NOMINVALUE", "NOCYCLE",
  "NEXT", "VALUE", "CACHE", "GENERATED", "ALWAYS", "IDENTITY", "SERIAL",
  "BIGSERIAL", "AUTO_INCREMENT", "SCOLON", "AT", "XMLCOMMENT", "XMLCONCAT",
  "XMLDOCUMENT", "XMLELEMENT", "XMLATTRIBUTES", "XMLFOREST", "XMLPARSE",
  "STRIP", "WHITESPACE", "XMLPI", "XMLQUERY", "PASSING", "XMLTEXT", "NIL",
  "REF", "ABSENT", "EMPTY", "DOCUMENT", "ELEMENT", "CONTENT",
  "XMLNAMESPACES", "NAMESPACE", "XMLVALIDATE", "RETURNING", "LOCATION",
  "ID", "ACCORDING", "XMLSCHEMA", "URI", "XMLAGG", "FILTER", "UNION",
  "EXCEPT", "INTERSECT", "CORRESPONDING", "UNIONJOIN", "WITH", "DATA",
  "'('", "')'", "FILTER_FUNC", "NOT", "'='", "ALL", "ANY", "NOT_BETWEEN",
  "BETWEEN", "NOT_IN", "sqlIN", "NOT_LIKE", "LIKE", "NOT_ILIKE", "ILIKE",
  "OR", "SOME", "AND", "COMPARISON", "'+'", "'-'", "'&'", "'|'", "'^'",
  "LEFT_SHIFT", "RIGHT_SHIFT", "LEFT_SHIFT_ASSIGN", "RIGHT_SHIFT_ASSIGN",
  "CONCATSTRING", "SUBSTRING", "POSITION", "SPLIT_PART", "UMINUS", "'*'",
  "'/'", "'%'", "'~'", "GEOM_OVERLAP", "GEOM_OVERLAP_OR_ABOVE",
  "GEOM_OVERLAP_OR_BELOW", "GEOM_OVERLAP_OR_LEFT", "GEOM_OVERLAP_OR_RIGHT",
  "GEOM_BELOW", "GEOM_ABOVE", "GEOM_DIST", "GEOM_MBR_EQUAL", "TEMP",
  "TEMPORARY", "STREAM", "MERGE", "REMOTE", "REPLICA", "ASC", "DESC",
  "AUTHORIZATION", "CHECK", "CONSTRAINT", "CREATE", "TYPE", "PROCEDURE",
  "FUNCTION", "sqlLOADER", "AGGREGATE", "RETURNS", "EXTERNAL", "sqlNAME",
  "DECLARE", "CALL", "LANGUAGE", "ANALYZE", "MINMAX", "SQL_EXPLAIN",
  "SQL_PLAN", "SQL_DEBUG", "SQL_TRACE", "PREPARE", "EXECUTE", "DEFAULT",
  "DISTINCT", "DROP", "FOREIGN", "RENAME", "ENCRYPTED", "UNENCRYPTED",
  "PASSWORD", "GRANT", "REVOKE", "ROLE", "ADMIN", "INTO", "IS", "KEY",
  "ON", "OPTION", "OPTIONS", "PATH", "PRIMARY", "PRIVILEGES", "PUBLIC",
  "REFERENCES", "SCHEMA", "SET", "AUTO_COMMIT", "RETURN", "ALTER", "ADD",
  "TABLE", "COLUMN", "TO", "UNIQUE", "VALUES", "VIEW", "WHERE", "sqlDATE",
  "TIME", "TIMESTAMP", "INTERVAL", "YEAR", "QUARTER", "MONTH", "WEEK",
  "DAY", "HOUR", "MINUTE", "SECOND", "ZONE", "LIMIT", "OFFSET", "SAMPLE",
  "CASE", "WHEN", "THEN", "ELSE", "NULLIF", "COALESCE", "IF", "ELSEIF",
  "WHILE", "DO", "ATOMIC", "BEGIN", "END", "COPY", "RECORDS", "DELIMITERS",
  "STDIN", "STDOUT", "FWF", "INDEX", "REPLACE", "AS", "TRIGGER", "OF",
  "BEFORE", "AFTER", "ROW", "STATEMENT", "sqlNEW", "OLD", "EACH",
  "REFERENCING", "OVER", "PARTITION", "CURRENT", "EXCLUDE", "FOLLOWING",
  "PRECEDING", "OTHERS", "TIES", "RANGE", "UNBOUNDED", "','", "'.'", "':'",
  "'['", "']'", "'?'", "$accept", "sqlstmt", "$@1", "$@2", "$@3", "$@4",
  "$@5", "create", "create_or_replace", "if_exists", "if_not_exists",
  "drop", "set", "declare", "sql", "opt_minmax", "declare_statement",
  "variable_list", "set_statement", "schema", "schema_name_clause",
  "authorization_identifier", "opt_schema_default_char_set",
  "opt_schema_element_list", "schema_element_list", "schema_element",
  "opt_grantor", "grantor", "grant", "authid_list", "opt_with_grant",
  "opt_with_admin", "opt_from_grantor", "revoke", "opt_grant_for",
  "opt_admin_for", "privileges", "global_privileges", "global_privilege",
  "object_name", "object_privileges", "operation_commalist", "operation",
  "grantee_commalist", "grantee", "alter_statement", "passwd_schema",
  "alter_table_element", "drop_table_element", "opt_column",
  "create_statement", "seq_def", "opt_seq_params", "opt_alt_seq_params",
  "opt_seq_param", "opt_alt_seq_param", "opt_seq_common_param",
  "index_def", "opt_index_type", "role_def", "opt_encrypted",
  "table_opt_storage", "table_def", "opt_temp", "opt_on_commit",
  "table_content_source", "as_subquery_clause", "with_or_without_data",
  "table_element_list", "add_table_element", "table_element",
  "serial_or_bigserial", "column_def", "opt_column_def_opt_list",
  "column_def_opt_list", "column_options", "column_option_list",
  "column_option", "default", "default_value", "column_constraint",
  "generated_column", "serial_opt_params", "table_constraint",
  "opt_constraint_name", "ref_action", "ref_on_update", "ref_on_delete",
  "opt_ref_action", "opt_match_type", "opt_match",
  "column_constraint_type", "table_constraint_type",
  "domain_constraint_type", "ident_commalist", "like_table", "view_def",
  "query_expression_def", "query_expression", "opt_with_check_option",
  "opt_column_list", "column_commalist_parens", "type_def",
  "external_function_name", "function_body", "func_def", "routine_body",
  "procedure_statement_list", "trigger_procedure_statement_list",
  "procedure_statement", "trigger_procedure_statement",
  "control_statement", "call_statement", "call_procedure_statement",
  "routine_invocation", "routine_name", "argument_list",
  "return_statement", "return_value", "case_statement", "when_statement",
  "when_statements", "when_search_statement", "when_search_statements",
  "case_opt_else_statement", "if_statement", "if_opt_else",
  "while_statement", "opt_begin_label", "opt_end_label",
  "table_function_column_list", "func_data_type", "opt_paramlist",
  "paramlist", "trigger_def", "trigger_action_time", "trigger_event",
  "opt_referencing_list", "old_or_new_values_alias_list",
  "old_or_new_values_alias", "opt_as", "opt_row", "triggered_action",
  "opt_for_each", "row_or_statement", "opt_when", "triggered_statement",
  "routine_designator", "drop_statement", "opt_typelist", "typelist",
  "drop_action", "update_statement", "transaction_statement",
  "_transaction_stmt", "transaction_mode_list", "_transaction_mode_list",
  "transaction_mode", "iso_level", "opt_work", "opt_chain",
  "opt_to_savepoint", "copyfrom_stmt", "opt_fwf_widths", "fwf_widthlist",
  "opt_header_list", "header_list", "header", "opt_seps", "opt_using",
  "opt_nr", "opt_null_string", "opt_locked", "opt_best_effort",
  "opt_constraint", "string_commalist", "string_commalist_contents",
  "delete_stmt", "update_stmt", "insert_stmt", "values_or_query_spec",
  "row_commalist", "atom_commalist", "value_commalist", "null",
  "simple_atom", "insert_atom", "value", "opt_distinct",
  "assignment_commalist", "assign_default", "assignment",
  "opt_where_clause", "joined_table", "join_type", "opt_outer",
  "outer_join_type", "join_spec", "with_query", "with_list",
  "with_list_element", "with_query_expression", "simple_select",
  "select_statement_single_row", "select_no_parens_orderby",
  "select_target_list", "target_specification", "select_no_parens",
  "set_distinct", "opt_corresponding", "selection", "table_exp",
  "opt_from_clause", "table_ref_commalist", "table_ref", "$@6",
  "table_name", "opt_table_name", "opt_group_by_clause",
  "column_ref_commalist", "opt_having_clause", "search_condition",
  "and_exp", "opt_order_by_clause", "opt_limit", "opt_offset",
  "opt_sample", "sort_specification_list", "ordering_spec", "opt_asc_desc",
  "predicate", "pred_exp", "comparison_predicate", "between_predicate",
  "opt_bounds", "like_predicate", "like_exp", "test_for_null",
  "in_predicate", "pred_exp_list", "all_or_any_predicate", "any_all_some",
  "existence_test", "filter_arg_list", "filter_args", "filter_exp",
  "subquery_with_orderby", "subquery", "simple_scalar_exp", "scalar_exp",
  "value_exp", "param", "window_function", "window_function_type",
  "window_specification", "window_partition_clause", "window_order_clause",
  "window_frame_clause", "window_frame_units", "window_frame_extent",
  "window_frame_start", "window_frame_preceding", "window_frame_between",
  "window_frame_end", "window_frame_following", "window_frame_exclusion",
  "var_ref", "func_ref", "qfunc", "func_ident", "datetime_funcs",
  "opt_brackets", "string_funcs", "column_exp_commalist", "column_exp",
  "opt_alias_name", "atom", "qrank", "qaggr", "qaggr2", "aggr_ref",
  "opt_sign", "tz", "time_precision", "timestamp_precision",
  "datetime_type", "non_second_datetime_field", "datetime_field",
  "extract_datetime_field", "start_field", "end_field",
  "single_datetime_field", "interval_qualifier", "interval_type", "user",
  "literal", "interval_expression", "qname", "column_ref", "cast_exp",
  "cast_value", "case_exp", "scalar_exp_list", "case_scalar_exp_list",
  "when_value", "when_value_list", "when_search", "when_search_list",
  "case_opt_else", "case_scalar_exp", "nonzero", "nonzerolng", "poslng",
  "posint", "data_type", "subgeometry_type", "type_alias", "varchar",
  "clob", "blob", "column", "authid", "restricted_ident", "ident",
  "non_reserved_word", "name_commalist", "lngval", "intval", "string",
  "exec", "exec_ref", "opt_path_specification", "path_specification",
  "schema_name_list", "XML_value_expression", "XML_value_expression_list",
  "XML_primary", "XML_value_function", "XML_comment", "XML_concatenation",
  "XML_document", "XML_element",
  "opt_comma_XML_namespace_declaration_attributes_element_content",
  "XML_element_name", "XML_attributes", "XML_attribute_list",
  "XML_attribute", "opt_XML_attribute_name", "XML_attribute_value",
  "XML_attribute_name", "XML_element_content_and_option",
  "XML_element_content_list", "XML_element_content",
  "opt_XML_content_option", "XML_content_option", "XML_forest",
  "opt_XML_namespace_declaration_and_comma", "forest_element_list",
  "forest_element", "forest_element_value", "opt_forest_element_name",
  "forest_element_name", "XML_parse", "XML_whitespace_option", "XML_PI",
  "XML_PI_target", "opt_comma_string_value_expression", "XML_query",
  "XQuery_expression", "opt_XML_query_argument_list",
  "XML_query_default_passing_mechanism", "XML_query_argument_list",
  "XML_query_argument", "XML_query_context_item", "XML_query_variable",
  "opt_XML_query_returning_mechanism", "XML_query_empty_handling_option",
  "XML_text", "XML_validate", "document_or_content_or_sequence",
  "document_or_content", "opt_XML_returning_clause",
  "XML_namespace_declaration", "XML_namespace_declaration_item_list",
  "XML_namespace_declaration_item", "XML_namespace_prefix",
  "XML_namespace_URI", "XML_regular_namespace_declaration_item",
  "XML_default_namespace_declaration_item", "opt_XML_passing_mechanism",
  "XML_passing_mechanism", "opt_XML_valid_according_to_clause",
  "XML_valid_according_to_clause", "XML_valid_according_to_what",
  "XML_valid_according_to_URI", "XML_valid_target_namespace_URI",
  "XML_URI", "opt_XML_valid_schema_location",
  "XML_valid_schema_location_URI", "XML_valid_according_to_identifier",
  "registered_XML_Schema_name", "opt_XML_valid_element_clause",
  "XML_valid_element_clause", "opt_XML_valid_element_name_specification",
  "XML_valid_element_name_specification",
  "XML_valid_element_namespace_specification",
  "XML_valid_element_namespace_URI", "XML_valid_element_name",
  "XML_aggregate", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,    40,    41,   428,   429,    61,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,    43,    45,    38,   124,    94,   444,   445,   446,
     447,   448,   449,   450,   451,   452,    42,    47,    37,   126,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,   505,   506,   507,   508,   509,   510,   511,   512,
     513,   514,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,    44,    46,    58,    91,    93,    63
};
# endif

#define YYPACT_NINF -1693

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1693)))

#define YYTABLE_NINF -1105

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    2127,     2, -1693,    61, 16597,   -44,   -87,   128,   128, 16597,
     350,   434, -1693, 16597,   616,   443, -1693, 14245, 16597, -1693,
   -1693, -1693, -1693, -1693,   685, -1693,   696,   115,   364,   135,
     427,   568,  1364,   682,  1250, 12775, 12481,   599, -1693, -1693,
   -1693, -1693, -1693, -1693, -1693, -1693, -1693, -1693, -1693, -1693,
   -1693, -1693, -1693, -1693, -1693, -1693, -1693, -1693, -1693, -1693,
   -1693, -1693, -1693,   847,   626, -1693, 16597, -1693, -1693, -1693,
   -1693, -1693, -1693, -1693, -1693, -1693, -1693, -1693, -1693, -1693,
   -1693, -1693, -1693, -1693, -1693, -1693, -1693, -1693, -1693, -1693,
   -1693, -1693, -1693, -1693, -1693, -1693, -1693, -1693, -1693, -1693,
   -1693, -1693, -1693, -1693, -1693, -1693, -1693, -1693, -1693, -1693,
   -1693, -1693, -1693, -1693, -1693, -1693, -1693, -1693, -1693, -1693,
   -1693, -1693, -1693, -1693, -1693, -1693, -1693, -1693, -1693, -1693,
   -1693, -1693, -1693, -1693, -1693, -1693, -1693, -1693, -1693, -1693,
   -1693, -1693, -1693, -1693, -1693, -1693, -1693, -1693, -1693, -1693,
     511,   465, -1693, -1693, -1693,  4332, 16597, -1693,   654,   654,
   -1693, 16597,   842,     0, -1693,   705,   -44,   826,   598, -1693,
   -1693, -1693, -1693,   731, -1693,   609,   705,  2480,  2480,  2127,
    2127,  2480, -1693, -1693,   756, -1693, -1693, -1693, -1693, -1693,
   -1693, -1693, -1693,   705,   705, -1693,   694, -1693,   705,   358,
     217,   704, -1693,   666,   751,   676, -1693, -1693, -1693,   764,
     774,   376,  1151,   974,   842, 15421, 16597, 16597, -1693,   649,
     877,  1077,   879, -1693,   109, -1693, -1693,   424, -1693, -1693,
     828, 16597,   833, -1693, -1693, 16597, -1693, -1693,   883,   894,
     901,   913, 16597, 16597,   922,   922, -1693, 16597, 16597,   845,
   -1693, -1693,   938, -1693,   993, 16597, 16597, 16597, 16597, 16597,
   16597,  1018,   790, 16597, 16597, 16597, 16597, 16597, 16597,   950,
     950,   950, 16597, 16597,  1030, -1693, -1693, -1693,  1048, 16597,
   16597, 16597,   990,  1119,  1120,  1121,  1022,  1023,   113,   959,
   -1693,  1118, -1693, -1693,  1200,    52,    52,    52,  1009, -1693,
    1025, 15715, 16597,  1308,  1308,  1308,  1309,  1140,  1141,  1142,
   -1693, -1693, -1693, -1693, -1693,  1143,  1145,  1300, -1693, -1693,
   -1693,  1154,  1154,  1154,  1154,  1154, -1693,  1155, -1693,  1156,
    1205, 16597,  1160,  1164,  1165,  1166,  1184,  1185,  1186,  1187,
    1189,  1190,  1191,  3297,  5022,  9682,  9682,  1193,  1195,  1196,
   -1693,  9682,  1308,   264,   450,    95,  7386,  1197,  1198,  5022,
   -1693, -1693,   367,   -83,  1182, -1693,  1421, -1693, -1693, -1693,
   -1693, -1693, -1693, -1693, 16597, -1693, -1693, -1693, 10284, -1693,
   -1693, -1693,  1039, -1693,  1029, -1693, -1693,  1031, -1693, -1693,
    1204,  1207,  1209,  1044, -1693, -1693, -1693, -1693, -1693, -1693,
    1308,  1308,   -71, -1693, -1693, -1693, -1693, -1693, -1693, -1693,
   -1693, -1693, -1693, -1693, -1693, -1693,   334,  1012, -1693,  1102,
   -1693,  1079,  1292,  1287, -1693,  1042, -1693, 16597, -1693, -1693,
    1064, -1693,  4332, -1693, -1693,  7714, 14245,  1087,  1256,  1263,
   -1693, -1693,  1264,  5712, -1693, -1693, -1693, -1693, -1693, -1693,
     104,  1151,   104,  1083, 13069,   395,  1291,  1296,  1288,   -27,
     842, -1693,   923,   537,   552,   634,  1235,   835, 16597, -1693,
      48,  1148, 16597,  1077,  1111, -1693, -1693,  1241, -1693, -1693,
     858,   922,   922,   922,   922,  1177,  1245,  1242, 16891, 16597,
     705,   861, 16597,   922, 16597,  1244,  1247,  1248,  1251, -1693,
   -1693, 16597,  1201, 16597, 16597, 16597, 16597,  1030,  1253,  1253,
    1253,  1253, -1693,  1317, 16597, 16597, 16597, -1693, -1693, -1693,
   -1693, -1693, 16597,   270, -1693, -1693,    27,  1155, 16597,  5022,
   16597,  1257,  1265, -1693,   525, -1693, -1693, -1693,  1268,  1273,
   -1693, -1693, -1693, -1693, -1693,  1391, -1693,  1274, -1693, -1693,
   -1693,  1277,  1278,   822, 16597, -1693, -1693, -1693,  1279,  1280,
    1281,  1286,  9682, -1693, -1693,  1294,  1294,  1294,    36,  1161,
    5022, -1693,  1283,   -18, -1693,  1289, -1693,  1135, -1693, -1693,
   -1693,  5022,  5022,  1441,  1314, -1693, -1693, -1693, -1693, -1693,
     281, -1693,   919,  1377, -1693,  9682,  9682,  9682,  1258,  1336,
     744,  1259,  1491,  9682,   725,  9682,  3297,  1322,  1324,   860,
     556,   924,   274, -1693,   110,  1421,  3297,  1136,  1136,  9682,
    9682,  9682,  1260, -1693,   685,  1329,   685,  1329, -1693, -1693,
    1308,  5022,  3055, -1693,   668,  9682,  9682,  1421,  -183,  2899,
   16597, -1693,  1025,  5022, 16597, -1693,  5022,  3642,  1090,  1090,
    1328,  1332,  9682,  9682,  9682,  9682,  3642,  1162,  9682,  9682,
    9682,  9682,  9682,  9682,  9682,  9682,  9682,  9682,  9682,  9682,
    9682,  9682,  9682,  9682,  9682,  9682,  9682,  9682,  9682,  9682,
    9682,  9682,   381,  1334,  1302,  4332,  1337,  6040,  9682, -1693,
   -1693, 13363, 14833,  1219,  1322, -1693,   380, -1693, -1693,  1432,
    1437, -1693, -1693, -1693,   765,   685,   842, -1693,  1344,  1407,
   -1693, -1693, 13350,   282, -1693, -1693,    59,  1276, -1693, -1693,
   -1693,  3297, -1693,   293, -1693, -1693,   954, -1693,    12, -1693,
   -1693, -1693,    87, -1693,  1018, 16597, -1693, -1693, -1693, -1693,
   -1693, -1693,   104,   104, -1693, -1693, -1693,  1267,   923,  1240,
    1249, -1693,  1422,  1356,  1077,  1077, -1693, -1693, -1693, -1693,
    1077,  2501,   552, -1693, -1693,  -110,   766,  1252,   928, -1693,
    1417,    41,    41, 16597,   705,  1214,  1077,   923,  1362,  2501,
     858, -1693, -1693, 16597, 16597, 16597, 16597,  1299,  1301, -1693,
    1444, 16597,  1297,  1325,     4,  1246, -1693, -1693,   971,  1298,
   16597,  1394, 16009, 16009, 16009, 16009,  1253, 16597,  1030,  1030,
    1030,  1030, -1693,  1713, -1693, -1693, -1693, -1693, -1693,  1030,
    1030,  1030, -1693, -1693, -1693,  1032, -1693, -1693, -1693,  1380,
    1118,   685,   685, -1693,  1547,   685,   685,   685, -1693,   157,
    1329,  1329, -1693, -1693, -1693, -1693, -1693,  1278,  1277,  1310,
   -1693, -1693, -1693,   685,   685,   685,   685,  1228, -1693, 11217,
    1469,   616,   616,   616, -1693, -1693, -1693,    36,  1087,  1380,
    1155, 15715,  1025,  4677, 16597,  1380,  1254,  1231, -1693, -1693,
   -1693, -1693, -1693, -1693, -1693,  1467, 16597, 13350,   592, 13350,
   -1693,   -52, -1693,  1423, 16597,  1406,  9682,  1236, -1693, -1693,
    9682, 16597, -1693,  1436,   592, -1693,  9682, -1693,  1487,   918,
    8042,   301, -1693, -1693, -1693,  1046,  5022, 14539,  1647, 11528,
    2377,  1416,  1305,  1308,  1419,  1308,   822,   114,  9682, -1693,
     686,  9682, -1693,  1304,  2405,  1266,   303,  5022, -1693, 13657,
    2176, -1693, -1693,  1270,   887, 17185, 17185, 17185,   127,    53,
   -1693, -1693,  1502,  1182, -1693,  1421, -1693, -1693, -1693,  1604,
    5022, -1693, -1693,  5022,  5022,  8370,  8370, -1693, 10595, -1693,
   -1693, -1693, -1693,  1155, -1693, 13350,  1136,  1136,  1136,  1136,
    1136,  1136,  1136,  1136,  1136,  1136,   917,   917,   917,  1260,
     709,   709,   709,   709,  1466,  1466,  1466,  1466,  1466, -1693,
    1505,  1290, -1693, -1693, -1693,  9682,  1447,  9682, 13350,  1448,
     204,  1282,  1454,  1462,  1463, -1693,   246, -1693,  1303, -1693,
   -1693, 16597,  1139,  1550, -1693, -1693, -1693, -1693,   300, -1693,
   -1693,  9682, -1693, -1693, -1693, -1693, -1693, -1693,  8370,  1379,
     104,  1533,  1387,  1533, -1693,    80,    80,  1308,  1392, 16597,
   16597,  1077,   438, -1693, -1693, -1693, -1693, -1693, 16597, 16597,
   -1693, -1693, 16597,  1560,  1146, -1693, 16597, 16597, 16303, 14245,
   -1693,  1541,  1338,  1541,   705,  1542, -1693, -1693,  1397,  1077,
   -1693, -1693,  1483,  1483,  1483,  1483, 16597,   374, -1693, -1693,
   -1693,  1637,  1399, 16597,  1425, 15127,  1561, -1693,  1346,   649,
   -1693,  1348, -1693,  1409, 16597,  1483, 16009, -1693,  1510,  1335,
    2501,  1512,  1513,  1516, -1693,  1030, -1693, -1693, -1693, -1693,
   -1693,  1521,  1352, -1693, -1693, -1693, -1693,  1524, -1693,  1525,
   -1693,  1526,   306,  1527,  1359, -1693,   318, -1693, -1693, -1693,
   -1693,  1395,   977,  1530,  1363,  1534,  1535,  1539,  9682, -1693,
   -1693, -1693,  1543, -1693, -1693, -1693, -1693, -1693, -1693, -1693,
   -1693, -1693, -1693, -1693,  1380, -1693,  2501,  2501,  9682, -1693,
     610,  1540,  9682,  1551,  1552, -1693,  1385,  8698, 13350,  -107,
   -1693,  1398, -1693,    32, -1693,  1386,  1628,  1423,  1562,  1574,
    1423,   651, -1693,   341, -1693, -1693, -1693,  1578,  1580,  1581,
    1421,  9682,  9682,  9682,  9682, -1693,  1458, -1693, -1693, -1693,
   -1693,  9682,  2606, -1693,  1443, 13350, -1693,  9682,  9682, -1693,
    9682,  1421, 17185, 17185,  2176,  1322,  1586,  1587,  1588,   896,
     616,  2899, -1693, -1693, -1693,   998,  1688, -1693,  2899,  1689,
    1696, 16597, -1693,  1596, -1693, -1693, -1693, 14245, 16597, -1693,
    1666,  1664,  1604,  1358,  1374,   351,   363,  1308, -1693, -1693,
    1671,  1605,  1678,  1608, -1693,  1618, -1693, 13951,  9682, 16597,
   -1693, -1693, -1693, -1693, -1693, -1693,  1531, -1693,   374, -1693,
    1536, -1693, -1693, -1693,  1777,  1308, -1693, -1693, -1693, -1693,
   -1693,  1030,  1030,  1030, -1693, -1693, -1693,   481, -1693, 16597,
   -1693, -1693, -1693,   636,  1169, -1693,  1473, -1693,  1308, -1693,
    1690,    51,  1308, -1693, -1693, -1693,  1544, -1693, -1693, -1693,
   -1693, -1693,  1537, 16597,   760, -1693, -1693, 14245, 16597,   366,
   -1693, -1693, -1693, -1693,   130, 16597, -1693,   649,  1633, 16597,
   16597,  1626,  1545,  1634, 10297, 16597, -1693,  1576,  1572,  1579,
   -1693, -1693,  2501, -1693, -1693, -1693, -1693,   685, -1693,   685,
   -1693,   685,  1278, -1693, -1693, -1693,   685, -1693, -1693, -1693,
   -1693, 16597,  1640,  1642, 11833, -1693, -1693, -1693, -1693, -1693,
   -1693,  6368,  1423,  1568,  9682, 13350,   368, -1693,  1498, -1693,
   -1693,   718,  9682,  1423, 16597, -1693,  1680,  1681,  1652,  9682,
    1423,   627,  9682, -1693,  1628, -1693,  1553,  1655, -1693,  1657,
   -1693,  8042,  8042,  8370,  8370, 10907,  1755, 12144,  2567, -1693,
   -1693,  9682, -1693, 12469, -1693, -1693, -1693, -1693,   369, -1693,
   -1693, -1693,   -37,   887,  1757,  2899,   325,  2899, -1693, -1693,
    1662, 16597,   254, -1693, 16597,  5022, -1693,  5022,  5022, -1693,
   -1693, -1693, 16597, -1693,  1732,   -33, -1693, -1693,  1663,  1675,
   -1693, -1693, -1693, -1693,  1519,  1592, -1693, -1693, -1693,  1617,
     638, -1693,  1606,  1607,   705, -1693, -1693, -1693, -1693,   821,
   -1693,  1308,  1528,   100,  1308,  1695,  1695,  1529, -1693,  1636,
    1872, 16597, -1693,  1532, -1693,  1410,  1431, -1693,   760, -1693,
   -1693, -1693, -1693, -1693, -1693, -1693, -1693, -1693, 15127,  1610,
    1876,  1709,  1653, -1693,  1546,  1563, 16597,  1806, -1693,  1648,
     -44,   350,   434,  1646, 14245,  3987,  9026,  5022,  1583, -1693,
   -1693, -1693, -1693, -1693, -1693, -1693, -1693, -1693, -1693, -1693,
   -1693, -1693, -1693, -1693, -1693,  1591, -1693, -1693, -1693, -1693,
    1556,  2501,  1998,  1881,  1998, -1693,  1719, -1693,  1723,  1730,
   -1693,  1731,   382, -1693,  1564, -1693, -1693, -1693,  1734, 13350,
    1566, -1693,   200, -1693,  1567,  1738, -1693, -1693, -1693,  8698,
   16597,  1650,  1654,  1656,  1659, -1693, -1693,  1748, -1693, -1693,
   -1693, -1693, -1693,   635,  1752, -1693, -1693,   377,  1589, -1693,
   -1693, -1693,   584, -1693,  1765, -1693, -1693, -1693,   384,   385,
     392,  9682, -1693, -1693,  9682, -1693,  9682, -1693, -1693, -1693,
   17185,  2899, -1693,   705,  5022, -1693,   325, 16597,   397,  1593,
    1380,  1740,  1740,  1593,  9682, -1693, -1693, -1693,  5367, -1693,
   -1693,  1679,  1665, -1693,   706, -1693,  1822,  9682,   705,   705,
   -1693,  1811, -1693,  9682, -1693,   821, -1693, -1693, -1693, -1693,
     523, -1693,  1308,  1858,   398, 16597,    41,    41,  1308,  1308,
   -1693, -1693, 16597, -1693, -1693,  1771,  1770, -1693,   582, -1693,
    1708,   909,  1832,   412,   349,  1707,  4332, 16597, -1693,  1802,
   -1693,  1803, -1693, -1693,  1380,  5022, -1693,   693,  9973,   190,
   -1693, 11541,  5022, -1693, -1693,  1804, 10608, -1693,  1238,   565,
   -1693, -1693, -1693, -1693, -1693, 16597, 16597,  9682,  9682,  9682,
   -1693,  9354, -1693, -1693, -1693, -1693,  1868,   639,  1869,  1871,
   -1693, -1693, 16597, -1693, -1693,  9682,  1717,  1718,  1810,   343,
   -1693, -1693, -1693, 12763, 13057, 13645, -1693, -1693, -1693,  1380,
   -1693,   423, -1693,  1228,  6696,  1658,  1649,  1667,  1660, -1693,
   -1693, -1693,  1308, 16597, -1693, -1693, -1693, -1693,  1548,  1715,
   -1693,  1670, -1693, -1693, -1693,  1875,  1816,  1743, 16597, -1693,
   -1693, -1693,  1651,  1767, -1693, -1693,   433, -1693,  1991,  1541,
    1541, -1693,  1725, -1693,   557,  1836, -1693, -1693,   155,   455,
     909, -1693,  1677, -1693,  1710, -1693,  1925,  1926, -1693, 16597,
    1750, -1693,  1669,  9682,   722,   232, -1693, -1693,  1701,  9682,
   -1693,   778, -1693, 11541,  1883,   436, 16597,  1779,  2014, -1693,
   -1693, -1693, -1693,  1782,  2016, -1693,  1691, 13350,   453, -1693,
    1720, -1693, -1693,  1694, -1693, -1693,  1886, -1693, -1693, -1693,
    1628, -1693,  1890,  1891, -1693,  1889, 16597,  2043,   674, -1693,
   -1693, -1693, -1693, -1693, -1693,  1857, -1693, -1693, -1693,    75,
   -1693, -1693, -1693, 16597,  1919, -1693,  5022, -1693,   705,  1308,
   -1693, -1693, 16597, -1693,  1990,  1990, 16597,   460, -1693, -1693,
    1473, -1693,  1473,  1473,  1473, -1693,   926,  1880, 11845, -1693,
   -1693, -1693, 16597,   468, 13350,  1882, -1693, 10919,  1753,  2635,
   -1693,  1744,  9986,  1921,  1745, -1693,   477,  2501, 16597,  1238,
   16597,  1238, -1693,  9682, 16597, -1693,  9682, -1693, -1693, -1693,
   -1693,  1898, -1693, -1693, -1693,  1898, -1693,  1904, 16597,  2043,
   -1693, -1693, -1693,  1908,  7041,  1722, -1693,  1735, -1693,   705,
    1892,   662,  1953, -1693, -1693, -1693,  2008,  2008, -1693, -1693,
     557, 16597, 16597, 16597, 16597, -1693, -1693, -1693,  5022,  1758,
   -1693, -1693, -1693, -1693, -1693, -1693, -1693, -1693, -1693, -1693,
   -1693, -1693,  9682, -1693, 10919,  1938, -1693, -1693,  1772, -1693,
    5022,  1759,  1761, -1693, 11230, -1693, 16597, -1693, -1693, -1693,
   -1693, -1693, -1693, -1693, -1693, -1693,  2043, -1693, -1693, -1693,
   -1693, -1693, -1693, -1693, -1693, -1693,  1754,  1742,  1733, -1693,
   -1693, -1693, -1693,  1953,   858, -1693, -1693,   784,  1819,  2025,
    1858,  1858, -1693, -1693, -1693, -1693, -1693,   663, -1693, 13350,
   -1693, 10919, -1693, 10919,   345,  1781, -1693,  1780,  2501, -1693,
   -1693, -1693, -1693, -1693,  1819,   652, -1693, -1693, -1693, -1693,
    1192,  1826,  1827, -1693, -1693, -1693,  1774, -1693, 12156, -1693,
   -1693, 16597, -1693, -1693, -1693,    85,    85,  2031, -1693,  2032,
   -1693,  1923, -1693, -1693,  1965,  9986, -1693, -1693, -1693, -1693,
    2059,   372, -1693, -1693,  1077, -1693, -1693, -1693, -1693, -1693,
     485, -1693, -1693,  1077, -1693
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,    17,     0,     0,   506,     0,   441,   441,     0,
       0,     0,    15,     0,     0,    18,    27,     0,     0,     7,
       5,     9,    11,     3,     0,    25,     0,    85,    26,     0,
     469,     0,    19,     0,     0,     0,     0,     0,    34,    35,
      28,    29,    30,    33,    31,   143,   142,   140,   141,    37,
     144,    32,   415,   414,   420,   419,   416,   418,   417,   532,
     550,   538,   539,   588,     0,    16,     0,   909,   910,   912,
     913,   914,   915,   917,   919,   966,   922,   930,   991,   953,
     927,   968,   941,   952,   946,   925,   990,   960,   947,   936,
     937,   938,   934,   928,   944,   969,   970,   971,   972,   973,
     974,   975,   976,   977,   978,   979,   980,   981,   982,   983,
     984,   985,   945,   911,   987,   986,   932,   926,   918,   951,
     988,   989,   963,   939,   964,   965,   961,   962,   935,   920,
     924,   950,   948,   921,   923,   940,   967,   943,   933,   954,
     955,   956,   957,   958,   959,   929,   992,   931,   949,   942,
       0,   825,   916,   507,   508,     0,     0,   440,   444,   444,
     422,     0,   428,     0,   535,   272,   506,     0,     0,   737,
     735,   736,   322,     0,   732,   734,   272,     0,     0,     0,
       0,     0,   997,   996,     0,  1000,   903,   904,   905,   906,
     907,   908,   104,   272,   272,   103,    99,   108,   272,     0,
       0,     0,    89,    91,     0,   100,   101,    75,   902,     0,
       0,     0,     0,     0,   428,     0,     0,     0,   995,     0,
       0,     0,     0,   266,     0,   269,   268,     0,   853,     1,
       0,     0,     0,   170,   171,     0,   188,   187,     0,     0,
       0,     0,     0,     0,    23,    23,   169,     0,     0,     0,
     137,   138,     0,   139,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
      21,    21,     0,     0,   411,   805,   807,   806,   953,     0,
     924,   940,   955,     0,     0,     0,   987,   986,    23,    40,
      41,     0,   262,     2,     0,   551,   551,   551,   590,    13,
     515,     0,     0,   998,   909,   910,   912,   913,   914,   915,
     811,   810,   809,   812,   813,     0,     0,     0,   899,   822,
     823,   744,   744,   744,   744,   744,   686,     0,   500,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     755,     0,   954,   955,   956,   957,     0,     0,     0,     0,
     700,   699,   559,   759,   585,   616,   587,   606,   607,   608,
     609,   610,   611,   612,     0,   613,   683,   682,   614,   654,
     698,   687,     0,   689,   691,   693,   694,   557,   753,   684,
       0,     0,     0,   690,   685,   761,   817,   688,   696,   695,
       0,     0,   828,   808,   697,  1011,  1012,  1013,  1014,  1015,
    1016,  1017,  1018,  1019,  1020,   774,   490,     0,   421,   445,
     423,     0,     0,     0,   425,   429,   430,     0,   533,   537,
       0,   273,     0,   549,    20,     0,     0,   596,     0,     0,
      10,    12,     0,     0,   105,   106,    98,   107,    93,    94,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     428,   427,   175,     0,     0,     0,     0,   588,     0,   471,
       0,     0,     0,     0,   470,   192,   191,     0,   190,   189,
       0,    23,    23,    23,    23,     0,    69,     0,     0,     0,
     272,     0,     0,    23,     0,     0,     0,     0,     0,   403,
     146,     0,     0,     0,     0,     0,     0,   411,   406,   406,
     406,   406,   402,     0,     0,     0,     0,   404,   405,   413,
     412,   394,     0,     0,    49,    47,     0,     0,     0,     0,
       0,   884,   879,   893,   855,   894,   896,   897,   868,   871,
     863,   864,   866,   867,   865,   874,   876,   886,   890,   889,
     784,   781,   783,     0,     0,   877,   878,    42,   881,   856,
     857,   861,     0,   552,   553,   554,   554,   554,     0,   593,
       0,   486,     0,   559,   509,     0,   901,   826,   999,   821,
     819,     0,     0,     0,     0,   739,   741,   740,   743,   742,
       0,   643,     0,     0,   729,     0,     0,     0,     0,  1054,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   587,     0,   691,   828,   615,     0,   679,   680,     0,
       0,     0,   674,   814,     0,   779,     0,   779,   775,   776,
       0,     0,     0,   846,   848,     0,     0,   644,     0,     0,
       0,   540,   515,     0,     0,   758,     0,     0,   621,   621,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   820,
     818,     0,     0,     0,     0,   493,   490,   488,   442,     0,
       0,   424,   433,   432,     0,     0,     0,   534,     0,   559,
     730,   838,   501,     0,   733,   734,     0,    38,     8,     6,
       4,     0,  1001,     0,   504,   498,   505,   111,    79,   109,
     112,    76,    77,    92,   985,   943,    90,    97,    96,   102,
      86,    88,     0,     0,   426,   177,   176,     0,   175,     0,
       0,   120,     0,   156,     0,     0,   166,   164,   162,   167,
       0,     0,   147,   150,   159,   136,     0,   136,   136,   267,
       0,   463,   463,     0,   272,     0,     0,   175,     0,     0,
     145,   148,   154,     0,     0,     0,     0,     0,     0,   173,
       0,   932,    58,    54,   272,     0,   361,   362,     0,     0,
       0,     0,   357,   357,   357,   357,   406,     0,   411,   411,
     411,   411,   401,     0,   391,   388,   392,   390,    22,   411,
     411,   411,    46,   274,    50,   777,    51,    45,    48,    44,
       0,     0,     0,   895,     0,     0,     0,     0,   875,     0,
     779,   779,   787,   788,   789,   790,   791,   783,   781,     0,
     803,   804,   263,     0,     0,     0,     0,   589,   600,   603,
     555,     0,     0,     0,   592,   591,   852,     0,   596,   516,
       0,     0,   515,     0,     0,   833,     0,     0,   900,   745,
     795,   796,   793,   792,   794,     0,     0,     0,   654,  1010,
    1008,  1091,  1007,  1091,     0,     0,     0,     0,  1089,  1090,
       0,     0,  1071,  1072,   654,  1088,     0,  1087,   588,     0,
       0,     0,   653,   651,   681,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   843,
     848,     0,   847,     0,     0,     0,     0,     0,   646,     0,
       0,   570,   569,   560,   561,   568,   576,   576,   825,   559,
     543,   545,   578,   584,   760,   586,   642,   640,   641,   618,
       0,   622,   623,     0,     0,     0,     0,   624,   628,   626,
     625,   627,   617,     0,   647,   670,   655,   656,   661,   671,
     660,   675,   676,   677,   678,   751,   657,   658,   659,   672,
     662,   667,   665,   663,   664,   666,   668,   669,   673,   631,
       0,   705,   757,   754,   702,     0,     0,   935,   850,     0,
     828,     0,   913,   914,   915,   756,   829,   491,   492,   489,
     443,     0,     0,     0,   439,   434,   435,   431,     0,   536,
     731,     0,   598,   599,   597,    39,    36,  1002,     0,     0,
       0,    81,     0,    81,    95,    81,    81,     0,     0,     0,
       0,     0,     0,   163,   161,   165,   155,   151,     0,     0,
     135,   116,     0,     0,     0,   115,     0,     0,   232,     0,
     468,   474,     0,   474,   272,     0,   472,   473,     0,     0,
     152,   149,   272,   272,   272,   272,     0,     0,    24,    55,
      57,     0,  1003,     0,     0,   232,   178,   198,     0,     0,
     364,   365,   363,     0,     0,   272,   357,   356,     0,   355,
       0,     0,     0,     0,   389,   411,   398,   395,   399,   397,
     408,     0,   409,    53,   393,   400,    43,     0,   851,     0,
     898,     0,     0,     0,   851,   891,     0,   892,   785,   786,
     801,   800,     0,     0,   851,     0,     0,     0,     0,   604,
     605,   602,     0,   546,   547,   548,   595,   594,   542,   514,
     510,   487,   511,   512,   513,   827,     0,     0,     0,   692,
       0,     0,     0,     0,     0,  1033,  1025,     0,  1059,  1046,
    1056,  1060,  1055,   654,  1067,  1068,     0,  1091,     0,  1108,
    1091,   651,   503,     0,   502,   496,   652,     0,     0,     0,
     637,     0,     0,     0,     0,   780,     0,   815,   782,   816,
     824,     0,     0,   844,     0,   849,   837,     0,     0,   835,
       0,   645,     0,   576,     0,     0,   569,     0,     0,   522,
       0,     0,   527,   528,   529,   522,     0,   523,     0,     0,
     525,   931,   566,   575,   577,   564,   563,     0,     0,   541,
       0,   582,   639,     0,     0,     0,     0,     0,   638,   630,
       0,     0,   707,     0,   768,     0,   772,     0,     0,     0,
     446,   436,   437,   438,   839,   499,     0,   110,     0,    74,
       0,    73,    83,    84,     0,     0,   121,   124,   160,   158,
     157,   411,   411,   411,   118,   119,   117,     0,   114,     0,
     113,   205,   206,     0,     0,   449,   375,   452,     0,   451,
       0,     0,     0,   153,   182,   183,     0,   184,   275,    71,
      72,    70,     0,     0,    60,  1004,    56,     0,     0,     0,
     207,   203,   208,   209,   901,     0,   180,     0,   270,     0,
       0,     0,   193,     0,   347,     0,   359,     0,     0,     0,
     396,   407,     0,   885,   880,   858,   869,     0,   872,     0,
     887,     0,   783,   798,   802,   882,     0,   859,   860,   862,
     601,     0,     0,     0,     0,  1093,  1092,  1021,  1009,  1022,
    1023,     0,  1091,   968,     0,  1100,     0,  1095,     0,  1097,
    1098,     0,     0,  1091,     0,  1058,     0,     0,     0,     0,
    1091,     0,     0,  1074,  1081,  1085,     0,     0,  1109,     0,
     494,     0,     0,     0,     0,     0,     0,     0,     0,   778,
     845,     0,   836,     0,   840,   841,   567,   565,     0,   517,
     650,   648,     0,   562,     0,     0,   522,     0,   526,   524,
     573,     0,   826,   544,     0,     0,   558,     0,     0,   632,
     633,   629,     0,   701,     0,   709,   771,   770,     0,     0,
     830,    80,    82,    78,     0,   123,   133,   134,   132,     0,
       0,   233,     0,     0,     0,   231,   210,   211,   213,   214,
     376,     0,   464,     0,     0,   457,   457,   482,   484,     0,
       0,     0,   993,  1006,  1005,    19,     0,    52,    61,    62,
      64,    65,    68,    66,    67,   181,   264,   197,   232,     0,
       0,   200,     0,   265,   366,   367,     0,     0,   186,     0,
     506,   927,   941,     0,     0,     0,     0,     0,   291,   303,
     304,   297,   298,   299,   302,   300,   286,   288,   305,   316,
     315,   320,   319,   318,   317,     0,   301,   296,   295,   306,
       0,     0,     0,     0,     0,   410,     0,   854,     0,     0,
     799,     0,     0,   580,   828,   831,   832,   738,     0,  1045,
    1030,  1032,  1046,  1043,  1026,     0,  1103,  1102,  1094,     0,
       0,     0,     0,     0,     0,  1047,  1057,     0,  1062,  1061,
    1064,  1065,  1063,   654,     0,  1107,  1106,   654,  1073,  1075,
    1077,  1078,     0,  1082,     0,  1086,  1133,   497,     0,     0,
       0,     0,   748,   749,     0,   750,     0,   842,   834,   649,
       0,     0,   518,     0,     0,   519,   522,     0,     0,   579,
     583,   619,   620,   706,     0,   711,   712,   704,     0,   769,
     773,     0,     0,   129,     0,   127,     0,     0,     0,     0,
     258,     0,   228,     0,   212,   215,   216,   221,   222,   223,
       0,   475,     0,   480,     0,     0,   463,   463,     0,     0,
     185,    59,     0,    63,   204,   901,     0,   179,     0,   199,
       0,     0,   380,     0,     0,     0,     0,     0,   321,     0,
     324,   943,   329,   328,   330,     0,   338,   340,     0,     0,
     291,   347,     0,   348,   358,     0,   347,   354,     0,     0,
     870,   873,   888,   883,   556,     0,     0,     0,     0,     0,
    1042,     0,  1024,  1096,  1099,  1101,     0,     0,     0,     0,
    1053,  1066,     0,  1079,  1105,     0,     0,     0,     0,     0,
     495,   634,   635,     0,     0,     0,   571,   521,   531,   530,
     520,     0,   574,   708,     0,     0,     0,   654,   724,   713,
     716,   714,     0,     0,   130,   131,   128,   126,   682,     0,
     259,     0,   224,   217,   253,     0,     0,     0,     0,   254,
     226,   257,   465,     0,   450,   483,     0,   459,   461,   474,
     474,   485,     0,   994,   232,     0,   202,   271,   377,   377,
     368,   369,     0,   360,   384,   168,     0,     0,   196,     0,
       0,   285,     0,   325,     0,     0,   291,   339,     0,     0,
     335,   340,   291,   347,     0,     0,     0,     0,   951,   280,
     277,   287,   278,     0,     0,   581,   829,  1040,     0,  1035,
    1038,  1031,  1044,  1027,  1029,  1048,     0,  1051,  1050,  1049,
    1104,  1076,     0,     0,  1070,     0,     0,     0,  1122,  1111,
    1112,   746,   747,   752,   572,     0,   717,   715,   718,     0,
     710,   122,   125,     0,     0,   252,     0,   255,   272,     0,
     481,   458,     0,   462,   476,   476,     0,     0,   219,   201,
     375,   378,   375,   375,   375,   370,     0,     0,   347,   194,
     195,   282,     0,     0,   326,     0,   291,   341,     0,     0,
     336,     0,   343,     0,   292,   291,     0,     0,     0,     0,
       0,     0,  1034,     0,     0,  1037,     0,  1052,  1080,  1083,
    1084,  1117,  1121,  1120,  1116,  1117,  1115,     0,     0,     0,
    1110,  1123,  1124,  1126,     0,     0,   726,     0,   727,   272,
     229,     0,   250,   466,   460,   477,   478,   478,   174,   218,
     232,     0,     0,     0,     0,   382,   383,   381,     0,     0,
     311,   312,   309,   310,   386,   313,   379,   308,   307,   314,
     276,   323,     0,   331,   337,     0,   333,   291,     0,   291,
       0,     0,   292,   289,   347,   353,     0,   351,   279,   281,
     283,   284,  1036,  1041,  1039,  1028,     0,  1114,  1113,  1129,
    1132,  1128,  1131,  1130,  1125,  1127,     0,     0,   654,   719,
     721,   728,   725,   250,     0,   227,   261,   246,   241,     0,
     480,   480,   220,   374,   372,   373,   371,     0,   293,   327,
     292,   334,   332,   344,     0,     0,   290,     0,     0,  1119,
    1118,   722,   720,   723,   241,     0,   248,   249,   247,   251,
       0,   242,   243,   256,   479,   448,   453,   385,   347,   291,
     342,   349,   352,   260,   230,     0,     0,     0,   245,     0,
     244,     0,   447,   387,     0,   343,   346,   350,   235,   236,
       0,     0,   240,   239,     0,   294,   345,   234,   237,   238,
       0,   455,   454,     0,   456
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1693,  1080, -1693, -1693, -1693, -1693, -1693, -1192, -1693,  1010,
     173, -1053, -1693, -1693,   805, -1693,    15, -1693,    20,   425,
   -1693,  1011, -1693, -1693, -1693,   608, -1693,   829,     1,  1896,
   -1693, -1693,    -2,     8, -1693, -1693,  1900, -1693,  1661, -1693,
   -1693, -1693,  1668,  -418,  1069,    55, -1693, -1693, -1693,   515,
      68, -1693,    88, -1693,  -777,  1351,  -411, -1693, -1693, -1693,
      17, -1693,  2079, -1693, -1693,  -929, -1693, -1693, -1693,  1051,
     612, -1693, -1693, -1693, -1693, -1693, -1693, -1586, -1693,   463,
   -1693, -1693, -1693, -1693, -1019,    45,    60,    63,    71, -1693,
     103, -1693, -1693, -1693,   -13, -1693, -1693,  -200,  -412, -1693,
    -155,   -29, -1693, -1692,  -981, -1693,   426, -1346, -1693, -1294,
      62, -1375, -1693,   539, -1693, -1693, -1693, -1693, -1693, -1693,
     308, -1693,   441, -1693,   310, -1693,    54, -1693, -1693, -1693,
   -1693,   579,  -722, -1693, -1693, -1693, -1693, -1693, -1693,   365,
    -886,   373, -1693, -1693, -1693, -1693, -1693,  1712,   101,  -423,
     812,  -429,    25,    37, -1693,  -118, -1693,  1461, -1693,  2160,
    2012, -1693, -1693, -1693, -1693,   687, -1693,   292,  -760, -1693,
   -1693, -1044,   290,   219,  -746,   697,   695, -1693, -1693, -1693,
    1481,  -650,   775,  -894, -1693,  -379,   777,  1152,  -164, -1693,
   -1693,  1318,  -538,  -876,   960, -1693, -1693,   570,   415, -1693,
    1773, -1693, -1693,    42,   225, -1693,   949,    22,   994,   726,
    -425,  1261,  1630, -1693,  -622, -1693,  -923,  -868, -1693, -1281,
   -1693,  -263,  1558,  1307, -1693, -1693,  1340,   575,  1063, -1693,
   -1693,  -284, -1693, -1693,  1569, -1693,   530, -1693, -1693, -1693,
   -1693,  1565, -1693, -1693,  1555, -1693,  1508,  -262,  -753,  1482,
    -568,  -474, -1693, -1693, -1693, -1693, -1693, -1693, -1693, -1693,
     466, -1693, -1693, -1693, -1693, -1693, -1693,     7, -1693,  -395,
   -1693,   925, -1693, -1693,  1538, -1693, -1693, -1693, -1693, -1693,
   -1693, -1693,  -332,  -484,  -524, -1693,  -562, -1693, -1693, -1693,
   -1693, -1693,  1293, -1693,  2187, -1693,  1698,    73, -1326, -1693,
    1643, -1693, -1693, -1693,  1306, -1693,  1595, -1693,  1311,  -655,
     243,  -665,  -203, -1693,  -245, -1693,  -275, -1693, -1693,  -265,
    -290,    81, -1693,    -4, -1693, -1333,  -469,    34,     9, -1693,
   -1693, -1693, -1693, -1693,  -557, -1693, -1693, -1693, -1693, -1693,
   -1693, -1693, -1693, -1693,   505, -1693,   304, -1693, -1693, -1693,
   -1621, -1693,   512,   658, -1693, -1693, -1693, -1693,   840, -1693,
   -1693, -1693, -1693, -1693, -1693, -1693, -1693, -1693, -1693, -1693,
   -1693, -1693,   498, -1693, -1693, -1693, -1693, -1693, -1693, -1693,
    1631,  -830,   853, -1693,   659, -1693,   856, -1693, -1693,   387,
   -1094, -1693, -1693, -1693, -1693, -1693, -1476,   312, -1693, -1693,
   -1693, -1693, -1693, -1693,   305, -1693, -1693, -1693, -1693
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    31,   181,   178,   177,   179,   180,    32,    33,   514,
     489,    34,    35,    36,    37,  1036,  1529,   289,  1530,  1531,
     792,  1089,  1092,  1497,  1498,  1499,   789,  1321,  1532,   200,
    1043,  1041,  1279,  1533,   211,   212,   201,   202,   203,   736,
     204,   205,   206,   728,   729,  1534,   751,  1065,  1061,  1062,
    1535,    45,   780,   762,   781,   763,   782,    46,   249,   250,
     747,  1336,   251,   252,  1518,  1096,  1097,  1679,  1329,  1330,
    1331,  1478,  1301,  1654,  1655,  1332,  1887,  1656,  1657,  1767,
    1658,  1659,  2025,  1302,  1660,  2092,  2061,  2062,  2063,  2059,
    2028,  1780,  1475,  1781,   523,  1333,   253,   222,   223,  1513,
    1098,   431,    47,  1811,  1831,    48,  1536,  1701,  2068,  1985,
    1974,  1538,  1539,  1540,  1688,  1689,  1903,  1541,  1693,  1542,
    1820,  1821,  1696,  1697,  1818,  1543,  1991,  1544,  1545,  2086,
    1916,  1706,  1108,  1109,    50,   798,  1103,  1682,  1800,  1801,
    1481,  1892,  1803,  1804,  1967,  1898,  1976,   274,  1546,   814,
    1121,   521,  1547,  1548,    54,   424,   425,   426,  1025,   158,
     418,   701,    55,  2082,  2100,  1666,  1786,  1787,  1071,  1072,
     224,  1307,  1956,  2030,  1784,  1486,  1487,    56,    57,    58,
     697,   911,  1193,   723,   361,   724,  1195,   725,   155,   573,
    1163,   574,   571,   942,  1239,  1439,  1240,  1625,   225,   163,
     164,   428,    60,  1549,   226,   949,   950,    63,   565,   861,
     362,   641,   642,   943,  1229,  1230,  1244,  1245,  1251,  1562,
    1446,   363,   364,   298,   569,   868,   717,   857,   858,  1151,
     365,   366,   367,   368,   963,   369,   967,   370,   371,   612,
     372,   960,   373,   638,   374,   375,   945,   376,   377,   378,
     379,   380,   381,   382,  1261,  1262,  1455,  1637,  1638,  1758,
    1759,  1760,  1761,  2019,  2020,  1870,   383,   613,   173,   174,
     385,   585,   386,   387,   388,   645,   389,   390,   391,   392,
     393,   630,   923,   625,   627,   555,   848,   884,   885,   849,
    1364,   850,   851,   556,   394,   395,   396,   947,   397,   398,
     876,   399,   713,   936,   929,   930,   633,   634,   933,  1009,
    1127,   865,   227,  1556,  1122,  1136,   400,   559,   560,   401,
    1304,   730,   208,   614,   152,  1493,   228,  1128,   403,    64,
     185,  1324,  1325,  1494,   890,   891,   892,   404,   405,   406,
     407,   408,  1382,  1176,  1570,  1838,  1839,  1925,  1840,  2004,
    1571,  1572,  1573,  1393,  1585,   409,   896,  1179,  1180,  1181,
    1395,  1589,   410,  1398,   411,  1185,  1400,   412,   903,  1187,
    1402,  1598,  1599,  1600,  1601,  1602,  1738,   413,   414,   906,
     900,  1171,   897,  1386,  1387,  1725,  1388,  1389,  1390,  1733,
    1734,  1407,  1408,  1858,  1859,  1935,  1936,  2007,  2050,  1860,
    1933,  1940,  1941,  2014,  1942,  1943,  2013,  2011,   415
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     151,    41,   432,  1081,   695,   160,   283,   709,    42,   165,
     430,   575,  1073,   175,   151,    38,   558,   944,   469,   466,
      39,   437,  1242,   291,   172,    52,   561,   888,   841,  1309,
     883,   285,   292,  1011,   732,   904,   167,    53,   444,   445,
     893,   714,    61,   447,  1018,  1563,   557,   218,   908,  1303,
    1537,   303,  1635,   764,   303,    43,   711,  1070,   184,   611,
     615,  1173,   151,  1174,  1226,   591,   166,   840,    44,  1773,
     218,  1255,  1256,  1032,  1188,   637,  1303,   150,   812,  1246,
     610,  1111,  1112,  1113,   743,   824,   815,   816,   817,  1053,
    1054,   176,  1403,   639,   864,  1055,   461,  1841,  -777,   866,
    1844,    51,  -734,   303,   952,   643,  1170,   207,  1628,   186,
     187,   188,   189,   190,   191,  1094,  1396,  1901,  1563,  1058,
     -87,   -87,   -87,   -87,   -87,   -87,  1563,  2088,  2089,   295,
     296,   297,  1495,  -943,   153,    65,   471,  -943,  -943,   300,
    -943,  -943,  -943,  -943,  -943,  -943,  -943,  -943,  -943,  -943,
    -943,   402,   151,  1314,  1315,  1316,  1317,   420,  1945,  1391,
     303,   937,   384,  1629,   639,   938,  -943,  -943,  2090,  1059,
    1060,  1633,    66,    14,  1397,   156,  1342,  1095,    41,    41,
      41,    41,    41,  1039,  1946,    42,    42,    42,    42,    42,
     215,  1278,    38,    38,    38,    38,    38,    39,    39,    39,
      39,    39,    52,    52,    52,    52,    52,   154,  1888,   157,
    1135,   463,   151,   151,    53,    53,    53,    53,    53,    61,
      61,    61,    61,    61,  1484,    62,  1998,   477,  2000,   416,
     563,   151,    43,    43,    43,    43,    43,  1392,   151,   486,
     644,   467,  1033,   151,   151,    44,    44,    44,    44,    44,
     216,   151,   151,   151,   151,   499,   151,   935,  1042,   151,
     151,   151,   151,   151,   512,   827,   829,  -781,   151,   151,
     775,  1496,   572,  1484,   691,   292,   524,   525,    51,    51,
      51,    51,    51,  -734,   695,   866,   866,   628,   629,   464,
     465,   866,  1172,   207,  1751,   925,   714,   576,   577,  1426,
    -734,  1509,   643,   564,  -262,  2005,  1495,   869,   480,  1636,
    1603,  1620,   578,   579,   580,   485,   825,   451,   875,   875,
     490,   491,   611,  1140,  1045,  1046,   871,   594,   495,   496,
     497,   498,  1183,   500,  1161,   795,   507,   508,   509,   510,
     511,  1623,   744,   610,   427,   517,   518,   166,  1226,  1189,
    1263,   764,  1265,   610,  1823,  1427,  1040,  1404,  -467,  2091,
    1409,   623,   955,   959,  1141,   609,   166,   771,   927,  1485,
     151,   472,   972,   209,  2032,   727,   210,  -734,   643,  1116,
    1117,  1118,  1119,  1114,  1343,   360,  1288,   696,   429,  1835,
    1123,  1124,  1125,  1156,  1232,  1233,  1234,  1248,  1235,  1236,
     166,  1237,    62,    62,    62,    62,    62,  1824,   360,   689,
     690,  1947,  1537,  1806,   217,    59,  1948,   488,  1211,  -734,
     643,   487,   213,   165,  1040,    40,  1855,  -734,   402,   161,
    1319,  1040,   715,  1807,  1890,  -781,  1320,   624,   218,   384,
     192,   193,   194,   195,   823,  1496,   166,   657,   915,   218,
     151,   214,    13,  -783,    14,   917,  1030,  -943,   610,   192,
     193,   194,   195,  2012,   151,   726,  1391,  1037,   151,   448,
    1907,    13,  1247,    14,  -262,  1196,  1912,  1219,   639,   772,
    1356,  1401,  2098,  1891,   793,   151,   558, -1104,   799,  1303,
     151,   999,  1360,   166,  1822,  1238,   561,   151,   450,   151,
     151,   151,   151,  1856,   558,    13,  1857,   692,  1138,  1139,
     151,   151,   151,  1034,   561,  1410,  1056,   830,   822,  1609,
    1610,   162,   714,  1975,   828,  1449,   292,   738, -1104,  1913,
    2049,  1194,   731,   643,  1080, -1104,  1906,  1450,   558,    49,
    1507,   770,  1578,  1619,  1719,   774,   833,   834,   561,  1267,
     852,    13,  1575,    14,   196,   558,  1714,  1000,  1740,  1741,
    1984,   451,   794,  1587,   607,   561,  1742,   801,   229,  1994,
    1594,  1752,  1785,  1077,   806,  1428,   808,   809,   810,   811,
    1363,   575,   866,  1225,   693,  1126,  1805,   819,   820,   821,
    1624,  1269,    59,    59,    59,    59,    59,  1864,    13,   874,
     219,  1808,    40,    40,    40,    40,    40,  1881,  1159,  1433,
    1164,   590,   609,  1459,   554,  1378,  1436,   694,   916,  1075,
     449,  -783,  2099,   626,   643,   197,  1031,  1922,   909,   640,
     693,   168,  1200,  1774,  1959,   948,   951,  1038,   609,   926,
     954,  2041,  1981,  2043,   197,  1197,   946,  1220,   198,  2069,
    1357,  1995,  1274,  1221,   783,   784,   785,   786,   921,  2102,
     924,   220,  1361,   694,  1157,  1795,   800,   198,   752,   753,
     754,   755,   756,   757,   758,   759,  1252,  1222,   760,  1253,
    1254,   402,   166,  1010,  1651,  1411,  1350,  1016,   292,  1652,
     182,   199,   384,  1975,  1736,  1038,   183,  1746,   835,  1775,
    1732,   186,   187,   188,   189,   190,   191,  1038,   748,  1764,
    1508,  1258,  1579,  1197,   167,   166,    49,    49,    49,    49,
      49, -1104,  1846,  2085,   473,  1375,  1715,   221,  1411,  1038,
     914,   151,   293,  1469,  1893,  1737,  1038,  1644,   778,  1026,
     474,  1672,  1668,   909,   643,  1884,  1885,  1915,  1645,  1847,
    1170,  1776,  1595,  -549,  1796,  1470,   554,  1937,   608,   299,
     192,   193,   194,   195,  1376,  1048, -1091,  1672,   752,   151,
     754,   755,   756,   757,   758,   759,  1596,  1882,   760,   151,
     151,   151,   151,  1891,  -549,   301,  1299,  1090,   166,    14,
    1289,   749,  1777, -1069,  1078,  1778,   151,  1923,  1110,  1110,
    1110,  1110,  1833,   151,  1960,  1779,  1834,  1653,  1044, -1069,
     302,   750,  1982,  1622,  1646,  1626,  1765,  -549,  -549,  -549,
      13,  1996,   219,  2056,  2057,  -549,  2074,  1938,  1581,  2103,
    1939,  1593,  1420,  1063,  1597,   558,  2026,  2067,  1560,  1424,
     905,  1425,   572,   658,   417,   561,  1074,   254,  1137,  1290,
     643,   643,   714,  1022,  1064,  2058,  1082,  1083,  1084,  1085,
    1023,  1024,  1466,  1467,  1468,  1346,  1582,   576,  1583,  1584,
    1165,  1134,   714,  1105,   196,   761,  1313,   898,   279,   899,
    1115,  -549,   151,  1153,  1154,  1155,   765,  1144,  1647,  1472,
    1175,   558,   558,    13,  1768,    14,   898,  1184,   899,  1338,
    1768,   561,   561,  -549,   435,  1473,  1789,  1790,   766,  -549,
    -549,   767,   768,  1016,   255,   256,   257,   258,  1474,  1310,
     434,  1372,  1373,   677,   678,   679,   680,   681,  -549,   443,
     421,  -232,  1207,   422,  1209,   175,   948,   294,  1999,   423,
    2001,  1243,  1243,  1243,   778,   197,  1223,   946,  1651,   294,
    -549,  -549,  -549,  1652,   436,   502,  1232,  1233,  1234,  1169,
    1235,  1236,  -522,  1237,   446,  1232,  1233,  1234,   198,  1235,
    1236,   631,  1237,   931,   752,   779,   754,   755,   756,   757,
     758,   759,   438,   439,   760,   452,   442,   726,   726,   928,
      15,   931,   295,   296,   297,  -549,  1695,  -232,  1816,  1747,
     433,   295,   296,   297,  1961,   608,  1962,  1963,  1964,   433,
     453,   199,    25,   295,   296,   297,   454,  1270,    26,    27,
     455,   608,   503,   504,   505,   506,   295,   296,   297,   558,
     456,   608,  1194,  1194,   913,  1100,  1101,    29,  1102,   561,
     457,  1281,  1617,  1282,  1283,  1286,  1287,   475,   476,  -232,
    1299,   658,   478,   479,  1291,  1292,  1284,  1238,  1293,  1479,
     726,   460,  1297,   151,   576,   175,  1238,  1232,  1233,  1234,
    1757,  1653,   519,   520,  1237,  1129,  1305,   558,  1131,  1132,
    1133,  1819,  1318,  1816,   295,   296,   297,   561,   218,  1090,
    -232,  1334,  1191,  -232,   698,   699,  1143,  1145,  1146,  1147,
     151,   647,  1110,  -232,   648,   649,   650,   651,   652,   653,
     654,   655,   842,  1692,   843,   656,   844,   845,   846,   847,
     295,   296,   297,   531,   532,   533,   672,   673,   674,   675,
     676,   677,   678,   679,   680,   681,   608,  1511,   534,   468,
    1298,   470,   535,   536,   537,   317,   318,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   186,   187,   188,   189,
     190,   191,   481,  1631,  1632,  1228,   492,  1597,   702,   703,
     547,   548,   549,   482,   531,   532,   533,  1341,   745,   746,
     483,   779,  1630,   969,   970,   971,  1757,   796,   797,   534,
     961,   962,   484,   535,   536,   537,   317,   318,   538,   539,
     540,   541,   542,   543,   544,   545,   546,  1067,  1060,   842,
     880,   843,   881,   844,   845,   846,   882,   493,  1243,  1243,
     948,   547,   548,   549,   628,   629,   494,   948,  1198,  1199,
     487,   946,  1271,  1272,   948,  1295,  1296,  1440,   946,  1798,
    1799,   303,  1830,  1442,   951,   946,   467,   586,   587,   588,
     589,   501,  1432,  1228,  1965,  1966,  2075,  2076,   513,   440,
     441,  1810,  1694,  1016,  1699,  1460,  1451,   842,  -636,   843,
     658,   844,   845,   846,  1362,   522,   558,   558,  1081,   558,
     515,   516,  1066,  1068,  2065,  2066,   561,   561,   526,   561,
     566,   567,   862,   863,  1465,  1471,   527,   528,   529,  1476,
    1477,  -188,  -187,   530,   562,   259,  1704,  1707,   568,  1707,
     570,   303,  -893,  -764,  -766,  -762,   581,  1482,   582,  1492,
    1488,  1489,   583,   175,   151,  1500,  1514,   584,   590,   592,
     593,  1510,  1501,   595,  1505,   292,   151,   596,   597,   598,
    1550,  1551,   669,   670,   671,   672,   673,   674,   675,   676,
     677,   678,   679,   680,   681,  1227,  1686,   599,   600,   601,
     602,  1749,   603,   604,   605,   260,   619,  1564,   620,   621,
     635,   636,   646,   683,   684,   685,  2018,   686,  -703,  1502,
     687,   230,   688,   700,   704,   705,   706,   708,   716,   718,
    1588,  1557,  1503,  1558,   658,  1559,   719,   720,   199,   742,
    1561,  1506,  1905,   740,   550,   551,   552,   553,   741,   769,
     773,   776,   777,  1515,   787,   261,   788,   802,   790,   231,
     803,   804,   232,   818,   805,  1504,   813,   230,   262,   838,
     831,   948,  1815,   948,   807,   726,   726,  1492,   832,  1825,
    1564,   836,   946,  1227,   946,  1650,   837,   839,  1564,  1228,
     624,   626,   853,   854,   855,   550,   551,   552,   553,   856,
     870,   867,   554,   860,   878,   231,   873,   233,   232,   234,
     673,   674,   675,   676,   677,   678,   679,   680,   681,   235,
     874,   263,   264,   265,   266,   267,   259,  1671,   879,   886,
    1661,   895,  1488,  1488,   902,   910,   894,   901,   912,  1500,
     922,   965,  1017,  1683,  1675,   966,  1501,  1001,  1002,   359,
     268,  1004,   292,   233,  1020,   234,  1021,  1028,   639,  1035,
     948,  1049,  1050,   269,  1047,   235,  1051,  1052,  1069,   270,
    1076,   172,  1060,  1079,   271,   647,  1917,  1086,   648,   649,
     650,   651,   652,   653,   654,   655,   260,  1091,  1447,   656,
    1088,   647,  1093,  1502,   648,   649,   650,   651,   652,   653,
     654,   655,  1087,  1104,  1448,   656,  1503,  1106,   643,  1099,
    1130,   272,  1148,  1152,   273,  1167,  1724,  1166,  1168,  1177,
    1182,  1170,  1186,   236,   237,   238,   239,   240,   241,   294,
    1205,  1142,  1206,  1208,  1748,   242,   261,  1690,   647,  1504,
     658,   648,   649,   650,   651,   652,   653,   654,   655,   262,
    1218,  1250,   656,  1951,  1231,  1259,  1243,   948,  1216,  1769,
    1770,  1264,  1266,  1492,   243,  1260,  1268,  -765,   946,   236,
     237,   238,   239,   240,   241,  -767,  -763,   244,  1273,  1227,
    1276,   242,   558,   245,  1278,  1280,   246,  1197,   247,  1285,
    1294,  1306,   561,  1311,  1312,  1308,  1095,  1322,  -225,  1327,
    1335,  1788,   263,   264,   265,   266,   267,  1323,  1793,  1337,
     243,  1782,  1997,  1339,  1340,  -225,  -797,  1791,  1792,  1345,
    -225,  -225,   402,  1812,  1344,  -172,  1347,  1348,   248,   245,
    1349,   268,   246,   384,   247,  1351,  1352,  1550,  1353,  1354,
    1355,  1358,  1550,  1359,  1365,  2037,  2048,  1366,  1367,  1368,
     270,  1564,  1836,  1369,  1377,   271,  1371,  1832,   531,   532,
     533,  1394,  -225,  1952,  -225,  1379,  1380,  2044,  1850,  1381,
    1399,  -172,  1401,   534,   248,  1406,  1405,   535,   536,   537,
     317,   318,   538,   539,   540,   541,   542,   543,   544,   545,
     546,  1412,   272,  1413,  1414,   273,  1419,  1422,  1201,  1872,
    1429,  1430,  1431,  1435,  1437,   547,   548,   549,  1438,  1441,
    1444,  1871,  1445,   558,   151,  1452,  -225,  -225,  -225,  1453,
    1454,   658,  1456,   561,   648,   649,   650,   651,   652,   653,
     654,   655,  1457,  1464,  2023,   656,  1480,  1461,  -225,  1516,
    -225,  1483,  1463,  2072,  1512,  1812,  -225,  -225,  1519,  1490,
    1517,  1491,  1552,  1553,  1565,  1554,  1566,  -225,  1576,  1550,
    -225,  1580,   576,  1590,  1591,  -225,  1592,   617,   618,  1605,
    -225,  1606,  1621,   622,  1604,  1627,  1634,  1639,   632,   659,
     660,   661,   662,   663,   664,   665,   666,   667,   668,  1640,
    1641,  1878,  1932,   669,   670,   671,   672,   673,   674,   675,
     676,   677,   678,   679,   680,   681,  1642,  1643,  1665,   151,
    1648,  1649,  1662,  1668,  1669,  1670,  1672,  1676,  1788,  1677,
    1678,  1680,  1958,  1684,  1687,  1685,  1708,  1120,  1953,   658,
     554,  2101,  -225,  1710,  1550,  1700,  1681,  1711,  1980,  1972,
    2104,  1702,  1703,  1550,  1712,  1713,  1973,  1717,  1550,  1716,
    1718,  1721,  1722,  1970,  1812,  1726,  1812,   712,  1971,  1727,
    2003,  1728,  1730,  1977,  1729,   712,  1731,  1739,  1832,  1613,
    1832,   656,  1766,  1735,  2010,  1978,  1762,  1715,  1763,  1771,
    1979,  1783,  1509,  1794,  1802,  1809,  1949,   659,   660,   661,
     662,   663,   664,   665,   666,   667,   668,  2033,  2034,  2035,
    2036,   669,   670,   671,   672,   673,   674,   675,   676,   677,
     678,   679,   680,   681,  1797,  1813,  1814,  1826,  1845,  1848,
    1550,  1849,  1852,  1853,  1854,  1875,  1866,  1873,  1867,  1876,
    1550,  1202,   576,  1874,  1883,  1879,  1880,  1869,  1886,   550,
     551,   552,   553,   531,   532,   533,  1868,  1877,  1889,  1896,
    1899,  1900,   640,  1897,  1902,  1908,  1914,  1918,   534,  1919,
    1920,  1921,   535,   536,   537,   317,   318,   538,   539,   540,
     541,   542,   543,   544,   545,   546,  1269,  1550,  1926,  1550,
    1927,  1929,  1930,  1924,   859,  1931,  1934,  1944,  1950,  1955,
     547,   548,   549,  1968,  1992,  1986,  1983,  2006,  1988,  1993,
    2009,  1938,  2021,  2022,  1550,  2024,  2027,  2087,  2029,  1972,
    2038,  2040,  2053,  2045,  2042,  2046,  1973,   887,   889,   889,
    2052,  1550,  2051,  1970,  2060,   887,  2064,   889,  1971,  2070,
    2071,  2077,  2079,  1977,  2081,  2075,  2094,  2076,  2095,  1614,
    2097,   918,   919,   920,  1326,  1978,  1673,  1462,   459,  1277,
    1979,   458,  2055,  1057,   733,   290,  1772,   934,   712,  1300,
    1674,  2093,  2080,   739,  2078,  2073,  2054,   -14,     1,  1910,
    2084,  1911,  1829,  1709,   968,   968,   968,   968,  1817,  2096,
     975,   976,   977,   978,   979,   980,   981,   982,   983,   984,
     985,   986,   987,   988,   989,   990,   991,   992,   993,   994,
     995,   996,   997,   998,  1555,  1895,   737,  1027,   159,  1008,
    1008,   419,  1894,  1667,  1954,  1957,  2031,  1019,     2,  1664,
    1663,    67,    68,    69,    70,    71,    72,  1608,  1607,  1160,
    1275,     3,     4,     5,     6,  1434,  1750,  1443,    73,    74,
     707,   953,    75,   872,     7,     8,     9,    10,  1158,  1753,
    1249,  1370,   974,    11,    76,  1190,  1029,    77,   964,  1210,
    1865,   973,   284,  1003,   826,   877,  1843,  2002,    78,   932,
    1720,  1842,  1586,  1851,  1574,   907,  1213,  1928,  1723,    79,
    1577,  1214,   166,   169,   939,   170,   171,  2008,  2015,     0,
       0,     0,     0,     0,     0,     0,    80,     0,     0,    81,
      12,     0,    82,     0,     0,     0,     0,     0,    83,     0,
       0,     0,     0,    84,    85,    86,     0,  1705,     0,     0,
       0,    87,     0,     0,   550,   551,   552,   553,     0,    88,
       0,     0,    89,     0,    90,    91,    92,     0,    13,     0,
      14,    93,    94,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    95,    96,
       0,     0,    97,     0,    98,    99,   100,   101,   102,   103,
     104,     0,   105,     0,   106,   107,   108,   109,     0,   110,
       0,   111,     0,     0,     0,     0,     0,    13,   112,  1224,
       0,   113,     0,     0,     0,     0,     0,    15,     0,     0,
       0,     0,     0,     0,     0,     0,    16,    17,     0,    18,
       0,    19,    20,    21,    22,    23,    24,     0,  1178,    25,
       0,     0,   887,     0,     0,    26,    27,     0,   889,     0,
       0,     0,   712,     0,     0,   114,   115,     0,     0,     0,
       0,    28,     0,   116,    29,     0,     0,   117,     0,     0,
    1212,     0,     0,  1215,   118,     0,     0,   119,   120,   121,
     122,   123,   124,   125,   126,   127,     0,   128,     0,     0,
       0,     0,     0,   129,     0,     0,   130,     0,     0,     0,
     131,     0,    30,   132,   133,     0,   134,   712,   712,   135,
       0,   136,     0,     0,     0,   137,   138,     0,     0,  1225,
       0,     0,   139,   140,   141,   142,     0,   143,     0,   144,
       0,     0,     0,     0,   145,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1008,     0,  1008,
       0,     0,     0,     0,     0,     0,     0,     0,   146,   147,
       0,     0,     0,     0,   148,   149,   531,   532,   533,     0,
       0,   658,     0,   712,     0,     0,     0,     0,     0,     0,
     712,   534,     0,   941,     0,   535,   536,   537,   317,   318,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   658,
       0,     0,     0,     0,     3,     4,     5,     6,     0,     0,
       0,     0,     0,   547,   548,   549,     0,     7,     8,     9,
      10,     0,     0,     0,     0,     0,    11,     0,     0,   659,
     660,   661,   662,   663,   664,   665,   666,   667,   668,     0,
       0,     0,     0,   669,   670,   671,   672,   673,   674,   675,
     676,   677,   678,   679,   680,   681,     0,   659,   660,   661,
     662,   663,   664,   665,   666,   667,   668,     0,     0,     0,
       0,   669,   670,   671,   672,   673,   674,   675,   676,   677,
     678,   679,   680,   681,     0,     0,     0,     0,     0,     0,
     859,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1374,    13,     0,    14,   889,     0,     0,     0,     0,  1385,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1415,  1416,  1417,  1418,     0,     0,     0,
       0,     0,     0,   712,     0,     0,     0,     0,     0,  1423,
     712,   658,   712,     0,     0,     0,     0,     0,     0,     0,
      15,     0,     0,     0,     0,     0,     0,     0,     0,    16,
      17,  1204,    18,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    25,     0,     0,     0,     0,     0,    26,    27,
     658,     0,     0,     0,     0,     0,     0,     0,     0,  1217,
    1008,     0,     0,     0,    28,     0,     0,    29,     0,   659,
     660,   661,   662,   663,   664,   665,   666,   667,   668,   658,
       0,     0,     0,   669,   670,   671,   672,   673,   674,   675,
     676,   677,   678,   679,   680,   681,     0,   550,   551,   552,
     553,     0,     0,     0,     0,    30,     0,     0,   659,   660,
     661,   662,   663,   664,   665,   666,   667,   668,     0,     0,
       0,     0,   669,   670,   671,   672,   673,   674,   675,   676,
     677,   678,   679,   680,   681,     0,     0,   659,   660,   661,
     662,   663,   664,   665,   666,   667,   668,     0,     0,     0,
       0,   669,   670,   671,   672,   673,   674,   675,   676,   677,
     678,   679,   680,   681,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1569,     0,     0,  1385,     0,     0,     0,
       0,     0,     0,     0,  1178,     0,     0,     0,     0,     0,
       0,   887,     0,     0,   887,     0,     0,     0,     0,     0,
       0,     0,     0,   712,   712,   712,   712,     0,     0,     0,
       0,     0,     0,   712,    67,    68,    69,    70,    71,    72,
    1421,  1616,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    73,    74,     0,     0,    75,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    76,     0,  1987,
      77,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    78,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,     0,     0,     0,   169,   939,   170,   171,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    80,
       0,     0,    81,     0,     0,    82,     0,     0,     0,     0,
       0,    83,     0,     0,     0,     0,    84,    85,    86,     0,
       0,     0,     0,     0,    87,     0,     0,     0,  1698,     0,
       0,     0,    88,     0,     0,    89,     0,    90,    91,    92,
       0,     0,     0,     0,    93,    94,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    95,    96,     0,     0,    97,     0,    98,    99,   100,
     101,   102,   103,   104,     0,   105,     0,   106,   107,   108,
     109,  1385,   110,     0,   111,     0,     0,     0,     0,     0,
       0,   112,   940,     0,   113,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1743,     0,     0,  1744,     0,  1745,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   859,     0,   114,   115,
     887,     0,     0,     0,     0,     0,   116,     0,     0,   887,
     117,     0,     0,     0,     0,   887,     0,   118,     0,     0,
     119,   120,   121,   122,   123,   124,   125,   126,   127,     0,
     128,     0,     0,     0,     0,     0,   129,     0,     0,   130,
       0,     0,     0,   131,     0,     0,   132,   133,     0,   134,
       0,     0,   135,     0,   136,     0,     0,     0,   137,   138,
       0,     0,     0,     0,     0,   139,   140,   141,   142,   658,
     143,     0,   144,     0,     0,     0,     0,   145,     0,  1837,
    1569,  1569,     0,  1569,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   887,     0,     0,
       0,   146,   147,     0,     0,     0,     0,   148,   149,     0,
       0,     0,     0,     0,     0,     0,   887,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   941,   659,   660,   661,
     662,   663,   664,   665,   666,   667,   668,     0,     0,     0,
       0,   669,   670,   671,   672,   673,   674,   675,   676,   677,
     678,   679,   680,   681,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1904,     0,     0,     0,     0,
     303,  1909,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,   315,   316,     0,     0,    73,
      74,     0,     0,    75,   317,   318,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    76,     0,     0,    77,     0,
       0,   319,   320,   321,   322,   323,   324,   325,     0,    78,
       0,     0,   275,   276,   277,     0,     0,     0,   928,   326,
      79,     0,     0,   166,   169,     0,   170,   171,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    80,     0,     0,
      81,     0,     0,    82,     0,     0,     0,     0,     0,    83,
       0,     0,     0,     0,    84,    85,    86,     0,     0,     0,
       0,     0,    87,   327,     0,  1837,     0,   328,  1569,     0,
      88,   329,     0,    89,     0,    90,    91,    92,     0,     0,
       0,   330,    93,    94,     0,     0,   887,     0,     0,     0,
       0,   331,   332,   333,   334,   335,     0,   336,   337,    95,
      96,   338,   339,    97,   340,    98,    99,   100,   101,   102,
     103,   104,     0,   105,   341,   106,   107,   108,   109,     0,
     110,   342,   111,     0,  2039,     0,     0,     0,    13,   112,
     606,     0,   113,   344,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   345,
     346,     0,     0,     0,     0,     0,     0,     0,     0,   347,
     348,   349,     0,     0,     0,     0,   351,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   114,   115,     0,     0,
       0,     0,     0,     0,   116,     0,     0,     0,   117,     0,
       0,     0,     0,     0,     0,   118,     0,     0,   119,   120,
     121,   122,   123,   124,   125,   126,   127,     0,   128,     0,
       0,     0,     0,     0,   129,     0,     0,   130,     0,     0,
       0,   131,     0,     0,   132,   133,     0,   134,     0,     0,
     135,     0,   136,     0,     0,     0,   137,   138,     0,     0,
     607,     0,     0,   352,   353,   354,   355,     0,   143,     0,
     144,     0,     0,     0,     0,   145,     0,     0,     0,   356,
       0,     0,     0,   357,   358,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   146,
     147,     0,     0,     0,     0,   148,   149,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   359,   303,   360,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
     315,   316,     0,     0,    73,    74,     0,     0,    75,   317,
     318,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      76,     0,     0,    77,     0,     0,   319,   320,   321,   322,
     323,   324,   325,     0,    78,     0,     0,   275,   276,   277,
       0,     0,     0,     0,   326,    79,     0,     0,     0,   169,
       0,   170,   171,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    80,     0,     0,    81,     0,     0,    82,     0,
       0,     0,     0,     0,    83,     0,     0,     0,     0,    84,
      85,    86,     0,     0,     0,     0,     0,    87,   327,     0,
       0,     0,   328,     0,     0,    88,   329,     0,    89,     0,
      90,    91,    92,     0,     0,     0,   330,    93,    94,     0,
       0,     0,     0,     0,     0,     0,   331,   332,   333,   334,
     335,     0,   336,   337,    95,    96,   338,   339,    97,   340,
      98,    99,   100,   101,   102,   103,   104,     0,   105,   341,
     106,   107,   108,   109,     0,   110,   342,   111,     0,     0,
       0,     0,     0,     0,   112,   343,     0,   113,   344,     0,
     956,   957,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   958,     0,     0,   345,   346,     0,     0,     0,     0,
       0,     0,     0,     0,   347,   348,   349,     0,     0,     0,
       0,   351,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   114,   115,     0,     0,     0,     0,     0,     0,   116,
       0,     0,     0,   117,     0,     0,     0,     0,     0,     0,
     118,     0,     0,   119,   120,   121,   122,   123,   124,   125,
     126,   127,     0,   128,     0,     0,     0,     0,     0,   129,
       0,     0,   130,     0,     0,     0,   131,     0,     0,   132,
     133,     0,   134,     0,     0,   135,     0,   136,     0,     0,
       0,   137,   138,     0,     0,     0,     0,     0,   352,   353,
     354,   355,     0,   143,     0,   144,     0,     0,     0,     0,
     145,     0,     0,     0,   356,     0,     0,     0,   357,   358,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   146,   147,     0,     0,     0,     0,
     148,   149,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   359,
     303,   360,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,   315,   316,     0,     0,    73,
      74,     0,     0,    75,   317,   318,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    76,     0,     0,    77,     0,
       0,   319,   320,   321,   322,   323,   324,   325,     0,    78,
       0,     0,   275,   276,   277,     0,     0,     0,     0,   326,
      79,     0,     0,   166,   169,     0,   170,   171,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    80,     0,     0,
      81,     0,     0,    82,     0,     0,     0,     0,     0,    83,
       0,     0,     0,     0,    84,    85,    86,     0,     0,     0,
       0,     0,    87,   327,     0,     0,     0,   328,     0,     0,
      88,   329,     0,    89,     0,    90,    91,    92,     0,     0,
       0,   330,    93,    94,     0,     0,     0,     0,     0,     0,
       0,   331,   332,   333,   334,   335,     0,   336,   337,    95,
      96,   338,   339,    97,   340,    98,    99,   100,   101,   102,
     103,   104,     0,   105,   341,   106,   107,   108,   109,     0,
     110,   342,   111,     0,     0,     0,     0,     0,    13,   112,
     606,     0,   113,   344,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   345,
     346,     0,     0,     0,     0,     0,     0,     0,     0,   347,
     348,   349,     0,     0,     0,     0,   351,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   114,   115,     0,     0,
       0,     0,     0,     0,   116,     0,     0,     0,   117,     0,
       0,     0,     0,     0,     0,   118,     0,     0,   119,   120,
     121,   122,   123,   124,   125,   126,   127,     0,   128,     0,
       0,     0,     0,     0,   129,     0,     0,   130,     0,     0,
       0,   131,     0,     0,   132,   133,     0,   134,     0,     0,
     135,     0,   136,     0,     0,     0,  1691,   138,     0,     0,
       0,     0,     0,   352,   353,   354,   355,     0,   143,     0,
     144,     0,     0,     0,     0,   145,     0,     0,     0,   356,
       0,     0,     0,   357,   358,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   146,
     147,     0,     0,     0,     0,   148,   149,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   359,   303,   360,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
     315,   316,     0,     0,    73,    74,     0,     0,    75,   317,
     318,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      76,     0,     0,    77,     0,     0,   319,   320,   321,   322,
     323,   324,   325,     0,    78,     0,     0,   275,   276,   277,
       0,     0,     0,     0,   326,    79,     0,     0,     0,   169,
       0,   170,   171,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    80,     0,     0,    81,     0,     0,    82,     0,
       0,     0,     0,     0,    83,     0,     0,     0,     0,    84,
      85,    86,     0,     0,     0,     0,     0,    87,   327,     0,
       0,     0,   328,     0,     0,    88,   329,     0,    89,     0,
      90,    91,    92,     0,     0,     0,   330,    93,    94,     0,
       0,     0,     0,     0,     0,     0,   331,   332,   333,   334,
     335,     0,   336,   337,    95,    96,   338,   339,    97,   340,
      98,    99,   100,   101,   102,   103,   104,     0,   105,   341,
     106,   107,   108,   109,     0,   110,   342,   111,     0,     0,
       0,     0,     0,     0,   112,   343,     0,   113,   344,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   345,   346,     0,     0,     0,     0,
       0,     0,     0,     0,   347,   348,   349,     0,   350,     0,
       0,   351,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   114,   115,     0,     0,     0,     0,     0,     0,   116,
       0,     0,     0,   117,     0,     0,     0,     0,     0,     0,
     118,     0,     0,   119,   120,   121,   122,   123,   124,   125,
     126,   127,     0,   128,     0,     0,     0,     0,     0,   129,
       0,     0,   130,     0,     0,     0,   131,     0,     0,   132,
     133,     0,   134,     0,     0,   135,     0,   136,     0,     0,
       0,   137,   138,     0,     0,     0,     0,     0,   352,   353,
     354,   355,     0,   143,     0,   144,     0,     0,     0,     0,
     145,     0,     0,     0,   356,     0,     0,     0,   357,   358,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   146,   147,     0,     0,     0,     0,
     148,   149,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   359,
     303,   360,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,   315,   316,     0,     0,    73,
      74,     0,     0,    75,   317,   318,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    76,     0,     0,    77,     0,
       0,   319,   320,   321,   322,   323,   324,   325,     0,    78,
       0,     0,   275,   276,   277,     0,     0,     0,     0,   326,
      79,     0,     0,     0,   169,     0,   170,   171,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    80,     0,     0,
      81,     0,     0,    82,     0,     0,     0,     0,     0,    83,
       0,     0,     0,     0,    84,    85,    86,     0,     0,     0,
       0,     0,    87,   327,     0,     0,     0,   328,     0,     0,
      88,   329,     0,    89,     0,    90,    91,    92,     0,     0,
       0,   330,    93,    94,     0,     0,     0,     0,     0,     0,
       0,   331,   332,   333,   334,   335,     0,   336,   337,    95,
      96,   338,   339,    97,   340,    98,    99,   100,   101,   102,
     103,   104,     0,   105,   341,   106,   107,   108,   109,     0,
     110,   342,   111,     0,     0,     0,     0,     0,     0,   112,
     343,     0,   113,   344,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   345,
     346,     0,     0,     0,     0,     0,     0,     0,     0,   347,
     348,   349,     0,     0,     0,     0,   351,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   114,   115,     0,     0,
       0,     0,     0,     0,   116,     0,     0,     0,   117,     0,
       0,     0,     0,     0,     0,   118,     0,     0,   119,   120,
     121,   122,   123,   124,   125,   126,   127,  1162,   128,     0,
       0,     0,     0,     0,   129,     0,     0,   130,     0,     0,
       0,   131,     0,     0,   132,   133,     0,   134,     0,     0,
     135,     0,   136,     0,     0,     0,   137,   138,     0,     0,
       0,     0,     0,   352,   353,   354,   355,     0,   143,     0,
     144,     0,     0,     0,     0,   145,     0,     0,     0,   356,
       0,     0,     0,   357,   358,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   146,
     147,     0,     0,     0,     0,   148,   149,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   359,   303,   360,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
     315,   316,     0,     0,    73,    74,     0,     0,    75,   317,
     318,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      76,     0,     0,    77,     0,     0,   319,   320,   321,   322,
     323,   324,   325,     0,    78,     0,     0,   275,   276,   277,
       0,     0,     0,     0,   326,    79,     0,     0,     0,   169,
       0,   170,   171,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    80,     0,     0,    81,     0,     0,    82,     0,
       0,     0,     0,     0,    83,     0,     0,     0,     0,    84,
      85,    86,     0,     0,     0,     0,     0,    87,   327,     0,
       0,     0,   328,     0,     0,    88,   329,     0,    89,     0,
      90,    91,    92,     0,     0,     0,   330,    93,    94,     0,
       0,     0,     0,     0,     0,     0,   331,   332,   333,   334,
     335,     0,   336,   337,    95,    96,   338,   339,    97,   340,
      98,    99,   100,   101,   102,   103,   104,     0,   105,   341,
     106,   107,   108,   109,     0,   110,   342,   111,     0,     0,
       0,     0,     0,     0,   112,   343,     0,   113,   344,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   345,   346,     0,     0,     0,     0,
       0,     0,     0,     0,   347,   348,   349,     0,     0,     0,
       0,   351,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   114,   115,     0,     0,     0,     0,     0,     0,   116,
       0,     0,     0,   117,     0,     0,     0,     0,     0,     0,
     118,     0,     0,   119,   120,   121,   122,   123,   124,   125,
     126,   127,     0,   128,     0,     0,     0,     0,     0,   129,
       0,     0,   130,     0,     0,     0,   131,     0,     0,   132,
     133,     0,   134,     0,     0,   135,     0,   136,     0,     0,
       0,   137,   138,     0,     0,     0,     0,     0,   352,   353,
     354,   355,     0,   143,     0,   144,     0,     0,     0,     0,
     145,     0,     0,     0,   356,     0,     0,     0,   357,   358,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   146,   147,     0,     0,     0,     0,
     148,   149,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   359,
     303,   360,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,   315,   316,     0,     0,    73,
      74,     0,     0,    75,   317,   318,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    76,     0,     0,    77,     0,
       0,   319,   320,   321,   322,   323,   324,   325,     0,    78,
       0,     0,   275,   276,   277,     0,     0,     0,     0,   326,
      79,     0,     0,     0,   169,     0,   170,   171,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    80,     0,     0,
      81,     0,     0,    82,     0,     0,     0,     0,     0,    83,
       0,     0,     0,     0,    84,    85,    86,     0,     0,     0,
       0,     0,    87,     0,     0,     0,     0,   328,     0,     0,
      88,   329,     0,    89,     0,    90,    91,    92,     0,     0,
       0,   330,    93,    94,     0,     0,     0,     0,     0,     0,
       0,   331,   332,   333,   334,   335,     0,   336,   337,    95,
      96,   338,   339,    97,   340,    98,    99,   100,   101,   102,
     103,   104,     0,   105,   341,   106,   107,   108,   109,     0,
     110,   342,   111,     0,     0,     0,     0,     0,     0,   112,
     616,     0,   113,     0,     0,     0,     0,     0,  1754,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   345,
     346,     0,     0,     0,     0,     0,     0,     0,     0,   347,
     348,   349,     0,     0,     0,     0,   351,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   114,   115,     0,     0,
       0,     0,     0,     0,   116,     0,     0,     0,   117,     0,
       0,     0,     0,     0,     0,   118,     0,     0,   119,   120,
     121,   122,   123,   124,   125,   126,   127,     0,   128,     0,
       0,     0,     0,     0,   129,     0,     0,   130,     0,     0,
       0,   131,     0,     0,   132,   133,     0,   134,     0,     0,
     135,     0,   136,     0,     0,     0,   137,   138,     0,     0,
       0,     0,     0,   352,   353,   354,   355,     0,   143,     0,
     144,     0,     0,     0,     0,   145,     0,     0,     0,   356,
       0,     0,     0,   357,   358,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   146,
     147,     0,     0,     0,     0,   148,   149,     0,     0,     0,
       0,     0,     0,  1755,     0,     0,     0,     0,     0,     0,
    1756,     0,     0,     0,     0,   303,   360,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
     315,   316,     0,     0,    73,    74,     0,     0,    75,   317,
     318,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      76,     0,     0,    77,     0,     0,   319,   320,   321,   322,
     323,   324,   325,     0,    78,     0,     0,   275,   276,   277,
       0,     0,     0,     0,   326,    79,     0,     0,   166,   169,
       0,   170,   171,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    80,     0,     0,    81,     0,     0,    82,     0,
       0,     0,     0,     0,    83,     0,     0,     0,     0,    84,
      85,    86,     0,     0,     0,     0,     0,    87,     0,     0,
       0,     0,   328,     0,     0,    88,   329,     0,    89,     0,
      90,    91,    92,     0,     0,     0,   330,    93,    94,     0,
       0,     0,     0,     0,     0,     0,   331,   332,   333,   334,
     335,     0,   336,   337,    95,    96,   338,   339,    97,   340,
      98,    99,   100,   101,   102,   103,   104,     0,   105,   341,
     106,   107,   108,   109,     0,   110,   342,   111,     0,     0,
       0,     0,     0,     0,   112,   721,   722,   113,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   345,   346,     0,     0,     0,     0,
       0,     0,     0,     0,   347,   348,   349,     0,     0,     0,
       0,   351,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   114,   115,     0,     0,     0,     0,     0,     0,   116,
       0,     0,     0,   117,     0,     0,     0,     0,     0,     0,
     118,     0,     0,   119,   120,   121,   122,   123,   124,   125,
     126,   127,     0,   128,     0,     0,     0,     0,     0,   129,
       0,     0,   130,     0,     0,     0,   131,     0,     0,   132,
     133,     0,   134,     0,     0,   135,     0,   136,     0,     0,
       0,   137,   138,     0,     0,     0,     0,     0,   352,   353,
     354,   355,     0,   143,     0,   144,     0,     0,     0,     0,
     145,     0,     0,     0,   356,     0,     0,     0,   357,   358,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   146,   147,     0,     0,     0,     0,
     148,   149,     0,   303,     0,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,   315,   316,
       0,   360,    73,    74,     0,     0,    75,   317,   318,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    76,     0,
       0,    77,     0,     0,   319,   320,   321,   322,   323,   324,
     325,     0,    78,     0,     0,   275,   276,   277,     0,     0,
       0,     0,   326,    79,     0,     0,     0,   169,     0,   170,
     171,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      80,     0,     0,    81,     0,     0,    82,     0,     0,     0,
       0,     0,    83,     0,     0,     0,     0,    84,    85,    86,
       0,     0,     0,     0,     0,    87,     0,     0,     0,     0,
     328,     0,     0,    88,   329,     0,    89,     0,    90,    91,
      92,     0,     0,     0,   330,    93,    94,     0,     0,     0,
       0,     0,     0,     0,   331,   332,   333,   334,   335,     0,
     336,   337,    95,    96,   338,   339,    97,   340,    98,    99,
     100,   101,   102,   103,   104,     0,   105,   341,   106,   107,
     108,   109,     0,   110,   342,   111,     0,     0,     0,     0,
       0,     0,   112,   616,     0,   113,     0,     0,  1005,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   345,   346,     0,     0,     0,     0,     0,     0,
       0,     0,   347,   348,   349,     0,  1006,     0,     0,   351,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   114,
     115,     0,     0,     0,     0,     0,     0,   116,     0,     0,
       0,   117,     0,     0,     0,     0,     0,     0,   118,     0,
       0,   119,   120,   121,   122,   123,   124,   125,   126,   127,
       0,  1007,     0,     0,     0,     0,     0,   129,     0,     0,
     130,     0,     0,     0,   131,     0,     0,   132,   133,     0,
     134,     0,     0,   135,     0,   136,     0,     0,     0,   137,
     138,     0,     0,     0,     0,     0,   352,   353,   354,   355,
       0,   143,     0,   144,     0,     0,     0,     0,   145,     0,
       0,     0,   356,     0,     0,     0,   357,   358,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   146,   147,     0,     0,     0,     0,   148,   149,
       0,   303,     0,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,   315,   316,     0,   360,
      73,    74,     0,     0,    75,   317,   318,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    76,     0,     0,    77,
       0,     0,   319,   320,   321,   322,   323,   324,   325,     0,
      78,     0,     0,   275,   276,   277,     0,     0,     0,     0,
     326,    79,     0,     0,     0,   169,     0,   170,   171,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    80,     0,
       0,    81,     0,     0,    82,     0,     0,     0,     0,     0,
      83,     0,     0,     0,     0,    84,    85,    86,     0,     0,
       0,     0,     0,    87,     0,     0,     0,     0,   328,     0,
       0,    88,   329,     0,    89,     0,    90,    91,    92,     0,
       0,     0,   330,    93,    94,     0,     0,     0,     0,     0,
       0,     0,   331,   332,   333,   334,   335,  1568,   336,   337,
      95,    96,   338,   339,    97,   340,    98,    99,   100,   101,
     102,   103,   104,   895,   105,   341,   106,   107,   108,   109,
       0,   110,   342,   111,     0,     0,     0,     0,     0,     0,
     112,   616,     0,   113,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     345,   346,     0,     0,     0,     0,     0,     0,     0,     0,
     347,   348,   349,     0,     0,     0,     0,   351,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   114,   115,     0,
       0,     0,     0,     0,     0,   116,     0,     0,     0,   117,
       0,     0,     0,     0,     0,     0,   118,     0,     0,   119,
     120,   121,   122,   123,   124,   125,   126,   127,     0,   128,
       0,     0,     0,     0,     0,   129,     0,     0,   130,     0,
       0,     0,   131,     0,     0,   132,   133,     0,   134,     0,
       0,   135,     0,   136,     0,     0,     0,   137,   138,     0,
       0,     0,     0,     0,   352,   353,   354,   355,     0,   143,
       0,   144,     0,     0,     0,     0,   145,     0,     0,     0,
     356,     0,     0,     0,   357,   358,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     146,   147,     0,     0,     0,     0,   148,   149,     0,   303,
       0,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,   315,   316,     0,   360,    73,    74,
       0,     0,    75,   317,   318,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    76,     0,     0,    77,     0,     0,
     319,   320,   321,   322,   323,   324,   325,     0,    78,     0,
       0,   275,   276,   277,     0,     0,     0,     0,   326,    79,
       0,     0,     0,   169,     0,   170,   171,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,     0,     0,    81,
       0,     0,    82,     0,     0,     0,     0,     0,    83,     0,
       0,     0,     0,    84,    85,    86,     0,     0,     0,     0,
       0,    87,     0,     0,     0,     0,   328,     0,     0,    88,
     329,     0,    89,     0,    90,    91,    92,     0,     0,     0,
     330,    93,    94,     0,     0,     0,     0,     0,     0,     0,
     331,   332,   333,   334,   335,     0,   336,   337,    95,    96,
     338,   339,    97,   340,    98,    99,   100,   101,   102,   103,
     104,     0,   105,   341,   106,   107,   108,   109,     0,   110,
     342,   111,     0,     0,     0,     0,     0,     0,   112,   616,
       0,   113,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   345,   346,
       0,     0,     0,     0,     0,     0,     0,     0,   347,   348,
     349,     0,     0,     0,     0,   351,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   114,   115,     0,     0,     0,
       0,     0,     0,   116,     0,     0,     0,   117,     0,     0,
       0,     0,     0,     0,   118,     0,     0,   119,   120,   121,
     122,   123,   124,   125,   126,   127,     0,   128,     0,     0,
       0,     0,     0,   129,     0,     0,   130,     0,     0,     0,
     131,     0,     0,   132,   133,     0,   134,     0,     0,   135,
       0,   136,     0,     0,     0,   137,   138,     0,     0,     0,
       0,     0,   352,   353,   354,   355,     0,   143,     0,   144,
       0,     0,     0,     0,   145,     0,     0,     0,   356,     0,
       0,     0,   357,   358,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   146,   147,
       0,     0,     0,     0,   148,   149,     0,     0,     0,     0,
       0,     0,  1755,     0,     0,     0,     0,     0,     0,  1756,
       0,     0,     0,     0,   303,   360,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,   315,
     316,     0,     0,    73,    74,     0,     0,    75,   317,   318,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    76,
       0,     0,    77,     0,     0,   319,   320,   321,   322,   323,
     324,   325,     0,    78,     0,     0,   275,   276,   277,     0,
       0,     0,     0,   326,    79,     0,     0,     0,   169,     0,
     170,   171,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,     0,     0,    81,     0,     0,    82,     0,     0,
       0,     0,     0,    83,     0,     0,     0,     0,    84,    85,
      86,     0,     0,     0,     0,     0,    87,     0,     0,     0,
       0,   328,     0,     0,    88,   329,     0,    89,     0,    90,
      91,    92,     0,     0,     0,   330,    93,    94,     0,     0,
       0,     0,     0,     0,     0,   331,   332,   333,   334,   335,
       0,   336,   337,    95,    96,   338,   339,    97,   340,    98,
      99,   100,   101,   102,   103,   104,     0,   105,   341,   106,
     107,   108,   109,     0,   110,   342,   111,     0,     0,     0,
       0,     0,     0,   112,   616,     0,   113,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   345,   346,     0,     0,     0,     0,     0,
       0,     0,     0,   347,   348,   349,     0,     0,     0,     0,
     351,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     114,   115,     0,     0,     0,     0,     0,     0,   116,     0,
       0,     0,   117,     0,     0,     0,     0,     0,     0,   118,
       0,     0,   119,   120,   121,   122,   123,   124,   125,   126,
     127,     0,   128,     0,     0,     0,     0,     0,   129,     0,
       0,   130,     0,     0,     0,   131,     0,     0,   132,   133,
       0,   134,     0,     0,   135,     0,   136,     0,     0,     0,
     137,   138,     0,     0,     0,     0,     0,   352,   353,   354,
     355,     0,   143,     0,   144,     0,     0,     0,     0,   145,
       0,     0,     0,   356,     0,     0,     0,   357,   358,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   146,   147,     0,     0,     0,     0,   148,
     149,     0,     0,     0,     0,     0,     0,  2016,     0,     0,
       0,     0,     0,     0,  2017,     0,     0,     0,     0,   303,
     360,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,   315,   316,     0,     0,    73,    74,
       0,     0,    75,   317,   318,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    76,     0,     0,    77,     0,     0,
     319,   320,   321,   322,   323,   324,   325,     0,    78,     0,
       0,   275,   276,   277,     0,     0,     0,     0,   326,    79,
       0,     0,     0,   169,     0,   170,   171,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,     0,     0,    81,
       0,     0,    82,     0,     0,     0,     0,     0,    83,     0,
       0,     0,     0,    84,    85,    86,     0,     0,     0,     0,
       0,    87,     0,     0,     0,     0,   328,     0,     0,    88,
     329,     0,    89,     0,    90,    91,    92,     0,     0,     0,
     330,    93,    94,     0,     0,     0,     0,     0,     0,     0,
     331,   332,   333,   334,   335,     0,   336,   337,    95,    96,
     338,   339,    97,   340,    98,    99,   100,   101,   102,   103,
     104,     0,   105,   341,   106,   107,   108,   109,     0,   110,
     342,   111,     0,     0,     0,     0,     0,     0,   112,   616,
       0,   113,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   345,   346,
       0,     0,     0,     0,     0,     0,     0,     0,   347,   348,
     349,     0,     0,     0,     0,   351,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   114,   115,     0,     0,     0,
       0,     0,     0,   116,     0,     0,     0,   117,     0,     0,
       0,     0,     0,     0,   118,     0,     0,   119,   120,   121,
     122,   123,   124,   125,   126,   127,     0,   128,     0,     0,
       0,     0,     0,   129,     0,     0,   130,     0,     0,     0,
     131,     0,     0,   132,   133,     0,   134,     0,     0,   135,
       0,   136,     0,     0,     0,   137,   138,     0,     0,     0,
       0,     0,   352,   353,   354,   355,     0,   143,     0,   144,
       0,     0,     0,     0,   145,     0,     0,     0,   356,   631,
       0,     0,   357,   358,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   146,   147,
       0,     0,     0,     0,   148,   149,     0,   303,     0,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,   315,   316,     0,   360,    73,    74,     0,     0,
      75,   317,   318,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    76,     0,     0,    77,     0,     0,   319,   320,
     321,   322,   323,   324,   325,     0,    78,     0,     0,   275,
     276,   277,     0,     0,     0,     0,   326,    79,     0,     0,
       0,   169,     0,   170,   171,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    80,     0,     0,    81,     0,     0,
      82,     0,     0,     0,     0,     0,    83,     0,     0,     0,
       0,    84,    85,    86,     0,     0,     0,     0,     0,    87,
       0,     0,     0,     0,   328,     0,     0,    88,   329,     0,
      89,     0,    90,    91,    92,     0,     0,     0,   330,    93,
      94,     0,     0,     0,     0,     0,     0,     0,   331,   332,
     333,   334,   335,     0,   336,   337,    95,    96,   338,   339,
      97,   340,    98,    99,   100,   101,   102,   103,   104,     0,
     105,   341,   106,   107,   108,   109,     0,   110,   342,   111,
       0,     0,     0,     0,     0,     0,   112,   616,   710,   113,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   345,   346,     0,     0,
       0,     0,     0,     0,     0,     0,   347,   348,   349,     0,
       0,     0,     0,   351,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   114,   115,     0,     0,     0,     0,     0,
       0,   116,     0,     0,     0,   117,     0,     0,     0,     0,
       0,     0,   118,     0,     0,   119,   120,   121,   122,   123,
     124,   125,   126,   127,     0,   128,     0,     0,     0,     0,
       0,   129,     0,     0,   130,     0,     0,     0,   131,     0,
       0,   132,   133,     0,   134,     0,     0,   135,     0,   136,
       0,     0,     0,   137,   138,     0,     0,     0,     0,     0,
     352,   353,   354,   355,     0,   143,     0,   144,     0,     0,
       0,     0,   145,     0,     0,     0,   356,     0,     0,     0,
     357,   358,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   146,   147,     0,     0,
       0,     0,   148,   149,     0,   303,     0,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
     315,   316,     0,   360,    73,    74,     0,     0,    75,   317,
     318,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      76,     0,     0,    77,     0,     0,   319,   320,   321,   322,
     323,   324,   325,     0,    78,     0,     0,   275,   276,   277,
       0,     0,     0,     0,   326,    79,     0,     0,     0,   169,
       0,   170,   171,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    80,     0,     0,    81,     0,     0,    82,     0,
       0,     0,     0,     0,    83,     0,     0,     0,     0,    84,
      85,    86,     0,     0,     0,     0,     0,    87,     0,     0,
       0,     0,   328,     0,     0,    88,   329,     0,    89,     0,
      90,    91,    92,     0,     0,     0,   330,    93,    94,     0,
       0,     0,     0,     0,     0,     0,   331,   332,   333,   334,
     335,     0,   336,   337,    95,    96,   338,   339,    97,   340,
      98,    99,   100,   101,   102,   103,   104,     0,   105,   341,
     106,   107,   108,   109,     0,   110,   342,   111,     0,     0,
       0,     0,     0,     0,   112,   616,     0,   113,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   345,   346,     0,     0,     0,     0,
       0,     0,     0,     0,   347,   348,   349,     0,     0,     0,
       0,   351,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   114,   115,     0,     0,     0,     0,     0,     0,   116,
       0,     0,     0,   117,     0,     0,     0,     0,     0,     0,
     118,     0,     0,   119,   120,   121,   122,   123,   124,   125,
     126,   127,  1192,   128,     0,     0,     0,     0,     0,   129,
       0,     0,   130,     0,     0,     0,   131,     0,     0,   132,
     133,     0,   134,     0,     0,   135,     0,   136,     0,     0,
       0,   137,   138,     0,     0,     0,     0,     0,   352,   353,
     354,   355,     0,   143,     0,   144,     0,     0,     0,     0,
     145,     0,     0,     0,   356,     0,     0,     0,   357,   358,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   146,   147,     0,     0,     0,     0,
     148,   149,     0,   303,     0,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,   315,   316,
       0,   360,    73,    74,     0,     0,    75,   317,   318,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    76,     0,
       0,    77,     0,     0,   319,   320,   321,   322,   323,   324,
     325,     0,    78,     0,     0,   275,   276,   277,     0,     0,
       0,     0,   326,    79,     0,     0,   166,   169,     0,   170,
     171,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      80,     0,     0,    81,     0,     0,    82,     0,     0,     0,
       0,     0,    83,     0,     0,     0,     0,    84,    85,    86,
       0,     0,     0,     0,     0,    87,     0,     0,     0,     0,
     328,     0,     0,    88,   329,     0,    89,     0,    90,    91,
      92,     0,     0,     0,   330,    93,    94,     0,     0,     0,
       0,     0,     0,     0,   331,   332,   333,   334,   335,     0,
     336,   337,    95,    96,   338,   339,    97,   340,    98,    99,
     100,   101,   102,   103,   104,     0,   105,   341,   106,   107,
     108,   109,     0,   110,   342,   111,     0,     0,     0,     0,
       0,     0,   112,   721,     0,   113,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   345,   346,     0,     0,     0,     0,     0,     0,
       0,     0,   347,   348,   349,     0,     0,     0,     0,   351,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   114,
     115,     0,     0,     0,     0,     0,     0,   116,     0,     0,
       0,   117,     0,     0,     0,     0,     0,     0,   118,     0,
       0,   119,   120,   121,   122,   123,   124,   125,   126,   127,
       0,   128,     0,     0,     0,     0,     0,   129,     0,     0,
     130,     0,     0,     0,   131,     0,     0,   132,   133,     0,
     134,     0,     0,   135,     0,   136,     0,     0,     0,   137,
     138,     0,     0,     0,     0,     0,   352,   353,   354,   355,
       0,   143,     0,   144,     0,     0,     0,     0,   145,     0,
       0,     0,   356,     0,     0,     0,   357,   358,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   146,   147,     0,     0,     0,     0,   148,   149,
       0,   303,     0,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,   315,   316,     0,   360,
      73,    74,     0,     0,    75,   317,   318,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    76,     0,     0,    77,
       0,     0,   319,   320,   321,   322,   323,   324,   325,     0,
      78,     0,     0,   275,   276,   277,     0,     0,     0,     0,
     326,    79,     0,     0,     0,   169,     0,   170,   171,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    80,     0,
       0,  1383,     0,     0,    82,     0,     0,     0,     0,     0,
      83,     0,     0,     0,     0,    84,    85,    86,     0,     0,
       0,     0,     0,    87,     0,     0,     0,     0,   328,     0,
       0,    88,   329,     0,    89,     0,    90,    91,    92,     0,
       0,     0,   330,    93,    94,     0,     0,     0,     0,     0,
       0,     0,   331,   332,   333,   334,   335,     0,   336,   337,
      95,    96,   338,   339,    97,   340,    98,    99,   100,   101,
     102,   103,   104,     0,   105,   341,   106,   107,   108,   109,
       0,   110,   342,   111,     0,     0,     0,     0,     0,     0,
     112,   616,     0,   113,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     345,   346,     0,     0,     0,     0,     0,     0,     0,     0,
     347,   348,   349,     0,     0,     0,     0,   351,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   114,   115,     0,
       0,     0,     0,     0,     0,   116,     0,     0,     0,   117,
       0,     0,     0,     0,     0,     0,   118,     0,     0,   119,
     120,   121,   122,   123,   124,   125,   126,   127,  1384,   128,
       0,     0,     0,     0,     0,   129,     0,     0,   130,     0,
       0,     0,   131,     0,     0,   132,   133,     0,   134,     0,
       0,   135,     0,   136,     0,     0,     0,   137,   138,     0,
       0,     0,     0,     0,   352,   353,   354,   355,     0,   143,
       0,   144,     0,     0,     0,     0,   145,     0,     0,     0,
     356,     0,     0,     0,   357,   358,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     146,   147,     0,     0,     0,     0,   148,   149,     0,   303,
       0,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,   315,   316,     0,   360,    73,    74,
       0,     0,    75,   317,   318,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    76,     0,     0,    77,     0,     0,
     319,   320,   321,   322,   323,   324,   325,     0,    78,     0,
       0,   275,   276,   277,     0,     0,     0,     0,   326,    79,
       0,     0,     0,   169,     0,   170,   171,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,     0,     0,    81,
       0,     0,    82,     0,     0,     0,     0,     0,    83,     0,
       0,     0,     0,    84,    85,    86,     0,     0,     0,     0,
       0,    87,     0,     0,     0,     0,   328,     0,     0,    88,
     329,     0,    89,     0,    90,    91,    92,     0,     0,     0,
     330,    93,    94,     0,     0,     0,     0,     0,     0,     0,
     331,   332,   333,   334,   335,     0,   336,   337,    95,    96,
     338,   339,    97,   340,    98,    99,   100,   101,   102,   103,
     104,     0,   105,   341,   106,   107,   108,   109,     0,   110,
     342,   111,     0,     0,     0,     0,     0,     0,   112,   616,
       0,   113,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   345,   346,
       0,     0,     0,     0,     0,     0,     0,     0,   347,   348,
     349,     0,     0,     0,     0,   351,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   114,   115,     0,     0,     0,
       0,     0,     0,   116,     0,     0,     0,   117,     0,     0,
       0,     0,     0,     0,   118,     0,     0,   119,   120,   121,
     122,   123,   124,   125,   126,   127,     0,   128,     0,     0,
       0,     0,     0,   129,     0,     0,   130,     0,     0,     0,
     131,     0,     0,   132,   133,     0,   134,     0,     0,   135,
       0,   136,     0,     0,     0,   137,   138,     0,     0,     0,
       0,     0,   352,   353,   354,   355,     0,   143,     0,   144,
       0,     0,     0,     0,   145,     0,     0,     0,   356,  1695,
       0,     0,   357,   358,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   146,   147,
       0,     0,     0,     0,   148,   149,     0,   303,     0,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,   315,   316,     0,   360,    73,    74,     0,     0,
      75,   317,   318,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    76,     0,     0,    77,     0,     0,   319,   320,
     321,   322,   323,   324,   325,     0,    78,     0,     0,   275,
     276,   277,     0,     0,     0,     0,   326,    79,     0,     0,
       0,   169,     0,   170,   171,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    80,     0,     0,    81,     0,     0,
      82,     0,     0,     0,     0,     0,    83,     0,     0,     0,
       0,    84,    85,    86,     0,     0,     0,     0,     0,    87,
       0,     0,     0,     0,   328,     0,     0,    88,   329,     0,
      89,     0,    90,    91,    92,     0,     0,     0,   330,    93,
      94,     0,     0,     0,     0,     0,     0,     0,   331,   332,
     333,   334,   335,  1568,   336,   337,    95,    96,   338,   339,
      97,   340,    98,    99,   100,   101,   102,   103,   104,     0,
     105,   341,   106,   107,   108,   109,     0,   110,   342,   111,
       0,     0,     0,     0,     0,     0,   112,   616,     0,   113,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   345,   346,     0,     0,
       0,     0,     0,     0,     0,     0,   347,   348,   349,     0,
       0,     0,     0,   351,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   114,   115,     0,     0,     0,     0,     0,
       0,   116,     0,     0,     0,   117,     0,     0,     0,     0,
       0,     0,   118,     0,     0,   119,   120,   121,   122,   123,
     124,   125,   126,   127,     0,   128,     0,     0,     0,     0,
       0,   129,     0,     0,   130,     0,     0,     0,   131,     0,
       0,   132,   133,     0,   134,     0,     0,   135,     0,   136,
       0,     0,     0,   137,   138,     0,     0,     0,     0,     0,
     352,   353,   354,   355,     0,   143,     0,   144,     0,     0,
       0,     0,   145,     0,     0,     0,   356,     0,     0,     0,
     357,   358,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   146,   147,     0,     0,
       0,     0,   148,   149,     0,   303,     0,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
     315,   316,     0,   360,    73,    74,     0,     0,    75,   317,
     318,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      76,     0,     0,    77,     0,     0,   319,   320,   321,   322,
     323,   324,   325,     0,    78,     0,     0,   275,   276,   277,
       0,     0,     0,     0,   326,    79,     0,     0,     0,   169,
       0,   170,   171,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    80,     0,     0,    81,     0,     0,    82,     0,
       0,     0,     0,     0,    83,     0,     0,     0,     0,    84,
      85,    86,     0,     0,     0,     0,     0,    87,     0,     0,
       0,     0,   328,     0,     0,    88,   329,     0,    89,     0,
      90,    91,    92,     0,     0,     0,   330,    93,    94,     0,
       0,     0,     0,     0,     0,     0,   331,   332,   333,   334,
     335,     0,   336,   337,    95,    96,   338,   339,    97,   340,
      98,    99,   100,   101,   102,   103,   104,     0,   105,   341,
     106,   107,   108,   109,     0,   110,   342,   111,     0,     0,
       0,     0,     0,     0,   112,   616,     0,   113,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   345,   346,     0,     0,     0,     0,
       0,     0,     0,     0,   347,   348,   349,     0,     0,     0,
       0,   351,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   114,   115,     0,     0,     0,     0,     0,     0,   116,
       0,     0,     0,   117,     0,     0,     0,     0,     0,     0,
     118,     0,     0,   119,   120,   121,   122,   123,   124,   125,
     126,   127,     0,   128,     0,     0,     0,     0,     0,   129,
       0,     0,   130,     0,     0,     0,   131,     0,     0,   132,
     133,     0,   134,     0,     0,   135,     0,   136,     0,     0,
       0,   137,   138,     0,     0,     0,     0,     0,   352,   353,
     354,   355,     0,   143,     0,   144,     0,     0,     0,     0,
     145,     0,     0,     0,   356,     0,     0,     0,   357,   358,
       0,    67,    68,    69,    70,    71,    72,     0,     0,     0,
       0,     0,     0,     0,   146,   147,     0,     0,    73,    74,
     148,   149,    75,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    76,     0,     0,    77,     0,     0,
       0,   360,     0,     0,     0,     0,     0,     0,    78,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    79,
       3,     4,  1520,     6,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     8,     9,  1521,     0,     0,    81,
       0,     0,  1522,     0,     0,     0,     0,     0,    83,     0,
       0,     0,     0,    84,    85,    86,     0,     0,     0,     0,
       0,    87,     0,     0,     0,     0,     0,     0,     0,    88,
       0,     0,    89,     0,    90,    91,    92,   658,     0,     0,
       0,    93,    94,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    95,    96,
       0,     0,    97,     0,    98,    99,   100,   101,   102,   103,
     104,     0,   105,     0,   106,   107,   108,   109,     0,   110,
       0,   111,     0,     0,     0,     0,     0,     0,   112,     0,
       0,   113,     0,     0,     0,   659,   660,   661,   662,   663,
     664,   665,   666,   667,   668,     0,     0,     0,     0,   669,
     670,   671,   672,   673,   674,   675,   676,   677,   678,   679,
     680,   681,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   114,   115,     0,     0,     0,
       0,     0,     0,   116,     0,     0,    15,   117,     0,     0,
       0,     0,     0,     0,   118,    16,  1524,   119,   120,   121,
     122,   123,   124,   125,   126,   127,     0,   128,    25,     0,
       0,     0,     0,   129,    26,    27,   130,     0,     0,     0,
     131,     0,     0,   132,   133,     0,   134,     0,     0,   135,
      28,   136,  1525,    29,     0,   137,   138,     0,     0,     0,
       0,     0,   139,   140,   141,   142,  1819,   143,     0,   144,
       0,     0,     0,     0,   145,     0,     0,     0,  1526,     0,
       0,  1989,     0,     0,  1527,  1990,  -347,     0,     0,     0,
       0,    30,    67,    68,    69,    70,    71,    72,   146,   147,
       0,     0,     0,     0,   148,   149,     0,     0,     0,    73,
      74,     0,     0,    75,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    76,     0,     0,    77,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    78,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      79,     3,     4,  1520,     6,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     8,     9,  1521,     0,     0,
      81,     0,     0,  1522,     0,     0,     0,     0,     0,    83,
       0,     0,     0,     0,    84,    85,    86,     0,     0,     0,
       0,     0,    87,     0,     0,     0,     0,     0,     0,     0,
      88,     0,     0,    89,     0,    90,    91,    92,   658,     0,
       0,     0,    93,    94,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    95,
      96,     0,     0,    97,     0,    98,    99,   100,   101,   102,
     103,   104,     0,   105,     0,   106,   107,   108,   109,     0,
     110,     0,   111,     0,     0,     0,     0,     0,     0,   112,
       0,     0,   113,     0,     0,     0,   659,   660,   661,   662,
     663,   664,   665,   666,   667,   668,     0,     0,     0,     0,
     669,   670,   671,   672,   673,   674,   675,   676,   677,   678,
     679,   680,   681,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   114,   115,     0,     0,
       0,     0,     0,     0,   116,     0,     0,    15,   117,     0,
       0,     0,     0,     0,  1523,   118,    16,  1524,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   682,   128,    25,
       0,     0,     0,     0,   129,    26,    27,   130,     0,     0,
       0,   131,     0,     0,   132,   133,     0,   134,     0,     0,
     135,    28,   136,  1525,    29,     0,   137,   138,     0,     0,
       0,     0,     0,   139,   140,   141,   142,     0,   143,     0,
     144,     0,     0,     0,     0,   145,     0,     0,     0,  1526,
       0,     0,     0,     0,     0,  1527,     0,     0,     0,     0,
    1528,     0,    30,    67,    68,    69,    70,    71,    72,   146,
     147,     0,     0,     0,     0,   148,   149,     0,     0,     0,
      73,    74,     0,     0,    75,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    76,     0,     0,    77,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      78,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    79,     3,     4,  1520,     6,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     8,     9,  1521,     0,
       0,    81,     0,     0,  1522,     0,     0,     0,     0,     0,
      83,     0,  1257,     0,     0,    84,    85,    86,     0,     0,
       0,     0,     0,    87,     0,     0,     0,     0,     0,     0,
       0,    88,     0,     0,    89,     0,    90,    91,    92,   658,
       0,     0,     0,    93,    94,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      95,    96,     0,     0,    97,     0,    98,    99,   100,   101,
     102,   103,   104,     0,   105,     0,   106,   107,   108,   109,
       0,   110,     0,   111,     0,     0,     0,     0,     0,     0,
     112,     0,     0,   113,     0,     0,     0,   659,   660,   661,
     662,   663,   664,   665,   666,   667,   668,     0,     0,     0,
       0,   669,   670,   671,   672,   673,   674,   675,   676,   677,
     678,   679,   680,   681,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   114,   115,     0,
       0,     0,     0,     0,     0,   116,     0,     0,    15,   117,
       0,     0,     0,     0,     0,  1827,   118,    16,  1524,  1828,
     120,   121,   122,   123,   124,   125,   126,   127,     0,   128,
      25,     0,     0,     0,     0,   129,    26,    27,   130,     0,
       0,     0,   131,     0,     0,   132,   133,     0,   134,     0,
       0,   135,    28,   136,  1525,    29,     0,   137,   138,     0,
       0,     0,     0,     0,   139,   140,   141,   142,     0,   143,
       0,   144,     0,     0,     0,     0,   145,     0,     0,     0,
    1526,     0,     0,     0,     0,     0,  1527,     0,     0,     0,
       0,  1528,     0,    30,    67,    68,    69,    70,    71,    72,
     146,   147,     0,     0,     0,     0,   148,   149,     0,     0,
       0,    73,    74,     0,     0,    75,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    76,     0,     0,
      77,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    78,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,     3,     4,  1520,     6,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     8,     9,  1521,
       0,     0,    81,     0,     0,  1522,     0,     0,     0,     0,
       0,    83,     0,     0,     0,     0,    84,    85,    86,  1611,
       0,     0,     0,     0,    87,     0,     0,     0,     0,     0,
       0,     0,    88,     0,     0,    89,     0,    90,    91,    92,
       0,   658,     0,     0,    93,    94,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    95,    96,     0,     0,    97,     0,    98,    99,   100,
     101,   102,   103,   104,     0,   105,     0,   106,   107,   108,
     109,  1612,   110,     0,   111,     0,     0,     0,     0,     0,
       0,   112,     0,     0,   113,     0,     0,     0,     0,   659,
     660,   661,   662,   663,   664,   665,   666,   667,   668,     0,
       0,     0,     0,   669,   670,   671,   672,   673,   674,   675,
     676,   677,   678,   679,   680,   681,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   114,   115,
       0,     0,     0,     0,     0,     0,   116,     0,     0,    15,
     117,     0,     0,     0,     0,     0,     0,   118,    16,  1524,
     119,   120,   121,   122,   123,   124,   125,   126,   127,     0,
     128,    25,     0,     0,     0,     0,   129,    26,    27,   130,
       0,     0,     0,   131,     0,     0,   132,   133,     0,   134,
       0,     0,   135,    28,   136,  1525,    29,     0,   137,   138,
       0,     0,     0,     0,     0,   139,   140,   141,   142,     0,
     143,     0,   144,     0,     0,     0,     0,   145,     0,     0,
       0,  1526,     0,     0,     0,     0,     0,  1527,     0,  -347,
       0,     0,     0,     0,    30,    67,    68,    69,    70,    71,
      72,   146,   147,     0,     0,     0,     0,   148,   149,     0,
       0,     0,    73,    74,     0,     0,    75,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    76,     0,
       0,    77,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    78,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    79,     3,     4,  1520,     6,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     8,     9,
    1521,     0,     0,    81,     0,     0,  1522,     0,     0,     0,
       0,     0,    83,     0,     0,     0,     0,    84,    85,    86,
       0,     0,     0,     0,     0,    87,     0,     0,     0,     0,
       0,     0,     0,    88,     0,     0,    89,     0,    90,    91,
      92,   658,     0,     0,     0,    93,    94,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    95,    96,     0,     0,    97,     0,    98,    99,
     100,   101,   102,   103,   104,     0,   105,     0,   106,   107,
     108,   109,     0,   110,     0,   111,     0,     0,     0,     0,
       0,     0,   112,     0,     0,   113,     0,     0,     0,   659,
     660,   661,   662,   663,   664,   665,   666,   667,   668,     0,
       0,     0,     0,   669,   670,   671,   672,   673,   674,   675,
     676,   677,   678,   679,   680,   681,     0,     0,     0,     0,
       0,     0,  1149,  1150,     0,     0,     0,     0,     0,   114,
     115,     0,     0,     0,     0,     0,     0,   116,     0,     0,
      15,   117,     0,     0,     0,     0,     0,     0,   118,    16,
    1524,   119,   120,   121,   122,   123,   124,   125,   126,   127,
       0,   128,    25,     0,     0,     0,     0,   129,    26,    27,
     130,     0,     0,     0,   131,     0,     0,   132,   133,     0,
     134,     0,     0,   135,    28,   136,  1525,    29,     0,   137,
     138,     0,     0,     0,     0,     0,   139,   140,   141,   142,
       0,   143,     0,   144,     0,     0,     0,     0,   145,     0,
       0,     0,  1526,     0,     0,     0,     0,     0,  1527,     0,
       0,     0,     0,     0,  2047,    30,    67,    68,    69,    70,
      71,    72,   146,   147,     0,     0,     0,     0,   148,   149,
       0,     0,     0,    73,    74,     0,     0,    75,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    76,
       0,     0,    77,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    79,     3,     4,  1520,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     8,
       9,  1521,     0,     0,    81,     0,     0,  1522,     0,     0,
       0,     0,     0,    83,     0,     0,     0,     0,    84,    85,
      86,     0,     0,     0,     0,     0,    87,     0,     0,     0,
       0,     0,     0,     0,    88,     0,     0,    89,     0,    90,
      91,    92,   658,     0,     0,     0,    93,    94,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    95,    96,     0,     0,    97,     0,    98,
      99,   100,   101,   102,   103,   104,     0,   105,     0,   106,
     107,   108,   109,     0,   110,     0,   111,     0,     0,     0,
       0,  1203,     0,   112,     0,     0,   113,     0,     0,     0,
     659,   660,   661,   662,   663,   664,   665,   666,   667,   668,
       0,     0,     0,     0,   669,   670,   671,   672,   673,   674,
     675,   676,   677,   678,   679,   680,   681,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     114,   115,     0,     0,     0,     0,     0,     0,   116,     0,
       0,    15,   117,     0,     0,     0,     0,     0,     0,   118,
      16,  1524,   119,   120,   121,   122,   123,   124,   125,   126,
     127,     0,   128,    25,     0,     0,     0,     0,   129,    26,
      27,   130,     0,     0,     0,   131,     0,     0,   132,   133,
       0,   134,     0,     0,   135,    28,   136,  1525,    29,     0,
     137,   138,     0,     0,     0,     0,     0,   139,   140,   141,
     142,     0,   143,     0,   144,     0,     0,     0,     0,   145,
       0,     0,     0,  1526,     0,     0,     0,     0,     0,  1527,
      67,    68,    69,    70,    71,    72,    30,     0,     0,     0,
       0,     0,     0,   146,   147,     0,     0,    73,    74,   148,
     149,    75,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    76,     0,     0,    77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79,     3,
       4,  1520,     6,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,     8,     9,  1521,     0,     0,    81,     0,
       0,  1522,     0,     0,     0,     0,     0,    83,     0,     0,
       0,     0,    84,    85,    86,     0,     0,     0,     0,     0,
      87,     0,     0,     0,     0,     0,     0,     0,    88,     0,
       0,    89,     0,    90,    91,    92,     0,   658,     0,     0,
      93,    94,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    95,    96,     0,
       0,    97,     0,    98,    99,   100,   101,   102,   103,   104,
       0,   105,     0,   106,   107,   108,   109,  1567,   110,     0,
     111,     0,     0,     0,     0,     0,     0,   112,     0,     0,
     113,     0,     0,     0,     0,   659,   660,   661,   662,   663,
     664,   665,   666,   667,   668,     0,     0,     0,     0,   669,
     670,   671,   672,   673,   674,   675,   676,   677,   678,   679,
     680,   681,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   114,   115,     0,     0,     0,     0,
       0,     0,   116,     0,     0,     0,   117,     0,     0,     0,
       0,     0,     0,   118,    16,  1524,   119,   120,   121,   122,
     123,   124,   125,   126,   127,     0,   128,     0,     0,     0,
       0,     0,   129,    26,    27,   130,     0,     0,     0,   131,
       0,     0,   132,   133,     0,   134,     0,     0,   135,    28,
     136,  1525,     0,     0,   137,   138,     0,     0,     0,     0,
       0,   139,   140,   141,   142,     0,   143,     0,   144,     0,
       0,     0,     0,   145,     0,     0,     0,  1526,     0,     0,
       0,     0,     0,  1527,     0,     0,     0,     0,  1969,     0,
      30,    67,    68,    69,    70,    71,    72,   146,   147,     0,
       0,     0,     0,   148,   149,     0,     0,     0,    73,    74,
       0,     0,    75,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    76,     0,     0,    77,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    78,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    79,
       3,     4,  1520,     6,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     8,     9,  1521,     0,     0,    81,
       0,     0,  1522,     0,     0,     0,     0,     0,    83,     0,
       0,     0,     0,    84,    85,    86,     0,     0,     0,     0,
       0,    87,     0,     0,     0,     0,     0,     0,     0,    88,
       0,     0,    89,     0,    90,    91,    92,     0,   658,     0,
       0,    93,    94,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    95,    96,
       0,     0,    97,     0,    98,    99,   100,   101,   102,   103,
     104,     0,   105,     0,   106,   107,   108,   109,  1615,   110,
       0,   111,     0,     0,     0,     0,     0,     0,   112,     0,
       0,   113,     0,     0,     0,     0,   659,   660,   661,   662,
     663,   664,   665,   666,   667,   668,     0,     0,     0,     0,
     669,   670,   671,   672,   673,   674,   675,   676,   677,   678,
     679,   680,   681,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   114,   115,     0,     0,     0,
       0,     0,     0,   116,     0,     0,     0,   117,     0,     0,
       0,     0,     0,     0,   118,    16,  1524,   119,   120,   121,
     122,   123,   124,   125,   126,   127,     0,   128,     0,     0,
       0,     0,     0,   129,    26,    27,   130,     0,     0,     0,
     131,     0,     0,   132,   133,     0,   134,     0,     0,   135,
      28,   136,  1525,     0,     0,   137,   138,     0,     0,     0,
       0,     0,   139,   140,   141,   142,     0,   143,     0,   144,
       0,     0,     0,     0,   145,     0,     0,     0,  1526,     0,
       0,     0,     0,     0,  1527,     0,     0,     0,     0,     0,
    2083,    30,     0,     0,     0,     0,     0,     0,   146,   147,
       0,     0,     0,     0,   148,   149,    67,    68,    69,    70,
      71,    72,     0,     0,     0,     0,     0,     0,   230,     0,
       0,     0,     0,    73,    74,     0,     0,    75,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    76,
       0,     0,    77,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,     0,     0,     0,     0,     0,   232,
       0,     0,     0,     0,    79,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,     0,     0,    81,     0,     0,    82,     0,     0,
       0,     0,     0,    83,     0,     0,     0,     0,    84,    85,
      86,     0,     0,     0,     0,     0,    87,     0,     0,     0,
       0,     0,     0,     0,    88,     0,     0,    89,     0,    90,
      91,    92,     0,   658,     0,     0,    93,    94,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    95,    96,     0,     0,    97,     0,    98,
      99,   100,   101,   102,   103,   104,     0,   105,     0,   106,
     107,   108,   109,  1618,   110,     0,   111,     0,     0,     0,
       0,     0,     0,   112,     0,     0,   113,     0,     0,     0,
       0,   659,   660,   661,   662,   663,   664,   665,   666,   667,
     668,     0,     0,     0,     0,   669,   670,   671,   672,   673,
     674,   675,   676,   677,   678,   679,   680,   681,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     286,   287,   238,   239,   240,   241,     0,     0,   116,     0,
       0,     0,   117,     0,     0,     0,     0,     0,     0,   118,
       0,     0,   119,   120,   121,   122,   123,   124,   125,   126,
     127,     0,   128,     0,     0,     0,     0,     0,   129,     0,
       0,   130,     0,     0,     0,   131,     0,     0,   132,   133,
       0,   134,     0,     0,   135,     0,   136,     0,     0,     0,
     288,   138,     0,     0,     0,     0,     0,   139,   140,   141,
     142,     0,   143,     0,   144,     0,     0,     0,     0,   145,
      67,    68,    69,    70,    71,    72,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    73,    74,     0,
       0,    75,     0,   146,   147,     0,     0,     0,     0,   148,
     149,     0,     0,    76,     0,     0,    77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,     0,     0,
     275,   276,   277,     0,     0,     0,     0,     0,   278,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    80,     0,     0,    81,     0,
       0,    82,     0,     0,     0,     0,     0,    83,     0,     0,
       0,     0,    84,    85,    86,     0,     0,     0,     0,     0,
      87,     0,     0,     0,     0,     0,     0,     0,    88,     0,
       0,    89,     0,    90,    91,    92,     0,   658,     0,     0,
      93,    94,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    95,    96,     0,
       0,    97,     0,    98,    99,   100,   101,   102,   103,   104,
       0,   105,     0,   106,   107,   108,   109,  1861,   110,     0,
     111,     0,     0,     0,     0,     0,     0,   112,   279,     0,
     113,     0,     0,     0,     0,   659,   660,   661,   662,   663,
     664,   665,   666,   667,   668,     0,     0,     0,     0,   669,
     670,   671,   672,   673,   674,   675,   676,   677,   678,   679,
     680,   681,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   114,   115,     0,     0,     0,     0,
       0,     0,   116,     0,     0,     0,   117,     0,     0,     0,
       0,     0,     0,   118,     0,     0,   119,   120,   121,   122,
     123,   124,   125,   126,   127,     0,   128,     0,     0,     0,
       0,     0,   129,     0,     0,   280,     0,     0,     0,   131,
       0,     0,   132,   133,     0,   134,     0,     0,   281,     0,
     136,     0,     0,     0,   137,   138,     0,     0,     0,     0,
       0,   139,   282,   141,   142,     0,   143,     0,   144,     0,
       0,     0,     0,   145,    67,    68,    69,    70,    71,    72,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    73,    74,     0,     0,    75,     0,   146,   147,     0,
       0,     0,     0,   148,   149,     0,     0,    76,     0,     0,
      77,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    78,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    80,
       0,     0,    81,     0,     0,    82,     0,     0,     0,     0,
       0,    83,     0,     0,     0,     0,    84,    85,    86,     0,
       0,     0,     0,     0,    87,     0,     0,     0,     0,     0,
       0,     0,    88,     0,     0,    89,     0,    90,    91,    92,
       0,   658,     0,     0,    93,    94,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    95,    96,     0,     0,    97,     0,    98,    99,   100,
     101,   102,   103,   104,     0,   105,     0,   106,   107,   108,
     109,  1862,   110,     0,   734,     0,     0,     0,     0,     0,
       0,   112,     0,     0,   113,     0,     0,     0,     0,   659,
     660,   661,   662,   663,   664,   665,   666,   667,   668,     0,
       0,     0,     0,   669,   670,   671,   672,   673,   674,   675,
     676,   677,   678,   679,   680,   681,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   114,   115,
       0,     0,     0,     0,     0,     0,   116,     0,     0,     0,
     117,   264,   265,   266,   267,     0,     0,   118,     0,     0,
     119,   120,   121,   122,   123,   124,   125,   126,   127,     0,
     128,     0,     0,     0,     0,     0,   129,     0,     0,   130,
       0,     0,     0,   131,     0,     0,   132,   133,     0,   134,
       0,     0,   135,     0,   136,     0,     0,     0,   735,   138,
       0,     0,     0,     0,     0,   139,   140,   141,   142,     0,
     143,     0,   144,     0,     0,     0,     0,   145,    67,    68,
      69,  1012,  1013,  1014,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    73,    74,     0,     0,    75,
       0,   146,   147,     0,     0,     0,     0,   148,   149,     0,
       0,    76,     0,     0,    77,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    79,     0,     0,     0,
     169,     0,   170,   171,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    80,     0,     0,    81,     0,     0,    82,
       0,     0,     0,     0,     0,    83,     0,     0,     0,     0,
      84,    85,    86,     0,     0,     0,     0,     0,    87,     0,
       0,     0,     0,     0,     0,     0,    88,     0,     0,    89,
       0,    90,    91,    92,   658,     0,     0,     0,    93,    94,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    95,    96,     0,     0,    97,
       0,    98,    99,   100,   101,   102,   103,   104,     0,   105,
       0,   106,   107,   108,   109,     0,   110,     0,   111,     0,
       0,     0,     0,     0,     0,   112,     0,     0,   113,     0,
       0,     0,   659,   660,   661,   662,   663,   664,   665,   666,
     667,   668,     0,     0,     0,     0,   669,   670,   671,   672,
     673,   674,   675,   676,   677,   678,   679,   680,   681,  1015,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   114,   115,     0,     0,     0,     0,     0,     0,
     116,     0,     0,     0,   117,     0,     0,     0,     0,     0,
       0,   118,     0,     0,   119,   120,   121,   122,   123,   124,
     125,   126,   127,     0,   128,     0,     0,     0,     0,     0,
     129,     0,     0,   130,     0,     0,     0,   131,     0,     0,
     132,   133,     0,   134,     0,     0,   135,     0,   136,     0,
       0,     0,   137,   138,     0,     0,     0,     0,     0,   139,
     140,   141,   142,     0,   143,     0,   144,     0,     0,     0,
       0,   145,    67,    68,    69,    70,    71,    72,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    73,
      74,     0,     0,    75,     0,   146,   147,     0,     0,     0,
       0,   148,   149,     0,     0,    76,     0,     0,    77,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    78,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      79,     0,     0,     0,   169,     0,   170,   171,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    80,     0,     0,
      81,     0,     0,    82,     0,     0,     0,     0,     0,    83,
       0,     0,     0,     0,    84,    85,    86,     0,     0,     0,
       0,     0,    87,     0,     0,     0,     0,     0,     0,     0,
      88,     0,     0,    89,     0,    90,    91,    92,     0,   658,
       0,     0,    93,    94,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    95,
      96,     0,     0,    97,     0,    98,    99,   100,   101,   102,
     103,   104,     0,   105,     0,   106,   107,   108,   109,  1863,
     110,     0,   111,     0,     0,     0,     0,     0,     0,   112,
     590,     0,   113,     0,     0,     0,     0,   659,   660,   661,
     662,   663,   664,   665,   666,   667,   668,     0,     0,     0,
       0,   669,   670,   671,   672,   673,   674,   675,   676,   677,
     678,   679,   680,   681,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   114,   115,     0,     0,
       0,     0,     0,     0,   116,     0,     0,     0,   117,     0,
       0,     0,     0,     0,     0,   118,     0,     0,   119,   120,
     121,   122,   123,   124,   125,   126,   127,     0,   128,     0,
       0,     0,     0,     0,   129,     0,     0,   130,     0,     0,
       0,   131,     0,     0,   132,   133,     0,   134,     0,     0,
     135,     0,   136,     0,     0,     0,   137,   138,     0,     0,
       0,     0,     0,   139,   140,   141,   142,     0,   143,     0,
     144,     0,     0,     0,     0,   145,    67,    68,    69,  1012,
    1013,  1014,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    73,    74,     0,     0,    75,     0,   146,
     147,     0,     0,     0,     0,   148,   149,     0,     0,    76,
       0,     0,    77,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    79,     0,     0,     0,   169,     0,
     170,   171,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,     0,     0,    81,     0,     0,    82,     0,     0,
       0,     0,     0,    83,     0,     0,     0,     0,    84,    85,
      86,     0,     0,     0,     0,     0,    87,     0,     0,     0,
       0,     0,     0,     0,    88,     0,     0,    89,     0,    90,
      91,    92,     0,     0,     0,     0,    93,    94,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    95,    96,     0,     0,    97,     0,    98,
      99,   100,   101,   102,   103,   104,     0,   105,     0,   106,
     107,   108,   109,     0,   110,     0,   111,     0,     0,     0,
       0,     0,     0,   112,     0,     0,   113,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1458,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     114,   115,     0,     0,     0,     0,     0,     0,   116,     0,
       0,     0,   117,     0,     0,     0,     0,     0,     0,   118,
       0,     0,   119,   120,   121,   122,   123,   124,   125,   126,
     127,     0,   128,     0,     0,     0,     0,     0,   129,     0,
       0,   130,     0,     0,     0,   131,     0,     0,   132,   133,
       0,   134,     0,     0,   135,     0,   136,     0,     0,     0,
     137,   138,     0,     0,     0,     0,     0,   139,   140,   141,
     142,     0,   143,     0,   144,     0,     0,     0,     0,   145,
      67,    68,    69,    70,    71,    72,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    73,    74,     0,
       0,    75,     0,   146,   147,     0,     0,     0,     0,   148,
     149,     0,     0,    76,     0,     0,    77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79,     0,
       0,     0,   169,     0,   170,   171,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    80,     0,     0,    81,     0,
       0,    82,     0,     0,     0,     0,     0,    83,     0,     0,
       0,     0,    84,    85,    86,     0,     0,     0,     0,     0,
      87,     0,     0,     0,     0,     0,     0,     0,    88,     0,
       0,    89,     0,    90,    91,    92,     0,     0,     0,     0,
      93,    94,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    95,    96,     0,
       0,    97,     0,    98,    99,   100,   101,   102,   103,   104,
       0,   105,     0,   106,   107,   108,   109,     0,   110,     0,
     111,     0,     0,     0,     0,     0,     0,   112,     0,     0,
     113,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   114,   115,     0,     0,     0,     0,
       0,     0,   116,     0,     0,     0,   117,     0,     0,     0,
       0,     0,     0,   118,     0,     0,   119,   120,   121,   122,
     123,   124,   125,   126,   127,     0,   128,     0,     0,     0,
       0,     0,   129,     0,     0,   130,     0,     0,     0,   131,
       0,     0,   132,   133,     0,   134,     0,     0,   135,     0,
     136,     0,     0,     0,   137,   138,     0,     0,     0,     0,
       0,   139,   140,   141,   142,     0,   143,     0,   144,     0,
       0,     0,     0,   145,    67,    68,    69,  1012,  1013,  1014,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    73,    74,     0,     0,    75,     0,   146,   147,     0,
       0,     0,     0,   148,   149,     0,     0,    76,     0,     0,
      77,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    78,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,     0,     0,     0,   169,     0,   170,   171,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    80,
       0,     0,    81,     0,     0,    82,     0,     0,     0,     0,
       0,    83,     0,     0,     0,     0,    84,    85,    86,     0,
       0,     0,     0,     0,    87,     0,     0,     0,     0,     0,
       0,     0,    88,     0,     0,    89,     0,    90,    91,    92,
       0,     0,     0,     0,    93,    94,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    95,    96,     0,     0,    97,     0,    98,    99,   100,
     101,   102,   103,   104,     0,   105,     0,   106,   107,   108,
     109,     0,   110,     0,   111,     0,     0,     0,     0,     0,
       0,   112,     0,     0,   113,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   114,   115,
       0,     0,     0,     0,     0,     0,   116,     0,     0,     0,
     117,     0,     0,     0,     0,     0,     0,   118,     0,     0,
     119,   120,   121,   122,   123,   124,   125,   126,   127,     0,
     128,     0,     0,     0,     0,     0,   129,     0,     0,   130,
       0,     0,     0,   131,     0,     0,   132,   133,     0,   134,
       0,     0,   135,     0,   136,     0,     0,     0,   137,   138,
       0,     0,     0,     0,     0,   139,   140,   141,   142,     0,
     143,     0,   144,     0,     0,     0,     0,   145,    67,    68,
      69,    70,    71,    72,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    73,    74,     0,     0,    75,
       0,   146,   147,     0,     0,     0,     0,   148,   149,     0,
       0,    76,     0,     0,    77,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    79,     0,     0,   166,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    80,     0,     0,    81,     0,     0,    82,
       0,     0,     0,     0,     0,    83,     0,     0,     0,     0,
      84,    85,    86,     0,     0,     0,     0,     0,    87,     0,
       0,     0,     0,     0,     0,     0,    88,     0,     0,    89,
       0,    90,    91,    92,     0,     0,     0,     0,    93,    94,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    95,    96,     0,     0,    97,
       0,    98,    99,   100,   101,   102,   103,   104,     0,   105,
       0,   106,   107,   108,   109,     0,   110,     0,   111,     0,
       0,     0,     0,     0,     0,   112,    14,     0,   113,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   114,   115,     0,     0,     0,     0,     0,     0,
     116,     0,     0,     0,   117,     0,     0,     0,     0,     0,
       0,   118,     0,     0,   119,   120,   121,   122,   123,   124,
     125,   126,   127,     0,   128,     0,     0,     0,     0,     0,
     129,     0,     0,   130,     0,     0,     0,   131,     0,     0,
     132,   133,     0,   134,     0,     0,   135,     0,   136,     0,
       0,     0,   137,   138,     0,     0,     0,     0,     0,   139,
     140,   141,   142,     0,   143,     0,   144,     0,     0,     0,
       0,   145,    67,    68,    69,    70,    71,    72,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    73,
      74,     0,     0,    75,     0,   146,   147,     0,     0,     0,
       0,   148,   149,     0,     0,    76,     0,     0,    77,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    78,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      79,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    80,     0,     0,
      81,     0,     0,    82,     0,     0,     0,     0,     0,    83,
       0,     0,     0,     0,    84,    85,    86,     0,     0,     0,
       0,     0,    87,     0,     0,     0,     0,     0,     0,     0,
      88,     0,     0,    89,     0,    90,    91,    92,     0,     0,
       0,     0,    93,    94,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    95,
      96,     0,     0,    97,     0,    98,    99,   100,   101,   102,
     103,   104,     0,   105,     0,   106,   107,   108,   109,     0,
     110,     0,   111,     0,     0,     0,     0,     0,     0,   112,
       0,     0,   113,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1328,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   114,   115,     0,     0,
       0,     0,     0,     0,   116,     0,  1299,     0,   117,     0,
       0,     0,     0,     0,     0,   118,     0,     0,   119,   120,
     121,   122,   123,   124,   125,   126,   127,     0,   128,     0,
       0,     0,     0,     0,   129,     0,     0,   130,     0,     0,
       0,   131,     0,     0,   132,   133,     0,   134,     0,     0,
     135,     0,   136,     0,     0,     0,   137,   138,     0,     0,
       0,     0,     0,   139,   140,   141,   142,     0,   143,     0,
     144,     0,     0,     0,     0,   145,    67,    68,    69,    70,
      71,    72,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    73,    74,     0,     0,    75,     0,   146,
     147,     0,     0,     0,     0,   148,   149,     0,     0,    76,
       0,     0,    77,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    79,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,     0,     0,    81,     0,     0,    82,     0,     0,
       0,     0,     0,    83,     0,     0,     0,     0,    84,    85,
      86,     0,     0,     0,     0,     0,    87,     0,     0,     0,
       0,     0,     0,     0,    88,     0,     0,    89,     0,    90,
      91,    92,     0,     0,     0,     0,    93,    94,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    95,    96,     0,     0,    97,     0,    98,
      99,   100,   101,   102,   103,   104,     0,   105,     0,   106,
     107,   108,   109,     0,   110,     0,   111,     0,     0,     0,
       0,     0,     0,   112,     0,     0,   113,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     114,   115,     0,     0,     0,     0,     0,     0,   116,     0,
       0,     0,   117,     0,     0,     0,     0,     0,     0,   118,
       0,     0,   119,   120,   121,   122,   123,   124,   125,   126,
     127,     0,   128,     0,     0,     0,     0,     0,   129,     0,
       0,   130,     0,     0,     0,   131,     0,     0,   132,   133,
       0,   134,     0,     0,   135,   462,   136,     0,     0,     0,
     137,   138,     0,     0,     0,     0,     0,   139,   140,   141,
     142,     0,   143,     0,   144,     0,     0,     0,     0,   145,
      67,    68,    69,    70,    71,    72,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    73,    74,     0,
       0,    75,     0,   146,   147,     0,     0,     0,     0,   148,
     149,     0,     0,    76,     0,     0,    77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    80,     0,     0,    81,     0,
       0,    82,     0,     0,     0,     0,     0,    83,     0,     0,
       0,     0,    84,    85,    86,     0,     0,     0,     0,     0,
      87,     0,     0,     0,     0,     0,     0,     0,    88,     0,
       0,    89,     0,    90,    91,    92,     0,     0,     0,     0,
      93,    94,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    95,    96,     0,
       0,    97,     0,    98,    99,   100,   101,   102,   103,   104,
       0,   105,     0,   106,   107,   108,   109,     0,   110,     0,
     111,     0,     0,     0,     0,     0,     0,   112,   279,     0,
     113,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   114,   115,     0,     0,     0,     0,
       0,     0,   116,     0,     0,     0,   117,     0,     0,     0,
       0,     0,     0,   118,     0,     0,   119,   120,   121,   122,
     123,   124,   125,   126,   127,     0,   128,     0,     0,     0,
       0,     0,   129,     0,     0,   130,     0,     0,     0,   131,
       0,     0,   132,   133,     0,   134,     0,     0,   135,     0,
     136,     0,     0,     0,   137,   138,     0,     0,     0,     0,
       0,   139,   140,   141,   142,     0,   143,     0,   144,     0,
       0,     0,     0,   145,    67,    68,    69,    70,    71,    72,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    73,    74,     0,     0,    75,     0,   146,   147,     0,
       0,     0,     0,   148,   149,     0,     0,    76,     0,     0,
      77,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    78,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    80,
       0,     0,    81,     0,     0,    82,     0,     0,     0,     0,
       0,    83,     0,     0,     0,     0,    84,    85,    86,     0,
       0,     0,     0,     0,    87,     0,     0,     0,     0,     0,
       0,     0,    88,     0,     0,    89,     0,    90,    91,    92,
       0,     0,     0,     0,    93,    94,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    95,    96,     0,     0,    97,     0,    98,    99,   100,
     101,   102,   103,   104,     0,   105,     0,   106,   107,   108,
     109,     0,   110,     0,   111,     0,     0,     0,     0,     0,
       0,   112,     0,     0,   113,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   114,   115,
       0,     0,     0,     0,     0,     0,   116,     0,     0,     0,
     117,     0,     0,     0,     0,     0,     0,   118,     0,     0,
     119,   120,   121,   122,   123,   124,   125,   126,   127,     0,
     128,     0,     0,     0,     0,     0,   129,     0,     0,   130,
       0,     0,     0,   131,     0,     0,   132,   133,     0,   134,
       0,     0,   135,     0,   136,     0,     0,     0,   137,   138,
       0,     0,     0,     0,     0,   139,   140,   141,   142,     0,
     143,     0,   144,     0,     0,     0,     0,   145,    67,    68,
      69,    70,    71,    72,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    73,    74,     0,     0,    75,
       0,   146,   147,     0,     0,     0,     0,   148,   149,     0,
       0,    76,     0,     0,    77,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    79,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    80,     0,     0,    81,     0,     0,    82,
       0,     0,     0,     0,     0,    83,     0,     0,     0,     0,
      84,    85,    86,     0,     0,     0,     0,     0,    87,     0,
       0,     0,     0,     0,     0,     0,    88,     0,     0,    89,
       0,    90,    91,    92,     0,     0,     0,     0,    93,    94,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    95,    96,     0,     0,    97,
       0,    98,    99,   100,   101,   102,   103,   104,     0,   105,
       0,   106,   107,   108,   109,     0,   110,     0,   111,     0,
       0,     0,     0,     0,     0,   112,     0,     0,   113,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   114,   115,     0,     0,     0,     0,     0,     0,
     116,     0,  1299,     0,   117,     0,     0,     0,     0,     0,
       0,   118,     0,     0,   119,   120,   121,   122,   123,   124,
     125,   126,   127,     0,   128,     0,     0,     0,     0,     0,
     129,     0,     0,   130,     0,     0,     0,   131,     0,     0,
     132,   133,     0,   134,     0,     0,   135,     0,   136,     0,
       0,     0,   137,   138,     0,     0,     0,     0,     0,   139,
     140,   141,   142,     0,   143,     0,   144,     0,     0,     0,
       0,   145,    67,    68,    69,    70,    71,    72,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    73,
      74,     0,     0,    75,     0,   146,   147,     0,     0,     0,
       0,   148,   149,     0,     0,    76,     0,     0,    77,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    78,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      79,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    80,     0,     0,
      81,     0,     0,    82,     0,     0,     0,     0,     0,    83,
       0,     0,     0,     0,    84,    85,    86,     0,     0,     0,
       0,     0,    87,     0,     0,     0,     0,     0,     0,     0,
      88,     0,     0,    89,     0,    90,    91,    92,     0,     0,
       0,     0,    93,    94,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    95,
      96,     0,     0,    97,     0,    98,    99,   100,   101,   102,
     103,   104,     0,   105,     0,   106,   107,   108,   109,     0,
     110,     0,   111,     0,     0,     0,     0,     0,     0,   112,
       0,     0,   113,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   114,   115,     0,     0,
       0,     0,     0,     0,   116,     0,     0,     0,   117,     0,
       0,     0,     0,     0,     0,   118,     0,     0,   119,   120,
     121,   122,   123,   124,   125,   126,   127,     0,   128,     0,
       0,     0,     0,     0,   129,     0,     0,   130,     0,     0,
       0,   131,     0,     0,   132,   133,     0,   134,     0,     0,
     135,     0,   136,     0,     0,     0,   137,   138,     0,     0,
       0,     0,     0,   139,   140,   141,   142,     0,   143,     0,
     144,     0,     0,     0,     0,   145,    67,    68,    69,    70,
      71,    72,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    73,    74,     0,     0,    75,     0,   146,
     147,     0,     0,     0,     0,   148,   149,     0,     0,    76,
       0,     0,    77,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    79,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,     0,     0,    81,     0,     0,    82,     0,     0,
       0,     0,     0,    83,     0,     0,     0,     0,    84,    85,
      86,     0,     0,     0,     0,     0,    87,     0,     0,     0,
       0,     0,     0,     0,    88,     0,     0,    89,     0,    90,
      91,    92,     0,     0,     0,     0,    93,    94,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    95,    96,     0,     0,    97,     0,    98,
      99,   100,   101,   102,   103,   104,     0,   105,     0,   106,
     107,   108,   109,     0,   110,     0,   111,     0,     0,     0,
       0,     0,     0,   112,     0,     0,   113,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     114,   115,     0,     0,     0,     0,     0,     0,   791,     0,
       0,     0,   117,     0,     0,     0,     0,     0,     0,   118,
       0,     0,   119,   120,   121,   122,   123,   124,   125,   126,
     127,     0,   128,     0,     0,     0,     0,     0,   129,     0,
       0,   130,     0,     0,     0,   131,     0,     0,   132,   133,
       0,   134,     0,     0,   135,     0,   136,     0,     0,     0,
     137,   138,     0,     0,     0,     0,     0,   139,   140,   141,
     142,     0,   143,     0,   144,     0,     0,     0,     0,   145,
      67,    68,    69,    70,    71,    72,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    73,    74,     0,
       0,    75,     0,   146,   147,     0,     0,     0,     0,   148,
     149,     0,     0,    76,     0,     0,    77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    80,     0,     0,    81,     0,
       0,    82,     0,     0,     0,     0,     0,    83,     0,     0,
       0,     0,    84,    85,    86,     0,     0,     0,     0,     0,
      87,     0,     0,     0,     0,     0,     0,     0,    88,     0,
       0,    89,     0,    90,    91,    92,     0,     0,     0,     0,
      93,    94,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    95,    96,     0,
       0,    97,     0,    98,    99,   100,   101,   102,   103,   104,
       0,   105,     0,   106,   107,   108,   109,     0,   110,     0,
     111,     0,     0,     0,     0,     0,     0,   112,     0,     0,
     113,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   114,   115,     0,     0,     0,     0,
       0,     0,   116,     0,     0,     0,   117,     0,     0,     0,
       0,     0,     0,   118,     0,     0,   119,   120,   121,   122,
     123,   124,   125,   126,   127,     0,   128,     0,     0,     0,
       0,     0,   129,     0,     0,   130,     0,     0,     0,   131,
       0,     0,   132,   133,     0,   134,     0,     0,   135,     0,
     136,     0,     0,     0,   137,   138,     0,     0,     0,     0,
       0,   139,   140,   141,   142,     0,   143,     0,   144,     0,
       0,     0,     0,   145,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   146,  1241,     0,
       0,     0,     0,   148,   149
};

static const yytype_int16 yycheck[] =
{
       4,     0,   166,   780,   416,     9,    35,   432,     0,    13,
     165,   301,   772,    17,    18,     0,   291,   639,   221,   219,
       0,   176,   945,    36,    17,     0,   291,   595,   552,  1073,
     592,    35,    36,   688,   452,   603,    14,     0,   193,   194,
     597,   436,     0,   198,   694,  1371,   291,    11,   605,  1068,
    1344,     3,    85,   464,     3,     0,   435,    16,    24,   343,
     344,   891,    66,   893,   940,   327,    66,   551,     0,  1655,
      11,   965,   966,    14,   904,   359,  1095,     4,   507,   947,
     343,   803,   804,   805,   111,    58,   509,   510,   511,   754,
     755,    18,  1186,   111,   568,   760,   214,  1718,     3,   568,
    1721,     0,   173,     3,   642,   188,   158,    26,  1441,     5,
       6,     7,     8,     9,    10,   111,    84,  1809,  1444,   229,
       5,     6,     7,     8,     9,    10,  1452,    42,    43,   166,
     167,   168,  1324,    20,   178,   133,    27,    24,    25,    66,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,   155,   156,  1082,  1083,  1084,  1085,   161,    83,   266,
       3,   344,   155,  1444,   111,   348,    53,    54,    83,   279,
     280,  1452,   111,   173,   142,   262,  1105,   173,   177,   178,
     179,   180,   181,   171,   109,   177,   178,   179,   180,   181,
      55,   111,   177,   178,   179,   180,   181,   177,   178,   179,
     180,   181,   177,   178,   179,   180,   181,   251,  1794,    81,
      53,   215,   216,   217,   177,   178,   179,   180,   181,   177,
     178,   179,   180,   181,   173,     0,  1918,   231,  1920,   156,
     178,   235,   177,   178,   179,   180,   181,   344,   242,   243,
     323,   219,   716,   247,   248,   177,   178,   179,   180,   181,
     115,   255,   256,   257,   258,   259,   260,   636,   171,   263,
     264,   265,   266,   267,   268,   527,   529,     3,   272,   273,
     473,  1324,   301,   173,   345,   279,   280,   281,   177,   178,
     179,   180,   181,   173,   696,   754,   755,   192,   193,   216,
     217,   760,   344,   212,  1627,   627,   691,   301,   302,  1222,
     173,   171,   188,   251,   174,  1926,  1498,   570,   235,   342,
    1404,   348,   303,   304,   305,   242,   289,   344,   581,   582,
     247,   248,   606,   847,   742,   743,   344,   331,   255,   256,
     257,   258,   900,   260,   872,   490,   263,   264,   265,   266,
     267,    16,   460,   606,   344,   272,   273,    66,  1224,   906,
    1005,   762,  1007,   616,  1700,  1223,   344,  1187,   317,   274,
    1190,   352,   646,   647,   848,   343,    66,   319,   631,   318,
     374,   262,   656,   258,  1960,   271,   261,   173,   188,   808,
     809,   810,   811,   806,  1106,   349,  1051,   416,   163,  1715,
     819,   820,   821,   867,    69,    70,    71,   344,    73,    74,
      66,    76,   177,   178,   179,   180,   181,  1701,   349,   400,
     401,   336,  1706,    64,   279,     0,   341,   244,   304,   173,
     188,   308,    58,   427,   344,     0,    83,   173,   432,    79,
      56,   344,   436,    84,   279,   171,    62,   173,    11,   432,
      64,    65,    66,    67,   174,  1498,    66,   374,   174,    11,
     454,    87,   171,     3,   173,   345,   174,   344,   721,    64,
      65,    66,    67,  1939,   468,   443,   266,   174,   472,   111,
    1816,   171,   345,   173,   344,   174,  1822,   174,   111,   470,
     174,   104,   110,   328,   488,   489,   761,   110,   492,  1508,
     494,   110,   174,    66,   304,   170,   761,   501,   281,   503,
     504,   505,   506,   160,   779,   171,   163,   173,   840,   841,
     514,   515,   516,   716,   779,   174,   761,   530,   522,  1413,
    1414,    87,   917,  1898,   528,   174,   530,   454,   151,  1823,
    2006,   910,   451,   188,   779,   158,   304,   174,   813,     0,
     174,   468,   174,   174,   344,   472,    21,    22,   813,   345,
     554,   171,  1382,   173,   178,   830,   174,   176,   174,   174,
    1906,   344,   489,  1393,   283,   830,   174,   494,     0,  1915,
    1400,   174,   174,   776,   501,  1225,   503,   504,   505,   506,
    1142,   871,  1051,   283,   250,   830,   174,   514,   515,   516,
     265,   345,   177,   178,   179,   180,   181,   174,   171,   345,
     173,   252,   177,   178,   179,   180,   181,   174,   870,  1231,
     873,   173,   590,  1268,   344,  1172,  1238,   283,   344,   774,
     262,   171,   250,   173,   188,   249,   344,   174,   606,   262,
     250,   188,   916,   110,   174,   639,   640,   344,   616,   630,
     644,  1987,   174,  1989,   249,   344,   639,   344,   272,   304,
     344,   174,  1031,   937,   481,   482,   483,   484,   624,   174,
     626,   234,   344,   283,   867,    83,   493,   272,   116,   117,
     118,   119,   120,   121,   122,   123,   960,   939,   126,   963,
     964,   685,    66,   687,   127,   344,  1115,   691,   692,   132,
       5,   315,   685,  2068,   110,   344,    11,  1620,   173,   176,
     323,     5,     6,     7,     8,     9,    10,   344,   171,     3,
     344,   973,   344,   344,   692,    66,   177,   178,   179,   180,
     181,   344,    83,  2069,   300,   115,   344,   300,   344,   344,
     174,   735,   133,   252,   279,   151,   344,    99,    86,   705,
     316,   344,   344,   721,   188,  1789,  1790,   311,   110,   110,
     158,   228,   125,   102,   172,   274,   344,    83,   343,   133,
      64,    65,    66,    67,   154,   748,   174,   344,   116,   773,
     118,   119,   120,   121,   122,   123,   149,   344,   126,   783,
     784,   785,   786,   328,   133,   274,   229,   791,    66,   173,
    1052,   254,   269,   158,   777,   272,   800,   344,   802,   803,
     804,   805,   237,   807,   344,   282,   241,   250,   735,   174,
     345,   274,   344,  1435,   176,  1437,   110,   166,   167,   168,
     171,   344,   173,    39,    40,   174,   174,   153,   110,   344,
     156,  1399,  1211,    67,  1402,  1110,   174,   174,  1362,  1218,
     115,  1220,   871,   134,   190,  1110,   773,   165,   839,  1052,
     188,   188,  1247,    88,    88,    71,   783,   784,   785,   786,
      95,    96,  1291,  1292,  1293,  1110,   148,   871,   150,   151,
     874,   837,  1267,   800,   178,   323,  1079,   152,   173,   154,
     807,   230,   886,   861,   862,   863,   252,   853,   250,   253,
     894,  1166,  1167,   171,  1647,   173,   152,   901,   154,  1099,
    1653,  1166,  1167,   252,   173,   269,  1666,  1667,   274,   258,
     259,   277,   278,   917,   232,   233,   234,   235,   282,  1074,
     322,  1166,  1167,   214,   215,   216,   217,   218,   277,   173,
      88,   110,   923,    91,   925,   939,   940,   102,  1919,    97,
    1921,   945,   946,   947,    86,   249,   939,   940,   127,   102,
     299,   300,   301,   132,   345,   165,    69,    70,    71,   886,
      73,    74,    75,    76,   270,    69,    70,    71,   272,    73,
      74,   303,    76,   305,   116,   323,   118,   119,   120,   121,
     122,   123,   177,   178,   126,   281,   181,   965,   966,   303,
     230,   305,   166,   167,   168,   344,   303,   176,   305,  1621,
     174,   166,   167,   168,  1890,   590,  1892,  1893,  1894,   174,
     344,   315,   252,   166,   167,   168,   265,  1021,   258,   259,
     344,   606,   232,   233,   234,   235,   166,   167,   168,  1304,
     266,   616,  1411,  1412,   174,    64,    65,   277,    67,  1304,
     266,  1043,  1421,  1045,  1046,  1049,  1050,   219,   220,   228,
     229,   134,   219,   220,  1058,  1059,  1047,   170,  1062,  1304,
    1038,    87,  1066,  1067,  1068,  1069,   170,    69,    70,    71,
    1638,   250,    42,    43,    76,   832,  1069,  1352,   835,   836,
     837,   303,  1086,   305,   166,   167,   168,  1352,    11,  1093,
     269,  1095,   174,   272,    82,    83,   853,   854,   855,   856,
    1104,   177,  1106,   282,   180,   181,   182,   183,   184,   185,
     186,   187,   290,  1525,   292,   191,   294,   295,   296,   297,
     166,   167,   168,     5,     6,     7,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   721,  1337,    20,   262,
    1067,   262,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,     5,     6,     7,     8,
       9,    10,   279,  1447,  1448,   940,   321,  1735,    89,    90,
      52,    53,    54,   279,     5,     6,     7,  1104,   255,   256,
     279,   323,  1445,   653,   654,   655,  1754,   326,   327,    20,
     100,   101,   279,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,   279,   280,   290,
     291,   292,   293,   294,   295,   296,   297,   279,  1222,  1223,
    1224,    52,    53,    54,   192,   193,   233,  1231,   182,   183,
     308,  1224,    93,    94,  1238,    89,    90,  1241,  1231,   330,
     331,     3,     4,  1247,  1248,  1238,  1224,   322,   323,   324,
     325,   233,  1230,  1028,   328,   329,    64,    65,   308,   179,
     180,  1686,  1525,  1267,  1527,  1269,  1257,   290,   344,   292,
     134,   294,   295,   296,   297,   227,  1551,  1552,  2055,  1554,
     270,   271,   767,   768,  2030,  2031,  1551,  1552,   298,  1554,
     296,   297,   566,   567,  1285,  1299,   177,   177,   177,   130,
     131,   279,   279,   344,   104,    55,  1551,  1552,   299,  1554,
     285,     3,     3,   173,   173,   173,   173,  1308,   173,  1323,
    1311,  1312,    22,  1327,  1328,  1324,  1339,   173,   173,   173,
     125,  1335,  1324,   173,  1327,  1339,  1340,   173,   173,   173,
    1344,  1345,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   940,  1520,   173,   173,   173,
     173,  1624,   173,   173,   173,   115,   173,  1371,   173,   173,
     173,   173,   190,   334,   345,   344,  1944,   173,   334,  1324,
     173,    17,   173,   281,    92,    98,   344,   323,   301,   133,
    1394,  1357,  1324,  1359,   134,  1361,   133,   133,   315,   111,
    1366,  1328,  1814,   112,   286,   287,   288,   289,   112,   174,
     262,   300,   171,  1340,   237,   165,   171,   173,   176,    55,
     173,   173,    58,   106,   173,  1324,   173,    17,   178,    38,
     173,  1435,  1695,  1437,   233,  1413,  1414,  1441,   173,  1702,
    1444,   173,  1435,  1028,  1437,  1474,   173,   173,  1452,  1224,
     173,   173,   173,   173,   173,   286,   287,   288,   289,   173,
     177,   300,   344,   169,    23,    55,   177,   103,    58,   105,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   115,
     345,   231,   232,   233,   234,   235,    55,  1491,   174,   112,
    1481,   155,  1483,  1484,     3,   173,   238,   238,   174,  1498,
     171,   173,   283,  1516,  1508,   173,  1498,   173,   206,   347,
     260,   174,  1516,   103,    82,   105,    79,   173,   111,   243,
    1524,   281,   273,   273,   257,   115,   104,   171,   111,   279,
     316,  1524,   280,   171,   284,   177,  1826,   238,   180,   181,
     182,   183,   184,   185,   186,   187,   115,   250,   190,   191,
     106,   177,   227,  1498,   180,   181,   182,   183,   184,   185,
     186,   187,   261,   265,   190,   191,  1498,   173,   188,   323,
      23,   321,   344,   104,   324,   344,  1580,   323,   111,   173,
     344,   158,   146,   219,   220,   221,   222,   223,   224,   102,
     174,   281,   287,   174,  1623,   231,   165,  1524,   177,  1498,
     134,   180,   181,   182,   183,   184,   185,   186,   187,   178,
     344,   109,   191,  1876,   344,   110,  1620,  1621,   314,  1648,
    1649,   174,   174,  1627,   260,   335,   344,   173,  1621,   219,
     220,   221,   222,   223,   224,   173,   173,   273,    88,  1224,
     261,   231,  1917,   279,   111,   258,   282,   344,   284,   257,
      90,   110,  1917,   111,   257,   317,   173,    20,   110,   234,
      99,  1665,   231,   232,   233,   234,   235,   268,  1672,   323,
     260,  1662,  1917,   325,   265,   127,   281,  1668,  1669,   344,
     132,   133,  1686,  1687,   174,   321,   174,   174,   324,   279,
     174,   260,   282,  1686,   284,   174,   344,  1701,   174,   174,
     174,   174,  1706,   344,   174,  1968,  1996,   344,   174,   174,
     279,  1715,  1716,   174,   174,   284,   173,  1708,     5,     6,
       7,   323,   174,  1878,   176,   174,   174,  1990,  1732,   344,
     344,   321,   104,    20,   324,   161,   174,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,   173,   321,   173,   173,   324,   298,   314,   111,  1763,
     174,   174,   174,    75,    75,    52,    53,    54,    72,   173,
     104,  1762,   108,  2048,  1778,   104,   228,   229,   230,   174,
     102,   134,   174,  2048,   180,   181,   182,   183,   184,   185,
     186,   187,   174,    16,  1949,   191,   323,   266,   250,   173,
     252,   111,   266,  2048,   171,  1809,   258,   259,   174,   265,
     265,   274,   236,   241,   174,   236,   174,   269,   250,  1823,
     272,   323,  1826,   143,   143,   277,   174,   345,   346,   174,
     282,   174,    75,   351,   281,   173,   104,   174,   356,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   174,
     331,  1778,  1856,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   274,   250,   173,  1873,
     264,   264,   344,   344,   238,     3,   344,   267,  1882,     3,
     171,   228,  1886,    77,   238,   237,     5,   174,  1879,   134,
     344,  2094,   344,   174,  1898,   312,   333,   174,  1902,  1898,
    2103,   310,   346,  1907,   174,   174,  1898,   173,  1912,   345,
     344,   344,   174,  1898,  1918,   265,  1920,   435,  1898,   265,
    1924,   265,   174,  1898,   265,   443,   174,   162,  1919,   174,
    1921,   191,   110,   344,  1938,  1898,   257,   344,   273,   128,
    1898,    83,   171,   173,   112,   238,  1873,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,  1961,  1962,  1963,
    1964,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   266,   173,   173,   173,   110,   110,
    1984,   110,   265,   265,   174,   110,   328,   272,   339,   173,
    1994,   344,  1996,   323,     3,   344,   229,   337,   273,   286,
     287,   288,   289,     5,     6,     7,   339,   264,   172,   332,
      85,    85,   262,   303,   345,   314,   133,   238,    20,     5,
     238,     5,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,   345,  2041,   344,  2043,
     154,   151,   151,   323,   562,   156,     3,   190,   129,    59,
      52,    53,    54,   173,   133,   302,   174,   159,   314,   314,
     156,   153,   340,   328,  2068,   173,   113,  2071,    60,  2068,
     312,   133,   339,   314,   302,   314,  2068,   595,   596,   597,
     338,  2085,   328,  2068,   265,   603,    61,   605,  2068,   308,
     310,   265,   265,  2068,   320,    64,   173,    65,   133,   344,
      41,   619,   620,   621,  1093,  2068,  1498,  1278,   212,  1040,
    2068,   211,  2024,   762,   453,    36,  1653,   635,   636,  1068,
    1508,  2076,  2062,   455,  2061,  2054,  2023,     0,     1,  1821,
    2068,  1821,  1706,  1554,   652,   653,   654,   655,  1697,  2085,
     658,   659,   660,   661,   662,   663,   664,   665,   666,   667,
     668,   669,   670,   671,   672,   673,   674,   675,   676,   677,
     678,   679,   680,   681,  1352,  1800,   454,   706,     8,   687,
     688,   159,  1799,  1486,  1882,  1885,  1957,   696,    51,  1484,
    1483,     5,     6,     7,     8,     9,    10,  1412,  1411,   871,
    1038,    64,    65,    66,    67,  1235,  1626,  1248,    22,    23,
     427,   643,    26,   573,    77,    78,    79,    80,   868,  1634,
     949,  1148,   657,    86,    38,   908,   708,    41,   649,   926,
    1754,   656,    35,   685,   526,   582,  1721,  1923,    52,   634,
    1572,  1719,  1392,  1735,  1381,   604,   930,  1850,  1579,    63,
    1384,   930,    66,    67,    68,    69,    70,  1935,  1943,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    83,
     133,    -1,    86,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      -1,    -1,    -1,    97,    98,    99,    -1,   279,    -1,    -1,
      -1,   105,    -1,    -1,   286,   287,   288,   289,    -1,   113,
      -1,    -1,   116,    -1,   118,   119,   120,    -1,   171,    -1,
     173,   125,   126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,   143,
      -1,    -1,   146,    -1,   148,   149,   150,   151,   152,   153,
     154,    -1,   156,    -1,   158,   159,   160,   161,    -1,   163,
      -1,   165,    -1,    -1,    -1,    -1,    -1,   171,   172,   173,
      -1,   175,    -1,    -1,    -1,    -1,    -1,   230,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   239,   240,    -1,   242,
      -1,   244,   245,   246,   247,   248,   249,    -1,   896,   252,
      -1,    -1,   900,    -1,    -1,   258,   259,    -1,   906,    -1,
      -1,    -1,   910,    -1,    -1,   219,   220,    -1,    -1,    -1,
      -1,   274,    -1,   227,   277,    -1,    -1,   231,    -1,    -1,
     928,    -1,    -1,   931,   238,    -1,    -1,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,   251,    -1,    -1,
      -1,    -1,    -1,   257,    -1,    -1,   260,    -1,    -1,    -1,
     264,    -1,   315,   267,   268,    -1,   270,   965,   966,   273,
      -1,   275,    -1,    -1,    -1,   279,   280,    -1,    -1,   283,
      -1,    -1,   286,   287,   288,   289,    -1,   291,    -1,   293,
      -1,    -1,    -1,    -1,   298,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1005,    -1,  1007,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,   323,
      -1,    -1,    -1,    -1,   328,   329,     5,     6,     7,    -1,
      -1,   134,    -1,  1031,    -1,    -1,    -1,    -1,    -1,    -1,
    1038,    20,    -1,   347,    -1,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,   134,
      -1,    -1,    -1,    -1,    64,    65,    66,    67,    -1,    -1,
      -1,    -1,    -1,    52,    53,    54,    -1,    77,    78,    79,
      80,    -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,    -1,
      -1,    -1,    -1,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,    -1,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,    -1,    -1,    -1,
      -1,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,    -1,    -1,    -1,    -1,    -1,    -1,
    1148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1168,   171,    -1,   173,  1172,    -1,    -1,    -1,    -1,  1177,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1201,  1202,  1203,  1204,    -1,    -1,    -1,
      -1,    -1,    -1,  1211,    -1,    -1,    -1,    -1,    -1,  1217,
    1218,   134,  1220,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,
     240,   344,   242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,   258,   259,
     134,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   344,
    1268,    -1,    -1,    -1,   274,    -1,    -1,   277,    -1,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   134,
      -1,    -1,    -1,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,    -1,   286,   287,   288,
     289,    -1,    -1,    -1,    -1,   315,    -1,    -1,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,    -1,    -1,
      -1,    -1,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,    -1,    -1,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,    -1,    -1,    -1,
      -1,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1381,    -1,    -1,  1384,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1392,    -1,    -1,    -1,    -1,    -1,
      -1,  1399,    -1,    -1,  1402,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1411,  1412,  1413,  1414,    -1,    -1,    -1,
      -1,    -1,    -1,  1421,     5,     6,     7,     8,     9,    10,
     304,   344,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    23,    -1,    -1,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,   304,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    -1,    -1,    -1,    67,    68,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    -1,    83,    -1,    -1,    86,    -1,    -1,    -1,    -1,
      -1,    92,    -1,    -1,    -1,    -1,    97,    98,    99,    -1,
      -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,  1526,    -1,
      -1,    -1,   113,    -1,    -1,   116,    -1,   118,   119,   120,
      -1,    -1,    -1,    -1,   125,   126,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   142,   143,    -1,    -1,   146,    -1,   148,   149,   150,
     151,   152,   153,   154,    -1,   156,    -1,   158,   159,   160,
     161,  1579,   163,    -1,   165,    -1,    -1,    -1,    -1,    -1,
      -1,   172,   173,    -1,   175,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1611,    -1,    -1,  1614,    -1,  1616,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1634,    -1,   219,   220,
    1638,    -1,    -1,    -1,    -1,    -1,   227,    -1,    -1,  1647,
     231,    -1,    -1,    -1,    -1,  1653,    -1,   238,    -1,    -1,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
     251,    -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,   260,
      -1,    -1,    -1,   264,    -1,    -1,   267,   268,    -1,   270,
      -1,    -1,   273,    -1,   275,    -1,    -1,    -1,   279,   280,
      -1,    -1,    -1,    -1,    -1,   286,   287,   288,   289,   134,
     291,    -1,   293,    -1,    -1,    -1,    -1,   298,    -1,  1717,
    1718,  1719,    -1,  1721,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1735,    -1,    -1,
      -1,   322,   323,    -1,    -1,    -1,    -1,   328,   329,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1754,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   347,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,    -1,    -1,    -1,
      -1,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1813,    -1,    -1,    -1,    -1,
       3,  1819,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    -1,    18,    19,    -1,    -1,    22,
      23,    -1,    -1,    26,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    41,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    -1,    52,
      -1,    -1,    55,    56,    57,    -1,    -1,    -1,   303,    62,
      63,    -1,    -1,    66,    67,    -1,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,
      83,    -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,    92,
      -1,    -1,    -1,    -1,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,   105,   106,    -1,  1923,    -1,   110,  1926,    -1,
     113,   114,    -1,   116,    -1,   118,   119,   120,    -1,    -1,
      -1,   124,   125,   126,    -1,    -1,  1944,    -1,    -1,    -1,
      -1,   134,   135,   136,   137,   138,    -1,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,   156,   157,   158,   159,   160,   161,    -1,
     163,   164,   165,    -1,  1982,    -1,    -1,    -1,   171,   172,
     173,    -1,   175,   176,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,
     193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,
     203,   204,    -1,    -1,    -1,    -1,   209,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   219,   220,    -1,    -1,
      -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,   231,    -1,
      -1,    -1,    -1,    -1,    -1,   238,    -1,    -1,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,   251,    -1,
      -1,    -1,    -1,    -1,   257,    -1,    -1,   260,    -1,    -1,
      -1,   264,    -1,    -1,   267,   268,    -1,   270,    -1,    -1,
     273,    -1,   275,    -1,    -1,    -1,   279,   280,    -1,    -1,
     283,    -1,    -1,   286,   287,   288,   289,    -1,   291,    -1,
     293,    -1,    -1,    -1,    -1,   298,    -1,    -1,    -1,   302,
      -1,    -1,    -1,   306,   307,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,
     323,    -1,    -1,    -1,    -1,   328,   329,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   347,     3,   349,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    -1,
      18,    19,    -1,    -1,    22,    23,    -1,    -1,    26,    27,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    41,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    -1,    52,    -1,    -1,    55,    56,    57,
      -1,    -1,    -1,    -1,    62,    63,    -1,    -1,    -1,    67,
      -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    -1,    83,    -1,    -1,    86,    -1,
      -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,    97,
      98,    99,    -1,    -1,    -1,    -1,    -1,   105,   106,    -1,
      -1,    -1,   110,    -1,    -1,   113,   114,    -1,   116,    -1,
     118,   119,   120,    -1,    -1,    -1,   124,   125,   126,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   134,   135,   136,   137,
     138,    -1,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,    -1,   156,   157,
     158,   159,   160,   161,    -1,   163,   164,   165,    -1,    -1,
      -1,    -1,    -1,    -1,   172,   173,    -1,   175,   176,    -1,
     178,   179,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   189,    -1,    -1,   192,   193,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   202,   203,   204,    -1,    -1,    -1,
      -1,   209,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   219,   220,    -1,    -1,    -1,    -1,    -1,    -1,   227,
      -1,    -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,
     238,    -1,    -1,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,    -1,    -1,    -1,    -1,    -1,   257,
      -1,    -1,   260,    -1,    -1,    -1,   264,    -1,    -1,   267,
     268,    -1,   270,    -1,    -1,   273,    -1,   275,    -1,    -1,
      -1,   279,   280,    -1,    -1,    -1,    -1,    -1,   286,   287,
     288,   289,    -1,   291,    -1,   293,    -1,    -1,    -1,    -1,
     298,    -1,    -1,    -1,   302,    -1,    -1,    -1,   306,   307,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   322,   323,    -1,    -1,    -1,    -1,
     328,   329,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   347,
       3,   349,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    -1,    18,    19,    -1,    -1,    22,
      23,    -1,    -1,    26,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    41,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    -1,    52,
      -1,    -1,    55,    56,    57,    -1,    -1,    -1,    -1,    62,
      63,    -1,    -1,    66,    67,    -1,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,
      83,    -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,    92,
      -1,    -1,    -1,    -1,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,   105,   106,    -1,    -1,    -1,   110,    -1,    -1,
     113,   114,    -1,   116,    -1,   118,   119,   120,    -1,    -1,
      -1,   124,   125,   126,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   134,   135,   136,   137,   138,    -1,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,   156,   157,   158,   159,   160,   161,    -1,
     163,   164,   165,    -1,    -1,    -1,    -1,    -1,   171,   172,
     173,    -1,   175,   176,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,
     193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,
     203,   204,    -1,    -1,    -1,    -1,   209,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   219,   220,    -1,    -1,
      -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,   231,    -1,
      -1,    -1,    -1,    -1,    -1,   238,    -1,    -1,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,   251,    -1,
      -1,    -1,    -1,    -1,   257,    -1,    -1,   260,    -1,    -1,
      -1,   264,    -1,    -1,   267,   268,    -1,   270,    -1,    -1,
     273,    -1,   275,    -1,    -1,    -1,   279,   280,    -1,    -1,
      -1,    -1,    -1,   286,   287,   288,   289,    -1,   291,    -1,
     293,    -1,    -1,    -1,    -1,   298,    -1,    -1,    -1,   302,
      -1,    -1,    -1,   306,   307,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,
     323,    -1,    -1,    -1,    -1,   328,   329,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   347,     3,   349,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    -1,
      18,    19,    -1,    -1,    22,    23,    -1,    -1,    26,    27,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    41,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    -1,    52,    -1,    -1,    55,    56,    57,
      -1,    -1,    -1,    -1,    62,    63,    -1,    -1,    -1,    67,
      -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    -1,    83,    -1,    -1,    86,    -1,
      -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,    97,
      98,    99,    -1,    -1,    -1,    -1,    -1,   105,   106,    -1,
      -1,    -1,   110,    -1,    -1,   113,   114,    -1,   116,    -1,
     118,   119,   120,    -1,    -1,    -1,   124,   125,   126,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   134,   135,   136,   137,
     138,    -1,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,    -1,   156,   157,
     158,   159,   160,   161,    -1,   163,   164,   165,    -1,    -1,
      -1,    -1,    -1,    -1,   172,   173,    -1,   175,   176,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   192,   193,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   202,   203,   204,    -1,   206,    -1,
      -1,   209,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   219,   220,    -1,    -1,    -1,    -1,    -1,    -1,   227,
      -1,    -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,
     238,    -1,    -1,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,    -1,    -1,    -1,    -1,    -1,   257,
      -1,    -1,   260,    -1,    -1,    -1,   264,    -1,    -1,   267,
     268,    -1,   270,    -1,    -1,   273,    -1,   275,    -1,    -1,
      -1,   279,   280,    -1,    -1,    -1,    -1,    -1,   286,   287,
     288,   289,    -1,   291,    -1,   293,    -1,    -1,    -1,    -1,
     298,    -1,    -1,    -1,   302,    -1,    -1,    -1,   306,   307,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   322,   323,    -1,    -1,    -1,    -1,
     328,   329,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   347,
       3,   349,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    -1,    18,    19,    -1,    -1,    22,
      23,    -1,    -1,    26,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    41,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    -1,    52,
      -1,    -1,    55,    56,    57,    -1,    -1,    -1,    -1,    62,
      63,    -1,    -1,    -1,    67,    -1,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,
      83,    -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,    92,
      -1,    -1,    -1,    -1,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,   105,   106,    -1,    -1,    -1,   110,    -1,    -1,
     113,   114,    -1,   116,    -1,   118,   119,   120,    -1,    -1,
      -1,   124,   125,   126,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   134,   135,   136,   137,   138,    -1,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,   156,   157,   158,   159,   160,   161,    -1,
     163,   164,   165,    -1,    -1,    -1,    -1,    -1,    -1,   172,
     173,    -1,   175,   176,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,
     193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,
     203,   204,    -1,    -1,    -1,    -1,   209,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   219,   220,    -1,    -1,
      -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,   231,    -1,
      -1,    -1,    -1,    -1,    -1,   238,    -1,    -1,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,    -1,
      -1,    -1,    -1,    -1,   257,    -1,    -1,   260,    -1,    -1,
      -1,   264,    -1,    -1,   267,   268,    -1,   270,    -1,    -1,
     273,    -1,   275,    -1,    -1,    -1,   279,   280,    -1,    -1,
      -1,    -1,    -1,   286,   287,   288,   289,    -1,   291,    -1,
     293,    -1,    -1,    -1,    -1,   298,    -1,    -1,    -1,   302,
      -1,    -1,    -1,   306,   307,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,
     323,    -1,    -1,    -1,    -1,   328,   329,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   347,     3,   349,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    -1,
      18,    19,    -1,    -1,    22,    23,    -1,    -1,    26,    27,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    41,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    -1,    52,    -1,    -1,    55,    56,    57,
      -1,    -1,    -1,    -1,    62,    63,    -1,    -1,    -1,    67,
      -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    -1,    83,    -1,    -1,    86,    -1,
      -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,    97,
      98,    99,    -1,    -1,    -1,    -1,    -1,   105,   106,    -1,
      -1,    -1,   110,    -1,    -1,   113,   114,    -1,   116,    -1,
     118,   119,   120,    -1,    -1,    -1,   124,   125,   126,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   134,   135,   136,   137,
     138,    -1,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,    -1,   156,   157,
     158,   159,   160,   161,    -1,   163,   164,   165,    -1,    -1,
      -1,    -1,    -1,    -1,   172,   173,    -1,   175,   176,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   192,   193,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   202,   203,   204,    -1,    -1,    -1,
      -1,   209,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   219,   220,    -1,    -1,    -1,    -1,    -1,    -1,   227,
      -1,    -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,
     238,    -1,    -1,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,    -1,    -1,    -1,    -1,    -1,   257,
      -1,    -1,   260,    -1,    -1,    -1,   264,    -1,    -1,   267,
     268,    -1,   270,    -1,    -1,   273,    -1,   275,    -1,    -1,
      -1,   279,   280,    -1,    -1,    -1,    -1,    -1,   286,   287,
     288,   289,    -1,   291,    -1,   293,    -1,    -1,    -1,    -1,
     298,    -1,    -1,    -1,   302,    -1,    -1,    -1,   306,   307,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   322,   323,    -1,    -1,    -1,    -1,
     328,   329,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   347,
       3,   349,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    -1,    18,    19,    -1,    -1,    22,
      23,    -1,    -1,    26,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    41,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    -1,    52,
      -1,    -1,    55,    56,    57,    -1,    -1,    -1,    -1,    62,
      63,    -1,    -1,    -1,    67,    -1,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,
      83,    -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,    92,
      -1,    -1,    -1,    -1,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,   105,    -1,    -1,    -1,    -1,   110,    -1,    -1,
     113,   114,    -1,   116,    -1,   118,   119,   120,    -1,    -1,
      -1,   124,   125,   126,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   134,   135,   136,   137,   138,    -1,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,   156,   157,   158,   159,   160,   161,    -1,
     163,   164,   165,    -1,    -1,    -1,    -1,    -1,    -1,   172,
     173,    -1,   175,    -1,    -1,    -1,    -1,    -1,   181,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,
     193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,
     203,   204,    -1,    -1,    -1,    -1,   209,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   219,   220,    -1,    -1,
      -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,   231,    -1,
      -1,    -1,    -1,    -1,    -1,   238,    -1,    -1,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,   251,    -1,
      -1,    -1,    -1,    -1,   257,    -1,    -1,   260,    -1,    -1,
      -1,   264,    -1,    -1,   267,   268,    -1,   270,    -1,    -1,
     273,    -1,   275,    -1,    -1,    -1,   279,   280,    -1,    -1,
      -1,    -1,    -1,   286,   287,   288,   289,    -1,   291,    -1,
     293,    -1,    -1,    -1,    -1,   298,    -1,    -1,    -1,   302,
      -1,    -1,    -1,   306,   307,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,
     323,    -1,    -1,    -1,    -1,   328,   329,    -1,    -1,    -1,
      -1,    -1,    -1,   336,    -1,    -1,    -1,    -1,    -1,    -1,
     343,    -1,    -1,    -1,    -1,     3,   349,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    -1,
      18,    19,    -1,    -1,    22,    23,    -1,    -1,    26,    27,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    41,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    -1,    52,    -1,    -1,    55,    56,    57,
      -1,    -1,    -1,    -1,    62,    63,    -1,    -1,    66,    67,
      -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    -1,    83,    -1,    -1,    86,    -1,
      -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,    97,
      98,    99,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,
      -1,    -1,   110,    -1,    -1,   113,   114,    -1,   116,    -1,
     118,   119,   120,    -1,    -1,    -1,   124,   125,   126,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   134,   135,   136,   137,
     138,    -1,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,    -1,   156,   157,
     158,   159,   160,   161,    -1,   163,   164,   165,    -1,    -1,
      -1,    -1,    -1,    -1,   172,   173,   174,   175,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   192,   193,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   202,   203,   204,    -1,    -1,    -1,
      -1,   209,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   219,   220,    -1,    -1,    -1,    -1,    -1,    -1,   227,
      -1,    -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,
     238,    -1,    -1,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,    -1,    -1,    -1,    -1,    -1,   257,
      -1,    -1,   260,    -1,    -1,    -1,   264,    -1,    -1,   267,
     268,    -1,   270,    -1,    -1,   273,    -1,   275,    -1,    -1,
      -1,   279,   280,    -1,    -1,    -1,    -1,    -1,   286,   287,
     288,   289,    -1,   291,    -1,   293,    -1,    -1,    -1,    -1,
     298,    -1,    -1,    -1,   302,    -1,    -1,    -1,   306,   307,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   322,   323,    -1,    -1,    -1,    -1,
     328,   329,    -1,     3,    -1,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    -1,    -1,    18,    19,
      -1,   349,    22,    23,    -1,    -1,    26,    27,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    41,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    -1,    52,    -1,    -1,    55,    56,    57,    -1,    -1,
      -1,    -1,    62,    63,    -1,    -1,    -1,    67,    -1,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    -1,    83,    -1,    -1,    86,    -1,    -1,    -1,
      -1,    -1,    92,    -1,    -1,    -1,    -1,    97,    98,    99,
      -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,
     110,    -1,    -1,   113,   114,    -1,   116,    -1,   118,   119,
     120,    -1,    -1,    -1,   124,   125,   126,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,    -1,   156,   157,   158,   159,
     160,   161,    -1,   163,   164,   165,    -1,    -1,    -1,    -1,
      -1,    -1,   172,   173,    -1,   175,    -1,    -1,   178,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   192,   193,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   202,   203,   204,    -1,   206,    -1,    -1,   209,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,
     220,    -1,    -1,    -1,    -1,    -1,    -1,   227,    -1,    -1,
      -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,   238,    -1,
      -1,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,   251,    -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,
     260,    -1,    -1,    -1,   264,    -1,    -1,   267,   268,    -1,
     270,    -1,    -1,   273,    -1,   275,    -1,    -1,    -1,   279,
     280,    -1,    -1,    -1,    -1,    -1,   286,   287,   288,   289,
      -1,   291,    -1,   293,    -1,    -1,    -1,    -1,   298,    -1,
      -1,    -1,   302,    -1,    -1,    -1,   306,   307,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   322,   323,    -1,    -1,    -1,    -1,   328,   329,
      -1,     3,    -1,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    -1,    18,    19,    -1,   349,
      22,    23,    -1,    -1,    26,    27,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    41,
      -1,    -1,    44,    45,    46,    47,    48,    49,    50,    -1,
      52,    -1,    -1,    55,    56,    57,    -1,    -1,    -1,    -1,
      62,    63,    -1,    -1,    -1,    67,    -1,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      -1,    83,    -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,
      92,    -1,    -1,    -1,    -1,    97,    98,    99,    -1,    -1,
      -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,   110,    -1,
      -1,   113,   114,    -1,   116,    -1,   118,   119,   120,    -1,
      -1,    -1,   124,   125,   126,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      -1,   163,   164,   165,    -1,    -1,    -1,    -1,    -1,    -1,
     172,   173,    -1,   175,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     192,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     202,   203,   204,    -1,    -1,    -1,    -1,   209,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,   220,    -1,
      -1,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,   231,
      -1,    -1,    -1,    -1,    -1,    -1,   238,    -1,    -1,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,   251,
      -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,   260,    -1,
      -1,    -1,   264,    -1,    -1,   267,   268,    -1,   270,    -1,
      -1,   273,    -1,   275,    -1,    -1,    -1,   279,   280,    -1,
      -1,    -1,    -1,    -1,   286,   287,   288,   289,    -1,   291,
      -1,   293,    -1,    -1,    -1,    -1,   298,    -1,    -1,    -1,
     302,    -1,    -1,    -1,   306,   307,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     322,   323,    -1,    -1,    -1,    -1,   328,   329,    -1,     3,
      -1,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    -1,    -1,    18,    19,    -1,   349,    22,    23,
      -1,    -1,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    41,    -1,    -1,
      44,    45,    46,    47,    48,    49,    50,    -1,    52,    -1,
      -1,    55,    56,    57,    -1,    -1,    -1,    -1,    62,    63,
      -1,    -1,    -1,    67,    -1,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    83,
      -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      -1,    -1,    -1,    97,    98,    99,    -1,    -1,    -1,    -1,
      -1,   105,    -1,    -1,    -1,    -1,   110,    -1,    -1,   113,
     114,    -1,   116,    -1,   118,   119,   120,    -1,    -1,    -1,
     124,   125,   126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     134,   135,   136,   137,   138,    -1,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,    -1,   156,   157,   158,   159,   160,   161,    -1,   163,
     164,   165,    -1,    -1,    -1,    -1,    -1,    -1,   172,   173,
      -1,   175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,   193,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,   203,
     204,    -1,    -1,    -1,    -1,   209,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   219,   220,    -1,    -1,    -1,
      -1,    -1,    -1,   227,    -1,    -1,    -1,   231,    -1,    -1,
      -1,    -1,    -1,    -1,   238,    -1,    -1,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,   251,    -1,    -1,
      -1,    -1,    -1,   257,    -1,    -1,   260,    -1,    -1,    -1,
     264,    -1,    -1,   267,   268,    -1,   270,    -1,    -1,   273,
      -1,   275,    -1,    -1,    -1,   279,   280,    -1,    -1,    -1,
      -1,    -1,   286,   287,   288,   289,    -1,   291,    -1,   293,
      -1,    -1,    -1,    -1,   298,    -1,    -1,    -1,   302,    -1,
      -1,    -1,   306,   307,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,   323,
      -1,    -1,    -1,    -1,   328,   329,    -1,    -1,    -1,    -1,
      -1,    -1,   336,    -1,    -1,    -1,    -1,    -1,    -1,   343,
      -1,    -1,    -1,    -1,     3,   349,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    -1,    18,
      19,    -1,    -1,    22,    23,    -1,    -1,    26,    27,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    41,    -1,    -1,    44,    45,    46,    47,    48,
      49,    50,    -1,    52,    -1,    -1,    55,    56,    57,    -1,
      -1,    -1,    -1,    62,    63,    -1,    -1,    -1,    67,    -1,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    -1,    83,    -1,    -1,    86,    -1,    -1,
      -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,    97,    98,
      99,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,
      -1,   110,    -1,    -1,   113,   114,    -1,   116,    -1,   118,
     119,   120,    -1,    -1,    -1,   124,   125,   126,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   134,   135,   136,   137,   138,
      -1,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    -1,   156,   157,   158,
     159,   160,   161,    -1,   163,   164,   165,    -1,    -1,    -1,
      -1,    -1,    -1,   172,   173,    -1,   175,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   192,   193,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   202,   203,   204,    -1,    -1,    -1,    -1,
     209,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     219,   220,    -1,    -1,    -1,    -1,    -1,    -1,   227,    -1,
      -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,   238,
      -1,    -1,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,   251,    -1,    -1,    -1,    -1,    -1,   257,    -1,
      -1,   260,    -1,    -1,    -1,   264,    -1,    -1,   267,   268,
      -1,   270,    -1,    -1,   273,    -1,   275,    -1,    -1,    -1,
     279,   280,    -1,    -1,    -1,    -1,    -1,   286,   287,   288,
     289,    -1,   291,    -1,   293,    -1,    -1,    -1,    -1,   298,
      -1,    -1,    -1,   302,    -1,    -1,    -1,   306,   307,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   322,   323,    -1,    -1,    -1,    -1,   328,
     329,    -1,    -1,    -1,    -1,    -1,    -1,   336,    -1,    -1,
      -1,    -1,    -1,    -1,   343,    -1,    -1,    -1,    -1,     3,
     349,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    -1,    -1,    18,    19,    -1,    -1,    22,    23,
      -1,    -1,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    41,    -1,    -1,
      44,    45,    46,    47,    48,    49,    50,    -1,    52,    -1,
      -1,    55,    56,    57,    -1,    -1,    -1,    -1,    62,    63,
      -1,    -1,    -1,    67,    -1,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    83,
      -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      -1,    -1,    -1,    97,    98,    99,    -1,    -1,    -1,    -1,
      -1,   105,    -1,    -1,    -1,    -1,   110,    -1,    -1,   113,
     114,    -1,   116,    -1,   118,   119,   120,    -1,    -1,    -1,
     124,   125,   126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     134,   135,   136,   137,   138,    -1,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,    -1,   156,   157,   158,   159,   160,   161,    -1,   163,
     164,   165,    -1,    -1,    -1,    -1,    -1,    -1,   172,   173,
      -1,   175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,   193,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,   203,
     204,    -1,    -1,    -1,    -1,   209,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   219,   220,    -1,    -1,    -1,
      -1,    -1,    -1,   227,    -1,    -1,    -1,   231,    -1,    -1,
      -1,    -1,    -1,    -1,   238,    -1,    -1,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,   251,    -1,    -1,
      -1,    -1,    -1,   257,    -1,    -1,   260,    -1,    -1,    -1,
     264,    -1,    -1,   267,   268,    -1,   270,    -1,    -1,   273,
      -1,   275,    -1,    -1,    -1,   279,   280,    -1,    -1,    -1,
      -1,    -1,   286,   287,   288,   289,    -1,   291,    -1,   293,
      -1,    -1,    -1,    -1,   298,    -1,    -1,    -1,   302,   303,
      -1,    -1,   306,   307,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,   323,
      -1,    -1,    -1,    -1,   328,   329,    -1,     3,    -1,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    -1,    18,    19,    -1,   349,    22,    23,    -1,    -1,
      26,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    41,    -1,    -1,    44,    45,
      46,    47,    48,    49,    50,    -1,    52,    -1,    -1,    55,
      56,    57,    -1,    -1,    -1,    -1,    62,    63,    -1,    -1,
      -1,    67,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    -1,    83,    -1,    -1,
      86,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,
      -1,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    -1,    -1,    -1,   110,    -1,    -1,   113,   114,    -1,
     116,    -1,   118,   119,   120,    -1,    -1,    -1,   124,   125,
     126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   134,   135,
     136,   137,   138,    -1,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,   158,   159,   160,   161,    -1,   163,   164,   165,
      -1,    -1,    -1,    -1,    -1,    -1,   172,   173,   174,   175,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   192,   193,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   202,   203,   204,    -1,
      -1,    -1,    -1,   209,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   219,   220,    -1,    -1,    -1,    -1,    -1,
      -1,   227,    -1,    -1,    -1,   231,    -1,    -1,    -1,    -1,
      -1,    -1,   238,    -1,    -1,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,   251,    -1,    -1,    -1,    -1,
      -1,   257,    -1,    -1,   260,    -1,    -1,    -1,   264,    -1,
      -1,   267,   268,    -1,   270,    -1,    -1,   273,    -1,   275,
      -1,    -1,    -1,   279,   280,    -1,    -1,    -1,    -1,    -1,
     286,   287,   288,   289,    -1,   291,    -1,   293,    -1,    -1,
      -1,    -1,   298,    -1,    -1,    -1,   302,    -1,    -1,    -1,
     306,   307,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   322,   323,    -1,    -1,
      -1,    -1,   328,   329,    -1,     3,    -1,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    -1,
      18,    19,    -1,   349,    22,    23,    -1,    -1,    26,    27,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    41,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    -1,    52,    -1,    -1,    55,    56,    57,
      -1,    -1,    -1,    -1,    62,    63,    -1,    -1,    -1,    67,
      -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    -1,    83,    -1,    -1,    86,    -1,
      -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,    97,
      98,    99,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,
      -1,    -1,   110,    -1,    -1,   113,   114,    -1,   116,    -1,
     118,   119,   120,    -1,    -1,    -1,   124,   125,   126,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   134,   135,   136,   137,
     138,    -1,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,    -1,   156,   157,
     158,   159,   160,   161,    -1,   163,   164,   165,    -1,    -1,
      -1,    -1,    -1,    -1,   172,   173,    -1,   175,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   192,   193,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   202,   203,   204,    -1,    -1,    -1,
      -1,   209,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   219,   220,    -1,    -1,    -1,    -1,    -1,    -1,   227,
      -1,    -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,
     238,    -1,    -1,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,    -1,    -1,    -1,    -1,    -1,   257,
      -1,    -1,   260,    -1,    -1,    -1,   264,    -1,    -1,   267,
     268,    -1,   270,    -1,    -1,   273,    -1,   275,    -1,    -1,
      -1,   279,   280,    -1,    -1,    -1,    -1,    -1,   286,   287,
     288,   289,    -1,   291,    -1,   293,    -1,    -1,    -1,    -1,
     298,    -1,    -1,    -1,   302,    -1,    -1,    -1,   306,   307,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   322,   323,    -1,    -1,    -1,    -1,
     328,   329,    -1,     3,    -1,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    -1,    -1,    18,    19,
      -1,   349,    22,    23,    -1,    -1,    26,    27,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    41,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    -1,    52,    -1,    -1,    55,    56,    57,    -1,    -1,
      -1,    -1,    62,    63,    -1,    -1,    66,    67,    -1,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    -1,    83,    -1,    -1,    86,    -1,    -1,    -1,
      -1,    -1,    92,    -1,    -1,    -1,    -1,    97,    98,    99,
      -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,
     110,    -1,    -1,   113,   114,    -1,   116,    -1,   118,   119,
     120,    -1,    -1,    -1,   124,   125,   126,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,    -1,   156,   157,   158,   159,
     160,   161,    -1,   163,   164,   165,    -1,    -1,    -1,    -1,
      -1,    -1,   172,   173,    -1,   175,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   192,   193,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   202,   203,   204,    -1,    -1,    -1,    -1,   209,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,
     220,    -1,    -1,    -1,    -1,    -1,    -1,   227,    -1,    -1,
      -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,   238,    -1,
      -1,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,   251,    -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,
     260,    -1,    -1,    -1,   264,    -1,    -1,   267,   268,    -1,
     270,    -1,    -1,   273,    -1,   275,    -1,    -1,    -1,   279,
     280,    -1,    -1,    -1,    -1,    -1,   286,   287,   288,   289,
      -1,   291,    -1,   293,    -1,    -1,    -1,    -1,   298,    -1,
      -1,    -1,   302,    -1,    -1,    -1,   306,   307,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   322,   323,    -1,    -1,    -1,    -1,   328,   329,
      -1,     3,    -1,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    -1,    18,    19,    -1,   349,
      22,    23,    -1,    -1,    26,    27,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    41,
      -1,    -1,    44,    45,    46,    47,    48,    49,    50,    -1,
      52,    -1,    -1,    55,    56,    57,    -1,    -1,    -1,    -1,
      62,    63,    -1,    -1,    -1,    67,    -1,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      -1,    83,    -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,
      92,    -1,    -1,    -1,    -1,    97,    98,    99,    -1,    -1,
      -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,   110,    -1,
      -1,   113,   114,    -1,   116,    -1,   118,   119,   120,    -1,
      -1,    -1,   124,   125,   126,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   134,   135,   136,   137,   138,    -1,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,   158,   159,   160,   161,
      -1,   163,   164,   165,    -1,    -1,    -1,    -1,    -1,    -1,
     172,   173,    -1,   175,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     192,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     202,   203,   204,    -1,    -1,    -1,    -1,   209,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,   220,    -1,
      -1,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,   231,
      -1,    -1,    -1,    -1,    -1,    -1,   238,    -1,    -1,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
      -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,   260,    -1,
      -1,    -1,   264,    -1,    -1,   267,   268,    -1,   270,    -1,
      -1,   273,    -1,   275,    -1,    -1,    -1,   279,   280,    -1,
      -1,    -1,    -1,    -1,   286,   287,   288,   289,    -1,   291,
      -1,   293,    -1,    -1,    -1,    -1,   298,    -1,    -1,    -1,
     302,    -1,    -1,    -1,   306,   307,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     322,   323,    -1,    -1,    -1,    -1,   328,   329,    -1,     3,
      -1,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    -1,    -1,    18,    19,    -1,   349,    22,    23,
      -1,    -1,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    41,    -1,    -1,
      44,    45,    46,    47,    48,    49,    50,    -1,    52,    -1,
      -1,    55,    56,    57,    -1,    -1,    -1,    -1,    62,    63,
      -1,    -1,    -1,    67,    -1,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    83,
      -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      -1,    -1,    -1,    97,    98,    99,    -1,    -1,    -1,    -1,
      -1,   105,    -1,    -1,    -1,    -1,   110,    -1,    -1,   113,
     114,    -1,   116,    -1,   118,   119,   120,    -1,    -1,    -1,
     124,   125,   126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     134,   135,   136,   137,   138,    -1,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,    -1,   156,   157,   158,   159,   160,   161,    -1,   163,
     164,   165,    -1,    -1,    -1,    -1,    -1,    -1,   172,   173,
      -1,   175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,   193,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,   203,
     204,    -1,    -1,    -1,    -1,   209,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   219,   220,    -1,    -1,    -1,
      -1,    -1,    -1,   227,    -1,    -1,    -1,   231,    -1,    -1,
      -1,    -1,    -1,    -1,   238,    -1,    -1,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,   251,    -1,    -1,
      -1,    -1,    -1,   257,    -1,    -1,   260,    -1,    -1,    -1,
     264,    -1,    -1,   267,   268,    -1,   270,    -1,    -1,   273,
      -1,   275,    -1,    -1,    -1,   279,   280,    -1,    -1,    -1,
      -1,    -1,   286,   287,   288,   289,    -1,   291,    -1,   293,
      -1,    -1,    -1,    -1,   298,    -1,    -1,    -1,   302,   303,
      -1,    -1,   306,   307,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,   323,
      -1,    -1,    -1,    -1,   328,   329,    -1,     3,    -1,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    -1,    18,    19,    -1,   349,    22,    23,    -1,    -1,
      26,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    41,    -1,    -1,    44,    45,
      46,    47,    48,    49,    50,    -1,    52,    -1,    -1,    55,
      56,    57,    -1,    -1,    -1,    -1,    62,    63,    -1,    -1,
      -1,    67,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    -1,    83,    -1,    -1,
      86,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,
      -1,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    -1,    -1,    -1,   110,    -1,    -1,   113,   114,    -1,
     116,    -1,   118,   119,   120,    -1,    -1,    -1,   124,   125,
     126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,   158,   159,   160,   161,    -1,   163,   164,   165,
      -1,    -1,    -1,    -1,    -1,    -1,   172,   173,    -1,   175,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   192,   193,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   202,   203,   204,    -1,
      -1,    -1,    -1,   209,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   219,   220,    -1,    -1,    -1,    -1,    -1,
      -1,   227,    -1,    -1,    -1,   231,    -1,    -1,    -1,    -1,
      -1,    -1,   238,    -1,    -1,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,   251,    -1,    -1,    -1,    -1,
      -1,   257,    -1,    -1,   260,    -1,    -1,    -1,   264,    -1,
      -1,   267,   268,    -1,   270,    -1,    -1,   273,    -1,   275,
      -1,    -1,    -1,   279,   280,    -1,    -1,    -1,    -1,    -1,
     286,   287,   288,   289,    -1,   291,    -1,   293,    -1,    -1,
      -1,    -1,   298,    -1,    -1,    -1,   302,    -1,    -1,    -1,
     306,   307,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   322,   323,    -1,    -1,
      -1,    -1,   328,   329,    -1,     3,    -1,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    -1,
      18,    19,    -1,   349,    22,    23,    -1,    -1,    26,    27,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    41,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    -1,    52,    -1,    -1,    55,    56,    57,
      -1,    -1,    -1,    -1,    62,    63,    -1,    -1,    -1,    67,
      -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    -1,    83,    -1,    -1,    86,    -1,
      -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,    97,
      98,    99,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,
      -1,    -1,   110,    -1,    -1,   113,   114,    -1,   116,    -1,
     118,   119,   120,    -1,    -1,    -1,   124,   125,   126,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   134,   135,   136,   137,
     138,    -1,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,    -1,   156,   157,
     158,   159,   160,   161,    -1,   163,   164,   165,    -1,    -1,
      -1,    -1,    -1,    -1,   172,   173,    -1,   175,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   192,   193,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   202,   203,   204,    -1,    -1,    -1,
      -1,   209,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   219,   220,    -1,    -1,    -1,    -1,    -1,    -1,   227,
      -1,    -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,
     238,    -1,    -1,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,    -1,    -1,    -1,    -1,    -1,   257,
      -1,    -1,   260,    -1,    -1,    -1,   264,    -1,    -1,   267,
     268,    -1,   270,    -1,    -1,   273,    -1,   275,    -1,    -1,
      -1,   279,   280,    -1,    -1,    -1,    -1,    -1,   286,   287,
     288,   289,    -1,   291,    -1,   293,    -1,    -1,    -1,    -1,
     298,    -1,    -1,    -1,   302,    -1,    -1,    -1,   306,   307,
      -1,     5,     6,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   322,   323,    -1,    -1,    22,    23,
     328,   329,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    41,    -1,    -1,
      -1,   349,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    78,    79,    80,    -1,    -1,    83,
      -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      -1,    -1,    -1,    97,    98,    99,    -1,    -1,    -1,    -1,
      -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
      -1,    -1,   116,    -1,   118,   119,   120,   134,    -1,    -1,
      -1,   125,   126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,   143,
      -1,    -1,   146,    -1,   148,   149,   150,   151,   152,   153,
     154,    -1,   156,    -1,   158,   159,   160,   161,    -1,   163,
      -1,   165,    -1,    -1,    -1,    -1,    -1,    -1,   172,    -1,
      -1,   175,    -1,    -1,    -1,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,    -1,    -1,    -1,    -1,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   219,   220,    -1,    -1,    -1,
      -1,    -1,    -1,   227,    -1,    -1,   230,   231,    -1,    -1,
      -1,    -1,    -1,    -1,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,   251,   252,    -1,
      -1,    -1,    -1,   257,   258,   259,   260,    -1,    -1,    -1,
     264,    -1,    -1,   267,   268,    -1,   270,    -1,    -1,   273,
     274,   275,   276,   277,    -1,   279,   280,    -1,    -1,    -1,
      -1,    -1,   286,   287,   288,   289,   303,   291,    -1,   293,
      -1,    -1,    -1,    -1,   298,    -1,    -1,    -1,   302,    -1,
      -1,   305,    -1,    -1,   308,   309,   310,    -1,    -1,    -1,
      -1,   315,     5,     6,     7,     8,     9,    10,   322,   323,
      -1,    -1,    -1,    -1,   328,   329,    -1,    -1,    -1,    22,
      23,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    65,    66,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    78,    79,    80,    -1,    -1,
      83,    -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,    92,
      -1,    -1,    -1,    -1,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     113,    -1,    -1,   116,    -1,   118,   119,   120,   134,    -1,
      -1,    -1,   125,   126,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,
     143,    -1,    -1,   146,    -1,   148,   149,   150,   151,   152,
     153,   154,    -1,   156,    -1,   158,   159,   160,   161,    -1,
     163,    -1,   165,    -1,    -1,    -1,    -1,    -1,    -1,   172,
      -1,    -1,   175,    -1,    -1,    -1,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,    -1,    -1,    -1,    -1,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   219,   220,    -1,    -1,
      -1,    -1,    -1,    -1,   227,    -1,    -1,   230,   231,    -1,
      -1,    -1,    -1,    -1,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   263,   251,   252,
      -1,    -1,    -1,    -1,   257,   258,   259,   260,    -1,    -1,
      -1,   264,    -1,    -1,   267,   268,    -1,   270,    -1,    -1,
     273,   274,   275,   276,   277,    -1,   279,   280,    -1,    -1,
      -1,    -1,    -1,   286,   287,   288,   289,    -1,   291,    -1,
     293,    -1,    -1,    -1,    -1,   298,    -1,    -1,    -1,   302,
      -1,    -1,    -1,    -1,    -1,   308,    -1,    -1,    -1,    -1,
     313,    -1,   315,     5,     6,     7,     8,     9,    10,   322,
     323,    -1,    -1,    -1,    -1,   328,   329,    -1,    -1,    -1,
      22,    23,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    78,    79,    80,    -1,
      -1,    83,    -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,
      92,    -1,   107,    -1,    -1,    97,    98,    99,    -1,    -1,
      -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,    -1,    -1,   116,    -1,   118,   119,   120,   134,
      -1,    -1,    -1,   125,   126,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     142,   143,    -1,    -1,   146,    -1,   148,   149,   150,   151,
     152,   153,   154,    -1,   156,    -1,   158,   159,   160,   161,
      -1,   163,    -1,   165,    -1,    -1,    -1,    -1,    -1,    -1,
     172,    -1,    -1,   175,    -1,    -1,    -1,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,    -1,    -1,    -1,
      -1,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,   220,    -1,
      -1,    -1,    -1,    -1,    -1,   227,    -1,    -1,   230,   231,
      -1,    -1,    -1,    -1,    -1,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,   251,
     252,    -1,    -1,    -1,    -1,   257,   258,   259,   260,    -1,
      -1,    -1,   264,    -1,    -1,   267,   268,    -1,   270,    -1,
      -1,   273,   274,   275,   276,   277,    -1,   279,   280,    -1,
      -1,    -1,    -1,    -1,   286,   287,   288,   289,    -1,   291,
      -1,   293,    -1,    -1,    -1,    -1,   298,    -1,    -1,    -1,
     302,    -1,    -1,    -1,    -1,    -1,   308,    -1,    -1,    -1,
      -1,   313,    -1,   315,     5,     6,     7,     8,     9,    10,
     322,   323,    -1,    -1,    -1,    -1,   328,   329,    -1,    -1,
      -1,    22,    23,    -1,    -1,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,    80,
      -1,    -1,    83,    -1,    -1,    86,    -1,    -1,    -1,    -1,
      -1,    92,    -1,    -1,    -1,    -1,    97,    98,    99,   112,
      -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   113,    -1,    -1,   116,    -1,   118,   119,   120,
      -1,   134,    -1,    -1,   125,   126,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   142,   143,    -1,    -1,   146,    -1,   148,   149,   150,
     151,   152,   153,   154,    -1,   156,    -1,   158,   159,   160,
     161,   174,   163,    -1,   165,    -1,    -1,    -1,    -1,    -1,
      -1,   172,    -1,    -1,   175,    -1,    -1,    -1,    -1,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,    -1,
      -1,    -1,    -1,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,   220,
      -1,    -1,    -1,    -1,    -1,    -1,   227,    -1,    -1,   230,
     231,    -1,    -1,    -1,    -1,    -1,    -1,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
     251,   252,    -1,    -1,    -1,    -1,   257,   258,   259,   260,
      -1,    -1,    -1,   264,    -1,    -1,   267,   268,    -1,   270,
      -1,    -1,   273,   274,   275,   276,   277,    -1,   279,   280,
      -1,    -1,    -1,    -1,    -1,   286,   287,   288,   289,    -1,
     291,    -1,   293,    -1,    -1,    -1,    -1,   298,    -1,    -1,
      -1,   302,    -1,    -1,    -1,    -1,    -1,   308,    -1,   310,
      -1,    -1,    -1,    -1,   315,     5,     6,     7,     8,     9,
      10,   322,   323,    -1,    -1,    -1,    -1,   328,   329,    -1,
      -1,    -1,    22,    23,    -1,    -1,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    65,    66,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,
      80,    -1,    -1,    83,    -1,    -1,    86,    -1,    -1,    -1,
      -1,    -1,    92,    -1,    -1,    -1,    -1,    97,    98,    99,
      -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   113,    -1,    -1,   116,    -1,   118,   119,
     120,   134,    -1,    -1,    -1,   125,   126,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   142,   143,    -1,    -1,   146,    -1,   148,   149,
     150,   151,   152,   153,   154,    -1,   156,    -1,   158,   159,
     160,   161,    -1,   163,    -1,   165,    -1,    -1,    -1,    -1,
      -1,    -1,   172,    -1,    -1,   175,    -1,    -1,    -1,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,    -1,
      -1,    -1,    -1,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,    -1,    -1,    -1,    -1,    -1,   219,
     220,    -1,    -1,    -1,    -1,    -1,    -1,   227,    -1,    -1,
     230,   231,    -1,    -1,    -1,    -1,    -1,    -1,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,   251,   252,    -1,    -1,    -1,    -1,   257,   258,   259,
     260,    -1,    -1,    -1,   264,    -1,    -1,   267,   268,    -1,
     270,    -1,    -1,   273,   274,   275,   276,   277,    -1,   279,
     280,    -1,    -1,    -1,    -1,    -1,   286,   287,   288,   289,
      -1,   291,    -1,   293,    -1,    -1,    -1,    -1,   298,    -1,
      -1,    -1,   302,    -1,    -1,    -1,    -1,    -1,   308,    -1,
      -1,    -1,    -1,    -1,   314,   315,     5,     6,     7,     8,
       9,    10,   322,   323,    -1,    -1,    -1,    -1,   328,   329,
      -1,    -1,    -1,    22,    23,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,
      79,    80,    -1,    -1,    83,    -1,    -1,    86,    -1,    -1,
      -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,    97,    98,
      99,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   113,    -1,    -1,   116,    -1,   118,
     119,   120,   134,    -1,    -1,    -1,   125,   126,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,   143,    -1,    -1,   146,    -1,   148,
     149,   150,   151,   152,   153,   154,    -1,   156,    -1,   158,
     159,   160,   161,    -1,   163,    -1,   165,    -1,    -1,    -1,
      -1,   183,    -1,   172,    -1,    -1,   175,    -1,    -1,    -1,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
      -1,    -1,    -1,    -1,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     219,   220,    -1,    -1,    -1,    -1,    -1,    -1,   227,    -1,
      -1,   230,   231,    -1,    -1,    -1,    -1,    -1,    -1,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,   251,   252,    -1,    -1,    -1,    -1,   257,   258,
     259,   260,    -1,    -1,    -1,   264,    -1,    -1,   267,   268,
      -1,   270,    -1,    -1,   273,   274,   275,   276,   277,    -1,
     279,   280,    -1,    -1,    -1,    -1,    -1,   286,   287,   288,
     289,    -1,   291,    -1,   293,    -1,    -1,    -1,    -1,   298,
      -1,    -1,    -1,   302,    -1,    -1,    -1,    -1,    -1,   308,
       5,     6,     7,     8,     9,    10,   315,    -1,    -1,    -1,
      -1,    -1,    -1,   322,   323,    -1,    -1,    22,    23,   328,
     329,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    78,    79,    80,    -1,    -1,    83,    -1,
      -1,    86,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,
      -1,    -1,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,
     105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,
      -1,   116,    -1,   118,   119,   120,    -1,   134,    -1,    -1,
     125,   126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,   143,    -1,
      -1,   146,    -1,   148,   149,   150,   151,   152,   153,   154,
      -1,   156,    -1,   158,   159,   160,   161,   174,   163,    -1,
     165,    -1,    -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,
     175,    -1,    -1,    -1,    -1,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,    -1,    -1,    -1,    -1,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   219,   220,    -1,    -1,    -1,    -1,
      -1,    -1,   227,    -1,    -1,    -1,   231,    -1,    -1,    -1,
      -1,    -1,    -1,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,   251,    -1,    -1,    -1,
      -1,    -1,   257,   258,   259,   260,    -1,    -1,    -1,   264,
      -1,    -1,   267,   268,    -1,   270,    -1,    -1,   273,   274,
     275,   276,    -1,    -1,   279,   280,    -1,    -1,    -1,    -1,
      -1,   286,   287,   288,   289,    -1,   291,    -1,   293,    -1,
      -1,    -1,    -1,   298,    -1,    -1,    -1,   302,    -1,    -1,
      -1,    -1,    -1,   308,    -1,    -1,    -1,    -1,   313,    -1,
     315,     5,     6,     7,     8,     9,    10,   322,   323,    -1,
      -1,    -1,    -1,   328,   329,    -1,    -1,    -1,    22,    23,
      -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    78,    79,    80,    -1,    -1,    83,
      -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      -1,    -1,    -1,    97,    98,    99,    -1,    -1,    -1,    -1,
      -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
      -1,    -1,   116,    -1,   118,   119,   120,    -1,   134,    -1,
      -1,   125,   126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,   143,
      -1,    -1,   146,    -1,   148,   149,   150,   151,   152,   153,
     154,    -1,   156,    -1,   158,   159,   160,   161,   174,   163,
      -1,   165,    -1,    -1,    -1,    -1,    -1,    -1,   172,    -1,
      -1,   175,    -1,    -1,    -1,    -1,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,    -1,    -1,    -1,    -1,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   219,   220,    -1,    -1,    -1,
      -1,    -1,    -1,   227,    -1,    -1,    -1,   231,    -1,    -1,
      -1,    -1,    -1,    -1,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,   251,    -1,    -1,
      -1,    -1,    -1,   257,   258,   259,   260,    -1,    -1,    -1,
     264,    -1,    -1,   267,   268,    -1,   270,    -1,    -1,   273,
     274,   275,   276,    -1,    -1,   279,   280,    -1,    -1,    -1,
      -1,    -1,   286,   287,   288,   289,    -1,   291,    -1,   293,
      -1,    -1,    -1,    -1,   298,    -1,    -1,    -1,   302,    -1,
      -1,    -1,    -1,    -1,   308,    -1,    -1,    -1,    -1,    -1,
     314,   315,    -1,    -1,    -1,    -1,    -1,    -1,   322,   323,
      -1,    -1,    -1,    -1,   328,   329,     5,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,
      -1,    -1,    -1,    22,    23,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    -1,    83,    -1,    -1,    86,    -1,    -1,
      -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,    97,    98,
      99,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   113,    -1,    -1,   116,    -1,   118,
     119,   120,    -1,   134,    -1,    -1,   125,   126,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,   143,    -1,    -1,   146,    -1,   148,
     149,   150,   151,   152,   153,   154,    -1,   156,    -1,   158,
     159,   160,   161,   174,   163,    -1,   165,    -1,    -1,    -1,
      -1,    -1,    -1,   172,    -1,    -1,   175,    -1,    -1,    -1,
      -1,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,    -1,    -1,    -1,    -1,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     219,   220,   221,   222,   223,   224,    -1,    -1,   227,    -1,
      -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,   238,
      -1,    -1,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,   251,    -1,    -1,    -1,    -1,    -1,   257,    -1,
      -1,   260,    -1,    -1,    -1,   264,    -1,    -1,   267,   268,
      -1,   270,    -1,    -1,   273,    -1,   275,    -1,    -1,    -1,
     279,   280,    -1,    -1,    -1,    -1,    -1,   286,   287,   288,
     289,    -1,   291,    -1,   293,    -1,    -1,    -1,    -1,   298,
       5,     6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    -1,
      -1,    26,    -1,   322,   323,    -1,    -1,    -1,    -1,   328,
     329,    -1,    -1,    38,    -1,    -1,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,
      55,    56,    57,    -1,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    83,    -1,
      -1,    86,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,
      -1,    -1,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,
     105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,
      -1,   116,    -1,   118,   119,   120,    -1,   134,    -1,    -1,
     125,   126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,   143,    -1,
      -1,   146,    -1,   148,   149,   150,   151,   152,   153,   154,
      -1,   156,    -1,   158,   159,   160,   161,   174,   163,    -1,
     165,    -1,    -1,    -1,    -1,    -1,    -1,   172,   173,    -1,
     175,    -1,    -1,    -1,    -1,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,    -1,    -1,    -1,    -1,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   219,   220,    -1,    -1,    -1,    -1,
      -1,    -1,   227,    -1,    -1,    -1,   231,    -1,    -1,    -1,
      -1,    -1,    -1,   238,    -1,    -1,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,   251,    -1,    -1,    -1,
      -1,    -1,   257,    -1,    -1,   260,    -1,    -1,    -1,   264,
      -1,    -1,   267,   268,    -1,   270,    -1,    -1,   273,    -1,
     275,    -1,    -1,    -1,   279,   280,    -1,    -1,    -1,    -1,
      -1,   286,   287,   288,   289,    -1,   291,    -1,   293,    -1,
      -1,    -1,    -1,   298,     5,     6,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    23,    -1,    -1,    26,    -1,   322,   323,    -1,
      -1,    -1,    -1,   328,   329,    -1,    -1,    38,    -1,    -1,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    -1,    83,    -1,    -1,    86,    -1,    -1,    -1,    -1,
      -1,    92,    -1,    -1,    -1,    -1,    97,    98,    99,    -1,
      -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   113,    -1,    -1,   116,    -1,   118,   119,   120,
      -1,   134,    -1,    -1,   125,   126,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   142,   143,    -1,    -1,   146,    -1,   148,   149,   150,
     151,   152,   153,   154,    -1,   156,    -1,   158,   159,   160,
     161,   174,   163,    -1,   165,    -1,    -1,    -1,    -1,    -1,
      -1,   172,    -1,    -1,   175,    -1,    -1,    -1,    -1,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,    -1,
      -1,    -1,    -1,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,   220,
      -1,    -1,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,
     231,   232,   233,   234,   235,    -1,    -1,   238,    -1,    -1,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
     251,    -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,   260,
      -1,    -1,    -1,   264,    -1,    -1,   267,   268,    -1,   270,
      -1,    -1,   273,    -1,   275,    -1,    -1,    -1,   279,   280,
      -1,    -1,    -1,    -1,    -1,   286,   287,   288,   289,    -1,
     291,    -1,   293,    -1,    -1,    -1,    -1,   298,     5,     6,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    23,    -1,    -1,    26,
      -1,   322,   323,    -1,    -1,    -1,    -1,   328,   329,    -1,
      -1,    38,    -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      67,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    -1,    83,    -1,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,
      97,    98,    99,    -1,    -1,    -1,    -1,    -1,   105,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,   116,
      -1,   118,   119,   120,   134,    -1,    -1,    -1,   125,   126,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   142,   143,    -1,    -1,   146,
      -1,   148,   149,   150,   151,   152,   153,   154,    -1,   156,
      -1,   158,   159,   160,   161,    -1,   163,    -1,   165,    -1,
      -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,   175,    -1,
      -1,    -1,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,    -1,    -1,    -1,    -1,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   206,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   219,   220,    -1,    -1,    -1,    -1,    -1,    -1,
     227,    -1,    -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,
      -1,   238,    -1,    -1,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,   251,    -1,    -1,    -1,    -1,    -1,
     257,    -1,    -1,   260,    -1,    -1,    -1,   264,    -1,    -1,
     267,   268,    -1,   270,    -1,    -1,   273,    -1,   275,    -1,
      -1,    -1,   279,   280,    -1,    -1,    -1,    -1,    -1,   286,
     287,   288,   289,    -1,   291,    -1,   293,    -1,    -1,    -1,
      -1,   298,     5,     6,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    -1,    -1,    26,    -1,   322,   323,    -1,    -1,    -1,
      -1,   328,   329,    -1,    -1,    38,    -1,    -1,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    67,    -1,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,
      83,    -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,    92,
      -1,    -1,    -1,    -1,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     113,    -1,    -1,   116,    -1,   118,   119,   120,    -1,   134,
      -1,    -1,   125,   126,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,
     143,    -1,    -1,   146,    -1,   148,   149,   150,   151,   152,
     153,   154,    -1,   156,    -1,   158,   159,   160,   161,   174,
     163,    -1,   165,    -1,    -1,    -1,    -1,    -1,    -1,   172,
     173,    -1,   175,    -1,    -1,    -1,    -1,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,    -1,    -1,    -1,
      -1,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   219,   220,    -1,    -1,
      -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,   231,    -1,
      -1,    -1,    -1,    -1,    -1,   238,    -1,    -1,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,   251,    -1,
      -1,    -1,    -1,    -1,   257,    -1,    -1,   260,    -1,    -1,
      -1,   264,    -1,    -1,   267,   268,    -1,   270,    -1,    -1,
     273,    -1,   275,    -1,    -1,    -1,   279,   280,    -1,    -1,
      -1,    -1,    -1,   286,   287,   288,   289,    -1,   291,    -1,
     293,    -1,    -1,    -1,    -1,   298,     5,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    23,    -1,    -1,    26,    -1,   322,
     323,    -1,    -1,    -1,    -1,   328,   329,    -1,    -1,    38,
      -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    67,    -1,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    -1,    83,    -1,    -1,    86,    -1,    -1,
      -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,    97,    98,
      99,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   113,    -1,    -1,   116,    -1,   118,
     119,   120,    -1,    -1,    -1,    -1,   125,   126,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,   143,    -1,    -1,   146,    -1,   148,
     149,   150,   151,   152,   153,   154,    -1,   156,    -1,   158,
     159,   160,   161,    -1,   163,    -1,   165,    -1,    -1,    -1,
      -1,    -1,    -1,   172,    -1,    -1,   175,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     219,   220,    -1,    -1,    -1,    -1,    -1,    -1,   227,    -1,
      -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,   238,
      -1,    -1,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,   251,    -1,    -1,    -1,    -1,    -1,   257,    -1,
      -1,   260,    -1,    -1,    -1,   264,    -1,    -1,   267,   268,
      -1,   270,    -1,    -1,   273,    -1,   275,    -1,    -1,    -1,
     279,   280,    -1,    -1,    -1,    -1,    -1,   286,   287,   288,
     289,    -1,   291,    -1,   293,    -1,    -1,    -1,    -1,   298,
       5,     6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    -1,
      -1,    26,    -1,   322,   323,    -1,    -1,    -1,    -1,   328,
     329,    -1,    -1,    38,    -1,    -1,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    67,    -1,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    83,    -1,
      -1,    86,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,
      -1,    -1,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,
     105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,
      -1,   116,    -1,   118,   119,   120,    -1,    -1,    -1,    -1,
     125,   126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,   143,    -1,
      -1,   146,    -1,   148,   149,   150,   151,   152,   153,   154,
      -1,   156,    -1,   158,   159,   160,   161,    -1,   163,    -1,
     165,    -1,    -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,
     175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   219,   220,    -1,    -1,    -1,    -1,
      -1,    -1,   227,    -1,    -1,    -1,   231,    -1,    -1,    -1,
      -1,    -1,    -1,   238,    -1,    -1,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,   251,    -1,    -1,    -1,
      -1,    -1,   257,    -1,    -1,   260,    -1,    -1,    -1,   264,
      -1,    -1,   267,   268,    -1,   270,    -1,    -1,   273,    -1,
     275,    -1,    -1,    -1,   279,   280,    -1,    -1,    -1,    -1,
      -1,   286,   287,   288,   289,    -1,   291,    -1,   293,    -1,
      -1,    -1,    -1,   298,     5,     6,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    23,    -1,    -1,    26,    -1,   322,   323,    -1,
      -1,    -1,    -1,   328,   329,    -1,    -1,    38,    -1,    -1,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    -1,    -1,    -1,    67,    -1,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    -1,    83,    -1,    -1,    86,    -1,    -1,    -1,    -1,
      -1,    92,    -1,    -1,    -1,    -1,    97,    98,    99,    -1,
      -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   113,    -1,    -1,   116,    -1,   118,   119,   120,
      -1,    -1,    -1,    -1,   125,   126,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   142,   143,    -1,    -1,   146,    -1,   148,   149,   150,
     151,   152,   153,   154,    -1,   156,    -1,   158,   159,   160,
     161,    -1,   163,    -1,   165,    -1,    -1,    -1,    -1,    -1,
      -1,   172,    -1,    -1,   175,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,   220,
      -1,    -1,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,
     231,    -1,    -1,    -1,    -1,    -1,    -1,   238,    -1,    -1,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
     251,    -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,   260,
      -1,    -1,    -1,   264,    -1,    -1,   267,   268,    -1,   270,
      -1,    -1,   273,    -1,   275,    -1,    -1,    -1,   279,   280,
      -1,    -1,    -1,    -1,    -1,   286,   287,   288,   289,    -1,
     291,    -1,   293,    -1,    -1,    -1,    -1,   298,     5,     6,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    23,    -1,    -1,    26,
      -1,   322,   323,    -1,    -1,    -1,    -1,   328,   329,    -1,
      -1,    38,    -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    -1,    83,    -1,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,
      97,    98,    99,    -1,    -1,    -1,    -1,    -1,   105,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,   116,
      -1,   118,   119,   120,    -1,    -1,    -1,    -1,   125,   126,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   142,   143,    -1,    -1,   146,
      -1,   148,   149,   150,   151,   152,   153,   154,    -1,   156,
      -1,   158,   159,   160,   161,    -1,   163,    -1,   165,    -1,
      -1,    -1,    -1,    -1,    -1,   172,   173,    -1,   175,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   219,   220,    -1,    -1,    -1,    -1,    -1,    -1,
     227,    -1,    -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,
      -1,   238,    -1,    -1,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,   251,    -1,    -1,    -1,    -1,    -1,
     257,    -1,    -1,   260,    -1,    -1,    -1,   264,    -1,    -1,
     267,   268,    -1,   270,    -1,    -1,   273,    -1,   275,    -1,
      -1,    -1,   279,   280,    -1,    -1,    -1,    -1,    -1,   286,
     287,   288,   289,    -1,   291,    -1,   293,    -1,    -1,    -1,
      -1,   298,     5,     6,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    -1,    -1,    26,    -1,   322,   323,    -1,    -1,    -1,
      -1,   328,   329,    -1,    -1,    38,    -1,    -1,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,
      83,    -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,    92,
      -1,    -1,    -1,    -1,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     113,    -1,    -1,   116,    -1,   118,   119,   120,    -1,    -1,
      -1,    -1,   125,   126,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,
     143,    -1,    -1,   146,    -1,   148,   149,   150,   151,   152,
     153,   154,    -1,   156,    -1,   158,   159,   160,   161,    -1,
     163,    -1,   165,    -1,    -1,    -1,    -1,    -1,    -1,   172,
      -1,    -1,   175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   219,   220,    -1,    -1,
      -1,    -1,    -1,    -1,   227,    -1,   229,    -1,   231,    -1,
      -1,    -1,    -1,    -1,    -1,   238,    -1,    -1,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,   251,    -1,
      -1,    -1,    -1,    -1,   257,    -1,    -1,   260,    -1,    -1,
      -1,   264,    -1,    -1,   267,   268,    -1,   270,    -1,    -1,
     273,    -1,   275,    -1,    -1,    -1,   279,   280,    -1,    -1,
      -1,    -1,    -1,   286,   287,   288,   289,    -1,   291,    -1,
     293,    -1,    -1,    -1,    -1,   298,     5,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    23,    -1,    -1,    26,    -1,   322,
     323,    -1,    -1,    -1,    -1,   328,   329,    -1,    -1,    38,
      -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    -1,    83,    -1,    -1,    86,    -1,    -1,
      -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,    97,    98,
      99,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   113,    -1,    -1,   116,    -1,   118,
     119,   120,    -1,    -1,    -1,    -1,   125,   126,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,   143,    -1,    -1,   146,    -1,   148,
     149,   150,   151,   152,   153,   154,    -1,   156,    -1,   158,
     159,   160,   161,    -1,   163,    -1,   165,    -1,    -1,    -1,
      -1,    -1,    -1,   172,    -1,    -1,   175,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     219,   220,    -1,    -1,    -1,    -1,    -1,    -1,   227,    -1,
      -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,   238,
      -1,    -1,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,   251,    -1,    -1,    -1,    -1,    -1,   257,    -1,
      -1,   260,    -1,    -1,    -1,   264,    -1,    -1,   267,   268,
      -1,   270,    -1,    -1,   273,   274,   275,    -1,    -1,    -1,
     279,   280,    -1,    -1,    -1,    -1,    -1,   286,   287,   288,
     289,    -1,   291,    -1,   293,    -1,    -1,    -1,    -1,   298,
       5,     6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    -1,
      -1,    26,    -1,   322,   323,    -1,    -1,    -1,    -1,   328,
     329,    -1,    -1,    38,    -1,    -1,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    83,    -1,
      -1,    86,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,
      -1,    -1,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,
     105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,
      -1,   116,    -1,   118,   119,   120,    -1,    -1,    -1,    -1,
     125,   126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,   143,    -1,
      -1,   146,    -1,   148,   149,   150,   151,   152,   153,   154,
      -1,   156,    -1,   158,   159,   160,   161,    -1,   163,    -1,
     165,    -1,    -1,    -1,    -1,    -1,    -1,   172,   173,    -1,
     175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   219,   220,    -1,    -1,    -1,    -1,
      -1,    -1,   227,    -1,    -1,    -1,   231,    -1,    -1,    -1,
      -1,    -1,    -1,   238,    -1,    -1,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,   251,    -1,    -1,    -1,
      -1,    -1,   257,    -1,    -1,   260,    -1,    -1,    -1,   264,
      -1,    -1,   267,   268,    -1,   270,    -1,    -1,   273,    -1,
     275,    -1,    -1,    -1,   279,   280,    -1,    -1,    -1,    -1,
      -1,   286,   287,   288,   289,    -1,   291,    -1,   293,    -1,
      -1,    -1,    -1,   298,     5,     6,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    23,    -1,    -1,    26,    -1,   322,   323,    -1,
      -1,    -1,    -1,   328,   329,    -1,    -1,    38,    -1,    -1,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    -1,    83,    -1,    -1,    86,    -1,    -1,    -1,    -1,
      -1,    92,    -1,    -1,    -1,    -1,    97,    98,    99,    -1,
      -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   113,    -1,    -1,   116,    -1,   118,   119,   120,
      -1,    -1,    -1,    -1,   125,   126,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   142,   143,    -1,    -1,   146,    -1,   148,   149,   150,
     151,   152,   153,   154,    -1,   156,    -1,   158,   159,   160,
     161,    -1,   163,    -1,   165,    -1,    -1,    -1,    -1,    -1,
      -1,   172,    -1,    -1,   175,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   206,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,   220,
      -1,    -1,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,
     231,    -1,    -1,    -1,    -1,    -1,    -1,   238,    -1,    -1,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
     251,    -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,   260,
      -1,    -1,    -1,   264,    -1,    -1,   267,   268,    -1,   270,
      -1,    -1,   273,    -1,   275,    -1,    -1,    -1,   279,   280,
      -1,    -1,    -1,    -1,    -1,   286,   287,   288,   289,    -1,
     291,    -1,   293,    -1,    -1,    -1,    -1,   298,     5,     6,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    23,    -1,    -1,    26,
      -1,   322,   323,    -1,    -1,    -1,    -1,   328,   329,    -1,
      -1,    38,    -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    -1,    83,    -1,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,
      97,    98,    99,    -1,    -1,    -1,    -1,    -1,   105,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,   116,
      -1,   118,   119,   120,    -1,    -1,    -1,    -1,   125,   126,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   142,   143,    -1,    -1,   146,
      -1,   148,   149,   150,   151,   152,   153,   154,    -1,   156,
      -1,   158,   159,   160,   161,    -1,   163,    -1,   165,    -1,
      -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,   175,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   219,   220,    -1,    -1,    -1,    -1,    -1,    -1,
     227,    -1,   229,    -1,   231,    -1,    -1,    -1,    -1,    -1,
      -1,   238,    -1,    -1,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,   251,    -1,    -1,    -1,    -1,    -1,
     257,    -1,    -1,   260,    -1,    -1,    -1,   264,    -1,    -1,
     267,   268,    -1,   270,    -1,    -1,   273,    -1,   275,    -1,
      -1,    -1,   279,   280,    -1,    -1,    -1,    -1,    -1,   286,
     287,   288,   289,    -1,   291,    -1,   293,    -1,    -1,    -1,
      -1,   298,     5,     6,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    -1,    -1,    26,    -1,   322,   323,    -1,    -1,    -1,
      -1,   328,   329,    -1,    -1,    38,    -1,    -1,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,
      83,    -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,    92,
      -1,    -1,    -1,    -1,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     113,    -1,    -1,   116,    -1,   118,   119,   120,    -1,    -1,
      -1,    -1,   125,   126,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,
     143,    -1,    -1,   146,    -1,   148,   149,   150,   151,   152,
     153,   154,    -1,   156,    -1,   158,   159,   160,   161,    -1,
     163,    -1,   165,    -1,    -1,    -1,    -1,    -1,    -1,   172,
      -1,    -1,   175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   219,   220,    -1,    -1,
      -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,   231,    -1,
      -1,    -1,    -1,    -1,    -1,   238,    -1,    -1,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,   251,    -1,
      -1,    -1,    -1,    -1,   257,    -1,    -1,   260,    -1,    -1,
      -1,   264,    -1,    -1,   267,   268,    -1,   270,    -1,    -1,
     273,    -1,   275,    -1,    -1,    -1,   279,   280,    -1,    -1,
      -1,    -1,    -1,   286,   287,   288,   289,    -1,   291,    -1,
     293,    -1,    -1,    -1,    -1,   298,     5,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    23,    -1,    -1,    26,    -1,   322,
     323,    -1,    -1,    -1,    -1,   328,   329,    -1,    -1,    38,
      -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    -1,    83,    -1,    -1,    86,    -1,    -1,
      -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,    97,    98,
      99,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   113,    -1,    -1,   116,    -1,   118,
     119,   120,    -1,    -1,    -1,    -1,   125,   126,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,   143,    -1,    -1,   146,    -1,   148,
     149,   150,   151,   152,   153,   154,    -1,   156,    -1,   158,
     159,   160,   161,    -1,   163,    -1,   165,    -1,    -1,    -1,
      -1,    -1,    -1,   172,    -1,    -1,   175,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     219,   220,    -1,    -1,    -1,    -1,    -1,    -1,   227,    -1,
      -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,   238,
      -1,    -1,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,   251,    -1,    -1,    -1,    -1,    -1,   257,    -1,
      -1,   260,    -1,    -1,    -1,   264,    -1,    -1,   267,   268,
      -1,   270,    -1,    -1,   273,    -1,   275,    -1,    -1,    -1,
     279,   280,    -1,    -1,    -1,    -1,    -1,   286,   287,   288,
     289,    -1,   291,    -1,   293,    -1,    -1,    -1,    -1,   298,
       5,     6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    -1,
      -1,    26,    -1,   322,   323,    -1,    -1,    -1,    -1,   328,
     329,    -1,    -1,    38,    -1,    -1,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    83,    -1,
      -1,    86,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,
      -1,    -1,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,
     105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,
      -1,   116,    -1,   118,   119,   120,    -1,    -1,    -1,    -1,
     125,   126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,   143,    -1,
      -1,   146,    -1,   148,   149,   150,   151,   152,   153,   154,
      -1,   156,    -1,   158,   159,   160,   161,    -1,   163,    -1,
     165,    -1,    -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,
     175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   219,   220,    -1,    -1,    -1,    -1,
      -1,    -1,   227,    -1,    -1,    -1,   231,    -1,    -1,    -1,
      -1,    -1,    -1,   238,    -1,    -1,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,   251,    -1,    -1,    -1,
      -1,    -1,   257,    -1,    -1,   260,    -1,    -1,    -1,   264,
      -1,    -1,   267,   268,    -1,   270,    -1,    -1,   273,    -1,
     275,    -1,    -1,    -1,   279,   280,    -1,    -1,    -1,    -1,
      -1,   286,   287,   288,   289,    -1,   291,    -1,   293,    -1,
      -1,    -1,    -1,   298,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,   323,    -1,
      -1,    -1,    -1,   328,   329
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,    51,    64,    65,    66,    67,    77,    78,    79,
      80,    86,   133,   171,   173,   230,   239,   240,   242,   244,
     245,   246,   247,   248,   249,   252,   258,   259,   274,   277,
     315,   351,   357,   358,   361,   362,   363,   364,   366,   368,
     369,   378,   383,   395,   400,   401,   407,   452,   455,   463,
     484,   498,   502,   503,   504,   512,   527,   528,   529,   548,
     552,   553,   554,   557,   679,   133,   111,     5,     6,     7,
       8,     9,    10,    22,    23,    26,    38,    41,    52,    63,
      80,    83,    86,    92,    97,    98,    99,   105,   113,   116,
     118,   119,   120,   125,   126,   142,   143,   146,   148,   149,
     150,   151,   152,   153,   154,   156,   158,   159,   160,   161,
     163,   165,   172,   175,   219,   220,   227,   231,   238,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   251,   257,
     260,   264,   267,   268,   270,   273,   275,   279,   280,   286,
     287,   288,   289,   291,   293,   298,   322,   323,   328,   329,
     647,   673,   674,   178,   251,   538,   262,    81,   509,   509,
     673,    79,    87,   549,   550,   673,    66,   557,   188,    67,
      69,    70,   617,   618,   619,   673,   647,   354,   353,   355,
     356,   352,     5,    11,   677,   680,     5,     6,     7,     8,
       9,    10,    64,    65,    66,    67,   178,   249,   272,   315,
     379,   386,   387,   388,   390,   391,   392,   671,   672,   258,
     261,   384,   385,    58,    87,    55,   115,   279,    11,   173,
     234,   300,   447,   448,   520,   548,   554,   662,   676,     0,
      17,    55,    58,   103,   105,   115,   219,   220,   221,   222,
     223,   224,   231,   260,   273,   279,   282,   284,   324,   408,
     409,   412,   413,   446,   165,   232,   233,   234,   235,    55,
     115,   165,   178,   231,   232,   233,   234,   235,   260,   273,
     279,   284,   321,   324,   497,    55,    56,    57,    63,   173,
     260,   273,   287,   451,   644,   673,   219,   220,   279,   367,
     412,   444,   673,   133,   102,   166,   167,   168,   573,   133,
     647,   274,   345,     3,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    18,    19,    27,    28,    44,
      45,    46,    47,    48,    49,    50,    62,   106,   110,   114,
     124,   134,   135,   136,   137,   138,   140,   141,   144,   145,
     147,   157,   164,   173,   176,   192,   193,   202,   203,   204,
     206,   209,   286,   287,   288,   289,   302,   306,   307,   347,
     349,   534,   560,   571,   572,   580,   581,   582,   583,   585,
     587,   588,   590,   592,   594,   595,   597,   598,   599,   600,
     601,   602,   603,   616,   617,   620,   622,   623,   624,   626,
     627,   628,   629,   630,   644,   645,   646,   648,   649,   651,
     666,   669,   673,   678,   687,   688,   689,   690,   691,   705,
     712,   714,   717,   727,   728,   758,   647,   190,   510,   510,
     673,    88,    91,    97,   505,   506,   507,   344,   551,   554,
     450,   451,   538,   174,   322,   173,   345,   450,   364,   364,
     351,   351,   364,   173,   450,   450,   270,   450,   111,   262,
     281,   344,   281,   344,   265,   344,   266,   266,   386,   379,
      87,   505,   274,   673,   647,   647,   447,   557,   262,   662,
     262,    27,   262,   300,   316,   219,   220,   673,   219,   220,
     647,   279,   279,   279,   279,   647,   673,   308,   360,   360,
     647,   647,   321,   279,   233,   647,   647,   647,   647,   673,
     647,   233,   165,   232,   233,   234,   235,   647,   647,   647,
     647,   647,   673,   308,   359,   359,   359,   647,   647,    42,
      43,   501,   227,   444,   673,   673,   298,   177,   177,   177,
     344,     5,     6,     7,    20,    24,    25,    26,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    52,    53,    54,
     286,   287,   288,   289,   344,   635,   643,   664,   666,   667,
     668,   669,   104,   178,   251,   558,   558,   558,   299,   574,
     285,   542,   451,   539,   541,   670,   673,   673,   678,   678,
     678,   173,   173,    22,   173,   621,   621,   621,   621,   621,
     173,   597,   173,   125,   673,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   283,   548,   557,
     571,   581,   589,   617,   673,   581,   173,   599,   599,   173,
     173,   173,   599,   678,   173,   633,   173,   634,   192,   193,
     631,   303,   599,   656,   657,   173,   173,   581,   593,   111,
     262,   561,   562,   188,   323,   625,   190,   177,   180,   181,
     182,   183,   184,   185,   186,   187,   191,   647,   134,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   263,   334,   345,   344,   173,   173,   173,   678,
     678,   345,   173,   250,   283,   448,   451,   530,    82,    83,
     281,   511,    89,    90,    92,    98,   344,   550,   323,   560,
     174,   535,   599,   652,   619,   673,   301,   576,   133,   133,
     133,   173,   174,   533,   535,   537,   557,   271,   393,   394,
     671,   671,   393,   388,   165,   279,   389,   497,   647,   392,
     112,   112,   111,   111,   505,   255,   256,   410,   171,   254,
     274,   396,   116,   117,   118,   119,   120,   121,   122,   123,
     126,   323,   403,   405,   406,   252,   274,   277,   278,   174,
     647,   319,   678,   262,   647,   662,   300,   171,    86,   323,
     402,   404,   406,   360,   360,   360,   360,   237,   171,   376,
     176,   227,   370,   673,   647,   450,   326,   327,   485,   673,
     360,   647,   173,   173,   173,   173,   647,   233,   647,   647,
     647,   647,   501,   173,   499,   499,   499,   499,   106,   647,
     647,   647,   673,   174,    58,   289,   646,   597,   673,   571,
     444,   173,   173,    21,    22,   173,   173,   173,    38,   173,
     633,   634,   290,   292,   294,   295,   296,   297,   636,   639,
     641,   642,   673,   173,   173,   173,   173,   577,   578,   599,
     169,   559,   559,   559,   601,   661,   676,   300,   575,   571,
     177,   344,   562,   177,   345,   571,   650,   650,    23,   174,
     291,   293,   297,   636,   637,   638,   112,   599,   600,   599,
     684,   685,   686,   684,   238,   155,   706,   732,   152,   154,
     730,   238,     3,   718,   600,   115,   729,   730,   684,   557,
     173,   531,   174,   174,   174,   174,   344,   345,   599,   599,
     599,   677,   171,   632,   677,   632,   678,   571,   303,   654,
     655,   305,   656,   658,   599,   535,   653,   344,   348,    68,
     173,   347,   543,   563,   564,   596,   617,   647,   673,   555,
     556,   673,   542,   572,   673,   581,   178,   179,   189,   581,
     591,   100,   101,   584,   584,   173,   173,   586,   599,   586,
     586,   586,   581,   591,   594,   599,   599,   599,   599,   599,
     599,   599,   599,   599,   599,   599,   599,   599,   599,   599,
     599,   599,   599,   599,   599,   599,   599,   599,   599,   110,
     176,   173,   206,   624,   174,   178,   206,   251,   599,   659,
     673,   659,     8,     9,    10,   206,   673,   283,   531,   530,
      82,    79,    88,    95,    96,   508,   677,   507,   173,   596,
     174,   344,    14,   601,   662,   243,   365,   174,   344,   171,
     344,   381,   171,   380,   647,   393,   393,   257,   410,   281,
     273,   104,   171,   661,   661,   661,   664,   405,   229,   279,
     280,   398,   399,    67,    88,   397,   399,   279,   399,   111,
      16,   518,   519,   518,   647,   450,   316,   662,   410,   171,
     664,   404,   647,   647,   647,   647,   238,   261,   106,   371,
     673,   250,   372,   227,   111,   173,   415,   416,   450,   323,
      64,    65,    67,   486,   265,   647,   173,   206,   482,   483,
     673,   482,   482,   482,   499,   647,   501,   501,   501,   501,
     174,   500,   664,   501,   501,   501,   664,   660,   677,   660,
      23,   660,   660,   660,   677,    53,   665,   678,   632,   632,
     634,   633,   281,   660,   677,   660,   660,   660,   344,   225,
     226,   579,   104,   557,   557,   557,   601,   662,   576,   597,
     541,   542,   250,   540,   571,   673,   323,   344,   111,   647,
     158,   731,   344,   731,   731,   673,   693,   173,   599,   707,
     708,   709,   344,   600,   673,   715,   146,   719,   731,   684,
     573,   174,   250,   532,   535,   536,   174,   344,   182,   183,
     581,   111,   344,   183,   344,   174,   287,   678,   174,   678,
     642,   304,   599,   654,   658,   599,   314,   344,   344,   174,
     344,   581,   597,   617,   173,   283,   543,   548,   554,   564,
     565,   344,    69,    70,    71,    73,    74,    76,   170,   544,
     546,   323,   566,   673,   566,   567,   567,   345,   344,   561,
     109,   568,   581,   581,   581,   533,   533,   107,   597,   110,
     335,   604,   605,   659,   174,   659,   174,   345,   344,   345,
     673,    93,    94,    88,   535,   537,   261,   394,   111,   382,
     258,   382,   382,   382,   678,   257,   673,   673,   661,   597,
     662,   673,   673,   673,    90,    89,    90,   673,   647,   229,
     419,   422,   433,   434,   670,   617,   110,   521,   317,   521,
     450,   111,   257,   662,   415,   415,   415,   415,   673,    56,
      62,   377,    20,   268,   681,   682,   371,   234,   185,   418,
     419,   420,   425,   445,   673,    99,   411,   323,   447,   325,
     265,   647,   415,   482,   174,   344,   664,   174,   174,   174,
     501,   174,   344,   174,   174,   174,   174,   344,   174,   344,
     174,   344,   297,   636,   640,   174,   344,   174,   174,   174,
     578,   173,   664,   664,   599,   115,   154,   174,   684,   174,
     174,   344,   692,    83,   250,   599,   733,   734,   736,   737,
     738,   266,   344,   703,   323,   710,    84,   142,   713,   344,
     716,   104,   720,   740,   731,   174,   161,   741,   742,   731,
     174,   344,   173,   173,   173,   599,   599,   599,   599,   298,
     535,   304,   314,   599,   535,   535,   566,   567,   531,   174,
     174,   174,   557,   564,   544,    75,   564,    75,    72,   545,
     673,   173,   673,   556,   104,   108,   570,   190,   190,   174,
     174,   678,   104,   174,   102,   606,   174,   174,   206,   659,
     673,   266,   377,   266,    16,   678,   501,   501,   501,   252,
     274,   673,   253,   269,   282,   442,   130,   131,   421,   664,
     323,   490,   678,   111,   173,   318,   525,   526,   678,   678,
     265,   274,   673,   675,   683,   357,   361,   373,   374,   375,
     378,   383,   395,   400,   498,   617,   647,   174,   344,   171,
     673,   447,   171,   449,   444,   647,   173,   265,   414,   174,
      66,    80,    86,   237,   240,   276,   302,   308,   313,   366,
     368,   369,   378,   383,   395,   400,   456,   459,   461,   462,
     463,   467,   469,   475,   477,   478,   498,   502,   503,   553,
     673,   673,   236,   241,   236,   500,   663,   677,   677,   677,
     634,   677,   569,   648,   673,   174,   174,   174,   139,   599,
     694,   700,   701,   702,   732,   731,   250,   736,   174,   344,
     323,   110,   148,   150,   151,   704,   708,   731,   673,   711,
     143,   143,   174,   600,   731,   125,   149,   600,   721,   722,
     723,   724,   725,   740,   281,   174,   174,   536,   532,   533,
     533,   112,   174,   174,   344,   174,   344,   535,   174,   174,
     348,    75,   564,    16,   265,   547,   564,   173,   675,   569,
     571,   581,   581,   569,   104,    85,   342,   607,   608,   174,
     174,   331,   274,   250,    99,   110,   176,   250,   264,   264,
     451,   127,   132,   250,   423,   424,   427,   428,   430,   431,
     434,   678,   344,   525,   526,   173,   515,   515,   344,   238,
       3,   673,   344,   375,   420,   673,   267,     3,   171,   417,
     228,   333,   487,   444,    77,   237,   538,   238,   464,   465,
     647,   279,   448,   468,   571,   303,   472,   473,   599,   571,
     312,   457,   310,   346,   664,   279,   481,   664,     5,   481,
     174,   174,   174,   174,   174,   344,   345,   173,   344,   344,
     703,   344,   174,   734,   673,   735,   265,   265,   265,   265,
     174,   174,   323,   739,   740,   344,   110,   151,   726,   162,
     174,   174,   174,   599,   599,   599,   566,   564,   451,   571,
     547,   675,   174,   577,   181,   336,   343,   600,   609,   610,
     611,   612,   257,   273,     3,   110,   110,   429,   598,   451,
     451,   128,   429,   427,   110,   176,   228,   269,   272,   282,
     441,   443,   678,    83,   524,   174,   516,   517,   673,   518,
     518,   678,   678,   673,   173,    83,   172,   266,   330,   331,
     488,   489,   112,   492,   493,   174,    64,    84,   252,   238,
     560,   453,   673,   173,   173,   571,   305,   472,   474,   303,
     470,   471,   304,   457,   459,   571,   173,   237,   241,   456,
       4,   454,   678,   237,   241,   648,   673,   599,   695,   696,
     698,   700,   702,   694,   700,   110,    83,   110,   110,   110,
     673,   722,   265,   265,   174,    83,   160,   163,   743,   744,
     749,   174,   174,   174,   174,   610,   328,   339,   339,   337,
     615,   678,   673,   272,   323,   110,   173,   264,   647,   344,
     229,   174,   344,     3,   521,   521,   273,   426,   427,   172,
     279,   328,   491,   279,   491,   489,   332,   303,   495,    85,
      85,   453,   345,   466,   599,   448,   304,   457,   314,   599,
     470,   474,   457,   459,   133,   311,   480,   670,   238,     5,
     238,     5,   174,   344,   323,   697,   344,   154,   739,   151,
     151,   156,   673,   750,     3,   745,   746,    83,   153,   156,
     751,   752,   754,   755,   190,    83,   109,   336,   341,   647,
     129,   571,   450,   678,   517,    59,   522,   522,   673,   174,
     344,   490,   490,   490,   490,   328,   329,   494,   173,   313,
     366,   368,   378,   383,   460,   461,   496,   502,   503,   553,
     673,   174,   344,   174,   457,   459,   302,   304,   314,   305,
     309,   476,   133,   314,   457,   174,   344,   664,   453,   454,
     453,   454,   696,   673,   699,   700,   159,   747,   747,   156,
     673,   757,   746,   756,   753,   754,   336,   343,   600,   613,
     614,   340,   328,   450,   173,   432,   174,   113,   440,    60,
     523,   523,   427,   673,   673,   673,   673,   571,   312,   599,
     133,   457,   302,   457,   571,   314,   314,   314,   670,   746,
     748,   328,   338,   339,   440,   402,    39,    40,    71,   439,
     265,   436,   437,   438,    61,   524,   524,   174,   458,   304,
     308,   310,   664,   438,   174,    64,    65,   265,   437,   265,
     436,   320,   513,   314,   460,   457,   479,   673,    42,    43,
      83,   274,   435,   435,   173,   133,   476,    41,   110,   250,
     514,   662,   174,   344,   662
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   350,   351,   352,   351,   353,   351,   354,   351,   355,
     351,   356,   351,   351,   351,   351,   351,   351,   357,   358,
     358,   359,   359,   360,   360,   361,   362,   363,   364,   364,
     364,   364,   364,   364,   364,   364,   364,   364,   365,   365,
     366,   366,   367,   367,   368,   368,   368,   368,   368,   368,
     368,   368,   369,   369,   370,   370,   370,   371,   372,   372,
     373,   373,   374,   374,   375,   375,   375,   375,   375,   376,
     376,   377,   377,   378,   378,   379,   379,   380,   380,   381,
     381,   382,   382,   383,   383,   384,   384,   385,   385,   386,
     386,   387,   387,   388,   388,   389,   389,   389,   390,   390,
     390,   391,   391,   392,   392,   392,   392,   392,   392,   393,
     393,   394,   394,   395,   395,   395,   395,   395,   395,   395,
     395,   395,   395,   396,   396,   396,   397,   397,   397,   397,
     397,   397,   398,   398,   398,   399,   399,   400,   400,   400,
     400,   400,   400,   400,   400,   401,   401,   401,   402,   402,
     403,   403,   404,   404,   404,   405,   405,   405,   405,   405,
     406,   406,   406,   406,   406,   406,   406,   406,   407,   408,
     408,   408,   408,   409,   409,   410,   410,   410,   411,   411,
     412,   412,   412,   412,   412,   412,   412,   413,   413,   413,
     413,   413,   413,   414,   414,   414,   414,   415,   415,   416,
     417,   417,   417,   418,   418,   419,   419,   420,   420,   420,
     421,   421,   422,   422,   423,   423,   424,   424,   425,   426,
     426,   427,   427,   427,   428,   429,   430,   431,   431,   432,
     432,   433,   434,   434,   435,   435,   435,   435,   435,   436,
     437,   438,   438,   438,   438,   438,   439,   439,   439,   439,
     440,   440,   441,   441,   441,   441,   441,   441,   442,   442,
     442,   443,   444,   444,   445,   446,   447,   447,   448,   448,
     449,   449,   450,   450,   451,   452,   453,   454,   454,   455,
     455,   455,   455,   455,   455,   455,   455,   455,   456,   456,
     456,   457,   457,   458,   458,   459,   459,   459,   459,   459,
     459,   459,   459,   459,   459,   459,   459,   460,   460,   460,
     460,   460,   460,   460,   460,   461,   461,   461,   461,   461,
     461,   462,   463,   464,   465,   466,   466,   466,   467,   468,
     468,   468,   469,   469,   470,   471,   471,   472,   473,   473,
     474,   474,   475,   476,   476,   476,   477,   478,   478,   479,
     479,   480,   480,   481,   481,   482,   482,   482,   483,   483,
     484,   485,   485,   486,   486,   486,   486,   487,   487,   488,
     488,   489,   489,   489,   489,   490,   490,   491,   491,   492,
     493,   493,   494,   494,   495,   495,   496,   496,   497,   497,
     497,   497,   497,   498,   498,   498,   498,   498,   498,   498,
     498,   498,   498,   498,   498,   498,   499,   499,   499,   500,
     500,   501,   501,   501,   364,   364,   502,   502,   502,   502,
     503,   504,   504,   504,   504,   504,   504,   504,   505,   505,
     506,   506,   507,   507,   507,   507,   508,   508,   508,   508,
     509,   509,   510,   510,   510,   511,   511,   512,   512,   512,
     512,   512,   512,   513,   513,   514,   514,   515,   515,   516,
     516,   517,   517,   518,   518,   518,   518,   519,   519,   520,
     520,   520,   520,   520,   521,   521,   522,   522,   523,   523,
     524,   524,   525,   525,   526,   526,   527,   528,   529,   529,
     530,   530,   530,   530,   531,   531,   532,   532,   533,   533,
     534,   535,   536,   536,   537,   537,   538,   538,   538,   539,
     539,   540,   541,   541,   541,   542,   542,   543,   543,   543,
     543,   543,   544,   544,   544,   545,   545,   546,   546,   546,
     547,   547,   364,   548,   549,   549,   550,   551,   364,   364,
     552,   553,   554,   555,   555,   556,   557,   557,   557,   557,
     557,   558,   558,   558,   559,   559,   559,   560,   561,   562,
     562,   563,   563,   564,   564,   564,   564,   564,   564,   564,
     565,   564,   566,   566,   566,   566,   567,   567,   568,   568,
     569,   569,   570,   570,   571,   571,   572,   572,   573,   573,
     574,   574,   574,   575,   575,   575,   576,   576,   576,   576,
     577,   577,   578,   579,   579,   579,   580,   580,   580,   580,
     580,   580,   580,   580,   580,   581,   581,   582,   582,   583,
     583,   584,   584,   584,   585,   585,   585,   585,   586,   586,
     587,   587,   588,   588,   588,   588,   589,   589,   590,   590,
     591,   591,   591,   592,   593,   593,   594,   595,   596,   596,
     596,   597,   597,   597,   598,   598,   598,   598,   598,   598,
     598,   598,   598,   598,   598,   598,   598,   598,   598,   598,
     598,   598,   598,   598,   598,   598,   598,   598,   598,   598,
     598,   598,   599,   599,   600,   600,   600,   600,   600,   600,
     600,   600,   600,   600,   600,   600,   600,   600,   600,   600,
     601,   602,   603,   603,   604,   605,   605,   606,   606,   607,
     607,   608,   608,   609,   609,   610,   610,   610,   611,   612,
     613,   613,   613,   614,   615,   615,   615,   615,   615,   616,
     617,   617,   618,   618,   619,   619,   619,   619,   620,   620,
     620,   620,   620,   620,   621,   621,   622,   622,   622,   622,
     622,   622,   622,   623,   623,   624,   624,   624,   624,   625,
     625,   626,   627,   627,   628,   628,   629,   629,   630,   630,
     630,   630,   630,   630,   630,   631,   631,   631,   632,   632,
     633,   633,   634,   634,   635,   635,   635,   636,   636,   636,
     636,   636,   637,   637,   638,   638,   638,   639,   640,   640,
     641,   641,   642,   642,   643,   644,   644,   644,   645,   645,
     645,   645,   645,   645,   645,   645,   645,   645,   645,   645,
     645,   645,   645,   645,   646,   647,   647,   647,   648,   648,
     648,   649,   649,   650,   651,   651,   651,   651,   652,   652,
     653,   653,   654,   655,   655,   656,   657,   657,   658,   658,
     659,   660,   661,   662,   663,   664,   664,   664,   664,   664,
     664,   664,   664,   664,   664,   664,   664,   664,   664,   664,
     664,   664,   664,   664,   664,   664,   664,   664,   664,   664,
     664,   664,   664,   664,   664,   664,   664,   664,   664,   664,
     664,   665,   665,   666,   667,   667,   668,   668,   668,   669,
     669,   670,   671,   672,   672,   672,   672,   672,   672,   673,
     673,   673,   673,   673,   673,   673,   673,   674,   674,   674,
     674,   674,   674,   674,   674,   674,   674,   674,   674,   674,
     674,   674,   674,   674,   674,   674,   674,   674,   674,   674,
     674,   674,   674,   674,   674,   674,   674,   674,   674,   674,
     674,   674,   674,   674,   674,   674,   674,   674,   674,   674,
     674,   674,   674,   674,   674,   674,   674,   674,   674,   674,
     674,   674,   674,   674,   674,   674,   674,   674,   674,   674,
     674,   674,   674,   674,   674,   674,   674,   674,   674,   674,
     674,   674,   674,   675,   675,   676,   677,   677,   678,   678,
     679,   680,   680,   681,   681,   682,   683,   684,   685,   685,
     686,   687,   687,   687,   687,   687,   687,   687,   687,   687,
     687,   688,   689,   690,   691,   692,   692,   692,   692,   692,
     692,   692,   692,   693,   694,   695,   695,   696,   697,   697,
     698,   699,   700,   701,   701,   702,   703,   703,   704,   704,
     704,   704,   704,   705,   706,   706,   707,   707,   708,   709,
     710,   710,   711,   712,   713,   713,   714,   715,   716,   716,
     717,   718,   719,   719,   720,   721,   721,   722,   722,   723,
     724,   725,   725,   726,   726,   727,   728,   729,   729,   730,
     730,   731,   731,   731,   732,   733,   733,   734,   734,   735,
     736,   737,   738,   738,   739,   739,   740,   740,   741,   741,
     742,   743,   743,   744,   744,   745,   746,   747,   747,   748,
     749,   750,   751,   751,   752,   752,   753,   753,   754,   755,
     755,   756,   757,   758
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     4,     0,     4,     0,     4,     0,
       3,     0,     3,     2,     0,     1,     2,     1,     1,     1,
       3,     0,     2,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     1,     0,     1,
       2,     2,     2,     4,     4,     4,     4,     3,     4,     3,
       4,     4,     7,     5,     1,     2,     3,     1,     0,     4,
       0,     1,     1,     2,     1,     1,     1,     1,     1,     0,
       3,     1,     1,     6,     6,     1,     3,     0,     3,     0,
       3,     0,     2,     6,     6,     0,     3,     0,     3,     1,
       3,     1,     3,     2,     2,     2,     1,     1,     2,     1,
       1,     1,     3,     1,     1,     2,     2,     2,     1,     1,
       3,     1,     1,     6,     6,     5,     5,     6,     6,     6,
       4,     6,    10,     4,     3,     7,     5,     4,     5,     4,
       5,     5,     3,     3,     3,     1,     0,     2,     2,     2,
       1,     1,     1,     1,     1,     4,     3,     4,     1,     2,
       1,     2,     2,     3,     1,     2,     1,     3,     3,     1,
       3,     2,     1,     2,     1,     2,     1,     1,     9,     1,
       1,     1,     0,     3,    10,     0,     1,     1,     0,     3,
       5,     6,     5,     5,     5,     7,     6,     1,     1,     2,
       2,     2,     2,     0,     4,     4,     3,     3,     1,     4,
       0,     3,     2,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     0,     1,     1,     2,     6,     1,
       3,     1,     1,     1,     2,     1,     2,     5,     1,     0,
       3,     2,     0,     2,     2,     1,     1,     2,     2,     3,
       3,     0,     1,     1,     2,     2,     0,     1,     1,     1,
       0,     2,     2,     1,     1,     2,     5,     1,     2,     3,
       8,     4,     1,     3,     2,     6,     1,     3,     1,     1,
       0,     3,     0,     1,     3,     6,     3,     1,     1,    11,
       9,    11,    10,    11,    11,     9,     7,     9,     1,     5,
       6,     0,     3,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     4,     1,     0,     1,     3,     2,     1,
       1,     4,     6,     5,     4,     1,     2,     4,     1,     2,
       0,     2,     7,     0,     2,     5,     8,     0,     2,     0,
       1,     2,     4,     4,     1,     1,     1,     0,     4,     2,
       9,     1,     1,     1,     1,     1,     3,     0,     2,     1,
       2,     4,     4,     4,     4,     0,     1,     0,     1,     3,
       0,     3,     1,     1,     0,     4,     1,     4,     3,     4,
       3,     3,     3,     5,     3,     5,     6,     5,     5,     5,
       5,     4,     3,     3,     3,     3,     0,     3,     2,     1,
       3,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     3,     4,     3,     4,     3,     0,     1,
       1,     3,     2,     2,     3,     3,     2,     2,     2,     1,
       1,     0,     2,     3,     0,     0,     3,    14,    13,     6,
       9,     6,     6,     0,     4,     1,     3,     0,     3,     1,
       3,     1,     2,     0,     3,     5,     7,     0,     1,     0,
       2,     2,     4,     4,     0,     3,     0,     1,     0,     2,
       0,     2,     1,     3,     1,     3,     4,     6,     4,     5,
       0,     2,     2,     1,     3,     5,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     0,     1,     1,     1,
       3,     1,     3,     3,     3,     0,     2,     3,     4,     4,
       5,     5,     0,     1,     2,     0,     1,     1,     1,     1,
       2,     2,     1,     3,     3,     1,     4,     1,     1,     1,
       4,     6,     5,     1,     3,     1,     5,     5,     5,     3,
       1,     0,     1,     1,     0,     1,     5,     1,     4,     0,
       2,     1,     3,     2,     2,     3,     2,     3,     1,     1,
       0,     5,     5,     2,     4,     1,     0,     1,     0,     3,
       1,     3,     0,     2,     3,     1,     3,     1,     0,     3,
       0,     2,     2,     0,     2,     2,     0,     2,     2,     2,
       1,     3,     2,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     3,     3,     6,
       6,     0,     1,     1,     3,     3,     3,     3,     1,     3,
       4,     3,     5,     5,     7,     7,     1,     3,     4,     4,
       1,     1,     1,     2,     1,     3,     3,     3,     3,     4,
       3,     3,     4,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     2,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     3,     1,     3,     0,     3,     0,     3,     0,
       3,     1,     1,     1,     1,     2,     1,     2,     2,     4,
       2,     1,     2,     2,     0,     3,     2,     2,     3,     2,
       3,     4,     1,     3,     1,     1,     1,     1,     6,     2,
       2,     2,     2,     2,     0,     2,     8,     8,     6,     6,
       6,     3,     8,     1,     3,     1,     3,     3,     2,     0,
       2,     1,     1,     3,     1,     3,     1,     3,     4,     6,
       5,     5,     4,     6,     1,     1,     1,     0,     3,     0,
       3,     0,     3,     0,     1,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     2,
       2,     2,     3,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     4,     4,     1,     2,     2,
       2,     2,     1,     1,     4,     1,     3,     5,     1,     3,
       5,     6,     6,     1,     6,     4,     5,     4,     1,     3,
       3,     3,     4,     1,     2,     4,     1,     2,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     1,     4,     1,     1,     1,     1,     1,     1,     4,
       6,     1,     4,     6,     1,     2,     1,     1,     1,     1,
       4,     1,     4,     6,     1,     4,     1,     4,     6,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     2,
       2,     3,     4,     0,     1,     2,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     5,     5,     7,     0,     2,     4,     6,     4,
       2,     4,     2,     1,     4,     1,     3,     2,     0,     2,
       1,     1,     2,     1,     3,     1,     0,     2,     3,     3,
       3,     3,     4,     7,     0,     2,     1,     3,     2,     1,
       0,     2,     1,     6,     2,     2,     7,     1,     0,     2,
       8,     1,     0,     3,     1,     1,     3,     1,     1,     2,
       4,     0,     1,     3,     3,     5,     6,     1,     1,     1,
       1,     0,     2,     2,     4,     1,     3,     1,     1,     1,
       1,     3,     2,     2,     0,     1,     2,     2,     0,     1,
       5,     1,     1,     3,     3,     1,     1,     0,     2,     1,
       2,     1,     0,     1,     1,     2,     0,     1,     2,     2,
       2,     1,     1,     6
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (m, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, m); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, mvc *m)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (m);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, mvc *m)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, m);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule, mvc *m)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              , m);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, m); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, mvc *m)
{
  YYUSE (yyvaluep);
  YYUSE (m);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (mvc *m)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval, m);
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 622 "sql_parser.y" /* yacc.c:1646  */
    {
		if (m->sym) {
			append_symbol(m->sym->data.lval, (yyval.sym));
			(yyval.sym) = m->sym;
		} else {
			m->sym = (yyval.sym) = (yyvsp[-1].sym);
		}
		YYACCEPT;
	}
#line 6769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 632 "sql_parser.y" /* yacc.c:1646  */
    {
		  	  m->emode = m_prepare; 
			  m->scanner.as = m->scanner.yycur; 
			  m->scanner.key = 0;
			}
#line 6779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 637 "sql_parser.y" /* yacc.c:1646  */
    {
			  if (m->sym) {
				append_symbol(m->sym->data.lval, (yyvsp[-1].sym));
				(yyval.sym) = m->sym;
			  } else {
				m->sym = (yyval.sym) = (yyvsp[-1].sym);
			  }
			  YYACCEPT;
			}
#line 6793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 646 "sql_parser.y" /* yacc.c:1646  */
    {
		  	  m->emode = m_plan;
			  m->scanner.as = m->scanner.yycur; 
			  m->scanner.key = 0;
			}
#line 6803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 651 "sql_parser.y" /* yacc.c:1646  */
    {
			  if (m->sym) {
				append_symbol(m->sym->data.lval, (yyvsp[-1].sym));
				(yyval.sym) = m->sym;
			  } else {
				m->sym = (yyval.sym) = (yyvsp[-1].sym);
			  }
			  YYACCEPT;
			}
#line 6817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 661 "sql_parser.y" /* yacc.c:1646  */
    {
		  	  m->emod |= mod_explain;
			  m->scanner.as = m->scanner.yycur; 
			  m->scanner.key = 0;
			}
#line 6827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 666 "sql_parser.y" /* yacc.c:1646  */
    {
			  if (m->sym) {
				append_symbol(m->sym->data.lval, (yyvsp[-1].sym));
				(yyval.sym) = m->sym;
			  } else {
				m->sym = (yyval.sym) = (yyvsp[-1].sym);
			  }
			  YYACCEPT;
			}
#line 6841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 676 "sql_parser.y" /* yacc.c:1646  */
    {
			  if (m->scanner.mode == LINE_1) {
				yyerror(m, "SQL debugging only supported in interactive mode");
				YYABORT;
			  }
		  	  m->emod |= mod_debug;
			  m->scanner.as = m->scanner.yycur; 
			  m->scanner.key = 0;
			}
#line 6855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 685 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[0].sym); YYACCEPT; }
#line 6861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 686 "sql_parser.y" /* yacc.c:1646  */
    {
		  	  m->emod |= mod_trace;
			  m->scanner.as = m->scanner.yycur; 
			  m->scanner.key = 0;
			}
#line 6871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 691 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[0].sym); YYACCEPT; }
#line 6877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 692 "sql_parser.y" /* yacc.c:1646  */
    { m->sym = (yyval.sym) = (yyvsp[-1].sym); YYACCEPT; }
#line 6883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 693 "sql_parser.y" /* yacc.c:1646  */
    { m->sym = (yyval.sym) = NULL; YYACCEPT; }
#line 6889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 694 "sql_parser.y" /* yacc.c:1646  */
    { m->sym = (yyval.sym) = NULL; YYACCEPT; }
#line 6895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 695 "sql_parser.y" /* yacc.c:1646  */
    { m->sym = (yyval.sym) = NULL; YYACCEPT; }
#line 6901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 696 "sql_parser.y" /* yacc.c:1646  */
    { m->sym = (yyval.sym) = NULL; YYABORT; }
#line 6907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 701 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = FALSE; }
#line 6913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 705 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = TRUE; }
#line 6919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 709 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = FALSE; }
#line 6925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 710 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = TRUE; }
#line 6931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 713 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = FALSE; }
#line 6937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 714 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = TRUE; }
#line 6943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 737 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
		append_list(l, (yyvsp[-3].l));
		append_list(l, (yyvsp[-2].l));
		append_symbol(l, (yyvsp[-1].sym));
		append_int(l, (yyvsp[0].i_val));
		(yyval.sym) = _symbol_create_list( SQL_ANALYZE, l); }
#line 6954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 747 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 0; }
#line 6960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 748 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 1; }
#line 6966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 753 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list( SQL_DECLARE, (yyvsp[0].l)); }
#line 6972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 754 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[0].sym); }
#line 6978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 759 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
		append_list(l, (yyvsp[-1].l) );
		append_type(l, &(yyvsp[0].type) );
		(yyval.l) = append_symbol(L(), _symbol_create_list( SQL_DECLARE, l)); }
#line 6987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 764 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
		append_list(l, (yyvsp[-1].l) );
		append_type(l, &(yyvsp[0].type) );
		(yyval.l) = append_symbol((yyvsp[-3].l), _symbol_create_list( SQL_DECLARE, l)); }
#line 6996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 773 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
		append_string(l, (yyvsp[-2].sval) );
		append_symbol(l, (yyvsp[0].sym) );
		(yyval.sym) = _symbol_create_list( SQL_SET, l); }
#line 7005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 778 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  	append_list(l, (yyvsp[-2].l));
	  	append_symbol(l, (yyvsp[0].sym));
	  	(yyval.sym) = _symbol_create_list( SQL_SET, l ); }
#line 7014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 783 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
		  sql_subtype t;
	        sql_find_subtype(&t, "char", UTF8_strlen((yyvsp[0].sval)), 0 );
		append_string(l, sa_strdup(SA, "current_user"));
		append_symbol(l,
			_newAtomNode( _atom_string(&t, sql2str((yyvsp[0].sval)))) );
		(yyval.sym) = _symbol_create_list( SQL_SET, l); }
#line 7026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 791 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
		  sql_subtype t;
		sql_find_subtype(&t, "char", UTF8_strlen((yyvsp[0].sval)), 0 );
		append_string(l, sa_strdup(SA, "current_schema"));
		append_symbol(l,
			_newAtomNode( _atom_string(&t, sql2str((yyvsp[0].sval)))) );
		(yyval.sym) = _symbol_create_list( SQL_SET, l); }
#line 7038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 799 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
		  sql_subtype t;
		sql_find_subtype(&t, "char", UTF8_strlen((yyvsp[0].sval)), 0 );
		append_string(l, sa_strdup(SA, "current_user"));
		append_symbol(l,
			_newAtomNode( _atom_string(&t, sql2str((yyvsp[0].sval)))) );
		(yyval.sym) = _symbol_create_list( SQL_SET, l); }
#line 7050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 807 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
		  sql_subtype t;
		sql_find_subtype(&t, "char", UTF8_strlen((yyvsp[0].sval)), 0);
		append_string(l, sa_strdup(SA, "current_role"));
		append_symbol(l,
			_newAtomNode( _atom_string(&t, sql2str((yyvsp[0].sval)))) );
		(yyval.sym) = _symbol_create_list( SQL_SET, l); }
#line 7062 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 815 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
		append_string(l, sa_strdup(SA, "current_timezone"));
		append_symbol(l, _symbol_create_list( SQL_OP, append_list(L(),
			append_string( L(), sa_strdup(SA, "local_timezone")))));
		(yyval.sym) = _symbol_create_list( SQL_SET, l); }
#line 7072 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 821 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
		append_string(l, sa_strdup(SA, "current_timezone"));
		append_symbol(l, (yyvsp[0].sym) );
		(yyval.sym) = _symbol_create_list( SQL_SET, l); }
#line 7081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 830 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
		append_list(l, (yyvsp[-3].l));
		append_symbol(l, (yyvsp[-2].sym));
		append_symbol(l, (yyvsp[-1].sym));
		append_list(l, (yyvsp[0].l));
		append_int(l, (yyvsp[-4].bval));
		(yyval.sym) = _symbol_create_list( SQL_CREATE_SCHEMA, l); }
#line 7093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 838 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
		append_list(l, (yyvsp[-1].l));
		append_int(l, (yyvsp[0].i_val));
		append_int(l, (yyvsp[-2].bval));
		(yyval.sym) = _symbol_create_list( SQL_DROP_SCHEMA, l); }
#line 7103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 847 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = L();
	  append_string((yyval.l), (yyvsp[0].sval) );
	  append_string((yyval.l), NULL ); }
#line 7111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 851 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = L();
	  append_string((yyval.l), NULL );
	  append_string((yyval.l), (yyvsp[0].sval) ); }
#line 7119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 855 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = L();
	  append_string((yyval.l), (yyvsp[-2].sval) );
	  append_string((yyval.l), (yyvsp[0].sval) ); }
#line 7127 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 864 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = NULL; }
#line 7133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 865 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create( SQL_CHARSET, (yyvsp[0].sval) ); }
#line 7139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 869 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = L(); }
#line 7145 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 874 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol(L(), (yyvsp[0].sym)); }
#line 7151 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 876 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol( (yyvsp[-1].l), (yyvsp[0].sym) ); }
#line 7157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 882 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = cur_user; }
#line 7163 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 883 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = (yyvsp[0].i_val); }
#line 7169 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 887 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = cur_user; }
#line 7175 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 888 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = cur_role; }
#line 7181 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 893 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_list(l, (yyvsp[-4].l));
	  append_list(l, (yyvsp[-2].l));
	  append_int(l, (yyvsp[-1].bval));
	  append_int(l, (yyvsp[0].i_val));
	(yyval.sym) = _symbol_create_list( SQL_GRANT, l);
	}
#line 7193 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 903 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_list(l, (yyvsp[-4].l));
	  append_list(l, (yyvsp[-2].l));
	  append_int(l, (yyvsp[-1].bval));
	  append_int(l, (yyvsp[0].i_val));
	(yyval.sym) = _symbol_create_list( SQL_GRANT_ROLES, l); }
#line 7204 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 912 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_string(L(), (yyvsp[0].sval)); }
#line 7210 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 914 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_string((yyvsp[-2].l), (yyvsp[0].sval)); }
#line 7216 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 918 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = 0; }
#line 7222 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 919 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = 1; }
#line 7228 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 923 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = 0; }
#line 7234 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 924 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = 1; }
#line 7240 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 929 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = cur_user; }
#line 7246 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 930 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = (yyvsp[0].i_val); }
#line 7252 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 935 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_list(l, (yyvsp[-3].l));
	  append_list(l, (yyvsp[-1].l));
	  append_int(l, (yyvsp[-4].bval)); /* GRANT OPTION FOR */
	  append_int(l, 0);
	  append_int(l, (yyvsp[0].i_val));
	(yyval.sym) = _symbol_create_list( SQL_REVOKE, l); }
#line 7264 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 943 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_list(l, (yyvsp[-3].l));
	  append_list(l, (yyvsp[-1].l));
	  append_int(l, (yyvsp[-4].bval));
	  append_int(l, (yyvsp[0].i_val));
	(yyval.sym) = _symbol_create_list( SQL_REVOKE_ROLES, l); }
#line 7275 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 952 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = 0; }
#line 7281 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 953 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = 1; }
#line 7287 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 957 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = 0; }
#line 7293 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 958 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = 1; }
#line 7299 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 963 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = L();
	  append_list((yyval.l), (yyvsp[0].l));
	  append_symbol((yyval.l), _symbol_create(SQL_GRANT, NULL)); }
#line 7307 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 967 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = L();
	  append_list((yyval.l), (yyvsp[-2].l));
	  append_symbol((yyval.l), (yyvsp[0].sym)); }
#line 7315 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 973 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_int(L(), (yyvsp[0].i_val)); }
#line 7321 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 975 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_int(append_int(L(), (yyvsp[-2].i_val)), (yyvsp[0].i_val)); }
#line 7327 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 979 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = PRIV_COPYFROMFILE; }
#line 7333 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 980 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = PRIV_COPYINTOFILE; }
#line 7339 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 984 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list(SQL_TABLE, (yyvsp[0].l)); }
#line 7345 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 985 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list(SQL_NAME, (yyvsp[0].l)); }
#line 7351 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 986 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list(SQL_FUNC, (yyvsp[0].l)); }
#line 7357 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 997 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = NULL; }
#line 7363 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 998 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = NULL; }
#line 7369 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1003 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol(L(), (yyvsp[0].sym)); }
#line 7375 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1005 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol((yyvsp[-2].l), (yyvsp[0].sym)); }
#line 7381 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1009 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create(SQL_INSERT,NULL); }
#line 7387 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1010 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create(SQL_DELETE,NULL); }
#line 7393 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1011 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list(SQL_UPDATE,(yyvsp[0].l)); }
#line 7399 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1012 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list(SQL_SELECT,(yyvsp[0].l)); }
#line 7405 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1013 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list(SQL_SELECT,(yyvsp[0].l)); }
#line 7411 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1014 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create(SQL_EXECUTE,NULL); }
#line 7417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1018 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_string(L(), (yyvsp[0].sval)); }
#line 7423 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1020 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_string((yyvsp[-2].l), (yyvsp[0].sval)); }
#line 7429 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1024 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = NULL; }
#line 7435 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1025 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[0].sval); }
#line 7441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1033 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_list(l, (yyvsp[-3].l));
	  append_symbol(l, (yyvsp[0].sym));
	  (yyval.sym) = _symbol_create_list( SQL_ALTER_TABLE, l ); }
#line 7450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1038 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_list(l, (yyvsp[-3].l));
	  append_symbol(l, _symbol_create_list( SQL_TABLE, (yyvsp[0].l)));
	  (yyval.sym) = _symbol_create_list( SQL_ALTER_TABLE, l ); }
#line 7459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1043 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_list(l, (yyvsp[-2].l));
	  append_symbol(l, (yyvsp[0].sym));
	  (yyval.sym) = _symbol_create_list( SQL_ALTER_TABLE, l ); }
#line 7468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1048 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_list(l, (yyvsp[-2].l));
	  append_symbol(l, (yyvsp[0].sym));
	  (yyval.sym) = _symbol_create_list( SQL_ALTER_TABLE, l ); }
#line 7477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1053 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_list(l, (yyvsp[-3].l));
	  append_symbol(l, _symbol_create_int(SQL_ALTER_TABLE, tr_readonly));
	  (yyval.sym) = _symbol_create_list( SQL_ALTER_TABLE, l ); }
#line 7486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1058 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_list(l, (yyvsp[-3].l));
	  append_symbol(l, _symbol_create_int(SQL_ALTER_TABLE, tr_append));
	  (yyval.sym) = _symbol_create_list( SQL_ALTER_TABLE, l ); }
#line 7495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1063 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_list(l, (yyvsp[-3].l));
	  append_symbol(l, _symbol_create_int(SQL_ALTER_TABLE, tr_writable));
	  (yyval.sym) = _symbol_create_list( SQL_ALTER_TABLE, l ); }
#line 7504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1068 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_string(l, (yyvsp[-1].sval));
	  append_list(l, (yyvsp[0].l));
	  (yyval.sym) = _symbol_create_list( SQL_ALTER_USER, l ); }
#line 7513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1073 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_string(l, (yyvsp[-3].sval));
	  append_string(l, (yyvsp[0].sval));
	  (yyval.sym) = _symbol_create_list( SQL_RENAME_USER, l ); }
#line 7522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1078 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  dlist *p = L();
	  append_string(l, NULL);
	  append_string(p, (yyvsp[-4].sval));
	  append_string(p, NULL);
	  append_int(p, (yyvsp[-6].i_val));
	  append_string(p, (yyvsp[0].sval));
	  append_list(l, p);
	  (yyval.sym) = _symbol_create_list( SQL_ALTER_USER, l ); }
#line 7536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1090 "sql_parser.y" /* yacc.c:1646  */
    { dlist * l = L();
				  append_string(l, (yyvsp[0].sval));
				  append_string(l, NULL);
				  append_int(l, (yyvsp[-2].i_val));
				  append_string(l, NULL);
				  (yyval.l) = l; }
#line 7547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1096 "sql_parser.y" /* yacc.c:1646  */
    { dlist * l = L();
				  append_string(l, NULL);
				  append_string(l, (yyvsp[0].sval));
				  append_int(l, 0);
				  append_string(l, NULL);
				  (yyval.l) = l; }
#line 7558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 1103 "sql_parser.y" /* yacc.c:1646  */
    { dlist * l = L();
				  append_string(l, (yyvsp[-3].sval));
				  append_string(l, (yyvsp[0].sval));
				  append_int(l, (yyvsp[-5].i_val));
				  append_string(l, NULL);
				  (yyval.l) = l; }
#line 7569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 1113 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_string(l, (yyvsp[-3].sval));
	  append_symbol(l, (yyvsp[0].sym));
	  (yyval.sym) = _symbol_create_list( SQL_DEFAULT, l); }
#line 7578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1118 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_string(l, (yyvsp[-2].sval));
	  (yyval.sym) = _symbol_create_list( SQL_NULL, l); }
#line 7586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1122 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_string(l, (yyvsp[-3].sval));
	  (yyval.sym) = _symbol_create_list( SQL_NOT_NULL, l); }
#line 7594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1126 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create( SQL_DROP_DEFAULT, (yyvsp[-2].sval)); }
#line 7600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1128 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_string(l, (yyvsp[-3].sval));
	  if (!strlen((yyvsp[0].sval)))
	  	append_string(l, NULL);
	  else
	  	append_string(l, (yyvsp[0].sval));
	  (yyval.sym) = _symbol_create_list( SQL_STORAGE, l); }
#line 7612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1136 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_string(l, (yyvsp[-3].sval));
	  append_string(l, NULL);
	  (yyval.sym) = _symbol_create_list( SQL_STORAGE, l); }
#line 7621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1144 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_string(l, (yyvsp[-1].sval) );
	  append_int(l, (yyvsp[0].i_val) );
	  (yyval.sym) = _symbol_create_list( SQL_DROP_COLUMN, l ); }
#line 7630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1149 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_string(l, (yyvsp[-1].sval) );
	  append_int(l, (yyvsp[0].i_val) );
	  (yyval.sym) = _symbol_create_list( SQL_DROP_CONSTRAINT, l ); }
#line 7639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1154 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_string(l, (yyvsp[-1].sval) );
	  append_int(l, (yyvsp[0].i_val) );
	  append_int(l, 0);
	  (yyval.sym) = _symbol_create_list( SQL_DROP_TABLE, l ); }
#line 7649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1162 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 0; }
#line 7655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1163 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 0; }
#line 7661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1167 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[0].sym); }
#line 7667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1168 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[0].sym); }
#line 7673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1169 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[0].sym); }
#line 7679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1191 "sql_parser.y" /* yacc.c:1646  */
    {
		dlist *l = L();
		append_list(l, (yyvsp[-1].l));
		append_list(l, (yyvsp[0].l));
		append_int(l, 0); /* to be dropped */
		(yyval.sym) = _symbol_create_list(SQL_CREATE_SEQ, l);
	}
#line 7691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1202 "sql_parser.y" /* yacc.c:1646  */
    {
		dlist *l = L();
		append_list(l, (yyvsp[0].l));
		(yyval.sym) = _symbol_create_list(SQL_DROP_SEQ, l);
	}
#line 7701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1219 "sql_parser.y" /* yacc.c:1646  */
    {
		dlist *l = L();
		append_list(l, (yyvsp[-1].l));
		append_list(l, (yyvsp[0].l)); 
		(yyval.sym) = _symbol_create_list(SQL_ALTER_SEQ, l);
	}
#line 7712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1228 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol(L(), (yyvsp[0].sym)); }
#line 7718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1229 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol((yyvsp[-1].l), (yyvsp[0].sym)); }
#line 7724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1233 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol(L(), (yyvsp[0].sym)); }
#line 7730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1234 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol((yyvsp[-1].l), (yyvsp[0].sym)); }
#line 7736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1238 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list(SQL_TYPE, append_type(L(),&(yyvsp[0].type))); }
#line 7742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1239 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_lng(SQL_START, (yyvsp[0].l_val)); }
#line 7748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 1240 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[0].sym); }
#line 7754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 1244 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list(SQL_TYPE, append_type(L(),&(yyvsp[0].type))); }
#line 7760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 1245 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list(SQL_START, append_int(L(),0)); /* plain restart now */ }
#line 7766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 1246 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list(SQL_START, append_lng(append_int(L(),2), (yyvsp[0].l_val)));  }
#line 7772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 1247 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list(SQL_START, append_symbol(append_int(L(),1), (yyvsp[0].sym)));  }
#line 7778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 1248 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[0].sym); }
#line 7784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 1252 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_lng(SQL_INC, (yyvsp[0].l_val)); }
#line 7790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 1253 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_lng(SQL_MINVALUE, (yyvsp[0].l_val)); }
#line 7796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1254 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_lng(SQL_MINVALUE, 0); }
#line 7802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1255 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_lng(SQL_MAXVALUE, (yyvsp[0].l_val)); }
#line 7808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1256 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_lng(SQL_MAXVALUE, 0); }
#line 7814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1257 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_lng(SQL_CACHE, (yyvsp[0].l_val)); }
#line 7820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1258 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_int(SQL_CYCLE, 1); }
#line 7826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1259 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_int(SQL_CYCLE, 0); }
#line 7832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1267 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_string(l, (yyvsp[-5].sval));
	  append_int(l, (yyvsp[-7].i_val));
	  append_list(l, (yyvsp[-3].l));
	  append_list(l, (yyvsp[-1].l));
	  (yyval.sym) = _symbol_create_list( SQL_CREATE_INDEX, l); }
#line 7843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1276 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = hash_idx; }
#line 7849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1277 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = ordered_idx; }
#line 7855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1278 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = imprints_idx; }
#line 7861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1279 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = hash_idx; }
#line 7867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1300 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_string(l, (yyvsp[-1].sval));
	  append_int(l, (yyvsp[0].i_val));
	  (yyval.sym) = _symbol_create_list( SQL_CREATE_ROLE, l ); }
#line 7876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1305 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_string(l, (yyvsp[-8].sval));
	  append_string(l, (yyvsp[-4].sval));
	  append_string(l, (yyvsp[-2].sval));
	  append_string(l, (yyvsp[0].sval));
	  append_int(l, (yyvsp[-6].i_val));
	  (yyval.sym) = _symbol_create_list( SQL_CREATE_USER, l ); }
#line 7888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1315 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = SQL_PW_UNENCRYPTED; }
#line 7894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1316 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = SQL_PW_UNENCRYPTED; }
#line 7900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1317 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = SQL_PW_ENCRYPTED; }
#line 7906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1321 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = NULL; }
#line 7912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1322 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_string(append_string(L(), (yyvsp[-1].sval)), (yyvsp[0].sval)); }
#line 7918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1327 "sql_parser.y" /* yacc.c:1646  */
    { int commit_action = CA_COMMIT;
	  dlist *l = L();

	  append_int(l, SQL_PERSIST);
	  append_list(l, (yyvsp[-2].l));
	  append_symbol(l, (yyvsp[-1].sym));
	  append_int(l, commit_action);
	  append_string(l, NULL);
	  append_int(l, (yyvsp[-3].bval));
	  append_list(l, (yyvsp[0].l));
	  (yyval.sym) = _symbol_create_list( SQL_CREATE_TABLE, l ); }
#line 7934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1339 "sql_parser.y" /* yacc.c:1646  */
    {
      dlist *l = L();
      append_list(l, (yyvsp[-3].l));
      append_symbol(l, (yyvsp[0].sym));
      (yyval.sym) = _symbol_create_list( SQL_CREATE_TABLE_LOADER, l);
    }
#line 7945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1346 "sql_parser.y" /* yacc.c:1646  */
    { int commit_action = CA_COMMIT, tpe = SQL_STREAM;
	  dlist *l = L();

	  append_int(l, tpe);
	  append_list(l, (yyvsp[-1].l));
	  append_symbol(l, (yyvsp[0].sym));
	  append_int(l, commit_action);
	  append_string(l, NULL);
	  append_int(l, (yyvsp[-2].bval));
	  (yyval.sym) = _symbol_create_list( SQL_CREATE_TABLE, l ); }
#line 7960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1357 "sql_parser.y" /* yacc.c:1646  */
    { int commit_action = CA_COMMIT, tpe = SQL_MERGE_TABLE;
	  dlist *l = L();

	  append_int(l, tpe);
	  append_list(l, (yyvsp[-1].l));
	  append_symbol(l, (yyvsp[0].sym));
	  append_int(l, commit_action);
	  append_string(l, NULL);
	  append_int(l, (yyvsp[-2].bval));
	  (yyval.sym) = _symbol_create_list( SQL_CREATE_TABLE, l ); }
#line 7975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1368 "sql_parser.y" /* yacc.c:1646  */
    { int commit_action = CA_COMMIT, tpe = SQL_REPLICA_TABLE;
	  dlist *l = L();

	  append_int(l, tpe);
	  append_list(l, (yyvsp[-1].l));
	  append_symbol(l, (yyvsp[0].sym));
	  append_int(l, commit_action);
	  append_string(l, NULL);
	  append_int(l, (yyvsp[-2].bval));
	  (yyval.sym) = _symbol_create_list( SQL_CREATE_TABLE, l ); }
#line 7990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1382 "sql_parser.y" /* yacc.c:1646  */
    { int commit_action = CA_COMMIT, tpe = SQL_REMOTE;
	  dlist *l = L();

	  append_int(l, tpe);
	  append_list(l, (yyvsp[-3].l));
	  append_symbol(l, (yyvsp[-2].sym));
	  append_int(l, commit_action);
	  append_string(l, (yyvsp[0].sval));
	  append_int(l, (yyvsp[-4].bval));
	  (yyval.sym) = _symbol_create_list( SQL_CREATE_TABLE, l ); }
#line 8005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1393 "sql_parser.y" /* yacc.c:1646  */
    { int commit_action = CA_COMMIT;
	  dlist *l = L();

	  append_int(l, (yyvsp[-5].i_val));
	  append_list(l, (yyvsp[-2].l));
	  append_symbol(l, (yyvsp[-1].sym));
	  if ((yyvsp[-5].i_val) != SQL_PERSIST)
		commit_action = (yyvsp[0].i_val);
	  append_int(l, commit_action);
	  append_string(l, NULL);
	  append_int(l, (yyvsp[-3].bval));
	  (yyval.sym) = _symbol_create_list( SQL_CREATE_TABLE, l ); }
#line 8022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1408 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = SQL_LOCAL_TEMP; }
#line 8028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1409 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = SQL_LOCAL_TEMP; }
#line 8034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1410 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = SQL_LOCAL_TEMP; }
#line 8040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1411 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = SQL_LOCAL_TEMP; }
#line 8046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1412 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = SQL_GLOBAL_TEMP; }
#line 8052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1413 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = SQL_GLOBAL_TEMP; }
#line 8058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1417 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = CA_COMMIT; }
#line 8064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1418 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = CA_DELETE; }
#line 8070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1419 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = CA_PRESERVE; }
#line 8076 "y.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1420 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = CA_DROP; }
#line 8082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1424 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list( SQL_CREATE_TABLE, (yyvsp[-1].l)); }
#line 8088 "y.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1425 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list( SQL_SELECT, (yyvsp[0].l)); }
#line 8094 "y.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1433 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_list(L(), (yyvsp[-3].l));
			  append_symbol((yyval.l), (yyvsp[-1].sym)); 
			  append_int((yyval.l), (yyvsp[0].i_val)); }
#line 8102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1439 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 1; }
#line 8108 "y.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1440 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 0; }
#line 8114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1441 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 1; }
#line 8120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1446 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol(L(), (yyvsp[0].sym)); }
#line 8126 "y.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1448 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol( (yyvsp[-2].l), (yyvsp[0].sym) ); }
#line 8132 "y.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1455 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 0; }
#line 8138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1456 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 1; }
#line 8144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1461 "sql_parser.y" /* yacc.c:1646  */
    {
			dlist *l = L();
			append_string(l, (yyvsp[-2].sval));
			append_type(l, &(yyvsp[-1].type));
			append_list(l, (yyvsp[0].l));
			(yyval.sym) = _symbol_create_list(SQL_COLUMN, l);
		}
#line 8156 "y.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1469 "sql_parser.y" /* yacc.c:1646  */
    { /* SERIAL = INTEGER GENERATED ALWAYS AS IDENTITY PRIMARY KEY */
			/* handle multi-statements by wrapping them in a list */
			sql_subtype it;
			dlist* stmts;
			/* note: sql_next_seq_name uses sa_alloc */
			str sn = sql_next_seq_name(m);
			dlist *p; /* primary key */
			/* sequence generation code */
			dlist *l = L();
			/* finally all the options */
			dlist *o = L();

			/* the name of the sequence */
			dlist *seqn1 = L(), *seqn2 = L();

			if (m->scanner.schema)
				append_string(seqn1, m->scanner.schema);
			append_list(l, append_string(seqn1, sn));
			if ((yyvsp[0].i_val) == 1)
				sql_find_subtype(&it, "bigint", 64, 0);
			else
				sql_find_subtype(&it, "int", 32, 0);
    			append_symbol(o, _symbol_create_list(SQL_TYPE, append_type(L(),&it)));
			append_list(l, o);
			append_int(l, 1); /* to be dropped */

			if (m->sym) {
				stmts = m->sym->data.lval;
			} else {
				stmts = L();
				m->sym = _symbol_create_list(SQL_MULSTMT, stmts);
			}	
			append_symbol(stmts, _symbol_create_list(SQL_CREATE_SEQ, l));

			l = L();
			append_string(l, (yyvsp[-1].sval));
			append_type(l, &it);
			o = L();
			if (m->scanner.schema)
				append_string(seqn2, m->scanner.schema);
			append_string(seqn2, sn);
			append_symbol(o, _symbol_create_symbol(SQL_DEFAULT, _symbol_create_list(SQL_NEXT, seqn2)));
			p = L();
			append_string(p, NULL);
			append_symbol(p, _symbol_create(SQL_PRIMARY_KEY, NULL));
			append_symbol(o, _symbol_create_list(SQL_CONSTRAINT, p));
			append_list(l, o);
			(yyval.sym) = _symbol_create_list(SQL_COLUMN, l);
		}
#line 8210 "y.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1521 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = NULL; }
#line 8216 "y.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1527 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol(L(), (yyvsp[0].sym) ); }
#line 8222 "y.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1529 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol( (yyvsp[-1].l), (yyvsp[0].sym) ); }
#line 8228 "y.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1535 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_string(l, (yyvsp[-5].sval) );
	  append_list(l, (yyvsp[-1].l) );
	  (yyval.sym) = _symbol_create_list( SQL_COLUMN_OPTIONS, l ); }
#line 8237 "y.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1543 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol(L(), (yyvsp[0].sym) ); }
#line 8243 "y.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1545 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol((yyvsp[-2].l), (yyvsp[0].sym) ); }
#line 8249 "y.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1551 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_symbol(SQL_DEFAULT, (yyvsp[0].sym)); }
#line 8255 "y.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1555 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[0].sym); }
#line 8261 "y.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1561 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_string(l, (yyvsp[-1].sval) );
	  append_symbol(l, (yyvsp[0].sym) );
	  (yyval.sym) = _symbol_create_list( SQL_CONSTRAINT, l ); }
#line 8270 "y.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1569 "sql_parser.y" /* yacc.c:1646  */
    {
		/* handle multi-statements by wrapping them in a list */
		sql_subtype it;
		dlist* stmts;
		/* note: sql_next_seq_name uses sa_alloc */
		str sn = sql_next_seq_name(m);
		/* sequence generation code */
		dlist *l = L();
		/* the name of the sequence */
		append_list(l, append_string(L(), sn));
		if (!(yyvsp[0].l))
			(yyvsp[0].l) = L();
		sql_find_subtype(&it, "int", 32, 0);
    		append_symbol((yyvsp[0].l), _symbol_create_list(SQL_TYPE, append_type(L(),&it)));

		/* finally all the options */
		append_list(l, (yyvsp[0].l));
		append_int(l, 0); /* to be dropped */
		(yyval.sym) = _symbol_create_symbol(SQL_DEFAULT, _symbol_create_list(SQL_NEXT, append_string(L(), sn)));

		if (m->sym) {
			stmts = m->sym->data.lval;
		} else {
			stmts = L();
			m->sym = _symbol_create_list(SQL_MULSTMT, stmts);
		}	
		append_symbol(stmts, _symbol_create_list(SQL_CREATE_SEQ, l));
	}
#line 8303 "y.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1598 "sql_parser.y" /* yacc.c:1646  */
    {
		/* handle multi-statements by wrapping them in a list */
		sql_subtype it;
		dlist* stmts;
		/* note: sql_next_seq_name uses sa_alloc */
		str sn = sql_next_seq_name(m);
		/* sequence generation code */
		dlist *l = L();
		/* finally all the options */
		dlist *o = L();

		/* the name of the sequence */
		dlist *seqn1 = L(), *seqn2 = L();

		if (m->scanner.schema)
			append_string(seqn1, m->scanner.schema);
		append_list(l, append_string(seqn1, sn));
		sql_find_subtype(&it, "int", 32, 0);
    		append_symbol(o, _symbol_create_list(SQL_TYPE, append_type(L(),&it)));
		append_list(l, o);
		append_int(l, 0); /* to be dropped */
		if (m->scanner.schema)
			append_string(seqn2, m->scanner.schema);
		append_string(seqn2, sn);
		(yyval.sym) = _symbol_create_symbol(SQL_DEFAULT, _symbol_create_list(SQL_NEXT, seqn2));

		if (m->sym) {
			stmts = m->sym->data.lval;
		} else {
			stmts = L();
			m->sym = _symbol_create_list(SQL_MULSTMT, stmts);
		}	
		append_symbol(stmts, _symbol_create_list(SQL_CREATE_SEQ, l));
	}
#line 8342 "y.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1635 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = NULL; }
#line 8348 "y.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1636 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[-1].l); }
#line 8354 "y.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1643 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_string(l, (yyvsp[-1].sval) );
	  append_symbol(l, (yyvsp[0].sym) );
	  (yyval.sym) = _symbol_create_list( SQL_CONSTRAINT, l ); }
#line 8363 "y.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 1652 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = NULL; }
#line 8369 "y.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 1653 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[0].sval); }
#line 8375 "y.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 1657 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 0; }
#line 8381 "y.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 1658 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 1; }
#line 8387 "y.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 1659 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 2; }
#line 8393 "y.tab.c" /* yacc.c:1646  */
    break;

  case 237:
#line 1660 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 3; }
#line 8399 "y.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 1661 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 4; }
#line 8405 "y.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 1665 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = ((yyvsp[0].i_val) << 8); }
#line 8411 "y.tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 1669 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = (yyvsp[0].i_val); }
#line 8417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 241:
#line 1673 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = (2 << 8) + 2; /* defaults are RESTRICT */ }
#line 8423 "y.tab.c" /* yacc.c:1646  */
    break;

  case 242:
#line 1674 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = (yyvsp[0].i_val); }
#line 8429 "y.tab.c" /* yacc.c:1646  */
    break;

  case 243:
#line 1675 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = (yyvsp[0].i_val); }
#line 8435 "y.tab.c" /* yacc.c:1646  */
    break;

  case 244:
#line 1676 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = (yyvsp[-1].i_val) + (yyvsp[0].i_val); }
#line 8441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 1677 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = (yyvsp[-1].i_val) + (yyvsp[0].i_val); }
#line 8447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 246:
#line 1681 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 0; }
#line 8453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 247:
#line 1682 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 1; }
#line 8459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 248:
#line 1683 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 2; }
#line 8465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 249:
#line 1684 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 0; }
#line 8471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 250:
#line 1688 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 0; }
#line 8477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 251:
#line 1689 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = (yyvsp[0].i_val); }
#line 8483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 252:
#line 1693 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create( SQL_NOT_NULL, NULL); }
#line 8489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 253:
#line 1694 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create( SQL_NULL, NULL); }
#line 8495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 254:
#line 1695 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create( SQL_UNIQUE, NULL ); }
#line 8501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1696 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create( SQL_PRIMARY_KEY, NULL ); }
#line 8507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1699 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
			  append_list(l, (yyvsp[-3].l) );
			  append_list(l, (yyvsp[-2].l) );
			  append_int(l, (yyvsp[-1].i_val) );
			  append_int(l, (yyvsp[0].i_val) );
			  (yyval.sym) = _symbol_create_list( SQL_FOREIGN_KEY, l); }
#line 8518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1712 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list( SQL_UNIQUE, (yyvsp[0].l)); }
#line 8524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1714 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list( SQL_PRIMARY_KEY, (yyvsp[0].l)); }
#line 8530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1718 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
			  append_list(l, (yyvsp[-3].l) );
			  append_list(l, (yyvsp[-5].l) );
			  append_list(l, (yyvsp[-2].l) );
			  append_int(l, (yyvsp[-1].i_val) );
			  append_int(l, (yyvsp[0].i_val) );
			  (yyval.sym) = _symbol_create_list( SQL_FOREIGN_KEY, l); }
#line 8542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1730 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = NULL; }
#line 8548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 262:
#line 1735 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_string(L(), (yyvsp[0].sval)); }
#line 8554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 263:
#line 1737 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_string( (yyvsp[-2].l), (yyvsp[0].sval) ); }
#line 8560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 264:
#line 1741 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list( SQL_LIKE, (yyvsp[0].l) ); }
#line 8566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1746 "sql_parser.y" /* yacc.c:1646  */
    {  dlist *l = L();
	  append_list(l, (yyvsp[-4].l));
	  append_list(l, (yyvsp[-3].l));
	  append_symbol(l, (yyvsp[-1].sym));
	  append_int(l, (yyvsp[0].bval));
	  append_int(l, TRUE);	/* persistent view */
	  (yyval.sym) = _symbol_create_list( SQL_CREATE_VIEW, l ); 
	}
#line 8579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 267:
#line 1758 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[-1].sym); }
#line 8585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 270:
#line 1767 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = FALSE; }
#line 8591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 271:
#line 1768 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = TRUE; }
#line 8597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 272:
#line 1772 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = NULL; }
#line 8603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 274:
#line 1777 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[-1].l); }
#line 8609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 275:
#line 1782 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
				append_list(l, (yyvsp[-3].l));
				append_string(l, (yyvsp[0].sval));
			  (yyval.sym) = _symbol_create_list( SQL_CREATE_TYPE, l ); }
#line 8618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 276:
#line 1789 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_string(append_string(L(), (yyvsp[-2].sval)), (yyvsp[0].sval)); }
#line 8624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 279:
#line 1804 "sql_parser.y" /* yacc.c:1646  */
    { dlist *f = L();
				append_list(f, (yyvsp[-8].l));
				append_list(f, (yyvsp[-6].l));
				append_symbol(f, (yyvsp[-3].sym));
				append_list(f, (yyvsp[0].l));
				append_list(f, NULL);
				append_int(f, F_FUNC);
				append_int(f, FUNC_LANG_MAL);
				append_int(f, (yyvsp[-10].bval));
			  (yyval.sym) = _symbol_create_list( SQL_CREATE_FUNC, f ); }
#line 8639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 280:
#line 1818 "sql_parser.y" /* yacc.c:1646  */
    { dlist *f = L();
				append_list(f, (yyvsp[-6].l));
				append_list(f, (yyvsp[-4].l));
				append_symbol(f, (yyvsp[-1].sym));
				append_list(f, NULL);
				append_list(f, (yyvsp[0].l));
				append_int(f, F_FUNC);
				append_int(f, FUNC_LANG_SQL);
				append_int(f, (yyvsp[-8].bval));
			  (yyval.sym) = _symbol_create_list( SQL_CREATE_FUNC, f ); }
#line 8654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 281:
#line 1831 "sql_parser.y" /* yacc.c:1646  */
    { 
			int lang = 0;
			dlist *f = L();
			char l = *(yyvsp[-1].sval);

			if (l == 'R' || l == 'r')
				lang = FUNC_LANG_R;
			else if (l == 'P' || l == 'p')
            {
            	// code does not get cleaner than this people
                if (strcasecmp((yyvsp[-1].sval), "PYTHON_MAP") == 0) {
					lang = FUNC_LANG_MAP_PY;
                } else if (strcasecmp((yyvsp[-1].sval), "PYTHON3_MAP") == 0) {
                	lang = FUNC_LANG_MAP_PY3;
                } else if (strcasecmp((yyvsp[-1].sval), "PYTHON3") == 0) {
                	lang = FUNC_LANG_PY3;
                } else if (strcasecmp((yyvsp[-1].sval), "PYTHON2_MAP") == 0) {
                	lang = FUNC_LANG_MAP_PY2;
                } else if (strcasecmp((yyvsp[-1].sval), "PYTHON2") == 0) {
                	lang = FUNC_LANG_PY2;
                } else {
                	lang = FUNC_LANG_PY;
                }
            }
			else if (l == 'C' || l == 'c')
				lang = FUNC_LANG_C;
			else if (l == 'J' || l == 'j')
				lang = FUNC_LANG_J;
			else {
				char *msg = sql_message("Language name R, C, PYTHON[3], PYTHON[3]_MAP or J(avascript):expected, received '%c'", l);
				yyerror(m, msg);
				_DELETE(msg);
			}

			append_list(f, (yyvsp[-8].l));
			append_list(f, (yyvsp[-6].l));
			append_symbol(f, (yyvsp[-3].sym));
			append_list(f, NULL); 
			append_list(f, append_string(L(), (yyvsp[0].sval)));
			append_int(f, F_FUNC);
			append_int(f, lang);
			append_int(f, (yyvsp[-10].bval));
			(yyval.sym) = _symbol_create_list( SQL_CREATE_FUNC, f ); }
#line 8702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 282:
#line 1877 "sql_parser.y" /* yacc.c:1646  */
    { dlist *f = L();
				append_list(f, (yyvsp[-6].l));
				append_list(f, (yyvsp[-4].l)); 
				/* no returns - use OID */
				append_symbol(f, NULL); 
				append_list(f, (yyvsp[0].l));
				append_list(f, NULL);
				append_int(f, F_FILT);
				append_int(f, FUNC_LANG_MAL);
				append_int(f, (yyvsp[-9].bval));
			  (yyval.sym) = _symbol_create_list( SQL_CREATE_FUNC, f ); }
#line 8718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 283:
#line 1892 "sql_parser.y" /* yacc.c:1646  */
    { dlist *f = L();
				append_list(f, (yyvsp[-8].l));
				append_list(f, (yyvsp[-6].l));
				append_symbol(f, (yyvsp[-3].sym));
				append_list(f, (yyvsp[0].l));
				append_list(f, NULL);
				append_int(f, F_AGGR);
				append_int(f, FUNC_LANG_MAL);
				append_int(f, (yyvsp[-10].bval));
			  (yyval.sym) = _symbol_create_list( SQL_CREATE_FUNC, f ); }
#line 8733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 284:
#line 1905 "sql_parser.y" /* yacc.c:1646  */
    { 
			int lang = 0;
			dlist *f = L();
			char l = *(yyvsp[-1].sval);

			if (l == 'R' || l == 'r')
				lang = FUNC_LANG_R;
			else if (l == 'P' || l == 'p')
            {
                if (strcasecmp((yyvsp[-1].sval), "PYTHON_MAP") == 0) {
					lang = FUNC_LANG_MAP_PY;
                } else if (strcasecmp((yyvsp[-1].sval), "PYTHON3_MAP") == 0) {
                	lang = FUNC_LANG_MAP_PY3;
                } else if (strcasecmp((yyvsp[-1].sval), "PYTHON3") == 0) {
                	lang = FUNC_LANG_PY3;
                } else if (strcasecmp((yyvsp[-1].sval), "PYTHON2_MAP") == 0) {
                	lang = FUNC_LANG_MAP_PY2;
                } else if (strcasecmp((yyvsp[-1].sval), "PYTHON2") == 0) {
                	lang = FUNC_LANG_PY2;
                } else {
                	lang = FUNC_LANG_PY;
                }
            }
			else if (l == 'C' || l == 'c')
				lang = FUNC_LANG_C;
			else if (l == 'J' || l == 'j')
				lang = FUNC_LANG_J;
			else {
				char *msg = sql_message("Language name R, C, PYTHON[3], PYTHON[3]_MAP or J(avascript):expected, received '%c'", l);
				yyerror(m, msg);
				_DELETE(msg);
			}

			append_list(f, (yyvsp[-8].l));
			append_list(f, (yyvsp[-6].l));
			append_symbol(f, (yyvsp[-3].sym));
			append_list(f, NULL);
			append_list(f, append_string(L(), (yyvsp[0].sval)));
			append_int(f, F_AGGR);
			append_int(f, lang);
			append_int(f, (yyvsp[-10].bval));
			(yyval.sym) = _symbol_create_list( SQL_CREATE_FUNC, f ); }
#line 8780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 285:
#line 1951 "sql_parser.y" /* yacc.c:1646  */
    { dlist *f = L();
				append_list(f, (yyvsp[-6].l));
				append_list(f, (yyvsp[-4].l));
				append_symbol(f, NULL); /* no result */
				append_list(f, (yyvsp[0].l));
				append_list(f, NULL);
				append_int(f, F_PROC);
				append_int(f, FUNC_LANG_MAL);
				append_int(f, (yyvsp[-8].bval));
			  (yyval.sym) = _symbol_create_list( SQL_CREATE_FUNC, f ); }
#line 8795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 286:
#line 1964 "sql_parser.y" /* yacc.c:1646  */
    { dlist *f = L();
				append_list(f, (yyvsp[-4].l));
				append_list(f, (yyvsp[-2].l));
				append_symbol(f, NULL); /* no result */
				append_list(f, NULL); 
				append_list(f, (yyvsp[0].l));
				append_int(f, F_PROC);
				append_int(f, FUNC_LANG_SQL);
				append_int(f, (yyvsp[-6].bval));
			  (yyval.sym) = _symbol_create_list( SQL_CREATE_FUNC, f ); }
#line 8810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 287:
#line 1976 "sql_parser.y" /* yacc.c:1646  */
    { 
			int lang = 0;
			dlist *f = L();
			char l = *(yyvsp[-1].sval);
			/* other languages here if we ever get to it */
			if (l == 'P' || l == 'p')
            {
                lang = FUNC_LANG_PY;
            }
			else
				yyerror(m, sql_message("Language name P(ython) expected, received '%c'", l));

			append_list(f, (yyvsp[-6].l));
			append_list(f, (yyvsp[-4].l));
			append_symbol(f, NULL);
			append_list(f, NULL); 
			append_list(f, append_string(L(), (yyvsp[0].sval)));
			append_int(f, F_LOADER);
			append_int(f, lang);
			append_int(f, (yyvsp[-8].bval));
			(yyval.sym) = _symbol_create_list( SQL_CREATE_FUNC, f ); }
#line 8836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 288:
#line 2001 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = L(); append_symbol( (yyval.l), (yyvsp[0].sym)); }
#line 8842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 289:
#line 2005 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol((yyvsp[-3].l),(yyvsp[-2].sym)); }
#line 8848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 290:
#line 2009 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol((yyvsp[-3].l),(yyvsp[-2].sym)); }
#line 8854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 291:
#line 2024 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = L(); }
#line 8860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 292:
#line 2026 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol((yyvsp[-2].l),(yyvsp[-1].sym));}
#line 8866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 293:
#line 2030 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = L(); }
#line 8872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 294:
#line 2032 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol((yyvsp[-2].l),(yyvsp[-1].sym));}
#line 8878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 321:
#line 2080 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[0].sym); }
#line 8884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 322:
#line 2084 "sql_parser.y" /* yacc.c:1646  */
    {(yyval.sym) = _symbol_create_symbol(SQL_CALL, (yyvsp[0].sym));}
#line 8890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 323:
#line 2089 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L(); 
		  append_list( l, (yyvsp[-3].l));
		  append_list( l, (yyvsp[-1].l));
		  assert(0);
		  (yyval.sym) = _symbol_create_list( SQL_FUNC, l);
		}
#line 8901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 325:
#line 2100 "sql_parser.y" /* yacc.c:1646  */
    {(yyval.l) = L();}
#line 8907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 326:
#line 2101 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol( L(), (yyvsp[0].sym)); }
#line 8913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 327:
#line 2103 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol( (yyvsp[-2].l), (yyvsp[0].sym)); }
#line 8919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 328:
#line 2108 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_symbol(SQL_RETURN, (yyvsp[0].sym)); }
#line 8925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 331:
#line 2115 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_symbol(SQL_TABLE, (yyvsp[-1].sym)); }
#line 8931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 332:
#line 2120 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list(SQL_CASE,
		   append_list(
		    append_list(
		     append_symbol(
		      L(),(yyvsp[-4].sym)),(yyvsp[-3].l)),(yyvsp[-2].l))); }
#line 8941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 333:
#line 2126 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list(SQL_CASE,
		   append_list(
		    append_list(
		     L(),(yyvsp[-3].l)),(yyvsp[-2].l))); }
#line 8950 "y.tab.c" /* yacc.c:1646  */
    break;

  case 334:
#line 2134 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list( SQL_WHEN,
			   append_list(
			    append_symbol(
			     L(), (yyvsp[-2].sym)),(yyvsp[0].l))); }
#line 8959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 335:
#line 2142 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol( L(), (yyvsp[0].sym));}
#line 8965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 336:
#line 2144 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol( (yyvsp[-1].l), (yyvsp[0].sym)); }
#line 8971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 337:
#line 2149 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list( SQL_WHEN,
			   append_list(
			    append_symbol(
			     L(), (yyvsp[-2].sym)),(yyvsp[0].l))); }
#line 8980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 338:
#line 2157 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol( L(), (yyvsp[0].sym)); }
#line 8986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 339:
#line 2159 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol( (yyvsp[-1].l), (yyvsp[0].sym)); }
#line 8992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 340:
#line 2163 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = NULL; }
#line 8998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 341:
#line 2164 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[0].l); }
#line 9004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 342:
#line 2174 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
		  append_symbol(l, (yyvsp[-5].sym));
		  append_list(l, (yyvsp[-3].l));
		  append_symbol(l, (yyvsp[-2].sym));
		  (yyval.sym) = _symbol_create_list(SQL_IF, l);
		}
#line 9015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 343:
#line 2185 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = NULL; }
#line 9021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 344:
#line 2187 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list(SQL_ELSE, (yyvsp[0].l)); }
#line 9027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 345:
#line 2190 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
		  append_symbol(l, (yyvsp[-3].sym));
		  append_list(l, (yyvsp[-1].l));
		  append_symbol(l, (yyvsp[0].sym));
		  { (yyval.sym) = _symbol_create_list(SQL_IF, l); }
		}
#line 9038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 346:
#line 2204 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l;
		  char *label = (yyvsp[-7].sval)?(yyvsp[-7].sval):(yyvsp[0].sval);
		  if ((yyvsp[-7].sval) && (yyvsp[0].sval) && strcmp((yyvsp[-7].sval), (yyvsp[0].sval)) != 0) {
			(yyval.sym) = NULL;
			yyerror(m, "WHILE: labels should match");
			YYABORT;
		  }
 		  l = L();
		  append_symbol(l, (yyvsp[-5].sym)); /* condition */
		  append_list(l, (yyvsp[-3].l));	/* statements */
		  append_string(l, label);
		  (yyval.sym) = _symbol_create_list(SQL_WHILE, l);
		}
#line 9056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 347:
#line 2220 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = NULL; }
#line 9062 "y.tab.c" /* yacc.c:1646  */
    break;

  case 349:
#line 2225 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = NULL; }
#line 9068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 351:
#line 2231 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = L();
				  append_string((yyval.l), (yyvsp[-1].sval));
			  	  append_type((yyval.l), &(yyvsp[0].type));
				}
#line 9077 "y.tab.c" /* yacc.c:1646  */
    break;

  case 352:
#line 2236 "sql_parser.y" /* yacc.c:1646  */
    { 
				  append_string((yyval.l), (yyvsp[-1].sval));
			  	  append_type((yyval.l), &(yyvsp[0].type));
				}
#line 9086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 353:
#line 2244 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list(SQL_TABLE, (yyvsp[-1].l)); }
#line 9092 "y.tab.c" /* yacc.c:1646  */
    break;

  case 354:
#line 2246 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list(SQL_TYPE, append_type(L(),&(yyvsp[0].type))); }
#line 9098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 356:
#line 2251 "sql_parser.y" /* yacc.c:1646  */
    { dlist *vararg = L();
			  append_string(vararg, "*");
			  append_type(vararg, NULL);
			  (yyval.l) = append_list(L(), vararg); }
#line 9107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 357:
#line 2255 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = NULL; }
#line 9113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 358:
#line 2260 "sql_parser.y" /* yacc.c:1646  */
    { dlist *p = L();
			  append_string(p, (yyvsp[-1].sval));
			  append_type(p, &(yyvsp[0].type));
			  (yyval.l) = append_list((yyvsp[-3].l), p); }
#line 9122 "y.tab.c" /* yacc.c:1646  */
    break;

  case 359:
#line 2265 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
			  dlist *p = L();
			  append_string(p, (yyvsp[-1].sval));
			  append_type(p, &(yyvsp[0].type));
			  (yyval.l) = append_list(l, p); }
#line 9132 "y.tab.c" /* yacc.c:1646  */
    break;

  case 360:
#line 2315 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_list(l, (yyvsp[-6].l));
	  append_int(l, (yyvsp[-5].i_val));
	  append_symbol(l, (yyvsp[-4].sym));
	  append_list(l, (yyvsp[-2].l));
	  append_list(l, (yyvsp[-1].l));
	  append_list(l, (yyvsp[0].l));
	  (yyval.sym) = _symbol_create_list(SQL_CREATE_TRIGGER, l); 
	}
#line 9146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 361:
#line 2327 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 0; }
#line 9152 "y.tab.c" /* yacc.c:1646  */
    break;

  case 362:
#line 2328 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 1; }
#line 9158 "y.tab.c" /* yacc.c:1646  */
    break;

  case 363:
#line 2333 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list(SQL_INSERT, NULL); }
#line 9164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 364:
#line 2334 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list(SQL_DELETE, NULL); }
#line 9170 "y.tab.c" /* yacc.c:1646  */
    break;

  case 365:
#line 2335 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list(SQL_UPDATE, NULL); }
#line 9176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 366:
#line 2336 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list(SQL_UPDATE, (yyvsp[0].l)); }
#line 9182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 367:
#line 2340 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = NULL; }
#line 9188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 368:
#line 2341 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[0].l); }
#line 9194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 369:
#line 2345 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_list(L(), (yyvsp[0].l)); }
#line 9200 "y.tab.c" /* yacc.c:1646  */
    break;

  case 370:
#line 2347 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_list((yyvsp[-1].l), (yyvsp[0].l)); }
#line 9206 "y.tab.c" /* yacc.c:1646  */
    break;

  case 371:
#line 2352 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_string(append_int(L(), 0), (yyvsp[0].sval)); }
#line 9212 "y.tab.c" /* yacc.c:1646  */
    break;

  case 372:
#line 2353 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_string(append_int(L(), 1), (yyvsp[0].sval)); }
#line 9218 "y.tab.c" /* yacc.c:1646  */
    break;

  case 373:
#line 2354 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_string(append_int(L(), 0), (yyvsp[0].sval)); }
#line 9224 "y.tab.c" /* yacc.c:1646  */
    break;

  case 374:
#line 2355 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_string(append_int(L(), 1), (yyvsp[0].sval)); }
#line 9230 "y.tab.c" /* yacc.c:1646  */
    break;

  case 379:
#line 2370 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = L();
	  append_int((yyval.l), (yyvsp[-2].i_val));
	  append_symbol((yyval.l), (yyvsp[-1].sym));
	  append_list((yyval.l), (yyvsp[0].l));
	}
#line 9240 "y.tab.c" /* yacc.c:1646  */
    break;

  case 380:
#line 2377 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 1; }
#line 9246 "y.tab.c" /* yacc.c:1646  */
    break;

  case 381:
#line 2378 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = (yyvsp[0].i_val); }
#line 9252 "y.tab.c" /* yacc.c:1646  */
    break;

  case 382:
#line 2382 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 0; }
#line 9258 "y.tab.c" /* yacc.c:1646  */
    break;

  case 383:
#line 2383 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 1; }
#line 9264 "y.tab.c" /* yacc.c:1646  */
    break;

  case 384:
#line 2387 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = NULL; }
#line 9270 "y.tab.c" /* yacc.c:1646  */
    break;

  case 385:
#line 2388 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[-1].sym); }
#line 9276 "y.tab.c" /* yacc.c:1646  */
    break;

  case 386:
#line 2393 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol(L(), (yyvsp[0].sym)); }
#line 9282 "y.tab.c" /* yacc.c:1646  */
    break;

  case 387:
#line 2396 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[-1].l); }
#line 9288 "y.tab.c" /* yacc.c:1646  */
    break;

  case 388:
#line 2401 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_list(l, (yyvsp[-1].l) );	
	  append_list(l, (yyvsp[0].l) );
	  append_int(l, F_FUNC );
	  (yyval.l) = l; }
#line 9298 "y.tab.c" /* yacc.c:1646  */
    break;

  case 389:
#line 2407 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_list(l, (yyvsp[-1].l) );	
	  append_list(l, (yyvsp[0].l) );
	  append_int(l, F_FILT );
	  (yyval.l) = l; }
#line 9308 "y.tab.c" /* yacc.c:1646  */
    break;

  case 390:
#line 2413 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_list(l, (yyvsp[-1].l) );	
	  append_list(l, (yyvsp[0].l) );
	  append_int(l, F_AGGR );
	  (yyval.l) = l; }
#line 9318 "y.tab.c" /* yacc.c:1646  */
    break;

  case 391:
#line 2419 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_list(l, (yyvsp[-1].l) );	
	  append_list(l, (yyvsp[0].l) );
	  append_int(l, F_PROC );
	  (yyval.l) = l; }
#line 9328 "y.tab.c" /* yacc.c:1646  */
    break;

  case 392:
#line 2425 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_list(l, (yyvsp[-1].l) );	
	  append_list(l, (yyvsp[0].l) );
	  append_int(l, F_LOADER );
	  (yyval.l) = l; }
#line 9338 "y.tab.c" /* yacc.c:1646  */
    break;

  case 393:
#line 2434 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_list(l, (yyvsp[-1].l) );
	  append_int(l, (yyvsp[0].i_val) );
	  append_int(l, (yyvsp[-2].bval));
	  (yyval.sym) = _symbol_create_list( SQL_DROP_TABLE, l ); }
#line 9348 "y.tab.c" /* yacc.c:1646  */
    break;

  case 394:
#line 2440 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = (yyvsp[-1].l);
	  append_int(l, 0 ); /* not all */
	  append_int(l, (yyvsp[0].i_val) );
	  (yyval.sym) = _symbol_create_list( SQL_DROP_FUNC, l ); }
#line 9357 "y.tab.c" /* yacc.c:1646  */
    break;

  case 395:
#line 2445 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_list(l, (yyvsp[-1].l) );
	  append_list(l, NULL );
	  append_int(l, F_FUNC );
	  append_int(l, 1 );
	  append_int(l, (yyvsp[0].i_val) );
	  (yyval.sym) = _symbol_create_list( SQL_DROP_FUNC, l ); }
#line 9369 "y.tab.c" /* yacc.c:1646  */
    break;

  case 396:
#line 2453 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_list(l, (yyvsp[-1].l) );
	  append_list(l, NULL );
	  append_int(l, F_FILT );
	  append_int(l, 1 );
	  append_int(l, (yyvsp[0].i_val) );
	  (yyval.sym) = _symbol_create_list( SQL_DROP_FUNC, l ); }
#line 9381 "y.tab.c" /* yacc.c:1646  */
    break;

  case 397:
#line 2461 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_list(l, (yyvsp[-1].l) );
	  append_list(l, NULL );
	  append_int(l, F_AGGR );
	  append_int(l, 1 );
	  append_int(l, (yyvsp[0].i_val) );
	  (yyval.sym) = _symbol_create_list( SQL_DROP_FUNC, l ); }
#line 9393 "y.tab.c" /* yacc.c:1646  */
    break;

  case 398:
#line 2469 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_list(l, (yyvsp[-1].l) );
	  append_list(l, NULL );
	  append_int(l, F_PROC );
	  append_int(l, 1 );
	  append_int(l, (yyvsp[0].i_val) );
	  (yyval.sym) = _symbol_create_list( SQL_DROP_FUNC, l ); }
#line 9405 "y.tab.c" /* yacc.c:1646  */
    break;

  case 399:
#line 2477 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_list(l, (yyvsp[-1].l) );
	  append_list(l, NULL );
	  append_int(l, F_LOADER );
	  append_int(l, 1 );
	  append_int(l, (yyvsp[0].i_val) );
	  (yyval.sym) = _symbol_create_list( SQL_DROP_FUNC, l ); }
#line 9417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 400:
#line 2485 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_list(l, (yyvsp[-1].l) );
	  append_int(l, (yyvsp[0].i_val) );
	  append_int(l, (yyvsp[-2].bval) );
	  (yyval.sym) = _symbol_create_list( SQL_DROP_VIEW, l ); }
#line 9427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 401:
#line 2491 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_list(l, (yyvsp[-1].l) );
	  append_int(l, (yyvsp[0].i_val) );
	  (yyval.sym) = _symbol_create_list( SQL_DROP_TYPE, l ); }
#line 9436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 402:
#line 2495 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create( SQL_DROP_ROLE, (yyvsp[0].sval) ); }
#line 9442 "y.tab.c" /* yacc.c:1646  */
    break;

  case 403:
#line 2496 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create( SQL_DROP_USER, (yyvsp[0].sval) ); }
#line 9448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 404:
#line 2497 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list( SQL_DROP_INDEX, (yyvsp[0].l) ); }
#line 9454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 405:
#line 2498 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list( SQL_DROP_TRIGGER, (yyvsp[0].l) ); }
#line 9460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 406:
#line 2502 "sql_parser.y" /* yacc.c:1646  */
    {(yyval.l) = NULL;}
#line 9466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 407:
#line 2503 "sql_parser.y" /* yacc.c:1646  */
    {(yyval.l) = (yyvsp[-1].l);}
#line 9472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 408:
#line 2504 "sql_parser.y" /* yacc.c:1646  */
    {(yyval.l) = L(); }
#line 9478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 409:
#line 2508 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
				  append_type(l, &(yyvsp[0].type) );
				  (yyval.l)= l; }
#line 9486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 410:
#line 2511 "sql_parser.y" /* yacc.c:1646  */
    { append_type((yyvsp[0].l), &(yyvsp[-2].type));
				  (yyval.l) = (yyvsp[0].l); }
#line 9493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 411:
#line 2516 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 0; }
#line 9499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 412:
#line 2517 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 0; }
#line 9505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 413:
#line 2518 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 1; }
#line 9511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 420:
#line 2537 "sql_parser.y" /* yacc.c:1646  */
    {
	  (yyval.sym) = (yyvsp[0].sym);
	  m->type = Q_TRANS;					}
#line 9519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 421:
#line 2544 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_int( TR_COMMIT, (yyvsp[0].bval));  }
#line 9525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 422:
#line 2546 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create( TR_SAVEPOINT, (yyvsp[0].sval)); }
#line 9531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 423:
#line 2548 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create( TR_RELEASE, (yyvsp[0].sval)); }
#line 9537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 424:
#line 2550 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list( TR_ROLLBACK,
		   append_string(
			append_int(L(), (yyvsp[-1].bval)), (yyvsp[0].sval) )); }
#line 9545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 425:
#line 2554 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_int( TR_START, (yyvsp[0].i_val)); }
#line 9551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 426:
#line 2556 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_int( TR_MODE, (yyvsp[0].i_val)); }
#line 9557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 427:
#line 2558 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_int( TR_MODE, (yyvsp[0].i_val)); }
#line 9563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 428:
#line 2562 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = tr_none; }
#line 9569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 430:
#line 2568 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = (yyvsp[0].i_val); }
#line 9575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 431:
#line 2570 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = ((yyvsp[-2].i_val) | (yyvsp[0].i_val)); }
#line 9581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 432:
#line 2575 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = tr_readonly; }
#line 9587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 433:
#line 2576 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = tr_writable; }
#line 9593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 434:
#line 2577 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = tr_serializable; }
#line 9599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 435:
#line 2578 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = tr_none; /* not supported */ }
#line 9605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 440:
#line 2589 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = 0; }
#line 9611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 441:
#line 2590 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = 0; }
#line 9617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 442:
#line 2594 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = 1; }
#line 9623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 443:
#line 2595 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = 0; }
#line 9629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 444:
#line 2596 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = 0; }
#line 9635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 445:
#line 2600 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = NULL; }
#line 9641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 446:
#line 2601 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[0].sval); }
#line 9647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 447:
#line 2606 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_list(l, (yyvsp[-10].l));
	  append_list(l, (yyvsp[-9].l));
	  append_list(l, (yyvsp[-7].l));
	  append_list(l, (yyvsp[-6].l));
	  append_list(l, (yyvsp[-5].l));
	  append_list(l, (yyvsp[-12].l));
	  append_string(l, (yyvsp[-4].sval));
	  append_int(l, (yyvsp[-3].bval));
	  append_int(l, (yyvsp[-2].bval));
	  append_int(l, (yyvsp[-1].bval));
	  append_list(l, (yyvsp[0].l));
	  (yyval.sym) = _symbol_create_list( SQL_COPYFROM, l ); }
#line 9665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 448:
#line 2620 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_list(l, (yyvsp[-9].l));
	  append_list(l, (yyvsp[-8].l));
	  append_list(l, NULL);
	  append_list(l, (yyvsp[-5].l));
	  append_list(l, (yyvsp[-4].l));
	  append_list(l, (yyvsp[-11].l));
	  append_string(l, (yyvsp[-3].sval));
	  append_int(l, (yyvsp[-2].bval));
	  append_int(l, (yyvsp[-1].bval));
	  append_int(l, (yyvsp[0].bval));
	  append_list(l, NULL);
	  (yyval.sym) = _symbol_create_list( SQL_COPYFROM, l ); }
#line 9683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 449:
#line 2634 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_list(l, (yyvsp[-2].l));
	  append_symbol(l, (yyvsp[0].sym));
	  (yyval.sym) = _symbol_create_list( SQL_COPYLOADER, l ); }
#line 9692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 450:
#line 2639 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  if ((yyvsp[-7].l) != NULL) {
	  	yyerror(m, "COPY INTO: cannot pass number of records when using binary COPY INTO");
		YYABORT;
	  }
	  append_list(l, (yyvsp[-4].l));
	  append_list(l, (yyvsp[-3].l));
	  append_list(l, (yyvsp[-1].l));
	  append_int(l, (yyvsp[0].bval));
	  (yyval.sym) = _symbol_create_list( SQL_BINCOPYFROM, l ); }
#line 9707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 451:
#line 2650 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_symbol(l, (yyvsp[-4].sym));
	  append_string(l, (yyvsp[-2].sval));
	  append_list(l, (yyvsp[-1].l));
	  append_string(l, (yyvsp[0].sval));
	  (yyval.sym) = _symbol_create_list( SQL_COPYTO, l ); }
#line 9718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 452:
#line 2657 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_symbol(l, (yyvsp[-4].sym));
	  append_string(l, NULL);
	  append_list(l, (yyvsp[-1].l));
	  append_string(l, (yyvsp[0].sval));
	  (yyval.sym) = _symbol_create_list( SQL_COPYTO, l ); }
#line 9729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 453:
#line 2668 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = NULL; }
#line 9735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 454:
#line 2669 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[-1].l); }
#line 9741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 455:
#line 2674 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_lng(L(), (yyvsp[0].l_val)); }
#line 9747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 456:
#line 2676 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_lng((yyvsp[-2].l), (yyvsp[0].l_val)); }
#line 9753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 457:
#line 2681 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = NULL; }
#line 9759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 458:
#line 2682 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[-1].l); }
#line 9765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 459:
#line 2686 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_list(L(), (yyvsp[0].l)); }
#line 9771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 460:
#line 2687 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_list((yyvsp[-2].l), (yyvsp[0].l)); }
#line 9777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 461:
#line 2692 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
			  append_string(l, (yyvsp[0].sval) );
			  (yyval.l) = l; }
#line 9785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 462:
#line 2696 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
			  append_string(l, (yyvsp[-1].sval) );
			  append_string(l, (yyvsp[0].sval) );
			  (yyval.l) = l; }
#line 9794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 463:
#line 2704 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
				  append_string(l, sa_strdup(SA, "|"));
				  append_string(l, sa_strdup(SA, "\\n"));
				  (yyval.l) = l; }
#line 9803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 464:
#line 2709 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
				  append_string(l, (yyvsp[0].sval));
				  append_string(l, sa_strdup(SA, "\\n"));
				  (yyval.l) = l; }
#line 9812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 465:
#line 2714 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
				  append_string(l, (yyvsp[-2].sval));
				  append_string(l, (yyvsp[0].sval));
				  (yyval.l) = l; }
#line 9821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 466:
#line 2719 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
				  append_string(l, (yyvsp[-4].sval));
				  append_string(l, (yyvsp[-2].sval));
				  append_string(l, sql2str((yyvsp[0].sval)));
				  (yyval.l) = l; }
#line 9831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 467:
#line 2727 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = NULL; }
#line 9837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 468:
#line 2728 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = NULL; }
#line 9843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 469:
#line 2732 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = NULL; }
#line 9849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 470:
#line 2733 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_lng(append_lng(L(), (yyvsp[-1].l_val)), 0); }
#line 9855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 471:
#line 2734 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_lng(append_lng(L(), -1), (yyvsp[0].l_val)); }
#line 9861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 472:
#line 2736 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_lng(append_lng(L(), (yyvsp[-3].l_val)), (yyvsp[-1].l_val)); }
#line 9867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 473:
#line 2738 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_lng(append_lng(L(), (yyvsp[-3].l_val)), (yyvsp[0].l_val)); }
#line 9873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 474:
#line 2742 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = NULL; }
#line 9879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 475:
#line 2743 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[0].sval); }
#line 9885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 476:
#line 2747 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = FALSE; }
#line 9891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 477:
#line 2748 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = TRUE; }
#line 9897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 478:
#line 2752 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = FALSE; }
#line 9903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 479:
#line 2753 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = TRUE; }
#line 9909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 480:
#line 2757 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = TRUE; }
#line 9915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 481:
#line 2758 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = FALSE; }
#line 9921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 482:
#line 2762 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[0].l); }
#line 9927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 483:
#line 2763 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[-1].l); }
#line 9933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 484:
#line 2767 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_string(L(), (yyvsp[0].sval)); }
#line 9939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 485:
#line 2769 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_string((yyvsp[-2].l), (yyvsp[0].sval)); }
#line 9945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 486:
#line 2775 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_list(l, (yyvsp[-1].l));
	  append_symbol(l, (yyvsp[0].sym));
	  (yyval.sym) = _symbol_create_list( SQL_DELETE, l ); }
#line 9954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 487:
#line 2784 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_list(l, (yyvsp[-4].l));
	  append_list(l, (yyvsp[-2].l));
	  append_symbol(l, (yyvsp[-1].sym));
	  append_symbol(l, (yyvsp[0].sym));
	  (yyval.sym) = _symbol_create_list( SQL_UPDATE, l ); }
#line 9965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 488:
#line 2826 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_list(l, (yyvsp[-1].l));
	  append_list(l, NULL);
	  append_symbol(l, (yyvsp[0].sym));
	  (yyval.sym) = _symbol_create_list( SQL_INSERT, l ); }
#line 9975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 489:
#line 2834 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_list(l, (yyvsp[-2].l));
	  append_list(l, (yyvsp[-1].l));
	  append_symbol(l, (yyvsp[0].sym));
	  (yyval.sym) = _symbol_create_list( SQL_INSERT, l ); }
#line 9985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 490:
#line 2843 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list( SQL_VALUES, L()); }
#line 9991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 491:
#line 2845 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list( SQL_VALUES, L()); }
#line 9997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 492:
#line 2847 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list( SQL_VALUES, (yyvsp[0].l)); }
#line 10003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 494:
#line 2853 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_list(L(), (yyvsp[-1].l)); }
#line 10009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 495:
#line 2855 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_list((yyvsp[-4].l), (yyvsp[-1].l)); }
#line 10015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 496:
#line 2859 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol(L(), (yyvsp[0].sym)); }
#line 10021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 497:
#line 2861 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol((yyvsp[-2].l), (yyvsp[0].sym)); }
#line 10027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 498:
#line 2865 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol(L(), (yyvsp[0].sym)); }
#line 10033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 499:
#line 2867 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol((yyvsp[-2].l), (yyvsp[0].sym)); }
#line 10039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 500:
#line 2872 "sql_parser.y" /* yacc.c:1646  */
    { 
	  if (m->emode == m_normal && m->caching) {
		/* replace by argument */
		atom *a = atom_general(SA, sql_bind_localtype("void"), NULL);

		sql_add_arg( m, a);
		(yyval.sym) = _symbol_create_list( SQL_COLUMN,
			append_int(L(), m->argc-1));
	   } else {
		(yyval.sym) = _symbol_create(SQL_NULL, NULL );
	   }
	}
#line 10056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 503:
#line 2893 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create(SQL_DEFAULT, NULL ); }
#line 10062 "y.tab.c" /* yacc.c:1646  */
    break;

  case 506:
#line 2902 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = FALSE; }
#line 10068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 507:
#line 2903 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = FALSE; }
#line 10074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 508:
#line 2904 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = TRUE; }
#line 10080 "y.tab.c" /* yacc.c:1646  */
    break;

  case 509:
#line 2908 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol(L(), (yyvsp[0].sym) ); }
#line 10086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 510:
#line 2910 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol((yyvsp[-2].l), (yyvsp[0].sym) ); }
#line 10092 "y.tab.c" /* yacc.c:1646  */
    break;

  case 511:
#line 2914 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create(SQL_DEFAULT, NULL ); }
#line 10098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 512:
#line 2919 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_symbol(l, (yyvsp[0].sym));
	  append_string(l, (yyvsp[-2].sval));
	  (yyval.sym) = _symbol_create_list( SQL_ASSIGN, l); }
#line 10107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 513:
#line 2924 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_symbol(l, (yyvsp[0].sym) );
	  append_string(l, (yyvsp[-2].sval));
	  (yyval.sym) = _symbol_create_list( SQL_ASSIGN, l); }
#line 10116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 514:
#line 2929 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_symbol(l, (yyvsp[0].sym));
	  append_list(l, (yyvsp[-2].l));
	  (yyval.sym) = _symbol_create_list( SQL_ASSIGN, l ); }
#line 10125 "y.tab.c" /* yacc.c:1646  */
    break;

  case 515:
#line 2936 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = NULL; }
#line 10131 "y.tab.c" /* yacc.c:1646  */
    break;

  case 516:
#line 2937 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[0].sym); }
#line 10137 "y.tab.c" /* yacc.c:1646  */
    break;

  case 517:
#line 2944 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[-1].sym); }
#line 10143 "y.tab.c" /* yacc.c:1646  */
    break;

  case 518:
#line 2946 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_symbol(l, (yyvsp[-3].sym));
	  append_symbol(l, (yyvsp[0].sym));
	  (yyval.sym) = _symbol_create_list( SQL_CROSS, l); }
#line 10152 "y.tab.c" /* yacc.c:1646  */
    break;

  case 519:
#line 2951 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_symbol(l, (yyvsp[-3].sym));
	  append_int(l, 0);
	  append_int(l, 4);
	  append_symbol(l, (yyvsp[-1].sym));
	  append_symbol(l, (yyvsp[0].sym));
	  (yyval.sym) = _symbol_create_list( SQL_UNIONJOIN, l); }
#line 10164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 520:
#line 2959 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_symbol(l, (yyvsp[-4].sym));
	  append_int(l, 0);
	  append_int(l, (yyvsp[-3].i_val));
	  append_symbol(l, (yyvsp[-1].sym));
	  append_symbol(l, (yyvsp[0].sym));
	  (yyval.sym) = _symbol_create_list( SQL_JOIN, l); }
#line 10176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 521:
#line 2967 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_symbol(l, (yyvsp[-4].sym));
	  append_int(l, 1);
	  append_int(l, (yyvsp[-2].i_val));
	  append_symbol(l, (yyvsp[0].sym));
	  append_symbol(l, NULL);
	  (yyval.sym) = _symbol_create_list( SQL_JOIN, l); }
#line 10188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 522:
#line 2977 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 0; }
#line 10194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 523:
#line 2978 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 0; }
#line 10200 "y.tab.c" /* yacc.c:1646  */
    break;

  case 524:
#line 2979 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 1 + (yyvsp[-1].i_val); }
#line 10206 "y.tab.c" /* yacc.c:1646  */
    break;

  case 525:
#line 2983 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 0; }
#line 10212 "y.tab.c" /* yacc.c:1646  */
    break;

  case 526:
#line 2984 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 0; }
#line 10218 "y.tab.c" /* yacc.c:1646  */
    break;

  case 527:
#line 2988 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 0; }
#line 10224 "y.tab.c" /* yacc.c:1646  */
    break;

  case 528:
#line 2989 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 1; }
#line 10230 "y.tab.c" /* yacc.c:1646  */
    break;

  case 529:
#line 2990 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 2; }
#line 10236 "y.tab.c" /* yacc.c:1646  */
    break;

  case 530:
#line 2994 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[0].sym); }
#line 10242 "y.tab.c" /* yacc.c:1646  */
    break;

  case 531:
#line 2996 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list( SQL_USING, (yyvsp[0].l)); }
#line 10248 "y.tab.c" /* yacc.c:1646  */
    break;

  case 533:
#line 3020 "sql_parser.y" /* yacc.c:1646  */
    {
		dlist *l = L();
	  	append_list(l, (yyvsp[-1].l));
	  	append_symbol(l, (yyvsp[0].sym));
	  	(yyval.sym) = _symbol_create_list( SQL_WITH, l ); 
	}
#line 10259 "y.tab.c" /* yacc.c:1646  */
    break;

  case 534:
#line 3029 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol((yyvsp[-2].l), (yyvsp[0].sym)); }
#line 10265 "y.tab.c" /* yacc.c:1646  */
    break;

  case 535:
#line 3030 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol(L(), (yyvsp[0].sym)); }
#line 10271 "y.tab.c" /* yacc.c:1646  */
    break;

  case 536:
#line 3035 "sql_parser.y" /* yacc.c:1646  */
    {  dlist *l = L();
	  append_list(l, append_string(L(), (yyvsp[-3].sval)));
	  append_list(l, (yyvsp[-2].l));
	  append_symbol(l, (yyvsp[0].sym));
	  append_int(l, FALSE);	/* no with check */
	  append_int(l, FALSE);	/* inlined view  (ie not persistent) */
	  (yyval.sym) = _symbol_create_list( SQL_CREATE_VIEW, l ); 
	}
#line 10284 "y.tab.c" /* yacc.c:1646  */
    break;

  case 540:
#line 3058 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = newSelectNode( SA, (yyvsp[-2].bval), (yyvsp[-1].l), NULL,
		(yyvsp[0].l)->h->data.sym,
		(yyvsp[0].l)->h->next->data.sym,
		(yyvsp[0].l)->h->next->next->data.sym,
		(yyvsp[0].l)->h->next->next->next->data.sym,
		NULL, NULL, NULL, NULL, NULL);
	}
#line 10296 "y.tab.c" /* yacc.c:1646  */
    break;

  case 541:
#line 3069 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = newSelectNode( SA, (yyvsp[-4].bval), (yyvsp[-3].l), (yyvsp[-1].l),
		(yyvsp[0].l)->h->data.sym,
		(yyvsp[0].l)->h->next->data.sym,
		(yyvsp[0].l)->h->next->next->data.sym,
		(yyvsp[0].l)->h->next->next->next->data.sym,
		NULL, NULL, NULL, NULL, NULL);
	}
#line 10308 "y.tab.c" /* yacc.c:1646  */
    break;

  case 542:
#line 3080 "sql_parser.y" /* yacc.c:1646  */
    { 
	  (yyval.sym) = (yyvsp[-4].sym);
	  if ((yyvsp[-3].sym) || (yyvsp[-2].sym) || (yyvsp[-1].sym) || (yyvsp[0].sym)) {
	  	if ((yyvsp[-4].sym) != NULL &&
		    ((yyvsp[-4].sym)->token == SQL_SELECT ||
		     (yyvsp[-4].sym)->token == SQL_UNION  ||
		     (yyvsp[-4].sym)->token == SQL_EXCEPT ||
		     (yyvsp[-4].sym)->token == SQL_INTERSECT)) {
			if ((yyvsp[-4].sym)->token == SQL_SELECT) {
	 			SelectNode *s = (SelectNode*)(yyvsp[-4].sym);
	
	  			s -> orderby = (yyvsp[-3].sym);
	  			s -> limit = (yyvsp[-2].sym);
	  			s -> offset = (yyvsp[-1].sym);
	  			s -> sample = (yyvsp[0].sym);
			} else { /* Add extra select * from .. in case of UNION, EXCEPT, INTERSECT */
				(yyval.sym) = newSelectNode( 
					SA, 0, 
					append_symbol(L(), _symbol_create_list(SQL_TABLE, append_string(append_string(L(),NULL),NULL))), NULL,
					_symbol_create_list( SQL_FROM, append_symbol(L(), (yyvsp[-4].sym))), NULL, NULL, NULL, (yyvsp[-3].sym), _symbol_create_list(SQL_NAME, append_list(append_string(L(),"inner"),NULL)), (yyvsp[-2].sym), (yyvsp[-1].sym), (yyvsp[0].sym));
			}
	  	} else {
			yyerror(m, "missing SELECT operator");
			YYABORT;
	  	}
	 } 
	}
#line 10340 "y.tab.c" /* yacc.c:1646  */
    break;

  case 543:
#line 3110 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_string(L(), (yyvsp[0].sval)); }
#line 10346 "y.tab.c" /* yacc.c:1646  */
    break;

  case 544:
#line 3112 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_string((yyvsp[-2].l), (yyvsp[0].sval)); }
#line 10352 "y.tab.c" /* yacc.c:1646  */
    break;

  case 546:
#line 3122 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_symbol(l, (yyvsp[-4].sym));
	  append_int(l, (yyvsp[-2].bval));
	  append_list(l, (yyvsp[-1].l));
	  append_symbol(l, (yyvsp[0].sym));
	  (yyval.sym) = _symbol_create_list( SQL_UNION, l); }
#line 10363 "y.tab.c" /* yacc.c:1646  */
    break;

  case 547:
#line 3131 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_symbol(l, (yyvsp[-4].sym));
	  append_int(l, (yyvsp[-2].bval));
	  append_list(l, (yyvsp[-1].l));
	  append_symbol(l, (yyvsp[0].sym));
	  (yyval.sym) = _symbol_create_list( SQL_EXCEPT, l); }
#line 10374 "y.tab.c" /* yacc.c:1646  */
    break;

  case 548:
#line 3140 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_symbol(l, (yyvsp[-4].sym));
	  append_int(l, (yyvsp[-2].bval));
	  append_list(l, (yyvsp[-1].l));
	  append_symbol(l, (yyvsp[0].sym));
	  (yyval.sym) = _symbol_create_list( SQL_INTERSECT, l); }
#line 10385 "y.tab.c" /* yacc.c:1646  */
    break;

  case 549:
#line 3146 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[-1].sym); }
#line 10391 "y.tab.c" /* yacc.c:1646  */
    break;

  case 551:
#line 3151 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = TRUE; }
#line 10397 "y.tab.c" /* yacc.c:1646  */
    break;

  case 552:
#line 3152 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = FALSE; }
#line 10403 "y.tab.c" /* yacc.c:1646  */
    break;

  case 553:
#line 3153 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = TRUE; }
#line 10409 "y.tab.c" /* yacc.c:1646  */
    break;

  case 554:
#line 3158 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = NULL; }
#line 10415 "y.tab.c" /* yacc.c:1646  */
    break;

  case 555:
#line 3160 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = L(); }
#line 10421 "y.tab.c" /* yacc.c:1646  */
    break;

  case 556:
#line 3162 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[-1].l); }
#line 10427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 558:
#line 3172 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = L();
	  append_symbol((yyval.l), (yyvsp[-3].sym));
	  append_symbol((yyval.l), (yyvsp[-2].sym));
	  append_symbol((yyval.l), (yyvsp[-1].sym));
	  append_symbol((yyval.l), (yyvsp[0].sym)); }
#line 10437 "y.tab.c" /* yacc.c:1646  */
    break;

  case 559:
#line 3180 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = NULL; }
#line 10443 "y.tab.c" /* yacc.c:1646  */
    break;

  case 560:
#line 3181 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list( SQL_FROM, (yyvsp[0].l)); }
#line 10449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 561:
#line 3185 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol(L(), (yyvsp[0].sym)); }
#line 10455 "y.tab.c" /* yacc.c:1646  */
    break;

  case 562:
#line 3187 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol((yyvsp[-2].l), (yyvsp[0].sym)); }
#line 10461 "y.tab.c" /* yacc.c:1646  */
    break;

  case 563:
#line 3191 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
		  		  append_list(l, (yyvsp[-1].l));
		  	  	  append_symbol(l, (yyvsp[0].sym));
		  		  (yyval.sym) = _symbol_create_list(SQL_NAME, l); }
#line 10470 "y.tab.c" /* yacc.c:1646  */
    break;

  case 564:
#line 3196 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
		  		  append_symbol(l, (yyvsp[-1].sym));
		  	  	  append_symbol(l, (yyvsp[0].sym));
		  	  	  append_int(l, 0);
		  		  (yyval.sym) = _symbol_create_list(SQL_TABLE, l); }
#line 10480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 565:
#line 3202 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
		  		  append_symbol(l, (yyvsp[-1].sym));
		  	  	  append_symbol(l, (yyvsp[0].sym));
		  	  	  append_int(l, 1);
		  		  (yyval.sym) = _symbol_create_list(SQL_TABLE, l); }
#line 10490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 566:
#line 3208 "sql_parser.y" /* yacc.c:1646  */
    {
				  (yyval.sym) = (yyvsp[-1].sym);
				  if ((yyval.sym)->token == SQL_SELECT) {
				  	SelectNode *sn = (SelectNode*)(yyvsp[-1].sym);
				  	sn->name = (yyvsp[0].sym);
				  } else {
				  	append_symbol((yyvsp[-1].sym)->data.lval, (yyvsp[0].sym));
				  }
				}
#line 10504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 567:
#line 3218 "sql_parser.y" /* yacc.c:1646  */
    {
				  (yyval.sym) = (yyvsp[-1].sym);
				  if ((yyval.sym)->token == SQL_SELECT) {
				  	SelectNode *sn = (SelectNode*)(yyvsp[-1].sym);
				  	sn->name = (yyvsp[0].sym);
					sn->lateral = 1;
				  } else {
				  	append_symbol((yyvsp[-1].sym)->data.lval, (yyvsp[0].sym));
	  				append_int((yyvsp[-1].sym)->data.lval, 1);
				  }
				}
#line 10520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 568:
#line 3230 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = NULL;
				  yyerror(m, "subquery table reference needs alias, use AS xxx");
				  YYABORT;
				}
#line 10529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 569:
#line 3234 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[0].sym);
				  append_symbol((yyvsp[0].sym)->data.lval, NULL); }
#line 10536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 570:
#line 3238 "sql_parser.y" /* yacc.c:1646  */
    { m->caching = 0; }
#line 10542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 571:
#line 3240 "sql_parser.y" /* yacc.c:1646  */
    {
		dlist *op = L();

 	  	append_symbol(op, (yyvsp[-2].sym));
		append_symbol(op, (yyvsp[0].sym));
		(yyval.sym) = _symbol_create_list(SQL_TABLE_OPERATOR, op); 
	}
#line 10554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 572:
#line 3251 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
		  		  append_string(l, (yyvsp[-3].sval));
		  	  	  append_list(l, (yyvsp[-1].l));
		  		  (yyval.sym) = _symbol_create_list(SQL_NAME, l); }
#line 10563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 573:
#line 3256 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
		  		  append_string(l, (yyvsp[0].sval));
		  	  	  append_list(l, NULL);
		  		  (yyval.sym) = _symbol_create_list(SQL_NAME, l); }
#line 10572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 574:
#line 3261 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
		  		  append_string(l, (yyvsp[-3].sval));
		  	  	  append_list(l, (yyvsp[-1].l));
		  		  (yyval.sym) = _symbol_create_list(SQL_NAME, l); }
#line 10581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 575:
#line 3266 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
		  		  append_string(l, (yyvsp[0].sval));
		  	  	  append_list(l, NULL);
		  		  (yyval.sym) = _symbol_create_list(SQL_NAME, l); }
#line 10590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 576:
#line 3273 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = NULL; }
#line 10596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 577:
#line 3274 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[0].sym); }
#line 10602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 578:
#line 3278 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = NULL; }
#line 10608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 579:
#line 3279 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list( SQL_GROUPBY, (yyvsp[0].l) );}
#line 10614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 580:
#line 3283 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol(L(),
			       _symbol_create_list(SQL_COLUMN,(yyvsp[0].l))); }
#line 10621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 581:
#line 3286 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol( (yyvsp[-2].l),
			       _symbol_create_list(SQL_COLUMN,(yyvsp[0].l))); }
#line 10628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 582:
#line 3291 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = NULL; }
#line 10634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 583:
#line 3292 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[0].sym); }
#line 10640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 584:
#line 3298 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
		  append_symbol(l, (yyvsp[-2].sym));
		  append_symbol(l, (yyvsp[0].sym));
		  (yyval.sym) = _symbol_create_list(SQL_OR, l ); }
#line 10649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 585:
#line 3302 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[0].sym); }
#line 10655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 586:
#line 3307 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
		  append_symbol(l, (yyvsp[-2].sym));
		  append_symbol(l, (yyvsp[0].sym));
		  (yyval.sym) = _symbol_create_list(SQL_AND, l ); }
#line 10664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 587:
#line 3311 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[0].sym); }
#line 10670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 588:
#line 3315 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = NULL; }
#line 10676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 589:
#line 3317 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list( SQL_ORDERBY, (yyvsp[0].l)); }
#line 10682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 590:
#line 3321 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = NULL; }
#line 10688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 591:
#line 3322 "sql_parser.y" /* yacc.c:1646  */
    { 
		  	  sql_subtype *t = sql_bind_localtype("lng");
			  (yyval.sym) = _newAtomNode( atom_int(SA, t, (yyvsp[0].l_val))); 
			}
#line 10697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 592:
#line 3326 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[0].sym); }
#line 10703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 593:
#line 3330 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = NULL; }
#line 10709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 594:
#line 3331 "sql_parser.y" /* yacc.c:1646  */
    { 
		  	  sql_subtype *t = sql_bind_localtype("lng");
			  (yyval.sym) = _newAtomNode( atom_int(SA, t, (yyvsp[0].l_val))); 
			}
#line 10718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 595:
#line 3335 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[0].sym); }
#line 10724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 596:
#line 3339 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = NULL; }
#line 10730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 597:
#line 3340 "sql_parser.y" /* yacc.c:1646  */
    {
		  	  sql_subtype *t = sql_bind_localtype("lng");
			  (yyval.sym) = _newAtomNode( atom_int(SA, t, (yyvsp[0].l_val)));
			}
#line 10739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 598:
#line 3344 "sql_parser.y" /* yacc.c:1646  */
    {
		  	  sql_subtype *t = sql_bind_localtype("dbl");
			  (yyval.sym) = _newAtomNode( atom_float(SA, t, strtod((yyvsp[0].sval),NULL)));
			}
#line 10748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 599:
#line 3348 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[0].sym); }
#line 10754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 600:
#line 3352 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol(L(), (yyvsp[0].sym)); }
#line 10760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 601:
#line 3354 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol( (yyvsp[-2].l), (yyvsp[0].sym) ); }
#line 10766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 602:
#line 3359 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_symbol(l, (yyvsp[-1].sym));
	  append_int(l, (yyvsp[0].bval));
	  (yyval.sym) = _symbol_create_list(SQL_COLUMN, l ); }
#line 10775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 603:
#line 3367 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = TRUE; }
#line 10781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 604:
#line 3368 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = TRUE; }
#line 10787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 605:
#line 3369 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = FALSE; }
#line 10793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 615:
#line 3386 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[0].sym);

		  if ((yyval.sym)->token == SQL_EXISTS)
			(yyval.sym)->token = SQL_NOT_EXISTS;
		  else if ((yyval.sym)->token == SQL_NOT_EXISTS)
			(yyval.sym)->token = SQL_EXISTS;
		  else if ((yyval.sym)->token == SQL_NOT_BETWEEN)
			(yyval.sym)->token = SQL_BETWEEN;
		  else if ((yyval.sym)->token == SQL_BETWEEN)
			(yyval.sym)->token = SQL_NOT_BETWEEN;
		  else if ((yyval.sym)->token == SQL_NOT_LIKE)
			(yyval.sym)->token = SQL_LIKE;
		  else if ((yyval.sym)->token == SQL_LIKE)
			(yyval.sym)->token = SQL_NOT_LIKE;
		  else
			(yyval.sym) = _symbol_create_symbol(SQL_NOT, (yyvsp[0].sym)); }
#line 10814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 616:
#line 3402 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[0].sym); }
#line 10820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 617:
#line 3407 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();

		  append_symbol(l, (yyvsp[-2].sym));
		  append_string(l, (yyvsp[-1].sval));
		  append_symbol(l, (yyvsp[0].sym));
		  (yyval.sym) = _symbol_create_list(SQL_COMPARE, l ); }
#line 10831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 618:
#line 3414 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();

		  append_symbol(l, (yyvsp[-2].sym));
		  append_string(l, sa_strdup(SA, "="));
		  append_symbol(l, (yyvsp[0].sym));
		  (yyval.sym) = _symbol_create_list(SQL_COMPARE, l ); }
#line 10842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 619:
#line 3424 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
		  append_symbol(l, (yyvsp[-5].sym));
		  append_int(l, (yyvsp[-3].i_val));
		  append_symbol(l, (yyvsp[-2].sym));
		  append_symbol(l, (yyvsp[0].sym));
		  (yyval.sym) = _symbol_create_list(SQL_NOT_BETWEEN, l ); }
#line 10853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 620:
#line 3431 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
		  append_symbol(l, (yyvsp[-5].sym));
		  append_int(l, (yyvsp[-3].i_val));
		  append_symbol(l, (yyvsp[-2].sym));
		  append_symbol(l, (yyvsp[0].sym));
		  (yyval.sym) = _symbol_create_list(SQL_BETWEEN, l ); }
#line 10864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 621:
#line 3440 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 0; }
#line 10870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 622:
#line 3441 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 0; }
#line 10876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 623:
#line 3442 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 1; }
#line 10882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 624:
#line 3447 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
		  append_symbol(l, (yyvsp[-2].sym));
		  append_symbol(l, (yyvsp[0].sym));
		  append_int(l, FALSE);  /* case sensitive */
		  append_int(l, TRUE);  /* anti */
		  (yyval.sym) = _symbol_create_list( SQL_LIKE, l ); }
#line 10893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 625:
#line 3454 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
		  append_symbol(l, (yyvsp[-2].sym));
		  append_symbol(l, (yyvsp[0].sym));
		  append_int(l, TRUE);  /* case insensitive */
		  append_int(l, TRUE);  /* anti */
		  (yyval.sym) = _symbol_create_list( SQL_LIKE, l ); }
#line 10904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 626:
#line 3461 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
		  append_symbol(l, (yyvsp[-2].sym));
		  append_symbol(l, (yyvsp[0].sym));
		  append_int(l, FALSE);  /* case sensitive */
		  append_int(l, FALSE);  /* anti */
		  (yyval.sym) = _symbol_create_list( SQL_LIKE, l ); }
#line 10915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 627:
#line 3468 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
		  append_symbol(l, (yyvsp[-2].sym));
		  append_symbol(l, (yyvsp[0].sym));
		  append_int(l, TRUE);  /* case insensitive */
		  append_int(l, FALSE);  /* anti */
		  (yyval.sym) = _symbol_create_list( SQL_LIKE, l ); }
#line 10926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 628:
#line 3478 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_symbol(l, (yyvsp[0].sym));
	  (yyval.sym) = _symbol_create_list(SQL_ESCAPE, l ); }
#line 10934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 629:
#line 3482 "sql_parser.y" /* yacc.c:1646  */
    { const char *s = sql2str((yyvsp[0].sval));
	  if (_strlen(s) != 1) {
		yyerror(m, SQLSTATE(22025) "ESCAPE must be one character");
		(yyval.sym) = NULL;
		YYABORT;
	  } else {
		dlist *l = L();
		append_symbol(l, (yyvsp[-2].sym));
		append_string(l, s);
		(yyval.sym) = _symbol_create_list(SQL_ESCAPE, l);
	  }
	}
#line 10951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 630:
#line 3497 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_symbol( SQL_IS_NOT_NULL, (yyvsp[-3].sym) );}
#line 10957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 631:
#line 3498 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_symbol( SQL_IS_NULL, (yyvsp[-2].sym) ); }
#line 10963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 632:
#line 3503 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();

		  append_symbol(l, (yyvsp[-4].sym));
		  append_list(l, (yyvsp[-1].l));
		  (yyval.sym) = _symbol_create_list(SQL_NOT_IN, l ); }
#line 10973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 633:
#line 3509 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();

		  append_symbol(l, (yyvsp[-4].sym));
		  append_list(l, (yyvsp[-1].l));
		  (yyval.sym) = _symbol_create_list(SQL_IN, l ); }
#line 10983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 634:
#line 3515 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
		  append_list(l, (yyvsp[-5].l));
		  append_list(l, (yyvsp[-1].l));
		  (yyval.sym) = _symbol_create_list(SQL_NOT_IN, l ); }
#line 10992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 635:
#line 3520 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
		  append_list(l, (yyvsp[-5].l));
		  append_list(l, (yyvsp[-1].l));
		  (yyval.sym) = _symbol_create_list(SQL_IN, l ); }
#line 11001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 636:
#line 3528 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol( L(), (yyvsp[0].sym));}
#line 11007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 637:
#line 3530 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol( (yyvsp[-2].l), (yyvsp[0].sym)); }
#line 11013 "y.tab.c" /* yacc.c:1646  */
    break;

  case 638:
#line 3536 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
		  append_symbol(l, (yyvsp[-3].sym));
		  append_string(l, (yyvsp[-2].sval));
		  append_symbol(l, (yyvsp[0].sym));
		  append_int(l, (yyvsp[-1].i_val));
		  (yyval.sym) = _symbol_create_list(SQL_COMPARE, l ); }
#line 11024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 639:
#line 3543 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
		  append_symbol(l, (yyvsp[-3].sym));
		  append_string(l, sa_strdup(SA, "="));
		  append_symbol(l, (yyvsp[0].sym));
		  append_int(l, (yyvsp[-1].i_val));
		  (yyval.sym) = _symbol_create_list(SQL_COMPARE, l ); }
#line 11035 "y.tab.c" /* yacc.c:1646  */
    break;

  case 640:
#line 3552 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 0; }
#line 11041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 641:
#line 3553 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 0; }
#line 11047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 642:
#line 3554 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 1; }
#line 11053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 643:
#line 3558 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_symbol( SQL_EXISTS, (yyvsp[0].sym) ); }
#line 11059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 644:
#line 3562 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol(L(), (yyvsp[0].sym)); }
#line 11065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 645:
#line 3563 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol((yyvsp[-2].l), (yyvsp[0].sym));  }
#line 11071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 646:
#line 3567 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[-1].l); }
#line 11077 "y.tab.c" /* yacc.c:1646  */
    break;

  case 647:
#line 3572 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
		  append_list(l, (yyvsp[-2].l));
		  append_list(l, (yyvsp[-1].l));
		  append_list(l, (yyvsp[0].l));
		  (yyval.sym) = _symbol_create_list(SQL_FILTER, l ); }
#line 11087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 648:
#line 3581 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[-1].sym); }
#line 11093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 649:
#line 3583 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list( SQL_VALUES, (yyvsp[-1].l)); }
#line 11099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 650:
#line 3585 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[-1].sym); }
#line 11105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 651:
#line 3589 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[-1].sym); }
#line 11111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 652:
#line 3591 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list( SQL_VALUES, (yyvsp[-1].l)); }
#line 11117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 653:
#line 3593 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[-1].sym); }
#line 11123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 655:
#line 3600 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
			  append_list(l, 
			  	append_string(append_string(L(), sa_strdup(SA, "sys")), sa_strdup(SA, "sql_add")));
	  		  append_symbol(l, (yyvsp[-2].sym));
	  		  append_symbol(l, (yyvsp[0].sym));
	  		  (yyval.sym) = _symbol_create_list( SQL_BINOP, l ); }
#line 11134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 656:
#line 3607 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
			  append_list(l, 
			  	append_string(append_string(L(), sa_strdup(SA, "sys")), sa_strdup(SA, "sql_sub")));
	  		  append_symbol(l, (yyvsp[-2].sym));
	  		  append_symbol(l, (yyvsp[0].sym));
	  		  (yyval.sym) = _symbol_create_list( SQL_BINOP, l ); }
#line 11145 "y.tab.c" /* yacc.c:1646  */
    break;

  case 657:
#line 3614 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
			  append_list(l, 
			  	append_string(append_string(L(), sa_strdup(SA, "sys")), sa_strdup(SA, "sql_mul")));
	  		  append_symbol(l, (yyvsp[-2].sym));
	  		  append_symbol(l, (yyvsp[0].sym));
	  		  (yyval.sym) = _symbol_create_list( SQL_BINOP, l ); }
#line 11156 "y.tab.c" /* yacc.c:1646  */
    break;

  case 658:
#line 3621 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
			  append_list(l, 
			  	append_string(append_string(L(), sa_strdup(SA, "sys")), sa_strdup(SA, "sql_div")));
	  		  append_symbol(l, (yyvsp[-2].sym));
	  		  append_symbol(l, (yyvsp[0].sym));
	  		  (yyval.sym) = _symbol_create_list( SQL_BINOP, l ); }
#line 11167 "y.tab.c" /* yacc.c:1646  */
    break;

  case 659:
#line 3628 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
			  append_list(l, 
			  	append_string(append_string(L(), sa_strdup(SA, "sys")), sa_strdup(SA, "mod")));
	  		  append_symbol(l, (yyvsp[-2].sym));
	  		  append_symbol(l, (yyvsp[0].sym));
	  		  (yyval.sym) = _symbol_create_list( SQL_BINOP, l ); }
#line 11178 "y.tab.c" /* yacc.c:1646  */
    break;

  case 660:
#line 3635 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
			  append_list(l, 
			  	append_string(append_string(L(), sa_strdup(SA, "sys")), sa_strdup(SA, "bit_xor")));
	  		  append_symbol(l, (yyvsp[-2].sym));
	  		  append_symbol(l, (yyvsp[0].sym));
	  		  (yyval.sym) = _symbol_create_list( SQL_BINOP, l ); }
#line 11189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 661:
#line 3642 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
			  append_list(l, 
			  	append_string(append_string(L(), sa_strdup(SA, "sys")), sa_strdup(SA, "bit_and")));
	  		  append_symbol(l, (yyvsp[-2].sym));
			  append_symbol(l, (yyvsp[0].sym));
	  		  (yyval.sym) = _symbol_create_list( SQL_BINOP, l ); }
#line 11200 "y.tab.c" /* yacc.c:1646  */
    break;

  case 662:
#line 3649 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
			  append_list(l, 
			  	append_string(L(), sa_strdup(SA, "mbr_overlap")));
	  		  append_symbol(l, (yyvsp[-2].sym));
	  		  append_symbol(l, (yyvsp[0].sym));
	  		  (yyval.sym) = _symbol_create_list( SQL_BINOP, l ); }
#line 11211 "y.tab.c" /* yacc.c:1646  */
    break;

  case 663:
#line 3656 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
			  append_list(l, 
			  	append_string(L(), sa_strdup(SA, "mbr_overlap_or_left")));
	  		  append_symbol(l, (yyvsp[-2].sym));
	  		  append_symbol(l, (yyvsp[0].sym));
	  		  (yyval.sym) = _symbol_create_list( SQL_BINOP, l ); }
#line 11222 "y.tab.c" /* yacc.c:1646  */
    break;

  case 664:
#line 3663 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
			  append_list(l, 
			  	append_string(L(), sa_strdup(SA, "mbr_overlap_or_right")));
	  		  append_symbol(l, (yyvsp[-2].sym));
	  		  append_symbol(l, (yyvsp[0].sym));
	  		  (yyval.sym) = _symbol_create_list( SQL_BINOP, l ); }
#line 11233 "y.tab.c" /* yacc.c:1646  */
    break;

  case 665:
#line 3670 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
			  append_list(l, 
			  	append_string(L(), sa_strdup(SA, "mbr_overlap_or_below")));
	  		  append_symbol(l, (yyvsp[-2].sym));
	  		  append_symbol(l, (yyvsp[0].sym));
	  		  (yyval.sym) = _symbol_create_list( SQL_BINOP, l ); }
#line 11244 "y.tab.c" /* yacc.c:1646  */
    break;

  case 666:
#line 3677 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
			  append_list(l, append_string(L(), sa_strdup(SA, "mbr_below")));
	  		  append_symbol(l, (yyvsp[-2].sym));
	  		  append_symbol(l, (yyvsp[0].sym));
	  		  (yyval.sym) = _symbol_create_list( SQL_BINOP, l ); }
#line 11254 "y.tab.c" /* yacc.c:1646  */
    break;

  case 667:
#line 3683 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
			  append_list(l, 
			  	append_string(L(), sa_strdup(SA, "mbr_overlap_or_above")));
	  		  append_symbol(l, (yyvsp[-2].sym));
	  		  append_symbol(l, (yyvsp[0].sym));
	  		  (yyval.sym) = _symbol_create_list( SQL_BINOP, l ); }
#line 11265 "y.tab.c" /* yacc.c:1646  */
    break;

  case 668:
#line 3690 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
			  append_list(l, 
			  	append_string(L(), sa_strdup(SA, "mbr_above")));
	  		  append_symbol(l, (yyvsp[-2].sym));
	  		  append_symbol(l, (yyvsp[0].sym));
	  		  (yyval.sym) = _symbol_create_list( SQL_BINOP, l ); }
#line 11276 "y.tab.c" /* yacc.c:1646  */
    break;

  case 669:
#line 3697 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
			  append_list(l, 
			  	append_string(L(), sa_strdup(SA, "mbr_distance")));
	  		  append_symbol(l, (yyvsp[-2].sym));
	  		  append_symbol(l, (yyvsp[0].sym));
	  		  (yyval.sym) = _symbol_create_list( SQL_BINOP, l ); }
#line 11287 "y.tab.c" /* yacc.c:1646  */
    break;

  case 670:
#line 3704 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
			  append_list(l, 
			  	append_string(L(), sa_strdup(SA, "mbr_contained")));
	  		  append_symbol(l, (yyvsp[-2].sym));
	  		  append_symbol(l, (yyvsp[0].sym));
	  		  (yyval.sym) = _symbol_create_list( SQL_BINOP, l ); }
#line 11298 "y.tab.c" /* yacc.c:1646  */
    break;

  case 671:
#line 3711 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
			  append_list(l, 
			  	append_string(append_string(L(), sa_strdup(SA, "sys")), sa_strdup(SA, "bit_or")));
	  		  append_symbol(l, (yyvsp[-2].sym));
	  		  append_symbol(l, (yyvsp[0].sym));
	  		  (yyval.sym) = _symbol_create_list( SQL_BINOP, l ); }
#line 11309 "y.tab.c" /* yacc.c:1646  */
    break;

  case 672:
#line 3718 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
			  append_list(l, 
			  	append_string(L(), sa_strdup(SA, "mbr_contains")));
	  		  append_symbol(l, (yyvsp[-2].sym));
	  		  append_symbol(l, (yyvsp[0].sym));
	  		  (yyval.sym) = _symbol_create_list( SQL_BINOP, l ); }
#line 11320 "y.tab.c" /* yacc.c:1646  */
    break;

  case 673:
#line 3725 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
			  append_list(l, 
			  	append_string(L(), sa_strdup(SA, "mbr_equal")));
	  		  append_symbol(l, (yyvsp[-2].sym));
	  		  append_symbol(l, (yyvsp[0].sym));
	  		  (yyval.sym) = _symbol_create_list( SQL_BINOP, l ); }
#line 11331 "y.tab.c" /* yacc.c:1646  */
    break;

  case 674:
#line 3732 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
			  append_list(l, 
			  	append_string(append_string(L(), sa_strdup(SA, "sys")), sa_strdup(SA, "bit_not")));
	  		  append_symbol(l, (yyvsp[0].sym));
	  		  (yyval.sym) = _symbol_create_list( SQL_UNOP, l ); }
#line 11341 "y.tab.c" /* yacc.c:1646  */
    break;

  case 675:
#line 3738 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
			  append_list(l, 
			  	append_string(append_string(L(), sa_strdup(SA, "sys")), sa_strdup(SA, "left_shift")));
	  		  append_symbol(l, (yyvsp[-2].sym));
	  		  append_symbol(l, (yyvsp[0].sym));
	  		  (yyval.sym) = _symbol_create_list( SQL_BINOP, l ); }
#line 11352 "y.tab.c" /* yacc.c:1646  */
    break;

  case 676:
#line 3745 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
			  append_list(l, 
			  	append_string(append_string(L(), sa_strdup(SA, "sys")), sa_strdup(SA, "right_shift")));
	  		  append_symbol(l, (yyvsp[-2].sym));
	  		  append_symbol(l, (yyvsp[0].sym));
	  		  (yyval.sym) = _symbol_create_list( SQL_BINOP, l ); }
#line 11363 "y.tab.c" /* yacc.c:1646  */
    break;

  case 677:
#line 3752 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
			  append_list(l, 
			  	append_string(append_string(L(), sa_strdup(SA, "sys")), sa_strdup(SA, "left_shift_assign")));
	  		  append_symbol(l, (yyvsp[-2].sym));
	  		  append_symbol(l, (yyvsp[0].sym));
	  		  (yyval.sym) = _symbol_create_list( SQL_BINOP, l ); }
#line 11374 "y.tab.c" /* yacc.c:1646  */
    break;

  case 678:
#line 3759 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
			  append_list(l, 
			  	append_string(append_string(L(), sa_strdup(SA, "sys")), sa_strdup(SA, "right_shift_assign")));
	  		  append_symbol(l, (yyvsp[-2].sym));
	  		  append_symbol(l, (yyvsp[0].sym));
	  		  (yyval.sym) = _symbol_create_list( SQL_BINOP, l ); }
#line 11385 "y.tab.c" /* yacc.c:1646  */
    break;

  case 679:
#line 3766 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[0].sym); }
#line 11391 "y.tab.c" /* yacc.c:1646  */
    break;

  case 680:
#line 3768 "sql_parser.y" /* yacc.c:1646  */
    { 
 			  (yyval.sym) = NULL;
			  assert((yyvsp[0].sym)->token != SQL_COLUMN || (yyvsp[0].sym)->data.lval->h->type != type_lng);
			  if ((yyvsp[0].sym)->token == SQL_COLUMN && (yyvsp[0].sym)->data.lval->h->type == type_int) {
				atom *a = sql_bind_arg(m, (yyvsp[0].sym)->data.lval->h->data.i_val);
				if (!atom_neg(a)) {
					(yyval.sym) = (yyvsp[0].sym);
				} else {
					yyerror(m, SQLSTATE(22003) "value too large or not a number");
					(yyval.sym) = NULL;
					YYABORT;
				}
			  } 
			  if (!(yyval.sym)) {
				dlist *l = L();
			  	append_list(l, 
			  		append_string(append_string(L(), sa_strdup(SA, "sys")), sa_strdup(SA, "sql_neg")));
	  		  	append_symbol(l, (yyvsp[0].sym));
	  		  	(yyval.sym) = _symbol_create_list( SQL_UNOP, l ); 
			  }
			}
#line 11417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 681:
#line 3789 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[-1].sym); }
#line 11423 "y.tab.c" /* yacc.c:1646  */
    break;

  case 682:
#line 3793 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[0].sym); }
#line 11429 "y.tab.c" /* yacc.c:1646  */
    break;

  case 685:
#line 3799 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list( SQL_COLUMN, 
			  append_string(L(), sa_strdup(SA, "current_user"))); }
#line 11436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 686:
#line 3801 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list( SQL_COLUMN, 
			  append_string(L(), sa_strdup(SA, "current_role"))); }
#line 11443 "y.tab.c" /* yacc.c:1646  */
    break;

  case 688:
#line 3804 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list( SQL_COLUMN, (yyvsp[0].l)); }
#line 11449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 692:
#line 3808 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list( SQL_NEXT, (yyvsp[0].l)); }
#line 11455 "y.tab.c" /* yacc.c:1646  */
    break;

  case 700:
#line 3820 "sql_parser.y" /* yacc.c:1646  */
    { 
	  int nr = (m->params)?list_length(m->params):0;

	  sql_add_param(m, NULL, NULL);
	  (yyval.sym) = _symbol_create_int( SQL_PARAMETER, nr ); 
	}
#line 11466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 701:
#line 3890 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list( SQL_RANK, 
		append_list(append_symbol(L(), (yyvsp[-4].sym)), (yyvsp[-1].l))); }
#line 11473 "y.tab.c" /* yacc.c:1646  */
    break;

  case 702:
#line 3895 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list( SQL_RANK, (yyvsp[-2].l) ); }
#line 11479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 704:
#line 3901 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol(append_symbol(append_symbol(L(), (yyvsp[-2].sym)), (yyvsp[-1].sym)), (yyvsp[0].sym)); }
#line 11485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 705:
#line 3905 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = NULL; }
#line 11491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 706:
#line 3907 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list( SQL_GROUPBY, (yyvsp[0].l) ); }
#line 11497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 707:
#line 3911 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = NULL; }
#line 11503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 708:
#line 3913 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list( SQL_ORDERBY, (yyvsp[0].l) ); }
#line 11509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 709:
#line 3917 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = NULL; }
#line 11515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 710:
#line 3919 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list( SQL_FRAME, append_int(append_int((yyvsp[-1].l), (yyvsp[-2].i_val)), (yyvsp[0].i_val))); }
#line 11521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 711:
#line 3923 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = FRAME_ROWS; }
#line 11527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 712:
#line 3924 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = FRAME_RANGE; }
#line 11533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 713:
#line 3928 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol(append_symbol(L(), (yyvsp[0].sym)), _symbol_create_int(SQL_FRAME, -1)); }
#line 11539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 714:
#line 3929 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[0].l); }
#line 11545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 715:
#line 3933 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_int(SQL_FRAME, -1); }
#line 11551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 716:
#line 3934 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[0].sym); }
#line 11557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 717:
#line 3935 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_int(SQL_FRAME, 0); }
#line 11563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 718:
#line 3939 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[-1].sym); }
#line 11569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 719:
#line 3944 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol(append_symbol(L(), (yyvsp[-2].sym)), (yyvsp[0].sym)); }
#line 11575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 720:
#line 3948 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_int(SQL_FRAME, -1); }
#line 11581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 721:
#line 3949 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[0].sym); }
#line 11587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 722:
#line 3950 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_int(SQL_FRAME, 0); }
#line 11593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 723:
#line 3954 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[-1].sym); }
#line 11599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 724:
#line 3958 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = EXCLUDE_NONE; }
#line 11605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 725:
#line 3959 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = EXCLUDE_CURRENT_ROW; }
#line 11611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 726:
#line 3960 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = EXCLUDE_GROUP; }
#line 11617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 727:
#line 3961 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = EXCLUDE_TIES; }
#line 11623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 728:
#line 3962 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = EXCLUDE_NO_OTHERS; }
#line 11629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 729:
#line 3966 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create( SQL_NAME, (yyvsp[0].sval) ); }
#line 11635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 730:
#line 3971 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
  	  append_list(l, (yyvsp[-2].l));
	  (yyval.sym) = _symbol_create_list( SQL_OP, l ); }
#line 11643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 731:
#line 3975 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
  	  append_list(l, (yyvsp[-3].l));
	  if (dlist_length((yyvsp[-1].l)) == 1) {
  	  	append_symbol(l, (yyvsp[-1].l)->h->data.sym);
	  	(yyval.sym) = _symbol_create_list( SQL_UNOP, l ); 
	  } else if (dlist_length((yyvsp[-1].l)) == 2) {
  	  	append_symbol(l, (yyvsp[-1].l)->h->data.sym);
  	  	append_symbol(l, (yyvsp[-1].l)->h->next->data.sym);
	  	(yyval.sym) = _symbol_create_list( SQL_BINOP, l ); 
	  } else {
  	  	append_list(l, (yyvsp[-1].l));
	  	(yyval.sym) = _symbol_create_list( SQL_NOP, l ); 
	  }
	}
#line 11662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 732:
#line 4002 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_string(L(), (yyvsp[0].sval)); }
#line 11668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 733:
#line 4003 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_string(
					append_string(L(), (yyvsp[-2].sval)), (yyvsp[0].sval));}
#line 11675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 734:
#line 4008 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[0].sval); }
#line 11681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 735:
#line 4009 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "left"); }
#line 11687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 736:
#line 4010 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "right"); }
#line 11693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 737:
#line 4011 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "insert"); }
#line 11699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 738:
#line 4016 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
			  const char *ident = datetime_field((itype)(yyvsp[-3].i_val));
			  append_list(l,
  		  	  	append_string(L(), sa_strdup(SA, ident)));
  		  	  append_symbol(l, (yyvsp[-1].sym));
		  	  (yyval.sym) = _symbol_create_list( SQL_UNOP, l ); }
#line 11710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 739:
#line 4023 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
			  append_list(l,
			  	append_string(L(), sa_strdup(SA, "current_date")));
	  		  (yyval.sym) = _symbol_create_list( SQL_OP, l ); }
#line 11719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 740:
#line 4028 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
			  append_list(l,
			  	append_string(L(), sa_strdup(SA, "current_time")));
	  		  (yyval.sym) = _symbol_create_list( SQL_OP, l ); }
#line 11728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 741:
#line 4033 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
			  append_list(l,
			  	append_string(L(), sa_strdup(SA, "current_timestamp")));
	  		  (yyval.sym) = _symbol_create_list( SQL_OP, l ); }
#line 11737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 742:
#line 4038 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
			  append_list(l,
			  	append_string(L(), sa_strdup(SA, "localtime")));
	  		  (yyval.sym) = _symbol_create_list( SQL_OP, l ); }
#line 11746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 743:
#line 4043 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
			  append_list(l,
			  	append_string(L(), sa_strdup(SA, "localtimestamp")));
	  		  (yyval.sym) = _symbol_create_list( SQL_OP, l ); }
#line 11755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 744:
#line 4050 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = 0; }
#line 11761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 745:
#line 4051 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = 1; }
#line 11767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 746:
#line 4056 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
			  dlist *ops = L();
  		  	  append_list(l,
				append_string(L(), sa_strdup(SA, "substring")));
  		  	  append_symbol(ops, (yyvsp[-5].sym));
  		  	  append_symbol(ops, (yyvsp[-3].sym));
  		  	  append_symbol(ops, (yyvsp[-1].sym));
			  append_list(l, ops);
		  	  (yyval.sym) = _symbol_create_list( SQL_NOP, l ); }
#line 11781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 747:
#line 4066 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
			  dlist *ops = L();
  		  	  append_list(l,
  		  	  	append_string(L(), sa_strdup(SA, "substring")));
  		  	  append_symbol(ops, (yyvsp[-5].sym));
  		  	  append_symbol(ops, (yyvsp[-3].sym));
  		  	  append_symbol(ops, (yyvsp[-1].sym));
			  append_list(l, ops);
		  	  (yyval.sym) = _symbol_create_list( SQL_NOP, l ); }
#line 11795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 748:
#line 4076 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
  		  	  append_list(l,
  		  	  	append_string(L(), sa_strdup(SA, "substring")));
  		  	  append_symbol(l, (yyvsp[-3].sym));
  		  	  append_symbol(l, (yyvsp[-1].sym));
		  	  (yyval.sym) = _symbol_create_list( SQL_BINOP, l ); }
#line 11806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 749:
#line 4083 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
  		  	  append_list(l,
  		  	  	append_string(L(), sa_strdup(SA, "substring")));
  		  	  append_symbol(l, (yyvsp[-3].sym));
  		  	  append_symbol(l, (yyvsp[-1].sym));
		  	  (yyval.sym) = _symbol_create_list( SQL_BINOP, l ); }
#line 11817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 750:
#line 4090 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
  		  	  append_list(l,
  		  	  	append_string(L(), sa_strdup(SA, "locate")));
  		  	  append_symbol(l, (yyvsp[-3].sym));
  		  	  append_symbol(l, (yyvsp[-1].sym));
		  	  (yyval.sym) = _symbol_create_list( SQL_BINOP, l ); }
#line 11828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 751:
#line 4097 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
  		  	  append_list(l,
  		  	  	append_string(L(), sa_strdup(SA, "concat")));
  		  	  append_symbol(l, (yyvsp[-2].sym));
  		  	  append_symbol(l, (yyvsp[0].sym));
		  	  (yyval.sym) = _symbol_create_list( SQL_BINOP, l ); }
#line 11839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 752:
#line 4104 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
			  dlist *ops = L();
  		  	  append_list(l,
				append_string(L(), sa_strdup(SA, "splitpart")));
  		  	  append_symbol(ops, (yyvsp[-5].sym));
  		  	  append_symbol(ops, (yyvsp[-3].sym));
  		  	  append_symbol(ops, (yyvsp[-1].sym));
			  append_list(l, ops);
		  	  (yyval.sym) = _symbol_create_list( SQL_NOP, l ); }
#line 11853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 753:
#line 4116 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol(L(), (yyvsp[0].sym) ); }
#line 11859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 754:
#line 4118 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol( (yyvsp[-2].l), (yyvsp[0].sym) ); }
#line 11865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 755:
#line 4123 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
  		  append_string(l, NULL);
  		  append_string(l, NULL);
  		  (yyval.sym) = _symbol_create_list( SQL_TABLE, l ); }
#line 11874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 756:
#line 4128 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
  		  append_string(l, (yyvsp[-2].sval));
  		  append_string(l, NULL);
  		  (yyval.sym) = _symbol_create_list( SQL_TABLE, l ); }
#line 11883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 757:
#line 4133 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
  		  append_symbol(l, (yyvsp[-2].sym));
  		  append_string(l, NULL);
  		  (yyval.sym) = _symbol_create_list( SQL_TABLE, l ); }
#line 11892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 758:
#line 4138 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
  		  append_symbol(l, (yyvsp[-1].sym));
  		  append_string(l, (yyvsp[0].sval));
  		  (yyval.sym) = _symbol_create_list( SQL_COLUMN, l ); }
#line 11901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 759:
#line 4145 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = NULL; }
#line 11907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 760:
#line 4146 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[0].sval); }
#line 11913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 761:
#line 4151 "sql_parser.y" /* yacc.c:1646  */
    { 
	  if (m->emode == m_normal && m->caching) { 
	  	/* replace by argument */
	  	AtomNode *an = (AtomNode*)(yyvsp[0].sym);
	
	  	sql_add_arg( m, an->a);
		an->a = NULL;
	  	/* we miss use SQL_COLUMN also for param's, maybe
	     		change SQL_COLUMN to SQL_IDENT */
 	  	(yyval.sym) = _symbol_create_list( SQL_COLUMN,
			append_int(L(), m->argc-1));
	   } else {
	  	AtomNode *an = (AtomNode*)(yyvsp[0].sym);
		atom *a = an->a; 
		an->a = atom_dup(SA, a); 
		(yyval.sym) = (yyvsp[0].sym);
	   }
	}
#line 11936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 762:
#line 4172 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_string(L(), (yyvsp[0].sval)); }
#line 11942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 763:
#line 4173 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_string(
			  append_string(L(), (yyvsp[-2].sval)), (yyvsp[0].sval));}
#line 11949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 764:
#line 4178 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_string(L(), (yyvsp[0].sval)); }
#line 11955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 765:
#line 4179 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_string(
			  append_string(L(), (yyvsp[-2].sval)), (yyvsp[0].sval));}
#line 11962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 766:
#line 4184 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_string(L(), (yyvsp[0].sval)); }
#line 11968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 767:
#line 4185 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_string(
			  append_string(L(), (yyvsp[-2].sval)), (yyvsp[0].sval));}
#line 11975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 768:
#line 4192 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
  		  append_list(l, (yyvsp[-3].l));
  		  append_int(l, FALSE);
  		  append_symbol(l, NULL);
		  (yyval.sym) = _symbol_create_list( SQL_AGGR, l ); }
#line 11985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 769:
#line 4198 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
  		  append_list(l, (yyvsp[-5].l));
  		  append_int(l, FALSE);
  		  append_symbol(l, NULL);
		  (yyval.sym) = _symbol_create_list( SQL_AGGR, l ); }
#line 11995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 770:
#line 4204 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
  		  append_list(l, (yyvsp[-4].l));
  		  append_int(l, TRUE);
  		  append_symbol(l, (yyvsp[-1].sym));
		  (yyval.sym) = _symbol_create_list( SQL_AGGR, l ); }
#line 12005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 771:
#line 4210 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
  		  append_list(l, (yyvsp[-4].l));
  		  append_int(l, FALSE);
  		  append_symbol(l, (yyvsp[-1].sym));
		  (yyval.sym) = _symbol_create_list( SQL_AGGR, l ); }
#line 12015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 772:
#line 4216 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
  		  append_list(l, (yyvsp[-3].l));
  		  append_int(l, FALSE);
  		  append_symbol(l, (yyvsp[-1].sym));
		  (yyval.sym) = _symbol_create_list( SQL_AGGR, l ); }
#line 12025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 773:
#line 4222 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
  		  append_list(l, (yyvsp[-5].l));
  		  append_int(l, FALSE);
  		  append_symbol(l, (yyvsp[-3].sym));
  		  append_symbol(l, (yyvsp[-1].sym));
		  (yyval.sym) = _symbol_create_list( SQL_AGGR, l ); }
#line 12036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 775:
#line 4232 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 1; }
#line 12042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 776:
#line 4233 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = -1; }
#line 12048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 777:
#line 4234 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 1; }
#line 12054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 778:
#line 4238 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = 1; }
#line 12060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 779:
#line 4239 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = 0; }
#line 12066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 780:
#line 4250 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = (yyvsp[-1].i_val)+1; }
#line 12072 "y.tab.c" /* yacc.c:1646  */
    break;

  case 781:
#line 4252 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 0+1; }
#line 12078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 782:
#line 4256 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = (yyvsp[-1].i_val)+1; }
#line 12084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 783:
#line 4258 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 6+1; }
#line 12090 "y.tab.c" /* yacc.c:1646  */
    break;

  case 784:
#line 4262 "sql_parser.y" /* yacc.c:1646  */
    { sql_find_subtype(&(yyval.type), "date", 0, 0); }
#line 12096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 785:
#line 4264 "sql_parser.y" /* yacc.c:1646  */
    { if ((yyvsp[0].bval))
				sql_find_subtype(&(yyval.type), "timetz", (yyvsp[-1].i_val), 0); 
			  else
				sql_find_subtype(&(yyval.type), "time", (yyvsp[-1].i_val), 0); 
			}
#line 12106 "y.tab.c" /* yacc.c:1646  */
    break;

  case 786:
#line 4270 "sql_parser.y" /* yacc.c:1646  */
    { if ((yyvsp[0].bval))
				sql_find_subtype(&(yyval.type), "timestamptz", (yyvsp[-1].i_val), 0); 
			  else
				sql_find_subtype(&(yyval.type), "timestamp", (yyvsp[-1].i_val), 0); 
			}
#line 12116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 787:
#line 4278 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = iyear; }
#line 12122 "y.tab.c" /* yacc.c:1646  */
    break;

  case 788:
#line 4279 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = imonth; }
#line 12128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 789:
#line 4280 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = iday; }
#line 12134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 790:
#line 4281 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = ihour; }
#line 12140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 791:
#line 4282 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = imin; }
#line 12146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 793:
#line 4287 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = isec; }
#line 12152 "y.tab.c" /* yacc.c:1646  */
    break;

  case 795:
#line 4292 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = iquarter; }
#line 12158 "y.tab.c" /* yacc.c:1646  */
    break;

  case 796:
#line 4293 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = iweek; }
#line 12164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 797:
#line 4298 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_int(
			 	append_int( L(), (yyvsp[-1].i_val)), (yyvsp[0].i_val)-1);  }
#line 12171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 798:
#line 4304 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_int(
			 	append_int( L(), (yyvsp[0].i_val)), 0);  }
#line 12178 "y.tab.c" /* yacc.c:1646  */
    break;

  case 799:
#line 4307 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_int(
			 	append_int( L(), isec), (yyvsp[0].i_val)-1);  }
#line 12185 "y.tab.c" /* yacc.c:1646  */
    break;

  case 800:
#line 4313 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_int(
			 	append_int( L(), (yyvsp[-1].i_val)), (yyvsp[0].i_val)-1);  }
#line 12192 "y.tab.c" /* yacc.c:1646  */
    break;

  case 801:
#line 4316 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_int(
			 	append_int( L(), isec), (yyvsp[0].i_val)-1);  }
#line 12199 "y.tab.c" /* yacc.c:1646  */
    break;

  case 802:
#line 4322 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) =  append_list(
			append_list( L(), (yyvsp[-2].l)), (yyvsp[0].l) ); }
#line 12206 "y.tab.c" /* yacc.c:1646  */
    break;

  case 803:
#line 4325 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) =  append_list( L(), (yyvsp[0].l)); }
#line 12212 "y.tab.c" /* yacc.c:1646  */
    break;

  case 804:
#line 4329 "sql_parser.y" /* yacc.c:1646  */
    {
		int sk, ek, sp, ep;
	  	int tpe;

		(yyval.type).type = NULL;
	  	if ( (tpe = parse_interval_qualifier( m, (yyvsp[0].l), &sk, &ek, &sp, &ep )) < 0){
			yyerror(m, SQLSTATE(22006) "incorrect interval");
			YYABORT;
	  	} else {
			int d = inttype2digits(sk, ek);
			if (tpe == 0){
				sql_find_subtype(&(yyval.type), "month_interval", d, 0);
			} else {
				sql_find_subtype(&(yyval.type), "sec_interval", d, 0);
			}
	  	}
	}
#line 12234 "y.tab.c" /* yacc.c:1646  */
    break;

  case 808:
#line 4355 "sql_parser.y" /* yacc.c:1646  */
    { const char *s = sql2str((yyvsp[0].sval));
		  int len = UTF8_strlen(s);
		  sql_subtype t;
		  sql_find_subtype(&t, "char", len, 0 );
		  (yyval.sym) = _newAtomNode( _atom_string(&t, s)); }
#line 12244 "y.tab.c" /* yacc.c:1646  */
    break;

  case 809:
#line 4361 "sql_parser.y" /* yacc.c:1646  */
    { int len = _strlen((yyvsp[0].sval)), i = 2, err = 0;
		  char * hexa = (yyvsp[0].sval);
	 	  sql_subtype t;
#ifdef HAVE_HGE
		  hge res = 0;
#else
		  lng res = 0;
#endif
		  /* skip leading '0' */
		  while (i < len && hexa[i] == '0')
		  	i++;

		  /* we only support positive values that fit in a signed 128-bit type,
		   * i.e., max. 63/127 bit => < 2^63/2^127 => < 0x800...
		   * (leading sign (-0x...) is handled separately elsewhere)
		   */
		  if (len - i < MAX_HEX_DIGITS || (len - i == MAX_HEX_DIGITS && hexa[i] < '8'))
		  	while (err == 0 && i < len)
		  	{
				res <<= 4;
				if ('0'<= hexa[i] && hexa[i] <= '9')
					res = res + (hexa[i] - '0');
				else if ('A' <= hexa[i] && hexa[i] <= 'F')
					res = res + (hexa[i] - 'A' + 10);
				else if ('a' <= hexa[i] && hexa[i] <= 'f')
					res = res + (hexa[i] - 'a' + 10);
				else
					err = 1;
		  		i++;
			}
		  else
			err = 1;

		  if (err == 0) {
		  	assert(res >= 0);

		  	/* use smallest type that can accommodate the given value */
			if (res <= GDK_bte_max)
				sql_find_subtype(&t, "tinyint", 8, 0 );
			else if (res <= GDK_sht_max)
				sql_find_subtype(&t, "smallint", 16, 0 );
		  	else if (res <= GDK_int_max)
				sql_find_subtype(&t, "int", 32, 0 );
			else if (res <= GDK_lng_max)
				sql_find_subtype(&t, "bigint", 64, 0 );
#ifdef HAVE_HGE
			else if (res <= GDK_hge_max && have_hge)
				sql_find_subtype(&t, "hugeint", 128, 0 );
#endif
			else
				err = 1;
		  }

		  if (err != 0) {
			char *msg = sql_message(SQLSTATE(22003) "Invalid hexadecimal number or hexadecimal too large (%s)", (yyvsp[0].sval));

			yyerror(m, msg);
			_DELETE(msg);
			(yyval.sym) = NULL;
			YYABORT;
		  } else {
			(yyval.sym) = _newAtomNode( atom_int(SA, &t, res));
		  }
		}
#line 12313 "y.tab.c" /* yacc.c:1646  */
    break;

  case 810:
#line 4426 "sql_parser.y" /* yacc.c:1646  */
    { int err = 0;
		  size_t len = sizeof(lng);
		  lng value, *p = &value;
		  sql_subtype t;

		  if (lngFromStr((yyvsp[0].sval), &len, &p) < 0 || value == lng_nil)
		  	err = 2;

		  if (!err) {
		    if ((value > GDK_lng_min && value <= GDK_lng_max))
#if SIZEOF_OID == SIZEOF_INT
		  	  sql_find_subtype(&t, "oid", 31, 0 );
#else
		  	  sql_find_subtype(&t, "oid", 63, 0 );
#endif
		    else
			  err = 1;
		  }

		  if (err) {
			char *msg = sql_message(SQLSTATE(22003) "OID value too large or not a number (%s)", (yyvsp[0].sval));

			yyerror(m, msg);
			_DELETE(msg);
			(yyval.sym) = NULL;
			YYABORT;
		  } else {
		  	(yyval.sym) = _newAtomNode( atom_int(SA, &t, value));
		  }
		}
#line 12348 "y.tab.c" /* yacc.c:1646  */
    break;

  case 811:
#line 4457 "sql_parser.y" /* yacc.c:1646  */
    { int digits = _strlen((yyvsp[0].sval)), err = 0;
#ifdef HAVE_HGE
		  hge value, *p = &value;
		  size_t len = sizeof(hge);
		  const hge one = 1;
#else
		  lng value, *p = &value;
		  size_t len = sizeof(lng);
		  const lng one = 1;
#endif
		  sql_subtype t;

#ifdef HAVE_HGE
		  if (hgeFromStr((yyvsp[0].sval), &len, &p) < 0 || value == hge_nil)
		  	err = 2;
#else
		  if (lngFromStr((yyvsp[0].sval), &len, &p) < 0 || value == lng_nil)
		  	err = 2;
#endif

		  /* find the most suitable data type for the given number */
		  if (!err) {
		    int bits = digits2bits(digits), obits = bits;

		    while (bits > 0 &&
			   (bits == sizeof(value) * 8 ||
			    (one << (bits - 1)) > value))
			  bits--;

 		    if (bits != obits &&
		       (bits == 8 || bits == 16 || bits == 32 || bits == 64))
				bits++;
		
		    if (value > GDK_bte_min && value <= GDK_bte_max)
		  	  sql_find_subtype(&t, "tinyint", bits, 0 );
		    else if (value > GDK_sht_min && value <= GDK_sht_max)
		  	  sql_find_subtype(&t, "smallint", bits, 0 );
		    else if (value > GDK_int_min && value <= GDK_int_max)
		  	  sql_find_subtype(&t, "int", bits, 0 );
		    else if (value > GDK_lng_min && value <= GDK_lng_max)
		  	  sql_find_subtype(&t, "bigint", bits, 0 );
#ifdef HAVE_HGE
		    else if (value > GDK_hge_min && value <= GDK_hge_max && have_hge)
		  	  sql_find_subtype(&t, "hugeint", bits, 0 );
#endif
		    else
			  err = 1;
		  }

		  if (err) {
			char *msg = sql_message(SQLSTATE(22003) "integer value too large or not a number (%s)", (yyvsp[0].sval));

			yyerror(m, msg);
			_DELETE(msg);
			(yyval.sym) = NULL;
			YYABORT;
		  } else {
		  	(yyval.sym) = _newAtomNode( atom_int(SA, &t, value));
		  }
		}
#line 12413 "y.tab.c" /* yacc.c:1646  */
    break;

  case 812:
#line 4518 "sql_parser.y" /* yacc.c:1646  */
    { char *s = strip_extra_zeros(sa_strdup(SA, (yyvsp[0].sval)));
		  char *dot = strchr(s, '.');
		  int digits = _strlen(s) - 1;
		  int scale = digits - (int) (dot-s);
		  sql_subtype t;

		  if (digits <= 0)
			digits = 1;
		  if (digits <= MAX_DEC_DIGITS) {
		  	double val = strtod((yyvsp[0].sval),NULL);
#ifdef HAVE_HGE
		  	hge value = decimal_from_str(s, NULL);
#else
		  	lng value = decimal_from_str(s, NULL);
#endif

		  	if (*s == '+' || *s == '-')
				digits --;
		  	sql_find_subtype(&t, "decimal", digits, scale );
		  	(yyval.sym) = _newAtomNode( atom_dec(SA, &t, value, val));
		   } else {
			char *p = (yyvsp[0].sval);
			double val;

			errno = 0;
			val = strtod((yyvsp[0].sval),&p);
			if (p == (yyvsp[0].sval) || val == dbl_nil || (errno == ERANGE && (val < -1 || val > 1))) {
				char *msg = sql_message(SQLSTATE(22003) "Double value too large or not a number (%s)", (yyvsp[0].sval));

				yyerror(m, msg);
				_DELETE(msg);
				(yyval.sym) = NULL;
				YYABORT;
			}
		  	sql_find_subtype(&t, "double", 51, 0 );
		  	(yyval.sym) = _newAtomNode(atom_float(SA, &t, val));
		   }
		}
#line 12456 "y.tab.c" /* yacc.c:1646  */
    break;

  case 813:
#line 4557 "sql_parser.y" /* yacc.c:1646  */
    { sql_subtype t;
  		  char *p = (yyvsp[0].sval);
		  double val;

		  errno = 0;
 		  val = strtod((yyvsp[0].sval),&p);
		  if (p == (yyvsp[0].sval) || val == dbl_nil || (errno == ERANGE && (val < -1 || val > 1))) {
			char *msg = sql_message(SQLSTATE(22003) "Double value too large or not a number (%s)", (yyvsp[0].sval));

			yyerror(m, msg);
			_DELETE(msg);
			(yyval.sym) = NULL;
			YYABORT;
		  }
		  sql_find_subtype(&t, "double", 51, 0 );
		  (yyval.sym) = _newAtomNode(atom_float(SA, &t, val)); }
#line 12477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 814:
#line 4574 "sql_parser.y" /* yacc.c:1646  */
    { sql_subtype t;
		  atom *a;
		  int r;

 		  r = sql_find_subtype(&t, "date", 0, 0 );
		  if (!r || (a = atom_general(SA, &t, (yyvsp[0].sval))) == NULL) {
			char *msg = sql_message(SQLSTATE(22007) "Incorrect date value (%s)", (yyvsp[0].sval));

			yyerror(m, msg);
			_DELETE(msg);
			(yyval.sym) = NULL;
			YYABORT;
		  } else {
		  	(yyval.sym) = _newAtomNode(a);
		} }
#line 12497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 815:
#line 4590 "sql_parser.y" /* yacc.c:1646  */
    { sql_subtype t;
		  atom *a;
		  int r;

	          r = sql_find_subtype(&t, ((yyvsp[-1].bval))?"timetz":"time", (yyvsp[-2].i_val), 0);
		  if (!r || (a = atom_general(SA, &t, (yyvsp[0].sval))) == NULL) {
			char *msg = sql_message(SQLSTATE(22007) "Incorrect time value (%s)", (yyvsp[0].sval));

			yyerror(m, msg);
			_DELETE(msg);
			(yyval.sym) = NULL;
			YYABORT;
		  } else {
		  	(yyval.sym) = _newAtomNode(a);
		} }
#line 12517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 816:
#line 4606 "sql_parser.y" /* yacc.c:1646  */
    { sql_subtype t;
		  atom *a;
		  int r;

 		  r = sql_find_subtype(&t, ((yyvsp[-1].bval))?"timestamptz":"timestamp",(yyvsp[-2].i_val),0);
		  if (!r || (a = atom_general(SA, &t, (yyvsp[0].sval))) == NULL) {
			char *msg = sql_message(SQLSTATE(22007) "Incorrect timestamp value (%s)", (yyvsp[0].sval));

			yyerror(m, msg);
			_DELETE(msg);
			(yyval.sym) = NULL;
			YYABORT;
		  } else {
		  	(yyval.sym) = _newAtomNode(a);
		} }
#line 12537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 818:
#line 4623 "sql_parser.y" /* yacc.c:1646  */
    { sql_subtype t;
		  atom *a= 0;
		  int r;

		  (yyval.sym) = NULL;
 		  r = sql_find_subtype(&t, "blob", 0, 0);
	          if (r && (a = atom_general(SA, &t, (yyvsp[0].sval))) != NULL)
			(yyval.sym) = _newAtomNode(a);
		  if (!(yyval.sym)) {
			char *msg = sql_message(SQLSTATE(22M28) "incorrect blob %s", (yyvsp[0].sval));

			yyerror(m, msg);
			_DELETE(msg);
			YYABORT;
		  }
		}
#line 12558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 819:
#line 4640 "sql_parser.y" /* yacc.c:1646  */
    { sql_subtype t;
		  atom *a= 0;
		  int r;

		  (yyval.sym) = NULL;
		  r = sql_find_subtype(&t, (yyvsp[-1].sval), 0, 0);
	          if (r && (a = atom_general(SA, &t, (yyvsp[0].sval))) != NULL)
			(yyval.sym) = _newAtomNode(a);
		  if (!(yyval.sym)) {
			char *msg = sql_message(SQLSTATE(22000) "incorrect %s %s", (yyvsp[-1].sval), (yyvsp[0].sval));

			yyerror(m, msg);
			_DELETE(msg);
			YYABORT;
		  }
		}
#line 12579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 820:
#line 4657 "sql_parser.y" /* yacc.c:1646  */
    { sql_subtype t; 
		  atom *a = 0;
		  int r;

		  (yyval.sym) = NULL;
		  r = sql_find_subtype(&t, (yyvsp[-1].sval), 0, 0);
	          if (r && (a = atom_general(SA, &t, (yyvsp[0].sval))) != NULL)
			(yyval.sym) = _newAtomNode(a);
		  if (!(yyval.sym)) {
			char *msg = sql_message(SQLSTATE(22000) "incorrect %s %s", (yyvsp[-1].sval), (yyvsp[0].sval));

			yyerror(m, msg);
			_DELETE(msg);
			YYABORT;
		  }
		}
#line 12600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 821:
#line 4674 "sql_parser.y" /* yacc.c:1646  */
    {
		  sql_type *t = mvc_bind_type(m, (yyvsp[-1].sval));
		  atom *a;

		  (yyval.sym) = NULL;
		  if (t) {
		  	sql_subtype tpe;
			sql_init_subtype(&tpe, t, 0, 0);
			a = atom_general(SA, &tpe, (yyvsp[0].sval));
			if (a)
				(yyval.sym) = _newAtomNode(a);
		  }
		  if (!t || !(yyval.sym)) {
			char *msg = sql_message(SQLSTATE(22000) "type (%s) unknown", (yyvsp[-1].sval));

			yyerror(m, msg);
			_DELETE(msg);
			YYABORT;
		  }
		}
#line 12625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 822:
#line 4695 "sql_parser.y" /* yacc.c:1646  */
    { sql_subtype t;
		  sql_find_subtype(&t, "boolean", 0, 0 );
		  (yyval.sym) = _newAtomNode( atom_bool(SA, &t, FALSE)); }
#line 12633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 823:
#line 4699 "sql_parser.y" /* yacc.c:1646  */
    { sql_subtype t;
		  sql_find_subtype(&t, "boolean", 0, 0 );
		  (yyval.sym) = _newAtomNode( atom_bool(SA, &t, TRUE)); }
#line 12641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 824:
#line 4705 "sql_parser.y" /* yacc.c:1646  */
    { 
		sql_subtype t;
		int sk, ek, sp, ep, tpe;
	  	lng i = 0;
		int r = 0;

		(yyval.sym) = NULL;
	  	if ( (tpe = parse_interval_qualifier( m, (yyvsp[0].l), &sk, &ek, &sp, &ep )) < 0){
			yyerror(m, "incorrect interval");
			YYABORT;
	  	} else {
			int d = inttype2digits(sk, ek);
			if (tpe == 0){
				r=sql_find_subtype(&t, "month_interval", d, 0);
			} else {
				r=sql_find_subtype(&t, "sec_interval", d, 0);
			}
	  	}
	  	if (!r || (tpe = parse_interval( m, (yyvsp[-2].i_val), (yyvsp[-1].sval), sk, ek, sp, ep, &i)) < 0) { 
			yyerror(m, "incorrect interval");
			(yyval.sym) = NULL;
			YYABORT;
	  	} else {
			/* count the number of digits in the input */
/*
			lng cpyval = i, inlen = 1;

			cpyval /= qualifier2multiplier(ek);
			while (cpyval /= 10)
				inlen++;
		    	if (inlen > t.digits) {
				char *msg = sql_message(SQLSTATE(22006) "incorrect interval (" LLFMT " > %d)", inlen, t.digits);
				yyerror(m, msg);
				$$ = NULL;
				YYABORT;
			}
*/
	  		(yyval.sym) = _newAtomNode( atom_int(SA, &t, i));
	  	}
	}
#line 12686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 825:
#line 4750 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_string(L(), (yyvsp[0].sval)); }
#line 12692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 826:
#line 4751 "sql_parser.y" /* yacc.c:1646  */
    {
				  m->scanner.schema = (yyvsp[-2].sval);
				  (yyval.l) = append_string(
					append_string(L(), (yyvsp[-2].sval)), (yyvsp[0].sval));}
#line 12701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 827:
#line 4755 "sql_parser.y" /* yacc.c:1646  */
    {
				  m->scanner.schema = (yyvsp[-4].sval);
				  (yyval.l) = append_string(
					append_string(
						append_string(L(), (yyvsp[-4].sval)), 
						(yyvsp[-2].sval)), 
					(yyvsp[0].sval))
				;}
#line 12714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 828:
#line 4766 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_string(
				L(), (yyvsp[0].sval)); }
#line 12721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 829:
#line 4769 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_string(
				append_string(
				 L(), (yyvsp[-2].sval)), (yyvsp[0].sval));}
#line 12729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 830:
#line 4774 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_string(
				append_string(
				 append_string(
				  L(), (yyvsp[-4].sval)), (yyvsp[-2].sval)), (yyvsp[0].sval));}
#line 12738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 831:
#line 4782 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_symbol(l, (yyvsp[-3].sym));
	  append_type(l, &(yyvsp[-1].type));
	  (yyval.sym) = _symbol_create_list( SQL_CAST, l ); }
#line 12747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 832:
#line 4788 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_symbol(l, (yyvsp[-3].sym));
	  append_type(l, &(yyvsp[-1].type));
	  (yyval.sym) = _symbol_create_list( SQL_CAST, l ); }
#line 12756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 834:
#line 4800 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list(SQL_NULLIF,
		   append_symbol(
		    append_symbol(
		     L(), (yyvsp[-3].sym)), (yyvsp[-1].sym))); }
#line 12765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 835:
#line 4805 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list(SQL_COALESCE, (yyvsp[-1].l)); }
#line 12771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 836:
#line 4807 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list(SQL_CASE,
		   append_symbol(
		    append_list(
		     append_symbol(
		      L(),(yyvsp[-3].sym)),(yyvsp[-2].l)),(yyvsp[-1].sym))); }
#line 12781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 837:
#line 4813 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list(SQL_CASE,
		   append_symbol(
		    append_list(
		     L(),(yyvsp[-2].l)),(yyvsp[-1].sym))); }
#line 12790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 838:
#line 4821 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol( L(), (yyvsp[0].sym)); }
#line 12796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 839:
#line 4823 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol( (yyvsp[-2].l), (yyvsp[0].sym)); }
#line 12802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 840:
#line 4828 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol( L(), (yyvsp[-2].sym));
			  (yyval.l) = append_symbol( (yyval.l), (yyvsp[0].sym));
			}
#line 12810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 841:
#line 4832 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol( (yyvsp[-2].l), (yyvsp[0].sym)); }
#line 12816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 842:
#line 4838 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list( SQL_WHEN,
			   append_symbol(
			    append_symbol(
			     L(), (yyvsp[-2].sym)),(yyvsp[0].sym))); }
#line 12825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 843:
#line 4846 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol( L(), (yyvsp[0].sym));}
#line 12831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 844:
#line 4848 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol( (yyvsp[-1].l), (yyvsp[0].sym)); }
#line 12837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 845:
#line 4853 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list( SQL_WHEN,
			   append_symbol(
			    append_symbol(
			     L(), (yyvsp[-2].sym)),(yyvsp[0].sym))); }
#line 12846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 846:
#line 4861 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol( L(), (yyvsp[0].sym)); }
#line 12852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 847:
#line 4863 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol( (yyvsp[-1].l), (yyvsp[0].sym)); }
#line 12858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 848:
#line 4867 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = NULL; }
#line 12864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 849:
#line 4868 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[0].sym); }
#line 12870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 851:
#line 4878 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = (yyvsp[0].i_val);
		  if ((yyval.i_val) <= 0) {
			(yyval.i_val) = -1;
			yyerror(m, "Positive value greater than 0 expected");
			YYABORT;
		  }
		}
#line 12882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 852:
#line 4889 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l_val) = (yyvsp[0].l_val);
		  if ((yyval.l_val) <= 0) {
			(yyval.l_val) = -1;
			yyerror(m, "Positive value greater than 0 expected");
			YYABORT;
		  }
		}
#line 12894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 853:
#line 4899 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l_val) = (yyvsp[0].l_val);
		  if ((yyval.l_val) < 0) {
			(yyval.l_val) = -1;
			yyerror(m, "Positive value expected");
			YYABORT;
		  }
		}
#line 12906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 854:
#line 4909 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = (yyvsp[0].i_val);
		  if ((yyval.i_val) < 0) {
			(yyval.i_val) = -1;
			yyerror(m, "Positive value expected");
			YYABORT;
		  }
		}
#line 12918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 855:
#line 4920 "sql_parser.y" /* yacc.c:1646  */
    { sql_find_subtype(&(yyval.type), "char", 1, 0); }
#line 12924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 856:
#line 4922 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.type).type = NULL;
			  yyerror(m, "CHARACTER VARYING needs a mandatory length specification");
			  YYABORT;
			}
#line 12933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 857:
#line 4926 "sql_parser.y" /* yacc.c:1646  */
    { sql_find_subtype(&(yyval.type), "clob", 0, 0); }
#line 12939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 858:
#line 4928 "sql_parser.y" /* yacc.c:1646  */
    { sql_find_subtype(&(yyval.type), "char", (yyvsp[-1].i_val), 0); }
#line 12945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 859:
#line 4930 "sql_parser.y" /* yacc.c:1646  */
    { sql_find_subtype(&(yyval.type), "varchar", (yyvsp[-1].i_val), 0); }
#line 12951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 860:
#line 4932 "sql_parser.y" /* yacc.c:1646  */
    { sql_find_subtype(&(yyval.type), "clob", (yyvsp[-1].i_val), 0);
			  /* NOTE: CLOB may be called as CLOB(2K) which is equivalent
			   *       to CLOB(2048).  Due to 'nonzero' it is not possible
			   *       to enter this as the parser rejects it.  However it
			   *       might be a ToDo for the future.
			   *       See p. 125 SQL-99
			   */
			}
#line 12964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 861:
#line 4940 "sql_parser.y" /* yacc.c:1646  */
    { sql_find_subtype(&(yyval.type), "blob", 0, 0); }
#line 12970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 862:
#line 4942 "sql_parser.y" /* yacc.c:1646  */
    { sql_find_subtype(&(yyval.type), "blob", (yyvsp[-1].i_val), 0);
			  /* NOTE: BLOB may be called as BLOB(2K) which is equivalent
			   *       to BLOB(2048).  Due to 'nonzero' it is not possible
			   *       to enter this as the parser rejects it.  However it
			   *       might be a ToDo for the future.
			   *       See p. 85 SQL-99
			   */
			}
#line 12983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 863:
#line 4950 "sql_parser.y" /* yacc.c:1646  */
    { sql_find_subtype(&(yyval.type), "tinyint", 0, 0); }
#line 12989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 864:
#line 4951 "sql_parser.y" /* yacc.c:1646  */
    { sql_find_subtype(&(yyval.type), "smallint", 0, 0); }
#line 12995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 865:
#line 4952 "sql_parser.y" /* yacc.c:1646  */
    { sql_find_subtype(&(yyval.type), "int", 0, 0); }
#line 13001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 866:
#line 4953 "sql_parser.y" /* yacc.c:1646  */
    { sql_find_subtype(&(yyval.type), "bigint", 0, 0); }
#line 13007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 867:
#line 4954 "sql_parser.y" /* yacc.c:1646  */
    { sql_find_subtype(&(yyval.type), "hugeint", 0, 0); }
#line 13013 "y.tab.c" /* yacc.c:1646  */
    break;

  case 868:
#line 4956 "sql_parser.y" /* yacc.c:1646  */
    { sql_find_subtype(&(yyval.type), "decimal", 18, 3); }
#line 13019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 869:
#line 4958 "sql_parser.y" /* yacc.c:1646  */
    { 
			  int d = (yyvsp[-1].i_val);
			  if (d > MAX_DEC_DIGITS) {
				char *msg = sql_message(SQLSTATE(22003) "Decimal of %d digits are not supported", d);
				yyerror(m, msg);
				_DELETE(msg);
				(yyval.type).type = NULL;
				YYABORT;
			  } else {
			        sql_find_subtype(&(yyval.type), "decimal", d, 0); 
			  }
			}
#line 13036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 870:
#line 4971 "sql_parser.y" /* yacc.c:1646  */
    { 
			  int d = (yyvsp[-3].i_val);
			  int s = (yyvsp[-1].i_val);
			  if (s > d || d > MAX_DEC_DIGITS) {
				char *msg = NULL;
				if (s > d)
					msg = sql_message(SQLSTATE(22003) "Scale (%d) should be less or equal to the precision (%d)", s, d);
				else
					msg = sql_message(SQLSTATE(22003) "Decimal(%d,%d) isn't supported because P=%d > %d", d, s, d, MAX_DEC_DIGITS);
				yyerror(m, msg);
				_DELETE(msg);
				(yyval.type).type = NULL;
				YYABORT;
			  } else {
				sql_find_subtype(&(yyval.type), "decimal", d, s);
			  }
			}
#line 13058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 871:
#line 4988 "sql_parser.y" /* yacc.c:1646  */
    { sql_find_subtype(&(yyval.type), "double", 0, 0); }
#line 13064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 872:
#line 4990 "sql_parser.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].i_val) > 0 && (yyvsp[-1].i_val) <= 24) {
				sql_find_subtype(&(yyval.type), "real", (yyvsp[-1].i_val), 0);
			  } else if ((yyvsp[-1].i_val) > 24 && (yyvsp[-1].i_val) <= 53) {
				sql_find_subtype(&(yyval.type), "double", (yyvsp[-1].i_val), 0);
			  } else {
				char *msg = sql_message(SQLSTATE(22003) "Number of digits for FLOAT values should be between 1 and 53");

				yyerror(m, msg);
				_DELETE(msg);
				(yyval.type).type = NULL;
				YYABORT;
			  }
			}
#line 13082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 873:
#line 5004 "sql_parser.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].i_val) >= (yyvsp[-3].i_val)) {
				char *msg = sql_message(SQLSTATE(22003) "Precision(%d) should be less than number of digits(%d)", (yyvsp[-1].i_val), (yyvsp[-3].i_val));

				yyerror(m, msg);
				_DELETE(msg);
				(yyval.type).type = NULL;
				YYABORT;
			  } else if ((yyvsp[-3].i_val) > 0 && (yyvsp[-3].i_val) <= 24) {
				sql_find_subtype(&(yyval.type), "real", (yyvsp[-3].i_val), (yyvsp[-1].i_val));
			  } else if ((yyvsp[-3].i_val) > 24 && (yyvsp[-3].i_val) <= 53) {
				sql_find_subtype(&(yyval.type), "double", (yyvsp[-3].i_val), (yyvsp[-1].i_val));
			  } else {
				char *msg = sql_message(SQLSTATE(22003) "Number of digits for FLOAT values should be between 1 and 53");
				yyerror(m, msg);
				_DELETE(msg);
				(yyval.type).type = NULL;
				YYABORT;
			  }
			}
#line 13106 "y.tab.c" /* yacc.c:1646  */
    break;

  case 874:
#line 5023 "sql_parser.y" /* yacc.c:1646  */
    { sql_find_subtype(&(yyval.type), "double", 0, 0); }
#line 13112 "y.tab.c" /* yacc.c:1646  */
    break;

  case 875:
#line 5024 "sql_parser.y" /* yacc.c:1646  */
    { sql_find_subtype(&(yyval.type), "double", 0, 0); }
#line 13118 "y.tab.c" /* yacc.c:1646  */
    break;

  case 876:
#line 5025 "sql_parser.y" /* yacc.c:1646  */
    { sql_find_subtype(&(yyval.type), "real", 0, 0); }
#line 13124 "y.tab.c" /* yacc.c:1646  */
    break;

  case 879:
#line 5028 "sql_parser.y" /* yacc.c:1646  */
    { sql_find_subtype(&(yyval.type), (yyvsp[0].sval), 0, 0); }
#line 13130 "y.tab.c" /* yacc.c:1646  */
    break;

  case 880:
#line 5030 "sql_parser.y" /* yacc.c:1646  */
    { sql_find_subtype(&(yyval.type), (yyvsp[-3].sval), (yyvsp[-1].i_val), 0); }
#line 13136 "y.tab.c" /* yacc.c:1646  */
    break;

  case 881:
#line 5031 "sql_parser.y" /* yacc.c:1646  */
    { sql_find_subtype(&(yyval.type), (yyvsp[0].sval), 0, 0); }
#line 13142 "y.tab.c" /* yacc.c:1646  */
    break;

  case 882:
#line 5033 "sql_parser.y" /* yacc.c:1646  */
    { sql_find_subtype(&(yyval.type), (yyvsp[-3].sval), (yyvsp[-1].i_val), 0); }
#line 13148 "y.tab.c" /* yacc.c:1646  */
    break;

  case 883:
#line 5035 "sql_parser.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].i_val) >= (yyvsp[-3].i_val)) {
				char *msg = sql_message(SQLSTATE(22003) "Precision(%d) should be less than number of digits(%d)", (yyvsp[-1].i_val), (yyvsp[-3].i_val));

				yyerror(m, msg);
				_DELETE(msg);
				(yyval.type).type = NULL;
				YYABORT;
			  } else {
			 	sql_find_subtype(&(yyval.type), (yyvsp[-5].sval), (yyvsp[-3].i_val), (yyvsp[-1].i_val));
			  }
			}
#line 13164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 884:
#line 5046 "sql_parser.y" /* yacc.c:1646  */
    {
			  sql_type *t = mvc_bind_type(m, (yyvsp[0].sval));
			  if (!t) {
				char *msg = sql_message(SQLSTATE(22000) "Type (%s) unknown", (yyvsp[0].sval));

				yyerror(m, msg);
				_DELETE(msg);
				(yyval.type).type = NULL;
				YYABORT;
			  } else {
				sql_init_subtype(&(yyval.type), t, 0, 0);
			  }
			}
#line 13182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 885:
#line 5061 "sql_parser.y" /* yacc.c:1646  */
    {
			  sql_type *t = mvc_bind_type(m, (yyvsp[-3].sval));
			  if (!t) {
				char *msg = sql_message(SQLSTATE(22000) "Type (%s) unknown", (yyvsp[-3].sval));

				yyerror(m, msg);
				_DELETE(msg);
				(yyval.type).type = NULL;
				YYABORT;
			  } else {
				sql_init_subtype(&(yyval.type), t, (yyvsp[-1].i_val), 0);
			  }
			}
#line 13200 "y.tab.c" /* yacc.c:1646  */
    break;

  case 886:
#line 5074 "sql_parser.y" /* yacc.c:1646  */
    {
		if (!sql_find_subtype(&(yyval.type), "geometry", 0, 0 )) {
			yyerror(m, SQLSTATE(22000) "type (geometry) unknown");
			(yyval.type).type = NULL;
			YYABORT;
		}
	}
#line 13212 "y.tab.c" /* yacc.c:1646  */
    break;

  case 887:
#line 5081 "sql_parser.y" /* yacc.c:1646  */
    {
		int geoSubType = (yyvsp[-1].i_val); 

		if(geoSubType == 0) {
			(yyval.type).type = NULL;
			YYABORT;
		} else if (!sql_find_subtype(&(yyval.type), "geometry", geoSubType, 0 )) {
			char *msg = sql_message(SQLSTATE(22000) "Type (%s) unknown", (yyvsp[-3].sval));
			yyerror(m, msg);
			_DELETE(msg);
			(yyval.type).type = NULL;
			YYABORT;
		}
		
	}
#line 13232 "y.tab.c" /* yacc.c:1646  */
    break;

  case 888:
#line 5096 "sql_parser.y" /* yacc.c:1646  */
    {
		int geoSubType = (yyvsp[-3].i_val); 
		int srid = (yyvsp[-1].i_val); 

		if(geoSubType == 0) {
			(yyval.type).type = NULL;
			YYABORT;
		} else if (!sql_find_subtype(&(yyval.type), "geometry", geoSubType, srid )) {
			char *msg = sql_message(SQLSTATE(22000) "Type (%s) unknown", (yyvsp[-5].sval));
			yyerror(m, msg);
			_DELETE(msg);
			(yyval.type).type = NULL;
			YYABORT;
		}
	}
#line 13252 "y.tab.c" /* yacc.c:1646  */
    break;

  case 889:
#line 5111 "sql_parser.y" /* yacc.c:1646  */
    {
		if (!sql_find_subtype(&(yyval.type), "geometrya", 0, 0 )) {
			yyerror(m, SQLSTATE(22000) "type (geometrya) unknown");
			(yyval.type).type = NULL;
			YYABORT;
		}
	}
#line 13264 "y.tab.c" /* yacc.c:1646  */
    break;

  case 890:
#line 5118 "sql_parser.y" /* yacc.c:1646  */
    {
	int geoSubType = find_subgeometry_type((yyvsp[0].sval));

	if(geoSubType == 0) {
		char *msg = sql_message(SQLSTATE(22000) "Type (%s) unknown", (yyvsp[0].sval));
		(yyval.type).type = NULL;
		yyerror(m, msg);
		_DELETE(msg);
		YYABORT;
	} else if (geoSubType == -1) {
		char *msg = sql_message("allocation failure");
		(yyval.type).type = NULL;
		yyerror(m, msg);
		_DELETE(msg);
		YYABORT;
	}  else if (!sql_find_subtype(&(yyval.type), "geometry", geoSubType, 0 )) {
		char *msg = sql_message(SQLSTATE(22000) "Type (%s) unknown", (yyvsp[0].sval));
		yyerror(m, msg);
		_DELETE(msg);
		(yyval.type).type = NULL;
		YYABORT;
	}
}
#line 13292 "y.tab.c" /* yacc.c:1646  */
    break;

  case 891:
#line 5144 "sql_parser.y" /* yacc.c:1646  */
    {
	int subtype = find_subgeometry_type((yyvsp[0].sval));
	char* geoSubType = (yyvsp[0].sval);

	if(subtype == 0) {
		char *msg = sql_message(SQLSTATE(22000) "Type (%s) unknown", geoSubType);
		yyerror(m, msg);
		_DELETE(msg);
		YYABORT;
	} else if(subtype == -1) {
		char *msg = sql_message("allocation failure");
		yyerror(m, msg);
		_DELETE(msg);
		YYABORT;
	} 
	(yyval.i_val) = subtype;	
}
#line 13314 "y.tab.c" /* yacc.c:1646  */
    break;

  case 892:
#line 5161 "sql_parser.y" /* yacc.c:1646  */
    {
	int subtype = find_subgeometry_type((yyvsp[0].sval));
	char* geoSubType = (yyvsp[0].sval);

	if(subtype == 0) {
		char *msg = sql_message(SQLSTATE(22000) "Type (%s) unknown", geoSubType);
		yyerror(m, msg);
		_DELETE(msg);
		YYABORT;
	} else if (subtype == -1) {
		char *msg = sql_message("allocation failure");
		yyerror(m, msg);
		_DELETE(msg);
		YYABORT;
	} 
	(yyval.i_val) = subtype;	
}
#line 13336 "y.tab.c" /* yacc.c:1646  */
    break;

  case 893:
#line 5182 "sql_parser.y" /* yacc.c:1646  */
    { 	char *t = sql_bind_alias((yyvsp[0].sval));
	  	if (!t) {
			char *msg = sql_message(SQLSTATE(22000) "Type (%s) unknown", (yyvsp[0].sval));

			yyerror(m, msg);
			_DELETE(msg);
			(yyval.sval) = NULL;
			YYABORT;
		}
		(yyval.sval) = t;
	}
#line 13352 "y.tab.c" /* yacc.c:1646  */
    break;

  case 894:
#line 5196 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[0].sval); }
#line 13358 "y.tab.c" /* yacc.c:1646  */
    break;

  case 895:
#line 5197 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[-1].sval); }
#line 13364 "y.tab.c" /* yacc.c:1646  */
    break;

  case 896:
#line 5201 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[0].sval); }
#line 13370 "y.tab.c" /* yacc.c:1646  */
    break;

  case 897:
#line 5202 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[0].sval); }
#line 13376 "y.tab.c" /* yacc.c:1646  */
    break;

  case 898:
#line 5203 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[-2].sval); }
#line 13382 "y.tab.c" /* yacc.c:1646  */
    break;

  case 899:
#line 5206 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[0].sval); }
#line 13388 "y.tab.c" /* yacc.c:1646  */
    break;

  case 900:
#line 5207 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[-2].sval); }
#line 13394 "y.tab.c" /* yacc.c:1646  */
    break;

  case 903:
#line 5215 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[0].sval); }
#line 13400 "y.tab.c" /* yacc.c:1646  */
    break;

  case 904:
#line 5216 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[0].sval); }
#line 13406 "y.tab.c" /* yacc.c:1646  */
    break;

  case 905:
#line 5217 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[0].sval); }
#line 13412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 906:
#line 5218 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[0].sval); }
#line 13418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 907:
#line 5219 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[0].sval); }
#line 13424 "y.tab.c" /* yacc.c:1646  */
    break;

  case 908:
#line 5220 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[0].sval); }
#line 13430 "y.tab.c" /* yacc.c:1646  */
    break;

  case 909:
#line 5224 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[0].sval); }
#line 13436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 910:
#line 5225 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[0].sval); }
#line 13442 "y.tab.c" /* yacc.c:1646  */
    break;

  case 911:
#line 5226 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[0].sval); }
#line 13448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 912:
#line 5227 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[0].sval); }
#line 13454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 913:
#line 5228 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[0].sval); }
#line 13460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 914:
#line 5229 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[0].sval); }
#line 13466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 915:
#line 5230 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[0].sval); }
#line 13472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 917:
#line 5235 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "large"); }
#line 13478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 918:
#line 5236 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "name"); }
#line 13484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 919:
#line 5237 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "object"); }
#line 13490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 920:
#line 5238 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "password"); }
#line 13496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 921:
#line 5239 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "path"); }
#line 13502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 922:
#line 5240 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "precision"); }
#line 13508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 923:
#line 5241 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "privileges"); }
#line 13514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 924:
#line 5242 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "role"); }
#line 13520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 925:
#line 5243 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "size"); }
#line 13526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 926:
#line 5244 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "type"); }
#line 13532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 927:
#line 5245 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "release"); }
#line 13538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 928:
#line 5246 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "value"); }
#line 13544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 929:
#line 5247 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "zone"); }
#line 13550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 930:
#line 5249 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "action"); }
#line 13556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 931:
#line 5250 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "as"); }
#line 13562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 932:
#line 5251 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "authorization"); }
#line 13568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 933:
#line 5252 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "column"); }
#line 13574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 934:
#line 5253 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "cycle"); }
#line 13580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 935:
#line 5254 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "distinct"); }
#line 13586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 936:
#line 5255 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "increment"); }
#line 13592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 937:
#line 5256 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "maxvalue"); }
#line 13598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 938:
#line 5257 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "minvalue"); }
#line 13604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 939:
#line 5258 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "plan"); }
#line 13610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 940:
#line 5259 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "schema"); }
#line 13616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 941:
#line 5260 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "start"); }
#line 13622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 942:
#line 5261 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "statement"); }
#line 13628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 943:
#line 5262 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "table"); }
#line 13634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 944:
#line 5264 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "cache"); }
#line 13640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 945:
#line 5265 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "data"); }
#line 13646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 946:
#line 5266 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "diagnostics"); }
#line 13652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 947:
#line 5267 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "match"); }
#line 13658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 948:
#line 5268 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "options"); }
#line 13664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 949:
#line 5269 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "row"); }
#line 13670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 950:
#line 5270 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "key"); }
#line 13676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 951:
#line 5271 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "language"); }
#line 13682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 952:
#line 5272 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "level"); }
#line 13688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 953:
#line 5273 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "session"); }
#line 13694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 954:
#line 5274 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "date"); }
#line 13700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 955:
#line 5275 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "time"); }
#line 13706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 956:
#line 5276 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "timestamp"); }
#line 13712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 957:
#line 5277 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "interval"); }
#line 13718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 958:
#line 5278 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "quarter"); }
#line 13724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 959:
#line 5279 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "week"); }
#line 13730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 960:
#line 5280 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "imprints"); }
#line 13736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 961:
#line 5282 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "prepare"); }
#line 13742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 962:
#line 5283 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "execute"); }
#line 13748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 963:
#line 5284 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "explain"); }
#line 13754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 964:
#line 5285 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "debug"); }
#line 13760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 965:
#line 5286 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "trace"); }
#line 13766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 966:
#line 5287 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "text"); }
#line 13772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 967:
#line 5288 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "auto_commit"); }
#line 13778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 968:
#line 5289 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "no"); }
#line 13784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 969:
#line 5291 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "strip"); }
#line 13790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 970:
#line 5292 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "whitespace"); }
#line 13796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 971:
#line 5293 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "passing"); }
#line 13802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 972:
#line 5294 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "nil"); }
#line 13808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 973:
#line 5295 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "ref"); }
#line 13814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 974:
#line 5296 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "absent"); }
#line 13820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 975:
#line 5297 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "empty"); }
#line 13826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 976:
#line 5298 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "document"); }
#line 13832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 977:
#line 5299 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "element"); }
#line 13838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 978:
#line 5300 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "content"); }
#line 13844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 979:
#line 5301 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "namespace"); }
#line 13850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 980:
#line 5302 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "returning"); }
#line 13856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 981:
#line 5303 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "location"); }
#line 13862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 982:
#line 5304 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "id"); }
#line 13868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 983:
#line 5305 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "according"); }
#line 13874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 984:
#line 5306 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "uri"); }
#line 13880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 985:
#line 5307 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "filter"); }
#line 13886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 986:
#line 5308 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "temporary"); }
#line 13892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 987:
#line 5309 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "temp"); }
#line 13898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 988:
#line 5310 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "analyze"); }
#line 13904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 989:
#line 5311 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "MinMax"); }
#line 13910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 990:
#line 5312 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "storage"); }
#line 13916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 991:
#line 5313 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "geometry"); }
#line 13922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 992:
#line 5314 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = sa_strdup(SA, "replace"); }
#line 13928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 993:
#line 5318 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_string(L(), (yyvsp[0].sval)); }
#line 13934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 994:
#line 5320 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_string((yyvsp[-2].l), (yyvsp[0].sval)); }
#line 13940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 995:
#line 5325 "sql_parser.y" /* yacc.c:1646  */
    {
		  char *end = NULL, *s = (yyvsp[0].sval);
		  int l = _strlen(s);
		  // errno might be non-zero due to other people's code
		  errno = 0;
		  if (l <= 19) {
		  	(yyval.l_val) = strtoll(s,&end,10);
		  } else {
			(yyval.l_val) = 0;
		  }
		  if (s+l != end || errno == ERANGE) {
			char *msg = sql_message(SQLSTATE(22003) "Integer value too large or not a number (%s)", (yyvsp[0].sval));

			errno = 0;
			yyerror(m, msg);
			_DELETE(msg);
			(yyval.l_val) = 0;
			YYABORT;
		  }
		}
#line 13965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 996:
#line 5348 "sql_parser.y" /* yacc.c:1646  */
    {
		  char *end = NULL, *s = (yyvsp[0].sval);
		  int l = _strlen(s);
		  // errno might be non-zero due to other people's code
		  errno = 0;
		  if (l <= 10) {
		  	(yyval.i_val) = strtol(s,&end,10);
		  } else {
			(yyval.i_val) = 0;
		  }
		  if (s+l != end || errno == ERANGE) {
			char *msg = sql_message(SQLSTATE(22003) "Integer value too large or not a number (%s)", (yyvsp[0].sval));

			errno = 0;
			yyerror(m, msg);
			_DELETE(msg);
			(yyval.i_val) = 0;
			YYABORT;
		  }
		}
#line 13990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 997:
#line 5368 "sql_parser.y" /* yacc.c:1646  */
    {
		  char *name = (yyvsp[0].sval);
		  sql_subtype *tpe;

		  if (!stack_find_var(m, name)) {
			char *msg = sql_message(SQLSTATE(22000) "Constant (%s) unknown", (yyvsp[0].sval));

			yyerror(m, msg);
			_DELETE(msg);
			(yyval.i_val) = 0;
			YYABORT;
		  }
		  tpe = stack_find_type(m, name);
		  if (tpe->type->localtype == TYPE_lng ||
		      tpe->type->localtype == TYPE_int ||
		      tpe->type->localtype == TYPE_sht ||
		      tpe->type->localtype == TYPE_bte ) {
			lng sgn = stack_get_number(m, name);
			assert((lng) GDK_int_min < sgn && sgn <= (lng) GDK_int_max);
			(yyval.i_val) = (int) sgn;
		  } else {
			char *msg = sql_message(SQLSTATE(22000) "Constant (%s) has wrong type (number expected)", (yyvsp[0].sval));

			yyerror(m, msg);
			_DELETE(msg);
			(yyval.i_val) = 0;
			YYABORT;
		  }
		}
#line 14024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 998:
#line 5401 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[0].sval); }
#line 14030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 999:
#line 5403 "sql_parser.y" /* yacc.c:1646  */
    { char *s = strconcat((yyvsp[-1].sval),(yyvsp[0].sval)); 
	 	  (yyval.sval) = sa_strdup(SA, s);	
		  _DELETE(s);
		}
#line 14039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1000:
#line 5411 "sql_parser.y" /* yacc.c:1646  */
    {
		  m->emode = m_execute;
		  (yyval.sym) = (yyvsp[0].sym); }
#line 14047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1001:
#line 5418 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
  	  append_int(l, (yyvsp[-2].i_val));
  	  append_list(l, NULL);
	  (yyval.sym) = _symbol_create_list( SQL_NOP, l ); }
#line 14056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1002:
#line 5423 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
  	  append_int(l, (yyvsp[-3].i_val));
  	  append_list(l, (yyvsp[-1].l));
	  (yyval.sym) = _symbol_create_list( SQL_NOP, l ); }
#line 14065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1003:
#line 5437 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = NULL; }
#line 14071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1005:
#line 5442 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = _symbol_create_list( SQL_PATH, (yyvsp[0].l)); }
#line 14077 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1008:
#line 5453 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol(L(), (yyvsp[0].sym)); }
#line 14083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1009:
#line 5455 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol((yyvsp[-2].l), (yyvsp[0].sym)); }
#line 14089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1021:
#line 5477 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_symbol(l, (yyvsp[-2].sym));
	  append_int(l, (yyvsp[-1].i_val));
	  (yyval.sym) = _symbol_create_list( SQL_XMLCOMMENT, l); }
#line 14098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1022:
#line 5485 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_list(l, (yyvsp[-2].l));
	  append_int(l, (yyvsp[-1].i_val));
	  (yyval.sym) = _symbol_create_list( SQL_XMLCONCAT, l); }
#line 14107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1023:
#line 5493 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_symbol(l, (yyvsp[-2].sym));
	  append_int(l, (yyvsp[-1].i_val));
	  (yyval.sym) = _symbol_create_list( SQL_XMLDOCUMENT, l); }
#line 14116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1024:
#line 5503 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_string(l, (yyvsp[-3].sval));
	  append_list(l, (yyvsp[-2].l));
	  append_int(l, (yyvsp[-1].i_val));
	  (yyval.sym) = _symbol_create_list( SQL_XMLELEMENT, l);
	}
#line 14127 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1025:
#line 5513 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = NULL; }
#line 14133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1026:
#line 5515 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol(L(), (yyvsp[0].sym));
	  (yyval.l) = append_symbol((yyval.l), NULL);
	  (yyval.l) = append_list((yyval.l), NULL); }
#line 14141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1027:
#line 5519 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol(L(), (yyvsp[-2].sym));
	  (yyval.l) = append_symbol((yyval.l), (yyvsp[0].sym));
	  (yyval.l) = append_list((yyval.l), NULL); }
#line 14149 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1028:
#line 5523 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol(L(), (yyvsp[-4].sym));
	  (yyval.l) = append_symbol((yyval.l), (yyvsp[-2].sym));
	  (yyval.l) = append_list((yyval.l), (yyvsp[0].l)); }
#line 14157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1029:
#line 5527 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol(L(), (yyvsp[-2].sym));
	  (yyval.l) = append_symbol((yyval.l), NULL);
	  (yyval.l) = append_list((yyval.l), (yyvsp[0].l)); }
#line 14165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1030:
#line 5531 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol(L(), NULL);
	  (yyval.l) = append_symbol((yyval.l), (yyvsp[0].sym));
	  (yyval.l) = append_list((yyval.l), NULL); }
#line 14173 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1031:
#line 5535 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol(L(), NULL);
	  (yyval.l) = append_symbol((yyval.l), (yyvsp[-2].sym));
	  (yyval.l) = append_list((yyval.l), (yyvsp[0].l)); }
#line 14181 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1032:
#line 5539 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol(L(), NULL);
	  (yyval.l) = append_symbol((yyval.l), NULL);
	  (yyval.l) = append_list((yyval.l), (yyvsp[0].l)); }
#line 14189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1034:
#line 5549 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[-1].sym); }
#line 14195 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1035:
#line 5553 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[0].sym); }
#line 14201 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1036:
#line 5555 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
		  append_list(l, 
		  	append_string(L(), sa_strdup(SA, "concat")));
	  	  append_symbol(l, (yyvsp[-2].sym));
	  	  append_symbol(l, (yyvsp[0].sym));
	  	  (yyval.sym) = _symbol_create_list( SQL_BINOP, l ); }
#line 14212 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1037:
#line 5565 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_string(l, (yyvsp[0].sval));
	  append_symbol(l, (yyvsp[-1].sym));
	  (yyval.sym) = _symbol_create_list( SQL_XMLATTRIBUTE, l ); }
#line 14221 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1038:
#line 5572 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = NULL; }
#line 14227 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1039:
#line 5573 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[0].sval); }
#line 14233 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1042:
#line 5586 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = L();
		  (yyval.l) = append_list((yyval.l), (yyvsp[-1].l));
		  (yyval.l) = append_int((yyval.l), (yyvsp[0].i_val)); 	}
#line 14241 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1043:
#line 5593 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol(L(), (yyvsp[0].sym)); }
#line 14247 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1044:
#line 5595 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol((yyvsp[-2].l), (yyvsp[0].sym)); }
#line 14253 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1046:
#line 5603 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 0; }
#line 14259 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1047:
#line 5604 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = (yyvsp[0].i_val); }
#line 14265 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1048:
#line 5608 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 0; }
#line 14271 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1049:
#line 5609 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 1; }
#line 14277 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1050:
#line 5610 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 2; }
#line 14283 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1051:
#line 5611 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 3; }
#line 14289 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1052:
#line 5612 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 4; }
#line 14295 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1053:
#line 5619 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_symbol(l, (yyvsp[-4].sym));
	  append_list(l, (yyvsp[-3].l));
	  append_int(l, (yyvsp[-2].i_val));
	  append_int(l, (yyvsp[-1].i_val));
	  (yyval.sym) = _symbol_create_list( SQL_XMLFOREST, l);
	}
#line 14307 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1054:
#line 5629 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = NULL; }
#line 14313 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1055:
#line 5630 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[-1].sym); }
#line 14319 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1056:
#line 5635 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_list(L(), (yyvsp[0].l)); }
#line 14325 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1057:
#line 5637 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_list((yyvsp[-2].l), (yyvsp[0].l)); }
#line 14331 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1058:
#line 5642 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.l) = append_symbol(L(), (yyvsp[-1].sym));
		  (yyval.l) = append_string((yyval.l), (yyvsp[0].sval)); }
#line 14338 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1059:
#line 5647 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[0].sym); }
#line 14344 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1060:
#line 5651 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = NULL; }
#line 14350 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1061:
#line 5652 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[0].sval); }
#line 14356 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1062:
#line 5656 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[0].sval); }
#line 14362 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1063:
#line 5663 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_int(l, (yyvsp[-3].i_val) );
	  append_symbol(l, (yyvsp[-2].sym));
	  append_int(l, (yyvsp[-1].i_val));
	  (yyval.sym) = _symbol_create_list( SQL_XMLPARSE, l); }
#line 14372 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1064:
#line 5670 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 0; }
#line 14378 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1065:
#line 5671 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 1; }
#line 14384 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1066:
#line 5678 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_string(l, (yyvsp[-3].sval));
	  append_symbol(l, (yyvsp[-2].sym));
	  append_int(l, (yyvsp[-1].i_val));
	  (yyval.sym) = _symbol_create_list( SQL_XMLPI, l); }
#line 14394 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1068:
#line 5690 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = NULL; }
#line 14400 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1069:
#line 5692 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[0].sym); }
#line 14406 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1070:
#line 5703 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = NULL; }
#line 14412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1085:
#line 5749 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  append_symbol(l, (yyvsp[-2].sym));
	  append_int(l, (yyvsp[-1].i_val));
	  (yyval.sym) = _symbol_create_list( SQL_XMLTEXT, l); }
#line 14421 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1086:
#line 5760 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = NULL; }
#line 14427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1088:
#line 5765 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 2; }
#line 14433 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1089:
#line 5769 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 0; }
#line 14439 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1090:
#line 5770 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 1; }
#line 14445 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1091:
#line 5774 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 0; }
#line 14451 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1092:
#line 5775 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 0; }
#line 14457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1093:
#line 5776 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.i_val) = 1; }
#line 14463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1094:
#line 5791 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[-1].sym); }
#line 14469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1095:
#line 5795 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = (yyvsp[0].sym); }
#line 14475 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1096:
#line 5797 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
		  append_list(l, 
		  	append_string(L(), sa_strdup(SA, "concat")));
	  	  append_symbol(l, (yyvsp[-2].sym));
	  	  append_symbol(l, (yyvsp[0].sym));
	  	  (yyval.sym) = _symbol_create_list( SQL_BINOP, l ); }
#line 14486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1101:
#line 5820 "sql_parser.y" /* yacc.c:1646  */
    { char *s = strconcat("xmlns:", (yyvsp[0].sval));
				  dlist *l = L();
	  			  append_string(l, sa_strdup(SA, s));
				  _DELETE(s);
	  			  append_symbol(l, (yyvsp[-2].sym));
	  			  (yyval.sym) = _symbol_create_list( SQL_XMLATTRIBUTE, l ); }
#line 14497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1102:
#line 5829 "sql_parser.y" /* yacc.c:1646  */
    { dlist *l = L();
	  			  append_string(l, sa_strdup(SA, "xmlns" ));
	  			  append_symbol(l, (yyvsp[0].sym));
	  			  (yyval.sym) = _symbol_create_list( SQL_XMLATTRIBUTE, l ); }
#line 14506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1103:
#line 5833 "sql_parser.y" /* yacc.c:1646  */
    { (yyval.sym) = NULL; }
#line 14512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 1133:
#line 5929 "sql_parser.y" /* yacc.c:1646  */
    { 
          dlist *aggr = L();

          if ((yyvsp[-2].sym)) {
	  	if ((yyvsp[-3].sym) != NULL && (yyvsp[-3].sym)->token == SQL_SELECT) {
			SelectNode *s = (SelectNode*)(yyvsp[-3].sym);
	
			s->orderby = (yyvsp[-2].sym);
	  	} else {
			yyerror(m, "ORDER BY: missing select operator");
			YYABORT;
		}
	  }
          append_list(aggr, append_string(append_string(L(), "sys"), "xmlagg"));
  	  append_int(aggr, FALSE);
	  append_symbol(aggr, (yyvsp[-3].sym));
	  /* int returning not used */
	  (yyval.sym) = _symbol_create_list( SQL_AGGR, aggr);
	}
#line 14536 "y.tab.c" /* yacc.c:1646  */
    break;


#line 14540 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (m, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (m, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, m);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, m);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (m, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, m);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, m);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 5950 "sql_parser.y" /* yacc.c:1906  */

int find_subgeometry_type(char* geoSubType) {
	int subType = 0;
	if(strcmp(geoSubType, "point") == 0 )
		subType = (1 << 2);
	else if(strcmp(geoSubType, "linestring") == 0)
		subType = (2 << 2);
	else if(strcmp(geoSubType, "polygon") == 0)
		subType = (4 << 2);
	else if(strcmp(geoSubType, "multipoint") == 0)
		subType = (5 << 2);
	else if(strcmp(geoSubType, "multilinestring") == 0)
		subType = (6 << 2);
	else if(strcmp(geoSubType, "multipolygon") == 0)
		subType = (7 << 2);
	else if(strcmp(geoSubType, "geometrycollection") == 0)
		subType = (8 << 2);
	else {
		size_t strLength = strlen(geoSubType);
		if(strLength > 0 ) {
			char *typeSubStr = GDKmalloc(strLength);
			char flag = geoSubType[strLength-1]; 

			if (typeSubStr == NULL) {
				return -1;
			}
			memcpy(typeSubStr, geoSubType, strLength-1);
			typeSubStr[strLength-1]='\0';
			if(flag == 'z' || flag == 'm' ) {
				subType = find_subgeometry_type(typeSubStr);
				if (subType == -1) {
					GDKfree(typeSubStr);
					return -1;
				}
				if(flag == 'z')
					SET_Z(subType);
				if(flag == 'm')
					SET_M(subType);
			}
			GDKfree(typeSubStr);
		}

	}
	return subType;	
}

char *token2string(int token)
{
	switch (token) {
#define SQL(TYPE) case SQL_##TYPE : return #TYPE
	SQL(CREATE_SCHEMA);
	SQL(CREATE_TABLE);
	SQL(CREATE_VIEW);
	SQL(CREATE_INDEX);
	SQL(CREATE_ROLE);
	SQL(CREATE_USER);
	SQL(CREATE_TYPE);
	SQL(CREATE_FUNC);
	SQL(CREATE_SEQ);
	SQL(CREATE_TRIGGER);
	SQL(DROP_SCHEMA);
	SQL(DROP_TABLE);
	SQL(DROP_VIEW);
	SQL(DROP_INDEX);
	SQL(DROP_ROLE);
	SQL(DROP_USER);
	SQL(DROP_TYPE);
	SQL(DROP_FUNC);
	SQL(DROP_SEQ);
	SQL(DROP_TRIGGER);
	SQL(ALTER_TABLE);
	SQL(ALTER_SEQ);
	SQL(ALTER_USER);
	SQL(DROP_COLUMN);
	SQL(DROP_CONSTRAINT);
	SQL(DROP_DEFAULT);
	SQL(DECLARE);
	SQL(SET);
	SQL(PREP);
	SQL(NAME);
	SQL(USER);
	SQL(PATH);
	SQL(CHARSET);
	SQL(SCHEMA);
	SQL(TABLE);
	SQL(TYPE);
	SQL(CASE);
	SQL(CAST);
	SQL(RETURN);
	SQL(IF);
	SQL(ELSE);
	SQL(WHILE);
	SQL(COLUMN);
	SQL(COLUMN_OPTIONS);
	SQL(COALESCE);
	SQL(CONSTRAINT);
	SQL(CHECK);
	SQL(DEFAULT);
	SQL(NOT_NULL);
	SQL(NULL);
	SQL(NULLIF);
	SQL(UNIQUE);
	SQL(PRIMARY_KEY);
	SQL(FOREIGN_KEY);
	SQL(BEGIN);
#define TR(TYPE) case TR_##TYPE : return #TYPE
	TR(COMMIT);
	TR(ROLLBACK);
	TR(SAVEPOINT);
	TR(RELEASE);
	TR(START);
	TR(MODE);
	SQL(INSERT);
	SQL(DELETE);
	SQL(UPDATE);
	SQL(CROSS);
	SQL(JOIN);
	SQL(SELECT);
	SQL(WHERE);
	SQL(FROM);
	SQL(UNIONJOIN);
	SQL(UNION);
	SQL(EXCEPT);
	SQL(INTERSECT);
	SQL(VALUES);
	SQL(ASSIGN);
	SQL(ORDERBY);
	SQL(GROUPBY);
	SQL(DESC);
	SQL(AND);
	SQL(OR);
	SQL(NOT);
	SQL(EXISTS);
	SQL(NOT_EXISTS);
	SQL(OP);
	SQL(UNOP);
	SQL(BINOP);
	SQL(NOP);
	SQL(BETWEEN);
	SQL(NOT_BETWEEN);
	SQL(LIKE);
	SQL(IN);
	SQL(NOT_IN);
	SQL(GRANT);
	SQL(GRANT_ROLES);
	SQL(REVOKE);
	SQL(REVOKE_ROLES);
	SQL(EXECUTE);
	SQL(PRIVILEGES);
	SQL(ROLE);
	SQL(PARAMETER);
	SQL(FUNC);
	SQL(AGGR);
	SQL(RANK);
	SQL(FRAME);
	SQL(COMPARE);
	SQL(FILTER);
	SQL(TEMP_LOCAL);
	SQL(TEMP_GLOBAL);
	SQL(INT_VALUE);
	SQL(ATOM);
	SQL(USING);
	SQL(WHEN);
	SQL(ESCAPE);
	SQL(COPYFROM);
	SQL(BINCOPYFROM);
	SQL(COPYTO);
	SQL(EXPORT);
	SQL(NEXT);
	SQL(MULSTMT);
	SQL(WITH);
	SQL(XMLCOMMENT);
	SQL(XMLCONCAT);
	SQL(XMLDOCUMENT);
	SQL(XMLELEMENT);
	SQL(XMLATTRIBUTE);
	SQL(XMLFOREST);
	SQL(XMLPARSE);
	SQL(XMLPI);
	SQL(XMLQUERY);
	SQL(XMLTEXT);
	SQL(XMLVALIDATE);
	SQL(XMLNAMESPACES);
	}
	return "unknown";	/* just needed for broken compilers ! */
}

void *sql_error( mvc * sql, int error_code, char *format, ... )
{
	va_list	ap;

	va_start (ap,format);
	if (sql->errstr[0] == '\0')
		vsnprintf(sql->errstr, ERRSIZE-1, _(format), ap);
	if (!sql->session->status)
		sql->session->status = -error_code;
	va_end (ap);
	return NULL;
}

int sqlerror(mvc * c, const char *err)
{
	const char *sqlstate;

	if (err && strlen(err) > 6 && err[5] == '!') {
		/* sql state provided */
		sqlstate = "";
	} else {
		/* default: Syntax error or access rule violation */
		sqlstate = SQLSTATE(42000);
	}
	if (c->scanner.errstr) {
		if (c->scanner.errstr[0] == '!'){
			assert(0);// catch it
			(void)sql_error(c, 4,
					"%s%s: %s\n",
					sqlstate, err, c->scanner.errstr + 1);
		} else
			(void)sql_error(c, 4,
					"%s%s: %s in \"%.80s\"\n",
					sqlstate, err, c->scanner.errstr,
					QUERY(c->scanner));
	} else
		(void)sql_error(c, 4,
				"%s%s in: \"%.80s\"\n",
				sqlstate, err, QUERY(c->scanner));
	return 1;
}

