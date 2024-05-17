////Eli Ahmed
////Exam 1 Question 3 Demonstrate Polymorphism with D&D Characters
//
//
//#include<iostream>
//#include<string>
//#include<vector>
//#include<ctime>  //For srand seed time
//#include<cstdlib>  //For srand seed time
//
//using namespace std;
//
////Wanted to make an interesting program. (You said have fun ;))
//
//class PlayerChar {
//
//private:
//
//	string name;
//
//	int level;  //Levels are usually int, imagine being lvl 11.5
//
//	int strength, dexterity, constitution, intellegence, wisdom, charisma;
//
//
//public:
//
//
//
//	//Constructor Prototype
//	PlayerChar(string cName = "no name", int cLevel = 0,
//		int cStrength = 0, int cDexterity = 0, int cConstitution = 0,
//		int cIntelligence = 0, int cWisdom = 0, int cCharisma = 0);                 //Initialiazing base case for constructor.
//																	//In case no value is input.
//
//
//	//Accessor Nethods 
//
//
//	void setName(string argC);   //Set Methods for Accessor methods
//	void setLevel(int argL);
//	void setStrength(int argS);  //THINKING ABOUT USING INT FOR ALL SINCE ITS 3-18 (Normal 10-11) 
//	void setDexterity(int argD);
//	void setConstitution(int argCon);
//	void setIntelligence(int argI);
//	void setWisdom(int argWis);
//	void setCharisma(int argRizz);
//
//
//	string getName(void);   //Get Methods for accessor methods.
//	int getLevel(void);
//	int getStrength(void);
//	int getDexterity(void);
//	int getConstitution(void);
//	int getIntelligence(void);
//	int getWisdom(void);
//	int getCharisma(void);
//
//
//	
//
//	//Base class Utility Method 
//
//	virtual void printCharInfo(void) = 0; //When Initiliazing with = 0, this locks us in and forcs us to use printStats() for calculation in
//										  //in each.
//
//
//
//
//
//};
//
//
// 
//class Fighter : public PlayerChar {  //Inheretance with 
//
//private:
//
//	string favouriteWeapon;
//
//public: 
//
//
//	Fighter(string name, int cLevel, int cStrength, int cDexterity,  int cConstitution, int cIntelligence, int cWisdom, 
//			int cCharisma, string cFavWeapon = "Excalibur");   //Instatiating a base case if favourite weapon isn't
//															   //entered
//
//
//	//Accessor Methods Prototypes
//
//	void setFavWeapon(string argWeapon);   //Set Methods for Accessor methods
//
//	string getFavWeapon(void);   //Get Methods for accessor methods.
//
//
//
//	//Utility Method Prototype
//
//
//	void printCharInfo();   //Void Char info that we intilized
//							//with 0 above.
//
//
//
//};
//
//
//
//
//class Mage : public PlayerChar {   //Inheratance with of parent class PlayerChar
//
//
//private:
//
//	string favouriteSpell;
//
//public:
//
//	//Mage constructor
//
//	Mage (string name, int cLevel, int cStrength, int cDexterity, int cConstitution, int cIntelligence, int cWisdom,
//		int cCharisma, string cFavSpell = "Wingardium Leviosa");   //Instatiating a base case if favourite spell isn't
//																  //entered   
//
//	//Accessor Methods Prototypes
//
//	void setFavSpell(string argSpell);   //Set Methods for Accessor methods
//
//	string getFavSpell(void);   //Get Methods for accessor methods.
//
//
//
//
//	//Utility Method Prototype
//
//
//	void printCharInfo();   //Void Char info that we intilized
//							//with 0 above.
//
//
//
//
//
//};
//
//
//
//class Cleric : public PlayerChar {  //Inheretance with 
//
//private:
//
//	string deity;
//
//public:
//
//	// Cleric Constructor
//	
//	Cleric(string name, int cLevel, int cStrength, int cDexterity, int cConstitution, int cIntelligence, int cWisdom,
//	int cCharisma, string cFavDeity = "God of Grades Jones");    //Base(d) deity for both our grades and witty one liners
//					
//
//
//	//Accessor Methods Prototypes
//
//	void setFavDeity(string argDeity);   //Set Methods for Accessor methods
//
//	string getFavDeity(void);   //Get Methods for accessor methods.
//
//
//
//
//	//Utility Method Prototype
//
//	void printCharInfo();   //Void Char info that we intilized
//							//with 0 above.
//
//
//
//};
//
//
//
//
//class Thief : public PlayerChar {  //Inheretance with 
//
//private:
//
//	string favouriteSkill; 
//
//public:
//
//
//	Thief(string name, int cLevel, int cStrength, int cDexterity, int cConstitution, int cIntelligence, int cWisdom,
//		int cCharisma, string cFavSkill = "Clickbait Thumbnail");   //Base case is a thief of time. 
//
//
//	//Accessor Methods Prototypes
//
//	void setFavSkill(string argSkill);   //Set Methods for Accessor methods
//
//	string getFavSkill(void);   //Get Methods for accessor methods.
//
//
//
//	//Utility Method Prototype
//
//	void printCharInfo();   //Void Char info that we intilized
//							//with 0 above.
//
//
//
//};
//
//
//
//int main(void) {
//
//	srand(time(0));   //Seeding random time
//
//
//	vector<PlayerChar*> characters;  //starting the vector with the Playerchar ptr
//
//
//	//Objective 8 objects (2 from each class)
//
//	
//
//	characters.push_back(new Fighter("Cat", 1, generateStat(), generateStat(), generateStat(), generateStat(), generateStat(), "Excalibur"));
//	
//		
//	Fighter* fighter = new Fighter("", generateStat(), generateStat(), generateStat(), generateStat(), generateStat(), "");
//
//
//	characters.push_back(new Fighter("", generateStat(), generateStat(), generateStat(), generateStat(), generateStat(), ""));
//
//	// Creating a Fighter object separately
//	Fighter* fighter1 = new Fighter("", generateStat(), generateStat(), generateStat(), generateStat(), generateStat(), "");
//	characters.push_back(fighter1);
//
//		
//		//Fighter fighter("Fighter", 1, 11, 11, 11, 11, 11, "");
//	
//
//	/*Fighter fighter1( 100, generateStat(), generateStat(), generateStat(), generateStat(), generateStat(), "Excaliburo");
//
//
//	Fighter fighter2(100, generateStat(), generateStat(), generateStat(), generateStat(), generateStat(), "Excaliburo");*/
//
//
//	characters.push_back(&fighter1);
//
//
//	
//	//Comment where polymorphism occurs!!
//
//
//
//
//	//push_back.
//
//
//	rollDie();   //This randomizes the vector above.
//
//
//
//}
//
//
//
////Structures Constructor Implementations
//
//
//PlayerChar::PlayerChar(string cName, int cLevel, int cStrength, int cDexterity, int cConstitution, int cIntelligence, 
//					   int cWisdom, int cCharisma) {  //Input values
//
//	setName(cName);   //Indirect access 
//	setLevel(cLevel);  //Indirect Access
//	setStrength(cStrength);
//	setDexterity(cDexterity);
//	setConstitution(cConstitution);
//	setIntelligence(cIntelligence);
//	setWisdom(cWisdom);
//	setCharisma(cCharisma);
//
//
//}
//
//
//
//
////*****************PlayerChar Methods Implementation********************
//
//void PlayerChar::setName(string argC) {   //Set Methods for Accessor methods
//
//	name = argC;
//
//}
//
//
//void PlayerChar::setLevel(int argL) {      //Set Methods for Accessor methods
//
//	level = argL;
//
//}
//
//
//void PlayerChar::setStrength(int argS) {   //Strength Stat
//
//	strength = argS;
//
//} 
//
//
//void PlayerChar::setDexterity(int argD) {
//
//	dexterity = argD;
//
//
//}
//
//
//void PlayerChar::setConstitution(int argCon) {
//
//	constitution = argCon;
//
//}
//void PlayerChar::setIntelligence(int argI) {
//
//	intellegence = argI;
//
//}
//void PlayerChar::setWisdom(int argWis) {
//
//	wisdom = argWis;
//
//}
//void PlayerChar::setCharisma(int argRizz) {
//
//	charisma = argRizz;
//}
//
//
//
//
//
//
//string PlayerChar::getName(void) {   //Get Methods for accessor methods.
//
//	return name;
//
//}
//
//int PlayerChar::getLevel(void) {   //Get Methods for accessor methods.
//
//	return level;
//
//
//}
//int PlayerChar::getStrength(void){
//
//	return strength;
//
//}
//
//int PlayerChar::getDexterity(void) {
//
//	return dexterity;
//}
//
//int PlayerChar::getConstitution(void) {
//
//	return constitution;
//
//}
//
//int PlayerChar::getIntelligence(void) {
//
//	return intellegence;
//
//}
//
//int PlayerChar::getWisdom(void) {
//
//	return wisdom;
//
//}
//int PlayerChar::getCharisma(void) {
//
//	return charisma;
//
//}
//
//
//
//void PlayerChar::printCharInfo() {
//
//	cout << "The player name is: " << getName() << endl;
//
//	cout << "Their level is: " << getLevel() << endl;
//
//	//cout << "Their stats are: " << rollDie()  //Find a way to make this work for levels
//
//
//}
//
//
//
//
////***************** Fighter Implementation ********************
//
////Constructor
//
//
//Fighter::Fighter(string cName, int cLevel, int cStrength, int cDexterity, int cConstitution, int cIntelligence, int cWisdom,
//				int cCharisma, string cFavWeapon) : PlayerChar(cName, cLevel, cStrength, cDexterity,
//					cConstitution, cIntelligence, cWisdom, cCharisma){   //Base case is Excalibur
//
//	setFavWeapon(cFavWeapon);
//
//
//}
//
////Accessor Methods Implementation
//
//void Fighter::setFavWeapon(string argWeapon) {   //Set Methods for Accessor methods
//
//	favouriteWeapon = argWeapon;
//
//}
//string Fighter::getFavWeapon(void) {   //Get Methods for accessor methods.
//
//	return favouriteWeapon;
//
//}
//
////Utility Implementation
//
//void Fighter::printCharInfo() {
//
//	PlayerChar::printCharInfo();  //Getting the info from player stats
//
//	cout << "The figher's favourite weapon is: " << getFavWeapon() << endl;
//
//}
//
//
//
////***************** Mage Implementation ********************
//
//
//	//Mage constructor
//
//Mage::Mage(string cName, int cLevel, int cStrength, int cDexterity, int cConstitution, int cIntelligence, int cWisdom,
//		  int cCharisma, string cFavSpell) : PlayerChar(cName, cLevel, cStrength, cDexterity,
//		  cConstitution, cIntelligence, cWisdom, cCharisma) {    //Base case is Wingardium Leviosa 
//
//	setFavSpell(cFavSpell);
//
//}
//
//
////Accessor Methods Implementation
//
//void Mage::setFavSpell(string argSpell) {       //Set Methods for Accessor methods
//
//	favouriteSpell = argSpell;
//
//}
//
//string Mage::getFavSpell(void) {   //Get Methods for accessor methods.
//
//
//	return favouriteSpell;
//
//}
//
//
////Utility Methods Implementation
//
//void Mage::printCharInfo(void) {
//
//	PlayerChar::printCharInfo();  //Getting the info from player stats
//
//	cout << "Player Name: " << cName << endl;
//
//	cout << 
//	
//	cout << "Their favourite spell is: " << getFavSpell() << endl;			
//
//	
//
//}
//
//
//
//
////***************** Cleric Implementation ********************
//
//// Cleric Constructor
//
//Cleric::Cleric(string cName, int cLevel, int cStrength, int cDexterity, int cConstitution, int cIntelligence, int cWisdom,
//	int cCharisma, string cFavDeity) : PlayerChar(cName, cLevel, cStrength, cDexterity,
//			cConstitution, cIntelligence, cWisdom, cCharisma) {  //Base(d) deity for both our grades and witty one liners
//
//	setFavDeity(cFavDeity);
//
//}
//
//
////Accessor Methods Implementation
//
//void Cleric::setFavDeity(string argDeity) {   //Set Methods for Accessor methods
//
//	deity = argDeity;
//}
//
//
//string Cleric::getFavDeity(void) {   //Get Methods for accessor methods.
//
//	return deity;
//
//}
//
//
////Utility Methods Implementation
//
//void Cleric::printCharInfo(void) {
//
//	PlayerChar::printCharInfo();  //Getting the info from player stats
//
//	cout << "Their favourite Deity is: " << getFavDeity() << endl;
//
//}
//
//
//
//
////*****************Thief Methods Implementation********************
//
//
//Thief::Thief(string cName, int cLevel, int cStrength, int cDexterity, int cConstitution, int cIntelligence, int cWisdom,
//			int cCharisma, string cFavSkill) : PlayerChar(cName, cLevel, cStrength, cDexterity,
//			cConstitution, cIntelligence, cWisdom, cCharisma) {  //Base case is a thief of time. (Clickbait) 
//
//	setFavSkill(cFavSkill);
//
//
//}
////Accessor Methods Implementation
//
//void Thief::setFavSkill(string argSkill) {   //Set Methods for Accessor methods
//
//	favouriteSkill = argSkill;
//
//}
//
//
//string Thief::getFavSkill(void) {   //Get Methods for accessor methods.
//
//	return favouriteSkill;
//
//}
//
//void Thief::printCharInfo(void) {
//
//	PlayerChar::printCharInfo();  //Getting the info from player stats
//
//	cout << "Their favourite skill is " << getFavSkill() << endl;
//
//}
//
//
//
////C-type Functions Implemenetation 
//
//
//int rollDie(void) {
//
//	return 1 + rand() % 6;
//
//
//}
//
//
//int generateStat(void) {
//
//
//	return rollDie() + rollDie() + rollDie();
//
//}
//
//
//
