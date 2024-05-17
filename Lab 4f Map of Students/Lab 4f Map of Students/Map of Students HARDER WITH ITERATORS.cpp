////Eli Ahmed
////Lab 4f Map of Students 
//
//
//#include<iostream>
//#include<list>   //For the list library itself for iterators
//#include<string>  //For possible strings 
//#include<map>    //Finally the map library
//
//
//using namespace std;
//
//
////2 classes one is the student and the other is the ID
//
////Realistically you'd want to protect student data.
//
//class Student {
//
//private:   //Properties
//
//
//	string firstName, lastName;
//
//	string gender;
//
//	int age;
//
//
//public:
//
//
//	//General Constructor (Prototype)  Initiliazing base values 
//
//	Student(string argF = "", string argL = "", string argG = "", int argA = 0);  //Setting all values = to a base case so
//	//if nothing is entered it will print out what we have here.
//
//
//
////Accessor Methods (Get and Set)
//
//	void setFirstName(string argF);
//	void setLastName(string argL);
//	void setGender(string argG);
//	void setAge(int argA);
//
//
//	string getFirstName(void);
//	string getLastName(void);
//	string getGender(void);
//	int getAge(void);
//
//
//	//Utility Methods 
//
//	virtual void display();     //Using a virtual display so all values AND not initializing = 0 so that it's not forced to be in all.
//
//};
//
//
//
//struct StudentID : public Student {
//
//	string studentID;
//
//
//	//When doing inheretence must put all parent class info first, then the current StudentID info.
//	StudentID(string argF, string argL, string argG, int argA, string argSTD = "no ID") : Student(argF, argL, argG) {
//
//		studentID = argSTD;
//	}
//
//	//For our studentID string, I put the base case as no ID if no value is input. (Makes code flexible.)
//
//
//	//Utility Methods
//
//	virtual void display();     //Using a virtual display so all values AND not initializing = 0 so that it's not forced to be in all.
//
//};
//
//
////To make this a bit more interesting we'll comparators that sort them
//
//
//
//int main(void) {
//
//
//
//	map<string, StudentID*> cosStudentMap;  //The string in the map is the data type
//	//of our key. 
//
//
////Hard Coding 5 students (elements) to the map:
//
//	cosStudentMap["Student 1"] = new StudentID{ "Altair", "Kedish", "", 20, "2222" };
//
//	cosStudentMap["Student 2"] = new StudentID{ "Altair", "Kedish", " ", 18, "2222" };
//
//	cosStudentMap["Student 3"] = new StudentID{ "Rose", "Romano", "Female", 12, "2222" };
//
//	cosStudentMap["Student 4"] = new StudentID{ "Kaylin", "Smith", "Male", 33, "2222" };
//
//	cosStudentMap["Student [REDACTED]"] = new StudentID{ "EXPUNGED", "REDACTED", "Quazar", 0, "Unknown" };
//
//
//	//As you can see above the KEY is the unique identifier of each element in the Map.
//	//Student 1, Student 2, Student 3, Student 4, Student [REDACTED] are all keys (unique identifiers)
//	//To make it easier to find the file for a map.
//
//
//
//	//Iterator that goes through each element in list
//
//
//	map<string, StudentID*>::iterator itrMap;  //This is our iterator for our map
//
//
//	//itrMap = cosStudentMap.begin();  //Initializing the map at teh beginning
//
//
//
//	//Outputting sorted Map of Students
//
//	cout << "Sorted Student Map based off COS students. " << endl;
//
//
//	//Intializing the itrMap here at the beginning because we want the loop to 
//	//ALWAYS START AT THE BEGINNING.
//
//	for (itrMap = cosStudentMap.begin(); itrMap != cosStudentMap.end(); itrMap++) {
//
//
//		cout << "Student: " << itrMap->first << endl;  //Outputs the current (since we're starting at the beginnign) 
//
//
//		itrMap->second->display();  //IT then moves the itrMap to the second position and displa
//
//
//
//		//Memory Deallocation within iterator BECAUSE we DON'T/SHOULDN'T know how long it is
//		//(GOOD PROGRAMMING PRACTICE) 
//
//		delete itrMap->second;   //
//
//		itrMap->second = nullptr;
//
//		cout << endl;
//
//	}
//
//
//
//}
//
//
//
//
//
//
//
//
//
//
//
////*************Student Constructor Implementation**************** 
//
//
//Student::Student(string argF, string argL, string argG, int argA) {
//
//	setFirstName(argF);    //Indirect access of first name
//	setLastName(argL);	   //Indirect access of last name
//	setGender(argG);	   //Indirect access of gender
//	setAge(argA);		   //Indirect access of age
//
//}
//
//
//
//
////Accessor Methods Students
//
////All SetMethods for students
//
//void Student::setFirstName(string argF) {   //Set methods for first name
//
//	firstName = argF;
//
//}
//
//void Student::setLastName(string argL) {  //Set methods for last name
//
//	lastName = argL;
//
//}
//void Student::setGender(string argG) {   //Set methods for gender
//
//	gender = argG;
//
//}
//void Student::setAge(int argA) {   //Set methods for age
//
//	age = argA;
//
//}
//
//
//
//string Student::getFirstName(void) {   //Get methods for first name
//
//	return firstName;
//
//}
//string Student::getLastName(void) {  //Get methods for last name
//
//	return lastName;
//
//}
//string Student::getGender(void) {  //Get methods for gender
//
//	return gender;
//
//}
//int Student::getAge(void) {  //Get methods for age
//
//	return age;
//
//
//}
//
//
////Utility Implemenation
//
//void Student::display() {   //To get rid of large cursor press insert
//
//	cout << "The student's first name is: " << getFirstName() << endl;
//
//	cout << "The student's last name is: " << getLastName() << endl;
//
//	cout << "The student's gender is: " << getGender() << endl;
//
//	cout << "The student's age is: " << getAge() << endl;
//
//}
//
//
//
////*************StudentID Constructor Implementation**************** 
//
//
////The constructor implemenation for the above is in the StudentID class
//
//
////Utility Method Implementation
//
//
//void StudentID::display() {     //Virtual Can't be declared outside of the class!!
//
//	Student::display();
//
//	cout << "Their studentID is: " << studentID << endl;
//
//
//}