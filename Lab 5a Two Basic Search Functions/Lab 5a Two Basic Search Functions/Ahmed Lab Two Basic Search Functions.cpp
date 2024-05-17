//Eli Ahmed
//Lab 5a Two Basic Search Functions


#include<iostream>
#include<string>  //in case we need string
#include<vector>  //For vector inside both search Functions
#include<cstdlib>  //Seeding rand time
#include<ctime>  //Seeding rand time


using namespace std;


//C-type Function (Search Functions)

int searchListLinear(vector<int>& arg, int target);  //For a linear search
int searchListBinary(vector<int>& arg, int target);  //For a binary search

bool searchInt();  //For try and catch method.




int main(void) {


	//If integer is found, print "integer found" & if int not in list print -1.

	srand(time(0));   //Seeding rand time (TO get rand numbers)

	char userInput;
	int target;

	cout << "\nObjective: Populate and allow user to sort through random integers. " << endl;


	const int size = 100;
	//int arr[size];    //Declars the arr[size] as an int (BEEN A WHILE)


	vector<int> vec(size);  //Takes the same idea above, and applies it 
							//TO A VECTOR.


	for (int i = 0; i < 100; i++) {  //Generating 100 Unique random ints

		vec[i] = rand() % 10000;  //To generate values from 0 to 1000 and stores it in vector
		//int gets finnicky when value is too high

	}



	cout << "\nSorted Vector: " << endl;  //Prints the sprted vector.
	for (int i = 0; i < size; i++) {
		cout << vec[i] << " ";

	}

	cout << endl;  //Line betwewen the 



	do {


		cout << "\nEnter a value you want to search for: ";
		cin >> target;



		int linearResult = searchListLinear(vec, target);  //Find other value to put in the function
		int binResult = searchListBinary(vec, target);



		if (linearResult != -1 || binResult != -1)  //If target is found USING BOTH SEARCH FUNCTIONS
			cout << "\nInteger found using both linear and binary search " << endl;

		else
			cout << "\nInteger not found using both linear and binary search " << endl;




		cout << "\nDo you want to run again. ";
		cin >> userInput;


	}while(userInput != 'n' && userInput != 'N'); 

	//Will continue until user enters N or n.



	return(0);

}





//C-type Implementation (Search Functions)

int searchListLinear(vector<int>& arg, int target) {   //For a linear Search


	for (int i = 0; i < arg.size(); i++) {  //Goes and sorts through size of List

		if (arg[i] == target)  //If target is found return target.
			return target;

	}


	return -1;   //If not found it'll return -1
}

int searchListBinary(vector<int>& arg, int target) {   //For a basic Search


	int low = 0;
	int high = arg.size() - 1; //Because the size of the highest index is going
							   //to be one smaller than the actual vector.



	while (low < high) {  //While we're still in actual vector values themselves 
		int mid = low + (high - low) / 2;    //Continues the binary search

		if (arg[mid] == target)  //If the current mid is equal to the target
			return target;   //Gives us target

		else if (arg[mid] < target)  //If target is at place larger than the mid
									 //shifts the search to the right half
			low = mid + 1; 

		else  //If target is at place smaller than the mid shifts the
			high = mid - 1;       //search to the left half


	}

	return -1;  //If not found it'll return -1


}