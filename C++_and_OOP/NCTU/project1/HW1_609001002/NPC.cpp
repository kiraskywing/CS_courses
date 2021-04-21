#include "NPC.h"

using namespace std;

NPC::NPC(string name, string tag, vector<Item> itm)
    : GameCharacter(name, tag), script(""), commodity(itm) {}

// void NPC::listCommodity() {}

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
        while (true) {
            int i, j, n = commodity.size();
            cout << endl << "Please choose item: \n";
            for (j = 0; j < n; j++) 
                cout << "(" << (char)('a'+j) << ") " << commodity[j].getName() << endl;
            cout << "(" << (char)('a'+j) << ") " << "Back" << endl;
            cout << "Enter: ";
            
            do {
                cin >> c;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                
                i = tolower(c) - 'a';
                if (i > n || i < 0) 
                    cout << "Wrong input. Please enter again: ";
            } while (i > n || i < 0);
            
            if (i == n) return true;
            
            Item &itm = commodity[i];
            itm.triggerEvent(p);
        }
    }

    return true;
}

// void NPC::setScript(string) {}
// void NPC::setCommodity(vector<Item>) {}
// string NPC::getScript() {}