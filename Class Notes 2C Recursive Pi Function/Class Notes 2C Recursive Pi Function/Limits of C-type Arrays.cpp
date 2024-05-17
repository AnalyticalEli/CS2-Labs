//Limitations of C-type Arrays


//Recursive Pi Notes


//One of the Lab 2c, Recursive Pi 

//Pi is a mclaren series: 4 * (1 - 1/3 + 1/5 - 1/7 + 1/9 - 1/11 + 1/13 - 1/15 .....

//Pi 3.141592653589793 & we want to make
//function that prompts user to 


#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;



int main(void) {


	int n;

	char userResponse;

	//Exploring limiations of arrays
	 
	const int size = 3;   //Arrays can't change size at run time! :(
	int arr[size];

	arr[0] = 1;
	arr[1] = 7;
	arr[2] = 13;


	for (int n = 0; n < 5; n++) {

		cout << "arr[" << n << "] = " << arr[n] << endl;   //If we go past end of array (for example 5, when
														   //this is 3 long, it'll fill the array with junk 
														   // values

		cout << "Stored at" << int(&arr[n]) << endl;     //this is the address of the array 


														//Deleted files aren't deleted the memory is reallocated
														//but memory is still there unfortuantely
														//Arrays suck, even more whemn you try to delete from 
														//the middle
						

	}


	//To show the weaknesses of arrays we're setting arr[1] as NULL or doesn't exist

	arr[1] = '\0';   // '\0' is null, setting the value to 0, which is not ideal in array.

	for (int i = 1; i < size - 1; i++) {   //size - 1, means one smaller than the size off array

		arr[i] = arr[i + 1];  //This means one greater than 0


	}

	arr[size - 1] = 0;



	//for (int n = 0; n < size; n++) {

	//	cout 

	//}


	return(0);


}


