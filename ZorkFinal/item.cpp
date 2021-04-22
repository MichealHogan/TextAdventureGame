#include "item.h"

//manually set up the item when adding it to the room
Item::Item (string inDescription, bool weaponCheck, bool foodCheck, bool keyCheck, int inWeightKilos, unsigned int damage)
    : description{inDescription}, weaponCheck{weaponCheck}, foodCheck{foodCheck}, keyCheck{keyCheck}, damage{damage}, weightKilos{inWeightKilos}
{}

Item::Item () : description{""}, weaponCheck{false}, foodCheck{false}, keyCheck{false}, weightKilos{0}, damage{0} {
    std::cout << "The default constructor was called" << endl;
}

//Shallow Copy Constructor - default memberwise copy
// Dont use shallow copy when dealing with class member variables that are not raw pointers
Item::Item (const Item &source) : description{source.description}, weaponCheck{source.weaponCheck}, foodCheck{source.foodCheck}, keyCheck{source.keyCheck}, weightKilos{source.weightKilos}, damage{source.damage}
{}

//Operator Overloading:
Item Item::operator+ (Item rhs){
    Item new_item;
    new_item.weightKilos = weightKilos + rhs.weightKilos;
    return new_item;
}

int Item::getWeight(){
    return weightKilos;
}

int Item::getDamage(){
    return damage;
}

bool Item::getWeaponCheck(){
    return weaponCheck;
}

bool Item::getFoodCheck(){
    return foodCheck;
}

bool Item::getKeyCheck(){
    return keyCheck;
}

QString Item::getShortDescription(){
    QString temp = QString::fromStdString(description);
    return temp;
}
