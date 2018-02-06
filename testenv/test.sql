select count(*) from regextest1 where name like '%Strasse%';
/*select count(*) from regextest1 where regex(name, 'Strasse'); 
select count(*) from regextest1 where dfaregex(name, 'Strasse');*/
select count(*) from regextest1 where hyperscanregex(name, 'Strasse');
select count(*) from regextest1 where lvzixun_regex(name, '.*Strasse');

select count(*) from regextest2 where match(name, '(Strasse|Str\.).*(8[0-9]{4})');
/*select count(*) from regextest2 where regex(name, '(Strasse|Str\.).*(8[0-9]{4})');
select count(*) from regextest2 where dfaregex(name, '(Strasse|Str\.).*(8[0-9]{4})');*/
select count(*) from regextest2 where hyperscanregex(name, '(Strasse|Str\.).*(8[0-9]{4})');
select count(*) from regextest2 where lvzixun_regex(name, '.*(Strasse|Str\.).*(8[0-9][0-9][0-9][0-9])');

select count(*) from regextest3 where match(name, '[0-9]+(USD|EUR|GBP)');
/*select count(*) from regextest3 where regex(name, '[0-9]+(USD|EUR|GBP)');
select count(*) from regextest3 where dfaregex(name, '[0-9]+(USD|EUR|GBP)');*/
select count(*) from regextest3 where hyperscanregex(name, '[0-9]+(USD|EUR|GBP)');
select count(*) from regextest3 where lvzixun_regex(name, '.*[0-9]+(USD|EUR|GBP)');

select count(*) from regextest4 where match(name, '[A-Za-z]{3}\:[0-9]{4}');
/*select count(*) from regextest4 where regex(name, '[A-Za-z]{3}\:[0-9]{4}');
select count(*) from regextest4 where dfaregex(name, '[A-Za-z]{3}\:[0-9]{4}');*/
select count(*) from regextest4 where hyperscanregex(name, '[A-Za-z]{3}\:[0-9]{4}');
select count(*) from regextest4 where lvzixun_regex(name, '.*[A-Za-z][A-Za-z][A-Za-z]\:[0-9][0-9][0-9][0-9]');

/*
select count(*) from regextest1 where hyperscanregex(name, 'Strasse');
select count(*) from regextest1 where lvzixun_regex(name, '.*Strasse');

select count(*) from regextest2 where hyperscanregex(name, '(Strasse|Str\.).*(8[0-9]{4})');
select count(*) from regextest2 where lvzixun_regex(name, '.*(Strasse|Str\.).*(8[0-9][0-9][0-9][0-9])');

select count(*) from regextest3 where hyperscanregex(name, '[0-9]+(USD|EUR|GBP)');
select count(*) from regextest3 where lvzixun_regex(name, '.*[0-9]+(USD|EUR|GBP)');

select count(*) from regextest4 where hyperscanregex(name, '[A-Za-z]{3}\:[0-9]{4}');
select count(*) from regextest4 where lvzixun_regex(name, '.*[A-Za-z][A-Za-z][A-Za-z]\:[0-9][0-9][0-9][0-9]');
*/
/*
select count(*) from regextest1 where lvzixun_regex(name, '.*Strasse');
select count(*) from regextest2 where lvzixun_regex(name, '.*(Strasse|Str\.).*(8[0-9][0-9][0-9][0-9])');
select count(*) from regextest3 where lvzixun_regex(name, '.*[0-9]+(USD|EUR|GBP)');
select count(*) from regextest4 where lvzixun_regex(name, '.*[A-Za-z][A-Za-z][A-Za-z]\:[0-9][0-9][0-9][0-9]');
*/
