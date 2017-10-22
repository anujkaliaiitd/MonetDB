-- This Source Code Form is subject to the terms of the Mozilla Public
-- License, v. 2.0.  If a copy of the MPL was not distributed with this
-- file, You can obtain one at http://mozilla.org/MPL/2.0/.
--
-- Copyright 1997 - July 2008 CWI, August 2008 - 2017 MonetDB B.V.

-- add function signatures to SQL catalog

create function regex(pattern string, src string)
returns int external name udf.regex;

create function dfaregex(pattern string, src string)
returns int external name udf.dfaregex;

create function hyperscanregex(pattern string, src string)
returns int external name udf.hyperscanregex;

create function pcre_match(s string, pattern string)
returns BOOLEAN external name pcre.match;

create function pcre_imatch(s string, pattern string)
returns BOOLEAN external name pcre.imatch;
