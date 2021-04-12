#include "NPC.h"

using namespace std;

NPC::NPC(string name, string tag, vector<Item> itm)
    : GameCharacter(name, tag), script(""), commodity(itm) {}

// void NPC::listCommodity() {}

void NPC::triggerEvent(Object* obj) {
    if (commodity.empty()) {
        cout << "Sorry eveything sold out\n";
        return;
    }
    
    Player* p = dynamic_cast<Player*>(obj);
    
    cout << endl << "Welcome to the shop, please choose action\n"
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
        int i, n = commodity.size();
        cout << endl << "Please choose item: \n";
        for (int j = 0; j < n; j++) 
            cout << "(" << (char)('a'+j) << ") " << commodity[j].getName() << endl;
        cout << "Enter: ";
        
        do {
            cin >> c;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            
            i = tolower(c) - 'a';
            if (i >= n || i < 0) {cout << "Wrong input. Please enter again: ";}
        } while (i >= n || i < 0);
        
        Item itm = getCommodity(i);
        itm.triggerEvent(p);
    }
}

// void NPC::setScript(string) {}
// void NPC::setCommodity(vector<Item>) {}
// string NPC::getScript() {}

Item NPC::getCommodity(int i) {
    int n = commodity.size();
    Item itm = commodity[i];
    
    if (i != n - 1)
        commodity[i] = commodity[n - 1];
    commodity.pop_back();

    return itm;
}