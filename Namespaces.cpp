//Main CPP Code that GusGus and Jefe are being used in.
//Calling from Header files, because they're storing the info
//in the Resource CPP files for both Jefe and GusGus.

#include "gusgus.h"
#include "jefe.h"


int main(void) {

    //Three points of triangle from GusGus.
    gus::Point obj1(0, 0);  ///GusGus Code gives us the x & y values, but like this x = ... & y = ...              GusGus gives us the points in (x,y) 
    gus::Point obj2(3, 0);
    gus::Point obj3a(0, 3);  


    //Jefe's Code gives us the points in (x,y), SAME AS GusGus but just different form.
    jefe::Point obj3b(0, 3);  

    cout << "This is Gus's print" << endl;
    obj3a.print();

    cout << endl << endl << "This is Jefe's print" << endl;
    obj3b.print();


    //Both give us calculation, (OF ANGLE) BUT since GusGus has all 3 points of the triangle, we're 
    //using FUNCTION in the gusgus.cpp file to make the calculation!
    cout << endl << endl;
    cout << "Angle generated from the (0,3) point is: " << gus::angleMaker(obj1, obj2, obj3a) << endl << endl;
    
    
    
    //Point obj2 = obj1;

    //// Chained function calls.  All calls modify the same object 
    //// as the same object is returned by reference 
    //obj1.setX(10).setY(20);  // f(g(x)) compound functions

    //obj1.print();

    //obj2.displayPoints(&obj1);

    //spawning asteroids
    //Asteroid* xPtr = new Asteroid(10, "red"); //constructor call
    //Asteroid* yPtr = new Asteroid(20, "green");
    //Asteroid* zPtr = new Asteroid(30, "blue");

    //want the asteroid count independent of an object
    //printAsteroidCount();

    //delete xPtr; //destructor call -- NOT DELETING THE VARIABLE - you are deallocating the memory to which it points
    //delete yPtr;
    //delete zPtr;

    //printAsteroidCount();

    //xPtr = new Asteroid(5, "purple"); //constructor call
    //printAsteroidCount();

    return 0;

}
