//Eli Ahmed
//Lab 1C Function Templates   (Templates are useful, because they work no matter the data type) 


#include<iostream>


using namespace std;


//C-type Templates Prototype


template <typename T>    //Smallest Elements 
T minElement(T arg1, T arg2);



template <typename T>    //Largest Element
T maxElement(T arg1, T arg2);




int main(void) {

	cout << "The awesome thing about templates is that data type is IRRELEVANT! " << endl;

	//With all you only need to declare data type once, as long as you put (,) between them.


	double num1 = 10.5, num2 = 33.44;  

	cout << "The minimum between " << num1 << " and " << num2 << " is " << minElement(num1, num2) << endl;

	cout << "The maximum between " << num1 << " and " << num2 << " is " << maxElement(num1, num2) << endl;


	int num3 = 99, num4 = 23;


	cout << "The minimum between " << num3 << " and " << num4 << " is " << minElement(num3, num4) << endl;

	cout << "The maximum between " << num3 << " and " << num4 << " is " << maxElement(num3, num4) << endl;



	char char1 = 'n', char2 = 'z';  //This takes ASCII values and evalautes which is higher for max, & lower for min

	cout << "The minimum between " << char1 << " and " << char2 << " is " << minElement(char1, char2) << endl;

	cout << "The maximum between " << char1 << " and " << char2 << " is " << maxElement(char1, char2) << endl;




	string string1 = "El Jefe", string2 = "A Pleb";  //With strings you only need to declare data type once.


	cout << "The minimum between " << string1 << " and " << string2 << " is " << minElement(string1, string2) << endl;

	cout << "The maximum between " << string1 << " and " << string2 << " is " << maxElement(string1, string2) << endl;

	return(0);

}





//C-type Template Function Implementation



template <typename T> 
T minElement(T arg1, T arg2) {   

	if (arg1 < arg2)
		return arg1;     //As this returns smallest value

	else {
		return arg2;

	}



}



template <typename T>
T maxElement(T arg1, T arg2) {   

	if (arg1 < arg2)
		return arg2;   //Because max element returns larger value

	else {

		return arg1;   //Meaning if arg2 is smaller, return arg1

	}


}
