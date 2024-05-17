//Recursive Pi Notes


//One of the Lab 2c, Recursive Pi 

//Pi is a mclaren series: 4 * (1 - 1/3 + 1/5 - 1/7 + 1/9 - 1/11 + 1/13 - 1/15 .....

//Pi 3.141592653589793 & we want to make
//function that prompts user to 


#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;


//C-type Function Prototype

int recursivePi(int nTerms);   //Recursive Pi Function 



int main(void) {


	//Iterative not recursion

	//for (int n = 1; n < 8; n++) {

	//	cout << pow (-1, n-1) * 4 << "\\"

	//

	//}

	int n;

	char userResponse;

	bool runAgain = 1;


	do {

		cout << "Finding Recursively: CHose how may terms (number) to use";
		cin >> n;

		cout << "\t Pi with " << n << "terms = " << recursivePi(n) << endl;



		cout << endl << endl;

		cout << "Do you want to run again (y or n)";
		cin >> userResponse;


	} while (userResponse != 'n' &&  userResponse != 'N');   //As long as the user DOESN'T use N AND n, 
															 //the code will continue  (!= only works with &&)
											//Could also use while(userResponse == 'y' || userResponse == 'Y')

	
			

	return(0);


}






//C-type Implementation

int recursivePi(int nTerms) {   //Recursive Pi Function

	if (nTerms == 1)     //It's saying n == 1, which has no value, it will return n = 0
		return 4;


	double sum = pow(-1, nTerms - 1) * 4.0 / (2 * nTerms - 1);   //Our sum value that goes into the return

	return sum + recursivePi(nTerms - 1);



}