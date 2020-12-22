#!/bin/bash

cd $1
mkdir BRUTE
cd BRUTE
touch bad.cpp
touch bad__Good.cpp
touch bad__Generator.cpp
cp ../sol.cpp bad.cpp

cd ..	