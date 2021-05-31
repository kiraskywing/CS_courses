#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;

    vector<int> bucket1(19, 0), bucket2(19, 0);
    vector<bool> visited1(19, false), visited2(19, false);

    int num, index, probe;
    while (n--) {
        cin >> num;
        
        index = num % 19;
        while (visited1[index]) {
            index = (index + 1) % 19;
        }
        visited1[index] = true;
        bucket1[index] = num;

        index = num % 19;
        probe = 0;
        while (visited2[(index + probe * probe) % 19])
            probe++;
        visited2[(index + probe * probe) % 19] = true;
        bucket2[(index + probe * probe) % 19] = num;
    }

    for (int i = 0; i < 19; i++)
        cout << (visited1[i] ? bucket1[i] : 0) << ' ';
    cout << endl;

    for (int i = 0; i < 19; i++)
        cout << (visited2[i] ? bucket2[i] : 0) << ' ';
    cout << endl;

    return 0;
}
