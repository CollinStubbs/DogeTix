#!/bin/bash
make
# this generates an error
# test to check if event exists already
command1='login MATT sell MOVIELAUNCHHHHHHHHH q'
echo $command1 | ./DTFE tickets.txt user_info.txt
make clean