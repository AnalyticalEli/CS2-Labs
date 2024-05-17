//// CSCI 002 Spring 2024, Day 20, Binary Search Trees with Objects (Person)
//// Destructors!
//
//#include<iostream>
//#include<string>
//#include<list>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Person {
//private:
//    string firstName, lastName;
//    bool gender;
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
//class Node {
//private:
//    Node* left;
//    Node* right;
//
//    Person valueP;
//
//public:
//    Node(Person valArg);
//
//    void setLeft(Node* arg);
//    Node* getLeft(void);
//    void setRight(Node* arg);
//    Node* getRight(void);
//    void setValue(Person arg);
//    Person getValue(void);
//
//    int findDepth(Person i);
//    void report(void);
//
//
//    int countHangingNodes(void);
//    int maxDepth(void);
//    
//
//    void deleteHangingNode();
//
//    ~Node() {
//        cout << "Node containing " << getValue().getFName() <<  " has been destroyed" << endl;
//    }
//
//};
//
//class BinarySearchTree { // this is our forked version of linked list.
//private:
//    Node* root;
//public:
//    BinarySearchTree(Person arg);
//
//    Node* getRoot(void);
//    void setRoot(Node* arg);
//
//    int findDepth(Person arg);
//    //int findDepth(int);
//    void print(void); //  print function ?
//    void addNode(Person arg);
//
//    //int size(void);  //Number of elements within Tree.
//
//   // int maxDepth(void);   //Reports how deep the tree is.
//    // time permitting, let's do a size method, destructors, and make root private; insert node function?
//    void balanceTree(void);
//    void deleteTree(void);
//};
//
//bool compareAge(Person arg1, Person arg2);
//bool compareAgeForGreater(Person arg1, Person arg2);
//bool comparePeeps(Person arg1, Person arg2); // make it work by last name, then first name, then age
//
//
//int main(void) {
//    //cout << "testing" << endl;
//    Person tempPeep = { "David", "Jones", 1, 48 };
//    //tempPeep.display();
//    BinarySearchTree peopleTree(tempPeep);  // make a constructor for this
//
//    tempPeep = { "Barry", "Allen", 1, 23 };
//    peopleTree.addNode(tempPeep);
//
//    tempPeep = { "James", "Bond", 1, 35 };
//    peopleTree.addNode(tempPeep);
//
//    tempPeep = { "Diana", "Prince", 0, 25 };
//    peopleTree.addNode(tempPeep);
//
//    tempPeep = { "David", "Jones", 1, 25 };
//    peopleTree.addNode(tempPeep);
//
//    tempPeep = { "James Earl", "Jones", 1, 60 };
//    peopleTree.addNode(tempPeep);
//
//    tempPeep = { "Anita", "Jones", 0, 37 };
//    peopleTree.addNode(tempPeep);
//
//    tempPeep = { "Dillon \"Dill Pickle\"", "Allen", 1, 23 };
//    peopleTree.addNode(tempPeep);
//
//    peopleTree.print();   //Prints the tree
//
//    cout << endl << endl;
//
//    peopleTree.deleteTree();  //Deallocates Memory (For the Nodes)
//
//
//    cout << "Size of People Tree" << peopleTree.getRoot()->countHangingNodes() << endl << endl;  //Using root, we count all of the hanging nodes.
//
//    return(0);
//}
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
//    cout << getFName() << " " << getLName() << ", ";
//    if (getGender())  // if getGender() ==1 , cout Male (1 is true), Female (0 is false)
//    {
//        cout << "Male,";
//    }
//    else
//        cout << "Female,";
//    cout << " Age: " << getAge() << endl;
//}
//
//bool compareAge(Person arg1, Person arg2) {  // incoming person Arg1, and the Node to compare is arg2
//    bool answer = (arg1.getAge() < arg2.getAge());
//
//    return answer;
//}
//
//bool compareAgeForGreater(Person arg1, Person arg2) {
//    bool answer = ((arg1).getAge() > (arg2).getAge());
//
//    return answer;
//}
//
//// if new person (arg1) < old person (arg2);
//bool comparePeeps(Person arg1, Person arg2) {  // make it work by last name, then first name, then age
//    // compare last names, arg1<arg2
//    if (arg1.getLName() < arg2.getLName()) {
//        return (1); // tells it to go left
//    }
//    if (arg1.getLName() == arg2.getLName()) {
//        // now we look at first names;
//        if (arg1.getFName() < arg2.getFName()) {
//            return(1);
//        }
//        if (arg1.getFName() == arg2.getFName()) {
//            // now we look at genders, Alexis chose this;
//            if (arg1.getGender() < arg2.getGender()) {
//                return (1);
//            }
//            if (arg1.getGender() == arg2.getGender()) {
//                if (arg1.getAge() < arg2.getAge()) {
//                    return(1);
//                }
//                if (arg1.getAge() == arg2.getAge()) {// where everthing is equal;
//                    throw exception("We have a doppleganger!");
//                }
//            }
//        }
//    }
//    return(0);
//}
//
//Node::Node(Person valArg) {
//    setValue(valArg);
//    setLeft(nullptr);
//    setRight(nullptr);
//}
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
//void Node::setValue(Person arg) {
//    valueP = arg;
//}
//Person Node::getValue() {
//    return valueP;
//}
//
//int Node::findDepth(Person i) {
//    if (i.getLName() == getValue().getLName()) {
//        if (i.getFName() == getValue().getFName()) {
//            if (i.getGender() == getValue().getGender()) {
//                if (i.getAge() == getValue().getAge()) {
//                    return(0);
//                }
//            }
//        }
//    }
//
//    int d = 0;
//    if (comparePeeps(i, getValue())) { // this is our goal, to make this work
//        //if (i < value) {
//        if (left) d = left->findDepth(i); // is left nullptr or does it exist?
//        else d = -1; // this is the left is nullptr option.
//    }
//    if (!comparePeeps(i, getValue())) {  // or we could have said comparePeeps(value, i);
//        //if (i > value) {
//        if (right) d = right->findDepth(i); // this is like the left, but for going right
//        else d = -1;
//    }
//    if (d == -1) return(-1);
//    else return(d + 1);
//};
//
//void Node::report() { // recursive print job, edited for Person
//    if (left) left->report();
//    getValue().display();
//    // cout << endl;
//    if (right) right->report();
//};
//
//
//int Node::countHangingNodes(void) {  //Number of elements within Tree.
//
//
//    int sizeCounter = 1;  //Iterates through each starting at 1
//
//    //If left exists
//    if (left != nullptr) {
//        sizeCounter = sizeCounter + left->countHangingNodes();   //Increments on right everytime it's called upon adding previous and next.
//
//
//    }
//    //If right exists
//    if (right != nullptr) {
//        sizeCounter += right->countHangingNodes();  //Increments on right everytime it's called upon adding previous and next.
//    }
//
//    return sizeCounter;
//}
//
//int Node::maxDepth(void) {   //Reports how deep the tree is.
//
//    int maxDepth = findDepth(getValue());  //Gets the Depth from find depth, and inputs value from getValue.
//    int temp = findDepth(getValue());
//
//
//    //If Left Exists
//    if (left != nullptr) {
//        temp = 1 + left->maxDepth();   //Gets the right depth from maxDepth variable above (Need to add one because it starts at ZERO)
//       
//        if (temp > maxDepth) {  //If the temp is greater than maxDepth
//            maxDepth = temp;       //Return temp value because it (probably) has the correct value for the Depth. (TEMP BECOMES NEW CURRENT VALUE)
//        }
//    }
//
//
//    //If right exists
//    if (right != nullptr) {
//        temp = 1 + right->maxDepth();   //Gets the right depth from maxDepth variable above (Need to add one because it starts at ZERO)
//
//        if (temp > maxDepth) {  //If the temp is greater than maxDepth
//            maxDepth = temp;   //Return temp value because it (probably) has the correct value for the Depth. (TEMP BECOMES NEW CURRENT VALUE)
//        }
//
//    }
//
//    
//    return maxDepth;   //Returns maxDepth as maximum possible size.
//}
//
//void Node::deleteHangingNode(void) {      //Deletes the hanging nodes (sets things to nullptr and deallocates them)
//    if (this == nullptr) { // If Node is nullptr (empty) & takes to the node before the end.
//        return;
//    }
//    else {
//        Node* forward = this; // Goes to last node
//        Node* previous = forward; // goes to second to last node
//        while (previous != nullptr) { // Checks to see if the whole tree is deleted
//            if (forward == nullptr) { // resets both foward and previous to root after deleting a node
//                forward = this;
//                previous = forward;
//            }
//            if (forward->getLeft() == nullptr && forward->getRight() == nullptr) { // checks to see if forward is at the last node
//                //  deletes and sets the the one you deleted to nullptr to take care of dangling pointers (GOOD PRACTICE)
//                if (previous->getLeft() == forward) {  //If previous on the left is NOT a nullptr 
//                    delete forward;                 //Memory Deallocation (Left) 
//                    forward = nullptr;
//                    previous->setLeft(nullptr);   //Sets previous to nullptr as well
//                }
//                else if (previous->getRight() == forward) {
//                    delete forward;                 //Memory Deallocation (Right)
//                    forward = nullptr;
//                    previous->setRight(nullptr);
//                }
//                else {   //Deallocates any other situation.
//                    delete forward;
//                    forward = nullptr;
//                    previous = nullptr;
//                }
//            }
//            else if (forward->getLeft() != nullptr) { // iterates both forward and previous to intended last path.
//                previous = forward;
//                forward = forward->getLeft();
//            }
//            else { // iterates both forward and previous to intended last path.
//                previous = forward;
//                forward = forward->getRight();
//            }
//        }
//    }
//}
//Node* BinarySearchTree::getRoot(void) {
//    return(root);
//}
//void BinarySearchTree::setRoot(Node* arg) {
//    root = arg;
//}
//
//void BinarySearchTree::deleteTree(void) {
//    getRoot()->deleteHangingNode(); // function call to deleting all nodes below (and including) the root
//}
//
//int BinarySearchTree::findDepth(Person i) {
//    if (root)  return (root->findDepth(i));
//    else { return(-1); }
//}
//
//void BinarySearchTree::print(void) {
//    cout << "Our Binary Search Tree, in order, is:  " << endl << endl;
//    root->report();
//    //cout << endl;
//}
//
//BinarySearchTree::BinarySearchTree(Person arg) {
//    root = new Node(arg);
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
//            if (comparePeeps(arg, curr->getValue())) // arg < curr
//                //if (arg < curr->getValue())
//                curr = curr->getLeft();  // go left if incoming value is less.
//            else curr = curr->getRight();
//        } // current is the location of where the new value goes.
//
//        // finally set the Node up.
//        // temp is the last good Node, so we need to add from there.
//        if (comparePeeps(arg, temp->getValue()))
//            //if (arg < temp->getValue())
//            temp->setLeft(new Node(arg));
//        else
//            temp->setRight(new Node(arg));
//    }
//}
//
//void BinarySearchTree::balanceTree(void) {
//    vector<Person> arg;
//    Node* temp = root;
//    Node* curr = root;
//    if (temp == nullptr) {
//        //cout << "Empty tree." << endl;
//        return;
//    }
//    while (root != nullptr) {
//        temp = root;
//        curr = root;
//        while (temp->getLeft() != nullptr && temp->getRight() != nullptr) {  // !temp
//            curr = temp;
//            if (temp->getLeft() != nullptr) {
//                //arg.push_back(temp->getValue());
//                temp = temp->getLeft();
//            }
//            else if (temp->getRight() != nullptr) {
//                //arg.push_back(temp->getValue());
//                temp = temp->getRight();
//            }
//        }
//        arg.push_back(curr->getValue());
//        delete curr; // this just deletes the data, curr is still pointing to the same memory spot.
//        curr = nullptr;
//    }
//
//    sort(arg.begin(), arg.end(), comparePeeps);
//}