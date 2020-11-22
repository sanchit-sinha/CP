!/bin/bash

mkdir $1
cd $1

for ((i=1;i<=$2;i++)); do
	mkdir $i
	cd $i
	touch sol.cpp
	cd ..
done
subl ./$1/



