////Eli Ahmed
////Lab 4I STL 300 Employees  (Dynamically meaning new - delete - ptrs) 
//
//#include<iostream>
//#include<string>
//#include<list>  //For our dynamic list
//#include<iomanip>  //For the setprecision in the employee salary.
//#include<ctime>		//For seeding random tiem.
//#include<cstdlib>  //For seeding random time
//
//using namespace std;
//
//
//class Person {    //Person Base Class
//
//private:
//
//	string firstName, lastName;
//	int age;
//
//
//public:
//
//
//	//Constructor
//
//	Person(string argFirst, string argLast, int argAge);
//
//
//
//	//Accessor Methods Prototypes
//
//	void setFirstName(string argFirst);
//
//	string getFirstName(void);
//
//
//	void setLastName(string argLast);
//
//	string getLastName(void);
//
//
//	void setAge(int argAge);
//
//	int getAge(void);
//
//
//	//Utility Methods 
//
//	void displayPerson(void);
//
//
//};
//
//
//class Uscitizen {    // : allows us to call on another class, specifically the Person Class :D
//
//
//private:
//
//	double ssn;  //ssn = Social Security Number 
//	//Lord knows we don't want the user seeing this
//
//
//public:
//
//
//	//Constructor (If you use : to include another class you must use their info in the constructor)
//
//	Uscitizen(double argSSN);  //Which is why we include previous
//	//class info here
//
//
//
////Accessor Method 
//
//	void setSSN(double argSSN);    //Using a double for SSN as it's more flexible.
//	double getSSN(void);			 //Using double for SSN as it's more flexible.
//
//
//	//Utility Method (For displaying info) 
//
//	void displayUsInfo(void);
//
//
//};
//
//
//
//class Employee : public Person, public Uscitizen {  //Employee class is "inhereting" the public Person info 
//	//& Uscitizen public info via colon (:).
//
//
//private:
//
//	int employeeID;   //Employee Id is int
//	double Salary;     //Employee salary is double 
//
//
//public:
//
//
//	//Constructor Employee (Because it includes : UsCitizen it must have all of the info in UsCitizen constructor
//	//Plus their own!
//
//
//	Employee(string argFirst, string argLast, int argAge, double argSSN, int argID, double argSalary);
//
//
//	//Only unique feature of constructor above is the int argID, & argSalary rest are from UsCitizen Constructor.
//
//
//	//Accessor methods
//
//
//	void setEmployeeID(int argID);    //Set methods for employee ID
//	int getEmployeeID(void);		//Get methods for employee ID
//
//
//	void setSalary(double argSalary);     //Set methods for employee ID
//	double getSalary(void);  //Get methods for employee ID
//
//
//	//Utility Methods for Employee Class 
//
//	void checkSalary(double salaryC);   //This gives us an exception if certain salaries are met
//
//	void displayEmployee(void);
//
//};
//
//
//
////C-type Function for Catching Errors 
//
////bool generationError(string);  (DELETE) 
//
//bool memoryDeallocation(string);   //Using a bool because either memory is deallocated or not (Did this for fun) 
//
//
//
//int main(void) {
//
//	cout << "Objective: Create a list of 300 Dynmaically instantiated Employees. (NO UI!) " << endl;
//
//	//char userInput;  
//
//	srand(time(0));  //Seeding random time.
//
//
//	//List
//	list<Employee*> employeeList;
//
//
//	//Made it simple but in alternate version created a list, and had a map sort the EmployeeID numbers to allow
//	//user to type & find any employee they wanted by ID after the random list was generated. (So for example if employeeID 2222 and if multiple
//	//you could either in the output or link your shell with it to find out why (throw exception), and enter your conclusion for why it happened.
//	//The program would then give you whether your response was correct or not.
//
//
//	try {   //Our for loop dynmaic Generator for the 300 PTR Objects in the employeeList, is the try
//
//
//		for (int i = 0; i < 300; i++) {   //Accumulates until right before 300
//
//
//			string firstName = "Employee" + to_string(i);  //to_string(i) adds a consective number to each....firstName0, firstName1, firstName2....etc 
//			string lastName = "Lastname" + to_string(i);   //to_string(i) adds a consective number to each....firstName0, firstName1, firstName2....etc 
//
//			int age = rand() % 53 + 18;	 //Doing first range of 0-52 (with modulus (%))
//			//then adjusting it to capture through 70 (+ 18)  SHIFTS RANGE FORWARD BY 18
//
//			double ssn = rand() % 9000000000 + 1000000000;  //This one is a little more tricky, we want a 9 digit number (so switched my int to double)
//
//
//			int employeeID = rand() % 1000 + 1;      //Starting from 0 to 1000, the + 1 shifts it to the right by 1 making it 1-1000;
//
//
//			double empSalary = rand() % 2000000 + 1;   //This gives us salary 1 - 2000000, funny exception here if salary low.
//
//			checkSalary(empSalary);
//
//
//			//Adding the new emoloyee Ptr Object to list
//
//			employeeList.push_back(new Employee(firstName, lastName, age, ssn, employeeID, empSalary));
//
//
//			//Deallocating the Employee* for each object
//			employeeList.push_back(nullptr);  //After every ptr, because we DON'T KNOW how long list is we set each to nullptr after its used.
//			//Especially before we move to the next object in employee list.
//
//
//		}
//
//		//Prints Employee Info: Still inside the try block 
//		for (auto emp : employeeList) {  //Emp Ptr Object within employeeList (auto
//
//			emp->displayEmployee();  //Displays the actual info on each "element" within the employeeList. (EVERY EMPLOYEE)b
//
//			cout << endl;
//
//		}
//
//		//Again still inside try Block
//		//Memory Deallocation
//
//		for (auto emp : employeeList) {
//
//			delete emp;  //Deleting "new" (Delete for every new)
//
//
//		}
//
//	}
//
//
//	catch (exception e) {    //If there is an error in the code above it will let the user know there was AT LEAST one not created.
//
//		cout << "Error: " << e.what() << endl;
//
//	}
//
//	return(0);
//}
//
//
//
//
////Constructor Implementation
//
//Person::Person(string argFirst, string argLast, int argAge) {
//
//	setFirstName(argFirst);     //Indirect access first name from get and set below
//
//	setLastName(argLast);       //Indirect access  last name from get and set below
//
//	setAge(argAge);				//Indirect access from age get and set below
//}
//
//
//Uscitizen::Uscitizen(double argSSN) {
//
//	/*The : Person(argFirst, argLast, argAge) lets the program know the Person classes constructor info
//	is being carried over to the UsCitizen constructor! Which is handy for advanced inheretance. */
//
//	setSSN(argSSN);   //Indirect access SSN from get & set below 
//
//}
//
//
//
//
//Employee::Employee(string argFirst, string argLast, int argAge, double argSSN, int argID, double argSalary)
//	: Person(argFirst, argLast, argAge), Uscitizen(argSSN) {   //Includes, Employee constructor, Person and UsCitizen)
//	//public info!
//
//
//	setEmployeeID(argID);     //Indirect access EmployeeID from get & set below 
//
//	setSalary(argSalary);	  //Indirect access Salary from get & set below 
//
//	//checkSalary(argSalary);   //Checks salary and throws exception if "funny business"
//
//
//
//
//}
//
//
//
////Accessor methods Implementation for Person
//
//
//void Person::setFirstName(string argFirst) {   //set method of First name
//
//
//	firstName = argFirst;
//
//}
//
//string Person::getFirstName() {
//
//	return firstName;
//
//
//}
//
//
//void Person::setLastName(string argLast) {  //set method of First name
//
//	lastName = argLast;
//
//
//}
//
//string Person::getLastName(void) {
//
//
//	return lastName;
//
//
//}
//
//
//void Person::setAge(int argAge) {   //set method of age
//
//	age = argAge;
//
//}
//
//int Person::getAge(void) {
//
//	return age;
//}
//
//
////Accessor method for US citizen
//
//
//void Uscitizen::setSSN(double argSSN) {     //set method of ssn = social security
//
//	ssn = argSSN;
//
//}
//
//double Uscitizen::getSSN(void) {
//
//
//	return ssn;
//
//}
//
//
////Accessor method for Employee citizen
//
//void Employee::setEmployeeID(int argID) {
//
//	employeeID = argID;      //Indirect access with EmployeeID = argID
//
//
//}
//
//
//int Employee::getEmployeeID(void) {
//
//	return employeeID;   //Returns employeeID 
//
//}
//
//
//void Employee::setSalary(double argSalary) {
//
//
//	Salary = argSalary;     //Indirect access setSalary = Salary.
//
//
//
//}
//double Employee::getSalary(void) {
//
//	return Salary;
//
//}
//
//
//
////Utility Methods for Person
//
//void Person::displayPerson(void) {
//
//
//	cout << "Classified US Citizen Info, for Jefe's eyes only!!" << endl;   //Funny message for declassified
//
//	cout << "First Name: " << getFirstName() << endl;   //Gets the first name info from get accessor method
//
//	cout << "Last Name: " << getLastName() << endl;   //Gets the last name info from get accessor method
//
//	cout << "Age : " << getAge() << endl;   //Gets the age from get accessor method
//
//
//}
//
//
//
////Utility Methods for Us Citizen
//
//
//void Uscitizen::displayUsInfo(void) {
//
//	cout << "Social Security Number: " << getSSN() << endl;
//
//
//}
//
//
//
////Utility Methods 
//
//void Employee::checkSalary(double salaryC) {
//
//	//Checks throw exception:
//
//	if (salaryC >= 0 && salaryC <= 1000) {   //If between 0 and 1000, gives the "truth"
//		throw exception("Tax Fraud or Offshore Account");
//	}
//	else if (salaryC >= 10000 && salaryC <= 20000)
//		throw exception("Contact HR Employee Underpaid");
//
//}
//
//
//void Employee::displayEmployee(void) {
//
//
//	Person::displayPerson();   //Displays the person display info
//
//	Uscitizen::displayUsInfo();   //Displays the UsCitizen display info
//
//
//	cout << "The Employee ID is: " << getEmployeeID() << endl;
//
//	cout << "The Salary (Big Dineros) is ($): " << fixed << setprecision(2) << getSalary() << endl;
//
//	//Set precision forces it to be printed out properly in it's entirety.
//
//}
