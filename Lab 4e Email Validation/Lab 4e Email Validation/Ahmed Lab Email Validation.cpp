//Eli Ahmed
//Lab 4h Email Validation (NO COUT)


#include<iostream>
#include<string>
#include<list>  //For list of approved emails

using namespace std;


//C-type Prototype for Validation

bool isEmailValid(string argEmail); //Makes sense email is either valid or not


int main(void) {

	string email;
	char userInput;


	do {

		cout << "\nEnter a valid email address: ";
		getline(cin, email);


		try {

			cout << isEmailValid(email) << endl;

			cout << "Email is valid! " << endl;
		}

		catch (exception e) {  //Catches if the value above is an error.

			cout << "Error: " << e.what() << endl;  //e.what() gives us what is error
		}

		cout << "Do you want to try again? (y or n) ";
		cin >> userInput;
		cin.ignore();


	} while (userInput == 'y' || userInput == 'Y');  	//Because this is email validation, went with it only continues 
														//if they (user) want to continue.


	return 0;
}



//C-type Implementation
bool isEmailValid(string argEmail) { //Makes sense email is either valid or not


	int atPos = argEmail.find('@');   //Moves the position to find the @ symbol.

	if (atPos == -1) {  //IF it doesn't have it (0 is a position in C++)

		throw exception("Email is missing @, please add");  //Returning false that the email is valid. (EMAIL IS NOT VALID)
	}


	string extension = argEmail.substr(atPos);  //Takes in pos above
	list<string> validEmailExtensions = { "@gmail.com", "@aol.com", "@cos.edu", "@giant.cos.edu" };


	//Using an iterator (BEST FOR LIST AND MAPS) 
	list<string>::iterator itrEmail;

	for (itrEmail = validEmailExtensions.begin(); itrEmail != validEmailExtensions.end(); itrEmail++) {

		if (extension == *itrEmail) {  //Takes ptr of iterator cycling through iterator.
									   //Comparing each and verifying good ones.
			return true;
		}
	}

	////IF (BAD Email Extension) IS RETURNED THEN IT IS FALSE.  
	throw exception("Invalid Email Extension");

}