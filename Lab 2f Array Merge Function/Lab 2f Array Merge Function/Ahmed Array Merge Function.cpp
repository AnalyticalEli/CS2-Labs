//Eli Ahmed 
//Lab 2f Array Merge Function

#include<iostream>


using namespace std;


//C-type Function Template Prototype

template<typename T>

void mergeArrays(const T* arr1, const T* arr2, T* result, size_t size);  //T* are just pointers to object T
																		 //the const ensures values won't be altered.


int main(void) {


	int arr1[] = {2, 4, 6, 8, 10};    //Array 1 values
	int arr2 [] = {12, 14, 16, 18, 20};  //Array 2 Values

	const size_t size = sizeof(arr1) / sizeof(arr1[0]);  //Calculates the size of the array and the elements in it.
	int result[2 * size];  //This ensures there's enough room for both arrays by declaring the size 
							//as double arr1. (Assumes that double of arr1 will be enough) 


	mergeArrays(arr1, arr2, result, size);

	cout << "Merged Array: ";

	for (size_t i = 0; i < 2 * size; i++) {  //This gives us enough space to merge the arrays.

		cout << result[i] << " ";  //Prints the result space

	}

	cout << endl;



	return(0);
}




//C-type Function Template Implementation

template<typename T>

void mergeArrays(const T* arr1, const T* arr2, T* result, size_t size) {

	for (size_t i = 0; i < size; i++) { //Accumulator for loop & size_t i = 0 initializes loop lower bound.

		result[i] = arr1[i];

		result[i + size] = arr2[i];   //This puts arr2[i] at the end of
									  //arr1[i] which makes sense since
									 //arr2 comes after.

	}


}