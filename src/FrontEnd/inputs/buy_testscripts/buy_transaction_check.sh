#!/bin/bash
make
# check to make sure transaction can be completed
command2='login MATT buy MOVIELAUNCH MATTHEW 1 y q'
echo $command2 | ./DTFE tickets.txt user_info.txt
make clean