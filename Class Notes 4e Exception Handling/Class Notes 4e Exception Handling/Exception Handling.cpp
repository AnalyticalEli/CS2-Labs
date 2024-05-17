//Exception Handling ALLOWS us to get rid
//of the couts in functions.

//How it works is that if an exception happens
//in the "try block", the try block then expires
//and program control tranfers paramteres type
//that of the thrown exception.

#include <iostream>
#include <string>
using namespace std;

double quotient(int, int);

int main(void) {

	int n, d;
	char userResponse = 'y';

	do {
		cout << "\nEnter the numerator: "; //Top of fraction
		cin >> n;
		cout << "Enter the denominator: ";  //Bottom Of fraction
		cin >> d;

		//NEW try-catch block
		try {
			cout << quotient(n, d) << endl;  //If this does produce error goes straight to catch block of code
											 //This also checks for any BAD conditions that are met below in function
											 //like dividing by 0, etc.
			cout << "You got answer!" << endl;
		}

		//If there is a problem the error gets
		//put into this catch block over here.
		catch (exception e) {
			cout << "Error Message: " << e.what() << endl;
		}
		// get user response to run again.
		cout << "\nRun again? (y or n)";
		cin >> userResponse;
		cin.ignore();

	} while (userResponse == 'y');

	system("pause");
	return(0);
}

double quotient(int numerator, int denominator) {  //This gives us specific exceptions
												   //when those specific conditions are met.

	if (numerator == 0 && denominator == 0)
		throw exception("Indeterminate 0/0.");
	if (denominator == 0)
		throw exception("Cannot divide by zero.");

	//cast numerator to double to avoid integer division
	return (double)numerator / denominator;
}