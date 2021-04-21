#include "Dungeon.h"

using namespace std;

int Dungeon::randomInt(int start, int end) {
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(start, end);
    return distribution(generator);
}

int Dungeon::getRandomRoomNumber() {
    int idx;
    Room* curRM = player.getCurrentRoom();
    do {
        idx = randomInt(0, map_row * map_col - 1);
    } while ((curRM && curRM->getIndex() == idx) || rooms[idx].getObject());

    return idx;
}

void Dungeon::createPlayer() {
    string s_name;
    cout << "Please enter player's name: ";
    cin >> s_name;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    
    player.setName(s_name);
    vector<Object*> itm;
    Item* obj;
    for (int i = 0; i < player.getInventorySize(); i++) {
        obj = new Item("Posion", 100);
        itm.push_back(obj);
    }
    player.setInventory(itm);
}

void Dungeon::createMap() {
    for (int i = 0; i < map_row * map_col; i++) 
        rooms.push_back(Room(i, false));
    
    for (int i = 0; i < map_row; i++) {
        for (int j = 0; j < map_col; j++) {
            if (i > 0)     {rooms[j + i * map_col].setUpRoom(&rooms[j + (i - 1) * map_col]);}
            if (i + 1 < map_row) {rooms[j + i * map_col].setDownRoom(&rooms[j + (i + 1) * map_col]);}
            if (j > 0)     {rooms[j + i * map_col].setLeftRoom(&rooms[(j - 1) + i * map_col]);}
            if (j + 1 < map_col) {rooms[j + i * map_col].setRightRoom(&rooms[(j + 1) + i * map_col]);}
        }
    }

    // set player's start position
    int start_room = getRandomRoomNumber();
    player.setCurrentRoom(&rooms[start_room]);
    rooms[start_room].setIsVisited(true);

    // set boss' position
    int bossRM = getRandomRoomNumber();
    boss_room = &rooms[bossRM];
    Monster* boss = new Monster("Boss", 1000, 1000, 1000, 20);
    rooms[bossRM].setObjects(boss);
    rooms[bossRM].setIsVisited(true);

    // set goal position
    int exitRM = getRandomRoomNumber();
    rooms[exitRM].setIsExit(true);

    // set NPC
    createNPC();
    
    // set Monsters
    createMonster();

    // set Treasure
    createChest(maxChestNumber);
}

void Dungeon::createNPC() {
    NPC* npc = new NPC("WeaponShop", "NPC", 
    vector<Item>{Item("UltraSword", 0, 5000, 0, 90), Item("SuperSword", 0, 2500, 0, 65), Item("NiceSword", 0, 1000, 0, 40)});
    int npcRM = getRandomRoomNumber();
    rooms[npcRM].setObjects(npc);
    rooms[npcRM].setIsVisited(true);
    
    npc = new NPC("PosionShop", "NPC", vector<Item>{Item("UltraPosion", 2000), Item("SuperPosion", 1000), Item("NicePosion", 500)});
    npcRM = getRandomRoomNumber();
    rooms[npcRM].setObjects(npc);
    rooms[npcRM].setIsVisited(true);
}

void Dungeon::createMonster() {
    int lv = player.getLevel();
    int times = pow(2.5, lv - 1);
    for (int i = 0; i < maxMonsterNumber; i++) {
        Monster* mon = new Monster(string("Slime lv.") + to_string(lv), 150 * times, 100 * times, 100 * times);
        int monRM = getRandomRoomNumber();
        rooms[monRM].setObjects(mon);
        rooms[monRM].setIsVisited(true);
    }
    currentMonsterNumber = maxMonsterNumber;
}

void Dungeon::createChest(int n) {
    int lv = player.getLevel();
    int times = pow(2, lv - 1);
    Item* itm = nullptr;
    int type, iRM;
    for (int i = 0; i < n; i++) {
        type = randomInt(1, 3);
        if (type == 1) itm = new Item(string("Coins lv.") + to_string(lv), 0, 0, 200 * times);
        if (type == 2) itm = new Item(string("AttackUp lv.") + to_string(lv), 0, 90 * times);
        if (type == 3) itm = new Item(string("HealthRecover lv.") + to_string(lv), 95 * times);
        iRM = getRandomRoomNumber();
        rooms[iRM].setObjects(itm);
        rooms[iRM].setIsVisited(true);
    }
    currentChestNumber = maxChestNumber;
}

