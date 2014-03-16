#!/bin/bash

# run the program using the make file
make
# test the file with a seller account ANDREWGULLA to perform an admin transaction
command1='login ANDREWGULLA create'
echo $command1 | ./DTFE tickets.txt user_info.txt

make clean
