#include <iostream>

using namespace std;

struct Node {
    bool isLeaf;
    int *keys, nodeSize;
    Node *parent, *next;
    Node **children;
    
    Node(int, int);
    ~Node() { delete [] keys; }
};

class bPlusTree {
private:
    int maxChildrenNumber, maxKeyNumber;
    Node* root;
public:
    bPlusTree(int n): maxChildrenNumber(n), maxKeyNumber(n - 1), root(nullptr) {}
    ~bPlusTree() { destruct(root); }
    void insert(int);
    void insertInternal(Node*, Node*, int);

    void search(int);
    void print(Node*, int);
    Node* getRoot() { return root; }
    void destruct(Node*);
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
            BPtree.insert(value);
        }
        else if (mode == 's') {
            cin >> value;
            BPtree.search(value);
            cout << endl;
        }
        else if (mode == 'p') {
            BPtree.print(BPtree.getRoot(), 0);
            cout << endl;
        }
        cin >> mode;
    }

    return 0;
}

Node::Node(int maxKeyNumber, int maxChildrenNumber) {
    keys = new int[maxKeyNumber];
    parent = next = nullptr;
    children = new Node*[maxChildrenNumber];
    for (int i = 0; i < maxChildrenNumber; i++) children[i] = nullptr;
    nodeSize = 0;
} 

void bPlusTree::insert(int keyToInsert) {
    if (!root) {
        root = new Node(maxKeyNumber, maxChildrenNumber);
        root->isLeaf = true;
        root->keys[0] = keyToInsert;
        root->nodeSize++;
        return;
    }
    
    Node *cur = root;
    while (!cur->isLeaf) {
        int i = 0;
        while (i < cur->nodeSize && keyToInsert > cur->keys[i])
            i++;
        cur = cur->children[i];
    }

    if (cur->nodeSize < maxKeyNumber) {
        int left = 0;
        while (left < cur->nodeSize && keyToInsert > cur->keys[left])
            left++;
        
        for (int right = cur->nodeSize; right > left; right--) 
            cur->keys[right] = cur->keys[right - 1];
        
        cur->keys[left] = keyToInsert;
        cur->nodeSize++;
    } 
    else {
        int totalSize = maxKeyNumber + 1;
        int tempKeys[totalSize];
        int insertPos = 0;

        while (insertPos < maxKeyNumber && keyToInsert > cur->keys[insertPos])
            insertPos++;
        
        for (int i = 0, j = 0; i < totalSize; i++) 
            tempKeys[i] = (i == insertPos ? keyToInsert : cur->keys[j++]);
        
        Node* newLeaf = new Node(maxKeyNumber, maxChildrenNumber);
        newLeaf->isLeaf = true;
        
        cur->nodeSize = totalSize / 2;
        newLeaf->nodeSize = totalSize - totalSize / 2;
        for (int i = 0, j = 0, k = 0; i < totalSize; i++) {
            if (i < totalSize / 2) 
                cur->keys[j++] = tempKeys[i];
            else 
                newLeaf->keys[k++] = tempKeys[i];
        }

        newLeaf->next = cur->next;
        cur->next = newLeaf;

        if (cur == root) {
            root = new Node(maxKeyNumber, maxChildrenNumber);
            root->keys[0] = newLeaf->keys[0];
            root->children[0] = cur;
            root->children[1] = newLeaf;
            cur->parent = root;
            newLeaf->parent = root;
            root->isLeaf = false;
            root->nodeSize++;
        }
        else {
            newLeaf->parent = cur->parent;
            insertInternal(cur->parent, newLeaf, newLeaf->keys[0]);
        }
    }
}
void bPlusTree::insertInternal(Node* cur, Node* child, int keyToInsert) {
    if (cur->nodeSize < maxKeyNumber) {
        int left = 0;
        while (left < cur->nodeSize && keyToInsert > cur->keys[left])
            left++;
        
        for (int right = cur->nodeSize; right > left; right--) {
            cur->keys[right] = cur->keys[right - 1];
            cur->children[right + 1] = cur->children[right];
        }
        cur->keys[left] = keyToInsert;
        cur->nodeSize++;
        cur->children[left + 1] = child;
    }
    else {
        int tempKeys[maxKeyNumber + 1];
        Node* tempChildren[maxChildrenNumber + 1];
        tempChildren[0] = cur->children[0];

        int insertPos = 0;
        while (insertPos < maxKeyNumber && keyToInsert > cur->keys[insertPos])
            insertPos++;
        
        for (int i = 0, j = 0; i < maxKeyNumber + 1; i++) {
            if (i == insertPos) {
                tempKeys[i] = keyToInsert;
                tempChildren[i + 1] = child;
            }
            else {
                tempKeys[i] = cur->keys[j];
                tempChildren[i + 1] = cur->children[j + 1];
                j++;
            }
        }

        Node* newInternal = new Node(maxKeyNumber, maxChildrenNumber);
        newInternal->isLeaf = false;
        cur->nodeSize = (maxKeyNumber + 1) / 2;
        newInternal->nodeSize = maxKeyNumber - (maxKeyNumber + 1) / 2;
        
        newInternal->children[0] = tempChildren[cur->nodeSize + 1];
        newInternal->children[0]->parent = newInternal;
        for (int i = 0, j = cur->nodeSize + 1; i < newInternal->nodeSize; i++, j++) {
            newInternal->keys[i] = tempKeys[j];
            newInternal->children[i + 1] = tempChildren[j + 1];
            newInternal->children[i + 1]->parent = newInternal;
        }

        if (cur == root) {
            root = new Node(maxKeyNumber, maxChildrenNumber);
            root->keys[0] = tempKeys[cur->nodeSize];
            root->children[0] = cur;
            root->children[1] = newInternal;
            cur->parent = root;
            newInternal->parent = root;
            root->isLeaf = false;
            root->nodeSize++;
        }
        else {
            newInternal->parent = cur->parent;
            insertInternal(cur->parent, newInternal, cur->keys[cur->nodeSize]);
        }
    }
}
void bPlusTree::print(Node* cur, int level) {
    string tab = string(level * 2, ' ');
    cout << tab << '(';
    if (cur) {
        for (int i = 0; i < cur->nodeSize; i++)
            cout << cur->keys[i] << (i < cur->nodeSize - 1 ? " " : "");
    }
    cout << ')' << endl;

    if (cur) {
        for (int i = 0; i < cur->nodeSize + 1; i++) 
            if (cur->children[i]) print(cur->children[i], level + 1);
    }
}
void bPlusTree::search(int target) {
    bool found = false;
    Node* cur = root;
    
    if (!cur) cout << "()" << endl;

    while (cur) {
        cout << '(';
        for (int i = 0; i < cur->nodeSize; i++) {
            if (cur->isLeaf && cur->keys[i] == target) found = true;
            cout << cur->keys[i] << (i < cur->nodeSize - 1 ? " " : "");
        }
        cout << ')' << endl;
        if (found) break;
        
        int childPos = 0;
        while (childPos < cur->nodeSize && cur->keys[childPos] <= target)
            childPos++;
        cur = cur->children[childPos];
    }

    cout << (found ? "Found" : "QAQ") << endl;
}
void bPlusTree::destruct(Node* cur) {
    if (!cur) return;
    
    for (int i = 0; i < cur->nodeSize + 1; i++) 
        destruct(cur->children[i]);
    delete cur;
}