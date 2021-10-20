#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main(void) {
    int num, res = 0, mod = 10000;
    priority_queue<int> pqMax;
    priority_queue<int, vector<int>, greater<int>> pqMin;

    while (cin >> num) {
        if (pqMax.size() <= pqMin.size())
            pqMax.push(num);
        else
            pqMin.push(num);
        if (!pqMax.empty() && !pqMin.empty() && pqMax.top() > pqMin.top()) {
            int a = pqMax.top(), b = pqMin.top();
            pqMax.pop(); pqMin.pop();
            pqMax.push(b); pqMin.push(a);
        }

        num = pqMax.top();
        res += num;
        res %= mod;
    }
    cout << res;

    return 0;
}