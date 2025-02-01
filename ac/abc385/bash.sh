#!/bin/bash
for((i = 0; i < 500; i++))
do
	echo $i
	./gen $i > input.txt
	./d < input.txt > my_output.txt
	./brute < input.txt > output.txt
	diff -w my_output.txt output.txt || break
done
