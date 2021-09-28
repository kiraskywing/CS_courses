#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> arr(n + 1, 0), dp(n + 1, 0), record(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    
    dp[1] = arr[1];
    for (int i = 2; i <= n; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
    
    int j = n;
    while (j >= 2) {
        if (dp[j - 1] >= dp[j - 2] + arr[j])
            j--;
        else {
            record[j] = 1;
            j -= 2;
        }
    }

    cout << record[1] << record[2] << record[3] << record[4] << record[17] << record[117] << record[517] << record[997] << endl;
    
    return 0;
}