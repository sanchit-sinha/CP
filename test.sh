#!/bin/bash

echo "number of test files $1"

RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color
for ((i=1; i <= $1; i++))
do
	file="in$i"
	echo "Testing on input $file"
	g++ sol.cpp -o sol
	echo "-----------------"
	echo "Input:"
	cat $file
	echo "Obtained output:"
	./sol < $file > obtained$i
	printf "${BLUE}"
	cat  obtained$i
	printf "${NC}"

	echo "Expected output:"
	printf "${CYAN}"
	cat o$i
	printf "${NC}"

	DIFF=$(diff obtained$i o$i) 
	if [ "$DIFF" != "" ] 
	then
    	printf "${RED}SAMPLE FAILED${NC}\n"
	fi
	if [ "$DIFF" == "" ] 
	then
    	printf "${GREEN}SAMPLE PASSED${NC}\n"
	fi
	echo "-----------------"
done

for ((i = 1; i <= $1; i++))
do
	rm obtained$i
done