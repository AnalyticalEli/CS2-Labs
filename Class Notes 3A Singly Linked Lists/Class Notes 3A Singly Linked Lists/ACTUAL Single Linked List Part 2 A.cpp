// Class Notes: Singly Linked List 
// An abstraction of an array.
//02/12/24

#include <iostream> 
#include <string>
using namespace std;

// Class that defines the node object
class Node {
private:
	string item;
	Node* nextPtr;

public:
	//constructors
	Node();
	Node(string);
	Node(string, Node*);

	//Accessor Methods
	void setItem(string);
	string getItem();
	void setNextPtr(Node*);
	Node* getNextPtr();

};
//Node has a string item and a Node* nextPtr


//This class is our Linked List 

class ourLinkedList {

private:

	Node* head;  //Head will have "item" and "nextPtr"

	//Node* tail; 


public:

	//Constructors

	ourLinkedList();

	ourLinkedList(Node* argHead);



	//Accessor Methods

	void setHead(Node* argHead);

	void getHead(void);


	//This might be useful for doubly linked 
	//void setTail(Node* argPtr);   //This creates nodes (aka tails because they're new and not current picked)

	//Node* getTail(void);         //Same as above;



	//Utility Methods:
	




	//Destructor


	/*for next class let's make a tailPtr
	we can look at other methods before we jump to doubly linked
	maybe add in the middle
	delete from somewhere without destructing whole list
	
	*/

};




//regular c-type function for printing the Linked List
void printStringList(Node* beginningNodePtr);

int main(void) {

	// 1. Note the difference between a pointer and Node Object
	Node* headPtr = nullptr;        //Always set node* ptr = to nullptr.
	Node myNode; //compile time instance

	Node* curNodePtr = nullptr; //temp curNodePtr is often called the iterator

	// 2. If you want to see the hard coded oart see the pre-existing lecture. We're switching to a class

	printStringList(headPtr);


	// 3. Memory Management (Clean-up when done from front)  //The explaination is on the first notes. 
	//The explaination of hard coded part is on the first notes.
	
	headPtr = new Node("ab");
	ourLinkedList myList(headPtr);

	curNodePtr = new Node("cd");
	myList.setTail(curNodePtr);
	
	curNodePtr = new Node("cd");
	myList.setTail(curNodePtr);

	curNodePtr = new Node("cd");
	myList.setTail(curNodePtr);


	curNodePtr = new Node("cd");
	myList.setTail(curNodePtr);

	curNodePtr = new Node("cd");
	myList.setTail(curNodePtr);


	//Lines for cd - ij, can be written as a single line of code (better way).

	myList.setTail(new Node("kl"));

	myList.addNodeFront(new Node("80?"));

	myList.addNodeMiddle("")



	printStringList(headPtr);

	return (0);
}





//Constructors for Linked List

ourLinkedList::ourLinkedList() {

	setHead = 

}

ourLinkedList::ourLinkedList(Node* argHead) {

	setHead();

}



//Accessor Methods for Linked List

void ourLinkedList::setHead(Node* argHead) {

	head = argHead;    //Gets head info from private 

}

Node* ourLinkedList::getHead(void) {

	return head;

}


void ourLinkedList::setTail(Node* argPtr) {   //This creates nodes (aka tails because they're new and not current picked)
	
	Node* tempPtr = getHead();     //This checks is the head empty.

	if (tempPtr == nullptr) {     //this accomadates empty lists,  

		cout << "This starts a new list " << endl;

		setHead(nullptr);

		return;     //This breaks us out if the list was empty so it doesn't add node twice.

	}


	//then we need to cycle through a long list to get to the end. Assuming that the top is skipped (isn't met)

	while (tempPtr->getNextPtr() != nullptr) {   //So meaning if it's not empty this condition will act

		tempPtr = tempPtr->getNextPtr();
	}

	tempPtr->setNextPtr(argPtr);

}



Node* ourLinkedList::getTail(void) {

	Node* tempPtr = getHead();     //This checks is the head empty.

	if (tempPtr == nullptr) {     //this accomadates empty lists, 

		return tempPtr;

	}

	//then we need to cycle through a long list to get to the end. Assuming that the top is skipped (isn't met)

	while (tempPtr->getNextPtr() != nullptr) {   //This accomadates 

		tempPtr = tempPtr->getNextPtr();
	}

	
	return tempPtr;    //Will only run if Linked List IS NOT empty (meaning if it's "while" condition)
}



//sof ar this works on middle and end. now we need it to work on front

void ourLinkedList::addNode(Node* argNode, string arg) {


	Node* temp = getHead();

	//Step 1 on paper
	if (temp == nullptr) {

		cout << "List doesn't exist, starting new list. " << endl;

		setHead(argNode);

		return;
	}


	//Step 1 on paper
	temp = searchForValue(arg); //This shpuld return ptr to 
	//Node before the insertion point.





}



void ourLinkedList::addNodeFront(Node* argNode) {

	


}


void ourLinkedList::addNodeMiddle(Node* argNode) {


	//Extunating 
	
	Node* temp = getHead();

	//Should return pointer to Node before insertion point.


	//Step 1 on paper
	if (temp == nullptr) {

		cout << "Empty List. " << endl;

		return;
	}


	//Step 1 on paper
	temp = searchForValue(arg); //This shpuld return ptr to 
	//Node before the insertion point.





}


Node* ourLinkedList::searchForValue(string arg) {

	Node* temp = getHead();


	if (temp == nullptr) {

		cout << "No value " << endl;


	}


	while (temp->getNextPtr() != nullptr) {


		if (temp->getItem() == arg) {

			return ;

		}


	}



}



ourLinkedList::~ourLinkedList() {

	//we need to delte the nodes and the list at the end,

	Node* temp = getHead();
	Node* currPtr = temp;

	if (temp == nullptr) {  //Meaning it's empty

		cout << "There's no list to delete, scrub. " << endl;

		return;
	}


	while (temp->getNextPtr() != nullptr) {


		setHead(temp->getNextPtr());

		cout << "Deleting " << temp->getItem() << endl;

		delete temp;

		temp = getHead();

	}

	cout << "Deleting " << temp->getItem() << endl;

	delete temp;

	temp = nullptr;

	setHead(nullptr);


	cout << "Linked List is empty " << endl;

}
//Destructor







void printStringList(Node* beginningNodePtr) {

	Node* tempNodePtr = beginningNodePtr;

	cout << "******************" << endl;
	if (tempNodePtr == nullptr) {        //This is just checking and making sure nullptr is empty
		cout << "List Empty" << endl;
	}
	else {					//If it's not (else) then it prints out the node before last that's not empty
		while (tempNodePtr->getNextPtr() != nullptr) {

			cout << tempNodePtr->getItem() << endl;
			tempNodePtr = tempNodePtr->getNextPtr();

		};

		//This line below takes care of final gap and prints final item
		cout << tempNodePtr->getItem() << endl;

	}
	cout << "******************" << endl;

}


//Node Implementation
Node::Node()
{
	setItem(""); //default to empty string
	setNextPtr(nullptr); //default to null pointer
}

Node::Node(string arg)
{
	setItem(arg);
	setNextPtr(nullptr);
}

Node::Node(string arg, Node* argPtr)
{
	setItem(arg);
	setNextPtr(argPtr);
}

void Node::setItem(string arg)
{
	item = arg;
}

string Node::getItem()
{
	return item;
}

void Node::setNextPtr(Node* argPtr)
{
	nextPtr = argPtr;
}

Node* Node::getNextPtr()
{
	return nextPtr;
}