/*
 * This is the main front end file which will use 
 * the methods in transactionCommands.cpp
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "transactionCommands.h" // this file contains all the transaction commands

using namespace std;
/*
 *	Reads in 2 files:
 *	1) file of tickets available for purchase
 *	2) file containing information regarding current user accounts
 */
void readFile(string file1, string file2){

	string transactionCommand;

	// String to store data in file
	string fileOneContents, fileTwoContents;

	// Open the two input files
	ifstream inputFile1(file1.c_str());
	ifstream inputFile2(file2.c_str());
	// handle if input file fails
	if(inputFile1.fail() || inputFile2.fail()){
		cout << "Error opening input files "<< endl;
		exit(1);
	}else{

		/*
		 * This is where everything happens.
		 */
		while(1){
			cout << endl;
			cout << "login: login to a user account and start a frontEnd session" << endl;
			cout << "logout: logout of a user account and end a frontEnd session" << endl;
			cout << "create: create a user account" << endl;
			cout << "delete: delete a user account" << endl;
			cout << "sell: sell a ticket or tickets to an event" << endl;
			cout << "buy: purchase a ticket or tickets to an event" << endl;
			cout << "refund: issue a credit to a buyer’s account from a seller’s account" << endl;
			cout << "addCredit: add credit into the system for the purchase of accounts" << endl;
			cout << endl;
			cout << "Please enter a command: ";
			cin >> transactionCommand;
			
			if(transactionCommand == "login"){
				cout << "login" << endl;

			}else if(transactionCommand == "logout"){
				cout << "logout" << endl;
				break;

			}else if(transactionCommand == "create"){
				cout << "create" << endl;
			
			}else if(transactionCommand == "delete"){
				cout << "delete" << endl;
			
			}else if(transactionCommand == "sell"){
				cout << "sell" << endl;
			
			}else if(transactionCommand == "buy"){
				cout << "refund" << endl;
			
			}else if(transactionCommand == "addCredit"){
				
				cout << "addCredit" << endl;
			};

			
		
		}
		
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