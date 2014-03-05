# A simple make file for our front end
FrontEnd : FrontEnd.class

FrontEnd.class : 
	g++ -o DTFE $ frontEnd.cpp transactionCommands.cpp
	./DTFE
	rm -f $ DTFE

clean:
	rm -f % *.out
