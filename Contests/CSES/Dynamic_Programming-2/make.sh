#!/bin/bash
chars=( {A..Z} )
for ((i=0;i<$1;i++)); do
	var="${chars[i]}"
	FILE=$var.cpp
	touch $FILE
done
