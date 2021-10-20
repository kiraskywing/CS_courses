#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <vector>
#include <bitset>
using namespace std;

void getSubsets(unordered_set<int>& cur, unordered_set<int>& prev, int n);

int main(void) {
    int n;
    cin >> n;
    float cities_x[n], cities_y[n];
    for (int i = 0; i < n; i++)
        cin >> cities_x[i] >> cities_y[i];

    vector<vector<float>> dist(n, vector<float>(n, INT_MAX));
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            float d = hypot(cities_x[i] - cities_x[j], cities_y[i] - cities_y[j]);
            dist[i][j] = dist[j][i] = d;
        }
    }

    vector<vector<float>> dp(1 << n, vector<float>(n, INT_MAX));
    dp[1 << 0][0] = 0;
    unordered_set<int> prev, cur;
    prev.insert(1 << 0);

    for (int m = 2; m <= n; m++) {
        getSubsets(cur, prev, n);
        for (int s : cur) {
            for (int j = 1; j < n; j++) {
                if (s & 1 << j) {
                    for (int k = 0; k < n; k++) {
                        if (j != k && (s & 1 << k)) {
                            int s_prev = s ^ 1 << j;
                            if (dp[s_prev][k] != INT_MAX && dist[k][j] != INT_MAX)
                                dp[s][j] = min(dp[s][j], dp[s_prev][k] + dist[k][j]);
                        }
                    }
                }
            }
        }
        prev = cur;
    }

    float res = INT_MAX;
    for (int j = 1; j < n; j++) {
        if (dist[j][0] != INT_MAX)
            res = min(res, dp[(1 << n) - 1][j] + dist[j][0]);
    }
    cout << res << endl;
    
    return 0;
}

void getSubsets(unordered_set<int>& cur, unordered_set<int>& prev, int n) {
    cur.clear();
    for (int i : prev) {
        for (int j = 1; j < n; j++) {
            if ((i & 1 << j) == 0 && !cur.count(i | 1 << j)) 
                cur.insert(i | 1 << j);
        }
    }
}