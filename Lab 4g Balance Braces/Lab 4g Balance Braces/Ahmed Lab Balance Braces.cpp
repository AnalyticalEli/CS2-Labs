//Eli Ahmed
//Lab 4d Balance Braces (USING STRING CHAR STACK NO ITERATORS) Code Efficient.

#include<iostream>
#include<string> //In case we use string or getline
#include<stack>   //For the stack library

using namespace std;


//C-type Function that checks: Prototype  (In Personal notes: 1-2 functions checking balance, & 1 function that iterates through) 


bool stringChecker(string argStr);  //Same there here, went with lower memory management since bools take up way less memory 
									   //IF it's called MANY TIMES in the main (50-100). 

									//GOT it done with one USING FOR loop! (Other one iterators took 2 functions (one to check, and one to balance)



int main(void) {


	
	cout << "Objective: Create a program that can determine if a string is balanced with braces\n" << endl;  //With {} [] & ()

	char userInput;  //For do while loop to rerun

	string userStr;   //To check the user string to see if it's balanced


	//User Interface that takes in string


	do {

		cout << "Enter your string to see if it's balanaced: ";
		getline(cin, userStr);
		     //This is to make it so no issues on the processing side


		if (stringChecker(userStr)) {
			
			cout << "The string is balanced. " << endl;
		}

		else {
			cout << "The string is not balanced (ERROR) " << endl;

		}


		cout << "Do you want to enter other values?: ";
		cin >> userInput;
		cin.ignore();   //This is to make it so no issues on the processing side


	} while (userInput != 'n' && userInput != 'N');    //Will continue until user types in N or n



}



//C-type Function Implementation


bool stringChecker(string argStr) {   // C-type Function that iterators through each char if there & ORDER INDEPENDENT


	stack<char> myString;  //Creating stack object.  (Didn't use 


	//IF DONE WITH ITERATORS:
	//Explaining why I'm using auto for below
	//auto itrString = argStr.begin();   //Like we've said before in previous code, the auto tells the compiler what the data type & two it allows the
									  //iterator to be more extensible for other data types 
									 // (again will try not to use it too often as I know it can become tedious.)

	//(auto itrString = argStr.begin(); itrString != argStr.end(); itrString++) {  //Starting at b

		//char current = *itrString;    //Our current string ptr. //This would be in the in the for loop RIGHT ABOVE


	for (int i = 0; i < argStr.length(); i++) {

		char current = argStr[i];

		//if (isBalanced(current)) {  //This function checks if the current ptr in stack is an opening brace 

		if (current == '(' || current == '{' || current == '[') {    //If the curent ptr is any of the braces()
				myString.push(current);					 //IT then adds the current char (ptr) to the top of (in this its the braces) 
		}

		else {

			if (myString.empty())
				return false;


			char top = myString.top();  //Since ptr declared above no need to redeclare.

			myString.pop();  //Popping value off of top off current.


			if (!((top == '{' && current == '}') || (top == '(' && current == ')') || (top == '[' && current == ']'))) {  //This one is a chonk boi.

				return false;    //If it's not a brace of any kind then return false (don't count).


			}   //If popped isn't a brace, then we tell the complier to ignore it for the stringChecker.
				//Again we only want to ensure that the braces are balanced everything else is fair game.

		}


	}

	return (myString.empty());   //Returns this when the string is braces are balanced :)  (All values popped and balanced)

}

