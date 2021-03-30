#include "NPC.h"

using namespace std;

NPC::NPC(string name, string tag, vector<Item> itm)
    : GameCharacter(name, tag), script(""), commodity(itm) {}