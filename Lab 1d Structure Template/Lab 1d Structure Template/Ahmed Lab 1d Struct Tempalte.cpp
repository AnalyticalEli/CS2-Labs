//Eli Ahmed
//Lab 1d Structure Template 

#include<iostream>
#include<vector>

using namespace std;

//Template Prototype (Using this because it is irrespective of data type) 

template<typename T>    //Template that allows us to set 3 arg (name, gender, age) is bounded by order in struct


struct Person {

	string name;     //their name
	string gender;   //their gender
	T age;			 //their age templated, because it has to change values later (float, int, double) 


	
	//Methods Prototype 

	void printDetails(void);


	bool isMinor(void);   //Returns if user is minor 


};


int main(void) {


	//Person person, person2;   Instatiating 2 Person Objects   (Original Before Templatizing Below)   


	Person<int> person{"Kumiho" , "Female", 19};      //Setting values for person via template
	Person<long>person2{ "Messi", "Male", 15};		  //Setting values for person2 via template


	cout << "Legend: False = 0, True = 1" << endl;

	cout << "\nPerson (Original) Details & Info" << endl;

	person.printDetails();   //This takes the info above about Kumiho, and inputs it into the printDetails funct


	cout << "Are they over the age of 18? " << person.isMinor() << endl;   //Checks if person (Kumiho) is a minor




	cout << "\nPerson2 Details & Info " << endl;

	person2.printDetails();   //This takes the info above about Messi, and inputs it into the printDetails funct


	cout << "Are they over the age of 18? " << person2.isMinor() << endl;   //Checks if person (Messi) is a minor


			

	Person<float> person3{ "Kumugi", "Unknown", 4000 };    //Person 3 Template


	Person<double> person4{ "Tyler ", "Male", 10.75};      //Person 4 Template



	cout << "\nPerson3 Details & Info " << endl;

	person3.printDetails();   //This takes the info above about Kumugi, and inputs it into the printDetails funct


	cout << "Are they over the age of 18? " << person3.isMinor() << endl;   //Checks if person (Kumugi) is a minor



	cout << "\nPerson4 Details & Info " << endl;

	person4.printDetails();   //This takes the info above about Tyler, and inputs it into the printDetails funct


	cout << "Are they over the age of 18? " << person4.isMinor() << endl;   //Checks if person (Tyler) is a minor




	return(0);
}





//Methods Implementation 

template<typename T>     //What this does is calls on template on top of struct (Template Implementation)

void Person<T>::printDetails(void) {     //What the <T> does is identifies, the info in the method as part of
										 //the TEMPLATE 
	

	cout << "Name is: " << name << endl;

	cout << "Gender is: " << gender << endl;

	cout << "Age is: " << age << endl;


}


template<typename T>			//What the <T> does is identifies, info below as part of Template

bool Person<T>::isMinor(void) {    //If user is minor their age should be under 18

	if (age < 18)
		return true;
	else {
		return false;
	}


}