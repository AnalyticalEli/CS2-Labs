//Eli Ahmed
//Lab 1e Student Grading with Templates


#include<iostream>
#include<string>   //For getline 
#include<iomanip>   //For the set precision to make it prettier


using namespace std;


//Templates work irrespective of data type! And they typically come before struct

template<class T>


struct Student {

	string name;
	int ID;
	T testAvg, hwAvg, finalAvg;  //Template values taht c
	
	float testWeight, hwWeight, finalWeight;

	
	//Method Prototypes

	void display(void);

	double calculateWeightedAverage(void) const;  //Must be floats


	char getGrade(void);  
};




int main(void) {

	char userResponse;  //User Response used to continue the do while loop

	Student<float> student;  //Creating a student object using TEMPLATES 


	do {       //Using a do while loop to allow user to rerun as many times as they want

		
		//User Interface

		cout << "\nEnter the student name: ";
		getline(cin, student.name);

		
		cout << "Enter the student ID: ";
		cin >> student.ID;

		cout << "Enter the test weight. (as a decimal, ie: 0.93, 0.88) : ";
		cin >> student.testWeight;


		cout << "Enter the homework weight. (as a decimal, ie: 0.93, 0.88): ";
		cin >> student.hwWeight;

		cout << "Enter the final exam weight: (as a decimal, ie: 0.93, 0.88) ";
		cin >> student.finalWeight;


		cout << "Enter the test average: ";
		cin >> student.testAvg;


		cout << "Enter the homework average: ";
		cin >> student.hwAvg;

		cout << "Enter the final exam weight: ";
		cin >> student.finalAvg;

		

		//This displays everything nicely, with the display funct below

		student.display();



		cout << "Do you want to enter different values for grades? (Y or N)";
		cin >> userResponse;

		cin.ignore();  //So responses don't overlap 

	}while (userResponse != 'N' && userResponse != 'n');



}


//Method Implementations (Need to put template class T, on each for template implementation)

template<class T>
void Student<T>::display(void) {


	cout << "Name: " << name << endl;

	cout << "ID: " << ID << endl;

	cout << "Test Average: " << fixed << setprecision(2) << testAvg << endl;

	cout << "Homework Average: " << fixed << setprecision(2) << hwAvg << endl;

	cout << "Final Average: " << fixed << setprecision(2) << finalAvg << endl;

	cout << "Weighted Average " << fixed << setprecision(2) << calculateWeightedAverage() << endl;

	cout << "Grade: " << getGrade() << endl;


}


template<class T>
double Student<T>::calculateWeightedAverage(void) const {   //Const to make sure this value doesn't change 

	//Calculation for weighted average in paranthesis. 

	double weightedSum = hwWeight * hwAvg + testWeight * testAvg + finalWeight * finalAvg;


	double sumOfWeights = hwWeight + testWeight + finalWeight;  //Sum of the weights


	//This gives our average for class, as we divide the weightedSum by the sumOfweights to get average grade.

	return(weightedSum / sumOfWeights);


}



template<class T> 
char Student<T>::getGrade(void) {

	//double weightedAvg = calculateWeightedAverage();   //Rounding function, in case you wanted to add a curve.

	//int roundedAverage = int(weightedAvg + 0.5);



	if (calculateWeightedAverage() >= 90) {

		return 'A';
	}

	else if (calculateWeightedAverage() >= 80) {

		return 'B';

	}

	else if (calculateWeightedAverage() >= 70) {

		return 'C';

	}

	else if (calculateWeightedAverage() >= 60) {

		return 'D';

	}
	else {
		return 'F';
	}


}
