#include <iostream>
using namespace std;

class Room{
public:
    Room *left_room;
    Room *right_room;
    int index;
  //add constructor or functions if you need
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int num;
    cin >> num;
    Room* prev = nullptr;
    Room* cur = nullptr;
    Room* head = nullptr;
    
    for (int i = 0; i < num; i++) {
        cur = new Room();
        cin >> cur->index;
        cur->left_room = prev;
        cur->right_room = nullptr;

        if (i == 0) {
            head = cur;
            prev = head;
        }
        else {
            prev->right_room = cur;
            prev = cur;
        }
    }

    char c;
    cin >> num;
    cur = head;
    cout << cur->index << " ";
    while (num--) {
        cin >> c;
        if (c == 'l') {
            if (cur->left_room) {
                cur = cur->left_room;
                cout << cur->index << " ";
            }
            else
                cout << -1 << " ";
        }
        if (c == 'r') {
            if (cur->right_room) {
                cur = cur->right_room;
                cout << cur->index << " ";
            }
            else
                cout << -1 << " ";
        }
    }

    while (head) {
        prev = head;
        head = head->right_room;
        if (head)
            head->left_room = nullptr;
        prev->right_room = nullptr;
        delete prev;
    }
    
    return 0;
}