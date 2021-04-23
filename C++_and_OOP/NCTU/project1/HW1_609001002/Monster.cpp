#include "Monster.h"
using namespace std;

bool Monster::triggerEvent(Object* obj) {
    Player* p = dynamic_cast<Player*>(obj);
    string monName = getName();
    int i;
    while (!this->checkIsDead() && !p->checkIsDead()) {
        cout << endl << "You encouter a \"" << monName << "\"";
        cout << endl << "Choose one action:" << endl
                << "(a) Fight with enemy" << endl
                << "(b) Check status" << endl
                << "(c) Use inventory" << endl
                << "(d) Retreat" << endl
                << "Enter: ";
        
        i = inputFilter(4);
        
        if (i == 0) {
            while (!this->checkIsDead() && !p->checkIsDead()) {
                cout << endl << this->getName() << "'s health: " << fixed << setprecision(1) 
                     << static_cast<double>(this->getCurrentHealth()) / this->getMaxHealth() * 100 << "%"
                     << endl << "Your health: " << p->getCurrentHealth()
                     << endl << "Choose one action:" << endl
                             << "(a) Attack enemy" << endl
                             << "(b) Use posion" << endl
                             << "(c) Retreat" << endl
                             << "Enter: ";
                i = inputFilter(3);

                if (i == 0) {
                    cout << endl;
                    attackFunction(p, this);
                    if (!this->checkIsDead()) 
                        attackFunction(this, p);
                }

                else if (i == 1) p->useInventory();

                else {
                    if (retreatFunction(p, this))
                        return true;
                }
            }
        }

        else if (i == 1) p->triggerEvent(nullptr);
        else if (i == 2) p->useInventory();
        else { if (retreatFunction(p, this)) return true; }
    }

    return true;
}

bool Monster::oddFunction(int rate) {
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(1, 100);
    return distribution(generator) <= rate;
}

void Monster::attackFunction(GameCharacter* a, GameCharacter* b) {
    bool isCritical = oddFunction(a->getCriticalAttackRate());
    int atk = a->getAttack() * (isCritical ? 2 : 1);
    cout << a->getName() <<"'s attack does " << b->takeDamage(atk)
         << (isCritical ? " \"Critical\" " : " ") << "damage" << endl;
}

bool Monster::retreatFunction(Player* p, Monster* m) {
    int rate = (m->getName() == "Boss" ? 25 : 50);
    bool retreatSuccess = oddFunction(rate);
    if (retreatSuccess) {
        p->changeRoom(p->getPreviousRoom());
        cout << endl << "Retreat success!" << endl;
        return true;
    }
    else {
        cout << endl << "Retreat fail!" << endl << endl;
        attackFunction(m, p);
        return false;
    }
}