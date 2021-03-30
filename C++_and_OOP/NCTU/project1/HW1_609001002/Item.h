#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Object.h"
#include "Player.h"

using namespace std;

// class Player;

class Item: public Object {
private:
    int health, attack, defense;
public:
    Item(string name="", int hp=0, int atk=0, int dfn=0);

    /* Virtual function that you need to complete    */
    /* In Item, this function should deal with the   */
    /* pick up action. You should add status to the  */
    /* player.                                       */
    virtual bool triggerEvent(Object*) override;

    /* Set & Get function*/
    int getHealth();
    int getAttack();
    int getDefense();
    void setHealth(int);
    void setAttack(int);
    void setDefense(int);
};

#endif // ITEM_H_INCLUDED