//CSCI 002 Spring 2024 Day 23 File Importing and Exporting

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <fstream>  // include file stream

using namespace std;

class Person {
private:
    string firstName, lastName;
    bool gender;
    int age;
public:
    Person(string argFirst = "", string argLast = "", bool argGen = 0, int argAge = 0);

    Person& setFName(string);
    Person& setLName(string);
    Person& setGender(bool); // 0 for female, 1 for male
    Person& setAge(int);

    string getFName();
    string getLName();
    bool getGender();
    int getAge();

    void display();
};

int main(void) {
    srand(time(0));
    string myString;
    vector<string> myText;
    vector<Person> myPeeps;
    ofstream myfile;

    myfile.open("PersonsOfInterest.csv");

    Person me("David", "Jones", 1, 49);
    Person notMe("Davita", "Jones", 0, 25);
    Person LordVader("James Earl", "Jones", 1, 93);
    myPeeps.push_back(me);
    myPeeps.push_back(notMe);
    myPeeps.push_back(LordVader);
    // to_string() converts to string, stoi converts strings to integers
    //for (int i = 0; i < myPeeps.size(); i++) {
    //    myString = myPeeps[i].getFName() + "," + myPeeps[i].getLName() + ",";
    //    myString += to_string(myPeeps[i].getGender()) + "," + to_string(myPeeps[i].getAge());
    //    
    //    myfile << myString;
    //    if (i != myPeeps.size() - 1) {
    //        myfile << endl;
    //    }
    //}

    myfile.close();
    vector<Person> database;
    Person blank;

    int pos, pos2, pos3;
    string first, last, temp, temp2, temp3;
    int gender, age;
    bool gen;
    ifstream f2;
    f2.open("PersonsOfInterest.csv");
    while (!f2.eof()) {
        getline(f2, myString);
        pos = myString.find(",");
        first = myString.substr(0, pos);  // this strips off the first name and stores it
        temp = myString.substr(pos + 1, myString.size() - pos - 1);

        pos2 = temp.find(",");
        last = temp.substr(0, pos2); // this stripped off and stored the last name
        temp2 = temp.substr(pos2 + 1, temp.size() - pos2 - 1);

        pos3 = temp2.find(",");
        gender = stoi(temp2.substr(0, pos3)); // this stripped off and stored the last name

        temp3 = temp2.substr(pos3 + 1, temp2.size() - pos3 - 1);
        age = stoi(temp3);

        blank.setFName(first);
        blank.setLName(last);
        blank.setGender(gender);
        blank.setAge(age);
        database.push_back(blank);

        blank.display();
    }
    f2.close();

    ofstream f3; // always need to open and close the file
    f3.open("Testing.csv");

    Person jackAss("Michael", "Camp", 1, 68);
    database.push_back(jackAss);
    for (int i = 0; i < database.size(); i++) {
        myString = database[i].getFName() + "," + database[i].getLName() + ",";
        myString += to_string(database[i].getGender()) + "," + to_string(database[i].getAge());

        f3 << myString;
        if (i != database.size() - 1) {
            f3 << endl;
        }
    }
    f3.close();


    /// ofstream output file stream, and ifstream is input file stream
    //myfile.open("JefeRocks.txt");

    ////output to file works just like 'cout' using insertion operator '<<'
    //myfile << "David is awesome." << endl;
    //myfile << "Juan is awesome too." << endl;
    //myfile << "Redden is a minion of Skynet." << endl;

    //myfile.close();


    //ifstream myInput;
    //myInput.open("JefeRocks.txt");
    //while (!myInput.eof()) {  // go through it while we are not at the End Of File (eof) for myInput

    //    getline(myInput, myString);
    //    if (myString != "") {
    //        //cout << "My String is : " << myString << endl;
    //        myText.push_back(myString);
    //    }
    //}
    //myInput.close();

    ////cout << endl << endl << "Now displaying saved text" << endl << endl;

    ////for (int i = 0; i < myText.size(); i++) {
    ////    cout << myText[i] << endl;
    ////}
    //cout << endl << endl;

    //myText.push_back("Eldy is the BBEG if Diablo 3.");

    //ofstream myOutput;
    //myOutput.open("JefeRocks.txt");
    //for (int i = 0; i < myText.size(); i++) {
    //    myOutput << myText[i];
    //    if (i < myText.size() - 1) //pushes an endl to the output file for every line except the last.
    //        myOutput << endl;
    //}
    //myOutput.close();





    //ifstream myTable;
    //myTable.open("myExcel.csv");
    //vector<string> temp;
    //while (!myTable.eof()) {

    //    getline(myTable, myString);
    //    if (myString != "") {
    //        //cout << "My String is : " << myString << endl;
    //        temp.push_back(myString);
    //    }
    //}
    //myTable.close();
    ////cout << endl << endl << "Now displaying saved excel content" << endl << endl;

    ////for (int i = 0; i < temp.size(); i++) {
    ////    cout << temp[i] << endl;
    ////}

    //cout << endl << endl;
    //ofstream myExcel;
    //ofstream myExcelText;
    //myExcel.open("myExcel.csv");
    //myExcelText.open("myExcelText.txt");

    ///*for (int i = 0; i < temp.size(); i++) {
    //    myExcel << temp[i] << endl;
    //}*/
    ////temp.clear();
    ////temp.push_back("Preston, 21");
    ////temp.push_back("Alexis, 20");

    ////temp.push_back("Eldy, 20");
    ////temp.push_back("Juan, 21");
    ////temp.push_back("Jefe, 49");
    ////temp.push_back("Redden, 51");

    //for (int i = 0; i < temp.size(); i++) {
    //    myExcel << temp[i];
    //    myExcelText << temp[i];
    //    if (i < temp.size() - 1) {
    //        myExcel << endl;
    //        myExcelText << endl;
    //    }
    //}

    //myExcel.close();
    //myExcelText.close();

    //ifstream useExcel;
    //useExcel.open("myExcel.csv");
    //string editExcel;
    //int pos;
    //vector<string> names;
    //vector<int> ages;
    //while (!useExcel.eof()) {
    //    //"David,49" pos of comma is at 5, 9 is at index 7.
    //    getline(useExcel, editExcel); //editExcel contains the row from the excel
    //    pos = editExcel.find(",");
    //    names.push_back(editExcel.substr(0, pos));
    //    //stoi stands for string to integer;
    //    ages.push_back(stoi(editExcel.substr(pos + 1, editExcel.size() - pos - 1))); // 8 - 5 = 3, 3-1 = 2;

    //}
    //useExcel.close();

    //cout << "This is what we pulled from Excel: " << endl;
    //for (int i = 0; i < names.size(); i++) {
    //    cout << "Row " << i + 1 << " has in column 1: " << names[i];
    //    cout << " and in column 2: " << ages[i] << endl;
    //}

    //cout << endl << endl;


    ////input file stream data type
    //ifstream myfile2;
    //myfile2.open("myExcel.csv");
    //string stringVar;

    ////current objective.  We have (David, 48), (Voldemorta, 18), and (Juan,20) saved in csv
    //// let's extract the data from that and store it in the appropriate vectors
    //// this is called string parsing.


    system("pause");

    return(0);
}

Person::Person(string argF, string argL, bool argG, int argA) {
    setFName(argF);
    setLName(argL);
    setGender(argG);
    setAge(argA);
}

Person& Person::setFName(string arg) {
    arg[0] = toupper(arg[0]);
    firstName = arg;
    return *this;
}

Person& Person::setLName(string arg) {
    arg[0] = toupper(arg[0]);
    lastName = arg;
    return *this;
}

Person& Person::setGender(bool arg) { gender = arg; return *this; }
Person& Person::setAge(int arg) { age = arg; return *this; }

string Person::getFName() { return firstName; }
string Person::getLName() { return lastName; }
bool Person::getGender() { return gender; }
int Person::getAge() { return age; }

void Person::display() {
    cout << getLName() << ", " << getFName() << " ";
    if (getGender())  // if getGender() ==1 , cout Male (1 is true), Female (0 is false)
    {
        cout << "Male";
    }
    else
        cout << "Female";
    cout << " Age : " << getAge() << endl;
}