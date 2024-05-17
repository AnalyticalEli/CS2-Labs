//Eli Ahmed
//Lab 7a String Hash Functions (Simple Hash)

#include<iostream>
#include<string>
#include<vector>

using namespace std;

//C-type Hash Functions Prototype (Prompt Goal)
int stringToIndexHash(string userName, int buckets);


int main(void) {

	//Prompt (Objective)

	cout << "Create a simple hash function (regular c-type function) that takes in a string & an integer number of buckets & returns an integer bucket index. NO HASH TABLE!!\n" << endl;

	int numBuckets;  //Setting data type for numBuckets and userName
	string userName;
	char userInput;  //For do loop 


	do {

		//User Interface (UI) 

		cout << "Enter a UserName if you will: ";
		getline(cin, userName);

		cout << "Enter a the number of buckets: ";  //This is incorrect (Because it attempts to Use ASCII VALUES BUT FAILS HORRIBLY)
		cin >> numBuckets;


		//Calling the hash function using our collected data from UI Above & Turning them into 
		//int buckets

		int bucketIndex = stringToIndexHash(userName, numBuckets);


		//Display Function:
		cout << "The bucket index for: " << userName << " is " << bucketIndex << endl;


		cout << "Do you want run the code again? ";
		cin >> userInput;
		cin.ignore();  //To avoid runtime issues.


	} while(userInput != 'n' && userInput != 'N');   //Allows user to rerunas many times as they want.
													//Until they enter N or n

	return 0;

}


//C-type Hash Functions Implementation (Prompt Goal) 
int stringToIndexHash(string userName, int buckets) {

	//Using for loop to cycle through function.
	
	int sum = 0;  //Setting accumulator at 0 

	for (int i = 0; i < userName.size(); i++) {

		sum += int(tolower(userName[i]));  //Adds the ASCII Value each UserName char, consecutively:
										  //So For Example Cats -> cats because of tolower 
										  // c + a + t + s = 99 (c) + 97 (a) + 116 (t) + 115 (s)  = 427
	}

	return(sum % buckets);   //Integer division (So 427 % 10 Buckets) = 7 (modulus remainder)
							 //SO no matter what Hash Function is always 
							//Organzied in a proper index.
}
