#include <iostream>
#include <vector>

using namespace std;

class bPlusTree {
private:
    int maxChildrenNumber;
    Node* root;
public:
    bPlusTree(int n): maxChildrenNumber(n) {}
    Node* insert(Node*, int);
    void search(Node*, int);
    void print();

    Node* getRoot() { return root; }
};

class Node {
private:
    int currentChildrenNumber;
    vector<int> values;
    vector<Node*> children;
    Node* nextNode;
public:
    Node(int);
    void setValue(int);
    vector<int>& getValues() { return values; }
};

int main() {
    int childrenNumber, value;
    char mode;
    
    cin >> childrenNumber;
    bPlusTree BPtree = bPlusTree(childrenNumber);
    
    cin >> mode;
    while (mode != 'q') {
        if (mode == 'i') {
            cin >> value;
            BPtree.insert(BPtree.getRoot(), value);
        }
        else if (mode == 's') {
            cin >> value;
            BPtree.search(BPtree.getRoot(), value);
        }
        else if (mode == 'p') {
            BPtree.print();
        }
    }

    return 0;
}


Node* bPlusTree::insert(Node* node, int insertValue) {
    if (!root) {
        root = new Node(insertValue);
        return root;
    }
    vector<int>& curNodeValues = node->getValues();
    int n_nodeValues = curNodeValues.size();
    for (int i = 0; i < n_nodeValues - 1; i++) {
        if (i == 0 && insertValue < curNodeValues[i + 1]) {

        }
        else if (i != n_nodeValues - 2 && curNodeValues[i] < insertValue && insertValue < curNodeValues[i + 1]) {

        }
    }

    
}

Node::Node(int insertValue) {
    values.push_back(insertValue);
    children = vector<Node*>(2, nullptr);
    nextNode = nullptr;
}