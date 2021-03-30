#include "Object.h"
using namespace std;

Object::Object(string nm, string tg): name(nm), tag(tg) {}

void Object::setName(string nm) { name = nm;}
void Object::setTag(string tg) { tag = tg; }

string Object::getName() { return name; }
string Object::getTag() { return tag; }