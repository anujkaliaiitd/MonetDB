select count(*) from regextest where match(name, '[A-Za-z]{3}\:[0-9]{4}');
select count(*) from regextest where regex(name, '[A-Za-z]{3}\:[0-9]{4}');
select count(*) from regextest where dfaregex(name, '[A-Za-z]{3}\:[0-9]{4}');
select count(*) from regextest where cre2regex(name, '[A-Za-z]{3}\:[0-9]{4}');
select count(*) from regextest where hyperscanregex(name, '[A-Za-z]{3}\:[0-9]{4}');
