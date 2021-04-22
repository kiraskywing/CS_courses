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
    vector<Object*> itms;
    Item* obj = nullptr;
    for (int i = 0; i < player.getInventorySize(); i++) {
        obj = new Item("Posion", 100);
        itms.push_back(obj);
    }
    player.setInventory(itms);
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
    player.setPreviousRoom(&rooms[start_room]);
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
    NPC* npc = new NPC("WeaponShop");
    
    vector<Object*> itms;
    Item* obj = nullptr;
    obj = new Item("NiceSword", 0, 1000, 0, 30);
    itms.push_back(obj);
    obj = new Item("SuperSword", 0, 2500, 0, 55);
    itms.push_back(obj);
    obj = new Item("UltraSword", 0, 5000, 0, 85);
    itms.push_back(obj);
    npc->setCommodity(itms);
    int npcRM = getRandomRoomNumber();
    rooms[npcRM].setObjects(npc);
    rooms[npcRM].setIsVisited(true);
    itms.clear();
    
    npc = new NPC("PosionShop");
    obj = new Item("NicePosion", 500);
    itms.push_back(obj);
    obj = new Item("SuperPosion", 1000);
    itms.push_back(obj);
    obj = new Item("UltraPosion", 2000);
    itms.push_back(obj);
    npc->setCommodity(itms);
    npcRM = getRandomRoomNumber();
    rooms[npcRM].setObjects(npc);
    rooms[npcRM].setIsVisited(true);
}

void Dungeon::createMonster() {
    int lv = player.getLevel();
    int times = pow(2.5, lv - 1);
    for (int i = 0; i < maxMonsterNumber; i++) {
        Monster* mon = new Monster(string("Slime_lv.") + to_string(lv), 150 * times, 100 * times, 100 * times);
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
        if (type == 1) itm = new Item(string("Coins_lv.") + to_string(lv), 0, 0, 200 * times);
        if (type == 2) itm = new Item(string("AttackUp_lv.") + to_string(lv), 0, 90 * times);
        if (type == 3) itm = new Item(string("HealthRecover_lv.") + to_string(lv), 95 * times);
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
    // cout << "(b) Load game" << endl;
    cout << "(c) Quit" << endl;
    cout << "Please choose one option: ";
    char c;
    do {
        cin >> c;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        c = tolower(c);
        if (!isalpha(c) || c < 'a' || c > 'c') cout << "Wrong option. Please enter again: ";
    } while (!isalpha(c) || c < 'a' || c > 'c');
        
    if (c == 'a') { 
        createMap();
        createPlayer();
    }
    // else if (c == 'b') { 
    //     Record rec;
    //     rec.loadFromFile(&player, rooms, this);
    // }
    else { 
        cout << "Goodbye!" << endl;
        exit(1); 
    }
}

void Dungeon::chooseAction() {
    // check items in current room and use handleEvent
    vector<string> actions = {"Move", "Check status", "Use inventory"};
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
    
    actions.push_back("Save to file");
    actions.push_back("Load test");
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
    
    Record rec;
    if (actions[i][0] == 'S') {
        rec.saveToFile(this, player, rooms);
        cout << endl << "Save success!" << endl;
    }
    if (actions[i][0] == 'L') {
        rec.loadFromFile(this, player, rooms);
        cout << endl << "Load success!" << endl;
    }
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
        
        cout << endl << "Congratulation! Game Clear!" << endl;
        return false;
    }

    return true;
}

void Dungeon::runDungeon() {
    startGame();
    
    do 
        chooseAction();
    while (checkGameLogic());

    cout << endl << "======= Game end =======" << endl;
}


void Record::saveToFile(Dungeon* d, Player& p, vector<Room>& rms) {
    ofstream outFile("savings.txt");
    if (!outFile.is_open()) {
        std::cerr << "Error opening output file" << std::endl;
        return;
    }
    saveDungoen(d, outFile);
    savePlayer(p, outFile);
    saveRooms(rms, outFile);
    outFile.close();
}
void Record::saveDungoen(Dungeon* d, ofstream& ofs) {
    ofs << "Dungeon" << ' ' 
        << d->getMapRow() << ' ' << d->getMapCol() << ' ' 
        << d->getCurMonNumber() << ' ' << d->getCurChestNumber() << ' ' 
        << d->getBossRoom()->getIndex() << endl;
}
void Record::savePlayer(Player& p, ofstream& ofs) {
    ofs << p.getTag() << ' ' << p.getName() << ' '
        << p.getMaxHealth() << ' ' << p.getCurrentHealth() << ' '
        << p.getAttack() << ' ' << p.getMoney() << ' ' << p.getCriticalAttackRate() << ' '
        << p.getCurrentRoom()->getIndex() << ' ' << p.getPreviousRoom()->getIndex() << ' '
        << p.getWeaponName() << ' ' << p.getWeaponAttack() << ' ' << p.getAddedAttack() << ' ' 
        << p.getLevel() << ' ' << p.getInventorySize() << ' ' << p.getInventory().size() << endl;
    
    for (Object* obj : p.getInventory()) saveItems(obj, ofs);
}
void Record::saveRooms(vector<Room>& rms, ofstream& ofs) {
    Object* obj = nullptr;
    for (Room &rm : rms) {
        ofs << "Room" << ' ' << rm.getIndex() << ' ' 
            << rm.getIsVisited() << ' ' << rm.getIsExit() << ' '
            << (rm.getUpRoom() ? rm.getUpRoom()->getIndex() : -1) << ' ' 
            << (rm.getDownRoom() ? rm.getDownRoom()->getIndex() : -1) << ' ' 
            << (rm.getLeftRoom() ? rm.getLeftRoom()->getIndex() : -1) << ' ' 
            << (rm.getRightRoom() ? rm.getRightRoom()->getIndex() : -1) << ' ';
        
        obj = rm.getObject();
        ofs << (obj ? 1 : 0) << endl;
        if (ofs) {
            saveMonsters(obj, ofs);
            saveItems(obj, ofs);
            saveNPCs(obj, ofs);
        }
    }
}
void Record::saveMonsters(Object* obj, ofstream& ofs) {
    Monster* mon = dynamic_cast<Monster*>(obj);
    if (!mon) return;
    ofs << mon->getTag() << ' ' << mon->getName() << ' '
        << mon->getMaxHealth() << ' ' << mon->getCurrentHealth() << ' '
        << mon->getAttack() << ' ' << mon->getMoney() << ' ' 
        << mon->getCriticalAttackRate() << endl;
}
void Record::saveItems(Object* obj, ofstream& ofs) {
    Item* itm = dynamic_cast<Item*>(obj);
    if (!itm) return;
    ofs << itm->getTag() << ' ' << itm->getName() << ' ' 
        << itm->getHealth() << ' ' << itm->getAttack() << ' ' 
        << itm->getMoney() << ' ' << itm->getCriticalAttackRate() << endl;
}
void Record::saveNPCs(Object* obj, ofstream& ofs) {
    NPC* npc = dynamic_cast<NPC*>(obj);
    if (!npc) return;
    ofs << npc->getTag() << ' ' << npc->getName() << endl;
    for (Object* obj : npc->getCommodity()) saveItems(obj, ofs);
}

