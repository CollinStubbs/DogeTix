/* TEAM 12
 *
 * Matthew Militante, 100457072
 * Collin Stubbs, 100454604
 * Andrew Gulla, 100395486
 *
 */

/*
 * This is the main front end file which will use 
 * the methods in transactionCommands.cpp
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include "data.h" // Structures are held in this header file

using namespace std;

static User users [256];
static Event tickets [256];
static User currentUser;

// output to daily transaction file
ofstream outToDTF("DailyTransactionFile.txt");
/*
 * login takes a string as input and checks if it is in the database and if it is 
 * it will set currentUser as that user.
 */
void login();
/*
 *	Reads in 2 files:
 *	- file of tickets available for purchase
 *	- file containing information regarding current user accounts
 * An output file stream is used to output any transactions into DailyTransactionFile.txt
 */
void initialize(string file1, string file2);

int main(int argc, char* argv[]){
	// Check if the user input 3 arguements
	if(argc > 2 || argc == 1){
		// read the files using the readFile method
		initialize(argv[1], argv[2]);
	}else{
		// This handles if the user inputs more than two arguements
		cout << "Usage: frontEnd [available_tickets_file] [info_file]" << endl;
		exit(1);
	}
	return 0;
}

void initialize(string file1, string file2){

	string transactionCommand;
	// Open the two input files
	ifstream ticketStream(file1.c_str());
	ifstream userStream(file2.c_str());
	string line;
	// handle if input file fails
	if(ticketStream.fail() || userStream.fail()){
		cout << "Error opening input files "<< endl;
		exit(1);
	}else{
		//PARSE FILES
		if (userStream.is_open()) {
			//Incrementally adds users to the array line by line
			int i = 0;
			while (getline (userStream,line)) {
				User temp;
				temp.name = line.substr (0,15);
				//Removes '_' from Usernames
				(temp.name).erase(remove((temp.name).begin(), (temp.name).end(), '_'), (temp.name).end());
				temp.type = line.substr (16,2);
				temp.credit = atoi((line.substr (19)).c_str());
				temp.loginState = false; //Makes sure user isnt set to logged in
				users[i] = temp;
				i++;
			}
			userStream.close();
		}

		if (ticketStream.is_open()) {
			//Incrementally adds the ticket event to an array of events
			int x = 0;
			while(getline (ticketStream,line)) {
				Event temp;
				temp.eventName = line.substr (0,19);
				//Formats event name to replace '_' with ' '
				replace((temp.eventName).begin(), (temp.eventName).end(), '_', ' ');
				temp.sellerName = line.substr (20,14);
				//Removes '_' from seller name
				temp.sellerName.erase(remove(temp.sellerName.begin(), temp.sellerName.end(), '_'), temp.sellerName.end());
				temp.nTickets = atoi((line.substr (35,3)).c_str());
				temp.ticketPrice = atoi((line.substr (39)).c_str());
				tickets[x] = temp;
				x++;
			}
			ticketStream.close();
		}
		cout << "<<<<<<<<<< WELCOME TO DOGETIX >>>>>>>>>>" << endl;
		cout << "Please type 'login' to start a Front End session" << endl;
		cin >> transactionCommand;
		outToDTF << transactionCommand << endl;
		
		// Check to make sure user logs in first
		if(transactionCommand == "login"){
			//calls the login function
			login();

			while(1){
				cout << endl;
				cout << "logout:    logout of a user account and end a frontEnd session" << endl;

				if((currentUser.type).compare("AA") == 0) {
					cout << "create:    create a user account" << endl;
				}
				if((currentUser.type).compare("AA") == 0){
					cout << "delete:    delete a user account" << endl;
				}

				cout << "sell:      sell a ticket or tickets to an event" << endl;
				cout << "buy:       purchase a ticket or tickets to an event" << endl;

				if((currentUser.type).compare("AA") == 0){
					cout << "refund:    issue a credit to a buyer’s account from a seller’s account" << endl;
				}
				if((currentUser.type).compare("AA") == 0){
					cout << "addCredit: add credit into the system for the purchase of accounts" << endl;
				}

				cout << endl;
				cout << "Please enter a command: ";
				cin >> transactionCommand;
				
				if(transactionCommand == "logout"){
					cout << "Logging out, have a great day!" << endl;
					break;

				}else if(transactionCommand == "create"){
					if((currentUser.type).compare("AA") == 0){
						cout << "You have selected create" << endl;
					}
					else{
						cout << "This is a privileged transaction that requires an Admin account."<<endl;
					}
				}else if(transactionCommand == "delete"){
					if((currentUser.type).compare("AA") == 0){
						cout << "You have selected Delete" << endl;
					}
					else{
						cout << "This is a privileged transaction that requires an Admin account."<<endl;
					}
				}else if(transactionCommand == "sell"){
					if((currentUser.type).compare("BS") == 0){
						cout<<"You are not allowed to access this function with a buy account."<<endl;
					}
					else{
						cout << "You have selected sell" << endl;
					}
				}else if(transactionCommand == "buy"){
					if((currentUser.type).compare("SS") == 0){
						cout<<"You are not allowed to access this function with a sell account."<<endl;
					}
					else{
						cout << "You have selected buy" << endl;
					}
				}else if(transactionCommand == "refund"){
					if((currentUser.type).compare("AA") == 0){
						cout << "You have selected refund" << endl;
					}
					else{
						cout << "This is a privileged transaction that requires an Admin account."<<endl;
					}
				}else if(transactionCommand == "addCredit"){
					if((currentUser.type).compare("AA") == 0){
						cout << "You have selected addCredit" << endl;
					}
					else{
						cout << "This is a privileged transaction that requires an Admin account."<<endl;
					}
				}else{
					cout << "Invalid command, please enter another command" << endl;
				}
			}	
		
		}else{
			cout << " Cannot perform "+transactionCommand+" You must log in to a user account" << endl;
		}

	}

	// close the output stream
	outToDTF.close();
} 

void login(){
	currentUser.name = "";
	string userName;
			
	// LOGIN			
	do {
		cout << "Please enter username: ";
		cin >> userName;
		outToDTF << userName;
			
		//checks the users and sets the current user 
		for(int i = 0; i< 256; i++){
			if((users[i].name).compare(userName) == 0){
				currentUser = users[i];
				currentUser.loginState = true;
				cout << "Successful login!" << endl;
			}
		}
		if((currentUser.name).compare("") == 0){
			cout << "Invalid username."<<endl;
		}
	} while ((currentUser.name).compare("") == 0);
}