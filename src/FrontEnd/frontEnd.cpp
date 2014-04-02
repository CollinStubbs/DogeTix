/* 
 * TEAM 12
 *
 * Matthew Militante, 100457072
 * Collin Stubbs, 100454604
 * Andrew Gulla, 100395486
 *
 * This is the frontEnd of our ticket system, DogeTix.
 * It uses an output file stream to store all the
 * user transactions and outputs it into DailyTransactionFile.txt 
 * which will be used to send information to the BackEnd of the 
 * application.
 *
 */
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <limits>

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

// Constants
int eventTitleLength = 19;
int sellerNameLength = 13;
int userNameLength = 15;

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

// helper function to remove extra spaces
string removeSpaces(string input);

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
        usizeStream.unsetf(ios_base::skipws);
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

                string eventName = tline.substr (0,19);
                //Formats event name to replace '_' with ' '
                replace((eventName).begin(), (eventName).end(), '_', ' ');
                temp.eventName = removeSpaces(eventName);

                string sellerName = tline.substr (20,14);
                //Removes '_' from seller name
                replace((sellerName).begin(), (sellerName).end(), '_', ' ');
                temp.sellerName = removeSpaces(sellerName);

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
        login();
    }

}

void login(){

    // For parse testing purposes
    cout << endl;
    cout << endl;
    cout << "CURRENT INFORMATION:" << endl;
    cout << "Number of events: " << ticketsSize << " events \n";
    cout << "Number of users: " << usersSize << " users \n";
    cout << endl;
    cout << "Events: "<< endl;    
    for(int i=0; i<ticketsSize; i++){
        cout << tickets[i].eventName <<  " " << tickets[i].sellerName <<  " " << tickets[i].nTickets <<  " " << tickets[i].ticketPrice << endl;
    }
    cout << endl;
    cout << "Users: "<< endl;
    for(int i=0; i<usersSize; i++){
        cout << users[i].name << " " << users[i].type << " " << users[i].credit << endl;
    }
    cout << endl;
    cout << "<<<<<<<<<< WELCOME TO DOGETIX >>>>>>>>>>" << endl;
    cout << "Please type 'login' to start a Front End session" << endl;
    while(cin >> transactionCommand){
        // Check to make sure user logs in first
        if(transactionCommand == "login"){
            currentUser.name = "";
            string userName;
            // LOGIN            
            do {
                cout << "Please enter username: ";
                cin >> userName;
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
        cout << "add: add credit into the system for the purchase of accounts" << endl;
    }
    /*
     * Prompt the user to enter a command
     */
    cout << endl;
    cout << "Please enter a command: ";
    cin >> transactionCommand;

    if(transactionCommand == "logout"){
        cout << "Logging out, have a great day!" << endl;
        logout();

    }else if(transactionCommand == "create"){
        if((currentUser.type).compare("AA") == 0){
            cout << "You have selected create" << endl;
            createUser();
        }
        else{
            cout << "This is a privileged transaction that requires an Admin account."<<endl;
            transactionCommands(transactionCommand);
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
            transactionCommands(transactionCommand);

        }
        else{
            cout << "You have selected sell" << endl;
            sellTicket();
        }
    }else if(transactionCommand == "buy"){
        if((currentUser.type).compare("SS") == 0){
            cout<<"You are not allowed to access this function with a sell account."<<endl;
            transactionCommands(transactionCommand);
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
            transactionCommands(transactionCommand);

        }
    }else if(transactionCommand == "add"){
        if((currentUser.type).compare("AA") == 0){
            cout << "You have selected addCredit" << endl;
            addCredit();
        }
        else{
            cout << "This is a privileged transaction that requires an Admin account."<<endl;
            transactionCommands(transactionCommand);
        }
        // forcequit frontend
    }else if(transactionCommand == "q"){
        exit(1);
    }else{
        cout << "Invalid command, please enter another command: ";
        transactionCommands(transactionCommand);

    }
}

/*
 * Loop back to login()
 */
void logout(){
    string userName = currentUser.name;
    string userType = currentUser.type;

    // Cast a long to a string
    stringstream ss;
    ss << currentUser.credit;
    string availableCredit = ss.str();

    // Output to DTFD
    DTF1 *output = CreateDTF1("00", userName, userType, availableCredit);
    outToDTF << output->transActionCode << "_"<< output->userName << "_"<<output->userType <<"_"<<output->availableCredit <<endl;

    login();
}

/*
 * Create a user account 
 * - must be logged in to admin account
 */
void createUser(){
    string userName; 
    string line;
    string userType;
    int offset;

    cout<<"Please enter a username to create:";
    cin >> userName;
    // Check if the current user name is trying to be deleted
    if(currentUser.name.compare(userName) == 0){
        cout << "Error: Cannot create current user" << endl;
        transactionCommands(transactionCommand);
    }else{
        // check if user name length is valid
        if(userName.length() > userNameLength){
            cout << "Error: Username length cannot exceed "<<userNameLength;
            transactionCommands(transactionCommand);
        }else{
            // iterate through users
            for(int i=0; i<usersSize; i++){
                // if user account is not found in users
                bool flag=false;
                for(int i=0; i<usersSize; i++){
                    if((users[i].name).compare(userName) == 0){
                        flag=true;
                        cout << "Error: User already exists";
                        transactionCommands(transactionCommand);
                    }
                }
                // If the user doesnt exist the create user
                if(!flag){
                    cout << "User Types:" << endl;
                    cout << "AA = admin" << endl;
                    cout << "FS = full-standard" << endl;
                    cout << "BS = buy-standard" << endl;
                    cout << "SS = sell-standard" << endl;
                    cout << "Please enter the user type: ";
                    cin >> userType;
                    cout << "created "+userName+" of type "+userType << endl;
                    DTF1 *output = CreateDTF1("01", userName, userType, "000000000");
                    outToDTF << output->transActionCode << "_"<< output->userName << "_"<<output->userType <<"_"<<output->availableCredit <<endl;
                    transactionCommands(transactionCommand);
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

    User temp;

    cout<<"Please enter a username to delete:";
    cin >> userName;

    // Check if the current user name is trying to be deleted
    if(currentUser.name.compare(userName) == 0){
        cout << "Error: Cannot delete current user" << endl;
        transactionCommands(transactionCommand);
    }else{
        bool flag=false;
        for(int i=0; i<usersSize; i++){
            if((users[i].name).compare(userName) == 0){
                temp.name = users[i].name;
                temp.type = users[i].type;
                temp.credit = users[i].credit;
                temp.loginState = users[i].loginState;
                flag=true;
                // delete the user 
                cout << "deleted "+temp.name << endl;
                DTF1 *output = CreateDTF1("02", userName, temp.type, "000000000");
                // output to the dtf file
                outToDTF << output->transActionCode << "_"<< output->userName << "_"<<output->userType <<"_"<<output->availableCredit <<endl;
                transactionCommands(transactionCommand);
            }
        }
        if(!flag){
            cout << "Error: User does not exist";
            transactionCommands(transactionCommand);
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
    string sellerName;
    long ticketPrice;
    int ticketNum;
    string line;

    cout << "Please enter the event title: ";
    cin >> eventTitle;

    bool flag=false;

    for(int i=0; i<ticketsSize; i++){
        if((tickets[i].eventName).compare(eventTitle) == 0){
            cout << "Error: the event already exists" << endl;
            flag = true;
            transactionCommands(transactionCommand);
        }
    }
    if(!flag){
        sellerName = currentUser.name;
        if(eventTitle.length() <= eventTitleLength){
            cout << "Please enter ticket price: ";
            cin >> ticketPrice;
            if(ticketPrice <= 999){ 
                cout << "Please enter the amount of tickets to be available for sale: ";
                cin >> ticketNum;
                if(ticketNum <= 100){
                    cout << "Selling "<<ticketNum<<" tickets for "<<eventTitle<<" at $"<< ticketPrice;
                    DTF3 *output = CreateDTF3("03", eventTitle, sellerName, ticketNum, ticketPrice);
                    outToDTF << output->transActionCode << "_" << output->eventName << "_" << output->sellerName << "_" << output->ticketNum << "_" << output->ticketPrice << endl;
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
            cout << "Error: Event title cannot exceed "<< eventTitleLength <<" characters" << endl;
            transactionCommands(transactionCommand);
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

    string eventTitle;
    string sellerName;
    int numTickets;
    float total;
    bool flag = false;
    Event temp; // holder to hold event information 


    cout << "Please enter the event name: ";
    cin >> eventTitle;
    cout << "Please enter the seller’s username:";
    cin >> sellerName;
    for(int i=0; i<ticketsSize; i++){
        if(((tickets[i].eventName).compare(eventTitle) == 0) && ((tickets[i].sellerName).compare(sellerName) == 0)){
            flag = true;
            temp.eventName = tickets[i].eventName;
            temp.nTickets = tickets[i].nTickets;
            temp.ticketPrice =  tickets[i].ticketPrice;
            temp.sellerName = tickets[i].sellerName;
        }
    }
    if(!flag){
        cout << "Error: Event does not exist." << endl;
        transactionCommands(transactionCommand);
    }
    // Display event details
    cout << "EVENT DETAILS: ";
    cout << "Event Title: "<<temp.eventName << endl; 
    cout << "Seller Name: "<<temp.sellerName << endl;
    cout << "Available Tickets: "<<temp.nTickets << endl;
    cout << "Price: $"<<temp.ticketPrice<<" per ticket"<< endl;
    cout << endl;

    cout << "Please enter the amount of tickets to purchase: ";
    cin >> numTickets;
    if(numTickets > temp.nTickets){
        cout << "Error: There are only "<<temp.nTickets<<" ticket(s) available." << endl;
        transactionCommands(transactionCommand);
    }else{
        total = numTickets*temp.ticketPrice;
        int remTick = temp.nTickets - numTickets;
        if(currentUser.credit < total){
            cout << "Error: Not enough credits to purchase ticket for event";
            transactionCommands(transactionCommand);
        }else{
            string inp; 
            cout << "Are you sure you want to purchase "<<numTickets<<" for "<<temp.eventName<<" for "<<total<<" ? (y/n)";
            cin >> inp;
            if(inp == "y" || inp == "Y"){
                cout << "Purchased!";
                DTF3 *output = CreateDTF3("04", eventTitle, temp.sellerName, remTick, temp.ticketPrice);
                outToDTF << output->transActionCode << "_" << output->eventName << "_" << output->sellerName << "_" << output->ticketNum << "_" << output->ticketPrice << endl;
                transactionCommands(transactionCommand);
            }else if(inp == "n" || inp == "N"){
                cout << "Cancelled Purchase.";
                transactionCommands(transactionCommand);
            }else{
                cout << "Error: Invalid Input" << endl;
                transactionCommands(transactionCommand);
            }
        }
    }
}

/*
 * - issue a credit to a buyer’s account from a seller’s account (privileged transaction)
 * - ask for the buyer’s username, the seller’s username and the amount of credit to transfer
 * - transfer the specified amount of credit from the seller’s credit balance to the buyer’s credit balance
 * - save this information in the daily transaction file
 */
void refundUser(){

    long refundAmount;

    string bName;
    string sName;

    // create two instances of user for buyer and seller
    User buyer;
    User seller;

    cout << "Please enter the buyer’s username: ";
    cin >> bName;
    for(int i=0; i<usersSize; i++){
        if((users[i].name) == bName){
            buyer.name = users[i].name;
            buyer.type = users[i].type;
            buyer.credit = users[i].credit;
            buyer.loginState = users[i].loginState;
        }
    }

    cout << "Please enter the sellers’s username: ";
    cin >> sName;
    for(int i=0; i<usersSize; i++){
        if((users[i].name) == sName){
            seller.name = users[i].name;
            seller.type = users[i].type;
            seller.credit = users[i].credit;
            seller.loginState = users[i].loginState;
        }
    }

    cout << "Please enter the amount to refund "<<buyer.name<< endl;
    cout << "Amount: ";
    cin >> refundAmount;

    // Check if seller has enough credits for the refund
    if(refundAmount > seller.credit){
        cout << "Error: Seller does not have enough credit, please add credit to user account" << endl;
        transactionCommands(transactionCommand);
    }else if((refundAmount+buyer.credit) > 999999999){
        cout << "Error: Buyer credits cannot exceed $999,999" << endl;
        transactionCommands(transactionCommand);
    }else{
        // deduct refund amount from seller account
        seller.credit -= refundAmount;
        // add refund amount to buyer account
        buyer.credit += refundAmount;
    }

    // Print to console the results
    cout << "Refunded "<<buyer.name<<" $"<<refundAmount<< " from "<<seller.name << endl;;
    cout << buyer.name << " CREDITS: " << buyer.credit << endl;
    cout << seller.name << " CREDITS: " << seller.credit << endl;

    // Cast refundAmount to a string
    stringstream ss;
    ss << refundAmount;
    string refundCredit = ss.str();

    // Output to DTF
    DTF2 *output = CreateDTF2("05", buyer.name, seller.name, refundCredit);
    outToDTF << output->transActionCode << "_"<< output->buyerName << "_"<<output->sellerName <<"_"<<output->refundCredit <<endl;
    transactionCommands(transactionCommand);

}

/*
 * - in admin mode ask amount of credit to add and the username of the account to which credit is being added
 * - in standard account should ask for the amount of credit
 * - saves this information in a daily transaction file
 */
void addCredit(){
    string userName;
    long creditAmount;

    cout << "Please enter username you wish to add credit to: ";
    cin >> userName;
    for(int i=0; i<usersSize; i++){
        // check if username exists in userAccounts
        if((users[i].name).compare(userName) == 0){
            string userType = users[i].type;
            cout << "Please enter the amount to add: ";
            cin >> creditAmount;
            
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Error: Number was not entered." << endl;
                transactionCommands(transactionCommand);
                return;
            }else{
                if(creditAmount <= 1000.00){
                    long totalCredit = users[i].credit + creditAmount;
                    stringstream ss;
                    ss << totalCredit;
                    string availableCredit = ss.str();
                    cout << "Added $"<<creditAmount<<" to "<<userName<<endl;
                    DTF1 *output = CreateDTF1("06", userName, userType, availableCredit);
                    outToDTF << output->transActionCode << "_"<< output->userName << "_"<<output->userType <<"_"<<output->availableCredit <<endl;
                    transactionCommands(transactionCommand);
                }else{
                    cout << "Error: Only a maximum of $1000.00 can be added to an account in a given session." << endl;
                    transactionCommands(transactionCommand);
                }
            }
        }else{
            cout << "Error: Username does not exist." << endl;
            transactionCommands(transactionCommand);
        }
    }
}
/*
 * Helper function to remove extra spaces
 */
string removeSpaces(string input){
    input.erase(std::remove(input.begin(),input.end(),' '),input.end());
    return input;
}