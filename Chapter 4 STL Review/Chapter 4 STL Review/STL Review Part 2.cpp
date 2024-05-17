#include <iostream>
#include <string>
#include <map>

using namespace std;
class UserInfo {
private:
	string displayName;
	string userPassword;
	int phoneNumber;

public:
	UserInfo(string, string);
	void displayUserInfo(void);


	//Accessor Methods for Phone 
	int getPhone(void);
	void setPhone(int arg);

};

int main(void)
{
	//the database
	map<string, UserInfo*> myDatabase;
	map<string, UserInfo*>::iterator it;

	//in the main populate the database at runtime... with user info
	myDatabase["johnr"] = new UserInfo("John Redden", "12345");

	//check to see if it works :)
	myDatabase["johnr"]->displayUserInfo();
	cout << "\n\n" << endl;

	myDatabase["billB"] = new UserInfo("Bill Bradley", "67891");
	myDatabase["jamesJ"] = new UserInfo("James Jones", "23456");


	//Indirectly Accessing and ADDING phone Number that is private in the constructor:

	myDatabase["johnr"]->setPhone(599000000);   //Setting phone number

	myDatabase["johnr"]->getPhone();   //Getting it and putting into the list.


	//Now display
	it = myDatabase.begin();

	while (it != myDatabase.end()) {
		cout << it->first << ": ";
		it->second->displayUserInfo();
		it++;
	}

	system("pause");  //Makes it so user has to hit key in order to continue code.
	return(0);
}


UserInfo::UserInfo(string arg1, string arg2) {
	displayName = arg1;
	userPassword = arg2;
}
void UserInfo::displayUserInfo() {
	cout << displayName << ": ";
	cout << userPassword << endl;
}


//Accessor Methods for Phone 
int UserInfo::getPhone(void) {

	return phoneNumber;

}
void UserInfo::setPhone(int arg) {

	phoneNumber = arg;


}