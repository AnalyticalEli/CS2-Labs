//Eli Ahmed
//Lab 2c Recursive Pi Function

//Pi is a Leibniz series: 4 * (1 - 1/3 + 1/5 - 1/7 + 1/9 - 1/11 + 1/13 - 1/15 .....

//Pi 3.141592653589793 & we want to make
//function that prompts user to input place how far in the 
//series they want.


#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;


//C-type Function Prototype

double recursivePi(int nTerms);   //Recursive Pi Function (function MUST be a double) 



int main(void) {

	int n;

	char userResponse;


	do {

		cout << "Finding recursively. Chose how may terms (number) to use: ";
		cin >> n;

		cout << "\t Pi with " << n << " terms = " << recursivePi(n) << endl;



		cout << endl << endl;

		cout << "Do you want to run again (y or n)";
		cin >> userResponse;


	} while (userResponse != 'n' && userResponse != 'N');   //As long as the user DOESN'T use N AND n, 
	//the code will continue  (!= only works with &&)
   //Could also use while(userResponse == 'y' || userResponse == 'Y')

	return(0);

}



//C-type Implementation


double recursivePi(int nTerms) {   //Recursive Pi Function


	if (nTerms == 1)    //It's saying n == 1, which has no value, it will return n = 4, because 4 is the
		return 4.0;     //the base case for the series. 
						//The int sign 1 is 


	//The pow(-1, nTerms + 1) ensures that each term has a different sign than the last. 
	double terms = pow(-1, nTerms + 1) * 4.0 / (2 * nTerms - 1);   //our sum value that goes into the return

	return (recursivePi(nTerms - 1) + terms);
}

