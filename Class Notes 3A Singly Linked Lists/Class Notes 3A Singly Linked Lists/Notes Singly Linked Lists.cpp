//// Class Notes: Singly Linked List 
//// An abstraction of an array.
////02/12/24
//
//#include <iostream> 
//#include <string>
//using namespace std;
//
//// Class that defines the node object
//class Node {
//private:
//	string item;
//	Node* nextPtr;
//
//public:
//	//constructors
//	Node();
//	Node(string);
//	Node(string, Node*);
//
//	//Accessor Methods
//	void setItem(string);
//	string getItem();
//	void setNextPtr(Node*);
//	Node* getNextPtr();
//
//};
////Node has a string item and a Node* nextPtr
//
//
////This class is our Linked List 
//
//class ourLinkedList {
//
//private:
//
//	Node* head;  //Head will have "item" and "nextPtr"
//
//public:
//
//	//Constructors
//
//	ourLinkedList();
//
//	ourLinkedList(Node* argHead);
//
//
//
//	//Accessor Methods
//
//	void setHead(Node* argHead);
//
//	void getHead(void);
//
//	//Destructor
//
//};
//
//
//
//
////regular c-type function for printing the Linked List
//void printStringList(Node* beginningNodePtr);
//
//int main(void) {
//
//	// 1. Note the difference between a pointer and Node Object
//	Node* headPtr = nullptr;        //Always set node* ptr = to nullptr.
//	Node myNode; //compile time instance
//
//	Node* curNodePtr = nullptr; //temp curNodePtr is often called the iterator
//
//	// 2. Hard code a singly linked list with the head pointer above.
//
//	// Populate the first node dynamically (at run-time)
//	curNodePtr = new Node("Mary");
//	headPtr = curNodePtr;
//
//	//populate the second node
//	curNodePtr->setNextPtr(new Node("Bill"));
//	curNodePtr = curNodePtr->getNextPtr();
//
//	//populate the third node
//	curNodePtr->setNextPtr(new Node("James"));
//	curNodePtr = curNodePtr->getNextPtr();
//
//	//populate the fourth node
//	curNodePtr->setNextPtr(new Node("Aubrey"));
//	curNodePtr = curNodePtr->getNextPtr();
//
//	printStringList(headPtr);
//
//	// 3. Memory Management (Clean-up when done from front)    
//	curNodePtr = headPtr;    //Takes current node and points it at the head (lead) ptr (Mary)
//	headPtr = headPtr->getNextPtr();
//	delete curNodePtr;		 //Deletes the head/beginning/lead pointer.  (Mary) 
//
//	curNodePtr = headPtr;     //Exact same process, now that the first lead is gone it goes to second for lead
//	headPtr = headPtr->getNextPtr();
//	delete curNodePtr;		 //Deletes second (Bill) as lead 
//
//	curNodePtr = headPtr;     //Exact same process, now that the second lead is gone it goes to third for lead
//	headPtr = headPtr->getNextPtr();
//	delete curNodePtr;        //Deletes second (James) as lead 
//
//	curNodePtr = headPtr;    //Exact same process, now that the third lead is gone it goes to fourth for lead
//	headPtr = headPtr->getNextPtr();
//	delete curNodePtr;      //Deletes second (Aubruey) as lead 
//
//	curNodePtr = headPtr; //both should be nullptr at the end
//
//	printStringList(headPtr);
//
//	return (0);
//}
//
//
//
//
//
////Constructors for Linked List
//
//ourLinkedList::ourLinkedList() {
//
//	setHead = 
//
//}
//
//ourLinkedList::ourLinkedList(Node* argHead) {
//
//	setHead()
//
//}
//
//
//
////Accessor Methods for Linked List
//
//void ourLinkedList::setHead(Node* argHead) {
//
//	head = argHead;    //Gets head info from private 
//
//}
//
//Node* ourLinkedList::getHead(void) {
//
//	return head;
//
//}
//
////Destructor
//
//
//
//
//void printStringList(Node* beginningNodePtr) {
//
//	Node* tempNodePtr = beginningNodePtr;
//
//	cout << "******************" << endl;
//	if (tempNodePtr == nullptr) {        //This is just checking and making sure nullptr is empty
//		cout << "List Empty" << endl;
//	}
//	else {					//If it's not (else) then it prints out the node before last that's not empty
//		while (tempNodePtr->getNextPtr() != nullptr) {   
//
//			cout << tempNodePtr->getItem() << endl;  
//			tempNodePtr = tempNodePtr->getNextPtr();
//
//		};     
//
//		//This line below takes care of final gap and prints final item
//		cout << tempNodePtr->getItem() << endl;
//
//	}
//	cout << "******************" << endl;
//
//}
//
//
////Node Implementation
//Node::Node()
//{
//	setItem(""); //default to empty string
//	setNextPtr(nullptr); //default to null pointer
//}
//
//Node::Node(string arg)
//{
//	setItem(arg);
//	setNextPtr(nullptr);
//}
//
//Node::Node(string arg, Node* argPtr)
//{
//	setItem(arg);
//	setNextPtr(argPtr);
//}
//
//void Node::setItem(string arg)
//{
//	item = arg;
//}
//
//string Node::getItem()
//{
//	return item;
//}
//
//void Node::setNextPtr(Node* argPtr)
//{
//	nextPtr = argPtr;
//}
//
//Node* Node::getNextPtr()
//{
//	return nextPtr;
//}