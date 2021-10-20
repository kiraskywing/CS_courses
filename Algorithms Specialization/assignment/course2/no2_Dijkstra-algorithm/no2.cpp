#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> iPair;

void createGraph(vector<int>& heap, vector<int>& position, vector<int>& scores, unordered_map<int, unordered_map<int, int>>& edges);
void heapifyToptoBottom(vector<int>& heap, vector<int>& position, vector<int>& scores, int i, int size);
void heapifyBottomtoTop(vector<int>& heap, vector<int>& position, vector<int>& scores, int size);
void heapInsert(vector<int>& heap, vector<int>& position, vector<int>& scores, int u, int& size);
void heapDelete(vector<int>& heap, vector<int>& position, vector<int>& scores, int i, int& size);
int heappop(vector<int>& heap, vector<int>& position, vector<int>& scores, int& size);
void printPath(vector<int>& path, int end);

int main(void) {
    int n = 200;
    vector<int> heap(n + 1, 0), position(n + 1, 0), scores(n + 1, 1000000), path(n + 1, 1);
    unordered_map<int, unordered_map<int, int>> edges;
    createGraph(heap, position, scores, edges);
    vector<int> scores2 = scores, path2 = path;

    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    pq.push(make_pair(scores[1], 1));

    int u, v, cost;
    while (!pq.empty()) {
        u = pq.top().second;
        pq.pop();

        for (auto& edge : edges[u]) {
            v = edge.first; cost = edge.second;
            if (scores[u] + cost < scores[v]) {
                scores[v] = scores[u] + cost;
                path[v] = u;
                pq.push(make_pair(scores[v], v));
            }
        }
    }

    // int size = 0;
    // for (int i = 1; i <= 200; i++)
    //     heapInsert(heap, position, scores2, i, size);
    // while (size) {
    //     u = heappop(heap, position, scores2, size);
    //     for (auto& edge : edges[u]) {
    //         v = edge.first; cost = edge.second;
    //         if (scores2[u] + cost < scores2[v]) {
    //             heapDelete(heap, position, scores2, position[v], size);
    //             scores2[v] = scores2[u] + cost;
    //             path2[v] = u;
    //             heapInsert(heap, position, scores2, v, size);
    //         }
    //     }
    // }
    
    cout << scores[7] << ',' << scores[37] << ',' << scores[59] << ',' << scores[82] << ',' << scores[99] << ','
         << scores[115] << ',' << scores[133] << ',' << scores[165] << ',' << scores[188] << ',' << scores[197] << endl;
    printPath(path, 7); printPath(path, 73); printPath(path, 59); printPath(path, 82); printPath(path, 99);
    printPath(path, 115); printPath(path, 133); printPath(path, 165); printPath(path, 188); printPath(path, 197);

    // cout << endl;

    // cout << scores2[7] << ',' << scores2[37] << ',' << scores2[59] << ',' << scores2[82] << ',' << scores2[99] << ','
    //      << scores2[115] << ',' << scores2[133] << ',' << scores2[165] << ',' << scores2[188] << ',' << scores2[197] << endl;
    // printPath(path2, 7); printPath(path2, 73); printPath(path2, 59); printPath(path2, 82); printPath(path2, 99);
    // printPath(path2, 115); printPath(path2, 133); printPath(path2, 165); printPath(path2, 188); printPath(path2, 197);
    
    return 0;
}

void createGraph(vector<int>& heap, vector<int>& position, vector<int>& scores, unordered_map<int, unordered_map<int, int>>& edges) {
    scores[1] = 0;
    for (int i = 1; i < heap.size(); i++) {
        position[i] = i;
        // heap[i] = position[i] = i;
    }
    
    ifstream ifs("dijkstraData.txt");
    // ifstream ifs("test.txt");
    string line, temp;
    stringstream ss;
    int u, v, l;
    size_t pos;
    while (getline(ifs, line)) {
        ss.str(""); ss.clear(); ss << line;
        ss >> u;
        // cout << u << ' ';
        while (ss >> temp) {
            pos = temp.find(",");
            v = stoi(temp.substr(0, pos));
            l = stoi(temp.substr(pos + 1));
            edges[u][v] = l;
            // cout << '(' << v << ',' << l << ") ";
        }
        // cout << endl;
    }
}
void heapifyToptoBottom(vector<int>& heap, vector<int>& position, vector<int>& scores, int i, int size) {
    int parent = i, child, u, v;
    while (true) {
        child = parent * 2;
        if (child > size) 
            break;
        if (child + 1 <= size && scores[heap[child + 1]] < scores[heap[child + 1]]) 
            child = child + 1;
        u = heap[parent];
        v = heap[child];
        if (scores[u] > scores[v]) {
            swap(position[u], position[v]);
            swap(heap[parent], heap[child]);
            parent = child;
        }
        else 
            break;
    }
}
void heapifyBottomtoTop(vector<int>& heap, vector<int>& position, vector<int>& scores, int size) {
    int child = size, parent, u, v;
    while (true) {
        parent = child / 2;
        if (parent == 0)
            break;
        u = heap[parent];
        v = heap[child];
        if (scores[u] > scores[v]) {
            swap(position[u], position[v]);
            swap(heap[parent], heap[child]);
            child = parent;
        }
        else 
            break;
    }
}
void heapInsert(vector<int>& heap, vector<int>& position, vector<int>& scores, int u, int& size) {
    heap[++size] = u;
    position[u] = size;
    heapifyBottomtoTop(heap, position, scores, size);
}
void heapDelete(vector<int>& heap, vector<int>& position, vector<int>& scores, int i, int& size) {
    int u = heap[i], v = heap[size];
    swap(heap[i], heap[size]);
    swap(position[u], position[v]);
    size--;
    position[u] = 0;
    heapifyToptoBottom(heap, position, scores, i, size);
}
int heappop(vector<int>& heap, vector<int>& position, vector<int>& scores, int& size) {
    int u = heap[1];
    heapDelete(heap, position, scores, 1, size);
    return u;
}
void printPath(vector<int>& path, int end) {
    cout << end;
    while (path[end] != end) {
        cout << "->" << path[end];
        end = path[end];
    }
    cout << endl;
}