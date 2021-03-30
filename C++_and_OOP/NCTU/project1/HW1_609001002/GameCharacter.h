#ifndef GAMECHARACTER_H_INCLUDED
#define GAMECHARACTER_H_INCLUDED

#include <iostream>
#include <string>
#include "Object.h"

using namespace std;

class GameCharacter: public Object {
private:
    int maxHealth, currentHealth, attack, defense;
public:
    GameCharacter(string name="", string tag="", int hp=0, int atk=0, int dfn=0);
    virtual ~GameCharacter() {}
    
    bool checkIsDead();
    int takeDamage(int);

    virtual bool triggerEvent(Object*) override;

    /* Set & Get function*/
    void setMaxHealth(int);
    void setCurrentHealth(int);
    void setAttack(int);
    void setDefense(int);
    int getMaxHealth();
    int getCurrentHealth();
    int getAttack();
    int getDefense();
};

#endif // GAMECHARACTER_H_INCLUDED