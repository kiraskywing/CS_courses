#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Room.h"
// #include "Item.h"

using namespace std;

// class Item;

class Player: public GameCharacter {
private:
    Room* currentRoom;
    Room* previousRoom;
    // vector<Item> inventory;
public:
    Player(string name="", int hp=100, int atk=100, int dfn=100);
    virtual ~Player() {}

    // void addItem(Item itm);
    void increaseStates(int hp,int atk, int dfn);
    void changeRoom(Room*);

    /* Virtual function that you need to complete   */
    /* In Player, this function should show the     */
    /* status of player.                            */
    virtual void triggerEvent(Object*) override;

    /* Set & Get function*/
    void setCurrentRoom(Room*);
    void setPreviousRoom(Room*);
    // void setInventory(vector<Item>);
    Room* getCurrentRoom();
    Room* getPreviousRoom();
    // vector<Item> getInventory();
};

#endif // PLAYER_H_INCLUDED
