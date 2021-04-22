#include "room.h"
#include "command.h"

Room::Room(QString description, QString path, bool locked, QString story): description{description}, path{path}, locked{locked},  roomInMapImage{path}, story{story}
{}

Room::Room()
{}

Room::Room(const Room &source): description{source.description}, exits{source.exits}, itemsInRoom{source.itemsInRoom}, path{source.path}, locked{source.locked},story{source.story}
{}

void Room::setExits(Room *north, Room *east, Room *south, Room *west) {
    if (north != NULL)
        exits["north"] = north;
    if (east != NULL)
        exits["east"] = east;
    if (south != NULL)
        exits["south"] = south;
    if (west != NULL)
        exits["west"] = west;
}

QString Room::shortDescription() {
    return description;
}

QPixmap Room::getPixmap(){
    return path;
}


QString Room::longDescription() {
    return story + "\n" + "room = " + description + ".\n" + displayItem() + exitString();
}

//exists from the room
QString Room::exitString() {
    QString returnString = "\nexits =";
    for (map<QString, Room*>::iterator i = exits.begin(); i != exits.end(); i++) // Loop through map
        returnString += "  " + i->first;	// access the "first" element of the pair (direction as a string)
    return returnString;
}

//taking in the direction you specified in the command line
Room* Room::nextRoom(QString direction) {
    map<QString, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
    if (next == exits.end()) {//.end() refers to the element beyond the last element (direction given didnt exist in the map)
        return NULL; // if exits.end() was returned, there's no room in that direction.
    }

    return next->second; // If there is a room, remove the "second" (Room*)
    // part of the "pair" (<string, Room*>) and return it.
}

void Room::addItem(Item inItem) {
    itemsInRoom.push_back(inItem);
}

QString Room::displayItem() {
    QString tempString = "items in room = ";
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        tempString = "no items in room";
    }
    else if (itemsInRoom.size() > 0) {
        int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            tempString = tempString + itemsInRoom[x].getShortDescription() + "  " ;
            x++;
        }
    }
    return tempString;
}

int Room::numberOfItems() {
    return itemsInRoom.size();
}

bool Room::getDoorType(){
    return locked;
}

void Room::setDoorType(bool type){
    this->locked = type;
}

int Room::isItemInRoom(QString inString)
{
    int sizeItems = (itemsInRoom.size());
    if (sizeItems < 1) {
        return -1; // no items in the room
    }

    else if (itemsInRoom.size() > 0) {
        int x = (0);
        for (int n = sizeItems - 1; n >= 0; n--) {
            int tempFlag = inString.compare( itemsInRoom[x].getShortDescription());
            if (tempFlag == 0) {
                return x;
            }
            x++;
        }
    }
    return -1;  // item was not found in the room
}

//remove item from the room
bool Room::removeItemFromRoom(QString inString){
    for(int i = 0; i < itemsInRoom.size(); i++){
        if(itemsInRoom[i].getShortDescription() == inString){
            itemsInRoom.erase(itemsInRoom.begin()+i);
            return true;
        }
    }
    return false;
}

Item& Room::getItem(int index){
    return itemsInRoom[index];
}
