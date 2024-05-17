//Class Notes 6B Binary T 


//Balanced Binary Trees Have the same number of lower
//and higher numbers on the base: For example {12, 30, 2}
//is balanced.

//Starting at 12 going to the right for larger(30), and one
//to the left which is less than 12 (2). 
//One on the left one on the right.

#include<iostream>
#include<string>
#include<list>
using namespace std;

class Node {
private:
    Node* left;
    Node* right;

    int value;

public:
    Node(int valArg);

    void setLeft(Node* arg);
    Node* getLeft(void);
    void setRight(Node* arg);
    Node* getRight(void);
    void setValue(int arg);
    int getValue();

    int findDepth(int);
    void report(void);  //Prints tree recursively
};

class BinarySearchTree {  //By having everything public no need to use accessor methods
public:
    Node* root;

    int findDepth(int);
    // print function?
    void print(void);
    // add node function?
    void addNode(int arg);
    // insert node function?
};

int main(void) {

    BinarySearchTree myTree;  //BinarySearchTree called myTree


    Node* head = new Node(8);
    Node* curr = head;
    myTree.root = new Node(8); //This is the Node* head


    curr->setLeft(new Node(3));
    curr->setRight(new Node(10));
    myTree.addNode(3);
    myTree.addNode(10);  //should do the last two lines.



    curr = curr->getLeft();
    curr->setLeft(new Node(1));
    curr->setRight(new Node(6));
    myTree.addNode(1);
    myTree.addNode(6);

    curr = curr->getRight();
    curr->setLeft(new Node(4));
    curr->setRight(new Node(7));
    myTree.addNode(4);
    myTree.addNode(7);


    curr = head;

    curr = curr->getRight();
    curr->setRight(new Node(14));


    curr->getRight()->setLeft(new Node(13));
    myTree.addNode(13);

    cout << "Depth of 13 is: " << myTree->findDepth(13);

    curr->getRight()->setLeft(new Node(13));

    cout << "Depth of 13 is: " << head->findDepth(13);

    cout << endl << endl;

    head->report();  //Prints out current head

    return(0);
}

Node::Node(int valArg) {
    setValue(valArg);
    setLeft(nullptr);
    setRight(nullptr);
}


void Node::setLeft(Node* arg) {
    left = arg;
}
Node* Node::getLeft(void) {
    return left;
}
void Node::setRight(Node* arg) {
    right = arg;
}
Node* Node::getRight(void) {
    return right;
}
void  Node::setValue(int arg) {
    value = arg;
}
int  Node::getValue() {
    return value;
}

int BinarySearchTree::findDepth(int i) {
    if (root)  return (root->findDepth(i));  //root depth = 0;
    else { return(-1); }
};



void BinarySearchTree :: print(void) {

    cout << "Our Binary Tree, in order, is:  " << endl;

    root->report();   //Prints tree

    cout << endl;

}


void BinarySearchTree::addNode(int arg) {  //Fix something are off


    Node* temp;
    Node* curr;

    if (root == nullptr) {  //If root is empty

        root = new Node(arg);  //Setting equal to new node as an argument


    }
    else {  //If it's not nullptr (empty)

        temp = root; //Because in this case root exists Node ptr is root
        curr = root;  //Our current Node* value is set to root. (Again if not empty)


        //Larger goes right, and smaller goes left.
        while (curr != nullptr) {  //While current isn't empty

            temp = curr;  //When it's done, temp is the last complete Node.

            if (arg < curr->getValue()) //Compares and sees if value is greater than our 
                curr = curr->getLeft();  //If smaller than base we're comparing to goes left


            else   //BUT if larger than base we're comparing to goes RIGHT
                curr = curr->getRight();

        } //current is the new location of where the new value goes.
          

        //FINALLY set the node.
        //ABOVE while(curr != nullptr) ensures the CODE BELOW IS A NULLPTR
        //temp is the last good node, so we need to add from there.
        //compares incoming value and if it's lower it goes left. (Needs to be done but in final spot)
        if (arg = temp->getValue()) { 
                temp->getLeft(new Node(arg));  //Takes lower values to left and creates a new nod with a new value
        }

        else {
            curr = temp->getRight(new Node(arg));

        }

    
        //this following line replaces the if/else above but only if you're an asshole like PadaJuan
        //arg < temp

    }



}

int Node::findDepth(int i) {    //Finds the depthof the binary tree.
    if (i == value) return(0);

    int d;

    if (i < value) {   //If it's smaller than base value (12) and i == 2
        if (left) d = left->findDepth(i);  //then it will be moved to find it
                                           //nullptr option.
        else d = -1;
    }
    if (i > value) {   //If it's alarge than base value (12) and i == 22
        if (right) d = right->findDepth(i);  //then it will be moved to find it
        else d = -1;
    }
    if (d == -1) return(-1);
    else return(d + 1);
};

void Node::report() {    //Prints out the tree order RECURSIVELY
    if (left) left->report();
    cout << value << " ";
    if (right) right->report();
};


