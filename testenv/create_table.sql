drop table if exists regextest1;
drop table if exists regextest2;
drop table if exists regextest3;
drop table if exists regextest4;

create table regextest1 (id INT, name VARCHAR(1000));
create table regextest2 (id INT, name VARCHAR(1000));
create table regextest3 (id INT, name VARCHAR(1000));
create table regextest4 (id INT, name VARCHAR(1000));

COPY INTO regextest1 FROM '/tmp/database/10M_Q1.txt' USING DELIMITERS '|','\n';
COPY INTO regextest2 FROM '/tmp/database/10M_Q2.txt' USING DELIMITERS '|','\n';
COPY INTO regextest3 FROM '/tmp/database/10M_Q3.txt' USING DELIMITERS '|','\n';
COPY INTO regextest4 FROM '/tmp/database/10M_Q4.txt' USING DELIMITERS '|','\n';
