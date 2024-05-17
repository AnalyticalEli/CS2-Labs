// Notes on keywords: new and delete

#include <iostream>
using namespace std;

/*************************************************************************/
// This header would be saved as: Line.h

class Line {

private:
	double m; // Slope 
	double b; // y-value of y-intercept

public:
	Line(double m = 0.0, double b = 0.0); // default constructor or assigns 
	
	//Accessor Methods     (Implicitly retrieves info)
	void setSlope(double);
	double getSlope();
	void setYint(double);
	double getYint();


	//Utility Methods  (Preforms calculation) 
	void printLine();


	// destructor  (Deallocates memory)  

	~Line(); 

};

/*************************************************************************/
//#include "Line.h" 

int main(void) {


	Line f(2, 3), g;   //Here we're stuck with f and g for the life of the program.

	f.printLine();
	cout << endl;
	g.printLine();
	cout << "\n" << endl;
	/********************************/

	/* Part 2******************************************/
	double m, b;
	//Line* linePtr;   //This is our linePtr (points to address)


	//User Interface below

	cout << "Enter m for your line: ";    
	cin >> m;

	cout << "Enter b for your line: ";
	cin >> b;

	Line* linePtr = new Line(m, b);  //This is our linePtr (points to address), of the values of the slope (m)
									 //and y-intercept(b)




	linePtr->printLine();  //This is the same as deferenceing the line below.
	cout << endl;
	(*linePtr).printLine();  //Same as the linePtr OR arrow (->) above. 
	cout << "\n" << endl;
	 
	f. ~Line();   //Dellocates F 
	g. ~Line();   //Deallocates G


	delete linePtr;    //This is a free call to the destructor in Class.
	linePtr = NULL;		//Sets Null equal to NULL WHICH IS GOOD PRACTICE.


	/********************************************/

	/* Part 3****************************************************/
	//An array of Lines called lineArray instantiated at runtime (Resizable Arrays!?!)
	int n;

	cout << "How many lines in your list? ";
	cin >> n;

	// user defined array size!
	Line* lineArray = new Line[n];


	// input Line list
	for (int i = 0; i < n; i++) {
		cout << "Enter m's and b's for line: " << i + 1 << ": ";
		cin >> m >> b;

		lineArray[i].setSlope(m);
		lineArray[i].setYint(b);
	}
	cout << endl;


	// output Line list
	for (int j = 0; j < n; j++) {
		cout << "Line " << j + 1 << " is ";
		lineArray[j].printLine();
		cout << endl;
	}
	cout << "\n" << endl;

	delete[] lineArray;
	cout << int(lineArray) << endl;
	lineArray = NULL;
	/*****************************************************/


	return (0);
}


/*************************************************************************/

// This would be saved as: Line.cpp (This is the implementation file)
Line::Line(double mm, double bb) {
	setSlope(mm);
	setYint(bb);
}

void Line::setSlope(double slope) {
	m = slope;
}

void Line::setYint(double yint) {
	b = yint;
}

double Line::getSlope(void) {
	return(m);
}

double Line::getYint(void) {
	return(b);
}

void Line::printLine(void) {
	cout << "y = " << getSlope() << "x + " << getYint();
}

Line::~Line() {

	// destructor, we can populate with comments.

	cout << "Boom,Line Terminated." << endl;



}
