#include "Dungeon.h"

using namespace std;

Dungeon::Dungeon() {}

void Dungeon::createPlayer() {
    string s_name;
    cout << "Please enter player's name: ";
    cin >> s_name;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    
    player.setName(s_name);
    player.setCurrentRoom(&rooms[0]);
}

void Dungeon::createMap() {
    int m = 3, n = 4;
    int clear_idx = m * n - 1;
    for (int i = 0; i < m * n; i++) {
        rooms.push_back(Room(false, i));
        vector<Object*> temp;
        if (i % 6 == 1) {
            Item* itm = new Item("posion", 200, 0, 0);
            temp.push_back(itm);
        }
        if (i % 6 == 2) {
            Monster* mon = new Monster("Slime", 150);
            temp.push_back(mon);
        }
        // if (i % 6 == 4) {
        //     NPC* npc = new NPC("Vender");
        //     temp.push_back(npc);
        // }
        
        if (!temp.empty())
            rooms[i].setObjects(temp);
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i > 0)     {rooms[j + i * n].setUpRoom(&rooms[j + (i - 1) * n]);}
            if (i + 1 < m) {rooms[j + i * n].setDownRoom(&rooms[j + (i + 1) * n]);}
            if (j > 0)     {rooms[j + i * n].setLeftRoom(&rooms[(j - 1) + i * n]);}
            if (j + 1 < n) {rooms[j + i * n].setRightRoom(&rooms[(j + 1) + i * n]);}
        }
    }
    
    rooms[clear_idx].setIsExit(true);
    Monster* lastBoss = new Monster("LastBoss", 300, 200, 1000);
    vector<Object*> boss = {lastBoss};
    rooms[clear_idx].setObjects(boss);
}

void Dungeon::handleMovement() {
    cout << endl << "Where do you want to go?\n";
    vector<string> moves;
    Room* curRM = player.getCurrentRoom();
    
    if (curRM->getUpRoom())    {moves.push_back("Move Up");}
    if (curRM->getDownRoom())  {moves.push_back("Move Down");}
    if (curRM->getLeftRoom())  {moves.push_back("Move Left");}
    if (curRM->getRightRoom()) {moves.push_back("Move Right");}
    
    int i;
    for (i = 0; i < moves.size(); i++)
        cout << "(" << (char)('a'+i) << ") " << moves[i] << endl;
    cout << "Please choose one direction: ";

    char c;
    do {
        cin >> c;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        
        i = tolower(c) - 'a';
        if (i >= moves.size()) {cout << "Wrong input. Please enter again: ";}
    } while (i >= moves.size());

    if (moves[i][5] == 'U') {player.changeRoom(curRM->getUpRoom());}
    if (moves[i][5] == 'D') {player.changeRoom(curRM->getDownRoom());}
    if (moves[i][5] == 'L') {player.changeRoom(curRM->getLeftRoom());}
    if (moves[i][5] == 'R') {player.changeRoom(curRM->getRightRoom());}
}

void Dungeon::startGame() {
    while (true) {
        cout << "===== Simple Dungeon Game =====" << endl;
        cout << "(a) Start new game" << endl;
        // cout << "(b) Load previous game" << endl;
        cout << "(c) Quit" << endl;
        cout << "Please choose one option: ";
        
        char c;
        cin >> c;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        
        if (isalpha(c) && tolower(c) == 'a') { 
            createMap();
            createPlayer();
            break; 
        }
        // else if (isalpha(c) && tolower(c) == 'b') { 
        //     class Record rec;
        //     rec.loadFromFile(&player, rooms);
        //     break; 
        // }
        else if (isalpha(c) && tolower(c) == 'c') { 
            cout << "Goodbye!" << endl;
            exit(1); 
        }
        else 
            cout << "Wrong option. Please enter again." << endl;
    }
}

void Dungeon::chooseAction() {
    // check items in current room and use handleEvent
    vector<string> actions = {"Move", "Check status"};
    Monster* mon = nullptr;
    Item* itm = nullptr;
    // NPC* npc = nullptr;
    Room* curRM = player.getCurrentRoom();
    
    for (Object* obj:curRM->getObjects()) {
        mon = dynamic_cast<Monster*>(obj);
        itm = dynamic_cast<Item*>(obj);
        // npc = dynamic_cast<NPC*>(obj);
    }
    
    if (mon) {
        mon->triggerEvent(&player);
        if (mon->checkIsDead()) {
            cout << "You beat " << mon->getName() << "!\n";
            curRM->popObject(mon);
            mon = nullptr;
        }
        return;
    }
    if (itm) actions.push_back("Pick up item");
    // if (npc) actions.push_back("Talk to NPC");
    
    // actions.push_back("Save to file");
    
    int i;
    cout << endl << "Please choose one action: ";
    for (i = 0; i < actions.size(); i++)
        cout << endl << "(" << (char)('a'+i) << ") " << actions[i];
    cout << endl << "Enter: ";

    char c;
    do {
        cin >> c;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        
        i = tolower(c) - 'a';
        if (i >= actions.size() || i < 0) {cout << "Wrong input. Please enter again: ";}
    } while (i >= actions.size());

    if (actions[i][0] == 'M') handleMovement();
    if (actions[i][0] == 'C') player.triggerEvent(&player);
    if (actions[i][0] == 'P') {
        itm->triggerEvent(&player);
        curRM->popObject(itm);
        itm = nullptr;
    }
    // if (actions[i][0] == 'A') npc->triggerEvent(&player);
    // if (actions[i][0] == 'S') {
    //     class Record rec;
    //     rec.saveToFile(&player, rooms);
    //     break;
    // }
}

bool Dungeon::checkGameLogic() {
    Room* curRM = player.getCurrentRoom();
    
    if (player.checkIsDead()) {
        cout << "You die!" << endl;
        return false;
    }
    
    Monster* mon = nullptr;
    for (Object* obj:curRM->getObjects())
        mon = dynamic_cast<Monster*>(obj);   
    if (mon && !mon->checkIsDead()) 
        return true;
    
    if (curRM->getIsExit()) {
        cout << "Congrats! Game Clear!" << endl;
        return false;
    }

    return true;
}

void Dungeon::runDungeon() {
    startGame();
    
    do 
        chooseAction();
    while (checkGameLogic());

    cout << endl << "===== Game end =====" << endl;
}