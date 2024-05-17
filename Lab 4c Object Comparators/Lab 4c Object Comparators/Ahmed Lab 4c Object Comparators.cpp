//Eli Ahmed
//Lab 4c Object Comparators   (For every new there must delete, for every Ptr there must be nullptr)


#include<iostream>
#include<string>
#include<list>  //For the comparators to sort values and for printList
#include<vector>  //For vector below for circle objects


using namespace std;


struct Circle {  //Parent class circle has two properties color & radius


	string colour;

	double radius;


	//Constructor Prototype

	//Initilizing values
	Circle(string argC = "", double argR = 0);


};


//Comparators (These are used to compare a certain property of a class)


bool compareColour(Circle* arg1, Circle* arg2);  //Compares all colours


bool compareRadius(Circle* arg1, Circle* arg2);  //Compares all raiduses




int main(void) {   //For every new there must delete, for every Ptr there must be nullptr


	list<Circle*> myCircles;  //Using the ptr of Circle,
							  //MUST USE LIST TO USE .sort() !!



	myCircles.push_back(new Circle("Red", 22.0));
	myCircles.push_back(new Circle("Red", 443));
	myCircles.push_back(new Circle("Red", 33));
	myCircles.push_back(new Circle("Red", 89));
	myCircles.push_back(new Circle("Green", 62.77));


	myCircles.sort(compareColour);  //This sorting allows us to specifically
								    //compare list, by specific criteria
									//In this case its by compareColour. (Colour)
							        //1st Comparison


	list<Circle*>::iterator itrCircle; // we'll use this to iterate through Loot in our Map

	itrCircle = myCircles.begin(); // temporarily using it to work with a loot list before our Map


	//Outputting the sorted circles (Colour)

	cout << "Sorted circles based on colour " << endl;

	for (myCircles.begin(); itrCircle != myCircles.end(); itrCircle++) {  //Starts at beginning of list the goes to end, 
																		  //by each item in the list.

		cout << "Colour: " << (*itrCircle)->colour << ", Radius:\t" << (*itrCircle)->radius << endl;


	}


	//Outputting the sorted circles (Radius)

	myCircles.sort(compareRadius);  //2nd Comparison 


	cout << "\nSorted cirlces based on radius: " << endl;

	//Keep in mind you must reset the itrCircle = myCircles.begin()) EVERYTIME YOU COMPARE SOMETHING NEW
	for (itrCircle = myCircles.begin(); itrCircle != myCircles.end(); itrCircle++) {  //Restarts at beginning of list the goes to end, 
																					  //by each item in the list.

		cout << "Colour: " << (*itrCircle)->colour << ", Radius:\t" << (*itrCircle)->radius << endl;


	}



	//Memorory Management. (Do to PTR & New Keyword) 

	for (auto circles : myCircles) {   //Don't want to have you overdose with autos so only using 1!
									  //Goes over each new circle PTR in the list and treats them as an individual element 
									  //of an array, which helps data deallocation work regardless of datatype in list.
								

		delete circles;   //Deletes each individual circle ("Element")

		circles = nullptr;  //Sets the Ptr of circle to nullptr for each.

	}
}




//Constructor Implementation

//Setting values
Circle::Circle(string argC, double argR){  //Initialized above, no need to do it again in constructor Implemenatation

	colour = argC;

	radius = argR;

}



//Comparator Implemenation


bool compareColour(Circle* arg1, Circle* arg2) {  //Compares all colours

	bool answer = (arg1->colour < arg2->colour); //We're returning colours from list in alphabetical order
	return answer;

}


bool compareRadius(Circle* arg1, Circle* arg2) {  //Compares all raiduses


	bool answer = (arg1->radius < arg2->radius); //We're returning a list from least to greatest
	return answer;



}