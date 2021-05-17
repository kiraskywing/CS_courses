#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int value): val(value), left(nullptr), right(nullptr) {}
    ~Node() {}
};

class BST {
private:
    Node* root;
public:
    BST() { root = nullptr; }
    ~BST() { destruct(root); }
    
    Node* getRoot() { return root; }
    Node* insert(Node* cur, int value) {
        if (!root) {
            root = new Node(value);
            return nullptr;
        }
        
        if (!cur) {
            Node* newNode = new Node(value);
            return newNode;
        }

        if (value < cur->val) cur->left = insert(cur->left, value);
        else cur->right = insert(cur->right, value);

        return cur;
    }
    void print(Node* cur) {
        if (!cur) return;
        print(cur->left);
        print(cur->right);
        cout << cur->val << endl;
    }
    void destruct(Node* cur) {
        if (!cur) return;
        destruct(cur->left);
        destruct(cur->right);
        delete cur;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    Node* root = nullptr;
    int val;
    BST tree;

    while (cin >> val) tree.insert(tree.getRoot(), val);
    tree.print(tree.getRoot());
    
    return 0;
}
