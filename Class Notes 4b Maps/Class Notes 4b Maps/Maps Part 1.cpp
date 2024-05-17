////Maps Notes
//
//#include <iostream>
//#include <string>
//#include <list>
//#include <map>
//using namespace std;
//
//class Person {
//
//private:
//    string firstName, lastName;
//    bool gender;
//    int age;
//
//public:
//    Person(string = "", string = "", bool = 0, int = 0);   //Initilizing base constructor
//
//    void setFName(string);    //Accessor Methods
//    void setLName(string);
//    void setGender(bool);
//    void setAge(int);
//
//    string getFName();
//    string getLName();
//    bool getGender();
//    int getAge();
//
//    void display();       //Utility Methods
//};
//
//struct Loot {
//    string name;
//    int value;
//    Loot(string arg1 = " ", int arg2 = 0) {
//        name = arg1;
//        value = arg2;
//    }
//};
//
//
//int main()
//{
//    list <Person*> myList;
//    list <Person*>::iterator itr; // datatype that acts like a pointer.
//
//    // you'll notice that adding stuff to a list is like adding to a vector
//    myList.push_back(new Person("mary", "jones", 0, 22));
//    myList.push_back(new Person("bill", "smith", 1, 23));
//    myList.push_back(new Person("jerry", "jones", 1, 23));
//    // we will deletes later on for each one.  Not the destructor
//
//
//    itr = myList.begin(); // .begin() gives us the first object in the list, 
//    //in this case Mary
//
//    //How to access the object data
//    // Dereferencing gives you a pointer!  Why?
//
//    //(*itr)->display();
//
//    while (itr != myList.end()) {
//        (*itr)->display();
//        itr++; // this takes us past end.  
//    }
//    cout << endl << endl;
//    myList.front()->display();
//    myList.back()->display();
//
//    // itr is at the end of the list right now.
//    // if we want to insert to before jerry, we'd need to search for jerry and find 
//    // the pointer to his location.
//    // insert(position, object to be inserted BEFORE the position given)
//    myList.insert(itr, new Person("juan", "the goat", 1, 24));
//
//
//    cout << endl << endl;
//    itr = myList.begin();
//    while (itr != myList.end()) {
//        (*itr)->display();
//        itr++;
//    }
//
//    cout << "************** bit on strings **************" << endl << endl;
//    list<string> myGames;
//    list<string>::iterator myItr;
//    myGames.push_back("Dark Souls");
//    myGames.push_back("Zelda");
//    myGames.push_back("Sekiro: Shadows Die Twice");
//    myGames.push_back("Metroid");
//    myGames.push_back("Horizon Zero Dawn");
//
//    myGames.sort();
//    list<string>::iterator temp;
//    cout << endl << endl;
//    myItr = myGames.begin();
//    while (myItr != myGames.end()) {
//        /*if (    (*myItr) == "Dark Souls"   ) {
//            temp = myItr++;
//            myGames.insert(temp, "Fortnite");
//        }*/  // Figure this out for practice for homework
//        cout << (*myItr) << endl;
//        myItr++;
//    }
//
//    cout << endl << endl << "************** MAPS ************" << endl << endl;
//
//    // map<key, value>  
//
//    map<string, Person*> myMap;
//    myMap["Thor"] = new Person("Thor", "Smash", 0, 28);
//    myMap["Jefe"] = new Person("David", "Jones", 1, 48);
//    myMap["Goat"] = new Person("Juan", "Ordaz", 1, 24);
//    // the names in brackets (code names) are the key to accessing the person (value)
//
//    // accessing individual members.  The Code Name is like the index in an array.
//    myMap["Jefe"]->display(); // Jefe here is like my index.  It's not a number.
//    myMap["Thor"]->display();
//    myMap["Goat"]->display();
//
//    // map<first, second>
//    map<string, Person*>::iterator itrMap = myMap.begin();
//    for (itrMap = myMap.begin(); itrMap != myMap.end(); itrMap++) {
//        cout << "Key: " << (*itrMap).first << endl;
//        cout << "     ";
//        (*itrMap).second->display();
//        cout << endl << endl;
//        //itrMap.second().display();
//
//    }
//
//    list<Loot*> myLoot;
//    myLoot.push_back(new Loot("Viking Helmet", 500));
//    myLoot.push_back(new Loot("Mjolnir", 10000));
//    myLoot.push_back(new Loot("Stormbreaker", 10001));
//
//    list<Loot*>::iterator itrL = myLoot.begin();
//
//    map<string, list<Loot*>> ourLoot;
//    map<string, list<Loot*>>::iterator mapTemp;
//
//    ourLoot["Thor"] = myLoot; // this is a list, we need the list iterator
//
//    for (itrL = ourLoot["Thor"].begin(); itrL != ourLoot["Thor"].end(); itrL++) {
//        cout << "Loot: " << (*itrL)->name << "     Value = " << (*itrL)->value << endl;
//    }
//    // We'll flesh this out more tomorrow night, 7:15pm on Zoom.  It will be recorded.
//    /*while (itrL != myLoot.end()) {
//        cout << (*itrL)->name << " is worth " << (*itrL)->value << endl;
//        itrL++;
//    }*/
//
//    cout << endl << endl << endl;
//    return(0);
//
//}
//
//Person::Person(string argF, string argL, bool argG, int argA)
//{
//    setFName(argF);
//    setLName(argL);
//    setGender(argG);
//    setAge(argA);
//}
//
//void Person::setFName(string arg)
//{
//    arg[0] = toupper(arg[0]);
//    firstName = arg;
//}
//void Person::setLName(string arg)
//{
//    arg[0] = toupper(arg[0]);
//    lastName = arg;
//}
//void Person::setGender(bool arg)
//{
//    gender = arg;
//}
//void Person::setAge(int arg)
//{
//    age = arg;
//}
//
//string Person::getFName()
//{
//    return firstName;
//}
//string Person::getLName()
//{
//    return lastName;
//}
//bool Person::getGender()
//{
//    return gender;
//}
//int Person::getAge()
//{
//    return age;
//}
//
//void Person::display()
//{
//    cout << getFName() << " " << getLName() << " ";
//    if (getGender())
//    {
//        cout << "Male";
//    }
//    else
//        cout << "Female";
//    cout << " Age : " << getAge() << endl << endl;
//}
//
//
