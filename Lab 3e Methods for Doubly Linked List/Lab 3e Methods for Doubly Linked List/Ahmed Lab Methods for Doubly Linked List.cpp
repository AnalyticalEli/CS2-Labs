////Eli Ahmed
////Lab 3e Methods for Doubly Linked List (COMPLETED WITH TEMPLATES) 
//
////Using 3e Notes as we've done most of the work
////for the doubly Linked list, but using templates 
//
////Go to edit > Find and Replace > Quick Find  
////lets you find all and replace!
////So i.e. find all Node* -> Node<T>*
//
//
//#include <iostream> 
//#include <string>
//
//using namespace std;
//
//
//
//template<class T = string>   //A pattern noticed is USUALLY in a linked List the template<class T = string> for classes 
//class Node {     // Class that defines the node object
//private:
//    T item;    //Since we define T = string, can put T instead of string
//    Node<T>* nextPtr;
//    Node<T>* prevPtr;
//
//public:
//    //constructors
//    Node();
//    Node(T);
//    Node(T arg, Node<T>*);    //Node::Node(T arg, Node<T>* argPtr)
//
//
//    //Accessor Methods
//    void setItem(T);
//    T getItem();
//    void setNextPtr(Node<T>*);
//    Node<T>* getNextPtr();
//    void setPrevPtr(Node<T>*);
//    Node<T>* getPrevPtr();
//
//};
//// Node has a string item and a Node<T>nextPtr
//
//
//template<class T = string>
//class DoublyLinkedList {
//private:
//    Node<T>* head;  // head will have "item" and "nextPtr"
//    Node<T>* tail;   //ASK JU
//
//public:
//    DoublyLinkedList();
//    DoublyLinkedList(Node<T>* argHead);
//
//    // accessor methods
//    void setHead(Node<T>* argHead);
//    Node<T>* getHead(void);
//    void setTail(Node<T>* argTail);
//    Node<T>* getTail(void);
//
//
//    // this might be useful for doubly linked but addNode
//    void addNodeEnd(Node<T>* argPtr);
//    Node<T>* getNodeEnd(void);
//    void deleteNodeEnd(void);  //This dellocates, the end of a node
//    void delNode(T arg);
//    void delNodeFront(void); //Used when you're starting at the
//    //front (or head) of linked list.
//
//
//
//// utility methods
//    Node<T>* searchForValue(T arg);  //returns Node prior to placement of New Node
//    void addNodeFront(Node<T>* argNode);
//    void addNode(Node<T>* argNode, T arg);
//
//
//    ~DoublyLinkedList(); // destructor
//
//    /* for next class, fix our tail adding
//    * let's do a doubly linked list.
//    */
//
//};
//
////regular c-type function for printing the Linked List
//
//template<typename T = string>    //Typename is for c-type functions, Class T 
//void printStringList(Node<T>* beginningNodePtr);   //Stringlist gives us hint that template = string
//
//template<typename T = string>
//void printStringReverse(Node<T>* argPtr);   //The <T> helps C++ recognize it as a data type T = string
//
//
//
//int main(void) {
//
//    DoublyLinkedList <string> myList(new Node<string>("ab"));  //We need to input data type <>, because of template
//    myList.addNodeEnd(new Node<string>("cd"));
//    myList.addNodeEnd(new Node<string>("ef"));
//    myList.addNodeEnd(new Node<string>("gh"));
//    myList.addNodeEnd(new Node<string>("ij"));
//
//    // lines for cd through ij can be rewritten as a single line for each like the kl line below
//    myList.addNodeEnd(new Node<string>("kl"));
//    myList.addNodeFront(new Node<string>("007"));
//    myList.addNode(new Node<string>("dd"), "cd");
//    myList.addNodeEnd(new Node<string>("mn"));
//    myList.deleteNodeEnd();  //This is our function that we made to delete 
//    //the current tail (end) node.
//    myList.delNode("kl");
//
//
//    myList.addNodeEnd(new Node<string>("zz"));
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
//
//template<class T>     //Must put template in all methods, constructors, and utility methods IF using templates!
//DoublyLinkedList<T>::DoublyLinkedList() {
//    setHead(nullptr);
//    setTail(nullptr);
//}
//
//
//template<class T>    //Must put template in all methods, constructors, and utility methods IF using templates!                
//DoublyLinkedList<T>::DoublyLinkedList(Node<T>* argHead) {
//    setHead(argHead);
//    setTail(argHead);
//}
//
//
//// accessor methods
//template<class T>
//void DoublyLinkedList<T>::setHead(Node<T>* argHead) {
//    head = argHead;
//}
//
//
//template<class T>
//Node<T>* DoublyLinkedList<T>::getHead(void) {
//    return head;
//}
//
//
//template<class T>
//void DoublyLinkedList<T>::addNodeEnd(Node<T>* argPtr) {
//    Node<T>* tempPtr = getTail();
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
//
//
//template<class T>
//Node<T>* DoublyLinkedList<T>::getNodeEnd(void) {
//    // can I simplify this to "getTail".  No. getTail refers to getNodeEnd
//    // so this looping needs to be done somewhere.
//    Node<T>* tempPtr = getHead();
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
//
//template<class T>
//void DoublyLinkedList<T>::addNodeFront(Node<T>* argNode) {
//    Node<T>* temp = argNode;
//    if (getHead() != nullptr) {
//        temp->setNextPtr(getHead());  // step 1 on the paper.
//        getHead()->setPrevPtr(temp); //step 2
//    }
//    setHead(temp); //step 3
//}
//
//
//template<class T>     //TO make constructor work with template put <T>: i.e. -> ourLinkedList<T> 
//void DoublyLinkedList<T>::addNode(Node<T>* argNode, T arg) { // this can do end as well.
//
//    Node<T>* temp = getHead();
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
//
//template<class T>
//Node<T>* DoublyLinkedList<T>::searchForValue(T arg) { //returns Node prior to placement of New Node
//    Node<T>* temp = getHead();
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
//
//template<class T>
//void DoublyLinkedList<T>::setTail(Node<T>* argTail) {
//    tail = getNodeEnd();
//}
//
//
//template<class T>
//Node<T>* DoublyLinkedList<T>::getTail(void) {
//    return tail;
//}
//
//
//template<class T>
//DoublyLinkedList<T>::~DoublyLinkedList() {  //THIS IS THE DESTRUCTOR (MEANING it dellocates & frees memmory
//    // we need to delete the Nodes and the list at the end
//    Node<T>* temp = getHead();
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
//template<class T>
//void DoublyLinkedList<T>::deleteNodeEnd(void) {     //This dellocates, the tail (end) of the node
//
//    Node<T>* temp = getTail();  //This points the tail at "mn" 
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
//    //PTR (or Tail) to nullptr works
//    //Sets the next(Tail) to nullptr.
//
//
//
////(BELOW) Checking setTail as the second to last PTR works 
//
//    setTail(getTail()->getPrevPtr());
//
//
//    //(Below) Testing if deleting PTR (or previous tail) works 
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
//template<class T>
//void DoublyLinkedList<T>::delNodeFront(void) {
//
//    Node<T>* temp = getHead();
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
//template<class T>
//void DoublyLinkedList<T>::delNode(T arg) {  //On kl
//
//    Node<T>* temp = searchForValue(arg); //Searches through linked list
//    //for a specific string.
//    //Could be ab, cd, ef, etc.
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
//    temp->getPrevPtr()->setNextPtr(temp->getNextPtr());
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
//template<typename T>
//void printStringList(Node<T>* beginningNodePtr) {
//
//    Node<T>* tempNodePtr = beginningNodePtr;
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
//
//template<typename T>      //Must put this on every c-type function with template
//void printStringReverse(Node<T>* argPtr) {    //The <T> helps C++ recognize it as a data type T = string from template
//    //prototype above
//
//    Node<T>* tempNodePtr = argPtr;
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
//
//template<class T>
//Node<T>::Node()
//{
//    setItem(""); //default to empty string
//    setNextPtr(nullptr); //default to null pointer
//    setPrevPtr(nullptr); // NEW with doubly linked!
//}
//
//
//template<class T>
//Node<T>::Node(T arg, Node<T>* argPtr)
//{
//    setItem(arg);
//    setNextPtr(argPtr);
//    setPrevPtr(nullptr);
//}
//
//
//
//template<class T>
//Node<T>::Node(T arg)
//{
//    setItem(arg);
//    setNextPtr(nullptr);
//    setPrevPtr(nullptr);
//}
//
//
//
//template<class T>
//void Node<T>::setItem(T arg)
//{
//    item = arg;
//}
//
//
//template<class T>
//T Node<T>::getItem() {
//    return item;
//}
//
//
//template<class T>
//void Node<T>::setNextPtr(Node<T>* argPtr)
//{
//    nextPtr = argPtr;
//}
//
//
//template<class T>
//Node<T>* Node<T>::getNextPtr() {
//
//
//    if (this != nullptr) {  //IF this doens't get nullptr 
//
//        return nextPtr;
//    }
//    else {  //IF it is a nullptr triggered
//
//        return nullptr;
//    }
//
//
//}
//
//
//template<class T>
//void Node<T>::setPrevPtr(Node<T>* argPtr)
//{
//    prevPtr = argPtr;
//}
//
//
//template<class T>
//Node<T>* Node<T>::getPrevPtr()
//{
//
//    if (this != nullptr) {  //IF this doens't get nullptr 
//
//        return prevPtr;
//    }
//    else {  //IF it is a nullptr triggered
//
//        return nullptr;
//    }
//
//}
//
//
