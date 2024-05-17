// CSCI 002 Spring 2024 Lecture Day 03
// Professor David Jones, 1/29/2024

#include <iostream>
#include <string>
#include <vector>
using namespace std;
const double PI = 3.14159;  // global constant

//Abstract base class shape, can't create objects.  Shape is an ADT
// ADT = Abstract Data Type
class Shape {    //Too vague is often used for the parent/base class
private:
    string color;

public:
    Shape(string argColor = "transparent");

    void setColor(string);
    string getColor(void);

    // virtual methods can be implemented in derived 
    // if it's set equal to zero, it must be implement in a derived class.
    virtual double calculatePerimeter() = 0;  //"virtual" allows us to have double of the same name.
                                              //For example: double Cat, and virtual double Cat.
    
    // you must do this in any class that uses this
    // = 0 is making it an abstract base class.
    // virtual method has implementation but can be overridden
    virtual void displayInfo(void);

}; 
//Too vague is often used for the parent/base class

//derived classes, concrete classes
class Circle : public Shape {
private:
    double radius;

public:
    Circle(string = "transparent", double = 0.0); //constructor

    // accessor methods
    void setRadius(double r);
    double getRadius();

    // utility methods; required to be implemented
    double calculatePerimeter();  //must have this one from base class having = 0 on ot
    double calculateArea();
    void displayInfo();   //This is voluntary because it doesn't have zero on it.

};
//Circle(string argColor, double argRadius);

class Triangle : public Shape {
private:
    double side;
public:
    Triangle(string = "transparent", double = 0.0); //constructor

    // accessor methods
    double getSide(void);
    void setSide(double);

    // utility methods; required to be implemented
    double calculatePerimeter();
    double calculateArea();
    void displayInfo();

};
//Triangle(string argColor, double argSide);

class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double argL = 0, double argW = 0, string argC = "transparent");

    double getLength(void);
    double getWidth(void);

    void setLength(double argL);
    void setWidth(double argW);

    double calculatePerimeter();
    double calculateArea();
    virtual void displayInfo(void);
};
//Rectangle(double argLength, double argWidth, string argColor);

class Box : public Rectangle {
private:
    double height;
public:
    Box(double argL = 0, double argW = 0, double argH = 0, string argC = "transparent");

    double getHeight(void);
    void setHeight(double argH);

    double calcSurfaceArea(void);
    double calcVolume(void);

    void displayInfo(void);
};
//Box(double argLength, double argWidth, double argHeight, string argColor);



// Cube Constructor line 330 ish after setting up Class, maybe do a Sphere?


// *******************************************************************************
// **********************************  Main  *************************************
// *******************************************************************************



