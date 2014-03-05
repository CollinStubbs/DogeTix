# A simple make file for our front end
FrontEnd : FrontEnd.class

FrontEnd.class : 
	g++ -o DTFE $ frontEnd.cpp transactionCommands.cpp
	./DTFE.out
	rm -f $ *.out

clean:
	rm -f % *.out
