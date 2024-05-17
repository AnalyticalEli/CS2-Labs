////Class Notes 6C Binary Search Trees with Objects
//
//
//// CSCI 002 Spring 2024, Day 18, Binary Search Trees with Objects (Person)
//// Comparators are making a comeback!
//
//#include<iostream>
//#include<string>
//#include<list>
//using namespace std;
//
//
//class Person {
//private:
//    string firstName, lastName;
//    bool gender;   //Either (0 is female, 1 is male)
//    int age;
//public:
//
//    Person(string argFirst = "", string argLast = "", bool argGen = 0, int argAge = 0);
//
//    void setFName(string);
//    void setLName(string);
//    void setGender(bool); // 0 for female, 1 for male
//    void setAge(int);
//
//    string getFName();
//    string getLName();
//    bool getGender();
//    int getAge();
//
//    void display();
//};
//
//class Node { //modify to work with Person
//private:
//    Node* left;
//    Node* right;
//
//    //int value;
//
//    Person value;
//
//public:
//   // Node(int valArg);
//
//    Node(Person argVal);
//
//    void setLeft(Node* arg);
//    Node* getLeft(void);
//    void setRight(Node* arg);
//    Node* getRight(void);
//
//    //These are the interger methods 
//   /* void setValue(int arg);
//    int getValue();*/
//
//
//
//    //int findDepth(int); the int return is depth, the int argument was absed on integer
//    //Accessor methods for the Person value set above & for Object
//    void setValue(Person arg);
//    Person getValue(void);
//
//    int findDepth(Person i);
//    void report(void);
//};
//
//class BinarySearchTree { // this is our forked version of linked list.
//public:
//    Node* root;
//    // modify to work with Person, set up Constructors too
//
//
//    BinarySearchTree(Person arg);  //BinarySearchTree Constructor
//
//    
//
//    //int findDepth(int);
//    int findDepth(Person i);
//    void print(void); //  print function ?
//    void addNode(Person arg);  // add node function ?
//    // insert node function?
//};
//
//
////Two different comparators:
//
//bool compareAge(Person arg1, Person arg2);  //Age comparator 
//bool compareAgeForGreater(Person arg1, Person arg2);  //
////bool comparePeeps(Person arg1, Person arg2); // make it work by last name, then first name, then age
//
//int main(void) {
//    
//    cout << "Test" << endl;
//    Person tempPeep = { "David", "Jones", 1, 48 };
//
//    cout << "1 2 3 4" << endl;
//
//    BinarySearchTree peopleTree(tempPeep);
//    // BinarySearchTree peopleTree(tempPeep);  // make a constructor for this
//
//     //tempPeep = { "Barry", "Allen", 1, 23 };
//     //peopleTree.addNode(tempPeep);
//
//     //tempPeep = { "James", "Bond", 1, 35 };
//     //peopleTree.addNode(tempPeep);
//
//     //tempPeep = { "Diana", "Prince", 0, 25 };
//     //peopleTree.addNode(tempPeep);
//
//     //tempPeep = { "David", "Jones", 1, 25 };
//     //peopleTree.addNode(tempPeep);
//
//     //tempPeep = { "James Earl", "Jones", 1, 60 };
//     //peopleTree.addNode(tempPeep);
//
//     //tempPeep = { "Anita", "Jones", 0, 37 };
//     //peopleTree.addNode(tempPeep);
//
//
//    return(0);
//}
//
//
//Person::Person(string argF, string argL, bool argG, int argA) {
//    setFName(argF);
//    setLName(argL);
//    setGender(argG);
//    setAge(argA);
//}
//
//void Person::setFName(string arg) {
//    arg[0] = toupper(arg[0]);
//    firstName = arg;
//}
//
//void Person::setLName(string arg) {
//    arg[0] = toupper(arg[0]);
//    lastName = arg;
//}
//
//void Person::setGender(bool arg) {
//    gender = arg;
//}
//
//void Person::setAge(int arg) {
//    age = arg;
//}
//
//string Person::getFName() {
//    return firstName;
//}
//
//string Person::getLName() {
//    return lastName;
//}
//
//bool Person::getGender() {
//    return gender;
//}
//
//int Person::getAge() {
//    return age;
//}
//
//void Person::display() {
//    cout << getFName() << " " << getLName() << " ";
//    if (getGender())  // if getGender() ==1 , cout Male (1 is true), Female (0 is false)
//    {
//        cout << "Male";
//    }
//    else
//        cout << "Female";
//    cout << " Age : " << getAge() << endl;
//}
//
//
//bool compareAge(Person arg1, Person arg2) {  //Compartor Normal and the Node to compare is arg2 from arg 1
//    bool answer = (arg1.getAge() < arg2.getAge());
//
//    return answer;
//
//}
//
//bool compareAgeForGreater(Person arg1, Person arg2) {  //Compartor prints from greatest least
//    bool answer = ((arg1).getAge() > (arg2).getAge());
//
//    return answer;
//}
//
//// if new person (arg1) < old person (arg2);
//bool comparePeeps(Person arg1, Person arg2) {  // make it work by last name, then first name, then age
//    // compare last names, arg1<arg2
//
//    if (arg1.getLName() < arg2.getLName()) {  //Search in order of last names (A-Z)
//
//        return(1);
//
//    }
//
//    if (arg1.getLName() == arg2.getLName()) {    //Then if the Last names are the same
//
//        if (arg1.getFName() < arg2.getFName())  //Sort by first name A-Z 
//            return(1);
//
//
//        if (arg1.getGender() == arg2.getGender()) {  //And Sort by first name A-Z
//           //Now we get age 
//            
//            return(1);
//        }
//
//
//        if (arg1.getAge() < arg2.getAge()) {
//
//            return(1);
//        }
//
//
//        throw exception("We have an imposter amongus, doppleganger! ");
//
//
//            
//
//    }
//
//
//
//
//    // after we do this, we need to edit the following, as they both rely on comparisons
//    // Node::findDepth
//    // BST::addNode
//    return(0);
//}
//
//
//
//Node::Node(Person valArg) {
//
//
//
//}
//
//Node::Node(int valArg) {
//    setValue(valArg);
//    setLeft(nullptr);
//    setRight(nullptr);
//}
//
//
//void Node::setLeft(Node* arg) {
//    left = arg;
//}
//Node* Node::getLeft(void) {
//    return left;
//}
//void Node::setRight(Node* arg) {
//    right = arg;
//}
//Node* Node::getRight(void) {
//    return right;
//}
////void  Node::setValue(int arg) {
////    value = arg;
////}
//
//void Node::setValue(Person arg) {
//
//    value = arg;
//
//}
//
//Person  Node::getValue() {
//    return value;
//}
//
////int  Node::getValue() {
////    return value;
////}
//
//Person  Node::getValue() {
//    return value;
//}
//
//int BinarySearchTree::findDepth(Person i) {
//    if (root)  return (root->findDepth(i));
//    else { return(-1); }
//}
//
//void BinarySearchTree::print(void) {
//    cout << "Our Binary Search Tree, in order, is:  ";
//    root->report();
//    cout << endl;
//}
//
//BinarySearchTree::BinarySearchTree(Person arg) {
//
//    cout << "Start Constructor " << endl;
//
//    root = new Node(arg);  //Creates a new Node for Person
//    root->setValue(arg); 
//
//
//
//}
//
//void BinarySearchTree::addNode(Person arg) {
//    Node* temp;
//    Node* curr;
//    if (root == nullptr) { // this deals with an emptry tree
//        root = new Node(arg);
//    }
//    else { // if not empty, 
//        temp = root;
//        curr = root;
//
//        // we follow the path to where it should go.
//        while (curr != nullptr) {
//            temp = curr; // when it's done, temp is the last complete Node.
//            if (comparePeeps() < curr->getValue())
//                curr = curr->getLeft();  // go left if incoming value is less.
//            else curr = curr->getRight();
//        } // current is the location of where the new value goes.
//
//        // finally set the Node up.
//        // temp is the last good Node, so we need to add from there.
//        if (arg < temp->getValue())
//            temp->setLeft(new Node(arg));
//        else
//            temp->setRight(new Node(arg));
//        // this following line replaces the if/esle above, but only if you're an asshole like PadaJuan
//        //arg < temp->getValue() ? temp->setLeft(new Node(arg)) : temp->setRight(new Node(arg));
//
//    }
//
//}
//
//
//int Node::findDepth(Person i) {  //Binary Tree for Person
//
//
////int Node::findDepth(int i) {
//   // if (i == value) return(0);  // root depth is zero.
//
//    if (i.getLName() == value.getLName()) {  //mmic i == value but for people. IF Last names are the same 
//
//
//        if (i.getFName() == value.getFName()) {   //Then checks the first names   (least to greatest) 
//            if (i.getGender() == value.getGender()) {  //If first names are the same then checks age (least to greatest) 
//
//                return(0);
//            }
//
//        }
//
//
//
//    }
//
//
//
//    int d = 0; //Initializing d for below
//
//
//    if (comparePeeps(i, value)) {  //This is our goal, make this work real quick
//
//   // if (i < value) {
//        if (right) d = left->findDepth(i); // is left nullptr or does it exist?
//        else d = -1; // this is the left is nullptr option.
//    }
//
//
//
//
//    if (!comparePeeps(i, value)){
//
//    //if (i > value){
//        if (right) d = right->findDepth(i); // this is like the left, but for going right
//        else d = -1;
//    }
//    if (d == -1) return(-1);
//    else return(d + 1);
//};
//
//void Node::report() { // recursive print job, 
//    if (left) left->report();
//    value.display();    //Displays the valuees
//    cout << endl << endl;
//    if (right) right->report();
//};