./generate_input --input-file dataJun7-2016-clean.csv --num-string 10000000 --selectivity 0.2
mv generate.out 10M_Q1.txt

./generate_input --input-file dataJun7-2016-clean.csv --num-string 10000000 --pattern 3 --selectivity 0.2
mv generate.out 10M_Q2.txt

./generate_input --input-file dataJun7-2016-clean.csv --num-string 10000000 --pattern 4 --selectivity 0.2
mv generate.out 10M_Q3.txt

./generate_input --input-file dataJun7-2016-clean.csv --num-string 10000000 --pattern 5 --selectivity 0.2
mv generate.out 10M_Q4.txt



