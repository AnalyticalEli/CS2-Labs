//Class Notes 3g Polymorphism & Review


#include<iostream>
#include<vector>
#include<string>  //For string processes
#include<cmath>


using namespace std;


double PI = 3.1415926;

// Abstract Base Class **************************  Could use templates
class Shape {   //The base class here, that the other constantly use is called the "Parent Class" 

private:
	string color;


public:
	Shape(string = "");

	// pure virtual methods
	virtual double calculateArea(void) = 0;
	virtual double calculatePerimeter(void) = 0;

	//What the equal zero does forces any class that inherents from this 
	//to implement methods with these names. (

	// virtual methods
	//virtual says later classes can use these names. (THIS ALLOWS US TO REUSE FORMULAS!)
	virtual double calculateVolume(void);


};



// Concrete Classes ********************************
class Rectangle : public Shape {       //The classes that use the "Parent Class" are called the 

private:
	double length, width;

public:
	Rectangle(string, double = 0.0, double = 0.0);

	virtual double calculateArea(void);
	virtual double calculatePerimeter(void);

};



class Triangle : public Shape {  //Takes in Shape info via ihheretance (:) which is why we need string in constructor.

private:
	double a, b, c;   //Should be documented

public:
	Triangle(string, double = 0.0, double = 0.0, double = 0.0);  //Inheretence, takes in 

	virtual double calculateArea(void);
	virtual double calculatePerimeter(void);


};



class Circle : public Shape {

private:
	double r;

public:
	Circle(string, double = 0.0);

	virtual double calculateArea(void);
	virtual double calculatePerimeter(void);


};



class Cylinder : public Circle {

private:
	double h;

public:
	Cylinder(string, double = 0.0, double = 0.0);

	virtual double calculateVolume(void);

};



int main() {

	cout << "* Part 1 ***************************" << endl;
	// Vector of base class pointers (To enable polymorphism)
	vector<Shape*> myShapeList;

	//classes that inherent can be used in pointers of the base class. 

	myShapeList.push_back(new Rectangle("Red", 3, 4));   //Push back allows us to put things in the vector.
	myShapeList.push_back(new Triangle("Green", 3, 4, 5));
	myShapeList.push_back(new Triangle("Blue", 6, 8, 10));
	myShapeList.push_back(new Circle("Yellow", 2));
	myShapeList.push_back(new Cylinder("Magenta", 3, 2));

	//Object identification (at run-time)
	for (int i = 0; i < myShapeList.size(); i++) {
		cout << "Object " << i << ": " << typeid(myShapeList[i]).name() << endl;
		cout << "Object " << i << ": " << typeid(*myShapeList[i]).name() << endl;
	}

	cout << "* Part 2 ***************************" << endl;

	// polymorphism here: Is using the same function or command in multiple ways, via inheretance with classes 
	//Meaning: (Because they all share the same parent class (Shape), they can ALL use these formulas!!)
	//calculatePerimter() is being used in a few different forms below.
	cout << "Object 1: " << myShapeList.at(0)->calculatePerimeter() << endl;   
	cout << "Object 1: " << myShapeList.at(0)->calculatePerimeter() << endl;
	cout << "Object 2: " << myShapeList.at(1)->calculatePerimeter() << endl;
	cout << "Object 3: " << myShapeList.at(2)->calculatePerimeter() << endl;
	cout << "Object 4: " << myShapeList.at(3)->calculateVolume() << endl;
	cout << "Object 5: " << myShapeList.at(4)->calculateVolume() << endl;


	for (int i = 0; i < myShapeList.size(); i++) {
		// polymorphism here
		cout << "volume = " << myShapeList[i]->calculateVolume() << endl;  
	}

	cout << "* Part 3 ***************************" << endl;
	// memory management...
	while (!myShapeList.empty()) {

		cout << "Deleting " << typeid(*myShapeList.back()).name() << endl;

		delete myShapeList.back(); //deallocate memory
		myShapeList.pop_back(); // pop address off vector
		cout << "Num Shapes in vector: " << myShapeList.size() << endl;

	}

	return (0);
}

//Base Class *********************************
Shape::Shape(string argColor) {
	color = argColor;
}
double Shape::calculateVolume(void) {
	return(0);
}

//2D Shapes *********************************
Rectangle::Rectangle(string argColor, double argL, double argW) :Shape(argColor) {
	length = argL;
	width = argW;
}
double Rectangle::calculateArea(void) {
	return(length * width);
}
double Rectangle::calculatePerimeter(void) {
	return(2 * length + 2 * width);
}


Triangle::Triangle(string argColor, double argA, double argB, double argC) : Shape(argColor) {
	a = argA;  //these are sides
	b = argB;  //these are sides
 	c = argC;  //these are sides

}


double Triangle::calculateArea(void) {
	// todo look up trig formula   Hereon's Formula.
	// (s(s-a)(s-b)(s-c))  

	double s = calculatePerimeter() / 2.0;   //Using 2.0 forces it to be a double (GOOD Practice) Even when not needed like here.
	double t = s * (s - a) * (s - b) * (s - c);

	return(pow(t, 0.5));   //Power 0.5 makes t a square root.
}


double Triangle::calculatePerimeter(void) {
	return(a + b + c);
}


Circle::Circle(string argColor, double argR) : Shape(argColor) {
	r = argR;
}


double Circle::calculateArea(void) {
	return(PI * r * r);
}


double Circle::calculatePerimeter(void) {
	return(2 * PI * r);
}

//3D Shapes *********************************

Cylinder::Cylinder(string argColor, double argR, double argH) :Circle(argColor, argR) {
	h = argH;
}

double Cylinder::calculateVolume(void) {
	return(Circle::calculateArea() * h);
}



