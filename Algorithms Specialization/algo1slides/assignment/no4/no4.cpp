#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <random>
#include <algorithm>

using namespace std;

void createGraph(vector<vector<int>>& record, vector<vector<int>>& edges);
int getEdgeNumber(vector<int>& used);

class UnionFind {
private:
    vector<int> parent;
    int n_vertices;
public:
    UnionFind(int n) : n_vertices(n) {
        for (int i = 0; i < n; i++)
            parent.emplace_back(i);
    }
    
    int find(int i) {
        if (parent[i] != i)
            parent[i] = find(parent[i]);
        return parent[i];
    }
    
    void uni(int i, int j) {
        int pi = find(i), pj = find(j);
        
        if (pi != pj) 
            n_vertices--;
        
        parent[pi] = pj;
        return;
    }

    int get_nv(void) { return n_vertices; }
};

random_device rd;
default_random_engine generator(rd());
int getEdgeNumber(vector<int>& used);

int main(void) {
    int n = 200;
    int times = n * n * 10;
    vector<vector<int>> edges, record(n, vector<int>(n, 0));
    createGraph(record, edges);
    
    int m = edges.size();
    int res = m;

    while (times--) {
        vector<int> used_edge(m, 0);
        UnionFind uf(n);
        while (uf.get_nv() > 2) {
            int edgeNumber = getEdgeNumber(used_edge);
            int a = edges[edgeNumber][0], b = edges[edgeNumber][1];
            uf.uni(a, b);
            used_edge[edgeNumber] = 1;
        }

        int cur = 0;
        for (int i = 0; i < m; i++) {
            int a = edges[i][0], b = edges[i][1];
            if (uf.find(a) != uf.find(b))
                cur++;
        }
        res = min(res, cur);
        if (times % n == 0)
            cout << cur << ", " << res << endl;
    }

    return 0;
}

void createGraph(vector<vector<int>>& record, vector<vector<int>>& edges) {
    string line;
    stringstream ss;
    int a, b;

    ifstream ifs("kargerMinCut.txt");
    while (getline(ifs, line)) {
        ss.str(""); ss.clear(); ss << line;
        ss >> a;
        while (ss >> b) {
            if (!record[a - 1][b - 1]) {
                edges.push_back({a - 1, b - 1});
                record[a - 1][b - 1] = record[b - 1][a - 1] = 1;
            }
        }
    }
    
    return;
}

int getEdgeNumber(vector<int>& used) {
    int index;
    uniform_int_distribution<int> distribution(0, used.size() - 1);
    do {
        index = distribution(generator);
    } while (used[index]);
    return index;
}