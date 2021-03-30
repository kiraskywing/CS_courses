#include "Item.h"

using namespace std;

Item::Item(string name, int hp, int atk, int dfn)
    : Object(name, "Item"), health(hp), attack(atk), defense(dfn) {}

bool Item::triggerEvent(Object *obj) {
    class Player* p = dynamic_cast<Player*>(obj);
    p->increaseStates();
    return false;
}

int Item::getHealth() { return health; }
int Item::getAttack() { return attack; }
int Item::getDefense() { return defense; }
void Item::setHealth(int hp) { health = hp; }
void Item::setAttack(int atk) { attack = atk; }
void Item::setDefense(int dfn) { defense = dfn; }