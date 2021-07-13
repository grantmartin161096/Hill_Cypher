#include<iostream>
#include<math.h>
using namespace std;

/*
					B00340010_GRLA09003_01
*/

class Hill { //The code below is stored within the Hill class
public: //This makes the attributes and functions contained in te class public, so they can be accessed outside the class
	float encrypt[3][1], decrypt[3][1], a[3][3], b[3][3], mes[3][1], c[3][3]; //class attributes

	void encryption() { //function encryption is used to encrypt the users inputted 3 character text
		int i, j, k; //attributes used in the encryption function
		for (i = 0; i < 3; i++)
			for (j = 0; j < 1; j++)
				for (k = 0; k < 3; k++)
					encrypt[i][j]= encrypt[i][j] + a[i][k] * mes[k][j];
		// In the code above the key and message strings inputted by the user are converted into a matrix, and the key and message are multiplied
		cout << "\nThe Encrypted text is: "; //outputs the encrypted message and displays to the user
		for (i = 0; i < 3; i++)
			cout << (char)(fmod(encrypt[i][0], 26) + 97); // for each element of the matrix generated by the multiplication modulo 26 is applied  
//outputs the encrypted message and displays to the user
	}

	void decryption() { //function decryption is used to decrypt the users inputted 3 character text
		int i, j, k; //attributes used in the decryption function
		inverse(); // here the inverse function is called and run

		for (i = 0; i < 3; i++)
			for (j = 0; j < 1; j++)
				for (k = 0; k < 3; k++)
					decrypt[i][j] = decrypt[i][j] + b[i][k] * encrypt[k][j];
		// In the code above the encrypted message (text inputted by user) is multiplied by the key matrix inputted by the user
		cout << "\nThe Decrypted text is: ";
		for (i = 0; i < 3; i++)
			cout << (char)(fmod(decrypt[i][0], 26) + 97); // finally modulo 26 applied
//outputs the decrypted message and displays to the user

	cout << "\n";
	}

	void getKeyMessage() { //function getKeyMessage is used to get the users inputted 3 character text and inputted 3x3 key matrix
		int i,j;
		string msg;
		
		//attributes used in the getKeyMessage function
		cout << "Start Programme by entering the 3x3 matrix manually: \n"; //user shown this message

		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++) {
				//cin >> a[i][j]; //users inputted 3x3 key matrix
				//c[i][j] = a[i][j];
				cout << "Enter " << i + 1 <<  "*"  << j + 1 <<  " value: \n";
				cin >> a[i][j];
				c[i][j] = a[i][j];
			}

		cout << "\nPlease enter 3 letters to encrypt and decrypt: "; //user shown this message
		cin >> msg; //users inputted message is stored as msg

		
		// message to uppercase
		for (int i = 0; i < 3; i++) {
			msg[i] = tolower(msg[i]);
		    }

		for (i = 0; i < 3; i++)
			mes[i][0] = msg[i] - 97;
	}

	void inverse() { //function inverse is used to calculate the inverse which is called in the decryption function
		int i, j, k;
		float p, q;
		//attributes used in the inverse function
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++) {
				if (i == j)
					b[i][j] = 1;
				    
				else
					b[i][j] = 0;
			}

		for (k = 0; k < 3; k++) {
			for (i = 0; i < 3; i++) {
				p = c[i][k];
				q = c[k][k];

				for (j = 0; j < 3; j++) {
					if (i != k) {
						c[i][j] = c[i][j] * q - p * c[k][j];
						b[i][j] = b[i][j] * q - p * b[k][j];
					}
				}
			}
		}

		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				b[i][j] = b[i][j] / c[i][i];
		// The code above is used to find inverse of key matrix
		cout << "\n\nThe inverse values of the matrix are:\n"; //user shown this message
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++)
				cout << b[i][j] << " "; //user is displayed with the inverse value of each element 

			cout << " \n";
		}
	}
}; 
/*
End of the programme

References used to help in the developmentand execution of the above code :
https://www.geeksforgeeks.org/hill-cipher/
https://www.tutorialspoint.com/cplusplus-program-to-implement-the-hill-cypher
https://www.youtube.com/watch?time_continue=6&v=_T4rFzjVQCk&feature=emb_logo
https://www.youtube.com/watch?v=ZEu6sAepFVU
https://en.wikipedia.org/wiki/Hill_cipher
https://www.tutorialspoint.com/design_pattern/singleton_pattern.htm

Future Improvements and Criticisms:
1. Currently, the user must enter a 3x3 matrix for the key manually. In future releases I would like to generate a random key
to improve the security of the encryption/decryption also it is less numbers for the user to input into the programme.
2. Currently, the key is in the form of integers and would like to use characters for the key.
3. The biggest criticism is currently I can only encode and decode 3 letter strings for the next release I would like to be
able to enter any length of string and have the ability to encode and decode all of the letters in the string and not just the first 3.
4. NOTE: Sometimes I receive the error message - int to float can cause possible loss of data and this can cause the encryption value and 
decryption value to be outputted incorrectly.
*/