#!/bin/bash
var=$1.cpp
echo "[DEBUG]"
g++ -D ONLINE_JUDGE -std=c++17 $var
./a.out < input.txt