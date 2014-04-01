#!/bin/bash
make
# this script generates an error
# test to check if price of tickets are a valid amount
command1='login MATT sell MYMOVIE 999999 101 q'
echo $command1 | ./DTFE tickets.txt user_info.txt
make clean