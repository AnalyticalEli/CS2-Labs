
#include <iostream>
#include <cstdlib>
#include <string>
#include <list>
#include <map>
#include <vector>

using namespace std;

struct Loot {
    string name;
    int value;

    Loot(string arg1 = " ", int arg2 = 0) {
        name = arg1;
        value = arg2;
    }

    virtual void display() {
        cout << name << " is worth " << value << " gold pieces." << endl;
    }
};

struct Weapon : Loot {
    int damageLow;
    int damageHigh;
    string bonusProperties;

    Weapon(string argN, int argV, int damL, int damH, string bonusP) : Loot(argN, argV) {
        damageLow = damL;
        damageHigh = damH;
        bonusProperties = bonusP;
    }
    virtual void display() {
        cout << name << " is worth " << value << " gold pieces.";
        cout << "\n \tIt does a minimum of " << damageLow << " and a maximum of " << damageHigh << " points of damage." << endl;
        cout << "\t\t with the additional property: " << bonusProperties << endl;
    }
};

struct Armor : Loot {
    string ArmorDescription;

    Armor(string argN, int argV, string argG) : Loot(argN, argV) {
        ArmorDescription = argG;
    }
    virtual void display() {
        cout << name << " is worth " << value << " gold pieces.";
        cout << "\n \tArmor has the following properties: " << ArmorDescription << endl;
    }
};

struct MagicRing : Loot {
    string RingDescription;

    MagicRing(string argN, int argV, string argG) : Loot(argN, argV) {
        RingDescription = argG;
    }
    virtual void display() {
        cout << name << " is worth " << value << " gold pieces.";
        cout << "\n \tTraits of this magic ring: " << RingDescription << endl;
    }
};

struct Shield : Loot {
    string ShieldDescription;

    Shield(string argN, int argV, string argG) : Loot(argN, argV) {
        ShieldDescription = argG;
    }
    virtual void display() {
        cout << name << " is worth " << value << " gold pieces.";
        cout << "\n \tTraits of this shield: " << ShieldDescription << endl;
    }
};

struct Necklace : Loot {
    string NecklaceDescription;

    Necklace(string argN, int argV, string argG) : Loot(argN, argV) {
        NecklaceDescription = argG;
    }
    virtual void display() {
        cout << name << " is worth " << value << " gold pieces.";
        cout << "\n \tTraits of this necklace: " << NecklaceDescription << endl;
    }
};

struct Potion : Loot {
    string PotionDescription;

    Potion(string argN, int argV, string argG) : Loot(argN, argV) {
        PotionDescription = argG;
    }
    virtual void display() {
        cout << name << " is worth " << value << " gold pieces.";
        cout << "\n \tTraits of this potion: " << PotionDescription << endl;
    }
};


int generateStat(void);
int rollDie(void);

struct playerChar {
    string charName;
    string charJob;
    string charTrait1;
    string charTrait2;
    int charLevel = rollDie();
    int charStrength = generateStat();
    int charDexterity = generateStat();
    int charConstitution = generateStat();
    int charIntelligence = generateStat();
    int charWisdom = generateStat();
    int charisma = generateStat();

    playerChar(string stringN, string stringJ, string stringT1, string stringT2);
    void printCharInfo(void);
};

void simplePrintTable(list<playerChar*> arg[], int size);

// comparators
bool compareLootByName(Loot* arg1, Loot* arg2) {
    bool answer = (arg1->name < arg2->name);
    return answer;
}

bool compareLootByValue(Loot* arg1, Loot* arg2) {
    bool answer = (arg1->value > arg2->value);
    return answer;
}

int hashFunction(playerChar& charArg) {
    char temp = tolower(charArg.charJob[0]);

    if (temp == 'm') {
        return 0;
    }
    else if (temp == 'w') {
        return 1;
    }
    else if (temp == 'c') {
        return 2;
    }
    else if (temp == 't') {
        return 3;
    }
    return -1;
}

