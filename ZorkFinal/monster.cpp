#include "monster.h"

void Monster::dropInventory(){
    //Using pointers to iterate over an array
    //p++ => p = p + 1 * sizeOf(type)
    for(Item *p = &MonsterBackpack[0]; p <= &MonsterBackpack[2]; p++){
        getCurrentRoom()->addItem(*p); // add item to the room
    }
}

int Monster::combat(){
    int highestDamage {0};
    for(Item *p = &MonsterBackpack[0]; p <= &MonsterBackpack[2]; p++){
        if(p->getWeaponCheck()){
            int weaponDamage = p->getDamage();
            if(weaponDamage > highestDamage){
                highestDamage = weaponDamage;
            }
        }
    }
    return highestDamage - 20;// deduct damage of the weapon based on a better combat system!
}
