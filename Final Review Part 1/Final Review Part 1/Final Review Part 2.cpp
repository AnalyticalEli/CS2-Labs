////Eldy sanchez
//
//
//#include <iostream>
//#include <vector>
//#include <list>
//#include <ctime>
//using namespace std;
//
//
//int rollDie();
//int generateStat();
//const int TABLE_SIZE = 4;
//
//
//struct Loot {
//    string name;
//    int value;
//
//
//    Loot(string arg1 = " ", int arg2 = 0) {
//        name = arg1;
//        value = arg2;
//    }
//
//
//    virtual void display() {
//        cout << name << " is worth " << value << " gold pieces." << endl;
//    }
//};
//
//
//struct Weapon : Loot {
//    int damageLow;
//    int damageHigh;
//    string bonusProperties;
//
//
//    Weapon(string argN, int argV, int damL, int damH, string bonusP) {
//        name = argN;
//        value = argV;
//        damageLow = damL;
//        damageHigh = damH;
//        bonusProperties = bonusP;
//    }
//    virtual void display() {
//        cout << name << " is worth " << value << " gold pieces.";
//        cout << "\n \tIt does a minimum of " << damageLow << " and a maximum of " << damageHigh << " points of damage." << endl;
//        cout << "\t\t with the additional property: " << bonusProperties << endl;
//    }
//};
//
//
//struct Armor : Loot {
//    string ArmorDescription;
//
//
//    Armor(string argN, int argV, string argG) {
//        name = argN;
//        value = argV;
//        ArmorDescription = argG;
//    }
//    virtual void display() {
//        cout << name << " is worth " << value << " gold pieces.";
//        cout << "\n \tArmor has the following properties: " << ArmorDescription << endl;
//    }
//};
//
//
//struct MagicRing : Loot {
//    string RingDescription;
//
//
//    MagicRing(string argN, int argV, string argG) {
//        name = argN;
//        value = argV;
//        RingDescription = argG;
//    }
//    virtual void display() {
//        cout << name << " is worth " << value << " gold pieces.";
//        cout << "\n \tTraits of this magic ring: " << RingDescription << endl;
//    }
//};
//
//
//struct Shield : Loot {
//    string shieldDescription;
//
//
//    Shield(string argN, int argV, string argG) {
//        name = argN;
//        value = argV;
//        shieldDescription = argG;
//    }
//    virtual void display() {
//        cout << name << " is worth " << value << " gold pieces.";
//        cout << "\n \tShield has the following properties: " << shieldDescription << endl;
//    }
//};
//
//
//struct Helm : Loot {
//    string helmDescription;
//
//
//    Helm(string argN, int argV, string argG) {
//        name = argN;
//        value = argV;
//        helmDescription = argG;
//    }
//    virtual void display() {
//        cout << name << " is worth " << value << " gold pieces.";
//        cout << "\n \tHelm has the following properties: " << helmDescription << endl;
//    }
//};
//
//
//struct Bracers : Loot {
//    string bracersDescription;
//
//
//    Bracers(string argN, int argV, string argG) {
//        name = argN;
//        value = argV;
//        bracersDescription = argG;
//    }
//    virtual void display() {
//        cout << name << " is worth " << value << " gold pieces.";
//        cout << "\n \tBracers have the following properties: " << bracersDescription << endl;
//    }
//};
//
//
//struct PlayerChar {
//    string charName;
//    int charLevel;
//    string charJob;
//    int strength;
//    int dexterity;
//    int constitution;
//    int intelligence;
//    int wisdom;
//    int charisma;
//    string charTrait;
//    list<Loot*> gear;
//
//
//    PlayerChar(string name, string job);
//
//
//    virtual void printCharInfo();
//};
//
//
//void addToHashTable(PlayerChar* character);
//void printHashTable();
//vector<list<PlayerChar*>> hashTable(TABLE_SIZE);
//
//
//int main() {
//    srand(time(NULL));
//
//
//    PlayerChar* warrior1 = new PlayerChar("Warrior 1", "Fighter");
//    warrior1->gear.push_back(new Weapon("Sword of Strength", 100, 10, 20, "Increases strength, attack max"));
//    warrior1->gear.push_back(new Armor("Armor of Wisdom", 120, "Increases wisdom, sound like master yoba"));
//    warrior1->gear.push_back(new MagicRing("Ring of Dexterity", 80, "Increases dexterity"));
//    addToHashTable(warrior1);
//
//
//    PlayerChar* wizard1 = new PlayerChar("Wizard 1", "Mage");
//    wizard1->gear.push_back(new Weapon("Staff of Magic", 150, 15, 30, "Increases magic power, I hope"));
//    wizard1->gear.push_back(new Armor("Robe of Intelligence", 130, "Increases intelligence, part time"));
//    wizard1->gear.push_back(new MagicRing("Ring of Mana", 90, "Increases mana pool, still dont know what this is"));
//    addToHashTable(wizard1);
//
//
//    PlayerChar* cleric1 = new PlayerChar("Cleric 1", "Cleric");
//    cleric1->gear.push_back(new Weapon("Mace of Faith", 110, 12, 24, "Increases faith power, go to Mass Jones"));
//    cleric1->gear.push_back(new Armor("Vestments of Piety", 140, "Increases piety, this is how you feel about me in class"));
//    cleric1->gear.push_back(new MagicRing("Ring of Prayer", 70, "Increases prayer power, end of the semester got me like this"));
//    addToHashTable(cleric1);
//
//
//    PlayerChar* rogue1 = new PlayerChar("Rogue 1", "Thief");
//    rogue1->gear.push_back(new Weapon("Dagger of Stealth", 90, 9, 18, "Increases stealth, this is why they call me the border hopper"));
//    rogue1->gear.push_back(new Armor("Leather Armor of Agility", 100, "Increases agility, out run ICE"));
//    rogue1->gear.push_back(new MagicRing("Ring of Speed", 80, "Increases speed, out run immgraiton"));
//    addToHashTable(rogue1);
//
//
//    printHashTable();
//
//
//    for (auto& bucket : hashTable) {
//        for (PlayerChar* character : bucket) {
//            for (Loot* loot : character->gear) {
//                delete loot;// this lovely auto function cleans up the allocated 
//                // memery
//            }
//            delete character;
//        }
//    }
//}
//
//
//int rollDie() {
//    return 1 + rand() % 6;
//}
//
//
//int generateStat() {
//    return rollDie() + rollDie() + rollDie();
//}
//
//
//int hashFunction(string& job) {
//    if (job == "Fighter")
//        return 0;
//    else if (job == "Mage")
//        return 1;
//    else if (job == "Cleric")
//        return 2;
//    else if (job == "Thief")
//        return 3;
//    else
//        return -1;
//}
//
//
//void addToHashTable(PlayerChar* character) {
//    int index = hashFunction(character->charJob);
//    if (index != -1) {
//        hashTable[index].push_back(character);
//    }
//    else {
//        cout << "Invalid job for character: " << character->charName << endl;
//    }
//}
//
//
//void printHashTable() {
//    for (int i = 0; i < TABLE_SIZE; ++i) {
//        cout << "Bucket " << i << ":\n";
//        for (PlayerChar* character : hashTable[i]) {
//            character->printCharInfo();
//        }
//        cout << "------------------------------\n";
//    }
//}
//
//
//PlayerChar::PlayerChar(string name, string job) {
//    charName = name;
//    charJob = job;
//    charLevel = generateStat();
//    strength = generateStat();
//    dexterity = generateStat();
//    constitution = generateStat();
//    intelligence = generateStat();
//    wisdom = generateStat();
//    charisma = generateStat();
//}
//
//
//void PlayerChar::printCharInfo() {
//    cout << "Name: " << charName << "\nJob: " << charJob << "\nLevel: " << charLevel << "\nStats: "
//        << "Strength: " << strength << ", Dexterity: " << dexterity << ", Constitution: " << constitution
//        << ", Intelligence: " << intelligence << ", Wisdom: " << wisdom << ", Charisma: " << charisma
//        << "\nCharacter Trait: " << charTrait << "\nGear:\n";
//    for (Loot* item : gear) {
//        item->display();
//    }
//    cout << endl;
//}