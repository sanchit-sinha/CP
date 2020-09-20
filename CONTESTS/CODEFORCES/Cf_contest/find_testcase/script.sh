#!/bin/bash
#give permission chmod 777 script.sh
#to execut  ./script.sh
g++ gen.cpp -o gen

echo "compiling"
g++ correct.cpp -o correct
g++ incorrect.cpp -o incorrect


for((i = 1; ; ++i)); do
    echo $i
    ./gen $i > input
    # ./a < int > out1
    # ./brute < int > out2
    # diff -w out1 out2 || break

    diff -w <(./incorrect < input) <(./correct < input) || break
done