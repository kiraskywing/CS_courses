#include "Player.h"

using namespace std;

Player::Player(string name, int hp, int atk, int dfn)
: GameCharacter(name, "Player", hp, atk, dfn),  currentRoom(nullptr), previousRoom(nullptr)
{}

// void Player::addItem(Item itm) { inventory.push_back(itm); }

void Player::increaseStates(int hp, int atk, int dfn) {
    hp += getCurrentHealth();
    atk += getAttack();
    dfn += getAttack();
    setCurrentHealth(hp);
    setAttack(atk);
    setDefense(dfn);
}

void Player::changeRoom(Room* nxt) {
    previousRoom = currentRoom;
    cout << endl << "Move from " << currentRoom->getIndex();
    currentRoom = nxt;
    cout << " to " << currentRoom->getIndex() << endl << endl;
}

bool Player::triggerEvent(Object* obj) {
    class GameCharacter* gc = dynamic_cast<GameCharacter*>(obj);
    cout << endl << "Player name: " <<obj->getName() << endl;
    cout << "Health: " << gc->getCurrentHealth() << "/" << gc->getMaxHealth() << endl;
    cout << "Attack: " << gc->getAttack() << endl;
    cout << "Defense: " << gc->getDefense() << endl << endl;

    return true;
}

void Player::setCurrentRoom(Room* rm) { currentRoom = rm; }
void Player::setPreviousRoom(Room* rm) { previousRoom = rm; }
// void Player::setInventory(vector<Item> itm) { inventory = itm; }
Room* Player::getCurrentRoom() { return currentRoom; }
Room* Player::getPreviousRoom() { return previousRoom; }
// vector<Item> Player::getInventory() { return inventory; }