#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
    int no, weight;
    Node *left, *right;
    Node(int w, int i = -1): no(i), weight(w), left(nullptr), right(nullptr) {}
};

void maxDepth(Node* root, int cur, int& res) {
    if (root->left)
        maxDepth(root->left, cur + 1, res);
    if (root->right)
        maxDepth(root->right, cur + 1, res);
    if (!root->left && !root->right)
        res = max(res, cur);
}
void minDepth(Node* root, int cur, int& res) {
    if (root->left)
        minDepth(root->left, cur + 1, res);
    if (root->right)
        minDepth(root->right, cur + 1, res);
    if (!root->left && !root->right)
        res = min(res, cur);
}

int main(void) {
    int n, weight;
    cin >> n;
    auto cmp = [](Node* a, Node* b){ return a->weight > b->weight; };
    priority_queue<Node*, vector<Node*>, decltype(cmp)> pq(cmp);
    for (int i = 0; i < n; i++) {
        cin >> weight;
        Node* cur = new Node(weight, i);
        pq.push(cur);
    }
    
    Node *leftChild, *rightChild, *root;
    while (pq.size() >= 2) {
        leftChild = pq.top(); pq.pop();
        rightChild = pq.top(); pq.pop();
        weight = leftChild->weight + rightChild->weight;
        root = new Node(weight);
        root->left = leftChild;
        root->right = rightChild;
        pq.push(root);
    }
    
    root = pq.top();
    int res = 0;
    maxDepth(root, 0, res);
    cout << "max length: " << res << endl;

    res = INT_MAX;
    minDepth(root, 0, res);
    cout << "min depth: " << res << endl;

    return 0;
}