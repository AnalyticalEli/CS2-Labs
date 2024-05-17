//Eli Ahmed
//Lab 3a Hard Code Linked Lists

#include<iostream>
#include<string>

using namespace std;


//Class that defines the node 


class Node {

private:
	string data;
	Node* nextPtr;


public:


	//Constructors for Node

	Node(string value);   //Uses indirect access to use nextptr as nullptr.


	//Accessor Methods 
	
	void setData(const string& value);   //Sets head from private

	string getData(void);		//Gets head from indirect access.


	void setNext(Node* nextNode);   //Sets nextPtr = nextNode 


	Node* getNext(void);   //Gets the Node Pointer, that we directly access
						   //and returns it.



};


//C - Type Function Prototype that takes a pointer to a Node (Node*) object,
//SPEFICALLY head of the linked list as its argument.  

void printLinkedList(Node* head);

void deallocateList(Node* head);



int main(void) {


	Node* head = new Node("hello");   //Hard coding Hello 

	Node* linked = new Node("linked");  //Hard coding Linked 

	Node* lists = new Node("list");		//Hard coding List


	head->setNext(linked);     //The -> is the same as a pointer (*) 

	linked->setNext(lists);



	//Call the function to print the contents of the linked lists

	printLinkedList(head);   //Cycles through the hard coded nodes pointers above



	//THIS IS OPTIONAL BUT IT'S TO FREE MEMORY USED BY THE LINKED LISTS:

	//delete head; delete linked; delete lists;


	return 0;
}




//Constructor Implementation for Node

Node::Node(string value) {

	data = value;

	nextPtr = nullptr;  //Automatically sets the next one to nullptr,
	//meaning the next is the last in linked list
   //which ensures that the node doesn't point to any 
   //other node in the beginning. This is helpful because
   //in the linked list due to this this Ptr, will update
   //to point to the next node in the sequence.


}


//Accessor Method Implementation for Node

void Node::setData(const string& value) {

	data = value;   //Indirectly accesses data by setting it equal to value


}



//Gets head from private

string Node::getData(void){


	return data;	//Returns the data that we indirectly accessed from above

}



void Node::setNext(Node* nextNode) {

	
	nextPtr = nextNode;    //This indirectly accesses the nextPtr in each line.

}


Node* Node::getNext(void) {  //Using Node Pointer 


	return nextPtr;    //This returns the nextPtr we indirectly accessed above.


}


//C-type Function Implementation for HEAD of Linked List. 

void printLinkedList(Node* head) {

	Node* current = head;


	while (current) {  //This while loop iterates through the linked list
					   //printing data stored in each node until END of list.

		cout << current->getData() << endl;

		current = current->getNext();


	}




}


//C-type Function Implementation

void deallocateList(Node* head) {




}
