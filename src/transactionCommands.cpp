/*
 * This file contains all the methods for the transactions
 * in the front end
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "transactionCommands.h"

/*
 * - this has to be the first command issued before any other command
 * - Reads in current user accounts file and ask for a username
 * - After username is accepted reads in the available tickets file and prompts user for next command 
 */
void userLogin(){

	
}
/*
 * - ends the front end session
 * - writes out a daily transaction file
 */
void userLogout(){

	
}

/*
 * - creates a new user and asks for new username
 * - should ask whether user is admin or full-standard, buy-standard,sell-standard
 */
void createUser(){

	
}

/*
 * - cancel any outstanding tickets for purchase or sale and remove the user account
 * - should ask for username
 * - saves this info in daily transaction file
 */
void deleteUser(){

	
}

/*
 * - sell a ticket or tickets to an event
 * - should ask for sale price for the tickets in dollars
 * - should ask for number of tickets for sale
 * - saves this info in the daily transaction file
 */
void sellTicket(){

	
}

/*
 * - purchase a tickets or ticket to an event
 * - asks for: event title, number of tickets and the seller’s username
 * - display the cost per ticket and the total cost to the user and ask for confirmation in the form of yes or no
 * - subtracts the number of tickets from the seller's inventory
 * - saves this info in the daily transaction file
 */
void buyTicket(){

	
}

/*
 * - issue a credit to a buyer’s account from a seller’s account (privileged transaction)
 * - ask for the buyer’s username, the seller’s username and the amount of credit to transfer
 * - transfer the specified amount of credit from the seller’s credit balance to the buyer’s credit balance
 * - save this information in the daily transaction file
 */
void refundUser(){

	
}

/*
 * - in admin mode ask amount of credit to add and the username of the account to which credit is being added
 * - in standard account should ask for the amount of credit
 * - saves this information in a daily transaction file
 */
void addCredit(){

	
}


