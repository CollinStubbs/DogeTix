#!/bin/bash
make
# test to generate error when username does not
command1='login MATT add MATT 1001 q'
echo $command1 | ./DTFE tickets.txt user_info.txt
make clean
