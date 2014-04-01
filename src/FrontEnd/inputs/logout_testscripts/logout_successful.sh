make
# test the file with correct input to verify successful login
command1='login COLLINSTUBBSSSS logout q'
echo $command1 | ./DTFE tickets.txt user_info.txt
make clean
