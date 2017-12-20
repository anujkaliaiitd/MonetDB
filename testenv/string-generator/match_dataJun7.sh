#!/bin/bash
egrep ".*Strasse.*" 10M_Q1.txt | wc -l
egrep "(Strasse|Str\.).*(8[0-9]{4})" 10M_Q2.txt | wc -l
egrep "[0-9]+(USD|EUR|GBP)" 10M_Q3.txt | wc -l
egrep "[A-Za-z]{3}\:[0-9]{4}" 10M_Q4.txt | wc -l

#egrep ".*Strasse.*" foo.txt
#egrep "(Strasse|Str\.).*(8[0-9]{4})" foo.txt
#egrep "[0-9]+(USD|EUR|GBP)" foo.txt
#egrep "[A-Za-z]{3}\:[0-9]{4}" foo.txt
