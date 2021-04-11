#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Object.h"

using namespace std;

class Room {
private:
    Room* upRoom;
    Room* downRoom;
    Room* leftRoom;
    Room* rightRoom;
    bool isExit;
    int index;
    vector<Object*> objects; /*contain 1 or multiple objects, including monster, npc, etc*/
public:
    Room(bool iEt=false, int idx=0, vector<Object*> obj=vector<Object*>(0, nullptr));
    ~Room() {}
    
    bool popObject(Object*); /*pop out the specific object, used when the interaction is done*/

    /* Set & Get function*/
    void setUpRoom(Room*);
    void setDownRoom(Room*);
    void setLeftRoom(Room*);
    void setRightRoom(Room*);
    void setIsExit(bool);
    void setIndex(int);
    void setObjects(vector<Object*> &obj);
    bool getIsExit();
    int getIndex();
    vector<Object*>& getObjects();
    Room* getUpRoom();
    Room* getDownRoom();
    Room* getLeftRoom();
    Room* getRightRoom();
};

#endif // ROOM_H_INCLUDED
