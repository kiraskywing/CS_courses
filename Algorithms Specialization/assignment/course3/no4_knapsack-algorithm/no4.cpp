#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int wLimit, n;
    cin >> wLimit >> n;

    vector<int> dp(wLimit + 1, 0);
    int val, w;
    while (n--) {
        cin >> val >> w;
        for (int i = wLimit; i >= 0; i--) {
            if (i >= w)
                dp[i] = max(dp[i], dp[i - w] + val);
        }
    }

    cout << dp[wLimit] << endl;
    
    return 0;
}