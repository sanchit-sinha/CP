# DEBUG YOUR CODE EASILY
## Easily find the testcase over which your code might be failing

## this folder contains the following ->
- gen.cpp :
   Generate random input as given in the program

- correct.cpp :
  Should contain the correct code of the program

- incorrect.cpp : 
  Contains the incorrect code of the program.(The one which we have to correct)

- script.sh :
  this script tests both the programs(correct.cpp && incorrect.cpp) over random testcases and pops out the testcase over which the outputs are found to be       different. 

## USAGE-
- Clone the repository into your local system 
- Code gen.cpp , correct.cpp , incorrect.cpp
- Run the script(after giving it permission to execute)

  Check the input over which your program is failing in file named "input"
