#include "Player.h"

using namespace std;

Player::Player(string name, int hp, int atk, int addAtk, int wpAtk, int mny, int car,  int lv)
    : GameCharacter(name, "Player", hp, atk + addAtk + wpAtk, mny, car) {
           currentRoom = previousRoom = nullptr;
           weaponName = "Sword";
           inventoryMaxSize = 6; addedAttack = addAtk; weaponAttack = wpAtk; level = lv;
        }  

bool Player::increaseStates(int hp, int addAtk, int mny) {
    if (hp) {
        int pre_hp = getCurrentHealth(), max_hp = getMaxHealth();
        if (pre_hp == max_hp) {
            cout << "Your health is already full!" << endl;
            return false;
        }
        hp = (hp + pre_hp >= max_hp ? max_hp :hp + pre_hp);
        setCurrentHealth(hp);
        cout << "Your health is increased to " << hp << endl;
    }
    if (addAtk) {
        addedAttack += addAtk;
        addAtk += getAttack();
        setAttack(addAtk);
        cout << "Your attack is increased to " << addAtk << endl;
    }
    if (mny) {
        cout << "Your money is " << (mny > 0 ? "increased" : "decreased") << " to ";
        mny += getMoney();
        setMoney(mny);
        cout << mny << endl;
    }
    return true;
}

void Player::changeRoom(Room* nxt) {
    previousRoom = currentRoom;
    currentRoom = nxt;
}

bool Player::triggerEvent(Object* obj) {
    cout << endl << "[Player " << getName() << "'s status]" << endl;
    cout << "=> Level: " << level << endl;
    cout << "=> Health: " << getCurrentHealth() << "/" << getMaxHealth() << endl;
    cout << "=> Attack: " << getAttack() << endl;
    cout << "=> Critical attack rate: " << getCriticalAttackRate() << '%' << endl;
    cout << "=> Money: " << getMoney() << endl;
    cout << "=> Weapon: " << weaponName << endl;
    cout << "=> Number of posions: " << inventory.size() << endl;
    return true;
}

void Player::levelUp() {
    cout << endl << "******* Level up! *******";
    level++;
    int maxHP = getMaxHealth(), curHP = getCurrentHealth();
    maxHP *= 2; curHP = maxHP;
    setMaxHealth(maxHP); setCurrentHealth(curHP);

    int atk = getAttack();
    atk = (atk - addedAttack - weaponAttack) * 2 + addedAttack + weaponAttack;
    setAttack(atk);

    triggerEvent(nullptr);
}

void Player::useInventory() {
    while (true) {
        if (inventory.empty()) {
            cout << endl << "No item." << endl;
            return;
        }
        
        cout << endl << "Please chose one item: ";
        Item* itm;
        int i, n = inventory.size();
        for (i = 0; i < n; i++) {
            itm = dynamic_cast<Item*>(inventory[i]);
            cout << endl << "(" << (char)('a'+i) << ") " << itm->getName() 
                 << ": Recover " << itm->getHealth() << " Health";
        }
        cout << endl << "(" << (char)('a'+i) << ") " << "Back"
             << endl << "Enter: ";

        char c;
        do {
            cin >> c;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            i = tolower(c) - 'a';
            if (i > n || i < 0) cout << "Wrong input. Please enter again: ";
        } while (i > n || i < 0);

        if (i == n) return;

        cout << endl << "Please chose use, discard or go back: "
             << endl << "(a) Use" 
             << endl << "(b) Discard"
             << endl << "(c) Back"
             << endl << "Enter: ";
        do {
            cin >> c;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            c = tolower(c);
            if (c == 'c') return;
            if (c < 'a' || c > 'c') cout << "Wrong input. Please enter again: ";
        } while (c < 'a' || c > 'c');

        itm = dynamic_cast<Item*>(inventory[i]);
        if ((c == 'a' && itm->triggerEvent(this)) || c == 'b') {
            delete inventory[i];
            if (i != n - 1) {
                for (int j = i; j < n - 1; j++)
                    inventory[j] = inventory[j + 1];
            }
            inventory[n - 1] = nullptr;
            inventory.pop_back();
        }
    }
}