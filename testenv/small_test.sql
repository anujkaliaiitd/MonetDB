/*
select count(*) from smallregextest1 where regex(name, 'Strasse');
select count(*) from smallregextest2 where regex(name, '(Strasse|Str\.).*(8[0-9]{4})');
select count(*) from smallregextest3 where regex(name, '[0-9]+(USD|EUR|GBP)');
select count(*) from smallregextest4 where regex(name, '[A-Za-z]{3}\:[0-9]{4}');
*/
select count(*) from smallregextest1 where hyperscanregex(name, 'Strasse');
select count(*) from smallregextest2 where hyperscanregex(name, '(Strasse|Str\.).*(8[0-9]{4})');
select count(*) from smallregextest3 where hyperscanregex(name, '[0-9]+(USD|EUR|GBP)');
select count(*) from smallregextest4 where hyperscanregex(name, '[A-Za-z]{3}\:[0-9]{4}');

select count(*) from smallregextest1 where myregex(name, '.*Strasse');
select count(*) from smallregextest2 where myregex(name, '.*(Strasse|Str\.).*(8[0-9][0-9][0-9][0-9])');
select count(*) from smallregextest3 where myregex(name, '.*[0-9]+(USD|EUR|GBP)');
select count(*) from smallregextest4 where myregex(name, '.*[A-Za-z][A-Za-z][A-Za-z]\:[0-9][0-9][0-9][0-9]');
