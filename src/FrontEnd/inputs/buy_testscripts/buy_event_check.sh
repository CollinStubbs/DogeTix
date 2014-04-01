#!/bin/bash
make
# this script generates an erro
# check to make sure event being bought is valid
command2='login MATT buy FAKEEVENT q'
echo $command2 | ./DTFE tickets.txt user_info.txt
make clean