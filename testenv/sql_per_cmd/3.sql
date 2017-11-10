select count(*) from regextest where match(name, '[0-9]+(USD|EUR|GBP)');
select count(*) from regextest where regex(name, '[0-9]+(USD|EUR|GBP)');
select count(*) from regextest where dfaregex(name, '[0-9]+(USD|EUR|GBP)');
select count(*) from regextest where cre2regex(name, '[0-9]+(USD|EUR|GBP)');
select count(*) from regextest where hyperscanregex(name, '[0-9]+(USD|EUR|GBP)');
