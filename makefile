# A simple make file for our front end

frontEnd: frontEnd.cpp transactionCommands.cpp
	g++ -o DogeTixFrontEnd frontEnd.cpp transactionCommands.cpp

clean:
	rm DogeTixFrontEnd
