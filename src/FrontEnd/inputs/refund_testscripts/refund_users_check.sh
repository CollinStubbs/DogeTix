#!/bin/bash
make
# test to check if seller and buyer are are current users
command1='login MATT refund MATT COLLINSTUBBSSSS q'
echo $command1 | ./DTFE tickets.txt user_info.txt
make clean