#!/bin/bash

# run the program using the make file
make
# test if a privilaged user can perform a privilaged transaction
command1='login COLLINSTUBBSSSS create'
echo $command1 | ./DTFE tickets.txt user_info.txt

make clean
