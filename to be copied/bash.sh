#!/bin/bash
for((i = 0; i < 500; i++))
do
	echo $i
	./gen > input.txt
	./template < input.txt > output.txt
	./brute < input.txt > correct_output.txt
	diff -w output.txt correct_output.txt || break
done
