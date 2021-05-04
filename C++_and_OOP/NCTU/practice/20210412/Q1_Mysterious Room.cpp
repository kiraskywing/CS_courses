#include <vector>
#include <iostream>
using namespace std;

class Object{
public:
    virtual void response() = 0;
    
    virtual ~Object() = default;
};

class IceMonster : public Object{
	//add constructor or functions if you need
public:
    virtual void response() override { cout << "fire attack"; }
};

class FireMonster : public Object{
	//add constructor or functions if you need
public:
    virtual void response() override { cout << "ice attack"; }
};

class Treasure : public Object{
	//add constructor or functions if you need
public:
    virtual void response() override { cout << "ya"; }
};


class Room{
public:
    Room *up_room;
    Room *down_room;
    Room *left_room;
    Room *right_room;
    int index;
    Object *o;
    //add constructor or functions if you need

    Room(int i) : up_room(nullptr), down_room(nullptr), left_room(nullptr), right_room(nullptr), index(i), o(nullptr) {}
    
    void action() {
        cout << index << " ";
        if (o) {
            o->response();
            delete o;
            o = nullptr;
        }
        cout << endl;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int room_num, steps;
    cin >> room_num >> steps;
    Room* rooms[room_num];
    for (int i = 0; i < room_num; i++)
        rooms[i] = new Room(i);
        
    char c;
    for (int i = 0; i < room_num; i++) {        
        cin >> c;
        if (c == 'i') { rooms[i]->o = new IceMonster(); }
        else if (c == 'f') { rooms[i]->o = new FireMonster(); }
        else if (c == 't') { rooms[i]->o = new Treasure(); }

        int rm;
        cin >> rm;
        if (rm != -1) { rooms[i]->up_room = rooms[rm]; }
        cin >> rm;
        if (rm != -1) { rooms[i]->down_room = rooms[rm]; }
        cin >> rm;
        if (rm != -1) { rooms[i]->left_room = rooms[rm]; }
        cin >> rm;
        if (rm != -1) { rooms[i]->right_room = rooms[rm]; }
    }
    
    Room* cur = rooms[0];
    cout << cur->index << endl;
    while (steps--) {
        cin >> c;
        if (c == 'u' && cur->up_room) {
            cur = cur->up_room;
            cur->action();
        } 
        else if (c == 'd' && cur->down_room) {
            cur = cur->down_room;
            cur->action();
        }
        else if (c == 'l' && cur->left_room) {
            cur = cur->left_room;
            cur->action();
        }
        else if (c == 'r' && cur->right_room) {
            cur = cur->right_room;
            cur->action();
        }
        else 
            cout << -1 << endl;
    }

    for (int i = 0; i < room_num; i++) 
        delete rooms[i];

    return 0;
}