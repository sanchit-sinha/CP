#!/bin/bash
mkdir $1
cd $1
if [[ $2 -gt 26 ]]
then
	for ((i=1;i<=$2;i++)); do
		FILE=$i.cpp
		touch $FILE
	done
	for a in [0-9].cpp; do
    	mv $a 0$a
	done
else
	chars=( {A..Z} )
	for ((i=0;i<$2;i++)); do
		var="${chars[i]}"
		FILE=$var.cpp
		touch $FILE
	done
fi
touch input.txt
touch output.txt
cd ..
cp run.sh $1/run.sh
subl $1

