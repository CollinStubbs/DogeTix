#!/bin/bash
# run the program using the make file
make
# test create to generate an error when user inputs a user that already exists
command1='login MATT create COLLINSTUBBSSSS AA q'
echo $command1 | ./DTFE tickets.txt user_info.txt

make clean
