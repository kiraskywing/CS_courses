// ans: 427

#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    long long res = 0, num, target;
    unordered_set<long long> nums;
    vector<int> targets(20001, 0);
    vector<long long> arr;
    while (cin >> num)
        arr.push_back(num);
    sort(arr.begin(), arr.end());
    
    int i = 0, j = arr.size() - 1;
    while (i < j) {
        if (arr[i] + arr[j] < -10000)
            i++;
        else if (arr[i] + arr[j] > 10000)
            j--;
        else {
            for (int k = j; k > i; k--) {
                num = arr[i] + arr[k];
                if (num < -10000) {
                    i++;
                    break;
                }
                if (arr[i] != arr[k])
                    targets[num + 10000] = 1;
            }
        }
    }
    for (int i : targets)
        res += i;

    // while (cin >> num) {
    //     for (int i = 0; i < 20001; i++) {
    //         if (targets[i])
    //             continue;
            
    //         target = i - 10000 - num;
    //         if (nums.count(target) && target != num) {
    //             res++;
    //             targets[i] = 1;
    //         }
    //     }
    //     if (!nums.count(num))
    //         nums.insert(num);
    //     if (res == 20001)
    //         break;
    // }
    cout << res << endl;

    return 0;
}