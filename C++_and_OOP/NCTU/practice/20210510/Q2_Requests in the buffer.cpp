#include <iostream>
#include <queue>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int times, i;
    queue<int> q;
    cin >> times;
    while (times--) {
        cin >> i;
        while (!q.empty() && (i - q.front() > 5000))
            q.pop();
        q.push(i);
        cout << q.size() << ' ';
    }
    
    return 0;
}