#include <iostream>

using namespace std;

struct Node {
    bool isLeaf;
    int *keys, nodeSize;
    Node *parent, *next;
    Node **children;
    
    Node(int, int);
    ~Node() { delete [] keys; delete [] children; }
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
    void remove(int);
    void removeInternal(Node*, Node*, int);

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
        else if (mode == 'd') {
            cin >> value;
            BPtree.remove(value);
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

void bPlusTree::remove(int target) {
    if (!root) {
        cout << "Empty tree!" << endl;
        return;
    }

    Node* cur = root;
    int j;
    while (!cur->isLeaf) {
        j = 0;
        while (j < cur->nodeSize && target >= cur->keys[j])
            j++;
        cur = cur->children[j];
    }
    int leftSibling = j - 1, rightSibling = j + 1;
    
    bool found = false;
    int posToBeRemoved;
    for (posToBeRemoved = 0; posToBeRemoved < cur->nodeSize; posToBeRemoved++) {
        if (cur->keys[posToBeRemoved] == target) {
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Not found!" << endl;
        return;
    }

    for (int i = posToBeRemoved; i < cur->nodeSize - 1; i++)
        cur->keys[i] = cur->keys[i + 1];
    cur->nodeSize--;

    if (cur == root && cur->nodeSize == 0) {
        cout << "Tree died" << endl;
        delete cur;
        root = nullptr;
        return;
    }

    if (cur->nodeSize >= (maxKeyNumber + 1) / 2)
        return;
    
    if (leftSibling >= 0) {
        Node* leftNode = cur->parent->children[leftSibling];
        if (leftNode->nodeSize > (maxKeyNumber + 1) / 2) {
            for (int i = cur->nodeSize; i > 0; i--)
                cur->keys[i] = cur->keys[i - 1];
            cur->nodeSize++;
            cur->keys[0] = leftNode->keys[leftNode->nodeSize - 1];
            leftNode->nodeSize--;
            cur->parent->keys[leftSibling] = cur->keys[0];
            return;
        }
    }
    if (rightSibling <= cur->parent->nodeSize) {
        Node* rightNode = cur->parent->children[rightSibling];
        if (rightNode->nodeSize > (maxKeyNumber + 1) / 2) {
            cur->nodeSize++;
            cur->keys[cur->nodeSize - 1] = rightNode->keys[0];
            rightNode->nodeSize--;
            for (int i = 0; i < rightNode->nodeSize; i++)
                rightNode->keys[i] = rightNode->keys[i + 1];
            cur->parent->keys[rightSibling - 1] = rightNode->keys[0];
            return;
        }
    }

    if (leftSibling >= 0) {
        Node* leftNode = cur->parent->children[leftSibling];
        for (int i = leftNode->nodeSize, j = 0; j < cur->nodeSize; i++, j++)
            leftNode->keys[i] = cur->keys[j];
        leftNode->nodeSize += cur->nodeSize;
        leftNode->next = cur->next;
        cout << "Merging two leaf nodes" << endl;
        removeInternal(cur->parent, cur, cur->parent->keys[leftSibling]);
        delete cur;
    } else if (rightSibling <= cur->parent->nodeSize) {
        Node* rightNode = cur->parent->children[rightSibling];
        for (int i = cur->nodeSize, j = 0; j < rightNode->nodeSize; i++, j++)
            cur->keys[i] = rightNode->keys[j];
        cur->nodeSize += rightNode->nodeSize;
        cur->next = rightNode->next;
        cout << "Merging two leaf nodes" << endl;
        removeInternal(cur->parent, rightNode, cur->parent->keys[rightSibling - 1]);
        delete rightNode;
    }
}

void bPlusTree::removeInternal(Node* cur, Node* child, int target) {
    if (cur == root && cur->nodeSize == 1) {
        root = (cur->children[1] == child ? cur->children[0] : cur->children[1]);
        delete cur;
        cout << "root node changed" << endl;
        return;
    }

    int pos;
    for (pos = 0; pos < cur->nodeSize; pos++) {
        if (cur->keys[pos] == target) 
            break;
    }
    for (int i = pos; i < cur->nodeSize - 1; i++)
        cur->keys[i] = cur->keys[i + 1];
    for (pos = 0; pos < cur->nodeSize + 1; pos++) {
        if (cur->children[pos] == child) 
            break;
    }
    for (int i = pos; i < cur->nodeSize; i++)
        cur->children[i] = cur->children[i + 1];
    cur->children[cur->nodeSize] = nullptr;
    cur->nodeSize--;
    if (cur->nodeSize >= (maxKeyNumber + 1) / 2 - 1 || cur == root)
        return;

    pos = 0;
    while (pos < cur->parent->nodeSize + 1 && cur->parent->children[pos] != cur)
        pos++;
    int leftSibling = pos - 1, rightSibling = pos + 1;
    
    if (leftSibling >= 0) {
        Node* leftNode = cur->parent->children[leftSibling];
        if (leftNode->nodeSize >= (maxKeyNumber + 1) / 2) {
            for (int i = cur->nodeSize; i > 0; i--) 
                cur->keys[i] = cur->keys[i - 1];
            cur->keys[0] = cur->parent->keys[leftSibling];
            cur->parent->keys[leftSibling] = leftNode->keys[leftNode->nodeSize - 1];
            for (int i = cur->nodeSize + 1; i > 0; i--)
                cur->children[i] = cur->children[i - 1];
            cur->children[0] = leftNode->children[leftNode->nodeSize];
            cur->nodeSize++;
            leftNode->nodeSize--;
            return;
        }
    }
    if (rightSibling <= cur->parent->nodeSize) {
        Node* rightNode = cur->parent->children[rightSibling];
        if (rightNode->nodeSize >= (maxKeyNumber + 1) / 2) {
            cur->keys[cur->nodeSize] = cur->parent->keys[pos];
            cur->parent->keys[pos] = rightNode->keys[0];
            for (int i = 0; i < rightNode->nodeSize - 1; i++)
                rightNode->keys[i] = rightNode->keys[i + 1];
            cur->children[cur->nodeSize + 1] = rightNode->children[0];
            for (int i = 0; i < rightNode->nodeSize; i++)
                rightNode->children[i] = rightNode->children[i + 1];
            rightNode->children[rightNode->nodeSize] = nullptr;
            cur->nodeSize++;
            rightNode->nodeSize--;
            return;
        }
    }

    if (leftSibling >= 0) {
        Node* leftNode = cur->parent->children[leftSibling];
        leftNode->keys[leftNode->nodeSize] = cur->parent->keys[leftSibling];
        for (int i = leftNode->nodeSize + 1, j = 0; j < cur->nodeSize; i++, j++)
            leftNode->keys[i] = cur->keys[j];
        for (int i = leftNode->nodeSize + 1, j = 0; j < cur->nodeSize + 1; i++, j++)
            leftNode->children[i] = cur->children[j];
        leftNode->nodeSize += cur->nodeSize + 1;
        removeInternal(cur->parent, cur, cur->parent->keys[leftSibling]);
        delete cur;
    } else if (rightSibling <= cur->parent->nodeSize) {
        Node* rightNode = cur->parent->children[rightSibling];
        cur->keys[cur->nodeSize] = cur->parent->keys[rightSibling - 1];
        for (int i = cur->nodeSize + 1, j = 0; j < rightNode->nodeSize; i++, j++)
            cur->keys[i] = rightNode->keys[j];
        for (int i = cur->nodeSize + 1, j = 0; j < rightNode->nodeSize + 1; i++, j++)
            cur->children[i] = rightNode->children[j];
        cur->nodeSize += rightNode->nodeSize + 1;
        removeInternal(cur->parent, cur, cur->parent->keys[rightSibling - 1]);
        delete rightNode;
    }
}