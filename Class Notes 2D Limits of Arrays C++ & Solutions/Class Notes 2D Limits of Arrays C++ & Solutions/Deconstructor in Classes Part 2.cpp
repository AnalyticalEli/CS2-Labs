// Destructor Call sequence for Composition
#include <iostream>
#include <string>
using namespace std;

// Simple Student Class definition
class Student {
private:
	string firstName;
	string lastName;
	int ID;

public:
	Student(); //defalult constructor
	Student(string, string, int);
	void printStudent(void);
	~Student(); //destructor
};

// Instructor Class definition with Student object as a private data member
class Instructor {
private:
	string firstName;
	string lastName;
	int ID;
	Student* assistant; // COMPOSITION HERE, Student object as member of Instructor Class!

public:
	Instructor(); //default constructor
	Instructor(string, string, int, Student*);
	void printInstructor(void);
	~Instructor(); //instructor destructor
};

int main(void) {

	// You are encouraged to experiment with this code.

	Instructor* mrJones = new Instructor("David", "Jones", 007, new Student("Juan", "Ordaz Herrera", 666)); //Spooky
	mrJones->printInstructor(); 

	cout << "\n\n *********** End of Program Tasks ***********" << endl;
	delete mrJones;

	return(0);
}



// STUDENT Implementation 
Student::Student() {
	//For testing purposes only!!
	cout << "STUDENT default constructor called" << endl;
}
Student::Student(string first, string last, int cosID) {
	firstName = first;
	lastName = last;
	ID = cosID;
}
void Student::printStudent(void) {
	cout << firstName << " " << lastName << " " << ID << endl;
}

Student::~Student() {
	//For testing purposes only!!
	cout << "STUDENT destructor called" << endl;
	cout << "Mission complete." << firstName << "'s destroyed " << endl;  
}




// INSTRUCTOR Implementation (David Jones) 
Instructor::Instructor() {
	cout << "INSTRUCTOR default constructor called" << endl;
}
Instructor::Instructor(string first, string last, int cosID, Student* arg) {
	firstName = first;
	lastName = last;
	ID = cosID;
	assistant = arg;
}
void Instructor::printInstructor(void) {
	cout << "Instructor: " << firstName << " " << lastName << " " << ID << endl;
	cout << "Assigned assistant: ";
	assistant->printStudent(); // call method from Student Class
}
Instructor::~Instructor() {
	cout << "INSTRUCTOR destructor called" << endl;
	cout << "de-allocating memory for assistant" << endl;


	//We didn't create this in the main, because it was done in the constructor for the instructor.
	delete assistant;
	assistant = nullptr;
	cout << "INSTRUCTOR de-allocation complete" << endl;
}