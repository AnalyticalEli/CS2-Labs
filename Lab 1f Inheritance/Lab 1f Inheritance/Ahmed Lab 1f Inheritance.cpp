//Eli Ahmed
//Lab 1f Inheritance  (Made this fun, and a little more difficult than prompt) IMPORTANT LESSON ABOUT (:) colon


#include<iostream>
#include<string>


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


class Uscitizen : public Person {    // : allows us to call on another class :D
	
	
private:

	int ssn;  //ssn = Social Security Number 
			  //Lord knows we don't want the user seeing this


public:


	//Constructor (If you use : to include another class you must use their info in the constructor)

	Uscitizen(string argFirst, string argLast, int argAge, int argSSN);  //Which is why we include previous
																		 //class info here



	//Accessor Method 

	void setSSN(int argSSN);

	int getSSN(void);


	//Utility Method (For displaying info) 

	void displayUsInfo(void);


};




int main(void) {


	//Instantiate 2 person objects


	Person person1{"George", "Alcatraz", 45};

	Person person2{"Alma", "Belarus", 24};


	//3 Us citizen objects

	Uscitizen usCitizen1{ "George", "Alcatraz", 45, 110339808 };

	Uscitizen usCitizen2{ "Alma", "Belarus", 24, 110399808 };

	Uscitizen usCitizen3{"[EXPUNGED]", "[REDACTED]" , 78, 160339808};


	//Citizens

	cout << "Person 1 Classified " << endl;  //displaypersoninfo person 1 (without social) 
	person1.displayPerson();

	cout << "\nPerson 1 Declassified" << endl;   //displayusinfo person 1 (with social) 
	usCitizen1.displayUsInfo();

	

	cout << "\nPerson 2 Classified " << endl;  //displayPersonInfo Person 2 (Without social) 
	person2.displayPerson();


	cout << "\nPerson 2 Declassified" << endl;   //displayUsInfo Person 2 (With social) 
	usCitizen2.displayUsInfo();


	cout << "\nOperative Declassified" << endl;   //displayUsInfo Operative (With social) 
	usCitizen3.displayUsInfo();



	return(0);
}




//Constructor Implementation

Person::Person(string argFirst, string argLast, int argAge) {

	setFirstName(argFirst);     //Indirect access first name from get and set below

	setLastName(argLast);       //Indirect access  last name from get and set below

	setAge(argAge);				//Indirect access from age get and set below
}


Uscitizen::Uscitizen(string argFirst, string argLast, int argAge, int argSSN) : Person(argFirst, argLast, argAge) {   
							
	/*The : Person(argFirst, argLast, argAge) lets the program know the Person classes constructor info
	is being carried over to the UsCitizen constructor! Which is handy for advanced inheretance. */

	setSSN(argSSN);

}




//Accessor methods Implementation


void Person::setFirstName(string argFirst) {   //set method of First name


	 firstName = argFirst;

}

string Person::getFirstName(){

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


void Uscitizen::setSSN(int argSSN) {     //set method of ssn = social security

	ssn = argSSN;

}


//Accessor method for US citizen

int Uscitizen::getSSN(void) {


	return ssn;

}


//Utility Methods for Person

void Person::displayPerson(void) {

	 
	cout << "First Name: " << getFirstName() << endl;   //Gets the first name info from get accessor method

	cout << "Last Name: " << getLastName() << endl;   //Gets the last name info from get accessor method

	cout << "Age : " << getAge() << endl;   //Gets the age from get accessor method


}



//Utility Methods for Us Citizen & vicariously Person


void Uscitizen::displayUsInfo(void) {

	cout << "Classified US Citizen Info, for Jefe's eyes only!!" << endl;   //Funny message for declassified

	Person::displayPerson();   //This allows us to display the Person info above, by scooping it INSIDE UsCitizen!

	cout << "Social Security Number: " << getSSN() <<  endl;


}