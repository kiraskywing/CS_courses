#include "Dungeon.h"

using namespace std;

Dungeon::Dungeon() {}

void Dungeon::createPlayer() {
    string s_name;
    cout << "Please enter player's name: ";
    cin >> s_name;
    
    player.setName(s_name);
    player.setCurrentRoom(&rooms[0]);
}

void Dungeon::createMap() {
    int m = 3, n = 4;
    int clear_idx = m * n - 1;
    for (int i = 0; i < m * n; i++)
        rooms.push_back(Room(false, i));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i > 0)     {rooms[j + i * n].setUpRoom(&rooms[j + (i - 1) * n]);}
            if (i + 1 < m) {rooms[j + i * n].setDownRoom(&rooms[j + (i + 1) * n]);}
            if (j > 0)     {rooms[j + i * n].setLeftRoom(&rooms[(j - 1) + i * n]);}
            if (j + 1 < n) {rooms[j + i * n].setRightRoom(&rooms[(j + 1) + i * n]);}
        }
    }
    
    rooms[clear_idx].setIsExit(true);
}

void Dungeon::handleMovement() {
    cout << "Where do you want to go?" << endl;
    vector<string> moves;
    Room* curRM = player.getCurrentRoom();
    cout << "Current position index: " << curRM->getIndex() << endl << endl;
    
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
        i = tolower(c) - 'a';
        if (i >= moves.size()) {cout << "Wrong input. Please enter again: ";}
    } while (i >= moves.size());

    if (moves[i][5] == 'U') {player.changeRoom(curRM->getUpRoom());}
    if (moves[i][5] == 'D') {player.changeRoom(curRM->getDownRoom());}
    if (moves[i][5] == 'L') {player.changeRoom(curRM->getLeftRoom());}
    if (moves[i][5] == 'R') {player.changeRoom(curRM->getRightRoom());}
}

// void Dungeon::handleEvent(Object*) {}

void Dungeon::startGame() {
    while (true) {
        cout << "===== Simple Dungeon Game =====" << endl;
        cout << "(a) Start new game" << endl;
        // cout << "(b) Load previous game" << endl;
        cout << "(c) Quit" << endl;
        cout << "Please choose one option: ";
        
        char c;
        cin >> c;
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

void Dungeon::chooseAction(vector<Object*>) {
    // check items in current room and use handleEvent
    
    char ch;
    while (true) {
        cout << "(a) Move" << endl;
        cout << "(b) Check status" << endl;
        cout << "Please choose one action: ";
        // cout << "C. Save to file" << endl;
        cin >> ch;
        
        // A. Move
        if (isalpha(ch) && tolower(ch) == 'a') {
            handleMovement();
            break;
        }

        // B. Check status
        else if (isalpha(ch) && tolower(ch) == 'b') {
            player.triggerEvent(&player);
            break;
        }

        // C. Save to file
        // else if (c == 'B') {
        //     class Record rec;
        //     rec.saveToFile(&player, rooms);
        //     break;
        // }

        else
            cout << "Wrong input. Please enter again." << endl;
    }
}

bool Dungeon::checkGameLogic() {
    GameCharacter *temp = dynamic_cast<GameCharacter*>(&player);
    Room* curRM = player.getCurrentRoom();
    
    if (temp->checkIsDead()) {
        cout << "You are dead!" << endl;
        return false;
    }

    if (curRM->getIsExit()) {
        cout << "Congrats! Game Clear!" << endl;
        return false;
    }

    return true;
}

void Dungeon::runDungeon() {
    startGame();
    
    do 
        chooseAction(vector<Object*>(0, nullptr));
    while (checkGameLogic());

    cout << endl << "===== Game end =====" << endl;
}