void Record::loadFromFile(Dungeon* d, Player& p, vector<Room>& rms) {
    ifstream inFile("savings.txt");
    if (!inFile.is_open()) {
        std::cerr << "Error opening input file" << std::endl;
        exit(1);
    }

    loadDungoen(d, rms, inFile);
    loadPlayer(p, rms, inFile);
    loadRooms(rms, inFile);
    inFile.close();
}

void Record::loadDungoen(Dungeon* d, vector<Room>& rms, ifstream& ifs) {
    string line, name;
    getline(ifs, line);
    istringstream iss(line);
    int r, c, curMon, curCh, n_rooms, bRM;
    iss >> name >> r >> c >> curMon >> curCh >> bRM;
    
    cout << name << ' ' << r << ' ' << c << ' ' << curMon << ' ' << curCh << ' ' << bRM << endl;
    
    n_rooms = r * c;
    // d->setCurMonNumber(curMon); 
    // d->setCurChestNumber(curCh);
    // for (int i = 0; i < n_rooms; i++)
    //     rms.push_back(Room(i, false));
    // d->setBossRoom(&rms[bRM]);
}
void Record::loadPlayer(Player& p, vector<Room>& rms, ifstream& ifs) {
    string line, pName, wName;
    getline(ifs, line);
    stringstream iss(line);
    int maxHp, curHp, atk, money, car, cRM, pRM, wAtk, addedAtk, lv, maxN, curN;
    iss >> pName >> pName >> maxHp >> curHp >> atk >> money 
        >> car >> cRM >> pRM >> wName >> wAtk >> addedAtk >> lv >> maxN >> curN;
    
    cout << pName << ' ' << maxHp << ' ' << curHp << ' ' << atk << ' ' << money << ' ' 
         << car << ' ' << cRM << ' ' << pRM << ' ' << wName << ' ' << wAtk << ' ' 
         << addedAtk << ' ' << lv << ' ' << maxN << ' ' << curN << endl;
    
    // p.setName(pName); p.setMaxHealth(maxHp); p.setCurrentHealth(curHp);
    // p.setAttack(atk); p.setMoney(money); p.setCriticalAttackRate(car);
    // p.setCurrentRoom(&rms[cRM]); p.setPreviousRoom(&rms[pRM]);
    // p.setWeaponName(wName); p.setWeaponAttack(wAtk); p.setAddedAttack(addedAtk);
    // p.setLevel(lv); p.setInventorySize(maxN);

    // vector<Object*> itms;
    // Item* obj;
    string iName;
    int iHP, iAtk, iMny, iCar;
    for (int i = 0; i < curN; i++) {
        getline(ifs, line);
        iss.str(""); iss.clear(); iss << line;
        iss >> iName >> iName >> iHP >> iAtk >> iMny >> iCar;
        cout << iName << ' ' << iHP << ' ' << iAtk << ' ' << iMny << ' ' << iCar << endl;
        // obj = new Item(iName, iHP, iAtk, iMny, iCar);
        // itms.push_back(obj);
    }
    // p.setInventory(itms);
}
void Record::loadRooms(vector<Room>& rms, ifstream& ifs) {
    
    // void setIndex(int idx) { index = idx; }
    // void setIsVisited(bool iVt) { isVisited = iVt; }
    // void setIsExit(bool iEt) { isExit = iEt; }
    // void setUpRoom(Room* up) { upRoom = up; }
    // void setDownRoom(Room* down) { downRoom = down; }
    // void setLeftRoom(Room* left) { leftRoom = left; }
    // void setRightRoom(Room* right) { rightRoom = right; }
    // void setObjects(Object* obj) { object = obj; }
}