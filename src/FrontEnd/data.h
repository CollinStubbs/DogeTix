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

#endif