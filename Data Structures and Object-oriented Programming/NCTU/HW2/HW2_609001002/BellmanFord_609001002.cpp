#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int numberOfVertices, numberOfEdges, startVertex, endVertex;
    cin >> numberOfVertices >> numberOfEdges >> startVertex >> endVertex;

    vector<vector<int>> edges;
    int v1, v2, cost;
    for (int i = 0; i < numberOfEdges; i++) {
        cin >> v1 >> v2 >> cost;
        edges.push_back({v1, v2, cost});
    }

    vector<int> vertexWeight(numberOfVertices, INT_MAX);
    vertexWeight[startVertex] = 0;

    for (int i = 0; i < numberOfVertices - 1; i++) {
        for (vector<int>& edge : edges) {
            v1 = edge[0]; v2 = edge[1]; cost = edge[2];
            if (vertexWeight[v1] != INT_MAX && vertexWeight[v1] + cost < vertexWeight[v2]) {
                vertexWeight[v2] = vertexWeight[v1] + cost;
            }
        }
    }
    for (vector<int>& edge : edges) {
        v1 = edge[0]; v2 = edge[1]; cost = edge[2];
        if (vertexWeight[v1] != INT_MAX && vertexWeight[v1] + cost < vertexWeight[v2]) {
            cout << "Negative loop detected!" << endl;
            return 0;
        }
    }

    cout << vertexWeight[endVertex] << endl;

    return 0;
}