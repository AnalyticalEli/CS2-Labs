//Eli Ahmed
//Lab 3F Hard Code List of Circles 

#include <iostream> 
#include <string>

using namespace std;


class Shape {


private:

    string color;


public: 

    Shape(string = "");  //Setting it empty for user input 

    virtual double calculateArea(void) = 0;
    virtual double calculatePerimeter(void) = 0;

    //What the equal zero does forces any class that inherents from this 
    //to implement methods with these names. Essentially forces you TO USE THIS FOR ALL, 
    //taking it off removes the restriction 


    // virtual methods
    //virtual says later classes can use these names. (THIS ALLOWS US TO REUSE FORMULAS!)
    virtual double calculateVolume(void);


};
             
class Circle: public Shape {   //Apprarently you can make templates with classes 

private: 

    double r


public:

    Circle();


    virtual double calculation = 0; //The = 0 forces you TO USE THIS FOR ALL, taking it off removes the restriction 


};

template<class T = Shape>   //A pattern noticed is USUALLY in a linked List the template<class T = string> for classes 
class Node {     // Class that defines the node object
private:


    T item;    //Since we define T = string, can put T instead of string
    Node<T>* nextPtr;
    Node<T>* prevPtr;

public:
    //constructors
    Node(T newData);
    //Node(T);
    //Node(T arg, Node<T>*);    //Node::Node(T arg, Node<T>* argPtr)


    //Accessor Methods
    void setItem(T setItem);
    T getItem(void);
    void setNextPtr(Node<T>* setNext);
    Node<T>* getNextPtr(void);
    void setPrevPtr(Node<T>* getPrevious);
    Node<T>* getPrevPtr(void);

};
// Node has a string item and a Node<T>nextPtr


template<class T = Shape>
class DoublyLinkedList {
private:
    Node<T>* head;  // head will have "item" and "nextPtr"
    Node<T>* tail;   //ASK JU

public:
    DoublyLinkedList();      //Default Constructor of Doubly Linked List
    DoublyLinkedList(Node<T>* argHead);

    // accessor methods
    void setHead(Node<T>* argHead);
    Node<T>* getHead(void);
    void setTail(Node<T>* argTail);
    Node<T>* getTail(void);


    // Utility Methods 

    Node<T>* lastNode(void);   //Returns a pointer to the last node
    void addNodeEnd(Node<T>* argPtr);  //Adds new nodes to the end of doubly Linked List
    void deleteNodeEnd(void);  //This dellocates, the end of a node
    void deleteNodeMid(T nameToDel);  //Deletes node of specific value, by using a target method
    void addNodeFront(Node<T>* argNode);  //Adds data at the front of the list void deallocateAll(void); 
    void deallocateAll(void);     //Deallocates memory that was taken up by Nodes, and frees up space
    int size(void);  //Returns size of the list. Using accumulator

    Node<T>* searchForValue(T arg);   //returns Node prior to placement of New Node

    void addNodeMid(Node<T>* argPtr, T argStr);   //gets argPtr, and str


    //Deconstructor
    ~DoublyLinkedList(); // destructor


};

//regular c-type function for printing the Linked List

template<typename T = string>    //Typename is for c-type functions, Class T 
void printStringList(Node<T>* beginningNodePtr);   //Stringlist gives us hint that template = string

template<typename T = string>
void printStringReverse(Node<T>* argPtr);   //The <T> helps C++ recognize it as a data type T = string



int main(void) {

    DoublyLinkedList <string> myList(new Node<string>("ab"));  //We need to input data type <>, because of template
    myList.addNodeEnd(new Node<string>("cd"));
    myList.addNodeEnd(new Node<string>("ef"));
    myList.addNodeEnd(new Node<string>("gh"));
    myList.addNodeEnd(new Node<string>("ij"));

    // lines for cd through ij can be rewritten as a single line for each like the kl line below
    myList.addNodeEnd(new Node<string>("kl"));
    myList.addNodeFront(new Node<string>("007"));
    //myList.addNode(new Node<string>("dd"), "cd");
    myList.addNodeEnd(new Node<string>("mn"));
    myList.deleteNodeEnd();  //This is our function that we made to delete 
    //the current tail (end) node.
    //myList.delNode("kl");


    myList.addNodeEnd(new Node<string>("zz"));

    cout << "Testing search function.  \"kl\" found at: " << myList.searchForValue("kl") << endl;

    printStringList(myList.getHead()); // make this a method, do it in reverse

    cout << endl << "&*&*&*&*&*&*&*&*&*&*&*&*&*&*&" << endl;

    printStringReverse(myList.getHead());

    return (0);
}




