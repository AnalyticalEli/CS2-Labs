#include<iostream>
#include<string>
using namespace std;

class Node {
private:
    Node* next;
    string item;
public:
    // Constructor
    Node() { } // generic. Hard code entries in main.
    // Accessor methods
    void setNext(Node* arg) { next = arg; }
    void setItem(string arg1) { item = arg1; }
    Node* getNext() { return next; }
    string getItem(void) { return item; }
};

void printList(Node* arg) {
    Node* temp = arg;
    while (temp != nullptr) {
        cout << temp->getItem() << " ";
        temp = temp->getNext();
    }
}

int main() {
    // Create Nodes and link them while setting items
    Node* node1 = new Node();
    node1->setItem("All");
    node1->setNext(new Node());
    node1->getNext()->setItem("hail");
    node1->getNext()->setNext(new Node());
    node1->getNext()->getNext()->setItem("Jefe");
    node1->getNext()->getNext()->setNext(nullptr);

    // Print the list
    printList(node1);

    // Free memory
    delete node1->getNext()->getNext();
    delete node1->getNext();
    delete node1;

    return 0;
}
