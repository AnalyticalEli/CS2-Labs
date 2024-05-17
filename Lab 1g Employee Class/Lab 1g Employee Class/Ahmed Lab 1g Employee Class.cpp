//Eli Ahmed
//Lab 1g Multiple Inheritance   IMPORTANT LESSON ABOUT (:) colon with multiple classes!


//Goal: Have both Person and UsCitizen class both be linked to Employee Class.


#include<iostream>
#include<string>
#include<iomanip>


using namespace std;


class Person {    //Person Base Class

private:

	string firstName, lastName;
	int age;


public:


	//Constructor

	Person(string argFirst, string argLast, int argAge);



	//Accessor Methods Prototypes

	void setFirstName(string argFirst);

	string getFirstName(void);


	void setLastName(string argLast);

	string getLastName(void);


	void setAge(int argAge);

	int getAge(void);


	//Utility Methods 

	void displayPerson(void);


};


class Uscitizen {    // : allows us to call on another class, specifically the Person Class :D


private:

	int ssn;  //ssn = Social Security Number 
	//Lord knows we don't want the user seeing this


public:


	//Constructor (If you use : to include another class you must use their info in the constructor)

	Uscitizen(int argSSN);  //Which is why we include previous
	//class info here



//Accessor Method 

	void setSSN(int argSSN);

	int getSSN(void);


	//Utility Method (For displaying info) 

	void displayUsInfo(void);


};



class Employee : public Person, public Uscitizen{  //Employee class is "inhereting" the public Person info 
												   //& Uscitizen public info via colon (:).


private:

	int employeeID;   //Employee Id is int

	double Salary;     //Employee salary is double 


public: 


	//Constructor Employee (Because it includes : UsCitizen it must have all of the info in UsCitizen constructor
	//Plus their own!


	Employee(string argFirst, string argLast, int argAge, int argSSN, int argID, double argSalary);


	//Only unique feature of constructor above is the int argID, & argSalary rest are from UsCitizen Constructor.


	//Accessor methods


	void setEmployeeID(int argID);    //Set methods for employee ID
	int getEmployeeID(void);	//Get methods for employee ID


	void setSalary(double argSalary);     //Set methods for employee ID
	double getSalary(void);  //Get methods for employee ID



	//Utility Methods for Employee Class 

	void displayEmployee(void);

};




int main(void) {


	//Instantiate 2 person objects (FirstName, Lastname, Age) 


	//Person person1{ "George", "Alcatraz", 45 };
	//Person person2{ "Alma", "Belarus", 24 };


	////2 Us citizen objects (Social Security) 

	//Uscitizen usCitizen1{110339808 };
	//Uscitizen usCitizen2{110399808 };



	//2 Employee Objects (Combines Person object + UsCitizen objects)


	Employee employee1{ "Alma", "Belarus", 45,  110339808, 3237, 1000000};

	Employee employee2{ "George", "Alcatraz", 24, 110399808, 1, 20};




	cout << "\n Employee 1 Info: " << endl;
	employee1.displayEmployee();


	

	cout << "\n Employee 2 Info: " << endl;
	employee2.displayEmployee();



	return(0);
}




//Constructor Implementation

Person::Person(string argFirst, string argLast, int argAge) {

	setFirstName(argFirst);     //Indirect access first name from get and set below

	setLastName(argLast);       //Indirect access  last name from get and set below

	setAge(argAge);				//Indirect access from age get and set below
}


Uscitizen::Uscitizen(int argSSN) {

	/*The : Person(argFirst, argLast, argAge) lets the program know the Person classes constructor info
	is being carried over to the UsCitizen constructor! Which is handy for advanced inheretance. */

	setSSN(argSSN);   //Indirect access SSN from get & set below 

}




Employee::Employee(string argFirst, string argLast, int argAge, int argSSN, int argID, double argSalary)
	: Person(argFirst, argLast, argAge), Uscitizen(argSSN) {   //Includes, Employee constructor, Person and UsCitizen)
															   //public info!


	setEmployeeID(argID);     //Indirect access EmployeeID from get & set below 

	setSalary(argSalary);	  //Indirect access Salary from get & set below 


}



//Accessor methods Implementation for Person


void Person::setFirstName(string argFirst) {   //set method of First name


	firstName = argFirst;

}

string Person::getFirstName() {

	return firstName;


}


void Person::setLastName(string argLast) {  //set method of First name

	lastName = argLast;


}

string Person::getLastName(void) {


	return lastName;


}


void Person::setAge(int argAge) {   //set method of age

	age = argAge;

}

int Person::getAge(void) {

	return age;
}


//Accessor method for US citizen


void Uscitizen::setSSN(int argSSN) {     //set method of ssn = social security

	ssn = argSSN;

}

int Uscitizen::getSSN(void) {


	return ssn;

}


//Accessor method for Employee citizen

void Employee::setEmployeeID(int argID) {

	employeeID = argID;      //Indirect access with EmployeeID = argID


}


int Employee::getEmployeeID(void) {

	return employeeID;   //Returns employeeID 

}


void Employee::setSalary(double argSalary) {


	Salary = argSalary;     //Indirect access setSalary = Salary.



}
double Employee::getSalary(void) {

	return Salary;

}



//Utility Methods for Person

void Person::displayPerson(void) {


	cout << "Classified US Citizen Info, for Jefe's eyes only!!" << endl;   //Funny message for declassified

	cout << "First Name: " << getFirstName() << endl;   //Gets the first name info from get accessor method

	cout << "Last Name: " << getLastName() << endl;   //Gets the last name info from get accessor method

	cout << "Age : " << getAge() << endl;   //Gets the age from get accessor method


}



//Utility Methods for Us Citizen


void Uscitizen::displayUsInfo(void) {

	cout << "Social Security Number: " << getSSN() << endl;


}



//Utility Methods 


void Employee::displayEmployee(void) {

	
	Person::displayPerson();   //Displays the person display info

	Uscitizen::displayUsInfo();   //Displays the UsCitizen display info


	cout << "The Employee ID is: " << getEmployeeID() << endl;

	cout << "The Salary (Big Dineros) is ($): " << fixed << setprecision(2) << getSalary() << endl;

	//Set precision forces it to be printed out properly in it's entirety.

}