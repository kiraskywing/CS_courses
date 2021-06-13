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
    
    int n = 100;
    for (int j = 0; j < 8; j++) {
        if (j > 0) n *= 2;
        uniform_int_distribution<int> dis(0, n - 1);
        
        double qtime = 0.0, mtime = 0.0;

        for (int times = 0; times < 100; times++) {
            vector<int> arr1(n, 0), arr2(n, 0), used(n, 0), temp(n, 0);
            int k = 0, num;
            while (k < n) {
                do {
                    num = dis(gen);
                } while (used[num]);
                used[num] = 1;
                arr1[k] = arr2[k] = num;
                k++;
            }
            clock_t t1_start = clock();
            quicksort(arr1, 0, n - 1);
            clock_t t1_end = clock();

            clock_t t2_start = clock();
            mergesort(arr2, temp, 0, n - 1);
            clock_t t2_end = clock();

            qtime += 1000000 * (t1_end - t1_start) / CLOCKS_PER_SEC;
            mtime += 1000000 * (t2_end - t2_start) / CLOCKS_PER_SEC;
        }

        qtime /= 100;
        mtime /= 100;
        cout << qtime << ' ' << mtime << endl;
    }

    return 0;
}