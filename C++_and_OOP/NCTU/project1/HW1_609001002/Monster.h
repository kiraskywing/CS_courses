#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include <vector>
#include <random>
#include "GameCharacter.h"
#include "Player.h"

using namespace std;

class Monster: public GameCharacter {
private:
    random_device rd;
public:
    Monster(string name="", int hp=100, int atk=100, int mny=100, int car=10)
        :GameCharacter(name, "Monster", hp, atk, mny, car) {}
    
    virtual ~Monster() {}

    /* Virtual function that you need to complete   */
    /* In Monster, this function should deal with   */
    /* the combat system.                           */
    virtual bool triggerEvent(Object*) override;
    
    bool oddFunction(int);
    void attackFunction(GameCharacter*, GameCharacter*);
};

#endif // ENEMY_H_INCLUDED
