#!/bin/bash
# run the program using the make file
make
# test if delete works 
command1='login MATT delete COLLINSTUBBSSSS q'
echo $command1 | ./DTFE tickets.txt user_info.txt

make clean