int main(void) {
    const int size = 3;



    //Shape myShape ("blue") 



    //Shape arr[3];   //Doesn't work, Single instatiation doesn't work so array doesn't work either.

    Shape* arr[5];   //This works, because Shape* (a pointer) is an address, arrays work with addresses.

    arr[0] = new Circle("blue", 10); //Once array is declared as address of shapes, we have to use ne to tell 
    //what's in it.


    arr[1] = new Box(1.1, 2.2, 3.3, "red");      //New box  (old below)
    arr[2] = new Rectangle(5.4, 12.3, "white");    // New Rectangle (Old below)
    arr[3] = new Triangle("aquamarine", 5.201);  //New Triangle  (old below)
    arr[4] = new Box(3, 4, 5, "grey");           //New box  (old below)



    for (int i = 0; i < 5; i++) {

        (*arr[i]).displayInfo();   //This is dereferecing operator IN an ARRAY (WOW!!)

        cout << endl;

        //arr[i] - > displayInfo();

        cout << endl << "*************" << endl;

    }


    //This loop ABOVE shows idea of polymorphism through inheretence 
    //And ut accesses display, info from 4 different classes all with teh same command.
    //Arrays are limited. Which is why we're using vectors.



    //Rectangle myRect(5.4, 12.3, "blue");  //This is our original Rectangle
    //myRect.displayInfo();

    //cout << endl << endl;               // //This is our original box
    //Box theBox(1.1, 2.2, 3.3, "red");
    //theBox.displayInfo();

    //cout << endl << endl;
    //Circle myCirc("red", 10);
    //myCirc.displayInfo();

    //cout << endl << endl;
    //Triangle myTri("yellow", 2.4);
    //myTri.displayInfo();



    //BELOW are OUR VECTOR EXAMPLES!!  (Vectors are better than arrays.)

    vector<Shape> myShapes;
    myShapes.push_back(new Circle("blue", 10));    //Just setting old values above into vectors. For all these.
    myShapes.push_back(new Box(1.1, 2.2, 3.3, "red"));
    myShapes.push_back(new Rectangle(5.4, 12.3, "white"));
    myShapes.push_back(new Triangle("maroon", PI));


    for (int i = 0; i < myShapes.size(); i++) {

        //myShapes[i]->displayInfo();

        //Another way doing above is
        cout << endl << endl;

        myShapes.at(i)->displayInfo(); //I like this one better.





        cout << typeid(*myShapes.at(i)).name() << endl;

        if typeid(*myShapes.at(i)).name() == "Triangle"){



        } //not working yet, look up later


        cout << endl << "****************" << endl;

       

    }

    //Another display of polymorphimism. Super handy command to rule them all.


    //Now we need to do some memory managment (above takes alot of space)
    //To do this we need to 1) Delete Shape stored, and 2) Want to shorten vector

    //Probably want to start at the end of the vector so use the vector.back()

    //Two ways: Delete then pop (which deletes the info and removed it)

    //Pop and delete (takes the whole thing and takes it off the vector, and deletes) WHICH IS BAD, DO NOT DO!!
    //Might be why megaman/metroid enemies respawn in older video games.
    
    for (int j = myShapes.size() - 1; j >= 0; j++) {  //Goes down the list deleting then popping (good practice) 


        //Delete the shape first 

        cout << typeid(*myShapes.at(j)).name() << endl;

        delete.myShapes.back();

        //pop_back to shorten vector

        myShapes.pop_back();

    }


    //Project for Thursday Night. 7:15 - Finished.

    //Your game that you're making, 
    // Base class monster (properties are health (double), armour rating, loot table, damage type)
    // Which of tehse should be forced to children classes? All of them.
    // base class off of moster that says "trash mob" or boss mob
    // Zombie trash loot, evil humans/knights, wizards or sorcerer, rogue. 





    {

        //memory management  start at back and work forward, start at front and work back.
        /*for (int i = myShapes.size()-1; i >=0; i--){
            cout << "Deleting " << typeid(*myShapes.back()).name() << endl;

            delete myShapes.back();
            myShapes.pop_back();

            cout << endl << endl;
        }*/

        //for (int i = 0; i < myShapes.size(); i++) {
        //    cout << "Deleting " << typeid(*myShapes.front()).name() << endl;

        //    delete myShapes.front();
        //    myShapes.pop_front();  //lists allow go forward, backward, add shit in the middle
        //    cout << endl << endl;
        //}
    } // 
    // hidden code I may want to reference during lecture 
    cout << endl << endl;
    cout << "****************************" << endl;
    cout << "****************************" << endl;
    cout << "****************************" << endl << endl << endl;

    cout << endl << endl << endl;
    return(0);
}


// *******************************************************************************
// ******************************Shape implementations ***************************
// *******************************************************************************

Shape::Shape(string argColor) {
    setColor(argColor);
}
void Shape::setColor(string arg) {
    color = arg;
}
string Shape::getColor(void) {
    return(color);
}
void Shape::displayInfo(void) {
    cout << "Color: " << getColor() << endl;
}


// *******************************************************************************
// **************************** Circle implementations ***************************
// *******************************************************************************

Circle::Circle(string argColor, double argRadius) :Shape(argColor) {
    //Shape::setColor(argColor); 
    setRadius(argRadius);
}

void Circle::setRadius(double r) {
    if (r < 0)
        r = -1.0 * r;
    radius = r;
}

double Circle::getRadius() {
    return radius;
}

double Circle::calculatePerimeter() {
    return 2 * PI * getRadius();
}

double Circle::calculateArea() {
    return  PI * getRadius() * getRadius();
}

void Circle::displayInfo() {

    cout << "Circle Properties" << endl;
    Shape::displayInfo();
    cout << "Radius = " << getRadius() << " units " << endl;
    cout << "Circumference = " << calculatePerimeter() << " units " << endl;
    cout << "Area = " << calculateArea() << " square units " << endl;
}

