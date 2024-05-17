//Cntrl + B Equals Compile

#include<map>
#include<string>
#include<iostream>
using namespace std;

struct Person {
	Person(string arg1, string arg2, int arg3 = 0) {
		firstName = arg1;
		lastName = arg2;
		age = arg3;
	}
	string firstName, lastName;
	int age;
};

int main(void) {

	map <string, Person*> myList;
	map <string, Person*>::iterator mapItr;

	myList["johnr"] = new Person("john", "redden");    //Sorted by ASCII values.
	myList["billB"] = new Person("bill", "bradley");
	myList["MaryW"] = new Person("mary", "white");
	myList["JamesJ"] = new Person("james", "jones");
	myList["AlleyB"] = new Person("alley", "bailey");
	myList["NedW"] = new Person("ned", "write", 18);
	myList["jerryQ"] = new Person("jerry", "que", 22);

	cout << "***** " << myList["johnr"]->firstName << endl;

	for (mapItr = myList.begin(); mapItr != myList.end(); mapItr++) {
		cout << mapItr->second->age << endl;
	}

	return(0);
}//Cntrl + B Equals Compile

#include<map>
#include<string>
#include<iostream>
using namespace std;

struct Person {
	Person(string arg1, string arg2, int arg3 = 0) {
		firstName = arg1;
		lastName = arg2;
		age = arg3;
	}
	string firstName, lastName;
	int age;
};

int main(void) {

	map <string, Person*> myList;
	map <string, Person*>::iterator mapItr;

	myList["johnr"] = new Person("john", "redden");    //Sorted by ASCII values.
	myList["billB"] = new Person("bill", "bradley");
	myList["MaryW"] = new Person("mary", "white");
	myList["JamesJ"] = new Person("james", "jones");
	myList["AlleyB"] = new Person("alley", "bailey");
	myList["NedW"] = new Person("ned", "write", 18);
	myList["jerryQ"] = new Person("jerry", "que", 22);

	cout << "***** " << myList["johnr"]->firstName << endl;

	for (mapItr = myList.begin(); mapItr != myList.end(); mapItr++) {
		cout << mapItr->second->age << endl;  //Second because first is the key words: "johnr", "billyB" etc. Second allows us to access properties.
	}

	return(0);
}