//   IMPLEMENTATIONS FOR OUR LINKED LIST


//Constructors for Node and Doubly Linked List

template<class T>     //Must put template in all methods, constructors, and utility methods IF using templates!
Node<T>::Node(T newData) {

    setData(newData);
    setHead(nullptr);  //Ensures head is empty
    setTail(nullptr);  //Ensures tail is empty.
}


template<class T>  //This is to ensure both setHead and setTail are empty (aka null)
DoublyLinkedList<T>::DoublyLinkedList() {  //Default Constructor of Doubly Linked List

    setHead(nullptr);  //Ensuring both head 
    setTail(nullptr);   //And tail are empty before we start.


}


template<class T>    //must put template in all methods, constructors, and utility methods if using templates!                
DoublyLinkedList<T>::DoublyLinkedList(Node<T>* argHead) {  //This is putting in the values we have for accessor methods

    setHead(argHead);  //Indirect Access 
    setTail(argHead);  //Indirect Access  <--- FIX THIS 


}



//Accessor Methods for Node and Doubly Linked Lists

template<class T>
void Node<T>::setItem(T setItem) {

    item = setItem;


}

template<class T>
T Node<T>::getItem(void) {

    return item;
}


template<class T>
void Node<T>::setNextPtr(Node<T>* setNext) {

    
    nextPtr = setNext;
}


template<class T>
Node<T>* Node<T>::getNextPtr(void) {

    return setNextPtr;
}


template<class T>
void Node<T>::setPrevPtr(Node<T>* setPrevious) {

    setPrevPtr = setPrevious;

}


template<class T>
Node<T>* Node<T>::getPrevPtr(void) {

    return setPrevPtr;
}



//Accessor Methods for Doubly Linked Lists

template<class T>
void DoublyLinkedList<T>::setHead(Node<T>* argHead) {  //Set Method for head 

    head = argHead;

}



template<class T>
Node<T>* DoublyLinkedList<T>::getHead(void) {  //Get method for head

    return head;

}



template<class T>
void DoublyLinkedList<T>::setTail(Node<T>* argTail) {  //Set method for tail

    tail = ;
}


template<class T>
Node<T>* DoublyLinkedList<T>::getTail(void) {  //Get Method for tail

    return tail;

}


//Utility Methods For Doubly Linked List

template<class T>
Node<T>* DoublyLinkedList<T>::lastNode(void) {

    if (tail == nullptr) {  //If ail is nullptr (empty), there are no nodes in linked list

        return nullptr;  //Meaning a return of nullptr means its empty.

    }

    else {  //If it returns tail that means linked list is not empty

        return tail;  
    }
}


template<class T>
void DoublyLinkedList<T>::addNodeEnd(Node<T>* argPtr) {
    Node<T>* tempPtr = getTail();

    if (tempPtr == nullptr) { // this accomodates empty lists
        cout << "This starts a new list!" << endl;
        setHead(argPtr);
        return;     // this breaks out if the list was empty so it does
                    // not try to add the node twice
    }

    //// then we need to cycle through a long list to get to the end
    //while (tempPtr->getNextPtr() != nullptr) {
    //    tempPtr = tempPtr->getNextPtr();
    //}  // we don't need this and we save processing time by not having
    // to search for the end


    tempPtr->setNextPtr(argPtr);  // this changes cd's next to ef
    argPtr->setPrevPtr(tempPtr);
    setTail(argPtr); // this one makes ef the tail
}




template<class T>
void DoublyLinkedList<T>::deleteNodeEnd(void) {     //This dellocates, the tail (end) of the node

    //This if statement checks and ensures that our Linked List is NOT EMPTY

    if (tail == nullptr) {  //If tail is nullptr(empty), meaning list has NO nodes (empty

        cout << "This list is empty! CANNOT delete node. " << endl;

        return;

    }


    //If it goes skips above that means it's NOT nullptr (empty) and does have 
    //NODES to be DELETED:
    
    
    Node<T>* temp = getTail();  //This points the tail at "mn" 

    //Node* temp2 = getTail()->getPrevPtr(); //It gets the node right
                                            //before the last (tail) 
                                            //and sets it as temp2
                                            // us to right before tail.


   //Checking if setting last PTR (or Tail) to nullptr works

    getTail()->getPrevPtr()->setNextPtr(nullptr); //Checking if setting last
    //PTR (or Tail) to nullptr works
    //Sets the next(Tail) to nullptr.



//(BELOW) Checking setTail as the second to last PTR works 

    setTail(getTail()->getPrevPtr());


    //(Below) Testing if deleting PTR (or previous tail) works 

    delete temp;  //Gets rid of mn

    temp = nullptr; //Sets temp equal to a nullptr (meaning empty)

}



