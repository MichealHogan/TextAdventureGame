#ifndef MONSTER_H_
#define MONSTER_H_

#include<iostream>
#include<QString>
#include<vector>

#include "character.h"
#include "inventory.h"
#include "item.h"
#include "room.h"

#define SIZE (3) //Macro

class Monster : public Character { //hero class (subClass) extends Character class (superClass)

private:
    Item MonsterBackpack [SIZE];
    Item *inventory_ptr; // declared initialized the pointer to point to the first value in the array MonsterBackpack

public:
    Monster() : Character{"Monster"} , inventory_ptr{MonsterBackpack}
    {
        *inventory_ptr = Item("icestaff",true,false,false,200,1000);
        *(inventory_ptr + 1) = Item("healthPotion",false,true,false,10,100);
        *(inventory_ptr + 2) = Item("eKey",false,false,true,1,80);
    }

    Monster(QString name, Item weapon, Item potion, Item key) : Character{name} , inventory_ptr{MonsterBackpack}
    {
        //Pointer Offset notation
        *inventory_ptr = weapon;
        *(inventory_ptr + 1) = potion;
        *(inventory_ptr + 2) = key;
    }

    void dropInventory(); // can loop through the array to drop the items using pointer
    int combat(); // over riding pure virtual function in this deveried class of character
};
#endif
