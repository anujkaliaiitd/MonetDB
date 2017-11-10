select count(*) from regextest where name like '%Strasse%';
select count(*) from regextest where regex(name, 'Strasse');
select count(*) from regextest where dfaregex(name, 'Strasse');
select count(*) from regextest where cre2regex(name, 'Strasse');
select count(*) from regextest where hyperscanregex(name, 'Strasse');

