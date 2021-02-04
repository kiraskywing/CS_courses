#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
    string user;
    getline(cin, user);

    size_t n {user.length()};
    size_t len = n * 2 - 1;
    for (size_t i {0}; i < n; i++)
    {
        string cur {user.substr(0, i + 1)};
        string cur_reverse {cur.substr(0, i)};
        reverse(cur_reverse.begin(), cur_reverse.end());
        cur += cur_reverse;
        
        string empties {};
        for (size_t j {0}; j < (len - cur.length()) / 2; j++)
            empties += " ";
        
        cout << empties << cur << empties << endl;
    }
    
    return 0;
}