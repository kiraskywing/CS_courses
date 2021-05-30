#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

void mergesort(vector<int> &array, vector<int> &temp, int left, int right) {
    if (left >= right)
        return;
    
    int mid = (left + right) / 2;
    
    mergesort(array, temp, left, mid);
    mergesort(array, temp, mid + 1, right);

    int i = left, j = mid + 1;
    int index = left;
    while (i <= mid && j <= right) {
        if (array[i] <= array[j])
            temp[index++] = array[i++];
        else
            temp[index++] = array[j++];
    }
    while (i <= mid)
        temp[index++] = array[i++];
    while (j <= right)
        temp[index++] = array[j++];
    for (int k = left; k <= right; k++)
        array[k] = temp[k];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    while (n != 0) {
        vector<int> array(n, 0), temp(n, 0);
        for (int i = 0; i < n; i++)
            cin >> array[i];
        
        mergesort(array, temp, 0, n - 1);

        for (int i : array) cout << i << ' ';
        cout << endl;

        cin >> n;
    }

    return 0;
}