#!/bin/bash
for((i = 0; i < 500; i++))
do
	echo $i
	./gen $i > random_input.txt
	./e < random_input.txt > my_output.txt
	./brute < random_input.txt > correct_output.txt
	diff -w my_output.txt correct_output.txt || break
done
