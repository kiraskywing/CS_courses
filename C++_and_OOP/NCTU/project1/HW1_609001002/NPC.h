#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Player.h"
#include "Item.h"

using namespace std;

class NPC: public GameCharacter {
private:
    string script;
    vector<Item> commodity;
public:
    NPC(string name="", string tag="NPC", vector<Item> itm=vector<Item>(1, Item("sword", 0, 1000, 0)));
    virtual ~NPC() {}
    
    // void listCommodity(); /*print all the Item in this NPC*/

    /* Virtual function that you need to complete   */
    /* In NPC, this function should deal with the   */
    /* transaction in easy implementation           */
    virtual void triggerEvent(Object*) override;

    /* Set & Get function*/
    // void setScript(string);
    // void setCommodity(vector<Item>);
    // string getScript();
    Item getCommodity(int);
};


#endif // NPC_H_INCLUDED
