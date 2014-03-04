# A simple make file for our front end

# Matthew Militante
# Collin Stubbs
# Andre Gulla

frontEnd: frontEnd.cpp transactionCommands.cpp
	g++ -o DogeTixFrontEnd frontEnd.cpp transactionCommands.cpp

clean:
	rm DogeTixFrontEnd