#!/bin/bash
make
# test to check that buyer credits cannot exceed 999,999
command1='login MATT refund USER COLLINSTUBBSSSS 10 q'
echo $command1 | ./DTFE tickets.txt user_info.txt
make clean