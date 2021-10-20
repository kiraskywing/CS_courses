#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

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

int bits2int(int n_bits);
void getMasks(vector<int>& masks, int n_bits);

int main(void) {
    int n_v, n_bits;
    cin >> n_v >> n_bits;

    vector<int> node2val(n_v, 0);
    unordered_map<int, vector<int>> val2node;
    UnionFind uf(n_v);

    for (int i = 0; i < n_v; i++) {
        int num = bits2int(n_bits);
        node2val[i] = num;
        val2node[num].push_back(i);
        int n_num = val2node[num].size();
        if (n_num > 1)
            uf.uni(val2node[num][n_num - 2], val2node[num][n_num - 1]);
    }

    vector<int> bitMasks;
    getMasks(bitMasks, n_bits);
    for (int i : bitMasks) {
        for (auto& temp : val2node) {
            int key1 = temp.first;
            int key2 = key1 ^ i;
            if (val2node.count(key2))
                uf.uni(val2node[key1][0], val2node[key2][0]);
        }
    }
    cout << uf.get_nv() << endl;

    return 0;
}

int bits2int(int n_bits) {
    int res = 0, c;
    for (int i = 0; i < n_bits; i++) {
        cin >> c;
        if (c) res |= 1 << (n_bits - 1 - i);
    }
    return res;
}
void getMasks(vector<int>& masks, int n_bits) {
    for (int i = 0; i < n_bits; i++) {
        masks.push_back(1 << i);
        for (int j = 0; j < i; j++)
            masks.push_back((1 << i) + (1 << j));
    }
}