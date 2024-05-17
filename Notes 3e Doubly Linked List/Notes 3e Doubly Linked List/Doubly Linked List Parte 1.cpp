//// CSCI 002 Lecture Day 09 Notes: Doubly Linked List 
//// An abstraction of an array.  (WITHOUT Size method) WORSE & Inefficient
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
//    void deleteNodeEnd(void);  //This dellocates, the end of a node
//    void delNode(string arg);
//    void delNodeFront(void); //Used when you're starting at the
//                             //front (or head) of linked list.
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
//void printStringReverse(Node* argPtr);
//
//int main(void) {
//
//    ourLinkedList myList(new Node("ab"));
//    myList.addNodeEnd(new Node("cd"));
//    myList.addNodeEnd(new Node("ef"));
//    myList.addNodeEnd(new Node("gh"));
//    myList.addNodeEnd(new Node("ij"));
//
//    // lines for cd through ij can be rewritten as a single line for each like the kl line below
//    myList.addNodeEnd(new Node("kl"));
//    myList.addNodeFront(new Node("007"));
//    myList.addNode(new Node("dd"), "cd");
//    myList.addNodeEnd(new Node("mn"));
//    myList.deleteNodeEnd();  //This is our function that we made to delete 
//                            //the current tail (end) node.
//    myList.delNode("kl");
//
//
//
//
//
//
//    myList.addNodeEnd(new Node("zz"));
//
//    cout << "Testing search function.  \"kl\" found at: " << myList.searchForValue("kl") << endl;
//
//    printStringList(myList.getHead()); // make this a method, do it in reverse
//
//    cout << endl << "&*&*&*&*&*&*&*&*&*&*&*&*&*&*&" << endl;
//
//    printStringReverse(myList.getHead());
//
//    return (0);
//}
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
//}
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
//    argNode->setPrevPtr(temp);  // line 1
//    temp->getNextPtr()->setPrevPtr(argNode); // line 2
//    argNode->setNextPtr(temp->getNextPtr()); // line 3
//    temp->setNextPtr(argNode);  // line 4
//
//    // does this end up being the tail node? if so, make it the tail.
//    if (argNode->getNextPtr() == nullptr) {
//        setTail(argNode);
//    }
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
//ourLinkedList::~ourLinkedList() {  //THIS IS THE DESTRUCTOR (MEANING it dellocates & frees memmory
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
//        delNodeFront();  //This saved one line of code.
//        temp = getHead();
//    }
//
//    // this set outside the while loop exterminates the final node
//    cout << "Deleting: " << temp->getItem() << endl;  //delete this crap first!
//    delete temp;  //this clears the memory 
//    temp = nullptr; //sets temp to null in case it's ised again.
//    setHead(nullptr);
//
//    cout << "Linked List is empty." << endl;
//}
//
//
//
//void ourLinkedList::deleteNodeEnd(void) {     //This dellocates, the tail (end) of the node
//
//    Node* temp = getTail();  //This points the tail at "mn" 
//
//    //Node* temp2 = getTail()->getPrevPtr(); //It gets the node right
//                                            //before the last (tail) 
//                                            //and sets it as temp2
//                                            // us to right before tail.
//
//
//   //Checking if setting last PTR (or Tail) to nullptr works
//
//    getTail()->getPrevPtr()->setNextPtr(nullptr); //Checking if setting last
//                                                //PTR (or Tail) to nullptr works
//                                                //Sets the next(Tail) to nullptr.
//
//
//
//     //(BELOW) Checking setTail as the second to last PTR works 
//
//    setTail(getTail()->getPrevPtr());   
//
//
//  //(Below) Testing if deleting PTR (or previous tail) works 
//
//    delete temp;  //Gets rid of mn
//
//    temp = nullptr; //Sets temp equal to a nullptr (meaning empty)
//
//
//
//}
//
//
//void ourLinkedList::delNodeFront(void) {
//
//    Node* temp = getHead();
//
//
//    temp->getNextPtr()->setPrevPtr(nullptr); //Sets the previous node
//    // to nullptr.
//
//
//    setHead(getTail()->getNextPtr());
//
//    delete temp;
//
//
//    temp = nullptr;
//
//}
//
//
//
//
//
//void ourLinkedList::delNode(string arg) {  //On kl
//
//    Node* temp = searchForValue(arg); //Searches through linked list
//                                      //for a specific string.
//                                      //Could be ab, cd, ef, etc.
//
//    if (temp == getTail()) { //Meaining it's already at end
//
//        deleteNodeEnd();
//        return;
//
//    }
//
//    if (temp == head) { //Meaning temp is at the beginning (head)
//
//        delNodeFront();
//
//        return;
//
//
//    }
//
//
//    temp->getPrevPtr()->setNextPtr(temp->getNextPtr() );
//
//    //What's happening above is: Temp ptr, points to previous ptr.
//    //Which ptrs to the next Ptr, which shifts to the
//
//
//    temp->getNextPtr()->setPrevPtr(temp->getPrevPtr());
//
//    //This shifts the linked list to the previous ptr.
//    //
//
//
//    //temp->setNextPtr(nullptr);  //Sets the next Ptr to nullptr (Unecessary) 
//    //temp->setPrevPtr(nullptr);  //Sets the previous as nullptr. (Unecessary)
//
//    delete temp;  //deletes temp
//
//    temp = nullptr;  //Dellocates memory as nullptr.
//
//
//
//
//}
//   
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
//void printStringReverse(Node* argPtr) {
//
//    Node* tempNodePtr = argPtr;
//
//    cout << "******************" << endl;
//    if (tempNodePtr == nullptr) {
//        cout << "List Empty" << endl;
//    }
//    else {
//        while (tempNodePtr->getNextPtr() != nullptr) {
//            // this while loop will stop at the last node.
//            //cout << tempNodePtr->getItem() << endl; // this line prints out each one forward
//            tempNodePtr = tempNodePtr->getNextPtr();
//
//        }; // after we have jumped to the final node
//
//
//        while (tempNodePtr->getPrevPtr() != nullptr) {
//            cout << tempNodePtr->getItem() << endl;
//            tempNodePtr = tempNodePtr->getPrevPtr();
//        }
//        // that while loop should take us to the head, but it doesn't print it.
//        cout << tempNodePtr->getItem() << endl; // this prints the head.
//
//    }
//    cout << "******************" << endl;
//
//}
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