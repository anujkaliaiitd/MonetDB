drop table if exists smallregextest1;
drop table if exists smallregextest2;
drop table if exists smallregextest3;
drop table if exists smallregextest4;

create table smallregextest1 (id INT, name VARCHAR(1000));
create table smallregextest2 (id INT, name VARCHAR(1000));
create table smallregextest3 (id INT, name VARCHAR(1000));
create table smallregextest4 (id INT, name VARCHAR(1000));

COPY INTO smallregextest1 FROM '/home/xzhang3/pattern_match_datasets/100_Q1.txt' USING DELIMITERS '|','\n';
COPY INTO smallregextest2 FROM '/home/xzhang3/pattern_match_datasets/100_Q2.txt' USING DELIMITERS '|','\n';
COPY INTO smallregextest3 FROM '/home/xzhang3/pattern_match_datasets/100_Q3.txt' USING DELIMITERS '|','\n';
COPY INTO smallregextest4 FROM '/home/xzhang3/pattern_match_datasets/100_Q4.txt' USING DELIMITERS '|','\n';

drop table if exists regextest1;
drop table if exists regextest2;
drop table if exists regextest3;
drop table if exists regextest4;

create table regextest1 (id INT, name VARCHAR(1000));
create table regextest2 (id INT, name VARCHAR(1000));
create table regextest3 (id INT, name VARCHAR(1000));
create table regextest4 (id INT, name VARCHAR(1000));

COPY INTO regextest1 FROM '/home/xzhang3/pattern_match_datasets/10M_Q1.txt' USING DELIMITERS '|','\n';
COPY INTO regextest2 FROM '/home/xzhang3/pattern_match_datasets/10M_Q2.txt' USING DELIMITERS '|','\n';
COPY INTO regextest3 FROM '/home/xzhang3/pattern_match_datasets/10M_Q3.txt' USING DELIMITERS '|','\n';
COPY INTO regextest4 FROM '/home/xzhang3/pattern_match_datasets/10M_Q4.txt' USING DELIMITERS '|','\n';
