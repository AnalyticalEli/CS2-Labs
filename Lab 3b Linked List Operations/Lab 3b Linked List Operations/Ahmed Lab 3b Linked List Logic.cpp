//Eli Ahmed
//Lab 3b Linked List Operations  (This is better than Lab 3a)
// 
// Exact same as the other 3b, however printBackwards function doesn't use direct accumulator
// instead it uses linked list logic to set the current at the end, the counts backward until 
//it reaches the head. (Uses Linked List Logic) 


#include<iostream>
#include<string>


using namespace std;


//The node structure for nodes in linked lists

class Node {

private:

	string data;   //If you get error for string here it's a glitch

	Node* nextPtr;


public:


	//Constructor Prototype 

	Node(string value);


	//Accessor Methods

	void setData(const string& value);  //Set Method for the adress of string 

	string getData(void);   //Get Method for Data


	void setNext(Node* nextNode);  //Set Method for the adress of string 

	Node* getNext(void);   //Get Method for Data



};




//C-type Function For Single Linked List Prototypes


void printForward(Node* head);   //Using node head pointer to print forward 

void printBackwards(Node* head);  //Using node head pointer to print backward

int countElements(Node* head); //This accumulator counts all of the elements
//in the linked list


void deallocateList(Node* head); //Deallocates memory in each node to
//free up space taken by linked list.



int main(void) {

	//Ensuring linked list is empty (GOOD PRACTICE) 

	Node* head = nullptr;  //Initializes empty linked list before adding nodes

	Node* tail = nullptr;  //Initializes empty linked list before adding nodes



	//Setting getline for user input, and do while loop char response

	string userInput;
	char userResponse;


	//Do while loop for singly linked list

	do {

		cout << "Enter a phrase or value for node: ";
		cin >> userInput;	 //For strings getline & string libr

		//cin.ignore();

		Node* newNode = new Node(userInput); //Initiating new Node
		//(IMPORTANT)


		if (head == nullptr) {  //If linked list is empty

			head = newNode;  //Head pointer is upated to point to this as first node

			tail = newNode;   //Tail pointer us also updated to point to newNode as first and last node;

		}
		else {   //If linked list is not empty

			tail->setNext(newNode);  //Links current last node to new node, 
			//making new node the new last node in list


			tail = newNode; //After updating tail ptr points to new node
			// "newNode" and now is the last node in list.
		}


		cout << "Do you want add another node to the list? (y or n): ";
		cin >> userResponse;

		cin.ignore();

	} while (userResponse != 'N' && userResponse != 'n');

	//Will continue until user inputs no. (N or n)



	//Printing Forward and Backward

	cout << "\n Print Linked List Forward: ";
	printForward(head);


	cout << "\n Print Linked List Backwards: ";
	printBackwards(head);



	//Accumulator counting every element in linked list

	int element = countElements(head);  //Renaming for simplicity


	cout << "\n Number of elements in the Linked List: " << element << endl;


	//Finally & Most importantly Delloacting memory to regain space.

	deallocateList(head);


	return(0);
}




//Constructor Implementation

Node::Node(string value) {

	setData(value);   //Indirect access of setData


	setNext(nullptr);  //Automatically sets the next one to nullptr,
	//meaning the next is the last in linked list
   //which ensures that the node doesn't point to any 
  //other node in the beginning. This is helpful because
 //in the linked list due to this this Ptr, will update
//to point to the next node in the sequence.


}



//Accessor Methods for Data (set and get methods)

void Node::setData(const string& value) { //Set Method for the adress of string 

	data = value;     //Accessing the data indirectly.

}

string Node::getData(void) {   //Get Method for Data

	return data;  //Return data we indirectly accessing.

}



void Node::setNext(Node* nextNode) {  //Set Method for getting the Next Ptr

	nextPtr = nextNode;   //Indirectly access nextPtr by setting 
	//equal to nextNode 


}


Node* Node::getNext(void) {  //Get Method for getting the Next Ptr

	return nextPtr;

}



//C-type Function For Single Linked List Implementation


void printForward(Node* head) {   //Using node head pointer to print forward 


	while (head) {

		cout << head->getData() << " ";  //Head pointer goes to get data

		head = head->getNext();   //Afterward, sets the new head to get
		//the next head.
	}


}

void printBackwards(Node* head) {

	Node* current = head;  //While the node pointer is at current head

	while (current && current->getNext()) {  //This ensures that current null and the next isn't null
											//meaning it will only trigger if something is there and for next at the end;


		current = current->getNext();   //Then move and get the next head consectively, 
		//NOW current is the LAST one in the list or end.



	}


	//Once we're at the end node of the list thanks to the while above, time 



	int x = countElements(head);


	for (int i = x; i > 0; i--) {


		for (int j = 0; j > i; j++) {

			current = current->getNext();  //Then move and get the next head consectively, 
										   //NOW current is the LAST one in the list or end.


		}


		cout << current->getData() << " ";

		current = head;     //Cycles until the current is equal to the beginning.


	}


}


int countElements(Node* head) { //This accumulator counts all of the elements
	//in the linked list.

	int count = 0; //Initiliazing accumulator


	while (head) { //While head != nullptr

		count++;  //Counts each consecutive element. (Node is element in this case)

		head = head->getNext(); //Gets next element once it's counted


	}


	return count;  //Returns the count number after running.
}


void deallocateList(Node* head) { //Deallocates memory in each node to
	//free up space taken by linked list.

	Node* temp; //Node is temp (or temporary placeholder)

	while (head) { //While the next isn't a nullptr

		temp = head;  //While node pointer is head

		head = head->getNext(); //It consectively gets the next if not empty

		delete temp; //Deletes aka dellocates memory to free up space.

	}


}