/* TEAM 12
 *
 * Matthew Militante, 100457072
 * Collin Stubbs, 100454604
 * Andrew Gulla, 100395486
 *
 * This is the frontEnd of our ticket system, DogeTix.
 * It uses an output file stream to store all the transactions
 * made by the user and places it into DailyTransactionFile.txt 
 * which will be used to send information to the BackEnd of the 
 * program.
 *
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <iterator>
#include "data.h"

using namespace std;

User *users; // users struct pointer
Event *tickets; // tickets struct pointer
unsigned usersSize; // size of users
unsigned ticketsSize; // size of tickets
// Create a user struct called current user for login purposes
User currentUser;
string transactionCommand;

// output stream to daily transaction file
ofstream outToDTF("DailyTransactionFile.txt");
ifstream readDTF("DailyTransactionFile.txt");

// Method defenitions
void initialize(string file1, string file2);
void login();
void transactionCommands(string transactionCommand);
void logout();
void createUser();
void deleteUser();
void sellTicket();
void buyTicket();
void refundUser();
void addCredit();


/***************************Main method*****************************/
int main(int argc, char* argv[]){

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
/*******************************************************************/
void initialize(string file1, string file2){

    // get size streams
    ifstream tsizeStream(file1.c_str());
    ifstream usizeStream(file2.c_str());
    string tline;
    string uline;

    // info streams
    ifstream tStream(file1.c_str());
    ifstream uStream(file2.c_str());

    if(tsizeStream.fail() || usizeStream.fail() || tStream.fail() || uStream.fail()){
        cout << "Error opening files - check permissions" << endl;
    }else{

        // get size of each file
        tsizeStream.unsetf(ios_base::skipws);
        usizeStream.unsetf(std::ios_base::skipws);
        ticketsSize = count(istream_iterator<char>(tsizeStream), istream_iterator<char>(),'\n')+1;
        usersSize = count(istream_iterator<char>(usizeStream), istream_iterator<char>(),'\n')+1;
        
        // create both arrays that will hold the information
        users = new User[usersSize];
        tickets = new Event[ticketsSize];
        // close the streams
        tsizeStream.close();
        usizeStream.close();

        if(tStream.is_open()){
            int x=0;
            while(getline(tStream, tline)){
                Event temp;
                temp.eventName = tline.substr (0,19);
                //Formats event name to replace '_' with ' '
                replace((temp.eventName).begin(), (temp.eventName).end(), '_', ' ');
                temp.sellerName = tline.substr (20,14);
                //Removes '_' from seller name
                temp.sellerName.erase(remove(temp.sellerName.begin(), temp.sellerName.end(), '_'), temp.sellerName.end());
                temp.nTickets = atoi((tline.substr (35,3)).c_str());
                temp.ticketPrice = atoi((tline.substr (39)).c_str());
                tickets[x] = temp;
                x++;
            }
            tStream.close();
        }

        if (uStream.is_open()) {
            //Incrementally adds users to the array line by line
            int i = 0;
            while (getline(uStream,uline)) {
                User temp;
                temp.name = uline.substr(0,15);
                //Removes '_' from Usernames
                (temp.name).erase(remove((temp.name).begin(), (temp.name).end(), '_'), (temp.name).end());
                temp.type = uline.substr(16,2);
                temp.credit = atoi((uline.substr(19)).c_str());
                temp.loginState = false; //Makes sure user isnt set to logged in
                users[i] = temp;
                i++;
            }
            uStream.close();
        }
        /*
        // For parse testing purposes
        cout << "size of tickets file: " << ticketsSize << "\n";
        cout << "size of users file: " << usersSize << "\n";
        
        cout << "Events: "<< endl;    
        for(int i=0; i<ticketsSize; i++){
        cout << tickets[i].eventName << endl;
        cout << tickets[i].sellerName << endl;
        cout << tickets[i].nTickets << endl;
        cout << tickets[i].ticketPrice << endl;
        }
        cout << endl;
        cout << "Users: "<< endl;
        for(int i=0; i<usersSize; i++){
        cout << users[i].name << endl;
        cout << users[i].type << endl;
        cout << users[i].credit << endl;
        }*/
        
        login();
    }

}

void login(){
    cout << "<<<<<<<<<< WELCOME TO DOGETIX >>>>>>>>>>" << endl;
    cout << "Please type 'login' to start a Front End session" << endl;
    while(cin >> transactionCommand){
        outToDTF << transactionCommand << endl;
        // Check to make sure user logs in first
        if(transactionCommand == "login"){
            currentUser.name = "";
            string userName;
            // LOGIN            
            do {
                cout << "Please enter username: ";
                cin >> userName;
                outToDTF << userName << endl;
                //checks the users and sets the current user 
                for(int i = 0; i<usersSize; i++){
                    if((users[i].name).compare(userName) == 0){
                        currentUser = users[i];
                        currentUser.loginState = true;
                        cout << "Successful login!" << endl;
                    }
                }
                if((currentUser.name).compare("") == 0){
                    cout << "Error: Invalid username."<<endl;
                }
            }while((currentUser.name).compare("") == 0);
            transactionCommands(transactionCommand);
        }else{
            cout << "Error: Cannot perform "+transactionCommand+" You must log in to a user account" << endl;
            login();
        }
    }
}

/***********METHOD DEFENITIONS**********/
void transactionCommands(string transactionCommand){

    cout << endl;
    /* 
     * Display the transaction commands
     * if statements handle transaction command permissions
     */
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
    /*
     * Prompt the user to enter a command
     */
    cout << endl;
    cout << "Please enter a command: ";
    cin >> transactionCommand;

    if(transactionCommand == "logout"){
        cout << "Logging out, have a great day!" << endl;
        outToDTF << transactionCommand << endl;
        logout();

    }else if(transactionCommand == "create"){
        if((currentUser.type).compare("AA") == 0){
            cout << "You have selected create" << endl;
            createUser();
        }
        else{
            cout << "This is a privileged transaction that requires an Admin account."<<endl;
        }
    }else if(transactionCommand == "delete"){
        if((currentUser.type).compare("AA") == 0){
            cout << "You have selected delete" << endl;
            deleteUser();

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
            sellTicket();
        }
    }else if(transactionCommand == "buy"){
        if((currentUser.type).compare("SS") == 0){
            cout<<"You are not allowed to access this function with a sell account."<<endl;
        }
        else{
            cout << "You have selected buy" << endl;
            buyTicket();
        }
    }else if(transactionCommand == "refund"){
        if((currentUser.type).compare("AA") == 0){
            cout << "You have selected refund" << endl;
            refundUser();
        }
        else{
            cout << "This is a privileged transaction that requires an Admin account."<<endl;
        }
    }else if(transactionCommand == "addCredit"){
        if((currentUser.type).compare("AA") == 0){
            cout << "You have selected addCredit" << endl;
            addCredit();
        }
        else{
            cout << "This is a privileged transaction that requires an Admin account."<<endl;
        }
    }else{
        cout << "Invalid command, please enter another command" << endl;
    }
}

/*
 * Loop back to login()
 */
void logout(){
    login();
}

/*
 * Create a user account 
 * - must be logged in to admin account
 */
void createUser(){
    string userName; // username
    string checkString;
    string line;
    string userType;
    int offset;

    cout<<"Please enter a username to create:";
    cin >> userName;
    checkString = "create "+userName;

    // Check if the current user name is trying to be deleted
    if(currentUser.name.compare(userName) == 0){
        cout << "Error: Cannot create current user" << endl;
        createUser();
    }else{
        // iterate through users
        for(int i=0; i<usersSize; i++){
            // if user account is not found in users
            if((users[i].name).compare(userName) != 0){
                cout << "User Types:" << endl;
                cout << "AA = admin" << endl;
                cout << "FS = full-standard" << endl;
                cout << "BS = buy-standard" << endl;
                cout << "SS = sell-standard" << endl;
                cout << "Please enter the user type: ";
                cin >> userType;
                while(!readDTF.eof()){
                    getline(readDTF, line);
                    // Check the daily transaction file if the user has been deleted already
                    if((offset = line.find(checkString, 0)) != string::npos){
                        cout << "Error: User has already been previously created" << endl;
                        // call deleteUser() again
                        createUser();
                    }
                    else{
                        // Output to console
                        cout << "created "+userName+" of type "+userType << endl;
                        outToDTF <<  checkString+" "+userType<< endl;
                        transactionCommands(transactionCommand);
                    }
                }
            }   
        }
    }
}


/*
 * - cancel any outstanding tickets for purchase or sale and remove the user account
 * - should ask for username
 * - saves this info in daily transaction file
 */
void deleteUser(){

    string userName;
    string checkString;
    string line;
    int offset;

    cout<<"Please enter a username to delete:";
    cin >> userName;
    checkString = "delete "+userName;

    // Check if the current user name is trying to be deleted
    if(currentUser.name.compare(userName) == 0){
        cout << "Error: Cannot delete current user" << endl;
        deleteUser();
    }else{
        // iterate through userAccounts
        for(int i = 0; i<usersSize; i++){
            // check if username exists in userAccounts
            if((users[i].name).compare(userName) == 0){
                while(!readDTF.eof()){
                    getline(readDTF, line);
                    // Check the daily transaction file if the user has been deleted already
                    if((offset = line.find(checkString, 0)) != string::npos){
                        cout << "Error: User has already been previously deleted" << endl;
                        // call deleteUser() again
                        deleteUser();
                    }
                    else{
                        // Output to console
                        // FOR SOME REASON IT PRINTS IT TWICE
                        cout << "deleted "+userName << endl;
                        outToDTF <<  checkString << endl;
                        transactionCommands(transactionCommand);
                    }
                }
            }
        }   
    }
}

/*
 * - sell a ticket or tickets to an event
 * - should ask for sale price for the tickets in dollars
 * - should ask for number of tickets for sale
 * - saves this info in the daily transaction file
 */
void sellTicket(){
    string eventTitle;
    long ticketPrice;
    int ticketNum;
    string line;

    cout << "Please enter the event title: ";
    cin >> eventTitle;
    string checkString = "sell "+eventTitle;

    for(int i=0; i<ticketsSize; i++){
        if((tickets[i].eventName).compare(eventTitle) == 0){
            cout << "Error: the event already exists" << endl;
            transactionCommands(transactionCommand);
        }else{
            while(!readDTF.eof()){
                getline(readDTF, line);
                int offset;
                // Check the daily transaction file if the user has been deleted already
                if((offset = line.find(checkString, 0)) != string::npos){
                    cout << "Error: the event already exists" << endl;
                    transactionCommands(transactionCommand);
                }else{
                    if(eventTitle.length() <= 25){
                        cout << "Please enter ticket price: ";
                        cin >> ticketPrice;
                        if(ticketPrice <= 999.99){ 
                            cout << "Please enter the amount of tickets to be available for sale: ";
                            cin >> ticketNum;
                            if(ticketNum <= 100){
                                cout << "Selling "<<ticketNum<<" tickets for "<<eventTitle<<" at $"<< ticketPrice;
                                outToDTF << checkString << " "<<ticketNum << " @ $"<< ticketPrice << endl;
                                cout << endl;
                                transactionCommands(transactionCommand);
                            }else{
                                 cout << "Error: maximum number of tickets for sale is 100" << endl;
                                transactionCommands(transactionCommand);
                            }
                        }else{
                            cout << "Error: ticket price cannot exceed $999.99" << endl;
                            transactionCommands(transactionCommand);
                        }
                    }else{
                        cout << "Error: Event title cannot exceed 25 characters" << endl;
                        transactionCommands(transactionCommand);
                    }
                }
            }
        }
    }

}


/*
 * - purchase a tickets or ticket to an event
 * - asks for: event title, number of tickets and the seller’s username
 * - display the cost per ticket and the total cost to the user and ask for confirmation in the form of yes or no
 * - subtracts the number of tickets from the seller's inventory
 * - saves this info in the daily transaction file
 */
void buyTicket(){
    /*
    string eventTitle;
    string sellerName;
    string transactionCommand;

    cout << "Please enter the event title: ";
    cin >> eventTitle;
    for(int i=0; i<ticketsSize; i++){
        if((tickets[i].eventName).compare(eventTitle) == 0){
            cout << "Please enter the seller's username: ";
            cin >> sellerName;
            if((tickets[i].sellerName).compare(sellerName) == 0){
                cout << "yes";
            }else{
                cout << "Error: Seller does not exist" << endl;
                transactionCommands(transactionCommand);
            }
        }else{
            cout << "Error: Event does not exist" << endl;
            transactionCommands(transactionCommand);
        }
    }*/
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
    string userName;
    float creditAmount;

    cout << "Please enter username you wish to add credit to: ";
    cin >> userName;
    for(int i=0; i<usersSize; i++){
        if((users[i].name).compare(userName)==0){
            cout << "Please enter the amount to add: ";
            cin >> creditAmount;
            if(creditAmount <= 1000.00){
                cout << "Added $"<<creditAmount<<" to "<<userName<<endl;
                outToDTF << "addCredit $"<<creditAmount<<" to "<<userName << endl;
            }else{
                cout << "Error: Only a maximum of $1000.00 can be added to an account in a given session." << endl;
                transactionCommands(transactionCommand);
            }
        }else{
            cout << "Error: Username does not exist";
            transactionCommands(transactionCommand);
        }
    }

}
