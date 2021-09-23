#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> iPair;

bool cmp1(iPair& p1, iPair& p2) {
    int diff1 = p1.first - p1.second, diff2 = p2.first - p2.second;
    if (diff1 != diff2) 
        return diff1 > diff2;
    return p1.first > p2.first;
}
bool cmp2(iPair& p1, iPair& p2) {
    double rank1 = (double) p1.first / p1.second, rank2 = (double) p2.first / p2.second;
    return rank1 > rank2;
}

int main(void) {
    int n, weight, length;
    cin >> n;
    vector<iPair> records;
    while (cin >> weight >> length) 
        records.push_back(make_pair(weight, length));
    
    sort(records.begin(), records.end(), cmp2);

    long long res = 0, time = 0;
    for (int i = 0; i < n; i++) {
        // double rank = (double) records[i].first / records[i].second;
        // cout << records[i].first << ' ' << records[i].second << ' ' << records[i].first - records[i].second << endl;
        // cout << records[i].first << ' ' << records[i].second << ' ' << rank << endl;
        time += records[i].second;
        res += time * records[i].first;
    }
    cout << res << endl;
    
    return 0;
}