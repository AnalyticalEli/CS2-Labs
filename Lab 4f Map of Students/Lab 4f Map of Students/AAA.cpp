////Eli Ahmed
////Lab 4f Map of Students 
//
//
//#include<iostream>
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
//	StudentID(string argF, string argL, string argG, int argA, string argSTD = "no ID") : Student(argF, argL, argG, argA) {
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
//	char userInput;
//	string studentId;
//
//	map<string, StudentID*> cosStudentMap;  //The int in the map is the data type
//	//of our key. 
//
//
////Hard Coding 5 students (elements) to the map:
//
//	cosStudentMap["4000"] = new StudentID{ "Altair", "Kedish", "NB", 20, "2222312" }; 
//
//	cosStudentMap["4003"] = new StudentID{ "Dryon", "Lemik", "Female", 18, "2332111" };
//
//	cosStudentMap["4010"] = new StudentID{ "Rose", "Romano", "Female", 12, "2222332" };
//
//	cosStudentMap["4011"] = new StudentID{ "Kaylin", "Smith", "Male", 33, "9932777" };
//
//	cosStudentMap["[REDACTED]"] = new StudentID{ "EXPUNGED", "REDACTED", "Quazar", 0, "Unknown" };
//
//
//	//As you can see above the KEY is the unique identifier of each element in the Map.
//	//Student 1, Student 2, Student 3, Student 4, Student [REDACTED] are all keys (unique identifiers)
//	//To make it easier to find the file for a map.
//
//	do {
//
//
//		cout << "Enter an ID Number you want to see ";
//		getline(cin, studentId);
//
//		//Using an iterator to find the desired ID 
//
//		map<string, StudentID*>::iterator itrMap;  //Try putting otuisde loop
//
//
//
//		bool found = false;  //Intialising a found variable, that scouts the map.
//							 //It will continue to stay false until told otherwise
//
//
//		//Intializing the itrMap here at the beginning because we want the loop to 
//    	//ALWAYS START AT THE BEGINNING.
//		for (itrMap = cosStudentMap.begin(); itrMap != cosStudentMap.end(); itrMap++) {
//			if (itrMap->first == studentId) {
//				cout << "Student Found! " << endl;
//				itrMap->second->display();
//				found = true;   //Because our value was thankfully found we now change it to true. (WITHOUT THIS THE VALUES PRINT INCONSISTENTLY)
//				break;
//			}
//		}
//
//
//		if (!found) {   //If found is false, meaning the bool found is NOT TRUE.
//			cout << "Student Not Found In Database. " << endl;
//		
//		
//		} //End of the for loop where user looks for values (IDs).
//
//
//		//Memory Deallocation within do while loop BECAUSE we DON'T/SHOULDN'T know how long it is + user is rerunning it constantly.
//		//(GOOD PROGRAMMING PRACTICE) 
//
//		//Starting the iterator for map back at the beginning
//		for (auto itrMap = cosStudentMap.begin(); itrMap != cosStudentMap.end(); itrMap++) {
//
//			delete itrMap->second;   //Deleting the ItrMap ptr point at second which displays values above. (IF ID is there)
//
//			itrMap->second = nullptr;   //Setting the ptr equal to nullptr; (
//			//So there are no hanging ptrs.
//
//
//		}
//
//		cosStudentMap.clear();  //Empties Map by key values
//
//
//
//		cout << "Do you want to search for more Student ID numbers?: (y or n)  ";
//		cin >> userInput;
//		cin.ignore();  //So rerunning won't break the loop 
//
//
//	} while (userInput != 'N' && userInput != 'n');  //Loop will continue until user enters N
//
//
//
//
//	//Memory Deallocation 
//
//
//
//	return(0);
//
//}
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
//	Student::display();  //Displays values from Student display first
//
//	cout << "Their Banner studentID is: " << studentID << endl;
//
//
//}