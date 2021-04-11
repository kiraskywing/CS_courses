#include "NPC.h"

using namespace std;

NPC::NPC(string name, string tag, vector<Item> itm)
    : GameCharacter(name, tag), script(""), commodity(itm) {}

void NPC::listCommodity() {}

bool NPC::triggerEvent(Object*) {
    // a. shop
    // b. leave

    // choose item -> add item
}

void NPC::setScript(string) {}
void NPC::setCommodity(vector<Item>) {}
string NPC::getScript() {}
vector<Item> NPC::getCommodity() {}