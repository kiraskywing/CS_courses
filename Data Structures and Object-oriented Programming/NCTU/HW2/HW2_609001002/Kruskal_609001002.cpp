#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int vertex1, vertex2, cost;
    Edge(int a, int b, int c): vertex1(a), vertex2(b), cost(c) {}
};
struct Vertex {
    int parent, rank;
    Vertex(int i): parent(i), rank(0) {}
};
class UnionFind {
private:
    vector<Vertex> vertices;
public:
    UnionFind(int n) {
        for (int i = 0; i < n; i++)
            vertices.push_back(Vertex(i));
    }
    int Find(int i) {
        if (vertices[i].parent != i)
            vertices[i].parent = Find(vertices[i].parent);
        return vertices[i].parent;
    }
    void Union(int x, int y) {
        int xRoot = Find(x), yRoot = Find(y);
        if (vertices[xRoot].rank < vertices[yRoot].rank)
            vertices[xRoot].parent = yRoot;
        else if (vertices[xRoot].rank > vertices[yRoot].rank)
            vertices[yRoot].parent = xRoot;
        else {
            vertices[yRoot].parent = xRoot;
            vertices[xRoot].rank++;
        }
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int numberOfVertices, numberOfEdges;
    cin >> numberOfVertices >> numberOfEdges;

    UnionFind uf(numberOfVertices);

    vector<Edge> edges;
    int n1, n2, cost;
    for (int i = 0; i < numberOfEdges; i++) {
        cin >> n1 >> n2 >> cost;
        edges.push_back(Edge(n1, n2, cost));
    }

    sort(edges.begin(), edges.end(), [](Edge& e1, Edge& e2) { return e1.cost < e2.cost; });

    vector<Edge> res;
    int i_res = 0, i_edges = 0;
    while (i_res < numberOfVertices - 1 && i_edges < numberOfEdges) {
        Edge& cur = edges[i_edges++];
        
        int root1 = uf.Find(cur.vertex1), root2 = uf.Find(cur.vertex2);
        if (root1 != root2) {
            res.push_back(cur);
            i_res++;
            uf.Union(root1, root2);
        }
    }

    int totalCost = 0;
    for (Edge& edge : res)
        totalCost += edge.cost;
    cout << totalCost << endl;

    return 0;
}