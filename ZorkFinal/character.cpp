#include "character.h"

Character::Character() :  currentRoom{nullptr}, health{100}, name{"Character"}
{}

Character::Character(QString name) : currentRoom{nullptr}, health{100}, name{name}
{}

Character::Character(const Character &source){ //Deep Copy Constructor using member wise assingment
    health = source.health;
    strength = source.strength;
    name = source.name;
    currentRoom = new Room();
    *currentRoom = *source.currentRoom;
}

Character::~Character() {
    delete currentRoom;
}

bool Character::aliveCheck(){
    if(this->getHealth() > 0){
        return true;
    }
    return false;
}

Room* Character::getCurrentRoom(){
    return currentRoom;
}

void Character::setCurrentRoom(Room *theRoom){ //pass by reference using a pointer type
    currentRoom = theRoom;
}

int Character::getHealth(){
    return health;
}

QString Character::getName(){
    return name;
}
