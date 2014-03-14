#!/bin/bash

# run the program using the make file
make
# test the file with username ADMIN COLLINSTUBBSSSS
command1='login COLLINSTUBBSSSS login'
echo $command1 | ./DTFE tickets.txt user_info.txt

make clean
