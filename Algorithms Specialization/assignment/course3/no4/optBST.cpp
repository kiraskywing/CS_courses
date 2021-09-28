#include <iostream>
#include <vector>
#include <algorithm>
#include <float.h>
using namespace std;

int main(void) {
    int n = 7;
    vector<double> w = {0.2, 0.05, 0.17, 0.1, 0.2, 0.03, 0.25};
    vector<vector<double>> dp(n, vector<double>(n, 0));

    for (int s = 0; s < n; s++) {
        for (int i = 0; i + s < n; i++) {
            double wSum = 0;
            for (int j = i; j <= i + s; j++)
                wSum += w[j];
            
            double minSub = DBL_MAX;
            for (int r = i; r <= i + s; r++) {
                double cur = 0;
                if (i <= r - 1) cur += dp[i][r - 1];
                if (r + 1 <= i + s) cur += dp[r + 1][i + s];
                minSub = min(minSub, cur);
            }
            dp[i][i + s] = wSum + (minSub == DBL_MAX ? 0 : minSub);
        }
    }
    
    cout << dp[0][n - 1] << endl;
    
    return 0;
}