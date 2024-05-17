//Eli Ahmed
//Lab 3c Singly Linked List  (Using Lab 3b with Accumulator!)


#include<iostream>
#include<string>
#include<vector>  //For the vector in PrintBackwards 


using namespace std;


//Template Prototype:


template<class T = string>   //Allows to apply template to class Node ;)  (Must define as data type as well T = int, or T = string, etc.) 
class Node {

private:

	T data;   //If you get error for string here it's a glitch 
			  //Data has ORIGINAL DATA type of STRING 

	Node<T>* nextPtr;


public:


	//Constructor Prototype 

	Node(T value);    //T was ORIGINALLY String


	//Accessor Methods

	void setData(const T& value);  //Set Method for the adress of string 

	T getData(void);   //Get Method for Data


	void setNext(Node* nextNode);  //Set Method for the adress of string 

	Node* getNext(void);   //Get Method for Data



};




//C-type Function For Single Linked List Prototypes

template<typename T = string>   //You must instatiate a template<typename T = [DESIRED DATA TYPE] for each C-type Function
void printForward(Node<T>* head);   //Using node head pointer to print forward  (Within each <>, you must put the data type you want) 


template<typename T = string>   //You must instatiate a template<typename T = [DESIRED DATA TYPE] for each C-type Function
void printBackwards(Node<T>* head);  //Using node head pointer to print backward


template<typename T = string>   //You must instatiate a template<typename T = [DESIRED DATA TYPE] for each C-type Function
int countElements(Node<T>* head); //This accumulator counts all of the elements
								 //in the linked list

template<typename T = string>   //You must instatiate a template<typename T = [DESIRED DATA TYPE] for each C-type Function
void deallocateList(Node<T>* head); //Deallocates memory in each node to
//free up space taken by linked list.



int main(void) {

	//Ensuring linked list is empty (GOOD PRACTICE) 

	Node<string>* head = nullptr;  //Initializes empty linked list before adding nodes

	Node<string>* tail = nullptr;  //Initializes empty linked list before adding nodes



	//Setting getline for user input, and do while loop char response

	string userInput;
	char userResponse;


	//Do while loop for singly linked list

	do {

		cout << "Enter a phrase or value for node: ";
		cin >> userInput;	 //For strings getline & string libr

		//cin.ignore();

		Node<string>* newNode = new Node<string>(userInput); //Initiating new Node
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



template<class T>   //The <T> transfers over. Also must put template
					//class on each fucntion & constructor!

Node<T>::Node(T value) {  //T was originally string data type.

	setData(value);   //Indirect access of setData


	setNext(nullptr);  //Automatically sets the next one to nullptr,
	//meaning the next is the last in linked list
   //which ensures that the node doesn't point to any 
  //other node in the beginning. This is helpful because
 //in the linked list due to this this Ptr, will update
//to point to the next node in the sequence.


}



//Accessor Methods for Data (set and get methods)


template<class T>
void Node<T>::setData(const T& value) { //Set Method for the adress of string 

	data = value;     //Accessing the data indirectly.

}



template<class T>
T Node<T>::getData(void) {   //Get Method for Data

	return data;  //Return data we indirectly accessing.

}



template<class T>
void Node<T>::setNext(Node* nextNode) {  //Set Method for getting the Next Ptr

	nextPtr = nextNode;   //Indirectly access nextPtr by setting 
	//equal to nextNode 


}


template<class T>
Node<T>* Node<T>::getNext(void) {  //Get Method for getting the Next Ptr

	return nextPtr;

}



//C-type Function For Single Linked List Implementation


template<class T>
void printForward(Node<T>* head) {   //Using node head pointer to print forward 


	while (head) {

		cout << head->getData() << " ";  //Head pointer goes to get data

		head = head->getNext();   //Afterward, sets the new head to get
		//the next head.
	}


}



template<class T>
void printBackwards(Node<T>* head) {

	vector<Node<T>*> nodeAddress;  //Creating vector NodeAddress.

	Node<T>* current = head;  //While the node pointer is at current head

	while (current) {  //This ensures that current isn't null and node can move forward.


		nodeAddress.push_back(current);    //Pushes back the vector so we can input values

		current = current->getNext();     //Updates current pointer and allows
		//us to access data in list or preform operations 
		//in next node

	}


	//Using a for loop to print the vector backwards acheiving our goal
	// of printing the linked list backwards. 

	for (int i = nodeAddress.size() - 1; i >= 0; i--) {  //Starts us at the end!
		//and prints backward (because of i--)

		cout << nodeAddress[i]->getData() << " ";

	}


}


template<class T>
int countElements(Node<T>* head) { //This accumulator counts all of the elements
	//in the linked list.

	int count = 0; //Initiliazing accumulator


	while (head) { //While head != nullptr

		count++;  //Counts each consecutive element. (Node is element in this case)

		head = head->getNext(); //Gets next element once it's counted


	}


	return count;  //Returns the count number after running.
}



template<typename T>
void deallocateList(Node<T>* head) { //Deallocates memory in each node to
	//free up space taken by linked list.

	Node<T>* temp; //Node is temp (or temporary placeholder)

	while (head) { //While the next isn't a nullptr

		temp = head;  //While node pointer is head

		head = head->getNext(); //It consectively gets the next if not empty

		delete temp; //Deletes aka dellocates memory to free up space.

	}




}