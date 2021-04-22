#include "NPC.h"

using namespace std;

bool NPC::triggerEvent(Object* obj) {
    Player* p = dynamic_cast<Player*>(obj);
    string shopName = getName();
    cout << endl << "Welcome to " << shopName << ", please choose action\n"
         << "(a) Buy item\n"
         << "(b) Leave\n"
         << "Enter: ";
    char c;
    do {
        cin >> c;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        c = tolower(c);
        if (c != 'a' && c != 'b') cout << "Wrong input. Please enter again: ";
    } while (c != 'a' && c != 'b');
    
    if (c == 'a') {
        Item* itm = nullptr;
        while (true) {
            int i, j, n = commodity.size();
            int cur_money = p->getMoney();
            int cur_n = p->getInventorySize() - p->getInventory().size();
            cout << endl << "Your money: " << cur_money << ", number of inventory slots: " << cur_n << endl
                 << "Please choose item: " << endl;
            for (j = 0; j < n; j++) {
                itm = dynamic_cast<Item*>(commodity[j]);
                cout << "(" << (char)('a'+j) << ") " << itm->getName() << ", ";
                if (shopName == string("PosionShop")) 
                    cout << "recover health: " << itm->getHealth() << ", ";
                else {
                    cout << "weapon attack: " << itm->getAttack() 
                         << ", critical attack rate: " << itm->getCriticalAttackRate() << ", ";
                }
                cout << "price: " << 200 * (1 + 3 * j) << endl; 
            }
            cout << "(" << (char)('a'+j) << ") " << "Back" << endl
                 << "Enter: ";
            
            do {
                cin >> c;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                
                i = tolower(c) - 'a';
                if (i > n || i < 0) 
                    cout << "Wrong input. Please enter again: ";
            } while (i > n || i < 0);
            
            if (i == n) return true;
            
            int price = 200 * (1 + 3 * i);
            if (cur_money < price) {
                cout << endl << "You don't have enough money." << endl;
                continue;
            }
            
            itm = dynamic_cast<Item*>(commodity[i]);
            if (shopName == string("WeaponShop") && itm->triggerEvent(p)) {
                p->increaseStates(0, 0, -price);
                return true;
            }
            else if (shopName == string("PosionShop")) {
                int n_maxBuy = cur_money / price;
                n_maxBuy = (cur_n < n_maxBuy ? cur_n : n_maxBuy);
                if (n_maxBuy == 0) {
                    cout << "Your inventory is full." << endl;
                    continue;
                }

                cout << endl << "How many posions do you want to buy?" << endl
                     << "Enter number: (max: " << n_maxBuy << ", 0 to cancel)" << endl
                     << "Enter: ";
                do {
                    cin >> c;
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    j = c - '0';
                    if (j > n_maxBuy || j < 0) 
                        cout << "Wrong input. Please enter again: ";
                } while (j > n || j < 0);

                if (j == 0) continue;
                vector<Object*> objs;
                Item* obj;
                for (int k = 0; k < j; k++) {
                    obj = new Item();
                    *obj = *itm;
                    objs.push_back(obj);
                }
                p->setInventory(objs);
                cout << endl << "You got " << j << " " << itm->getName() << endl;
                p->increaseStates(0, 0, -price * j);
            }
        }
    }

    return true;
}

