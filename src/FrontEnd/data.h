// This file contains the tructs for the input files

#include <string>

using namespace std;

#ifndef DATA_H_
#define DATA_H_

extern int eventTitleLength = 19;
extern int sellerNameLength = 13;
extern int userNameLength = 15;

struct User{
	string name;
	string type;
	long credit;
	bool loginState;
};
struct Event{
	string eventName;
	string sellerName;
	int nTickets;
	long ticketPrice;
};


/******DTF STRUCTURES******/
string spaces(string text, int size);
/* 
 * Three dtf structs for the various transactions
 */
struct DTF1{
	// create, delete, addCredit, end of session
	string transActionCode;
	string userName;
	string userType;
	string availableCredit;
};

DTF1* CreateDTF1(string tC, string uN, string uT, string C){
	DTF1* temp = new DTF1;
	temp->transActionCode = tC;
	if(uN.size() < userNameLength){
		// get size of username;
		int size = userNameLength-uN.size();
		temp->userName = spaces(uN, size);
	}else{
		temp->userName = uN;
	}	
	temp->userType = uT;
	temp->availableCredit = C;
	return temp;
}
struct DTF2{
	// refund
	string transActionCode;
	string buyerName;
	string sellerName;
	long refundCredit;
};
DTF2* CreateDTF2(string tC, string uN, string sN, long C){
	DTF2* temp = new DTF2;
	temp->transActionCode = "05";
	temp->buyerName = uN;
	temp->sellerName = sN;
	temp->refundCredit = C;
	return temp;
}
struct DTF3{
	// buy and sell
	string transActionCode;
	string eventName;
	string sellerName;
	int ticketNum;
	float ticketPrice;
};
DTF3* CreateDTF3(string tC, string eN, string sN, int tN, float tP){
	DTF3* temp = new DTF3;
	temp->transActionCode = tC;
	if(eN.size() < eventTitleLength){
		// get size of username;
		int size = eventTitleLength-eN.size();
		temp->eventName = spaces(eN, size);
	}else{
		temp->eventName = eN;
	}
	if(sN.size() < sellerNameLength){
		// get size of username;
		int size = sellerNameLength-sN.size();
		temp->sellerName = spaces(sN, size);
	}else{
		temp->sellerName = sN;
	}
	temp->ticketNum = tN;
	temp->ticketPrice = tP;
	return temp;
}

/*
 * helper function to replace spaces with underscores 
 */
string spaces(string text, int size){
	text = text.append(size, ' ');
    for(int i = 0; i < text.length(); i++)
    {
        if(text[i] == ' ')
            text[i] = '_';
    }
    return text;
}

#endif