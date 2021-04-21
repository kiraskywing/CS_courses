#include "Monster.h"
using namespace std;

bool Monster::triggerEvent(Object* obj) {
    Player* p = dynamic_cast<Player*>(obj);
    string monName = getName();
    
    while (!this->checkIsDead() && !p->checkIsDead()) {
        cout << endl << "You encouter a \"" << monName << "\"";
        cout << endl << "Please choose action:" << endl
                << "(a) Fight with enemy" << endl
                << "(b) Check status" << endl
                << "(c) Use posion" << endl
                << "(d) Retreat" << endl
            //  << "(e) Save to file\n"
                << "Enter: ";
        char c;
        do {
            cin >> c;
            c = tolower(c);
            if (c < 'a' || c > 'd')
                cout << "Wrong input. Please enter again: ";
        } while (c < 'a' || c > 'd');
        
        if (c == 'a') {
            while (!this->checkIsDead() && !p->checkIsDead()) {
                do {
                    cout << endl << this->getName() << "'s health: " 
                        << fixed << setprecision(1) << static_cast<double>(this->getCurrentHealth()) / this->getMaxHealth() * 100 << "%";
                    cout << endl << "Your health: " << p->getCurrentHealth();
                    cout << endl << "Please choose action:" << endl
                        << "(a) Attack enemy" << endl
                        << "(b) Use posion" << endl
                        << "(c) Retreat" << endl
                        << "Enter: ";
                    
                    cin >> c;
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    c = tolower(c);
                    if (c < 'a' || c > 'c')
                        cout << "Wrong input. Please enter again: ";
                
                } while (c < 'a' || c > 'c');

                if (c == 'a') {
                    attackFunction(p, this);
                    if (!this->checkIsDead()) 
                        attackFunction(this, p);
                }

                else if (c == 'b') p->useInventory();

                else {
                    int rate = (monName == "Boss" ? 50 : 75);
                    bool retreatSuccess = oddFunction(rate);
                    if (retreatSuccess) {
                        p->changeRoom(p->getPreviousRoom());
                        cout << "Retreat success!\n";
                        return true;
                    }
                    else {
                        cout << "Retreat fail!\n";
                        attackFunction(this, p);
                    }
                }
            }
        }

        else if (c == 'b') p->triggerEvent(nullptr);
        
        else if (c == 'c') p->useInventory();
        
        else if (c == 'd') {
            int rate = (monName == "Boss" ? 25 : 50);
            bool retreatSuccess = oddFunction(rate);
            if (retreatSuccess) {
                p->changeRoom(p->getPreviousRoom());
                cout << "Retreat success!\n";
                return true;
            }
            else {
                cout << "Retreat fail!\n";
                attackFunction(this, p);
            }
        }

        // else {}
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
    int atk = a->getAttack();
    atk = (isCritical ? atk * 2 : atk);
    cout << a->getName() <<"'s attack does " << b->takeDamage(atk)
         << (isCritical ? " \"Critical\" " : " ") << "damage" << endl;
}