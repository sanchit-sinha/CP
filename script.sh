#/bin/bash/

for dir in A B C D E F G H I 
do
	echo "creating directory $dir"
	mkdir $dir
	cd $dir
	echo ".. creating sol.cpp"
	touch sol.cpp
	echo ".. creating brute.cpp"
	touch brute.cpp
	echo "created"
	echo "
	#!/bin/bash

	RED='\033[0;31m'
	GREEN='\033[0;32m'
	BLUE='\033[0;34m'
	CYAN='\033[0;36m'
	NC='\033[0m' # No Color

	# get the number of input files automatically
	inputfilecount=\$(ls -1 | grep in | wc -l)

	echo \"number of test files detected to be \$inputfilecount\"
	g++ sol.cpp -o sol

	for ((i=1; i <= \$inputfilecount; i++))
	do
		file=\"in\$i\"
		echo \"-----------------\"

		if [ ! -f \"sol\" ]; then
		    echo \"executable does not exist.... compile error\"
		    exit 1
		fi
		./sol < \$file > output\$i

		DIFF=\$(diff -EZbwB output\$i o\$i) 
		if [ \"\$DIFF\" != \"\" ] 
		then
			echo \"Input:\"
		    cat \$file
		    echo \"\"
	    	printf \"\${RED}SAMPLE \$i FAILED\${NC}\n\"
			echo \"obtained output:\"
			printf \"\${BLUE}\"
			cat  output\$i
			printf \"\${NC}\n\"

			echo \"Expected output:\"
			printf \"\${CYAN}\"
			cat o\$i
			printf \"\${NC}\n\"
		fi
		if [ \"\$DIFF\" == \"\" ] 
		then
	    	printf \"\${GREEN}SAMPLE \$i PASSED\${NC}\n\"
		fi
		echo \"-----------------\"
	done

	for ((i = 1; i <= \$inputfilecount; i++))
	do
		rm output\$i
	done

	rm sol
	" > test.sh
	echo "created testing script inside $dir"
	chmod +x test.sh


	echo "
	#!/bin/bash

	numfiles=\$1
	for ((i=1; i<=\$numfiles; i++))
	do
		touch in\$i
		touch o\$i
	done
	" > create.sh
	chmod +x create.sh


	echo "
	#!/bin/bash

	g++ testgen.cpp -o testgen
	g++ sol.cpp -o sol
	g++ brute.cpp -o brute
	for((i=1; i<=1000;i++))
	do
		./testgen > stress
		./sol < stress > codeoutput
		./brute < stress > checkeroutput
		echo \"random test number \$i passed\"
		DIFF=\$(diff -EZbwB codeoutput checkeroutput)

		if [ \"\$DIFF\" != \"\" ] 
		then
			# get the number of input files automatically
	        inputfilecount=\$(ls -1 | grep in | wc -l)
	        ((newinput=inputfilecount+1))
			echo \"input \" 
			cat stress > in\$newinput
			cat stress
			echo \"obtained output\"
			cat codeoutput
			echo \"brute output\"
			cat checkeroutput
			cat checkeroutput > o\$newinput
			exit 1
		fi
		rm stress
	done
	" > stress.sh

	chmod +x stress.sh
	touch testgen.cpp
	cd ..
done

echo "
#/bin/bash/
for dir in A B C D E F G 
do
	echo \"erasing directory \$dir\"
	rm -rf \$dir
done
" > erase.sh

chmod +x erase.sh