#include <iostream>
#include <fstream>
#include <string>

/*
	Reads in 2 files:
	1) file of tickets available for purchase
	2) file containing information regarding current user accounts
*/
int main(int argc, char* argv[]){

	// Check if the user input 3 arguements
	if(argc > 3 || argc == 1){
		// Open the first file
		ofstream file1;
		file1.open(argv[1]);
		
		// Open the second file
		ofstream file2;
		file2.open(argv[2]);
	}else{
		cout << "Usage: frontEnd [available_tickets_file] [info_file]" << endl;
	}

	return 0;
} 