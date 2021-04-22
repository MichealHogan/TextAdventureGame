#include "inventory.h"


inventory::inventory(int weight) : weightLimit{weight}{
    inventoryItems.push_back(Item("map",false,false,false));
    setTotalWeight(); // performs operator overloading on item (objects), assigns a value to the totalWeightOfItems member var
}

/* Prints short description of the items in the inventory */
QString inventory::displayInventory(){
    QString temp;
    for(int i = 0; i < inventoryItems.size(); i++){
        temp += inventoryItems[i].getShortDescription() + " ";
    }
    return temp;
}

vector<Item> inventory::getInventory(){
    return inventoryItems;
}

Item* inventory::getItem(int index){
    return &inventoryItems[index];
}

void inventory::setTotalWeight(){
    Item temp;
    for(int i = 0; i < inventoryItems.size(); i++)
    {
        temp = temp + inventoryItems[i]; // use of operator overloading
    }
    totalWeightOfItems = temp.weightKilos; // friendship - no need for use of accessor method
}

int inventory::getTotalWeight(){
    return totalWeightOfItems;
}

bool inventory::addItem(Item &item){ // pass by reference using references in c++
    int temp = totalWeightOfItems + item.weightKilos;
    if(temp <= weightLimit){

        inventoryItems.push_back(item);
        totalWeightOfItems += item.weightKilos;
        return true;
    }
    return false;
}

// Remove item from inventory based on index notation
void inventory::removeItem(int index){
    inventoryItems.erase(inventoryItems.begin()+index);
    totalWeightOfItems -= inventoryItems[index].weightKilos;
}

// Remove item from the inventory based item string name
bool inventory::removeItem(QString itemName){
    for(int i = 0; i < inventoryItems.size(); i++){
        if(inventoryItems[i].getShortDescription() == itemName){
            inventoryItems.erase(inventoryItems.begin()+i);
            totalWeightOfItems -= inventoryItems[i].weightKilos;
            return true;
        }
    }
    return false;
}

// retrive item* from inventory based on item string name
Item* inventory::getItem(QString itemName){

    int sizeItems = (inventoryItems.size());
    if (inventoryItems.size() > 0) {
        int x = (0);
        for (int n = sizeItems - 1; n >= 0; n--) {
            int tempFlag = itemName.compare( inventoryItems[x].getShortDescription());
            if (tempFlag == 0) {
                return &inventoryItems[x];
            }
            x++;
        }
    }
    return NULL;
}

