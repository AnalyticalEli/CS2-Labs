//// Laura Torres
//// Final Exam Has Table Loot
//
//#include<iostream>
//#include<string>
//#include<list>
//
//using namespace std;
//
//struct Loot {
//    //Variables
//    string name;
//    int value;
//
//
//    //Constructor
//    Loot(string argN = " ", int argV = 0);
//
//    void display();
//
//};
//
//// This is the first part of the assignment :
////In the begin of the project I created a struct called playerChar
////playerChar is my base struct
////This is where I place in my variables needed for my project
//
////This is the second part of the assignment:
////Where the struct has a string that stores information 
////about the character traits (charTraits).
//struct playerChar {
//    string Name, Job, charTraits;
//    int Level, Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma;
//    list<Loot*> myLoot;
//
//    playerChar(string argN = " ", string argJ = " ", string argCT = " ");
//
//    virtual void printCharInfo();
//
//};
//
////This is the fourth part of the assignment:
////Each structs have the printCharInto that prints the screen of their,
////name, job, level, stats, charTraits, and gear. 
//struct Weapon : Loot {
//    //Variables
//    int damageLow;
//    int damageHigh;
//    string bonusProperties;
//
//    //Constructor
//
//
//    Weapon(string argN, int argV, int damL, int damH, string bonusP);
//
//    virtual void  display();
//};
//
//struct Armor : Loot {
//    //Variable
//    string ArmorDescription;
//
//    //Constructor
//    Armor(string argN, int argV, string argG);
//
//
//    virtual void  display();
//};
//
//struct MagicRing : Loot {
//    //Variable
//    string RingDescription;
//
//    //Constructor
//    MagicRing(string argN, int argV, string argG);
//
//
//    virtual void  display();
//};
//
////This is the third part of the assignment:
////Down below are 3 additional structs that inherit from the Loot struct
//struct SpellFocus : Loot {
//    //Variable
//    string SpellDescription;
//
//    //Constructor
//    SpellFocus(string argN, int argV, string argG);
//
//
//    virtual void  display();
//
//};
//
//struct Shield : Loot {
//    //Variable
//    string ShieldDescription;
//
//    //Constructor
//    Shield(string argN, int argV, string argG);
//
//    virtual void  display();
//
//};
//
//struct Potion : Loot {
//    //Variable
//    string PotionDescription;
//
//    //Constructor
//    Potion(string argN, int argV, string argG);
//
//    virtual void  display();
//
//};
//
//// comparators
//bool compareLootByName(Loot* argName1, Loot* argName2) {
//    return argName1->name < argName2->name;
//}
//
//// Functions
//int rollDie() {
//    return 1 + rand() % 6;
//}
//
//int generateStat() {
//    return rollDie() + rollDie() + rollDie();
//}
//
//
////This is the fifth part of the assignment:
////This is part A of section 5 where we create a Hash Table of the D&D Characters
////There are four different jobs which are fighter, mage, cleric, and thief
//int jobHashFunction(playerChar* argJobs) {
//    if (argJobs->Job == "Fighter") {
//        return 0;
//    }
//    else if (argJobs->Job == "Mage") {
//        return 1;
//    }
//    else if (argJobs->Job == "Cleric") {
//        return 2;
//    }
//    else if (argJobs->Job == "Thief") {
//        return 3;
//    }
//    return 0;
//}
//
//int main() {
//    //Lecture Notes 22:
//    //We made it into a list of the base struct called playerChar
//    //Since there is going to be four jobs we have a array of 4 [Fighter, Mage, Ceric, Thief]
//    list<playerChar*> jobs[4];
//    list<playerChar*>::iterator itr;
//
//    //This is the fifth part of the assignment:
//    //This is part B of section 5 where we create 12 players with 3 loots
//    //By using playerChar I would be able to create my first player
//    //This is where I provide my players information:
//
//
//    //I wasn't able to finish on adding creativity chractors so i just copped and pass to try to test out my program. 
//    playerChar* player1 = new playerChar("Fernando", "Fighter", "He can predict a players move");
//    player1->myLoot.push_back(new Weapon("Belt", 20, 30, 40, "leather"));
//    player1->myLoot.push_back(new Shield("Fire Shield", 50, "Shield you with a ring of fire from attackers"));
//    player1->myLoot.push_back(new SpellFocus("Fart Bomb", 30, "It dissociate your enemies for 10 sec."));
//
//    playerChar* player2 = new playerChar("Oscar", "Fighter", "cool");
//    player1->myLoot.push_back(new Armor("Diamond", 100, "withstand up to 90 % of damage"));
//    player1->myLoot.push_back(new Shield("Fire Shield", 50, "Shield you with a ring of fire from attackers"));
//    player1->myLoot.push_back(new SpellFocus("Fart Bomb", 30, "It dissociate your enemies for 10 sec."));
//
//    playerChar* player3 = new playerChar("Abby", "Fighter", "brave");
//    player1->myLoot.push_back(new Weapon("Belt", 20, 30, 40, "trait 1"));
//    player1->myLoot.push_back(new Shield("Fire Shield", 50, "Shield you with a ring of fire from attackers"));
//    player1->myLoot.push_back(new SpellFocus("Fart Bomb", 30, "It dissociate your enemies for 10 sec."));
//
//
//    playerChar* player4 = new playerChar("Rosa", "Mage", "He is skilled in fire spells");
//    player2->myLoot.push_back(new SpellFocus("Inferno", 40, "It damages your opponent by 30%"));
//    player2->myLoot.push_back(new MagicRing("JJJ", 30, "IDID"));
//    player2->myLoot.push_back(new Potion("dd", 60, "jfjf"));
//
//    playerChar* player5 = new playerChar("Jake", "Mage", "He is skilled in fire spells");
//    player2->myLoot.push_back(new SpellFocus("Inferno", 40, "It damages your opponent by 30%"));
//    player2->myLoot.push_back(new MagicRing("JJJ", 30, "IDID"));
//    player2->myLoot.push_back(new Potion("dd", 60, "jfjf"));
//
//    playerChar* player6 = new playerChar("Jonathan", "Mage", "He is skilled in fire spells");
//    player2->myLoot.push_back(new SpellFocus("Inferno", 40, "It damages your opponent by 30%"));
//    player2->myLoot.push_back(new MagicRing("JJJ", 30, "IDID"));
//    player2->myLoot.push_back(new Potion("dd", 60, "jfjf"));
//
//    playerChar* player7 = new playerChar("Leticia", "Cleric", "He is skilled in fire spells");
//    player3->myLoot.push_back(new SpellFocus("Inferno", 40, "It damages your opponent by 30%"));
//    player3->myLoot.push_back(new MagicRing("JJJ", 30, "IDID"));
//    player3->myLoot.push_back(new Potion("dd", 60, "jfjf"));
//
//    playerChar* player8 = new playerChar("Laura", "Cleric", "He is skilled in fire spells");
//    player3->myLoot.push_back(new SpellFocus("Inferno", 40, "It damages your opponent by 30%"));
//    player3->myLoot.push_back(new MagicRing("JJJ", 30, "IDID"));
//    player3->myLoot.push_back(new Potion("dd", 60, "jfjf"));
//
//    playerChar* player9 = new playerChar("Laura", "Cleric", "He is skilled in fire spells");
//    player3->myLoot.push_back(new SpellFocus("Inferno", 40, "It damages your opponent by 30%"));
//    player3->myLoot.push_back(new MagicRing("JJJ", 30, "IDID"));
//    player3->myLoot.push_back(new Potion("dd", 60, "jfjf"));
//
//
//    playerChar* player10 = new playerChar("Isabel", "Thief", "He is skilled in fire spells");
//    player4->myLoot.push_back(new SpellFocus("Inferno", 40, "It damages your opponent by 30%"));
//    player4->myLoot.push_back(new MagicRing("JJJ", 30, "IDID"));
//    player4->myLoot.push_back(new Potion("dd", 60, "jfjf"));
//
//    playerChar* player11 = new playerChar("Oscar", "Thief", "He is skilled in fire spells");
//    player4->myLoot.push_back(new SpellFocus("Inferno", 40, "It damages your opponent by 30%"));
//    player4->myLoot.push_back(new MagicRing("JJJ", 30, "IDID"));
//    player4->myLoot.push_back(new Potion("dd", 60, "jfjf"));
//
//    playerChar* player12 = new playerChar("Giovanny", "Thief", "He is skilled in fire spells");
//    player4->myLoot.push_back(new SpellFocus("Inferno", 40, "It damages your opponent by 30%"));
//    player4->myLoot.push_back(new MagicRing("JJJ", 30, "IDID"));
//    player4->myLoot.push_back(new Potion("dd", 60, "jfjf"));
//
//    //Placing the players into the hash table based on their jobs
//    jobs[jobHashFunction(player1)].push_back(player1);
//    jobs[jobHashFunction(player2)].push_back(player2);
//    jobs[jobHashFunction(player3)].push_back(player3);
//    jobs[jobHashFunction(player4)].push_back(player4);
//    jobs[jobHashFunction(player5)].push_back(player5);
//    jobs[jobHashFunction(player6)].push_back(player6);
//    jobs[jobHashFunction(player7)].push_back(player7);
//    jobs[jobHashFunction(player8)].push_back(player8);
//    jobs[jobHashFunction(player9)].push_back(player9);
//    jobs[jobHashFunction(player10)].push_back(player10);
//    jobs[jobHashFunction(player11)].push_back(player11);
//    jobs[jobHashFunction(player12)].push_back(player12);
//
//
//    //This is the fifth part of the assignment:
//    //This is part D of section 5 where we display the the hash table
//    for (int i = 0; i < 4; i++) {
//        cout << "Bucket " << i << "  " << endl;
//        cout << " ****************************************" << endl;
//        for (itr = jobs[i].begin(); itr != jobs[i].end(); itr++) {
//            (*itr)->printCharInfo();
//        }
//    }
//};
//
////Implementations
//
////PlayerChar implementation:
//
//playerChar::playerChar(string argN, string argJ, string argCT) {
//    Name = argN;
//    Job = argJ;
//    Level = generateStat();
//    Strength = generateStat();
//    Dexterity = generateStat();
//    Constitution = generateStat();
//    Intelligence = generateStat();
//    Wisdom = generateStat();
//    Charisma = generateStat();
//    charTraits = argCT;
//}
//
//void playerChar::printCharInfo(void) {
//    list<Loot*> myLoot;
//    list<Loot*>::iterator itr;
//    cout << "Name: " << Name << endl;
//    cout << "Job: " << Job << endl;
//    cout << "Level: " << Level << endl;
//    cout << "Strength: " << Strength << endl;
//    cout << "Dexterity: " << Dexterity << endl;
//    cout << "Constitution: " << Constitution << endl;
//    cout << "Intelligence: " << Intelligence << endl;
//    cout << "Wisdom: " << Wisdom << endl;
//    cout << "Charisma: " << Charisma << endl;
//    cout << "Character Traits : " << charTraits << endl;
//    cout << "Gear: " << endl;
//    //Lecture 22:
//    //Create a for loop that obtains the series of loots
//    //This will cause the series of loots to be displayed
//    for (itr = myLoot.begin(); itr != myLoot.end(); itr++) {
//        (*itr)->display();
//    }
//    cout << endl;
//}
//
////Loot implementation:
//Loot::Loot(string argN, int argV) {
//    name = argN;
//    value = argV;
//}
//
//void Loot::display() {
//    cout << name << " is worth " << value << " gold pieces." << endl;
//
//}
//
//// Weapon implementation:
//Weapon::Weapon(string argN, int argV, int damL, int damH, string bonusP) {
//    damageLow = damL;
//    damageHigh = damH;
//    bonusProperties = bonusP;
//}
//
//void Weapon::display() {
//    cout << name << " is worth " << value << " gold pieces." << endl;
//    cout << "\n \tIt does a minimum of " << damageLow << " and a maximum of " << damageHigh << " points of damage." << endl;
//    cout << "\t\t with the additional property: " << bonusProperties << endl;
//
//}
//
////Armor implementation:
//Armor::Armor(string argN, int argV, string argG) {
//    ArmorDescription = argG;
//}
//
//void Armor::display() {
//    cout << name << " is worth " << value << " gold pieces." << endl;
//    cout << "\n \tArmor has the following properties: " << ArmorDescription << endl;
//}
//
////Magic Ring implementation:
//MagicRing::MagicRing(string argN, int argV, string argG) {
//    RingDescription = argG;
//}
//
//void MagicRing::display() {
//
//    cout << name << " is worth " << value << " gold pieces." << endl;
//    cout << "\n \tTraits of this magic ring: " << RingDescription << endl;
//}
//
////Spell Focus implementation:
//SpellFocus::SpellFocus(string argN, int argV, string argG) {
//    SpellDescription = argG;
//}
//
//void SpellFocus::display() {
//
//    cout << name << " is worth " << value << " gold pieces." << endl;
//    cout << "\n \tTraits of this Spell: " << SpellDescription << endl;
//}
//
////Shield implementation:
//Shield::Shield(string argN, int argV, string argG) {
//    ShieldDescription = argG;
//}
//
//void Shield::display() {
//
//    cout << name << " is worth " << value << " gold pieces." << endl;
//    cout << "\n \tArmor has the following properties: " << ShieldDescription << endl;
//}
//
////Potion implementation:
//Potion::Potion(string argN, int argV, string argG) {
//    PotionDescription = argG;
//
//}
//
//void Potion::display() {
//    cout << name << " is worth " << value << " gold pieces." << endl;
//    cout << "\n \tTraits of this Spell: " << PotionDescription << endl;
//}