int main(void) {

    list<Loot*> lootList;
    vector<playerChar*> characterList;
    list<playerChar*> hashTable(12);

    string charNameHash;

    characterList.push_back(new playerChar("Bartholomew", "Warrior", "Mundane", "Headbutt"));
    characterList.push_back(new playerChar("Archibald", "Warrior", "Poor", "Split the bill"));
    characterList.push_back(new playerChar("Aldous", "Warrior", "Affluent", "Moneymaker"));
    characterList.push_back(new playerChar("Baldwin", "Mage", "Unpredictable", "Explode"));
    characterList.push_back(new playerChar("Col", "Mage", "Studious", "Flameburst"));
    characterList.push_back(new playerChar("Orion", "Mage", "Magnanimous", "Lightning"));
    characterList.push_back(new playerChar("Aldreda", "Cleric", "Tree Speaker", "Growth"));
    characterList.push_back(new playerChar("Cassian", "Cleric", "Indecisive", "Flee"));
    characterList.push_back(new playerChar("Bertram", "Cleric", "Pious", "Prayer"));
    characterList.push_back(new playerChar("Amice", "Thief", "Nimble", "Scurry"));
    characterList.push_back(new playerChar("Arat", "Thief", "Swift", "Dash"));
    characterList.push_back(new playerChar("Athief", "Thief", "Silent", "Sneak"));

    lootList.push_back(new Armor("Rusted Chainmail", 60, "better than nothing"));
    lootList.push_back(new Weapon("Old Mace", 60, 30, 50, "-2 against Slimes"));
    lootList.push_back(new Shield("Shattered Shield", 80, "To protect your good side"));
    lootList.push_back(new MagicRing("Silver Ring", 150, "It hasn't been polished in years"));

    list<Loot*>::iterator itrLoot;
    itrLoot = lootList.begin();

    map<string, list<Loot*>> character;
    map<string, list<Loot*>>::iterator itrMap;

    //Warrior loot
    character["Bartholomew"] = lootList;
    character["Archibald"].push_back(new Armor("New Chainmail", 120, "The links glisten in the light"));
    character["Archibald"].push_back(new Weapon("Chipped Sword", 90, 60, 80, "+1 Bleeding"));
    character["Archibald"].push_back(new Shield("Wooden Door", 40, "They say the tavern is drafty to this day"));
    character["Archibald"].push_back(new Necklace("Lucky Cord", 10, "One man's trash..."));
    character["Aldous"].push_back(new Armor("Full Plate", 500, "Protection against most physical attacks"));
    character["Aldous"].push_back(new Weapon("War Hammer", 180, 100, 120, "+2 against Heavy Armor"));
    character["Aldous"].push_back(new MagicRing("Ring of Agility", 400, "Keeps you nimble in the heaviest of armor"));
    character["Aldous"].push_back(new Potion("Potionseller's Potion", 750, "His strongest potion."));
    //Mage loot
    character["Baldwin"].push_back(new MagicRing("Person Explodus", 400, "Single Use"));
    character["Baldwin"].push_back(new Weapon("Oak Staff", 100, 60, 75, "+1 against wand users"));
    character["Baldwin"].push_back(new Necklace("10 Leaf Clover", 1000, "An experiment in Luck potions"));
    character["Baldwin"].push_back(new Potion("Wizard's Brew", 180, "Relax with a cold Wizard's Brew."));
    character["Col"].push_back(new Armor("Enchanted Plate", 500, "Reflect 3 spells with minimal effort"));
    character["Col"].push_back(new Weapon("Ashen Wand", 320, 50, 65, "+4 constitution against Nature"));
    character["Col"].push_back(new Necklace("Lich's Ear", 400, "A gross puzzle piece"));
    character["Col"].push_back(new Potion("Liquid Courage", 90, "When you need to ask the Archmage for a raise."));
    character["Orion"].push_back(new Armor("Starry Hat", 460, "A beacon in the dark"));
    character["Orion"].push_back(new Weapon("Meteor", 800, 90, 130, "+3 chance to grant concussion"));
    character["Orion"].push_back(new Necklace("Newt's Eye", 55, "Keep an eye out"));
    character["Orion"].push_back(new Potion("Pain-Away", 90, "For the clumsy adventurer."));
    //Cleric loot
    character["Aldreda"].push_back(new Armor("Grassy Boots", 70, "Plants sprout from these old boots"));
    character["Aldreda"].push_back(new Weapon("Late Woodcutter's Axe", 90, 50, 65, "+3 against Lumberjacks"));
    character["Aldreda"].push_back(new Necklace("Water's Blessing", 230, "A gift of water from the river"));
    character["Aldreda"].push_back(new Potion("Fertilizer", 90, "For the gardener in need."));
    character["Cassian"].push_back(new Armor("Leather Cap", 40, "To keep your head warm"));
    character["Cassian"].push_back(new Weapon("Small Sword", 90, 50, 65, "-3 against Tall People"));
    character["Cassian"].push_back(new Necklace("Grass Necklace", 25, "Stay grounded"));
    character["Cassian"].push_back(new Potion("Pain-Away", 90, "For the clumsy adventurer."));
    character["Bertram"].push_back(new Armor("Leather Boots", 50, "For kicking"));
    character["Bertram"].push_back(new Weapon("Heavy Axe", 90, 50, 65, "-1 Dexerity"));
    character["Bertram"].push_back(new Necklace("Chainmail Scarf", 25, "Keep your head on your shoulders"));
    character["Bertram"].push_back(new Potion("Antidote", 110, "Use within 15 minutes of a poisoning."));
    //Thief loot
    character["Amice"].push_back(new Armor("Endless Belt", 300, "A belt with a seemingly endless number of compartments"));
    character["Amice"].push_back(new Weapon("Small Dagger", 90, 35, 150, "+3 against ankles"));
    character["Amice"].push_back(new Necklace("Jeweler's Amulet", 450, "An easy mark"));
    character["Amice"].push_back(new Potion("Pain-Away", 90, "For the clumsy adventurer."));
    character["Arat"].push_back(new MagicRing("Ring of Sticky Fingers", 600, "+5 to Pickpocket Coins"));
    character["Arat"].push_back(new Weapon("Sharp Dagger", 230, 50, 100, "+1 against Coin Purses"));
    character["Arat"].push_back(new Necklace("Engagement Present", 430, "Taken from the bride to be"));
    character["Arat"].push_back(new Potion("Poison", 120, "For a botched robbery."));
    character["Athief"].push_back(new Armor("Thief's Hood", 140, "Disappear into the shadows"));
    character["Athief"].push_back(new Weapon("Club", 200, 70, 90, "+1 to Armor"));
    character["Athief"].push_back(new MagicRing("Thief's Ring", 310, "+2 to lockpicking"));
    character["Athief"].push_back(new Potion("Feather Weight", 450, "Jump to great heights."));


    const int size = 12;

    list<playerChar*> myHash[size];
    int count = 0;
    do {
        playerChar* temp = characterList[count];
        int i = hashFunction((*characterList[count]));

        myHash[i].push_back(temp);

        count++;
    } while (count < 12);

    simplePrintTable(myHash, 4);

    cout << endl;


    for (itrMap = character.begin(); itrMap != character.end(); itrMap++) {
        (*itrMap).second.sort(compareLootByName);

        cout << "\t" << (*itrMap).first << "'s Loot: " << endl;
        cout << "--------------------------" << endl;
        for (itrLoot = (*itrMap).second.begin(); itrLoot != (*itrMap).second.end(); itrLoot++) {
            (*itrLoot)->display();
            cout << endl;
        }
    }


    return 0;
}

