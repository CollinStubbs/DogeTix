/*
 * This is the main front end file which will use 
 * the methods in transactionCommands.cpp
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "transactionCommands.h"

using namespace std;
/*
 *	Reads in 2 files:
 *	1) file of tickets available for purchase
 *	2) file containing information regarding current user accounts
 */
void readFile(string file1, string file2){
	// Open the two input files
	ifstream inputFile1(file1.c_str());
	ifstream inputFile2(file2.c_str());
	// handle if input file fails
	if(inputFile1.fail() || inputFile2.fail()){
		cout << "Error opening input files "<< endl;
		exit(1);
	}else{

		/*
		 * This is where the magic happens!
         * 
		 */

	}

}

/*
 * the main method takes in 2 arguements and passes it onto readFile
 */
int main(int argc, char* argv[]){
	// Check if the user input 3 arguements
	if(argc > 2 || argc == 1){
		// read the files using the readFile method
		readFile(argv[1], argv[2]);
	}else{
		// This handles if the user inputs more than tw arguements
		cout << "Usage: frontEnd [available_tickets_file] [info_file]" << endl;
		exit(1);
	}
	return 0;
} 