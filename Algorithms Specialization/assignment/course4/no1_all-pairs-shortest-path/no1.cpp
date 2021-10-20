#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(n, vector<int>(n, INT_MAX));
    int v1, v2, cost;
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2 >> cost;
        edges[v1 - 1][v2 - 1] = cost;
    }

    vector<vector<vector<long>>> dp(n, vector<vector<long>>(n, vector<long>(n + 1)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                dp[i][j][0] = 0;
            else if (edges[i][j] != INT_MAX)
                dp[i][j][0] = edges[i][j];
            else
                dp[i][j][0] = INT_MAX;
        }
    }

    long res = INT_MAX;
    for (int k = 1; k <= n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j][k] = min(dp[i][j][k - 1], dp[i][k - 1][k - 1] + dp[k - 1][j][k - 1]);
                if (k == n) {
                    if (i == j && dp[i][j][k] < 0) {
                        cout << "Negative cycle detected\n";
                        return 0;
                    }
                    else if (i != j) {
                        res = min(res, dp[i][j][k]);
                    }
                }
            }
        }
    }
    cout << res << endl;
    
    return 0;
}