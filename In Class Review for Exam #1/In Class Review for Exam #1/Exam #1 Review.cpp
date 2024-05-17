// Review Notes for Exam 1


#include <iostream>
#include <vector>
#include <list>
#include <cmath>
using namespace std;

template<class T>
class Point {
private:
    T x, y;

public:

    Point(T a = 0, T b = 0) { x = a;  y = b; }

    void setX(T arg) { x = arg; }
    T getX(void) { return this->x; }

    void setY(T arg) { y = arg; }
    T getY(void) { return y; }

    virtual void print() { // on virtual methods, if it has = 0, it must be
        // implemented in derived or children classes, if not, it's optional
        cout << "Point(" << x << "," << y << ")";
    }

    //double distanceCalc(Point arg) {
        // pow(base, exponent)  sqrt[(x2-x1)^2 + (y2-y1)^2]
        //double base = pow(this->x - arg.x, 2) + pow(this->y - arg.y, 2);
        //(   base    ,  0.5  )
    //}

};

template<class T>
class Circle : public Point<T> {
private:
    T r;

public:
    Circle(T argX = 0, T argY = 0, T argR = 0) { //} : Point<T>(argX, argY) {  //constructor
        Point<T>::setX(argX);
        Point<T>::setY(argY);
        r = argR;
    }
    /*
       or
        Circle(T argX = 0, T argY = 0, T argR = 0) : Point<T>(argX, argY) {  //constructor
        r = argR;
    }
    */

    virtual void print() {
        cout << "Circle with Center Point(" << Point<T>::getX() << ", " << Point<T>::getY() << ")";
        //cout << "Circle with Center: ";
        //Point<T>::print();
        cout << " and radius r = " << r;
    }

};

template<class Obj>
class Node {
private:
    Node<Obj>* prev;
    Node<Obj>* next;

    Obj item;

public:
    // Constructor
    Node<Obj>() { next = nullptr; prev = nullptr; } // generic.  Hard code entries in main.
    // Accessor methods

    void setPrev(Node<Obj>* arg) { prev = arg; }
    Node<Obj>* getPrev(void) { return prev; }

    void setNext(Node<Obj>* arg) { next = arg; }
    Node<Obj>* getNext() { return next; }

    void setItem(Obj arg) { item = arg; }
    Obj getItem(void) { return item; }
};

void printNodeListDouble(Node<Point<double>>* arg) {
    Node<Point<double>>* temp = arg;

    while (temp != nullptr) {
        temp->getItem().print();
        cout << endl;
        temp = temp->getNext();
    }
}

// talk about using function returns in couts rather than couts in function returns.

int main(void) {

    // ***********************************************************************
    // ****************** Polymorphism with Linked Up Nodes ******************
    // ***********************************************************************

    cout << "\n\n*** A Node based List of new objects derived from Point ***\n " << endl << endl;
    Node<Point<double>>* head = new Node<Point<double>>();

    head->setItem(Point<double>(3.3, 5.5));
    head->setPrev(nullptr);
    head->setNext(nullptr);

    Node<Point<double>>* curr = head;

    curr->setNext(new Node<Point<double>>());  // this sets up Node 2

    curr->getNext()->setItem(Circle<double>(2.3, 4.5, 7.8)); // this sets the item in Node2
    curr->getNext()->setPrev(curr); // this connects the next pointer back to the current
    curr = curr->getNext(); // finally we can jump to the next Node, Node 2
    curr->setNext(nullptr); // I jumped to this Node before doing this nullptr for shorter code

    printNodeListDouble(head);  // notice that the Polymorphism isn't working for our Nodes


    // ***************************************************************
    // ****************** Polymorphism with Vectors ******************
    // ***************************************************************


    cout << "\n\n*** now a Vector of new objects derived from Point ***\n " << endl << endl;
    vector<Point<double>*> myList;

    myList.push_back(new Point<double>(7.9, 12.3));
    myList.push_back(new Point<double>(1.2, 3.5));
    myList.push_back(new Circle<double>(17.9, 2.3, 5.6));
    myList.push_back(new Circle<double>(4.9, 12.3, 7.8));

    while (!myList.empty()) {
        //demo polymorphism with templates here!
        myList.back()->print();
        cout << endl;
        delete myList.back();
        myList.pop_back();

    }

    // ****************************************************************
    // ****************** Polymorphism with STD List ******************
    // ****************************************************************

    cout << "\n\n*** now a STD List of new objects derived from Point ***\n " << endl << endl;
    list<Point<double>*> mySTDList;

    mySTDList.push_back(new Point<double>(7.9, 12.3));
    mySTDList.push_back(new Point<double>(1.2, 3.5));
    mySTDList.push_back(new Circle<double>(17.9, 2.3, 5.6));
    mySTDList.push_back(new Circle<double>(4.9, 12.3, 7.8));

    while (!mySTDList.empty()) {
        //demo polymorphism with templates here!
        mySTDList.back()->print();
        cout << endl;
        delete mySTDList.back();
        mySTDList.pop_back();
    }

    return(0);
}