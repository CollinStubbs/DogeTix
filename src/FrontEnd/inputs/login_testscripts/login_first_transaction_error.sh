#!/bin/bash

# run the program using the make file
make
# test the file with create as a first input to generate an error
command1='create q'
echo $command1 | ./DTFE tickets.txt user_info.txt

make clean
