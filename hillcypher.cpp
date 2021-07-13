#include<iostream>
#include<math.h>
#include "Hill.h" //This provides the connection between hillcypher.cpp and Hill.h

/*
					B00340010_GRLA09003_01
*/
using namespace std;

int main() {
	//The main allows the user to interact with the programme and the functions stored in the class Hill
	Hill hillRun; //Here I am instantiating Hill and creating the object hillRun. The object is copying the class Hill from hillcypher.cpp
	hillRun.getKeyMessage();//The object hillRun calls the function getKeyMessage from the Hill class 
	//hillRun.encryption(); 
	//hillRun.decryption(); //The object hillRun calls the function decryption from the Hill class 
	cout << "1. Start Encryption and Decryption\n2. Exit Programme\nChoose(1/2): "; //gives the user the option to encrypt and decrypt the inputted message or exit the programme
	int choice;
	cin >> choice; //user inputs a choice


	if (choice == 1) { //if the user selects choice 1 then the users inputted message is encrypted and decrypted
		hillRun.encryption(); //The object hillRun calls the function encryption from the Hill class 
		hillRun.decryption(); //The object hillRun calls the function decryption from the Hill class 
		return 0;
	}
	else if (choice == 2) {
		return 0; //The programme will be terminated if the user selects choice 2
	}
}