void Dungeon::handleMovement() {
    showMap();
    
    cout << endl << "Where do you want to go?\n";
    vector<string> moves;
    
    Room* curRM = player.getCurrentRoom();
    if (curRM->getUpRoom())    {moves.push_back("Move Up");}
    if (curRM->getDownRoom())  {moves.push_back("Move Down");}
    if (curRM->getLeftRoom())  {moves.push_back("Move Left");}
    if (curRM->getRightRoom()) {moves.push_back("Move Right");}
    
    int i, n = moves.size();
    for (i = 0; i < n; i++)
        cout << "(" << (char)('a'+i) << ") " << moves[i] << endl;
    cout << "Please choose one direction: ";

    char c;
    do {
        cin >> c;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        
        i = tolower(c) - 'a';
        if (i >= n || i < 0) {cout << "Wrong input. Please enter again: ";}
    } while (i >= n || i < 0);

    if (moves[i][5] == 'U') {player.changeRoom(curRM->getUpRoom()); }
    if (moves[i][5] == 'D') {player.changeRoom(curRM->getDownRoom()); }
    if (moves[i][5] == 'L') {player.changeRoom(curRM->getLeftRoom()); }
    if (moves[i][5] == 'R') {player.changeRoom(curRM->getRightRoom()); }
    
    curRM = player.getCurrentRoom();
    curRM->setIsVisited(true);
    showMap();
}

void Dungeon::showMap() {
    int pRM = player.getCurrentRoom()->getIndex();

    string line(map_col * 4 + 1, '-');
    
    cout << endl << "[MAP]";
    cout << endl << ' ' << line << endl;
    for (int i = 0; i < map_row; i++) {
        for (int j = 0; j < map_col; j++) {
            int cRM = j + i * map_col;
            cout << " | ";
            if (rooms[cRM].getIsVisited()) {
                Monster* mon = nullptr;
                Item* itm = nullptr;
                NPC* npc = nullptr;
                Object* obj = rooms[cRM].getObject();
                mon = dynamic_cast<Monster*>(obj);
                itm = dynamic_cast<Item*>(obj);
                npc = dynamic_cast<NPC*>(obj);

                if (cRM == pRM) cout << 'P';
                else if (mon) cout << (mon->getName() == string("Boss") ? 'B' : 'M');
                else if (itm) cout << 'C';
                else if (npc) cout << 'S';
                else if (rooms[cRM].getIsExit()) cout << 'G';
                else cout << ' ';
            }
            else cout << '?';
        }
        cout << " | " << endl << ' ' << line << endl;
    }
    cout << "?: Not explored" << endl;
    cout << "P: Player, M: Monster, B: Boss" << endl;
    cout << "S: Shop, C: Chest, G: Goal" << endl;
}

void Dungeon::startGame() {
    cout << "===== Simple Dungeon Game =====" << endl;
    cout << "(a) Start new game" << endl;
    // cout << "(b) Load previous game" << endl;
    cout << "(c) Quit" << endl;
    cout << "Please choose one option: ";
    while (true) {
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
    vector<string> actions = {"Move", "Check status", "Use posion"};
    Monster* mon = nullptr;
    Item* itm = nullptr;
    NPC* npc = nullptr;
    Room* curRM = player.getCurrentRoom();
    
    Object* obj = curRM->getObject();
    mon = dynamic_cast<Monster*>(obj);
    itm = dynamic_cast<Item*>(obj);
    npc = dynamic_cast<NPC*>(obj);
    
    if (mon) {
        mon->triggerEvent(&player);
        if (mon->checkIsDead()) {
            cout << "You beat " << mon->getName() << "!\n";
            if (mon->getName() != string("Boss")) currentMonsterNumber--;
            player.increaseStates(0, 0, mon->getMoney());
            curRM->popObject();
            mon = nullptr;
            if (currentMonsterNumber == 0) {
                if (currentChestNumber < maxChestNumber) 
                    createChest(maxChestNumber - currentChestNumber);
                player.levelUp();
                createMonster();
            }
        }
        return;
    }
    if (itm && itm->triggerEvent(&player)) {
        curRM->popObject();
        itm = nullptr;
        currentChestNumber--;
    }
    if (npc) actions.push_back("Talk to shop");
    
    // actions.push_back("Save to file");
    actions.push_back("Quit");
    
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
    } while (i >= actions.size() || i < 0);

    if (actions[i][0] == 'M') handleMovement();
    if (actions[i][0] == 'C') { player.triggerEvent(nullptr); showMap(); }
    if (actions[i][0] == 'U') { player.useInventory(); }
    if (actions[i][0] == 'T') npc->triggerEvent(&player);
    // if (actions[i][0] == 'S') {
    //     Record rec;
    //     rec.saveToFile(&player, rooms);
    // }
    if (actions[i][0] == 'Q') { cout << "Goodbye!" << endl; exit(1); }

    
    
}

bool Dungeon::checkGameLogic() {
    Room* curRM = player.getCurrentRoom();
    
    if (player.checkIsDead()) {
        cout << "You die!" << endl;
        return false;
    }
    
    if (curRM->getIsExit()) {
        Monster* mon = nullptr;
        Object* obj = boss_room->getObject();
        mon = dynamic_cast<Monster*>(obj);   
        if (mon && !mon->checkIsDead()) {
            cout << endl << "You reach the goal, but the Boss is still alive." << endl;
            return true;
        }
        
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