#!/bin/bash
make
# test to check if event title does not exceed specified amount of characters, generate an error
command1='login MATT sell EVENT12345678dwewrewrwedwedwedewerewrew q'
echo $command1 | ./DTFE tickets.txt user_info.txt
make clean