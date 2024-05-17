//Eli Ahmed
//Lab 3D Class Singly Linked List (With Templates)  Notes to put 

#include<iostream>
#include<string>  //For string processes
#include<ctime>    //For srand (Random time) 
#include<cstdlib>  //For srand (Random time) 

using namespace std;


//Class to hold chars 
template<class T = string>
class Node {

private:

	T item;  //T is string so item is a string

	Node<T>* nextNode;   //The node pointer is a string


public:

	//Constructors Prototype

	Node(void);  //Default constructor to hold Chars 

	Node(T arg);

	Node(T arg, Node* argPtr);


	//Accessor Method Prototype

	void setItem(T argItem);  //Accessor methods Item

	T getItem();			  //Accessor methods Item

	void setNextNode(Node* argPtr);  //Accessor methods NextNode

	Node* getNextNode();       //Accessor methods NextNode

};


//C-type Function Prototype & Template Prototype

template<typename T = char>       //For regular c-type function templates
void printCharList(Node<T>* headPtr);  //Must input typename T = (datatype) 
								     //for each c-type Function


template<typename T = string>		 //For regular c-type function templates
void deleteLinkedList(Node<T>* head);  //Must input typename T = (datatype) 
									//for each c-type function.




int main(void) {


	cout << "Goal: Create a dynamic random num letter generator (1-100)." << endl;


	srand(time(0)); //For random number generator

	char userInput;  //For do while loop 


	do { 

		//Using a for loop to generate each rand number (a-z)

		int const size = 101;  //Because 1 value is null, so 101 = 100 spaces
		//char arr[size];  //Saying the data type of the values are char


		Node<char>* head = nullptr;  //Char because template, and setting equal to nullptr
		//to ensure that it starts at headptr and is empty
		//before starting. (GOOD PRACTICE) 


		for (int i = 0; i < size; i++) { //For loop accumulates 

			char randomChar = 'a' + rand() % 26;  //Using ASCII values with char 'a' and 
			//dividing with 26 because there are 26 letters
			//in the alphabet


			Node<char>* newNode = new Node<char>(randomChar);  // Creating a new node with randomChar Accumulator above (a-z) 100 times

			newNode->setNextNode(head); //Setting the next node as the current head

			head = newNode; //Updating the head to point to the new node.

		}


		//Prints the chars to inside the Linked List (NO user interface)  Starting from head


		printCharList(head);    //Starting from head



		//Deletes and deallocates memory in EACH node: (Starting from head)

		deleteLinkedList(head);


		cout << "Do you want run another simulation of a 100 set of random numbers? ";  //Matrix Vibes
		cin >> userInput;
		
	} while (userInput != 'n' && userInput != 'N');  //Will continue to run until user puts either N or n. 


	return(0);
}





//Constructor Implementation Node (Must put template IF
								 //using template class)

template<class T>   //We've set T = string. So anytime T is used it's inferred it's a string.
Node<T>::Node(void) {  //Default constructor to hold Chars 

	setItem(" "); //default to empty string

	setNextNode(nullptr); //Default set to nullptr.

}




template<class T>   
Node<T>::Node(T arg) {  //<T> inside scope resolution (::) IS MANDATORY for class templates.

	setItem(arg); 

	setNextNode(nullptr);  //Inputting nullptr for the next/last node


}

template<class T>
Node<T>::Node(T arg, Node* argPtr) {

	setItem(arg);

	setNextNode(argPtr);  //Entering value for PTR after inputting
						  //default PTR as nullptr

}



//Accessor Methods Implemetnation


template<class T>
void Node<T>::setItem(T argItem) {

	item = argItem;


}



template<class T> 
T Node<T>::getItem() {   //What this is saying is: String Node(String Template)  as T was set to string at top.


	return(item);


}


template<class T>
void Node<T>::setNextNode(Node* argPtr) {


	nextNode = argPtr;

}



template<class T>
Node<T>* Node<T> ::getNextNode() {


	return nextNode;


}



//C-type Function Implementation

template<typename T>					//For regular c-type functoion Implementation
void printCharList(Node<T>* headPtr) { //Must input template< typename T> 
	//for each c-type Function WHEN USING
	//Template.

	Node<T>* tempNodePtr = headPtr; //Intitializing  temperorary pointer to the head
	//headPTR (or beginning of Linked List)


	if (tempNodePtr == nullptr) {  //If the list is empty

		cout << "List Empty " << endl;  //It prints List Empty


	}

	else {  //If list is populated & NOT empty

		while (tempNodePtr->getNextNode() != nullptr) {  //Goes through the list until it reaches the end
			//aka is a nullptr!

			cout << tempNodePtr->getItem();  //Prints the items stored in the current node after it sorts

			tempNodePtr = tempNodePtr->getNextNode();  //Moves to next node AFTER retreiving item
		}


		cout << "*&*&*&*&*&*&*&*&*&*&*&*&" << endl;  //Sepeartes each print out.


	}


}


 
template<typename T>		        //For regular c-type function templates
void deleteLinkedList(Node<T>* head) {  //Must input typename T = (datatype) 
										//for each c-type function.

	Node<T>* temp = head;   //Instantiates temp pointer to move through list


	while (temp != nullptr) {  //Meaning it's not at END (TAIL), so it can continue
							   //To move forward.

		Node<T>* nextNode = temp->getNextNode();  //Gets pointer to "point" at the next node


		delete temp;  //deletes and frees memory taken up by the node


		temp = nextNode; //Moves forward to next item in the Linked List


		//THIS ENTIRE PROCESS SEQUENTIALLY DEALLOCATES & DELETES EACH NODE TO FREE UP MEMORY.

	}

}