#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

void quicksort(vector<int> &array, int left, int right) {
    if (left >= right)
        return;
    
    int i = left, j = right;
    int pivot = array[(i + j) / 2];

    while (i <= j) {
        while (i <= j && array[i] < pivot)
            i++;
        while (i <= j && array[j] > pivot)
            j--;
        if (i <= j) {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++; j--;
        }
    }

    quicksort(array, left, j);
    quicksort(array, i, right);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    while (n != 0) {
        vector<int> array(n, 0);
        for (int i = 0; i < n; i++)
            cin >> array[i];
        
        quicksort(array, 0, n - 1);

        for (int i : array) cout << i << ' ';
        cout << endl;

        cin >> n;
    }

    return 0;
}