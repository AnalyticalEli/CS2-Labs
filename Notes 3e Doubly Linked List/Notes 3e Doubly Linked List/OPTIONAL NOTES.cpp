//// CSCI 002 Doubly Linked List 
//// An abstraction of an array.  
//// 02/21/2024
//
//#include <iostream> 
//#include <string>
//using namespace std;
//
//// Class that defines the node object
//class Node {
//private:
//    string item;
//    Node* nextPtr;
//    Node* prevPtr;
//
//public:
//    //constructors
//    Node();
//    Node(string);
//    Node(string, Node*);
//
//    //Accessor Methods
//    void setItem(string);
//    string getItem();
//    void setNextPtr(Node*);
//    Node* getNextPtr();
//    void setPrevPtr(Node*);
//    Node* getPrevPtr();
//
//};
//// Node has a string item and a Node* nextPtr
//
//class ourLinkedList {
//private:
//    Node* head;  // head will have "item" and "nextPtr"
//    Node* tail;
//
//public:
//    ourLinkedList();
//    ourLinkedList(Node* argHead);
//
//    // accessor methods
//    void setHead(Node* argHead);
//    Node* getHead(void);
//    void setTail(Node* argTail);
//    Node* getTail(void);
//
//
//    // this might be useful for doubly linked but addNode
//    void addNodeEnd(Node* argPtr);
//    Node* getNodeEnd(void);
//
//
//    // utility methods
//    Node* searchForValue(string arg);  //returns Node prior to placement of New Node
//    void addNodeFront(Node* argNode);
//    void addNode(Node* argNode, string arg);
//
//
//    ~ourLinkedList(); // destructor
//
//    /* for next class, fix our tail adding
//    * let's do a doubly linked list.
//    */
//
//};
//
////regular c-type function for printing the Linked List
//void printStringList(Node* beginningNodePtr);
//
//void printStringReverse(Node* beginningNodePtr);   //Prototype for the reverse printing.
//
//int main(void) {
//
//    // 1. Note the difference between a pointer and Node Object
//    Node* headPtr = nullptr; // run time
//    Node myNode; //compile time instance
//
//    Node* curNodePtr = nullptr; //temp curNodePtr is often called the iterator
//
//    Node* examplePtr = examplePtr;
//
//    // 2. If you want to see the hard coded part, see the pre-existing lecture notes.
//    // we're switching to a class
//    //printStringList(headPtr);
//
//    // 3. Memory Management (Clean-up when done from front)
//   // headPtr = new Node("ab");
//    ourLinkedList myList(new Node("ab"));
//
// 
//    myList.addNodeEnd(new Node("cd"));
//  
//
//    myList.addNodeEnd(new Node("ef"));
//
//    myList.addNodeEnd(new Node("gh"));
//
//    myList.addNodeEnd(new Node("ij"));
//
//
//    // lines for cd through ij can be rewritten as a single line for each like the kl line below
//    myList.addNodeEnd(new Node("kl"));
//    myList.addNodeFront(new Node("007"));
//    myList.addNode(new Node("dd"), "cd");
//    myList.addNodeEnd(new Node("mn"));
//
//
//
//
//
//    cout << "Testing search function.  \"kl\" found at: " << myList.searchForValue("kl") << endl;
//
//    //curNodePtr = headPtr; //both should be nullptr at the end
//
//    printStringList(myList.getHead()); // make this a method, do it in reverse
//
//
//    cout << endl << "&*&*&*&*&*&*&*&*&*&*&*&*&*" << endl;
//
//
//
//    printStringReverse(myList.getHead());
//
//
//    return (0);
//}
//
//
//
//
//
//
////   IMPLEMENTATIONS FOR OUR LINKED LIST
//ourLinkedList::ourLinkedList() {
//    setHead(nullptr);
//    setTail(nullptr);
//}
//ourLinkedList::ourLinkedList(Node* argHead) {
//    setHead(argHead);
//    setTail(argHead);
//}
//
//// accessor methods
//void ourLinkedList::setHead(Node* argHead) {
//    head = argHead;
//}
//Node* ourLinkedList::getHead(void) {
//    return head;
//}
//
//
//
//
//
//
//
//void ourLinkedList::addNodeEnd(Node* argPtr) {
//    Node* tempPtr = getTail();
//
//    if (tempPtr == nullptr) { // this accomodates empty lists
//        cout << "This starts a new list!" << endl;
//        setHead(argPtr);
//        return; // this breaks out if the list was empty so it does
//        // not try to add the node twice
//    }
//
//    //// then we need to cycle through a long list to get to the end
//    //while (tempPtr->getNextPtr() != nullptr) {
//    //    tempPtr = tempPtr->getNextPtr();
//    //}  // we don't need this and we save processing time by not having
//    // to search for the end
//
//
//
//
//    tempPtr->setNextPtr(argPtr);  // this changes cd's next to ef
//    argPtr->setPrevPtr(tempPtr);
//    setTail(argPtr); // this one makes ef the tail
//}
//
//Node* ourLinkedList::getNodeEnd(void) {
//    // can I simplify this to "getTail".  No. getTail refers to getNodeEnd
//    // so this looping needs to be done somewhere.
//    Node* tempPtr = getHead();
//
//    if (tempPtr == nullptr) { // this accomodates empty lists
//        return tempPtr;  // 
//    }
//
//    // then we need to cycle through a long list to get to the end
//    while (tempPtr->getNextPtr() != nullptr) {
//        tempPtr = tempPtr->getNextPtr();
//    }
//
//    return tempPtr;
//
//
//}
//
//
//
//
//void ourLinkedList::addNodeFront(Node* argNode) {
//    Node* temp = argNode;
//    if (getHead() != nullptr) {
//        temp->setNextPtr(getHead());  // step 1 on the paper.
//        getHead()->setPrevPtr(temp); //step 2
//    }
//    setHead(temp); //step 3
//}
//
//
//// so far, this works on middle and end.  now we need it to work on front.
//void ourLinkedList::addNode(Node* argNode, string arg) { // this can do end as well.
//    Node* temp = getHead();
//
//    if (temp == nullptr) {
//
//        cout << "List doesn't exist, starting new list." << endl;
//        setHead(argNode);
//        return;
//    }
//
//    // step 1 on paper
//    temp = searchForValue(arg); // this should return a ptr
//
//    argNode->setPrevPtr(temp);  // line 1  (Points to Cd)
//    temp->getNextPtr()->setPrevPtr(argNode); // line 2 (This points to dd from Ef.)
//
//    argNode->setNextPtr(temp->getNextPtr()); // line 3  (goes from cd back to dd) 
//    temp->setNextPtr(argNode);  // line 4   (goes from dd back to ef) 
//
//    // does this end up being the tail node? if so, make it the tail.
//    if (argNode->getNextPtr() == nullptr) {
//        setTail(argNode);
//    }
//
//}
//
//Node* ourLinkedList::searchForValue(string arg) { //returns Node prior to placement of New Node
//    Node* temp = getHead();
//
//    if (temp == nullptr) {  // empty List case
//        cout << "No value found.  Returning nullptr." << endl;
//        return nullptr;
//    }
//
//    while (temp->getNextPtr() != nullptr) {
//        if (temp->getItem() == arg) {
//            return temp;
//        }
//        else temp = temp->getNextPtr();
//    }
//
//    if (temp->getItem() == arg) { // this covers the last Node
//        return temp;
//    }
//    else {
//        cout << "Value not found." << endl;
//        return nullptr;
//    }
//}
//
//void ourLinkedList::setTail(Node* argTail) {
//    tail = getNodeEnd();
//}
//Node* ourLinkedList::getTail(void) {
//    return tail;
//}
//
//ourLinkedList::~ourLinkedList() {
//    // we need to delete the Nodes and the list at the end
//    Node* temp = getHead();
//    //Node* currPtr = temp;
//
//    if (temp == nullptr) {
//        cout << "There's no list to delete, scrub" << endl;
//        return;
//    }
//
//    while (temp->getNextPtr() != nullptr) {
//        setHead(temp->getNextPtr());
//        cout << "Deleting: " << temp->getItem() << endl;
//        delete temp;
//        temp = getHead();
//    }
//
//    // this set outside the while loop exterminates the final node
//    cout << "Deleting: " << temp->getItem() << endl;
//    delete temp;
//    temp = nullptr;
//    setHead(nullptr);
//
//    cout << "Linked List is empty." << endl;
//}
//
//void printStringList(Node* beginningNodePtr) {
//
//    Node* tempNodePtr = beginningNodePtr;
//
//    cout << "******************" << endl;
//    if (tempNodePtr == nullptr) {
//        cout << "List Empty" << endl;
//    }
//    else {
//        while (tempNodePtr->getNextPtr() != nullptr) {
//            // this while loop will stop at the last node.
//            cout << tempNodePtr->getItem() << endl; // this line prints out each one
//            tempNodePtr = tempNodePtr->getNextPtr();
//
//        }; // after we have jumped to the final node, this doesn't print it.
//
//        // this line takes care of the gap and prints the final item.
//        cout << tempNodePtr->getItem() << endl;
//
//    }
//    cout << "******************" << endl;
//
//}
//
//void printStringReverse(Node* beginningNodePtr) {
//
//    Node* tempNodePtr = beginningNodePtr;
//
//    cout << "******************" << endl;
//    if (tempNodePtr == nullptr) {
//        cout << "List Empty" << endl;
//    }
//    else {
//        while (tempNodePtr->getNextPtr() != nullptr) {
//            // this while loop will stop at the last node.
//
//
//           // cout << tempNodePtr->getItem() << endl; // this line prints out each oen forward 
//            tempNodePtr = tempNodePtr->getNextPtr();
//
//        }; // after we have jumped to the final node, this doesn't print it.
//
//        // this line takes care of the gap and prints the final item.
//        cout << tempNodePtr->getItem() << endl;
//
//
//        while (tempNodePtr ->getPrevPtr() != nullptr) {
//
//            cout << tempNodePtr->getItem() << endl;    
//            tempNodePtr = tempNodePtr->getPrevPtr();   //Reverese prints the code to make sure it works even with problems.
//
//
//        }
//
//
//
//
//    }
//    cout << "******************" << endl;
//
//}
//
//
//
//
//
//
//
//
////Node Implementation
//Node::Node()
//{
//    setItem(""); //default to empty string
//    setNextPtr(nullptr); //default to null pointer
//    setPrevPtr(nullptr); // NEW with doubly linked!
//}
//
//Node::Node(string arg)
//{
//    setItem(arg);
//    setNextPtr(nullptr);
//    setPrevPtr(nullptr);
//}
//
//Node::Node(string arg, Node* argPtr)
//{
//    setItem(arg);
//    setNextPtr(argPtr);
//    setPrevPtr(nullptr);
//}
//
//void Node::setItem(string arg)
//{
//    item = arg;
//}
//
//string Node::getItem()
//{
//    return item;
//}
//
//void Node::setPrevPtr(Node* argPtr)
//{
//    prevPtr = argPtr;
//}
//
//Node* Node::getPrevPtr()
//{
//    return prevPtr;
//}
//
//void Node::setNextPtr(Node* argPtr)
//{
//    nextPtr = argPtr;
//}
//
//Node* Node::getNextPtr()
//{
//    return nextPtr;
//}
