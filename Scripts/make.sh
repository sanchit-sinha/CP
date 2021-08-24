#!/bin/bash
mkdir $1
cd $1
cp ../brute.sh brute.sh
if [[ $2 -gt 26 ]]
then
	for ((i=1;i<=$2;i++)); do
		mkdir $i
		cd $i
		touch sol.cpp
		cd ..
	done
	for a in [0-9]; do
    	mv $a 0$a
	done
else
	chars=( {A..Z} )
	for ((i=0;i<$2;i++)); do
		var="${chars[i]}"
		FILE=$var
		mkdir $FILE
		cd $FILE
		touch sol.cpp
		cd ..
	done
fi
cd ..
subl $1
