#!/bin/bash
# run the program using the make file
make
# test create to generate an error when user enters create transaction that is not an admin
command1='login ANDREWGULLA create q'
echo $command1 | ./DTFE tickets.txt user_info.txt

make clean
