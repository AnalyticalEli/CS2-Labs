// CSCI 002 Spring 2024, Day 18, Binary Search Trees with Objects (Person)
// Comparators are making a comeback!   FIX SOME ISSUES IN THE SORT TREE IMPLEMENTATION BELOW. USE JEFE's notes to fix.

#include<iostream>
#include<string>
#include<list>
#include<vector>
#include<algorithm>


using namespace std;


class Person {
private:
    string firstName, lastName;
    bool gender;
    int age;
public:

    Person(string argFirst = "", string argLast = "", bool argGen = 0, int argAge = 0);

    void setFName(string);
    void setLName(string);
    void setGender(bool); // 0 for female, 1 for male
    void setAge(int);

    string getFName();
    string getLName();
    bool getGender();
    int getAge();
void display();
};

class Node { //modify to work with Person
private:
    Node* left;
    Node* right;

    //int value;
    Person valueP;

public:
    // Node(int valArg);
    Node(Person valArg);

    void setLeft(Node* arg);
    Node* getLeft(void);
    void setRight(Node* arg);
    Node* getRight(void);
    void setValue(Person arg);
    Person getValue(void);
    // these are integer methods
    /*void setValue(int arg);
    int getValue();*/

    //int findDepth(int); // the int return is depth, the int argument was based on integers
    int findDepth(Person i);
    void report(void);

    Node sortTree(vector<Person> arg);
};

class BinarySearchTree { // this is our forked version of linked list.
public:
    Node* root;
    // modify to work with Person, set up Constructors too

    BinarySearchTree(Person arg);

    int findDepth(Person arg);
    //int findDepth(int);
    void print(void); //  print function ?
    void addNode(Person arg);
    //void addNode(int arg);  // add node function ?
    // time permitting, let's do a size method, destructors, and make root private; 
    //insert node function?

    void sortTree(vector<Person> arg);
    void balanceTree(void);
 
};


bool compareAge(Person arg1, Person arg2);
bool compareAgeForGreater(Person arg1, Person arg2);
//bool comparePeeps(Person arg1, Person arg2); // make it work by last name, then first name, then age


int main(void) {
    //cout << "testing" << endl;
    Person tempPeep = { "David", "Jones", 1, 48 };
    //tempPeep.display();
    BinarySearchTree peopleTree(tempPeep);  // make a constructor for this
    peopleTree.print();

    tempPeep = { "Barry", "Allen", 1, 23 };
    peopleTree.addNode(tempPeep);

    tempPeep = { "James", "Bond", 1, 35 };
    peopleTree.addNode(tempPeep);

    tempPeep = { "Diana", "Prince", 0, 25 };
    peopleTree.addNode(tempPeep);

    tempPeep = { "David", "Jones", 1, 40 };
    peopleTree.addNode(tempPeep);

    tempPeep = { "James Earl", "Jones", 1, 60 };
    peopleTree.addNode(tempPeep);

    tempPeep = { "Anita", "Jones", 0, 37 };
    peopleTree.addNode(tempPeep);


    return(0);
}


Person::Person(string argF, string argL, bool argG, int argA) {
    setFName(argF);
    setLName(argL);
    setGender(argG);
    setAge(argA);
}

void Person::setFName(string arg) {
    arg[0] = toupper(arg[0]);
    firstName = arg;
}

void Person::setLName(string arg) {
    arg[0] = toupper(arg[0]);
    lastName = arg;
}

void Person::setGender(bool arg) {
    gender = arg;
}

void Person::setAge(int arg) {
    age = arg;
}

string Person::getFName() {
    return firstName;
}

string Person::getLName() {
    return lastName;
}

bool Person::getGender() {
    return gender;
}

int Person::getAge() {
    return age;
}

void Person::display() {
    cout << getFName() << " " << getLName() << " ";
    if (getGender())  // if getGender() ==1 , cout Male (1 is true), Female (0 is false)
    {
        cout << "Male";
    }
    else
        cout << "Female";
    cout << " Age : " << getAge() << endl;
}


bool compareAge(Person arg1, Person arg2) {  // incoming person Arg1, and the Node to compare is arg2
    bool answer = (arg1.getAge() < arg2.getAge());

    return answer;

}

bool compareAgeForGreater(Person arg1, Person arg2) {
    bool answer = ((arg1).getAge() > (arg2).getAge());

    return answer;
}

