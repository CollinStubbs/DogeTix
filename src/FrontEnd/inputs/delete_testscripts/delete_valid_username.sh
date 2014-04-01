#!/bin/bash
# run the program using the make file
make
# test delete with a fake username to generate an error
command1='login MATT delete FAKEUSERNAME q'
echo $command1 | ./DTFE tickets.txt user_info.txt

make clean