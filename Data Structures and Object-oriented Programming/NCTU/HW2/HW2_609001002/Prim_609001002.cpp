#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <climits>
#include <queue>

using namespace std;

struct Node {
    int index, weight;
    bool visited;
    Node* parent;
    Node(int i): index(i), weight(INT_MAX), visited(false), parent(nullptr) {}
};
typedef pair<int, int> iPair;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int m, n;
    cin >> m >> n;
    
    vector<Node> vertices;
    for (int i = 0; i < m; i++)
        vertices.push_back(Node(i));

    vector<vector<iPair>> edges(m);
    int n1, n2, cost;
    for (int i = 0; i < n; i++) {
        cin >> n1 >> n2 >> cost;
        edges[n1].push_back(make_pair(n2, cost));
        edges[n2].push_back(make_pair(n1, cost));
    }

    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vertices[0].weight = 0;
    pq.push(make_pair(vertices[0].weight, 0));    
    // make_pair(weight, vertex index), start at vertex 0 with weight 0

    while (!pq.empty()) {
        n1 = pq.top().second;
        pq.pop();

        if (vertices[n1].visited)
            continue;
        vertices[n1].visited = true;

        for (iPair &edge : edges[n1]) {
            n2 = edge.first;
            cost = edge.second;
            if (!vertices[n2].visited && vertices[n2].weight > cost) {
                vertices[n2].weight = cost;
                vertices[n2].parent = &vertices[n1];
                pq.push(make_pair(vertices[n2].weight, n2));
            }
        }
    }

    int res = 0;
    for (int i = 0; i < m; i++)
        res += vertices[i].weight;
    cout << res << endl;

    return 0;
}
