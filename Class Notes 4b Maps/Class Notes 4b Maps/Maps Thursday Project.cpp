#include <iostream>
#include <string>
#include <list>
#include <map>
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
    }
};

struct MagicArmor : Loot {
    string ArmorDescription;

    MagicArmor(string argN, int argV, string argG) : Loot(argN, argV) {
        ArmorDescription = argG;
    }
    virtual void display() {
        cout << name << " is worth " << value << " gold pieces.";
        cout << "\n \tArmor has the following properties: " << ArmorDescription << endl;
        cout << "\n\t\t with additional property" << bonusProperties << endl;
    
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

// comparators
bool compareLootByName(Loot* arg1, Loot* arg2) {    //This prints in alphabetical order 
    bool answer = (arg1->name < arg2->name);
    return answer;
}

bool compareLootByValue(Loot* arg1, Loot* arg2) {   //This prints in greatest value to least
    bool answer = (arg1->value > arg2->value); 
    return answer;
}




int main()
{
    cout << endl << endl << "************** MAPS ************" << endl << endl;

    //// map<key, value>  

    list<Loot*> myLoot;

    // Let's revise these to include our inheritance of Weapon, MagicArmor, MagicRing
    myLoot.push_back(new Loot("Viking Helmet", 500, "just looks cool, has rings"));
    myLoot.push_back(new Loot("Mjolnir", 10000, 80, 100, "is immovable "));  //The 80 to 100 is a range
     myLoot.push_back(new Loot("Stormbreaker", 10001, 90, 110));  //The 90 to 100 is a range
     myLoot.push_back(new MagicRing("Jane's Ring", 2, "a token of affection from Jane"));


    myLoot.sort(compareLootByName);   


    //myLoot.sort()   What does it sort by? Name? Price? Comparison? 


    // let's sort the loot.  We can decide on name or value

    // renamed the loot and map iterators to separate them more easily
    list<Loot*>::iterator itrLoot; // we'll use this to iterate through Loot in our Map
    itrLoot = myLoot.begin(); // temporarily using it to work with a loot list before our Map

    map<string, list<Loot*>> character;  // renamed this be more like the D&D stuff you did on your test.
    map<string, list<Loot*>>::iterator itrMap;

    character["Thor"] = myLoot; // this is a list, we need the list iterator

    // let's adapt this to include the loot display method that was added.
   /* for (itrLoot = character["Thor"].begin(); itrLoot != character["Thor"].end(); itrLoot++) {
        cout << "Loot: " << (*itrLoot)->name << "\n\t";
        (*itrLoot)->display();
    
    }*/



    //mpa["unique key"].value; in our case, value was a Loot list.

    character["Macks"].push_back(new Weapon("Darkdrift", 3000, 65, 96, "deals slashing and dark damage"));
    character["Macks"].push_back(new MagicArmor("Button Up Sweater", 15, "Protects from cold Debuff"));
    character["Macks"].push_back(new MagicArmor("Havels Ring", 4000, "Protects from cold Debuff"));


    character["Snaz"].push_back(new Weapon("Harbinger of Dawn", 3200, 60, 80, "15% "))





    character["Jefe"].push_back(new Weapon("Cometfall", 2500, 35, 50, "summosn a falling start to strike in  a '100' radius"));

    character["Jefe"].push_back(new MagicArmor("Cathedral Knight Armor", 500, "provides an absurb amount of"))


    character["Jefe"].push_back(new MagicArmor("C", 500, "provides an absurb amount of"))



    //Counter to Anti Dark Weapon for Macks
    character["Macks"].push_back(new MagicRing("Brass Knuckles", 30, "punches out people that have protection from Dark"));




    //map.first spits out the unique key, in our case, character name
    //

    for (itrMap = character.begin(); itrMap != character.end(); itrMap++) {  //Through the characters 1 at a time.

        (*itrMap).second.sort(compareLootByName);   //sorts the character's inventory 


        //Spits out Character Names (*itrMap).first
        cout << "\t" << (*itrMap).first << "'s Inventory" << endl;  //tells us which character's loot we are viewing 

        cout << "--------------------" << endl << endl;   //For pleasant display purposes


        itr = (*itrMap).second.begin();
        (*itrLoot)



        //Goes through the character's sorted inventory to retreive the information 
        for (itrLoot = (*itrMap).second.begin(); itrLoot != (*itrMap).second.end(); itrLoot++) {


            (*itrLoot)->display();

            cout << endl;

        }


          cout << endl << endl;  //To sort better 

    }





    cout << endl << endl << endl;
    return(0);

}




// the following is for reference in case we want to speed up the lecture, if it's getting late.

//for (itrMap = character.begin(); itrMap != character.end(); itrMap++) { // iterates through the characters
//    cout << (*itrMap).first << " has the following loot:" << endl; // this one says who each character is.
//    (*itrMap).second.sort(compareLootByValue);
//    for (itrLoot = (*itrMap).second.begin(); itrLoot != (*itrMap).second.end(); itrLoot++) {
//        cout << "    ";
//        (*itrLoot)->display();
//    }
//    cout << endl << endl;
//}