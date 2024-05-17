//Eli Ahmed
//Lab 4a User Populated Stack (No Nodes) 

#include<iostream>
#include<stack>   //This is our stack library 
#include<string> //In case we use a string or its processes (getline) 
#include<vector>  //Because vectors can increase and decrease
				  //dynamically 

using namespace std;


int main(void) {

	//Objective: Create program that allows you to populate user input strings for dog names, 
	//prints and pops off the top of the stack & proper memory management.

	cout << "Objective: Create a program that allows you to dynamically populate, with proper pops and memory management.\n" << endl;

	string userResponse;


	stack<string*> myStack;  //Using a string PTR for 
							  //Data type.  (Nullptr must done after each.)

	string* topString = nullptr;  //Initiliazing the ptr topString to ensure it's empty.


	//User Interface (Allows user to input names) 

	cout << "Enter Dog names: (Press -1 when done) " << endl;  //Tried it inside loop, but it becomes annoying 
															   //reappearing on each response instead of just on top
															   // (waste of space)

	do{   //Allows us to redo 

		//cout << "Enter Dog names: (Press -1 when done) " << endl;
		getline(cin, userResponse);


		if (userResponse != "-1") {  //Keeps going until user 

			myStack.push(new string(userResponse));  //Enters all non -1 values, into the stack with as new string
													 // (MEANING we need to have a delete)

		}


	} while (userResponse != "-1");



	//I solved it! And figured out something interesting. Because Stacks start at the end LIFO (Last in First Out)
	//we can deallocate at each right before popping it out of stack existance. Using a loop.


	//Pop Back Front & Dynamic Memory Deallocation.  (To uncomment they changed in update Cntr + K then Cntrl + U)

	while (!myStack.empty()) {   //While the stack is not empty

		string* topString = myStack.top(); //StringPtr much like a NodePtr, is being set to the top of 
		//of the string.

		//TRIED THIS DID NOT WORK BECAUSE YOU CANNOT SET PTR = NULLPTR BEFORE DEREFENCING IT IN STACK
		//topString = nullptr;  


		cout << *topString << endl;  //Prints off top, and dereferences the topString


		delete topString;   //Deletes the topString (Pretty Self Explainatory)



		myStack.pop();  //Pops off each one if not empty


		topString = nullptr;  //Doing AFTER POPPING, because...
							  //Resetting topString to nullptr after each iteration guarantees an empty state of the next,
		                     //prevents dangling pointers, and is GOOD MEMORY management practice!
	                         //(GOOD MEMORY MANAGEMENT PRACTICE)

	}

	return(0);

}
