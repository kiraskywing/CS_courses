#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Player.h"

using namespace std;

class Monster: public GameCharacter {
private:
    // int retreat_possibility;
public:
    Monster(string name="", int hp=100, int atk=100, int dfn=100);
    virtual ~Monster() {}

    /* Virtual function that you need to complete   */
    /* In Monster, this function should deal with   */
    /* the combat system.                           */
    virtual void triggerEvent(Object*) override;
    // bool treatSuccess();
};

#endif // ENEMY_H_INCLUDED
