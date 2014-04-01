#!/bin/bash
make
# test to check if seller account works on all accounts except buy standard

# AA account
command1='login MATT sell EVENT1 10 10 q'
echo $command1 | ./DTFE tickets.txt user_info.txt

# FS account
command2='login USER1 sell EVENT2 10 10 q'
echo $command2 | ./DTFE tickets.txt user_info.txt

# SS account
command3='login ANDREWGULLA sell EVENT3 10 10 q'
echo $command3 | ./DTFE tickets.txt user_info.txt

# BS account to generate an error
command3='login MATTHEWMILI sell q'
echo $command3 | ./DTFE tickets.txt user_info.txt

make clean