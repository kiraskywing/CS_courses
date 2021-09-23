#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <fstream>
#include <sstream>

using namespace std;

void firstDfs(vector<int>& visited, vector<int>& secondVertices, vector<vector<int>>& edges, int i, int& finishTime);
void secondDfs(vector<int>& visited, vector<vector<int>>& edges, int i, int& SCCsize);

int main() {
    int a, b, n = 875714;
    vector<vector<int>> forwardEdges(n, vector<int>()), backwardEdges(n, vector<int>());
    vector<int> visited(n, 0), secondVertices(n, -1);

    while (cin >> a >> b) {
        if (a != b) {
            forwardEdges[a - 1].push_back(b - 1);
            backwardEdges[b - 1].push_back(a - 1);
        }
    }

    // cout << "Forward: \n";
    // for (int i = 0; i < n; i++) {
    //     for (int j : forwardEdges[i])
    //         cout << i << " -> " << j << endl;
    // }
    // cout << "Backward: \n";
    // for (int i = 0; i < n; i++) {
    //     for (int j : backwardEdges[i])
    //         cout << i << " -> " << j << endl;
    // }

    int finishTime = 0;
    for (int i = n - 1; i >= 0; i--)
        firstDfs(visited, secondVertices, forwardEdges, i, finishTime);
    
    // for (int i : secondVertices)
    //     cout << i << ' ';
    // cout << endl;
    
    visited.assign(n, 0);
    priority_queue<int, deque<int>, greater<int>> q;
    for (int i = n - 1; i >= 0; i--) {
        int index = secondVertices[i];
        if (!visited[index]) {
            int SCCsize = 0;
            secondDfs(visited, backwardEdges, index, SCCsize);
            q.push(SCCsize);
            if (q.size() > 5)
                q.pop();
        }
    }

    while (!q.empty()) {
        cout << q.top() << ' ';
        q.pop();
    }
    cout << endl;

    return 0;
}

void firstDfs(vector<int>& visited, vector<int>& secondVertices, vector<vector<int>>& edges, int i, int& finishTime) {
    if (visited[i])
        return;

    visited[i] = 1;
    for (int j : edges[i])
        firstDfs(visited, secondVertices, edges, j, finishTime);
    
    secondVertices[finishTime++] = i;
    return;
}

void secondDfs(vector<int>& visited, vector<vector<int>>& edges, int i, int& SCCsize) {
    if (visited[i])
        return;
    
    visited[i] = 1;
    SCCsize++;
    for (int j : edges[i])
        secondDfs(visited, edges, j, SCCsize);
}