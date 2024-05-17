//Eli Ahmed 
//Exam 2 

#include<iostream>
#include<string>
#include<map>

using namespace std;


//2 classes one is the student and the other is the ID

//Realistically you'd want to protect student data.

class Artists {

private:   //Properties


	string firstName, lastName;

	string gender;

	int age;


public:


	//General Constructor (Prototype)  Initiliazing base values 

	Artists(string argF = "", string argL = "", string argG = "", int argA = 0);  //Setting all values = to a base case so
	//if nothing is entered it will print out what we have here.



//Accessor Methods (Get and Set)

	void setFirstName(string argF);
	void setLastName(string argL);
	void setGender(string argG);
	void setAge(int argA);


	string getFirstName(void);
	string getLastName(void);
	string getGender(void);
	int getAge(void);


	//Utility Methods 

	virtual void display();     //Using a virtual display so all values AND not initializing = 0 so that it's not forced to be in all.

};



struct Songs : public Artists {

	string songLink;


	//When doing inheretence must put all parent class info first, then the current StudentID info.
	Songs(string argF, string argL, string argG, int argA, string argSong = "no Song") : Artists(argF, argL, argG, argA) {

		songLink = argSong;
	}

	//For our studentID string, I put the base case as no ID if no value is input. (Makes code flexible.)


	//Utility Methods

	virtual void display();     //Using a virtual display so all values AND not initializing = 0 so that it's not forced to be in all.

};



int main(void) {

	char userInput;
	string songNom;

	map<string, Songs*> songLink;  //The int in the map is the data type
	//of our key. 


//Hard Coding 6 students (elements) to the map:

	songLink["[SampleName]"] = new Songs{ "Altair", "Kedish", "NB", 20, "2222312" };  //With ID numbers 

	songLink["[SampleName2"] = new Songs{ "Dryon", "Lemik", "Female", 18, "2332111" };

	songLink["[SampleName3]"] = new Songs{ "Rose", "Romano", "Female", 12, "2222332" };

	songLink["[SampleName4]"] = new Songs{ "Kaylin", "Smith", "Male", 33, "9932777" };

	songLink["[SampleName5]"] = new Songs{ "EXPUNGED", "REDACTED", "Quazar", 0, "Unknown" };

	songLink["[SampleName6]"] = new Songs{ "Funny", "Guy", "N/A", 26, "2334423" };   //With email 
	//One with email just to prove that I understand 


	//As you can see above the KEY is the unique identifier of each element in the Map.
	//Student 1, Student 2, Student 3, Student 4, Student [REDACTED] are all keys (unique identifiers)
	//To make it easier to find the file for a map.

	do {


		cout << "Enter an song name you want to check. ";
		getline(cin, songNom);

		//Using an iterator to find the desired ID 

		map<string, Songs*>::iterator itrMap;  //Try putting otuisde loop



		bool found = false;  //Intialising a found variable, that scouts the map.
		//It will continue to stay false until told otherwise


		//Intializing the itrMap here at the beginning because we want the loop to 
		//ALWAYS START AT THE BEGINNING.
		for (itrMap = songLink.begin(); itrMap != songLink.end(); itrMap++) {
			if (itrMap->first == songNom) {
				cout << "Song Found! " << endl;
				itrMap->second->display();
				found = true;   //Because our value was thankfully found we now change it to true. (WITHOUT THIS THE VALUES PRINT INCONSISTENTLY)
				break;
			}

			if (songNom == "Rick Roll") {

				cout << "You asshole " << endl;

				cin.  //Use command that forces user to type enter to go forward

				cout << "We're " << endl;
				cin.  //Use command that forces user to type enter to go forward

				cout << "no" << endl;
				cin.  //Use command that forces user to type enter to go forward

				cout << "strangers " << endl;
				cin.  //Use command that forces user to type enter to go forward

				cout << "love" << endl;

				cin.  //Use command that forces user to type enter to go forward

				cout << "Regretting it now? ";

				cin.  //Use command that forces user to type enter to go forward

				cout << "Too bad, you must pay for your sins :)" << endl;

				cin.  //Use command that forces user to type enter to go forward



				
			}
		}

		if(songLink == )
		if (!found) {   //If found is false, meaning the bool found is NOT TRUE.
			cout << "Song not found in playlist. " << endl;


		} //End of the for loop where user looks for values (IDs).


		//Memory Deallocation within do while loop BECAUSE we DON'T/SHOULDN'T know how long it is + user is rerunning it constantly.
		//(GOOD PROGRAMMING PRACTICE) 

		//Starting the iterator for map back at the beginning
		for (auto itrMap = songLink.begin(); itrMap != songLink.end(); itrMap++) {

			delete itrMap->second;   //Deleting the ItrMap ptr point at second which displays values above. (IF ID is there)

			itrMap->second = nullptr;   //Setting the ptr equal to nullptr; (
			//So there are no hanging ptrs.


		}

		songLink.clear();  //Empties Map by key values



		cout << "Do you want to search for more Songs?: (y or n)  ";
		cin >> userInput;
		cin.ignore();  //So rerunning won't break the loop 


	} while (userInput != 'N' && userInput != 'n');  //Loop will continue until user enters N or n



	return(0);

}




//*************Student Constructor Implementation**************** 


Artists::Artists(string argF, string argL, string argG, int argA) {

	setFirstName(argF);    //Indirect access of first name
	setLastName(argL);	   //Indirect access of last name
	setGender(argG);	   //Indirect access of gender
	setAge(argA);		   //Indirect access of age

}




//Accessor Methods Students

//All SetMethods for students

void Artists::setFirstName(string argF) {   //Set methods for first name

	firstName = argF;

}

void Artists::setLastName(string argL) {  //Set methods for last name

	lastName = argL;

}
void Artists::setGender(string argG) {   //Set methods for gender

	gender = argG;

}
void Artists::setAge(int argA) {   //Set methods for age

	age = argA;

}



string Artists::getFirstName(void) {   //Get methods for first name

	return firstName;

}
string Artists::getLastName(void) {  //Get methods for last name

	return lastName;

}
string Artists::getGender(void) {  //Get methods for gender

	return gender;

}
int Artists::getAge(void) {  //Get methods for age

	return age;


}


//Utility Implemenation

void Artists::display() {   //To get rid of large cursor press insert

	cout << "The student's first name is: " << getFirstName() << endl;

	cout << "The student's last name is: " << getLastName() << endl;

	cout << "The student's gender is: " << getGender() << endl;

	cout << "The student's age is: " << getAge() << endl;

}



//*************StudentID Constructor Implementation**************** 


//The constructor implemenation for the above is in the StudentID class


//Utility Method Implementation


void Songs::display() {     //Virtual Can't be declared outside of the class!!

	Artists::display();  //Displays values from Student display first

	cout << "Their Banner studentID is: " << songLink << endl;


}
