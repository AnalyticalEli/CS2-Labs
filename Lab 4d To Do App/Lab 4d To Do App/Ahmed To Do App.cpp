//Eli Ahmed
//To Do (List) App


#include<iostream>
#include<string> //For string or possible getline
#include<vector>  //For our list below (vector is the container) 
#include<list>    //For our list below

//Remember if you're doing comparisons with stacks
//You must reset the stack to the beginning if want to
//use another. 

//For example:
//comparing values of character > RESET >   Then you set another comparison
// compareBYVALUE()               = begin()   CompareBYName()


using namespace std;


struct Task {  //Our structure is named task

	//Properties

	string myObjectives;



	//Constructor Prototype
	Task(string argO = " ");   //Initializing string as base in case user enters nothing.




	//Utility Method Prototype


	void printList(void);

	void deleteTask(list<Task*>& tasks);   //Deleting Function for our List


};




int main(void) {


	//Goal create a self automated list with User Interface User can enter (Add) values, delete values, and print them at will.

	string userChoice;

	char userInput;

	list<Task*> myTasks;  //Our List


	//Push_back is generally used for lists and vectors to add value to front.


	//User Interface

	do {  //Using a do while loop to enscapuslate ADDING the new Tasks 

		cout << "To Do List: ";
		getline(cin, userChoice);

		myTasks.push_back(new Task(userChoice));
		
		myTasks.push_back(nullptr);  //After every ptr, because we don't know how long list is we set each to nullptr after its used.
		

		cout << "Do you want to enter another task?: ";
		cin >> userInput;
		cin.ignore();   //This ensures that the loop runs smoothly and doesn't inappropriately repeat: "Do you want to enter another task." 


	} while (userInput != 'n' && userInput != 'N');
	


	//Printing the New List (Using Iterators) 

	list<Task*>::iterator itrTask;

	itrTask = myTasks.begin();   //Setting it to start at the beginning of the list



	//Outputting tasks to List 

	cout << "To Do List (currently): " << endl;
	
	for (myTasks.begin(); itrTask != myTasks.end(); itrTask++ ) {   //Starting at beginning cycles until it reaches the end.

		if (*itrTask != nullptr) { //Meaning if the task hasn't been set to a nullptr YET.

			(*itrTask)->printList();
		}
	}
	

	//This iterator above ^^^^ acts like an accumulator cycling
	//through each element of the list iteratively until it reaches 
	//the end. Specifically it only prints non nullptr values.




	//Now Giving the User the Ability to Delete tasks: 

	//Create a Task Object to delete tasks in the list.

	Task task;

	task.deleteTask(myTasks);  //This one is a LONG one so put it into a function.



	//Reprinting list (To Show how it looks AFTER DELETION)

	//Outputting tasks to List POST Deletion

	cout << "To Do List (currently): " << endl;

	//Restarting the list from the beginning to properly print out list after deleting
	for (itrTask = myTasks.begin(); itrTask != myTasks.end(); itrTask++) {   //Starting at beginning cycles until it reaches the end.

		if (*itrTask != nullptr) { //Meaning if the task hasn't been set to a nullptr YET.

			(*itrTask)->printList();
		}
	}




	//Memory Deallocation:

	for (auto taskPtr : myTasks ) {  //Because we did the nullptr section above we ONLY need to have a DELETE for every new
									 //However because nullptr was what we set the constraints to above, we're cyclcing through the 
									 //Taskptr.

		delete taskPtr;
	}


	return (0);

}


//Constructor Implemenation

Task::Task(string argO) {

	
	myObjectives = argO;

}



//Utility Methods Implementation 
void Task::printList(void) {


	cout << "Task: " << myObjectives << endl;

}


void Task::deleteTask(list<Task*>& tasks) {


	int deleteTask;

	cout << "\nEnter the index (number) of the task to delete (0 to skip) ";   //Gives user a chance to not delete anything
	cin >> deleteTask;
	cin.ignore();


	if (deleteTask > 0 && deleteTask <= tasks.size()) {  //If delete number is greater than 0, than its valued
												         //and if the deleteTask ensures doesn't not get bigger than
													     //the size of the list itself.
		
		
		auto itrTask = tasks.begin(); //Auto makes the iterator take on the form of any data type that the tasks are.



		for (int i = 0; i < deleteTask - 1; i++) {  //For loop arithmetic, the loop continues even with 
													//a deleted item from the list

			itrTask++;  //Accumulator for deleting the task 

		}

		
		//Thing to note: erase (used this in godot) in a list
		//removes the element that we specified above, and
		//adjusts the other iterators to function like they
		//did before with this difference accounted.

		
		tasks.erase(itrTask);  //Does this for the itrTask.


		cout << "The Task was deleted. " << endl;


	}
	else {  //If for whatever reason it's not able to delete task
			  //skips above. Prints no bueno, did not delete.

		cout << "Invalid index. The Task was not deleted. " << endl;

	}


}
