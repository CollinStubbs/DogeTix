// This file contains the tructs for the input files

#include <string>

using namespace std;

#ifndef DATA_H_
#define DATA_H_

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
	if(uN.size() < 15){
		// get size of username;
		int size = 15-uN.size();
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