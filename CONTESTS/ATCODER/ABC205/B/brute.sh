#!/bin/bash

mkdir BRUTE
cd BRUTE
touch bad.cpp
touch bad__Good.cpp
touch bad__Generator.cpp
touch debug.cpp
cp ../sol.cpp bad.cpp
cp ../debug.cpp debug.cpp

cd ..	