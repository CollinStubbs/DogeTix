#!/bin/bash
make
# test to check if number of tickets are a valid amount
command1='login MATT sell MYMOVIE 10 101 q'
echo $command1 | ./DTFE tickets.txt user_info.txt
make clean