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
    void report(void);
};

class BinarySearchTree { // this is our forked version 
    // of linked list.
public:
    Node* root;

    int findDepth(int);
    void print(void); //  print function ?
    void addNode(int arg);  // add node function ?
    // insert node function?
};

int main(void) {
    BinarySearchTree myTree;

    Node* head = new Node(8);
    Node* curr = head;
    myTree.root = new Node(8); // this is the Node* head.

    curr->setLeft(new Node(3));
    curr->setRight(new Node(10));
    myTree.addNode(3);
    myTree.addNode(10); // should do the last two lines.

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
    myTree.addNode(14);

    curr->getRight()->setLeft(new Node(13));
    myTree.addNode(13);

    cout << "Depth of 6 is: " << myTree.findDepth(6);

    cout << endl << endl;

    myTree.print();

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
    if (root)  return (root->findDepth(i));
    else { return(-1); }
}

void BinarySearchTree::print(void) {
    cout << "Our Binary Search Tree, in order, is:  ";
    root->report();
    cout << endl;
}

void BinarySearchTree::addNode(int arg) {
    Node* temp;
    Node* curr;
    if (root == nullptr) { // this deals with an emptry tree
        root = new Node(arg);
    }
    else { // if not empty, 
        temp = root;
        curr = root;

        // we follow the path to where it should go.
        while (curr != nullptr) {
            temp = curr; // when it's done, temp is the last complete Node.
            if (arg < curr->getValue())
                curr = curr->getLeft();  // go left if incoming value is less.
            else curr = curr->getRight();
        } // current is the location of where the new value goes.

        // finally set the Node up.
        // temp is the last good Node, so we need to add from there.
        if (arg < temp->getValue())
            temp->setLeft(new Node(arg));
        else
            temp->setRight(new Node(arg));
        // this following line replaces the if/esle above, but only if you're an asshole like PadaJuan
        //arg < temp->getValue() ? temp->setLeft(new Node(arg)) : temp->setRight(new Node(arg));

    }

}

int Node::findDepth(int i) {
    if (i == value) return(0);  // root depth is zero.

    int d;

    if (i < value) {
        if (left) d = left->findDepth(i); // is left nullptr or does it exist?
        else d = -1; // this is the left is nullptr option.
    }
    if (i > value) {
        if (right) d = right->findDepth(i); // this is like the left, but for going right
        else d = -1;
    }
    if (d == -1) return(-1);
    else return(d + 1);
};

void Node::report() { // recursive print job, 
    if (left) left->report();
    cout << value << " ";
    if (right) right->report();
};