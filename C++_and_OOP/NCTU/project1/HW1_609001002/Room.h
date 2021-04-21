#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Object.h"

using namespace std;

class Room {
private:
    Room *upRoom, *downRoom, *leftRoom, *rightRoom;
    bool isVisited, isExit;
    int index;
    Object* object; /*contain 1 or multiple objects, including monster, npc, etc*/
public:
    Room(int idx=0, bool iVt=false, bool iEt=false, Object* obj=nullptr) {
    leftRoom = rightRoom = upRoom = downRoom = nullptr;
    isVisited = iVt; isExit = iEt; index = idx; 
    object = obj;
    }
    ~Room() {}
    
    void popObject() { delete object; object = nullptr; } /*pop out the specific object, used when the interaction is done*/

    /* Set & Get function*/
    void setUpRoom(Room* up) { upRoom = up; }
    void setDownRoom(Room* down) { downRoom = down; }
    void setLeftRoom(Room* left) { leftRoom = left; }
    void setRightRoom(Room* right) { rightRoom = right; }
    void setIsVisited(bool iVt) { isVisited = iVt; }
    void setIsExit(bool iEt) { isExit = iEt; }
    void setIndex(int idx) { index = idx; }
    bool getIsVisited() { return isVisited; }
    bool getIsExit() { return isExit; }
    int getIndex() { return index; }
    Object* getObject() { return object; }
    void setObjects(Object* obj) { object = obj; }
    Room* getUpRoom() { return upRoom; }
    Room* getDownRoom() { return downRoom; }
    Room* getLeftRoom() { return leftRoom; }
    Room* getRightRoom() { return rightRoom; }
};

#endif // ROOM_H_INCLUDED
