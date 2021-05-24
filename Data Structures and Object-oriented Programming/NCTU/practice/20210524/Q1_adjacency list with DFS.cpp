#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void dfs(vector<vector<int>> &mat, vector<bool> &visited, vector<int> &temp, int i) {
    if (visited[i])
        return;
    
    temp.push_back(i);
    visited[i] = true;
    for (int j = 0; j < mat.size(); j++) {
        if (mat[i][j]) 
            dfs(mat, visited, temp, j);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n, 0));
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    }

    vector<int> temp;
    for (int i = 0; i < n; i++) {
        temp.clear();
        dfs(mat, visited, temp, i);
        
        if (!temp.empty()) {
            for (int num : temp)
                cout << num << ' ';
            cout << endl;
        }
    }

    return 0;
}
