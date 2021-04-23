#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  	vector<int> v;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int times;
    cin >> times;
    while (times--) {
        char c;
        int n;
        cin >> c;
        if (c == 'a') {
            cin >> n;
            v.push_back(n);
        }
        else if (c == 'e') {
            cin >> n;
            auto it = find(v.begin(), v.end(), n);
            if (it != v.end())
                v.erase(it);
        }
        else if (c == 'r')
            reverse(v.begin(), v.end());
        else if (c == 'd')
            v.pop_back();
        else if (c == 's')
            cout << v.size() << ' ';
        else if (c == 'p') {
            for (int &i : v)
                cout << i << ' ';
        }
    }
    
    return 0;
}