// if new person (arg1) < old person (arg2);
bool comparePeeps(Person arg1, Person arg2) {  // make it work by last name, then first name, then age
    // compare last names, arg1<arg2
    if (arg1.getLName() < arg2.getLName()) {
        return (1); // tells it to go left
    }
    if (arg1.getLName() == arg2.getLName()) {
        // now we look at first names;
        if (arg1.getFName() < arg2.getFName()) {
            return(1);
        }
        if (arg1.getFName() == arg2.getFName()) {
            // now we look at genders, Alexis chose this;
            if (arg1.getGender() < arg2.getGender()) {
                return (1);
            }
            if (arg1.getGender() == arg2.getGender()) {
                if (arg1.getAge() < arg2.getAge()) {
                    return(1);
                }
                if (arg1.getAge() == arg2.getAge()) {// where everthing is equal;
                    throw exception("We have a doppleganger!");
                }
            }
        }
    }

    // after we do this, we need to edit the following, as they both rely on comparisons
    // Node::findDepth
    // BST::addNode

    return(0);
}

Node::Node(Person valArg) {
    //Node::Node(int valArg) {
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
void Node::setValue(Person arg) {
    //void Node::setValue(int arg) {
    valueP = arg;
}
Person Node::getValue() {
    //int Node::getValue() {
    return valueP;
}


BinarySearchTree::BinarySearchTree(Person arg) {   //There needs to be a new Node 

    cout << "Start Constructor " << endl;

    root = new Node(arg);  //Creates a new Node for Person
    root->setValue(arg); 



}

int BinarySearchTree::findDepth(Person i) {
    if (root)  return (root->findDepth(i));
    else { return(-1); }
}

void BinarySearchTree::print(void) {
    cout << "Our Binary Search Tree, in order, is:  ";
    root->report();
    cout << endl;
}

void BinarySearchTree::addNode(Person arg) {
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
            if (comparePeeps(arg, curr->getValue())) // arg < curr
                //if (arg < curr->getValue())
                curr = curr->getLeft();  // go left if incoming value is less.
            else curr = curr->getRight();
        } // current is the location of where the new value goes.

        // finally set the Node up.
        // temp is the last good Node, so we need to add from there.
        if (comparePeeps(arg, temp->getValue()))
            //if (arg < temp->getValue())
            temp->setLeft(new Node(arg));
        else
            temp->setRight(new Node(arg));
    }

}
int Node::findDepth(Person i) {
    //int Node::findDepth(int i) {
       // if (i == value) return(0);  // root depth is zero.
    if (i.getLName() == getValue().getLName()) {// mimic i == value but for people
        if (i.getFName() == getValue().getFName()) {
            if (i.getGender() == getValue().getGender()) {
                if (i.getAge() == getValue().getAge()) {
                    return(0);
                }
            }
        }
    }

    int d = 0;
    if (comparePeeps(i, getValue())) { // this is our goal, to make this work
        //if (i < value) {
        if (left) d = left->findDepth(i); // is left nullptr or does it exist?
        else d = -1; // this is the left is nullptr option.
    }
    if (!comparePeeps(i, getValue())) {  // or we could have said comparePeeps(value, i);
        //if (i > value) {
        if (right) d = right->findDepth(i); // this is like the left, but for going right
        else d = -1;
    }
    if (d == -1) return(-1);
    else return(d + 1);
};

void Node::report() { // recursive print job, edited for Person
    if (left) left->report();
    getValue().display();
    cout << endl << endl;
    if (right) right->report();
};



vector<Person> BinarySearchTree::sortTree(vector<Person> arg) {  //Creating a recursive vector.


    Node* temp = root;  //Temp will always be ONE ahead with the code below
    Node* current = root;

    if (temp == nullptr) {  //If temp is empty 

        return arg;

    }


    while (root != nullptr) {

        temp = root;
        current = root;  //Not having current equal root could lead to some issues with the Nodes.


        while(temp->getLeft() != nullptr && temp->getRight() != nullptr) {  //While both left root and right root are not empty

            current = temp;

            temp = temp-_


            if (temp->getLeft() != nullptr) {  //If the left is not empty

                arg.push_back(temp->getValue());
                temp = temp->getLeft();

            }

            else if (temp->getRight() != nullptr) {

                arg.push_back(temp->getValue());
                temp = temp->getLeft();

            }

        }
        arg.push_back(current->getValue());   //And because we're deleting and getting 
        delete current;                       //rid of the tree with node
        current = nullptr;


    }


    arg.push_back(root->getValue());
    delete root;



    sort(arg.begin(), arg.end(), )




}

void BinarySearchTree::balanceTree(void) {


    vector<Person> temp;




}