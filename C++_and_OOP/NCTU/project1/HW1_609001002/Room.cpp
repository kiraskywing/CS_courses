#include "Room.h"

using namespace std;

Room::Room(bool iEt, int idx, vector<Object*> obj) {
    leftRoom = nullptr; rightRoom = nullptr; upRoom = nullptr; downRoom = nullptr;
    isExit = iEt; 
    index = idx; 
    objects = obj;
}

bool Room::popObject(Object* obj) { 
    int n = objects.size();
    for (int i = 0; i < n; i++) {
        if (objects[i] == obj) {
            delete objects[i];
            if (i != n - 1)
                objects[i] = objects[n - 1];
        }
        objects.pop_back();
        break;
    }
    return true; 
}
void Room::setUpRoom(Room* up) { upRoom = up; }
void Room::setDownRoom(Room* down) { downRoom = down; }
void Room::setLeftRoom(Room* left) { leftRoom = left; }
void Room::setRightRoom(Room* right) { rightRoom = right; }
void Room::setIsExit(bool iEt) { isExit = iEt; }
void Room::setIndex(int idx) { index = idx; }

void Room::setObjects(vector<Object*> &obj) { 
    for (Object* itm:obj)
        objects.push_back(itm);
}

bool Room::getIsExit() { return isExit; }
int Room::getIndex() { return index; }
vector<Object*>& Room::getObjects() { return objects; }
Room* Room::getUpRoom() { return upRoom; }
Room* Room::getDownRoom() { return downRoom; }
Room* Room::getLeftRoom() { return leftRoom; }
Room* Room::getRightRoom() { return rightRoom; }