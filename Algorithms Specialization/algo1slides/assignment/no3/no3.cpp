#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int qSort(vector<int>& nums, int left, int right);
int getPivotIdx(vector<int>& nums, int a, int b, int c);
int partition(vector<int>& nums, int left, int right, int idx);

int main() {
    int num;
    vector<int> nums;

    while (cin >> num)
        nums.emplace_back(num);
    
    int res = qSort(nums, 0, nums.size() - 1);
    // for (int n : nums)
    //     cout << n << ' ';
    // cout << endl;
    cout << "Comparisons: " << res << endl;

    return 0;
}

int qSort(vector<int>& nums, int left, int right) {
    if (left >= right)
        return 0;
    
    int res = right - left;

    // int pivotIdx = left;    // sub1
    // int pivotIdx = right;    // sub2
    int pivotIdx = getPivotIdx(nums, left, (left + right) / 2, right);    // sub3
    
    int parIdx = partition(nums, left, right, pivotIdx);
    res += qSort(nums, left, parIdx - 1);
    res += qSort(nums, parIdx + 1, right);
    
    return res;
}

int getPivotIdx(vector<int>& nums, int a, int b, int c) {
    int mid = 0;
    if (nums[a] <= nums[b] && nums[b] <= nums[c])
        mid = b;
    else if (nums[a] <= nums[c] && nums[c] <= nums[b])
        mid = c;
    else if (nums[b] <= nums[a] && nums[a] <= nums[c])
        mid = a;
    else if (nums[b] <= nums[c] && nums[c] <= nums[a])
        mid = c;
    else if (nums[c] <= nums[a] && nums[a] <= nums[b])
        mid = a;
    else if (nums[c] <= nums[b] && nums[b] <= nums[a])
        mid = b;
    return mid;
}

int partition(vector<int>& nums, int left, int right, int idx) {
    swap(nums[left], nums[idx]);
    int i = left + 1;
    for (int j = i; j <= right; j++) {
        if (nums[j] < nums[left]) {
            swap(nums[j], nums[i]);
            i++;
        }
    }
    swap(nums[left], nums[i - 1]);
    return i - 1;
}