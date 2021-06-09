#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <climits>
#include <queue>

using namespace std;

struct Vertex {
    int index, weight;
    bool visited;
    Vertex* parent;
    Vertex(int i): index(i), weight(INT_MAX), visited(false), parent(nullptr) {}
};
typedef pair<int, int> iPair;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int numberOfVertices, numberOfEdges;
    cin >> numberOfVertices >> numberOfEdges;
    
    vector<Vertex> vertices;
    for (int i = 0; i < numberOfVertices; i++)
        vertices.push_back(Vertex(i));

    vector<vector<iPair>> edges(numberOfVertices);
    int v1, v2, cost;
    for (int i = 0; i < numberOfEdges; i++) {
        cin >> v1 >> v2 >> cost;
        edges[v1].push_back(make_pair(v2, cost));
        edges[v2].push_back(make_pair(v1, cost));
    }

    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vertices[0].weight = 0;
    pq.push(make_pair(vertices[0].weight, 0));    
    // make_pair(weight, vertex index), start at vertex 0 with weight 0

    while (!pq.empty()) {
        v1 = pq.top().second;
        pq.pop();

        if (vertices[v1].visited)
            continue;
        vertices[v1].visited = true;

        for (iPair &edge : edges[v1]) {
            v2 = edge.first;
            cost = edge.second;
            if (!vertices[v2].visited && vertices[v2].weight > cost) {
                vertices[v2].weight = cost;
                vertices[v2].parent = &vertices[v1];
                pq.push(make_pair(vertices[v2].weight, v2));
            }
        }
    }

    int res = 0;
    for (int i = 0; i < numberOfVertices; i++)
        res += vertices[i].weight;
    cout << res << endl;

    return 0;
}
