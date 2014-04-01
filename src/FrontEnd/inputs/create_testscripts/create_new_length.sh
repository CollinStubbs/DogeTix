#!/bin/bash
# run the program using the make file
make
# test create to generate an error when user inputs more than 15 char
command1='login MATT create USERNAME1234555555 q'
echo $command1 | ./DTFE tickets.txt user_info.txt

make clean
