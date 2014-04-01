#!/bin/bash
# run the program using the make file
make
# test create each user type
command1='login MATT create USERNAME AA q'
echo $command1 | ./DTFE tickets.txt user_info.txt

command2='login MATT create USERNAME1 SS q'
echo $command2 | ./DTFE tickets.txt user_info.txt

command3='login MATT create USERNAME2 FS q'
echo $command3 | ./DTFE tickets.txt user_info.txt

command4='login MATT create USERNAME3 BS q'
echo $command4 | ./DTFE tickets.txt user_info.txt

make clean
