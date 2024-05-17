//#include<iostream>
//#include<string>
//using namespace std;
//
//class Athlete {
//private:
//	string sport;
//	char gender;
//	int age;
//
//public:
//	Athlete(string sArg = "no sport", char gArg = '0', int aArg = 0);
//
//	void setSport(string arg);
//	string getSport();
//	void setGender(char arg);
//	char getGender();
//	void setAge(int arg);
//	int getAge();
//
//	virtual void printStats() = 0;   //When putting = 0, this locks us in and forcs us to use printStats() for calculation in
//	//in each.
//};
//
//class Soccer : public Athlete {
//private:
//	string position;
//public:
//	Soccer(char gArg, int aArg, string pArg = "no position", string sArg = "Soccer");
//
//	void setPosition(string arg);
//	string getPosition(void);
//
//
//	void printStats();     //Using it here
//};
//
//class Track : public Athlete {
//private:
//	string event;
//public:
//	Track(char gArg, int aArg, string eArg = "no event", string sArg = "Track");
//
//	void setEvent(string arg);
//	string getEvent();
//
//	void printStats();    //Using it here
//};
//
//
//
//
//
//int main(void) {
//	Track myT1('f', 22, "1600 meter");
//
//	Soccer myS1('m', 19, "center forward"); // note, we don't have to mess with last sport parameter (sArg) 
//	//becuase we took care of it in the defaults inside the constructor
//
//	Soccer myS2('f', 31); // again note the defaults in constructor
//
//	//Bottom one uses abstract class (because of the pure virtual function(virtual... = 0)) so it won't work unless you make it not pure
//	//Athlete myA2("tennis", 'm', 21); 
//
//	myT1.printStats();
//
//	cout << endl;
//	myS1.printStats();
//	cout << endl;
//	myS2.printStats();
//
//
//
//
//
//	return(0);
//}
//
//
//
//
//
//
//
//// ******************* Athlete implementation ************************
//Athlete::Athlete(string sArg, char gArg, int aArg) {
//	setSport(sArg);
//	setAge(aArg);
//	setGender(gArg);
//}
//
//void Athlete::setSport(string arg) {
//	sport = arg;
//}
//string Athlete::getSport() {
//	return sport;
//}
//void Athlete::setGender(char arg) {
//	gender = arg;
//}
//char Athlete::getGender() {
//	return gender;
//}
//void Athlete::setAge(int arg) {
//	age = arg;
//}
//int Athlete::getAge() {
//	return age;
//}
//
//void Athlete::printStats() {
//	cout << "Age: " << getAge() << "\nGender: " << getGender() << "\nSport: " << getSport() << endl;
//}
//
//
//
//// ******************* Soccer implementation ************************
//Soccer::Soccer(char gArg, int aArg, string pArg, string sArg) : Athlete(sArg, gArg, aArg) {
//	setPosition(pArg);
//}
//
//void Soccer::setPosition(string arg) {
//	position = arg;
//}
//string Soccer::getPosition(void) {
//	return position;
//}
//
//void Soccer::printStats() {
//	Athlete::printStats();
//	cout << "Position: " << getPosition() << endl;
//}
//
//
//
//// ****************************** Track Implementation ******************************
//
//Track::Track(char gArg, int aArg, string eArg, string sArg) : Athlete(sArg, gArg, aArg) {
//	setEvent(eArg);
//}
//
//void Track::setEvent(string arg) {
//	event = arg;
//}
//string Track::getEvent() {
//	return event;
//}
//
//void Track::printStats() {
//	Athlete::printStats();
//	cout << "Event: " << getEvent() << endl;
//}





