//DELNODEMID(T nameToDel); BELONGS HERE

template<class T>
void DoublyLinkedList<T>::deleteNodeMid(T nameToDel) { //This one is a doozy, (MOST COMPLEX)
    
    Node<T>* temp = head;  //Setting Node* equal to head (Initilizing)

    while (temp != nullptr) {  //Loops through list until it reaches a nullptr (AT THE END)
                               //Because it's starting from head.

        if (temp->getItem() == nameToDel) {  //Meaning if within the list items = our target

            if (temp == head) {  //If target is the head node
                head = temp->getNextPtr();  //Update the head to point of next node

                if (head != nullptr) {

                    head
                }

            }
            
            else if (temp == tail) {  //Target node is the tail

                tail = temp->getPrevPtr(); //Update the tail to point to previous node 
                                           //This is so we can delete the nextPtr later

                if (tail != nullptr) { //If the list is not empty (IMPORTANT TO CHECK)

                    tail->setNextPtr(nullptr)  //Sets next Node (one that is tail (end)) 
                                               //To a nullptr.
                }
                else { //Only triggers when the node being deleted is both the head and tail node
                       //aka if the LIST ONLY HAS ONE NODE

                    head = nullptr;  //If the tail is a nullptr and the list only has one
                                    //value then the head should only one value as well.

                    }
            }
            else {   //If the target is NEITHER the head or tail


                //This bypasses forward the target node sequaentially, by linking the previous node
                // BEFORE target node and next node AFTER target node together, 
                // skipping the target node altogether "LINKING it out of the list"
                temp->getPrevPtr()->setNextPtr(temp->getNextPtr());  //Links forwards 


                //This does the same thing but IN REVERSE, setting the previous PTR of the
                //node AFTER the target to conenct to the NODE BEFORE TARGET.
                temp->getNextPtr()->setPrevPtr(temp->getPrevPtr());  //Links backwards to previous

            }

            delete temp;  //Deletes Target node in all cases

            return;  //Exits functiom

        }

        temp = temp->getNextPtr(); //Moves to next Node After Target.
    }

    cout << "BOOM Node with Name/data: " << nameToDel << "not found! " << endl; //Prints message target not found

}



template<class T>
void DoublyLinkedList<T>::addNodeFront(Node<T>* argNode) {   //Needed
    Node<T>* temp = argNode;
    if (getHead() != nullptr) {
        temp->setNextPtr(getHead());  // step 1 on the paper.
        getHead()->setPrevPtr(temp); //step 2
    }

    temp->setPrevPtr(nullptr);   //Sets new node to nillptr, bfore updating head.
    setHead(temp); 
}


template<class T>
void DoublyLinkedList<T>::addNodeFront(Node<T>* argNode) {   //Needed
    Node<T>* temp = argNode;
    if (getHead() != nullptr) {
        temp->setNextPtr(getHead());  // step 1 on the paper.
        getHead()->setPrevPtr(temp); //step 2
    }
    setHead(temp); //step 3
}


template<class T>
void DoublyLinkedList<T>::deallocateAll(void) {   //This deallocates and frees up memory taken up node 

    Node<T>* temp = head;  //Intilizes temporary ptr to head of list

    while (temp != nullptr) {  //Loops through list until it reaches the end (AKA a nullptr)

        delete temp;  //Deletes current node 

        temp = next;   //Sets and moves to next  

        //And because this is loop that contuines until it reaches tail (nullptr), it
        //sequentially deletes all of the values for us. 

    }

    head = nullptr;

}


template<class T>
int DoublyLinkedList<T>::size(void) {

    int count = 0;  //Initializing counter/accumulator


    Node<T>* temp = head;  //Starting at the front (head) of the list
                           //Setting the start of the list as a temporrary value

    while (temp != nullptr) {  //Cycles through list until it reaches end

        count++; //Counts every node that isn't empty

        temp = temp->getNextPtr(); //Moves to next after counting it.

    }

    //After the while loop hits a nullptr (end) it will stop and
    //Returns Number of Nodes.

    return count;

}



