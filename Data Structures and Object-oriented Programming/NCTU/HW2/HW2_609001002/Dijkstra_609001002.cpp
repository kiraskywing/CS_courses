#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <climits>
#include <queue>

using namespace std;

typedef pair<int, int> iPair;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int numberOfVertices, numberOfEdges, startVertex, endVertex;
    cin >> numberOfVertices >> numberOfEdges >> startVertex >> endVertex;

    vector<vector<iPair>> edges(numberOfEdges);
    int v1, v2, cost;
    for (int i = 0; i < numberOfEdges; i++) {
        cin >> v1 >> v2 >> cost;
        edges[v1].push_back(make_pair(v2, cost));
    }

    vector<int> vertexWeight(numberOfVertices, INT_MAX);
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vertexWeight[startVertex] = 0;
    pq.push(make_pair(vertexWeight[startVertex], startVertex));

    while (!pq.empty()) {
        v1 = pq.top().second;
        pq.pop();

        if (v1 == endVertex) {
            cout << vertexWeight[v1] << endl;
            break;
        }

        for (iPair& edge : edges[v1]) {
            v2 = edge.first;
            cost = edge.second;
            if (vertexWeight[v1] + cost < vertexWeight[v2]) {
                vertexWeight[v2] = vertexWeight[v1] + cost;
                pq.push(make_pair(vertexWeight[v2], v2));
            }
        }
    }

    return 0;
}