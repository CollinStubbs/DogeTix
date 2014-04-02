#!/bin/bash
make
# test that add works with admin account
command1='login MATT add COLLINSTUBBSSSS 10 q'
echo $command1 | ./DTFE tickets.txt user_info.txt
make clean
