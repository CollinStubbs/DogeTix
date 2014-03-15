#!/bin/bash

# run the program using the make file
make
# test the file with addcredit as first input to generate an error
command1='addcredit'
echo $command1 | ./DTFE tickets.txt user_info.txt

make clean