#!/bin/bash

# run the program using the make file
make
# test the file with refund as first input to generate an error
command1='refund'
echo $command1 | ./DTFE tickets.txt user_info.txt

make clean