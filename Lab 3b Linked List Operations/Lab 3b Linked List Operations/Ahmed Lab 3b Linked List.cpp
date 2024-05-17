//Eli Ahmed
//Lab 3b Linked List Operations  (This is better than Lab 3a) 

//Used Accumulator for printBackwards


#include<iostream>
#include<string>
#include<vector> //Vector libraray for Backwards function


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

		cin.ignore();  //Ensures there's no overlap when user hits run again.

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

	vector<Node*> nodeAddress;  //Creating vector NodeAddress.

	Node* current = head;  //While the node pointer is at current head

	while (current) {  //This ensures that current isn't null and node can move forward.
										 

		nodeAddress.push_back(current);    //Pushes back the vector so we can input values

		current = current->getNext();     //Updates current pointer and allows
										  //us to access data in list or preform operations 
										  //in next node

	}


	//Using a for loop to print the vector backwards acheiving our goal
	// of printing the linked list backwards. 

	for (int i = nodeAddress.size() - 1; i >= 0; i--){  //Starts us at the end!
														//and prints backward (because of i--)

		cout << nodeAddress[i]->getData() << " ";

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