// character stat generator functions

int rollDie(void) {
    return 1 + rand() % 6;
}

int generateStat(void) {
    return rollDie() + rollDie() + rollDie();
}

playerChar::playerChar(string stringN, string stringJ, string stringT1, string stringT2)
{
    charName = stringN;
    charJob = stringJ;
    charTrait1 = stringT1;
    charTrait2 = stringT2;
}

void playerChar::printCharInfo(void) {
    cout << "\n\n" << charName << " the " << charTrait1 << "\n" << "Level " << charLevel << " " << charJob << endl;
    cout << "Strength: " << charStrength << endl;
    cout << "Dexterity: " << charDexterity << endl;
    cout << "Constitution: " << charConstitution << endl;
    cout << "Intelligence: " << charIntelligence << endl;
    cout << "Wisdom: " << charWisdom << endl;
    cout << "Charisma: " << charisma << endl;
    cout << charName << "'s favorite move is " << charTrait2 << endl << endl;


}

void simplePrintTable(list<playerChar*> arg[], int size) {
    list<playerChar*>::iterator myItr;

    for (int i = 0; i < size; i++) {
        cout << "bucket " << i << " ==> ";
        myItr = arg[i].begin();

        while (myItr != arg[i].end()) {
            cout << (*myItr)->charName << ", " << (*myItr)->charLevel << " : ";
            (*myItr)->printCharInfo();
            myItr++;
        }
        cout << endl;
    }
}