#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <QString>
#include <vector>
#include "item.h"
#include <QPixmap>
using namespace std;
using std::vector;

class Room {

private:

    QString description;
    QString path;
    QPixmap roomInMapImage;
    QString story;
    // map <key, data types value> identifer;
    // map is a container just like vectors
    map<QString, Room*> exits; // each room has a instance of map - states what rooms are present in directions (north, east, south and west)
    vector <Item> itemsInRoom;
    bool locked;
    QString exitString();

public:
    QPixmap getPixmap();
    int numberOfItems();
    Room(); //default constructor
    Room(QString description, QString path, bool locked,QString story);
    Room(const Room &source); //Shallow Copy Constructor
    void setExits(Room *north, Room *east, Room *south, Room *west);
    QString shortDescription();
    QString longDescription();
    Room* nextRoom(QString direction);
    void addItem(Item inItem);
    QString displayItem();
    void displayItems();
    int isItemInRoom(QString inString);
    bool removeItemFromRoom(QString inString);
    Item& getItem(int item);
    bool getDoorType();
    void setDoorType(bool type);
};

#endif
