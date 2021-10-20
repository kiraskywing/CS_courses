#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Edge {
    int v1, v2, cost;
    Edge(int a, int b, int c): v1(a), v2(b), cost(c) {}
};

class UnionFind {
private:
    vector<int> parent, rank;
    int n_vertices;
public:
    UnionFind(int n) : n_vertices(n) {
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
            rank.push_back(0);
        }
    }
    
    int find(int i) {
        if (parent[i] != i)
            parent[i] = find(parent[i]);
        return parent[i];
    }
    
    void uni(int i, int j) {
        int pi = find(i), pj = find(j);
        
        if (pi != pj) {
            n_vertices--;
            
            if (rank[pi] < rank[pj])
                parent[pi] = pj;
            else if (rank[pi] > rank[pj])
                parent[pj] = pi;
            else {
                parent[pj] = pi;
                rank[pi]++;
            }
        }
    }

    int get_nv(void) { return n_vertices; }
};

typedef pair<int, int> iPair;

void createGraph(vector<Edge>& edges, int n);

int main(void) {
    int n, k = 4;
    cin >> n;
    vector<Edge> edges;
    createGraph(edges, n);
    UnionFind uf(n);

    int i = 0, m = edges.size(), v1, v2;
    while (uf.get_nv() > k) {
        v1 = edges[i].v1; v2 = edges[i].v2;
        uf.uni(v1, v2);
        i++;
    }

    int p1, p2, cost;
    unordered_map<int, int> record;
    for (; i < m; i++) {
        v1 = edges[i].v1; v2 = edges[i].v2; cost = edges[i].cost;
        p1 = uf.find(v1); p2 = uf.find(v2);
        if (p2 < p1) swap(p1, p2);
        if (p1 != p2) {
            int key = p1 * 1000 + p2;
            if (!record.count(key))
                record[key] = cost;
            else
                record[key] = min(record[key], cost);
        }
    }

    for (auto& d : record)
        cout << d.first / 1000 << "->" << d.first % 1000 << ": " << d.second << endl;
    
    return 0;
}

void createGraph(vector<Edge>& edges, int n) {
    int u, v, cost;
    vector<vector<bool>> record(n, vector<bool>(n, false));

    while (cin >> u >> v >> cost) {
        if (!record[u - 1][v - 1]) {
            edges.push_back(Edge(u - 1, v - 1, cost));
            record[u - 1][v - 1] = record[v - 1][u - 1] = 1;
        }
    }

    sort(edges.begin(), edges.end(), [](Edge& e1, Edge& e2){ return e1.cost < e2.cost; });
}