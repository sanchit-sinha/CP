
	#!/bin/bash

	g++ testgen.cpp -o testgen -std=c++17
	g++ sol.cpp -o sol -std=c++17
	g++ brute.cpp -o brute -std=c++17

	for((i=1; i<=1000;i++))
	do
		./testgen > stress
		./sol < stress > codeoutput
		./brute < stress > checkeroutput
		echo "random test number $i passed"
		DIFF=$(diff -bwB codeoutput checkeroutput)

		if [ "$DIFF" != "" ] 
		then
			# get the number of input files automatically
	        inputfilecount=$(ls -1 | grep in | wc -l)
	        ((newinput=inputfilecount+1))
			echo "input " 
			cat stress > in$newinput
			cat stress
			echo "obtained output"
			cat codeoutput
			echo "brute output"
			cat checkeroutput
			cat checkeroutput > o$newinput
			exit 1
		fi
		rm stress
	done
	
