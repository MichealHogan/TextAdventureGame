#include "hero.h"

bool hero::addItem(Item &item) {
    return backpack.addItem(item);
}

//Look at items in inventory
void hero::displayItems(){
    backpack.displayInventory();
}

inventory hero::getInventory(){
    return backpack;
}


void hero::dropItem(Item *item){
    getCurrentRoom()->addItem(*item);
    backpack.removeItem(item->getShortDescription());
}

void hero::useKey(Room* roomOpen){ //should pass the roomName to open
    roomOpen->setDoorType(false); // room opened
    backpack.removeItem(roomOpen->shortDescription()+"Key"); //remove the key from the inventory
}

int hero::combat(){
    //The implementation for the virtual function in the abstract class
    //The weapon with the greatest damage level will be the equiped weapon
    int highestDamage {0};
    for (auto & element : backpack.getInventory()) {
        if(element.getWeaponCheck()){ //only accounts for items that are classed as weapons
            int weaponDamage = element.getDamage();
            if(weaponDamage > highestDamage){
                highestDamage = weaponDamage;
            }
        }
    }
    return highestDamage; //Returns the greatest damage level of the items in the characters inventory
}

bool hero::consumeFood(QString food){
    if(backpack.getItem(food)->getFoodCheck()){
        this->setHealth<double>(100);
        backpack.removeItem(food);
        return true; // Food was consumed
    }
    return false;
}
