////CSCI 002 Spring 2024 Day 23 File Importing and Exporting (WRONG!!!!!!!!!!!!!!)
//
//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include <vector>
//#include <string>
//#include <fstream>  // include file stream
//
//using namespace std;
//
//class Person {
//private:
//    string firstName, lastName;
//    bool gender;
//    int age;
//public:
//    Person(string argFirst = "", string argLast = "", bool argGen = 0, int argAge = 0);
//
//    Person& setFName(string);
//    Person& setLName(string);
//    Person& setGender(bool); // 0 for female, 1 for male
//    Person& setAge(int);
//
//    string getFName();
//    string getLName();
//    bool getGender();
//    int getAge();
//
//    void display();
//};
//
//
//int main(void) {
//    srand(time(0));
//    string myString;
//
//    vector<string> myText;  //This is containing our values within a vector
//
//    //open creates the file if it does not exist
//    //outputting to a file basically clears the file and starts anew,
//    //effectively overwriting it.
//    //ofstream myfile;
//    //myfile.open("csciRocks.txt");
//
//    ////output to file works just like 'cout' using insertion operator '<<'
//    //myfile << "David is awesome." << endl;
//    //myfile << "Juan is awesome too." << endl;
//    //myfile << "Redden is a minion of Skynet." << endl;
//
//
//    //myfile.close();  //WHEN YOU'RE DONE with a file you MUST CLOSE IT LIKE THIS.
//
//
//
//    //
//    //ofstream file2;  //Starting with file use of stream
//
//    //file2.open("JefeRocks.txt");
//    //file2 << "Eldy is the BBEG if Diablo 3. " << endl;
//
//
//    //ifstream myInput;
//    //myInput.open("JefeRocks.txt");
//
//    //while (!myInput.eof()) {  //Goes through it while we are not at end of file (eof) for myInput;
//
//
//
//    //    getline(myInput, myString);
//    //    if (myString != "") {
//
//    //        cout << "My String is: " << myString << endl;
//
//    //        myText.push_back(myString);  //Storing our text above as output into vector
//
//
//    //    }
//
//
//    //}
//
//    //myInput.close();  //Closing the alterating to file above.
//
//
//    //cout << endl << endl;
//
//    //for (int i = 0; i < myText.size(); i++) {
//
//    //    cout << myText[i] << endl;   
//    //}
//
//
//    //myText.push_back("Eldy is the BBEG of Diablo 3.");
//
//
//    //ofstream myOutput;
//    //myOutput.open("JefeRocks.txt");  //Opens the Jefe rocks txt file
//    //for (int i = 0; i < myText.size(); i++) {
//    //    myOutput << myText[i] << endl;
//
//    //    if (i < myText.size() - 1)   //Pushes an endl to the output file for every line except the last.
//    //        myOutput << endl;
//
//
//    //}
//
//
//    //myOutput.close(); //WHEN YOU'RE DONE with a file you MUST CLOSE IT LIKE THIS.
//    //
//
//    ifstream useExcel;
//    useExcel.open("myExcel.csv");
//    string editExcel;
//
//    vector<string> name;  //Stores for a column in excel for names
//    vector<string> ages;  //Stores for a column in excel for ages 
//    int pos;  //Position in vector
//
//    while (!useExcel.eof()) {
//
//        //"David,49"  Position of the comma (,) is 5, the Position of 9 is 7 
//        getline(useExcel, editExcel);
//        pos = editExcel.find(",");  //Will FIND and PRINT in the list where given "," is in string
//        
//        name.push_back(editExcel.substr(0, pos));  //Creates column for namess (will align) 
//       
//        //stoi stands for string to integer.
//        ages.push_back(stoi(editExcel.substr(pos + 1, editExcel.size() - pos - 1));  //8 - 5 = 3, 3 - 1 = 2;
//    
//
//
//    }
//
//    useExcel.close();  //Closes the excel file (GOOD PRACTICE) 
//
//    cout << endl << endl;
//
//    cout << "Thhis is what we pulled form Excel: " << endl;
//
//    for (int i = 0; i < name.size(); i++) {
//
//        cout << "Now " << 
//
//        cout << ""
//
//
//    }
//
//    ofstream myExcel;  //Excel file variable
//    ofstream myExcelText;  //Text in excel file variable
//    myExcel.open("myExcel.csv");
//    myExcelText.open("myExcelText.txt");
//
//
//
//
//    
//
//    //Creating a vector to store values for 
//
//    temp.clear();  //Clears previous values in teh vecotrs
//    temp.push_back("Eldy, 20");
//    temp.push_back("Alexis, 20");
//
//    temp.push_back("Juan, 21");
//    temp.push_bacK("Jefe, 49");
//    temp.push_back("Redden, 51");
//
//
//
//    for (int i = 0; i < temp.size(); i++) {
//        myExcel << temp[i];
//        myExcelText << temp[i];
//        
//        if (i < temp.size() - 1) {
//
//            myExcel << endl;
//            myExcelText
//        }
//
//
//    }
//
//    myExcel.close();
//
//    myExcelText.close();
//
//
//    ifstream useExcel;
//
//
//
//
//    //ofstream myExcel;
//    //myExcel.open("myExcel.csv");78
//
//
//    //myExcel << "David, 48" << endl;
//    //myExcel << "Voldemorta, 18" << endl;
//    //myExcel << "Juan, 20";  // this final endl is creating a blank new line, removed it.
//
//    //myExcel.close();
//
//
//    ////input file stream data type
//    //ifstream myfile2;
//    //myfile2.open("myExcel.csv");
//    //string stringVar;
//
//    ////current objective.  We have (David, 48), (Voldemorta, 18), and (Juan,20) saved in csv
//    //// let's extract the data from that and store it in the appropriate vectors
//    //// this is called string parsing.
//
//
//    system("pause");
//
//    return(0);
//}
//
//Person::Person(string argF, string argL, bool argG, int argA) {
//    setFName(argF);
//    setLName(argL);
//    setGender(argG);
//    setAge(argA);
//}
//
//Person& Person::setFName(string arg) {
//    arg[0] = toupper(arg[0]);
//    firstName = arg;
//    return *this;
//}
//
//Person& Person::setLName(string arg) {
//    arg[0] = toupper(arg[0]);
//    lastName = arg;
//    return *this;
//}
//
//Person& Person::setGender(bool arg) { gender = arg; return *this; }
//Person& Person::setAge(int arg) { age = arg; return *this; }
//
//string Person::getFName() { return firstName; }
//string Person::getLName() { return lastName; }
//bool Person::getGender() { return gender; }
//int Person::getAge() { return age; }
//
//void Person::display() {
//    cout << getLName() << ", " << getFName() << " ";
//    if (getGender())  // if getGender() ==1 , cout Male (1 is true), Female (0 is false)
//    {
//        cout << "Male";
//    }
//    else
//        cout << "Female";
//    cout << " Age : " << getAge() << endl;
//}