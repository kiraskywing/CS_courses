#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void minheapify(vector<int>& heap, int parent, int size) {
    int child;
    while (true) {
        child = parent * 2;
        if (child > size) 
            break;
        if (child + 1 <= size && heap[child] > heap[child + 1]) 
            child = child + 1;
        if (heap[parent] > heap[child]) {
            swap(heap[parent], heap[child]);
            parent = child;
        }
        else 
            break;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int size;
    cin >> size;
    while (size > 0) {
        int res = 0;
        vector<int> heap(size + 1, 0);
        
        for (int i = 1; i < size + 1; i++) 
            cin >> heap[i];
        for (int i = size / 2; i > 0; i--) 
            minheapify(heap, i, size);

        while (size >= 2) {
            int temp1, temp2;
            temp1 = heap[1];
            res += temp1;
            heap[1] = heap[size--];
            minheapify(heap, 1, size);
            temp2 = heap[1];
            res += temp2;
            heap[1] = temp1 + temp2;
            minheapify(heap, 1, size);
        }
        cout << res << endl;

        cin >> size;
    }

    return 0;
}
