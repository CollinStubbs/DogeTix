# A simple make file for our front end
FrontEnd : FrontEnd.class

FrontEnd.class : 
	g++ -o DTFE $ frontEnd.cpp transactionCommands.cpp
	$ ./DTFE tickets.txt user_info.txt
	rm -f $ DTFE

clean:
	rm -f % *.out
	rm -f % DTFE
