#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> iPair;

int main(void) {
    int n_v, n_e;
    cin >> n_v >> n_e;

    vector<int> visited_v(n_v, 0), weight_v(n_v, INT_MAX);
    vector<vector<iPair>> edges(n_v);
    int v1, v2, cost;
    for (int i = 0; i < n_e; i++) {
        cin >> v1 >> v2 >> cost;
        edges[v1 - 1].push_back(make_pair(v2 - 1, cost));
        edges[v2 - 1].push_back(make_pair(v1 - 1, cost));
    }

    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    weight_v[0] = 0;
    pq.push(make_pair(weight_v[0], 0));

    while (!pq.empty()) {
        v1 = pq.top().second;
        pq.pop();

        if (visited_v[v1])
            continue;
        visited_v[v1] = 1;

        for (iPair& e : edges[v1]) {
            v2 = e.first; cost = e.second;
            if (!visited_v[v2] && weight_v[v2] > cost) {
                weight_v[v2] = cost;
                pq.push(make_pair(weight_v[v2], v2));
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n_v; i++)
        res += weight_v[i];
    cout << res << endl;

    return 0;
}