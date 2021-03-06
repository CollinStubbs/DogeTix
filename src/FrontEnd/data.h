// This file contains the tructs for the input files

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

#ifndef DATA_H_
#define DATA_H_

extern int eventTitleLength;
extern int sellerNameLength;
extern int userNameLength;

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
string int_array_to_string(int int_array[], int size_of_array);
string addZeros(string credit, int size);
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
	if(C.length() < 9){
		int size = C.length();
		temp->availableCredit = addZeros(C, size);
	}else{
		temp->availableCredit = C;
	}
	return temp;
}
struct DTF2{
	// refund
	string transActionCode;
	string buyerName;
	string sellerName;
	string refundCredit;
};
DTF2* CreateDTF2(string tC, string uN, string sN, string C){
	DTF2* temp = new DTF2;
	temp->transActionCode = "05";
	if(uN.size() < userNameLength){
		// get size of username;
		int size = userNameLength-uN.size();
		temp->buyerName = spaces(uN, size);
	}else{
		temp->buyerName = uN;
	}
	if(sN.size() < sellerNameLength){
		// get size of username;
		int size = sellerNameLength-sN.size();
		temp->sellerName = spaces(sN, size);
	}else{
		temp->sellerName = sN;
	}
	if(C.length() < 9){
		int size = C.length();
		temp->refundCredit = addZeros(C, size);
	}else{
		temp->refundCredit = C;
	}
	return temp;
}
struct DTF3{
	// buy and sell
	string transActionCode;
	string eventName;
	string sellerName;
	string ticketNum;
	string ticketPrice;
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
	// convert int to string
	ostringstream itS;
	itS << tN;
	string t(itS.str());
	if(t.length() < 3){
		temp->ticketNum = addZeros(t, t.length());
	}else{
		temp->ticketNum = t;
	}
	// convert float to string s
	ostringstream ss;
	ss << tP;
	string s(ss.str());
	if(s.length() < 6){
		temp->ticketPrice = addZeros(s, s.length());
	}else{
		temp->ticketPrice = s;
	}	
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

/*
 * Casts an integer array to a string
 */
string int_array_to_string(int int_array[], int size_of_array){
	ostringstream oss("");
 	for (int temp = 0; temp < size_of_array; temp++){
  		oss << int_array[temp];
 	}
 	return oss.str();
}

/*
 * add zeros to the beggining of credits
 */
string addZeros(string credit, int size){
	int arr[size];
	for(int i=0; i<size; i++){
		arr[i]=0;
	}
	credit = int_array_to_string(arr, size)+credit;
	return credit;
}

#endif