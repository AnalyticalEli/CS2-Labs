//#include<iostream>
//using namespace std;
//
//class Node {
//private:
//	Node* left;
//	Node* right;
//
//	int value;
//
//public:
//	Node(int valArg);
//
//
//	void setLeft(Node* arg);
//	Node* getLeft(void);
//	void setRight(Node* arg);
//	Node* getRight(void);
//	void setValue(int arg);
//	int getValue();
//
//
//};
//
//int main(void) {
//
//	Node* head = new Node(8);
//	Node* curr = head;
//
//	curr->setLeft(new Node(3));
//	curr->setRight(new Node(10));
//
//	curr = curr->getLeft();
//	curr->setLeft(new Node(1));
//	curr->setRight(new Node(6));
//
//	curr = curr->getRight();
//	curr->setLeft(new Node(4));
//	curr->setRight(new Node(7));
//
//	curr = head;
//
//	curr = curr->getRight();
//	curr->setRight(new Node(14));
//
//	curr->getRight()->setLeft(new Node(13));
//
//	return(0);
//}
//
//Node::Node(int valArg) {
//	setValue(valArg);
//	setLeft(nullptr);
//	setRight(nullptr);
//}
//
//
//void Node::setLeft(Node* arg) {
//	left = arg;
//}
//Node* Node::getLeft(void) {
//	return left;
//}
//void Node::setRight(Node* arg) {
//	right = arg;
//}
//Node* Node::getRight(void) {
//	return right;
//}
//void  Node::setValue(int arg) {
//	value = arg;
//}
//int  Node::getValue() {
//	return value;
//}