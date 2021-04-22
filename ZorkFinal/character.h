#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <QString>
//#include <string>
#include <vector>
#include "inventory.h"
#include "item.h"
#include "room.h"
#include <iostream>
using std::vector;

class Character
{
private:
    //Using bit fields - reduces the amount of storage in data types
    int health : 8; //max value of health is 100 - represented as 1100100 - 7 bits
    int strength : 4; //max value of strength is 10 - represented as 1010 - 4 bits
    QString name;
    Room *currentRoom; //Room the character is located at in real game time - changed inside of main

public:
    Character();
    Character(QString name); // player names their character!
    Character(const Character &source); //Deep Copy Constructor
    ~Character();

    virtual int combat() =0; //Pure virtual function - Character class is now an abstract class

    QString shortDescription();
    QString longDescription();
    bool aliveCheck();

    void setCurrentRoom(Room *theRoom);
    Room* getCurrentRoom();
    int getHealth();
    QString getName();

    template <typename T> //Member function template definition
    void setHealth(T newHealth){
        this->health = newHealth;
    }
};
#endif /*CHARACTER_H_*/
