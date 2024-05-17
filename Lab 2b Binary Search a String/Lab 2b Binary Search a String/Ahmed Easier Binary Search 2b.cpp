//Eli Ahmed
//Lab 2b Binary Search (Using Vectors) 



#include<iostream>
#include<vector> //For vector below.

using namespace std;


//Binary Search a String Prototype 


int binarySearch(const vector<int>& arr, int target);



int main(void) {

	//Instiatiting the vector.

	vector<int>arr  = { 2, 4, 6, 8, 10, 12, 14, 16, 20 };


	//Test cases for finding our searching values.

	cout << "First case: Searching for 16" << endl;

	int result = binarySearch(arr, 16 );  //Searching for 16


	if (result != -1) {

		cout << "Target found at index " << result << endl << endl;
	}

	else
		cout << "Target value not found in index " << endl << endl;




	cout << "Second case: Searching for 20" << endl;

	result = binarySearch(arr, 20);  //Searching for 16


	if (result != -1) {

		cout << "Target found at index " << result << endl;
	}

	else
		cout << "Target value not found in index " << endl;



	return(0);
}





//C-type Function Implemetation for Binary Search 


int binarySearch(const vector<int>& arr, int target) {

	cout << "Determines if target is in Array!" << endl;

	int size = arr.size();

	if (size == 1) {    //Base case if size is only 1 

		if (arr[0] == target)  //So if the target is found at
			return 0;			   //index 0, returns 0;

		else {			//Else it'll return -1;
			return -1;
		}

	}



	else {		//Remember that last of index array is null (\0) value 

		int first = 0;     //Instatiating the first index
		int last = size - 1;  //Instatiting that the size of the 
		//last value of index is 1 smaller than actual size of index 

		while (first <= last) {

			//Assuming that last is greater or equal to first
			//this determines where the midpoint is

			int mid = first + (last - first) / 2;



			if (arr[mid] == target)
				return mid;			//Target found in mid

			else if (target < arr[mid]) {
				last = mid - 1;  //Searches in the first half

			}

			else
				first = mid + 1;  //Searches in the second half

		}


		return -1;  //Cycles through above & if target not found
		//returns -1 here. 

	}



}