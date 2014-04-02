#!/bin/bash
make
# test to generate error when reached limit
command1='login MATT add MATT 1001 q'
echo $command1 | ./DTFE tickets.txt user_info.txt
make clean
