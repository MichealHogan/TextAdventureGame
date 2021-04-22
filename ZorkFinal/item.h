#ifndef ITEM_H_
#define ITEM_H_

#include <map>
#include <QString>
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

class Item
{
    friend class inventory;
private:
    string description;
    int weightKilos;
    bool weaponCheck;
    bool foodCheck;
    bool keyCheck;

    unsigned int damage : 8; // The max value held by damage is 100

public:
    Item(string description, bool weaponCheck, bool foodCheck, bool keyCheck, int inWeightKilos = 0, unsigned int damage = 0); //default arguements in the function prototype
    Item();
    Item(const Item &source); //shallow copy constructor declaration
    QString getShortDescription();
    QString getLongDescription();
    int getWeight();
    int getDamage();
    Item operator + (Item rhs); // Overload + operator for item objects
    bool getWeaponCheck();
    bool getFoodCheck();
    bool getKeyCheck();
};

#endif /*ITEM_H_*/
