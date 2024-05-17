/*CSCI 002 Spring 2024 Day 22, First day of Hash Tables and Hash Functions*/

#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

class Person {
private:
    string firstName, lastName;
    bool gender;
    int age;
public:

    Person(string argFirst = "", string argLast = "", bool argGen = 0, int argAge = 0);

    void setFName(string);
    void setLName(string);
    void setGender(bool); // 0 for female, 1 for male
    void setAge(int);

    string getFName();
    string getLName();
    bool getGender();
    int getAge();

    void display();
};

void printMultiples(vector<int>[], int multiple);

int firstChar(string arg);
int phoneWithoutArea(long double arg);
int areaCode(long double arg);
bool comparePeeps(Person* arg1, Person* arg2); // make it work by last name, then first name, then age

int main(void) {

    list<Person*> myPeeps[26][26]; // 2D array for initials myPeeps[Last][Name]
    list<Person*>::iterator itr;

    Person* me = new Person("David", "Jones", 1, 49);
    Person* me1 = new Person("Donald", "Jones", 1, 49);
    Person* me2 = new Person("Daisy", "Jones", 1, 49);
    Person* padaJuan = new Person("Juan", "Ordaz", 1, 21);
    Person* Eldinator = new Person("Eldy", "Sanchez-Marin", 1, 20);  // Marin-ate
    list<Person*> vecPeep = { me, padaJuan, Eldinator, me1, me2 };


    for (auto vPeep : vecPeep) { //goes through vecPeep and pulls out each Person* one at a time.
        myPeeps[firstChar(vPeep->getLName())][firstChar(vPeep->getFName())].push_back(vPeep);
    }
    itr = vecPeep.begin();
    //// firstChar("Name")
    //int key1, key2;
    //key1 = firstChar(me->getFName());
    //key2 = firstChar(me->getLName());
    //myPeeps[key2][key1].push_back(me);
    //myPeeps[firstChar(padaJuan->getLName())][firstChar(padaJuan->getFName())].push_back(padaJuan);
    //myPeeps[firstChar(Eldinator->getLName())][firstChar(Eldinator->getFName())].push_back(Eldinator);

    for (int i = 0; i < 26; i++) { // names[i].at(j), cout everything in it
        for (int j = 0; j < 26; j++) {
            if (!myPeeps[i][j].empty()) {  // if the ith letter has any names in it, otherwise skip
                cout << "Initials starting with: " << char(j + 'A') << char(i + 'A') << endl;
                cout << "********************************" << endl;
                myPeeps[i][j].sort(comparePeeps);
                //for(itr = myPeeps[i][j].begin(); itr!=myPeeps[i][j].end(); itr++){
                //   (*itr)->display();
                //}
                for (auto peep : myPeeps[i][j]) {  // auto chooses the datatype for you, with or w/o Pointers
                    peep->display(); //for the auto loop!
                }
                cout << endl;
            }
        }
    }
    return(0);
}

// Your first Hash Function
int firstChar(string arg) {  // this returns the ASCII value of a character minus 97
    char temp = tolower(arg[0]); // this will give me lower case value of first character of Name
    return (int(temp) - int('a'));  // int(a) or ASCII value a is 97
}

int areaCode(long double arg) {  // for my key
    int tempNumber = arg / 10000000;  // this gave us the 559
    return (arg / 10000000);
    // unsigned long int phoneNumber = arg - tempNumber * 10000000;
}
int phoneWithoutArea(long double arg) {  // for my value
    int tempNumber = arg / 10000000;  // this gave us the 559
    unsigned long int phoneNumber = arg - tempNumber * 10000000;
    return phoneNumber;
}

void printMultiples(vector<int> arg[], int multiple) {
    // this is O(1) = constant time lookup  (the most efficient search)
    cout << "a[" << multiple << "] = ";
    for (int j = 0; j < arg[multiple].size(); j++) {
        cout << arg[multiple].at(j) << " "; // for the columns
    }
}

Person::Person(string argF, string argL, bool argG, int argA) {
    setFName(argF);
    setLName(argL);
    setGender(argG);
    setAge(argA);
}

void Person::setFName(string arg) {
    arg[0] = toupper(arg[0]);
    firstName = arg;
}

void Person::setLName(string arg) {
    arg[0] = toupper(arg[0]);
    lastName = arg;
}

void Person::setGender(bool arg) {
    gender = arg;
}

void Person::setAge(int arg) {
    age = arg;
}

string Person::getFName() {
    return firstName;
}

string Person::getLName() {
    return lastName;
}

bool Person::getGender() {
    return gender;
}

int Person::getAge() {
    return age;
}

void Person::display() {
    cout << getFName() << " " << getLName() << " ";
    if (getGender())  // if getGender() ==1 , cout Male (1 is true), Female (0 is false)
    {
        cout << "Male";
    }
    else
        cout << "Female";
    cout << " Age : " << getAge() << endl;
}

bool comparePeeps(Person* arg1, Person* arg2) {  // make it work by last name, then first name, then age
    // compare last names, arg1<arg2
    if (arg1->getLName() < arg2->getLName()) {
        return (1); // tells it to go left
    }
    if (arg1->getLName() == arg2->getLName()) {
        // now we look at first names;
        if (arg1->getFName() < arg2->getFName()) {
            return(1);
        }
        if (arg1->getFName() == arg2->getFName()) {
            // now we look at genders, Alexis chose this;
            if (arg1->getGender() < arg2->getGender()) {
                return (1);
            }
            if (arg1->getGender() == arg2->getGender()) {
                if (arg1->getAge() < arg2->getAge()) {
                    return(1);
                }
                if (arg1->getAge() == arg2->getAge()) {// where everthing is equal;
                    cout << "We have a doppleganger!" << endl;
                }
            }
        }
    }

    return(0);
}