template<class T>
Node<T>* DoublyLinkedList<T>::searchForValue(T argData) { //returns Node prior to placement of New Node
    Node<T>* temp = getHead();

    if (temp == nullptr) {  // empty List case
        cout << "No value found.  Returning nullptr." << endl;
        return nullptr;
    }

    while (temp->getNextPtr() != nullptr) {
        if (temp->getItem() == argData) {
            return temp;
        }
        else temp = temp->getNextPtr();
    }

    if (temp->getItem() == argData) { // this covers the last Node
        return temp;
    }
    else {
        cout << "Value not found." << endl;
        return nullptr;
    }
}


template<class T>
void DoublyLinkedList<T>::addNodeMid(Node<T>* argPtr, T argStr) {   //gets argPtr, and str

    if (argPtr == nullptr) {  //Checks if the argPtr is currently pointed at a null node

        cout << "Error: Can't add node after null one. " << endl; //Prints erorr message showing new node cannot be added after null node.

    }


    //Creates new node dynamically 

    Node<T>* newNode = new Node<T>(argStr);


    //Sets pointer of the new node to the same one argPtr 
    //is pointing to.
    newNode->setNextPtr(argPtr->getNextPtr());


    //Set the previous p

    newNode->setPrevPtr(argPtr);



    //Check if the next node after argPtr exisits 

    if (argPtr->getNextPtr() != nullptr) { //meaning it's not at end and has another
                                            //valid node ahead


        argPtr->getNextPtr()->setPrevPtr(newNode); //Sets previous ptr, to Point
                                                   //to next new node
                                                   //Because there is another
                                                   //free node, for it to populate
                                                   //according to our if statement.

    }


    //Sets next ptr of argPtr to point to new new node

    argPtr->setNextPtr(newNode);



}


template<class T>
DoublyLinkedList<T>::~DoublyLinkedList() {  //THIS IS THE DESTRUCTOR (MEANING it dellocates & frees memmory
    // we need to delete the Nodes and the list at the end
    Node<T>* temp = getHead();
    //Node* currPtr = temp;

    if (temp == nullptr) {
        cout << "There's no list to delete, scrub" << endl;
        return;
    }

    while (temp->getNextPtr() != nullptr) {
        setHead(temp->getNextPtr());
        cout << "Deleting: " << temp->getItem() << endl;
        delNodeFront();  //This saved one line of code.
        temp = getHead();
    }

    // this set outside the while loop exterminates the final node
    cout << "Deleting: " << temp->getItem() << endl;  //delete this crap first!
    delete temp;  //this clears the memory 
    temp = nullptr; //sets temp to null in case it's ised again.
    setHead(nullptr);

    cout << "Linked List is empty." << endl

}



template<typename T>
void printStringList(Node<T>* beginningNodePtr) {

    Node<T>* tempNodePtr = beginningNodePtr;

    cout << "******************" << endl;
    if (tempNodePtr == nullptr) {
        cout << "List Empty" << endl;
    }
    else {
        while (tempNodePtr->getNextPtr() != nullptr) {
            // this while loop will stop at the last node.
            cout << tempNodePtr->getItem() << endl; // this line prints out each one
            tempNodePtr = tempNodePtr->getNextPtr();

        }; // after we have jumped to the final node, this doesn't print it.

        // this line takes care of the gap and prints the final item.
        cout << tempNodePtr->getItem() << endl;

    }
    cout << "******************" << endl;

}


template<typename T>      //Must put this on every c-type function with template
void printStringReverse(Node<T>* argPtr) {    //The <T> helps C++ recognize it as a data type T = string from template
    //prototype above

    Node<T>* tempNodePtr = argPtr;

    cout << "******************" << endl;
    if (tempNodePtr == nullptr) {
        cout << "List Empty" << endl;
    }
    else {
        while (tempNodePtr->getNextPtr() != nullptr) {
            // this while loop will stop at the last node.
            //cout << tempNodePtr->getItem() << endl; // this line prints out each one forward
            tempNodePtr = tempNodePtr->getNextPtr();

        }; // after we have jumped to the final node


        while (tempNodePtr->getPrevPtr() != nullptr) {
            cout << tempNodePtr->getItem() << endl;
            tempNodePtr = tempNodePtr->getPrevPtr();
        }
        // that while loop should take us to the head, but it doesn't print it.
        cout << tempNodePtr->getItem() << endl; // this prints the head.

    }
    cout << "******************" << endl;

}
