#!/bin/bash
# run the program using the make file
make
# test to make sure current user cannot be deleted
command1='login MATT delete MATT q'
echo $command1 | ./DTFE tickets.txt user_info.txt

make clean
