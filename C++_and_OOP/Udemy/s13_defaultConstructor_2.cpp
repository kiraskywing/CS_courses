// Section 13
// Default Constructor Parameters
#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
    std::string name;
    int health;
    int xp;
public:
    Player(string name_val = "None", int health_val = 0, int xp_val = 0);
    void details();
  //  Player() {}    // Will cause a compiler error
};

Player::Player(string name_val, int health_val, int xp_val) 
    :name {name_val}, health {health_val}, xp {xp_val} {
        cout << "Three-args constructor" << endl;
}
void Player::details() {
    cout << name << " " << health << " " << xp << endl;
}

int main() {
    
    Player empty;
    empty.details();
    Player frank {"Frank"};
    frank.details();
    Player hero {"Hero", 100};
    hero.details();
    Player villain {"Villain", 100, 55};
    villain.details();
    
    return 0;
}

