
	#!/bin/bash

	RED='[0;31m'
	GREEN='[0;32m'
	BLUE='[0;34m'
	CYAN='[0;36m'
	NC='[0m' # No Color

	# get the number of input files automatically
	inputfilecount=$(ls -1 | grep in | wc -l)

	echo "number of test files detected to be $inputfilecount"
	g++ -std=c++17 sol.cpp -o sol

	for ((i=1; i <= $inputfilecount; i++))
	do
		file="in$i"
		echo "-----------------"

		if [ ! -f "sol" ]; then
		    echo "executable does not exist.... compile error"
		    exit 1
		fi
		./sol < $file > output$i

		DIFF=$(diff -EbwB output$i o$i) 
		if [ "$DIFF" != "" ] 
		then
			echo "Input:"
		    cat $file
		    echo ""
	    	printf "${RED}SAMPLE $i FAILED${NC}
"
			echo "obtained output:"
			printf "${BLUE}"
			cat  output$i
			printf "${NC}
"

			echo "Expected output:"
			printf "${CYAN}"
			cat o$i
			printf "${NC}
"
		fi
		if [ "$DIFF" == "" ] 
		then
	    	printf "${GREEN}SAMPLE $i PASSED${NC}
"
		fi
		echo "-----------------"
	done

	for ((i = 1; i <= $inputfilecount; i++))
	do
		rm output$i
	done

	rm sol
	
