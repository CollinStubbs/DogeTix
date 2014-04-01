#!/bin/bash

#this tests that no transactions are accepted after logging out except login

make
# test the file with addcredit as first input to generate an error
command1='login COLLINSTUBBSSSS logout addCredit q'
echo $command1 | ./DTFE tickets.txt user_info.txt
make clean

make
# test the file with buy as first input to generate an error
command1='login COLLINSTUBBSSSS logout buy q'
echo $command1 | ./DTFE tickets.txt user_info.txt
make clean

make
# test the file with create as first input to generate an error
command1='login COLLINSTUBBSSSS logout create q'
echo $command1 | ./DTFE tickets.txt user_info.txt
make clean

make
# test the file with delete as first input to generate an error
command1='login COLLINSTUBBSSSS logout delete q'
echo $command1 | ./DTFE tickets.txt user_info.txt
make clean

make
# test the file with refund as first input to generate an error
command1='login COLLINSTUBBSSSS logout refund q'
echo $command1 | ./DTFE tickets.txt user_info.txt
make clean


make
# test the file with sell as first input to generate an error
command1='login COLLINSTUBBSSSS logout sell q'
echo $command1 | ./DTFE tickets.txt user_info.txt
make clean