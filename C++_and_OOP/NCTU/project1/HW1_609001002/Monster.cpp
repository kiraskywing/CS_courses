#include "Monster.h"
using namespace std;

Monster::Monster(string name, int hp, int atk, int dfn)
    :GameCharacter(name, "Monster", hp, atk, dfn) {}

void Monster::triggerEvent(Object* obj) {
    Player* p = dynamic_cast<Player*>(obj);

    cout << endl << "You encouter a \"" << this->getName() << "\"";
    cout << endl << "Please choose action:\n"
            << "(a) Fight with enemy\n"
            << "(b) Check status\n"
            << "(c) Retreat\n"
        //  << "(d) Save to file\n"
            << "Enter: ";
    char c;
    do {
        cin >> c;
        c = tolower(c);
        if (c < 'a' || c > 'c')
            cout << "Wrong input. Please enter again: ";
        else if (c == 'b')
            p->triggerEvent(p);
    
    } while (c != 'a' && c != 'c');
    
    if (c == 'a') {
        while (!this->checkIsDead() && !p->checkIsDead()) {
            do {
                cout << endl << this->getName() << "'s health: " 
                     << fixed << setprecision(1) << static_cast<double>(this->getCurrentHealth()) / this->getMaxHealth() * 100 << "%";

                cout << endl << "Your health: " << p->getCurrentHealth();

                cout << endl << "Please choose action:\n"
                    << "(a) Attack enemy\n"
                    << "(b) Retreat\n"
                    << "Enter: ";
                
                cin >> c;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                c = tolower(c);
                
                if (c < 'a' || c > 'b')
                    cout << "Wrong input. Please enter again: ";
            
            } while (c < 'a' || c > 'b');

            if (c == 'a') {
                cout << "Your attack does "
                     << this->takeDamage(p->getAttack()) << " damage\n";
                
                if (!this->checkIsDead()) {
                    cout << this->getName() << "'s attack does "
                         << p->takeDamage(this->getAttack()) << " damage\n";
                }
            }

            else if (c == 'b') {
                p->changeRoom(p->getPreviousRoom());
                cout << "Retreat success!\n";
                break;
            }
        }
    }
    
    else if (c == 'c') {
        p->changeRoom(p->getPreviousRoom());
        cout << "Retreat success!\n";
    }
}