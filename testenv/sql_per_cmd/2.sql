select count(*) from regextest where match(name, '(Strasse|Str\.).*(8[0-9]{4})');
select count(*) from regextest where regex(name, '(Strasse|Str\.).*(8[0-9]{4})');
select count(*) from regextest where dfaregex(name, '(Strasse|Str\.).*(8[0-9]{4})');
select count(*) from regextest where cre2regex(name, '(Strasse|Str\.).*(8[0-9]{4})');
select count(*) from regextest where hyperscanregex(name, '(Strasse|Str\.).*(8[0-9]{4})');
