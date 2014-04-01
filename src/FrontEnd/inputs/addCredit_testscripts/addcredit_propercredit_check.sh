#!/bin/bash
make
# test to generate error when string is entered instead of number
command1='login MATT add MATT STRING q'
echo $command1 | ./DTFE tickets.txt user_info.txt
make clean