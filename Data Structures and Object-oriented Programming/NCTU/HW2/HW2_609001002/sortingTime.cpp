#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <random>
#include <ctime>
#include <fstream>
#include <string>
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
    random_device rd;
    default_random_engine gen(rd());
    uniform_int_distribution<int> dis(0, 100);
    
    ofstream outFile("savings.txt");

    int n, times = 100;
    cin >> n;
    vector<int> arr1(n, 0), arr2(n, 0), temp(n, 0);
    while (times--) {
        for (int i = 0; i < n; i++)
            arr1[i] = arr2[i] = dis(gen);
        
        clock_t t1_start = clock();
        quicksort(arr1, 0, n - 1);
        clock_t t1_end = clock();

        clock_t t2_start = clock();
        mergesort(arr2, temp, 0, n - 1);
        clock_t t2_end = clock();

        outFile << 1000.0 * (t1_end - t1_start) / CLOCKS_PER_SEC << ' '
                << 1000.0 * (t2_end - t2_start) / CLOCKS_PER_SEC << endl;
    }
    outFile.close();

    return 0;
}