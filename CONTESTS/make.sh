#!/bin/bash
mkdir $1
cd $1
n=7
chars=( {A..Z} )
for ((i=0;i<$n;i++)); do
	var="${chars[i]}"
	mkdir $var
	cd $var
	FILE=$var.cpp
	touch $FILE
	cd ..
done
cd ..
subl $1

