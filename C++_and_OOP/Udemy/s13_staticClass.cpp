// Section 13
// Static class members
#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
    static int num_players;
    std::string name;
    int health;
    int xp;
public:
    std::string get_name() { return name; }
    int get_health() { return health; }
    int get_xp() {return xp; } 
    
    Player(std::string name_val ="None", int health_val = 0, int xp_val = 0)
        : name{name_val}, health{health_val}, xp{xp_val} {
            ++num_players;
        }
    // Copy constructor
    Player(const Player &source)
        : Player {source.name, source.health, source.xp}  {
        }
    // Destructor
    ~Player(){
    --num_players;
    }
    
    static int get_num_players(){
    return num_players;
    }
};

int Player::num_players {0};
// initialize static variable

void display_active_players() {
    cout << "Active players: " << Player::get_num_players() << endl;
}

int main() {
    display_active_players();
    Player hero{"Hero"};
    display_active_players();
    
    {
        Player frank{"Frank"};
        display_active_players();
    }
    display_active_players();
    
    Player *enemy = new Player("Enemy", 100, 100);
    display_active_players();
    delete enemy;
    display_active_players();    



    return 0;
}

