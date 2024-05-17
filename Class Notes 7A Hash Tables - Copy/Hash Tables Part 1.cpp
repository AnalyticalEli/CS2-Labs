////Hash Tables are LIKE arrays for Key Vales 
////Hash Tables Part 1


#include <iostream>
#include<string>
#include <vector>
using namespace std;

int firstChar(string arg);

void printMultiples(vector<int>[], int multiple);

int areaCode(long double arg);

int phoneWithoutArea(long double arg);


int main(void) {

    const int size = 10;

    //need an array of vectors -- cool
    vector<int> a[size]; //Array size 10 containing integer vectors.

    //create buckets that hold the multiples of the index of the hash table.

    for (int i = 0; i < size; i++) { //rows = array

        for (int j = 0; j < 20; j++) { //columns = vectors

            //populate the buckets (vector) with multiples of the index
            a[i].push_back(i * j);

        }
    }

    vector<string> names[26]; //Because there are 26 letters in the alphabet

    
    //passing in david

    string me = "David";  //Value
    int meVal = firstChar(me);  //Key  me is David. . FirstChar converts capital values to lower case 
    
    string notMe = "Deysi"; //Value 
    int notMeVal = firstChar(notMe); //Key  notMe is Padajuan. FirstChar converts capital values to lower case 

    //Together Hash functiins and tables are a lot like maps.


    names[meVal].push_back(me);
    names[notMeVal].push_back(notMe);
    names[firstChar("Juan")].push_back("Juan");  //Enters Juan using a map format (Hash TABLES ARE MAPS BUT FOR SMALLER AMOUNT OF VALUES) 


    //User Interface that allows student to enter value.
    string userResp;
    cout << "Please enter a name to sotre in the database: " << endl;
    getline(cin, userResp);


    for (int i = 0; i < 26; i++) {  //names[i] and cout everything in it.


        if (!names[i].empty()) {  //Only Prints first letter of names THAT EXIST IN VALUES ABOVE.
            cout << "Names starting with: " << char(i + 'A') << endl;  //Gives us the actual letter of the names we're starting with.
            cout << "*************************************" << endl;

            for (int j = 0; j < names[i].size(); j++) {
                cout << names[i].at(j) << endl;

            }
            cout << endl;
        }

    }


    //New idea: Hash Functions for phone numbers based off area codes:

    long double notMyNumber = 5598675309;

    vector<unsigned long int> myPhoneBook[999]; //Allows us to have an area code all the way to 998

    myPhoneBook[areaCode(notMyNumber)].push_back(phoneWithoutArea(notMyNumber));  //Takes in not my number and checks what it's area code as Key, and the actual Number WITHOUT AREA CIDE AS NUMBERS
 

  /*  int userResp;
    cout << "Enter a multiple 0-9: ";
    cin >> userResp;*/

   // printMultiples(a, userResp);

    cout << "\n******************" << endl;
    cout << endl;

    //print algorithm for the table
    for (int i = 0; i < size; i++) { //for the rows
        cout << "a[" << i << "] = ";
        for (int j = 0; j < a[i].size(); j++) {
            cout << a[i].at(j) << " "; // for the columns
        }

        cout << endl;
    }

    return(0);
}


//C-type Implemenation

int firstChar(string arg) {  //This returns the ascii value of a characater minus 97

    vector<string> names[26]; //Because there are 26 letters in the alphabet
    string name = "David";
    char temp = tolower(arg[0]);  //Makes all the letters lower case to make easier to sort with ascii values. (Lower case d)
    return (int(temp) - int('a'));  //Temp is 100 and ASCII value for a is 97. 100 - 97 = 3. 3 We know is D (for David Jones)

}



void printMultiples(vector<int> arg[], int multiple) {
    // this is O(1) = constant time lookup  (the most efficient search)
    cout << "a[" << multiple << "] = ";
    for (int j = 0; j < arg[multiple].size(); j++) {
        cout << arg[multiple].at(j) << " "; // for the columns
    }

}


int phoneWithoutArea(long double arg) {

    int tempNum = arg / 10000000;  //This gaves us Area Code
    unsigned long int phoneNumber = arg - tempNum * 10000000;
    return(arg / 10000000);

}

int areaCode(long double arg) {

    //long double notMyNumber = 5598675309;

    int tempNum = arg / 10000000;  //This gaves us Area Code
    return(arg / 10000000);


}


