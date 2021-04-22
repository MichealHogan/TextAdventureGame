#ifndef INVENTORY_H_
#define INVENTORY_H_

#include <QString>
#include <string>
#include <vector>
#include "item.h"

class inventory
{
private:
    int totalWeightOfItems;
    int weightLimit;
    vector<Item> inventoryItems;

public:
    inventory(int weightLimit);
    QString displayInventory();
    bool addItem(Item &item);
    void removeItem(int index);
    bool removeItem(QString itemName);
    void setTotalWeight();
    int getTotalWeight();
    int getWeightLimit();
    Item* getItem(QString itemName);
    int getIdexItem(QString itemName);
    vector<Item> getInventory();
    Item* getItem(int index);
};
#endif /*INVENTORY_H_*/
