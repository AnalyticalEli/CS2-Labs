////Eli Ahmed
////Final Project: Hash Tables with DnD Characters + Loot
//
//
//////HIGHLY RECOMMEND Listening to this while reading the lore on output for immersion.
//////https://youtu.be/Sww2K8e4Kdk?si=r3mRSq5ytmQaQQ0X
//
//#include<iostream>
//#include<string>
//#include<vector>
//#include<ctime>  //For srand seed time
//#include<cstdlib>  //For srand seed time
//#include<list>
//#include<utility>  //For making our code look Pretty In the printCharInfo()
//
//
//using namespace std;
//
////Wanted to make an interesting program. (You said have fun ;))
//
//
////So everytime we create a new struct in the main for example: new Weapon, we msut input all values
////within the new Weapon Object.
//
//
//struct Loot {  //Probably need to do a loot PTR to point to the object here:
//
//    //Loot* left;
//    //Loot* right;
//    string name;
//    int value;
//
//    Loot(string arg1 = " ", int arg2 = 0) {
//        name = arg1;
//        value = arg2;
//    }
//
//    virtual void display() {
//
//        cout << "\n" << name << " is worth " << value << " gold pieces.";
//
//
//
//    }
//};
//
//class PlayerChar {    //Putting it AFTER LOOT Because IT is Dependent 
//
//private:
//
//    string name;
//
//    int level;  //Levels are usually int, imagine being lvl 11.5
//
//    string charJob, charTraitUno, charSpecialization;
//
//    int strength, dexterity, constitution, intellegence, wisdom, charisma;
//
//    list<Loot*> charGear;
//
//
//public:
//
//    //Constructor Prototype
//    PlayerChar(string cName = "no name", int cLevel = 0, string cJob = "no job", string charUno = "no skills (noob)",
//        string charDos = "no specialized skill (git gud)", int cStrength = 0, int cDexterity = 0, int cConstitution = 0,
//        int cIntelligence = 0, int cWisdom = 0, int cCharisma = 0); //Initialiazing base case for constructor.
//    //In case no value is input.
//
//
////Accessor Nethods 
//
//
//    void setName(string argC);   //Set Methods for Accessor methods
//    void setLevel(int argL);
//    void setJob(string argJob);
//    void setCharTraitUno(string argCharOne);
//    void setCharTraitDos(string argCharTwo);
//    void setStrength(int argS);  //THINKING ABOUT USING INT FOR ALL SINCE ITS 3-18 (Normal 10-11) 
//    void setDexterity(int argD);
//    void setConstitution(int argCon);
//    void setIntelligence(int argI);
//    void setWisdom(int argWis);
//    void setCharisma(int argRizz);
//    void setLoot(list<Loot*> argLoot); //Set Method for Loot<List>
//
//
//    string getName(void);   //Get Methods for accessor methods.
//    int getLevel(void);
//    string getJob(void);
//    string getCharTraitUno(void);
//    string getCharTraitDos(void);
//    int getStrength(void);
//    int getDexterity(void);
//    int getConstitution(void);
//    int getIntelligence(void);
//    int getWisdom(void);
//    int getCharisma(void);
//    list<Loot*> getGear(void);  //Get method for List<Loot*> 
//
//
//    //Base class Utility Method (NOT NEEDED THIS TIME, SINCE CLASSES ARE NO LONGER....CLASSES
//
//    void addMyGear(Loot* gear);
//
//    //Might wamt to have an add Loot function:             that adds Loot (list<Loot*> charLoot)
//   //then adds a new node for the list<Loot*> charLoot:    charLoot.push_back(new.....)
//   //then maybe a function that calls on a comparator:     charLoot.sort(compareLootByValue)
//
//
//    void printCharInfo(void); //When Initiliazing with = 0, this locks us in and forcs us to use printStats() for calculation in
//    //in each.   
//
//};   //Putting it AFTER LOOT Because IT is Dependent 
//
//
//struct Weapon : Loot {
//    int damageLow;
//    int damageHigh;
//    string bonusProperties;
//
//    Weapon(string argN, int argV, int damL, int damH, string bonusP) : Loot(argN, argV) {
//        damageLow = damL;
//        damageHigh = damH;
//        bonusProperties = bonusP;
//    }
//    void display() {
//
//        Loot::display();  //Displays value and name of gear
//        cout << "\nIt does a minimum of " << damageLow << " and a maximum of " << damageHigh << " points of damage." << endl;
//        cout << "With the additional property: " << bonusProperties << endl;
//    }
//};
//
//struct Armor : Loot {
//    string ArmorDescription;
//
//    Armor(string argN, int argV, string argG) : Loot(argN, argV) {
//        ArmorDescription = argG;
//    }
//    void display() {
//
//        Loot::display();  //Displays value and name of gear
//        cout << "\nArmor has the following properties: " << ArmorDescription << endl;
//    }
//};
//
//struct MagicRing : Loot {
//    string RingDescription;
//
//    MagicRing(string argN, int argV, string argG) : Loot(argN, argV) {
//        RingDescription = argG;
//    }
//    void display() {
//        Loot::display();  //Displays value and name of gear
//        cout << "\nTraits of this magic ring: " << RingDescription << endl;
//    }
//};
//
//
////5 additional structs that Inherent From Loot  (2 Extra Ones FOR FUN) 
//// (Thinking: Enchanted Vambraces, Draconic Summoning, Stick named Alfred.)
//
//
//struct EnchantedVambraces : Loot {  //Like regular vambraces BUT ENCHANTED
//
//    string vambraceDescription;
//
//    EnchantedVambraces(string argN, int argV, string argVam) : Loot(argN, argV) {  //Must Input the Loot Values first in Constructor
//
//        vambraceDescription = argVam;
//    }
//
//    void display() {  //Should have the info from printCharInfo Above that prints before hand.
//        //Might want to use a vector that encapsulates values from PlayerChar
//
//        Loot::display();  //Displays value and name of gear
//
//        cout << "\nTraits of the bodacious behemoth: " << vambraceDescription << endl;
//
//    }
//
//};
//
//
//struct SummoningScroll : Loot {
//
//    string scrollDescription;
//
//    SummoningScroll(string argN, int argV, string argSummy) : Loot(argN, argV) {  //Must Input the Loot Values first in Constructor
//
//        scrollDescription = argSummy;
//    }
//
//    void display() {
//
//        Loot::display();  //Displays value and name of gear
//
//        cout << "\nTraits of the wondrous scroll: " << scrollDescription << endl;
//
//    }
//
//
//};
//
//
//struct CursedScroll : Loot {
//
//    string scrollDescription2;
//
//    CursedScroll(string argN, int argV, string argSummyy) : Loot(argN, argV) {  //Must Input the Loot Values first in Constructor
//
//        scrollDescription2 = argSummyy;
//    }
//
//    void display() {
//
//        Loot::display();  //Displays value and name of gear
//
//        cout << "\nTraits of the cursed catastrophic scroll: " << scrollDescription2 << endl;
//
//    }
//
//
//};
//
//
////Below is if you decide to stay with your idea (in your cannon) of having a positive ability trait that is amplified by Alfred Stick and a negative Character trait that is amplified by stick.
//
//struct AlfredStick : Loot {  //He's a pretty cool guy.   (MIGHT PUT SEPERATE TRAITS, argStickP (Postiive Traits), argStickN (Negative Traits ))
//
//    string stickDescriptionPos;  //Positive trait
//
//    string stickDescriptionNeg;  //Negative trait
//
//
//    AlfredStick(string argN, int argV, string argStickP, string argStickN) : Loot(argN, argV) {  //Must Input the Loot Values first in Constructor
//
//        stickDescriptionPos = argStickP;
//
//        stickDescriptionNeg = argStickN;
//    }
//
//    virtual void display() {  //Chose whether it goes on top or bottom 
//
//        cout << "\n\n*DISCLAIMER* Beware everyone who has equipped the AlfredStick before you has either died or gone mad." << endl;
//
//        Loot::display();  //Displays value and name of gear
//
//        cout << "\nStrongest Ability of the bodacious behemoth aka the final savoiur of humanity: " << stickDescriptionPos << endl;
//
//        cout << "\nNegative Character Trait of the bodacious behemoth aka the final savoiur of humanity : " << stickDescriptionNeg << endl << endl;
//
//        //cout << "\n\n *DISCLAIMER* Beware everyone before you who has equipped the AlfredStick has either died or gone mad. " << endl;
//
//    }
//};
//
//
//// Comparator Prototypes & C-type Functions]
//bool compareLootByName(Loot* arg1, Loot* arg2);  //Compares Loot by Name in ascending order. (A-Z) 
//
//bool compareLootByValue(Loot* arg1, Loot* arg2);  //Compares Loot by Ascending Value (1-highest level)
//
//bool comparePeeps(PlayerChar* arg1, PlayerChar* arg2);  //Compares PlayerChar Things In Order: Name (If same) then Rank (If Same) Then First Skill
//
//int firstChar(string arg);  //This is to ensure that if the USER or Programmer makes a mistake it will autocorrect it to a lower case JOB
//
//int rollDie(void); //Generates random num 1-6
//
//int generateStat(void); //3 dice rolls gives you 3 to 18 for stats 
//
//string displayLore1(void);  //Displays the Lore of our ancient kingdom in the Ouput Console.
//
//string displayLore2(void);  //Displays 2nd Piece of Lore in Ancient kingdom.
//
//
//
//int main(void) {
//
//    //Showing the EASY & DIFFICULT WAY TO DO THIS...FOR SCIENCE (TO SHOWOFF REALLY) 
//
//    srand(time(0));  //Seeding random time
//
//    displayLore1();
//
//    //Defining Keys for JOBS 
//    //int key1, key2, key3, key4;  //Defining the key for the Job Titles (Mage, Fighter (Paladin), Cleric, Ignis
//
//    int gen = generateStat();  //To make the code CLEANER in the list below.
//    const int jobBucketSize = 4;  //Bucket size for the Job Title (Will print only 4, because it'll stop at 5 with an extra space needed for null space)
//    //string jobs;  Get rid of no longer need because you defined jobs in for(auto) loop
//
//    const int myCharsSize = 13;
//
//
//    //HashTable Development:
//    list<PlayerChar*> myChars[jobBucketSize];//[myCharNames];  //2d Array We're going to want both Job title and Name or
//    list<PlayerChar*>::iterator itrChar;  //Iterator for Print Function Below
//
//    //cout << "Phase 1 Works" << endl;  //Testing
//
//    //Only unlock their second skill at 17. (COULD INPUT RANDOM LIST OF SKILLS FOR EACH CLASS, THAT CHANGES EVERYTIME YOU RUN IT);
//
//
//    PlayerChar* Protagonist = new PlayerChar("Steel ja Art", 14, "Theif", "Swindle", "", gen, gen, gen, gen, gen, gen);  //Our Theif
//    Protagonist->addMyGear(new Weapon("Cloak of Invisibility", 33, 77, 44, "Cat"));  //Gear Name, Level
//    Protagonist->addMyGear(new AlfredStick("Cat", 44, "Makes big Funni", "MAkes small Mind"));  //Gear Name, Level
//    Protagonist->addMyGear(new MagicRing("Rusty Knife", 33, "Cat"));  //Gear Name, Level
//
//    PlayerChar* Protagonist2 = new PlayerChar("Lady Peace", 15, "Paladin", "Cascading Swing", "", gen, gen, gen, gen, gen, gen);   //Super Fighter Type
//    Protagonist2->addMyGear(new Weapon("Sword of Death", 220, 20, 99, "15 % Chance of Insta-Kill"));  //Gear Name, Level
//    Protagonist2->addMyGear(new Armor("Berserker Armour", 333, "Ignis Domni"));  //Gear Name, Level
//    Protagonist2->addMyGear(new EnchantedVambraces("Achilles Amar", 240, "Defense + 20%"));  //Gear Name, Level
//
//    PlayerChar* Protagonist3 = new PlayerChar("Redden", 22, "Cleric", "Smite the with Sarcasm", "AI Overlords", gen, gen, gen, gen, gen, gen);  //Cleric
//    Protagonist3->addMyGear(new SummoningScroll("AI Apocolypse", 400, "Summons every (possible) Terminator, and Skynet as an ally in battle"));  //Gear Name, Level
//    Protagonist3->addMyGear(new Weapon("Machine Learning", 500, 19, 49, "The longer the battle goes on, the higher crit hit % is."));  //Gear Name, Level
//    Protagonist3->addMyGear(new SummoningScroll("Scroll Incantation", 700, "Prayer to the AI Lords for a random stat boost."));  //Gear Name, Level
//
//    PlayerChar* Protagonist4 = new PlayerChar("Ignis", 98, "Mage", "Obsidian Flame (Roast)", "Dreadful Tempest", gen, gen, gen, gen, gen, gen);   //Mage
//    Protagonist4->addMyGear(new SummoningScroll("Horrifying Almanac", 900, "Steals Memories and Abilites, and implants them with ones of User's choice"));  //Gear Name, Level
//    Protagonist4->addMyGear(new MagicRing("Element Morir", 800, "Protects Against All Elemental Attacks"));  //Gear Name, Level
//    Protagonist4->addMyGear(new AlfredStick("Alfred Stick", 0, "Hidden Wisdom", "Madness"));  //Gear Name, Level  
//
//    //******************Recommend Looking at the Descriptions for the weapons to get context for the story/lore.*****************************************
//
//
//    //Inputting Jobs Now with Accessor methods above (Makes my code more easily switchable later (since there's only 4 classes))
//
//    PlayerChar* antagonistLackey = new PlayerChar("Sinister Samurai", 21, "Paladin", "Wisp Away (Flame Engulfing Weapon 4 turns) ", "", gen, gen, gen, gen, gen, gen);
//    antagonistLackey->addMyGear(new Weapon("Unwavering Katana", 110, 19, 28, "Constitution + 10%"));  //Gear Name, Level
//    antagonistLackey->addMyGear(new EnchantedVambraces("Susami", 400, "Protects user from insta-death + 15% Defense"));  //Gear Name, Level
//    antagonistLackey->addMyGear(new MagicRing("Inherited Ring", 100, "A Wisp of flame engulfing weapon + 15% attack & chance of burn affect"));  //Gear Name, Level
//
//    PlayerChar* antagonistLackey2 = new PlayerChar("Unpaid Intern", 1, "Cleric", "Cup of Noodles", "", gen, gen, gen, gen, gen, gen);
//    antagonistLackey2->addMyGear(new Weapon("No Sleep", 344, 10, 44, "+ 15% Attack, and + 35% Intelligence"));  //Gear Name, Level
//    antagonistLackey2->addMyGear(new SummoningScroll("Ego Death", 2, "Defense up 44%, but lowers attack."));  //Gear Name, Level
//    antagonistLackey2->addMyGear(new SummoningScroll("Competition in the Halls", 777, "Boosts attack, defense, agility in team."));  //Gear Name, Level
//
//    PlayerChar* antagonistLackey3 = new PlayerChar("Mediocre Research Advisor", 13, "Theif", "Pelifered Published Papers", "", gen, gen, gen, gen, gen, gen);  //This is cheeky fun, no offense intended for Job Applications. 
//    antagonistLackey3->addMyGear(new SummoningScroll("Intern Barrage", 444, "Summons a band of unpaid interns, to distract and attack enemy. Gives you an extra turn."));  //Gear Name, Level
//    antagonistLackey3->addMyGear(new Weapon("Ego Killer", 22, 10, 22, "15-50% Higher Chance of Higher Critical Hit & +40% Accuracy"));  //Gear Name, Level
//    antagonistLackey3->addMyGear(new CursedScroll("Gaslighting", 700, "60% of Tricking Enemy Combantant to attack their own teammate, if no teammate then damages self."));  //Gear Name, Level
//
//    PlayerChar* antagonistBoss = new PlayerChar("Dilion aka Dill Pickle", 85, "Mage", "MatLab Matrix Master", "Calc Killer", gen, gen, gen, gen, gen, gen);
//    antagonistBoss->addMyGear(new Armor("Naughty Nostradamus", 555, "Allows user to predict 2 turns ahead."));  //Gear Name, Level
//    antagonistBoss->addMyGear(new MagicRing("Currie's Cure", 600, "Gives user + 30% HP back and cures some status effects. (Does Not heal poision)"));  //Gear Name, Level
//    antagonistBoss->addMyGear(new AlfredStick("Perfect Alfred Stick", 0, "Suppressed Intellgence", "Untamable Vitriol"));  //Gear Name, Level
//
//
//
//    //************************************Twists Characters (New Instantce)***********************************************
//
//    PlayerChar* newProtagonist4 = new PlayerChar{ "Juan Wrecker of Turtles", 65, "Paladin", "C++ Stagger", "Damiano's Mate (Sacrificial Check Mate)", gen, gen, gen, gen, gen, gen };
//    newProtagonist4->addMyGear(new Weapon("Arduino Saber", 750, 66, 69, "High Chance of Causing shock & Low Chance of Causing Bleeding (If left untreated for 5 turns insta-death). "));  //Gear Name, Level
//    newProtagonist4->addMyGear(new MagicRing("Willpower", 500, "Allows user to remain standing after HP reaches 0, and insane attack boost"));  //Gear Name, Level
//    newProtagonist4->addMyGear(new Armor("Main Character Energy", 444, "Enemies less likely to critcal damage on you. "));  //Gear Name, Level
//
//    PlayerChar* antagonistTurnedProtagonist = new PlayerChar("Dill Pickle The Wise", 97, "Mage", "MatLab Matrix Master", "Differential Dismantler", gen, gen, gen, gen, gen, gen);
//    antagonistTurnedProtagonist->addMyGear(new Weapon("A modified version of Alfred Stick to delay madness", 720, 70, 88, "Supressed Intellegence & Grand Wisdom"));  //Gear Name, Level
//    antagonistTurnedProtagonist->addMyGear(new Armor("Pouty Poisson", 720, "Allows user to predict any future outcome of battle"));  //Gear Name, Level
//    antagonistTurnedProtagonist->addMyGear(new MagicRing("Cantor's Cataclysm", 900, "Allows for an infinite perfect regenation in an infinitesimally small fraction of time"));  //Gear Name, Level
//
//    PlayerChar* NPC = new PlayerChar("Worshipper of Ye Olde Legend", 11, "Cleric", "Jefe Worship", "", gen, gen, gen, gen, gen, gen);
//    NPC->addMyGear(new Weapon("Jefe's Wise Words", 22, 10, 22, "15-50% Higher Chance of Higher Critical Hit & +40% Accuracy"));  //Gear Name, Level
//    NPC->addMyGear(new Armor("The armor of Jefe's Acceptance", 888 /* Priceless*/, "Gives user to defy odds and become a REAL Programme....I mean better, once near death"));  //Gear Name, Level
//    NPC->addMyGear(new EnchantedVambraces("Jefe's Witty Rage", 555, "Increases Attack 30% & Defense 40%, Decreases Accuracy."));  //Gear Name, Level
//
//    PlayerChar* dlcChar = new PlayerChar("Judas Jealous", 22, "Theif", "Baldur's Betrayal", "Soul Stealing ((1%) of insta-death)", gen, gen, gen, gen, gen, gen);
//    dlcChar->addMyGear(new Weapon("Shami", 250, 39, 65, "An invisible short sword."));  //Gear Name, Level
//    dlcChar->addMyGear(new MagicRing("Kiss of Suffering", 222, "Casts Negative Debuffs On Enemy Team + 20% Added Damage"));  //Gear Name, Level
//    dlcChar->addMyGear(new EnchantedVambraces("Michevelli Sunday", 800, "Steels 7 Given Items From Enemy Player"));  //Gear Name, Level
//
//
//    ////**********************Since I know Jefe is a dark side enjoyer & He Plays Mage/Wizard (ALSO SPOILER)*********************************************************************************************
//
//    PlayerChar* BBEG = new PlayerChar("Jefe the Invincible aka Ignis Final Form", 99, "Mage", "Cometfall", "Stardust Cinders the Ego Eviscerator", gen, gen, gen, gen, gen, gen);  //Homage to the Thursday Maps
//    BBEG->addMyGear(new Armor("Cosmic Cathederal Knight Armor", 988, "Protects against MOST physical attacks, and ALL ELEMENTAL ATTACKS"));  //Gear Name, Level
//    BBEG->addMyGear(new MagicRing("Ophanim", 966, "Provides God-Like Teleportation Speed"));  //Gear Name, Level
//    BBEG->addMyGear(new CursedScroll("Resurrection, Champion of Ye Olde", 998, "Summons the Last Hero and their legion of dragons"));  //Gear Name, Level
//    BBEG->addMyGear(new AlfredStick("Alfred Stick", 0, "Unwanted Wisdom", "World-Dominination"));
//
//    //Sort the buckets based on the character Name or character Level, (THIS WILL BE IN THE FOR LOOP (GIANT ONE BELOW) SORT BY NAMe
//
//
//
//    //First Sorting Jobs (Theif, Paladin, Cleric, Mage). 
//
//    //Using Auto (Treating the Object Ptrs as elements). Also using List allows us to use iterators below!! (Below the for(auto) loop) 
//
//    list<PlayerChar*> vecEntireCast = { Protagonist, Protagonist2, Protagonist3, Protagonist4, antagonistLackey, antagonistLackey2, antagonistLackey3, antagonistBoss, newProtagonist4, antagonistTurnedProtagonist,
//                                        NPC, dlcChar, BBEG };
//
//
//    for (auto vecC : vecEntireCast) {  //goes through vecEntireCast and pulls out each PlayerChar* at at time
//        //More specifically it makes sorting the keys easier, as it essentially automates
//        //The process for us.
//
//        //For the way I set this up indexing by job, I need to set up a table that
//        //associates values with certain jobs BECAUSE without each Job
//       //sorting is MEANINGLESS as THEY ARE NOT UNIQUE VALUES, they repeat unlike Names.
//       //I want my program to account for this.
//
//        string jobChar = (vecC->getJob());  //Don't want to repeat vecC->getJob(); For each line
//
//        if (jobChar == "Cleric") {
//
//            myChars[0].push_back(vecC);   //First Index of the Hash Table (C++ starts at zero) 
//
//        }
//        else if (jobChar == "Paladin") {
//
//            myChars[1].push_back(vecC);      //Second Index of the HashTable (1)
//        }
//        else if (jobChar == "Theif") {
//
//            myChars[2].push_back(vecC);   //Third Index of the hashtable (2) 
//        }
//        else {
//
//            myChars[3].push_back(vecC);
//
//        }
//
//    }
//
//
//    //Starting our iterator at the beginning of the vecEntireCast list above:
//
//    itrChar = vecEntireCast.begin();   //Might need to change this, why do you want to print this?
//
//
//    //Origianl one you were doing 
//    for (int i = 0; i < jobBucketSize; i++) { // names[i].at(j), cout everything in it. 12 For the Characters
//        //for (int j = 0; j < jobBucketSize; j++) {  //4 Bucket Values (Jobs: Theif, Cleric, Mute
//        if (!myChars[i].empty()) {  // if the ith letter has any names in it, otherwise skip
//            myChars[i].sort(comparePeeps);  // comparePeepsCompares, by Name, then Level then skill One. (Didn't need to be this extensive, but wanted to be sure code is extensible)
//            for (itrChar = myChars[i].begin(); itrChar != myChars[i].end(); itrChar++) {  //Wanted to make it a bit MORE difficult so force myself to use an iterator instead of auto
//
//                cout << "\nNext Character:\n" << endl;
//                cout << "**************************************************************" << endl;
//
//                (*itrChar)->printCharInfo();  //Use Display Method FOr loot to show all Loot Chararacter HAS!!!
//
//
//                ////Memory Deallocation (Since we (hypothetically) don't know size of the list we deallocate at the storing and 
//               //sorting of each. In the iterator. IT must loop around constantly (for loop) so it'll deallocate each for us.
//
//                delete* itrChar;
//
//                *itrChar = nullptr;
//
//            }
//        }
//    }
//
//
//
//
//    //********************************************Alternatively if you wanted to HARD-CODE it, instead of AUTO I have code below to show how EASY IT IS:*****************************************************
//
//     //Tried keys (keys 1, 2, 3, 4) didn't work (aka very similar to above), so hard-coded them FULLY. 
//
//     //  
//     // //All of the theifs
//     // myChars[firstChar(Protagonist->getJob())].push_back(Protagonist);  //Protag
//     // myChars[firstChar(antagonistLackey3->getJob())].push_back(antagonistLackey3);  //Protag
//     // myChars[firstChar(dlcChar->getJob())].push_back(dlcChar);  //Protag 
//
//     // //All of the Paladins
//     // myChars[firstChar(Protagonist2->getJob())].push_back(Protagonist2);      //Protag
//     // myChars[firstChar(antagonistLackey->getJob())].push_back(antagonistLackey);  //Protag
//     // myChars[firstChar(newProtagonist4->getJob())].push_back(newProtagonist4);       //Protag
//
//     // //All of the Clerics
//     // myChars[firstChar(Protagonist3->getJob())].push_back(Protagonist3);  //Protag
//     // myChars[firstChar(antagonistLackey2->getJob())].push_back(antagonistLackey2);  //Protag
//     // myChars[firstChar(NPC->getJob())].push_back(NPC);  //Protag
//
//     // //All of the Mages
//     // myChars[firstChar(Protagonist4->getJob())].push_back(Protagonist4);  //Protag
//     // myChars[firstChar(antagonistBoss->getJob())].push_back(antagonistBoss);  //Protag;  //Protag
//     // myChars[firstChar(antagonistTurnedProtagonist->getJob())].push_back(antagonistTurnedProtagonist);  //Protag
//     // myChars[firstChar(BBEG->getJob())].push_back(BBEG);  //Protag
//
//
//
//     // cout << "Passed 2" << endl;
//
//
//     // //itrChar = vecEntireCast.begin();   //Might need to change this, why do you want to print this? 
//
//     ////Origianl one you were doing 
//     // 
//     // for (int i = 0; i < myCharsSize; i++) {
//     //     for (int j = 0; j < jobBucketSize; j++) {
//     //         //Starting the for loop at the beginning and sorting through all Characters  incrementally 
//     //         if (!myChars[i].empty()) {  // if the ith letter has any names in it, otherwise skip
//
//     //             cout << "Jobs In Alphabetical Order" << endl;
//
//     //             cout << "************************************" << endl;
//
//     //             myChars[i].sort(comparePeeps);
//     //             for (auto myCharact : myChars[i]) {  // auto chooses the datatype for you, with or w/o Pointers
//     //                 myCharact->printCharInfo(); //for the auto loop!
//
//                        //Memory Deallocation
//
//                        /*delete myCharact
//                        myCharact = nullptr*/
//
//                        //             }
//
//                        //         }
//
//                        //     }
//
//
//                         //}
//
//    return(0);
//}
//
//
//
//
//
//
////Player Constructor Implementation
//
//
//PlayerChar::PlayerChar(string cName, int cLevel, string cJob, string charUno, string charDos, int cStrength, int cDexterity, int cConstitution, int cIntelligence,
//    int cWisdom, int cCharisma) {  //Input values
//
//    setName(cName);   //Indirect access 
//    setLevel(cLevel);  //Indirect Access
//    setJob(cJob);
//    setCharTraitUno(charUno);
//    setCharTraitDos(charDos);   //Indirect Access of Specialized stat
//    setStrength(cStrength);
//    setDexterity(cDexterity);
//    setConstitution(cConstitution);
//    setIntelligence(cIntelligence);
//    setWisdom(cWisdom);
//    setCharisma(cCharisma);
//
//}
//
//
////*****************PlayerChar Methods Implementation********************
//
//void PlayerChar::setName(string argC) {   //Set Methods for Accessor methods
//
//    name = argC;
//
//}
//void PlayerChar::setLevel(int argL) {      //Set Methods for Accessor methods
//
//    level = argL;
//
//}
//
//void PlayerChar::setJob(string argJob) {
//
//    charJob = argJob;
//
//}
//void PlayerChar::setCharTraitUno(string argCharOne) {
//
//    charTraitUno = argCharOne;
//}
//void PlayerChar::setCharTraitDos(string argCharTwo) {  //Returning the specialized stat for the class
//
//    charSpecialization = argCharTwo;
//}
//void PlayerChar::setStrength(int argS) {   //Strength Stat
//
//    strength = argS;
//
//}
//void PlayerChar::setDexterity(int argD) {
//
//    dexterity = argD;
//
//}
//void PlayerChar::setConstitution(int argCon) {
//
//    constitution = argCon;
//}
//void PlayerChar::setIntelligence(int argI) {
//
//    intellegence = argI;
//}
//void PlayerChar::setWisdom(int argWis) {
//
//    wisdom = argWis;
//}
//void PlayerChar::setCharisma(int argRizz) {
//
//    charisma = argRizz;
//}
//void PlayerChar::setLoot(list<Loot*> argLoot) {
//
//    charGear = argLoot;
//}
//
//
//
//string PlayerChar::getName(void) {   //Get Methods for accessor methods.
//
//    return name;
//}
//int PlayerChar::getLevel(void) {   //Get Methods for accessor methods.
//
//    return level;
//
//}
//string PlayerChar::getJob(void) {
//
//    return charJob;
//
//}
//string PlayerChar::getCharTraitUno(void) {
//
//    return charTraitUno;
//
//}
//string PlayerChar::getCharTraitDos(void) {
//
//    return charSpecialization;
//
//}
//int PlayerChar::getStrength(void) {
//
//    return strength;
//}
//
//int PlayerChar::getDexterity(void) {
//
//    return dexterity;
//}
//
//int PlayerChar::getConstitution(void) {
//
//    return constitution;
//}
//
//int PlayerChar::getIntelligence(void) {
//
//    return intellegence;
//}
//
//int PlayerChar::getWisdom(void) {
//
//    return wisdom;
//}
//int PlayerChar::getCharisma(void) {
//
//    return charisma;
//}
//list<Loot*> PlayerChar::getGear(void) {
//
//    return charGear;
//}
//
//
////PlayerChar Utility Methods
//
//void PlayerChar::addMyGear(Loot* gear) {
//
//    //Now that we're accessing charGear (From get and set methods ABOVE)
//
//    charGear.push_back(gear);   //Every instance that addMyGear is called it pushes back the value,
//    //so we can add more. & DEREFERENCED GEAR so that we can pass gear values 
//    //through dynamically (using new). WE MUST DO THIS BECAUSE LOOT DOES NOT
//    //EXIST in PlayerChar Class Natively (It's not inhereting it, or attached)
//    //So Derferencing allows PlayerChar to use it, and more importantly for 
//    //Loot Struct to recognize it as something to pass info through.
//
//    //If you're still having an issue visualizing it think about Exam 2
//    //When using Book object in the BinarySearchTree: void BinarySearchTree::addNode(Book arg)
//    //We call on object book (as an arg) to put through a process to find a node, now this time
//    //instead of using an object we use a Ptr object, and dereference it so we can pass it similarly through
//    //PlayeChar which IS NOT the native Object of Loot. This is the beauty of objects & dereferencing HERE.
//}
//
//
//void PlayerChar::printCharInfo() {
//
//    cout << "The player name is: " << getName() << endl << endl;
//
//    cout << "Their Job is: " << getJob() << endl;
//
//    cout << "Their level is: " << getLevel() << endl;
//
//    cout << "Their First Trait is: " << getCharTraitUno() << endl;
//
//    cout << "Their Second Specialised Trait is: " << getCharTraitDos() << endl;
//
//    cout << "Stats: Str: " << getStrength() << " Dex: " << getDexterity()
//        << " Constitution: " << getConstitution() << " Int: " << getIntelligence()
//        << " Wis: " << getWisdom() << " Charm: " << getCharisma() << endl;
//
//    //Can't use scoping directly for gear (not inhereted) so instead:  USE JUANS PAIR METHOD HERE IT'S PERFECT. Use eitehr -------- or &&&&&&&&
//
//    //Learned This From Juano Promise I'm Not Cheating (Graders don't send me to the shadow realm pls.)
//
//    string charGearPrettifier = "\nCharacter's Gear is: ";
//    cout << charGearPrettifier << endl << string(size(charGearPrettifier), '-');  //Allows us to make custom Line for each Gear Print, make our code SUPER PRETTY. ^^
//
//    //Similar to the for auto for loop in class (used Loot* instead of auto because I wanted to make this clear for the reader)
//    //We iteratate through each piece of gear in the character's arsenal. (In our case 3-4 pieces per Char) 
//
//    for (Loot* gear : charGear) {
//
//        gear->display();  //Just a simple display function that TAKES ANY DISPLAY, for example Weapon in Protag2, will
//        //Print the entire description + values we entered.
//    }
//
//}
//
////Comparator Implementation
//
//bool comparePeeps(PlayerChar* arg1, PlayerChar* arg2) {  // make it work by last name, then first name, then age   
//    // // compare FULL NAMES (Technically First Char later in the main)  
//    if (arg1->getName() < arg2->getName()) {
//        return (1); // tells it to go left
//    }
//    if (arg1->getName() == arg2->getName()) {  //If Names Are Equal ASKII VALUE
//        // now we look at level of Characters 
//        if (arg1->getLevel() < arg2->getLevel()) {
//            return(1);
//        }
//        if (arg1->getLevel() == arg2->getLevel()) {  //If level of characters are the same, the first names are the same (NOT THE CASE FOR ANY, but it's good to be careful)
//            // now we look and check the Name of the First Skill
//            if (arg1->getCharTraitUno() < arg2->getCharTraitUno()) {
//                return (1);
//            }
//        }
//    }
//
//    return(0);
//}
//
//bool compareLootByName(Loot* arg1, Loot* arg2) {
//    bool answer = (arg1->name < arg2->name);
//    return answer;
//}
//
//bool compareLootByValue(Loot* arg1, Loot* arg2) {
//    bool answer = (arg1->value > arg2->value);
//    return answer;
//}
//
//
//
////LowerCases First Letter.
//int firstChar(string arg) {  // this returns the ASCII value of a character minus 97
//    char temp = tolower(arg[0]); // this will give me lower case value of first character of Name
//    return (int(temp) - int('a'));  // int(a) or ASCII value a is 97
//}
//
//
//// character stat generator functions
//
//int rollDie(void) {
//    return 1 + rand() % 6;
//}
//
//int generateStat(void) {
//    return rollDie() + rollDie() + rollDie();
//}
//
//
//string displayLore1(void) {
//
//    string lore = "Long ago in a far away land there was a legend of a band of unrelated & unlikely heros, who through trials and tribulations saved us from cascading darkness. Among them were our Protagonist...";
//
//    lore += "Though all was not well, in our band of heros...they all different ambition and dreams, one specifically harbored a dark secret, but alas it was far to late to stop them the damage had already been done with the accursed Stick.... Now I leave it to you, in your hands to piece together what happens in the Adrana, and the future of of this land.\n\n";
//
//    //Because of the addendum of the lore += above cannot use Juan's method to make code nice have to do it the old fashioned way
//
//    cout << lore;  //Need this to actually output the lore to the screen.
//
//    return (lore);
//
//}