#include "Room.h"

using namespace std;

Room::Room(bool iEt, int idx, vector<Object*> obj) {
    leftRoom = nullptr; rightRoom = nullptr; upRoom = nullptr; downRoom = nullptr;
    isExit = iEt; 
    index = idx; 
    objects = obj;
}

// bool Room::popObject(Object* obj) { delete obj; }
void Room::setUpRoom(Room* up) { upRoom = up; }
void Room::setDownRoom(Room* down) { downRoom = down; }
void Room::setLeftRoom(Room* left) { leftRoom = left; }
void Room::setRightRoom(Room* right) { rightRoom = right; }
void Room::setIsExit(bool iEt) { isExit = iEt; }
void Room::setIndex(int idx) { index = idx; }
void Room::setObjects(vector<Object*> obj) { objects = obj; }
bool Room::getIsExit() { return isExit; }
int Room::getIndex() { return index; }
vector<Object*> Room::getObjects() { return objects; }
Room* Room::getUpRoom() { return upRoom; }
Room* Room::getDownRoom() { return downRoom; }
Room* Room::getLeftRoom() { return leftRoom; }
Room* Room::getRightRoom() { return rightRoom; }