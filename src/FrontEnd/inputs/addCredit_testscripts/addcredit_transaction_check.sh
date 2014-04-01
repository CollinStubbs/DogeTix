#!/bin/bash
make
# test that add works with admin account
command1='login MATT add MATT 100 q'
echo $command1 | ./DTFE tickets.txt user_info.txt
make clean
