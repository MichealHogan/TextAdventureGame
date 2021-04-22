#ifndef HERO_H_
#define HERO_H_

#include<iostream>
#include<QString>
#include<vector>

#include "character.h"
#include "inventory.h"
#include "item.h"
#include "room.h"

class hero : public Character { //hero class (subClass) extends Character class (superClass)

private:
    inventory backpack;
public:
    hero() : Character{"Bobby"} , backpack{100} {};
    bool addItem(Item &item);
    void displayItems();
    inventory getInventory();
    void dropItem(Item* item);
    void useKey(Room* roomOpen); //unlock door
    bool consumeFood(QString food); //drink/consume
    int combat(); // Over riding pure virtual function in this derived class of Character
};
#endif
