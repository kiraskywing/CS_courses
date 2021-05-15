#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int times;
    cin >> times;
    
    while (times--) {
        string s;
        stack<char> stk;
        bool check = true;
        cin >> s;
        
        if (s.empty() || s.size() % 2 != 0) {
            cout << "no" << endl;
            continue;
        }

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{')
                stk.push(c);
            else if (stk.empty()) {
                cout << "no" << endl;
                check = false;
                break;
            }
            else if ((c == ')' && stk.top() == '(') || (c == ']' && stk.top() == '[') || (c == '}' && stk.top() == '{'))
                stk.pop();
        }

        if (check) cout << (stk.empty() ? "yes" : "no") << endl;   
    }
    
    return 0;
}