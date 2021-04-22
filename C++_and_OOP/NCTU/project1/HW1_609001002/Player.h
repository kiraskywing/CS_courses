#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Item.h"
#include "Room.h"

using namespace std;

class Player: public GameCharacter {
private:
    Room *currentRoom, *previousRoom;
    vector<Object*> inventory;
    string weaponName;
    int inventoryMaxSize, addedAttack, weaponAttack, level;
public:
    Player(string name="", int hp=250, int atk=50, int addAtk=0, int wpAtk=50, int mny=100, int car=10, int lv=1);
    
    virtual ~Player() {}

    // void addItem(Item* itm) { inventory.push_back(itm); }
    bool increaseStates(int hp,int atk, int mny);
    void changeRoom(Room*);

    /* Virtual function that you need to complete   */
    /* In Player, this function should show the     */
    /* status of player.                            */
    virtual bool triggerEvent(Object*) override;

    void levelUp();

    /* Set & Get function*/
    void setCurrentRoom(Room* rm) { currentRoom = rm; }
    void setPreviousRoom(Room* rm) { previousRoom = rm; }
    void setWeaponName(string s) {weaponName = s; }
    void setWeaponAttack(int atk) { weaponAttack = atk; }
    void setAddedAttack(int atk) { addedAttack = atk; }
    void setLevel(int lv) { level = lv; }
    void setInventorySize(int n) { inventoryMaxSize = n; }
    void setInventory(vector<Object*>& itms) { inventory.insert(inventory.end(), itms.begin(), itms.end()); }
    Room* getCurrentRoom() { return currentRoom; }
    Room* getPreviousRoom() { return previousRoom; }
    string getWeaponName() { return weaponName; }
    int getWeaponAttack() { return weaponAttack; }
    int getAddedAttack() { return addedAttack; }
    int getLevel() { return level; }
    int getInventorySize() { return inventoryMaxSize; }
    vector<Object*> getInventory() { return inventory; }
    void useInventory();
};

#endif // PLAYER_H_INCLUDED
