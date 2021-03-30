#include "Monster.h"
using namespace std;

Monster::Monster(string name, int hp, int atk, int dfn)
    :GameCharacter(name, "Monster", hp, atk, dfn) {}

bool Monster::triggerEvent(Object *obj) {
    
}