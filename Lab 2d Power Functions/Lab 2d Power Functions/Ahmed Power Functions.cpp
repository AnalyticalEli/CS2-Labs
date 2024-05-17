//Eli Ahmed
//Lab 2d Power Functions + Accumulator

#include<iostream>

using namespace std;



//Regular C-type Function Prototypes



//Iterative Power Function Prototype

double powIterative(double x, int n);



//Recursive Power Function Prototype

double powRecursive(double x, int n);




int main(void) {

	double x;

	int n;  //Exponent

	char userResponse; //For do while loop

	do {
		
		//User Inputs
		cout << "Enter a value for your base term (x): ";
		cin >> x;


		cout << "Enter a value for your power (n): ";
		cin >> n;


		powIterative(x, n);

		powRecursive(x, n);


		double resultItereative = powIterative(x, n);

		double resultRecursive = powRecursive(x, n);



		cout << "Result (Iterative) is: " << resultItereative << endl;  //Prints Iterative answer
	
		cout << "Result Recursive is: " << resultRecursive << endl;		//Prints Recursive answer


		cout << "Do you want to input more values? (y or n) "; //User Input on whether they want to continue!
		cin >> userResponse;


	} while (userResponse != 'N' && userResponse != 'n');


	//Do while will continue unless you input N or n.


	return(0);
}



//Iterative Power Function Implementation

double powIterative(double x, int n) {

	double result = 1.0;  //Makes it easier to change result value.
						  //Because it's a double doing 1.0.

	if (n == 0)     //This automatically gives us 1 if our value is 0
		return result;   //Because it's a double doing 1.0.


	else if (n >= 0) {   //Pro tip: Usually Iterative Means For Loops 

		for (int i = 0; i < n; i++) {

			result = result * x;  //Meaning the result is going to 
								  //be consecutively mulitplied to the next

		}
	}


	else {   //If user inputs a negative value.
		cout << "Invalid value, enter a positive." << endl;
	}


}



//Recursive Power Function Implementation

double powRecursive(double x, int n) {

	if (n == 0)     //This automatically gives us 1 if our value is 0
		return 1.0;  //Because it's a double doing 1.0.


	else if (n >= 0) {      //Our recursive function for powers.

		return(x * powRecursive(x, (n - 1)));

	}

	else{   //If user inputs a negative value.
		cout << "Invalid value, enter a postive one." << endl;
	}

}