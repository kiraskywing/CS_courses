#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct Node {
    int value, height;
    Node *left, *right;
    Node(int value) { 
        this->value = value; 
        this->left = this->right = nullptr;
    }
};

class AVL {
public:
    Node* root;
    AVL() { root = nullptr; }
    
    int getHeight(Node* cur) {
        return (cur ? cur->height : 0);
    }
    
    Node* rightRotate(Node* cur) {
        Node* newRight = cur;
        Node* newRoot = cur->left;
        Node* newRoot_r = newRoot->right;

        newRoot->right = newRight;
        newRight->left = newRoot_r;
        
        newRight->height = max(getHeight(newRight->left), getHeight(newRight->right)) + 1;
        newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;

        return newRoot;
    }

    Node* leftRotate(Node* cur) {
        Node* newLeft = cur;
        Node* newRoot = cur->right;
        Node* newRoot_l = newRoot->left;

        newRoot->left = newLeft;
        newLeft->right = newRoot_l;

        newLeft->height = max(getHeight(newLeft->left), getHeight(newLeft->right)) + 1;
        newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;

        return newRoot;
    }
    
    int getBalanceFactor(Node *cur) {
        return getHeight(cur->left) - getHeight(cur->right);
    }

    Node* insertNode(Node* cur, int value) {
        if (!cur) {
            cur = new Node(value);
            cur->height = 1;
            return cur;
        }

        if (value < cur->value) 
            cur->left = insertNode(cur->left, value);
        else if (value > cur->value) 
            cur->right = insertNode(cur->right, value);
        else 
            return cur;
        
        cur->height = max(getHeight(cur->left), getHeight(cur->right)) + 1;

        int balanceFactor = getBalanceFactor(cur);

        // Left-Left condition
        if (balanceFactor > 1 && value < cur->left->value) 
            return rightRotate(cur);
        // Right-Right condition
        if (balanceFactor < -1 && value > cur->right->value)
            return leftRotate(cur);
        // Left-Right condition
        if (balanceFactor > 1 && value > cur->left->value) {
            cur->left = leftRotate(cur->left);
            return rightRotate(cur);
        }
        // Right-Left condition
        if (balanceFactor < -1 && value < cur->right->value) {
            cur->right = rightRotate(cur->right);
            return leftRotate(cur);
        }

        return cur;
    }

    void preOrder(Node* cur, int level) {
        if (!root)
            cout << "()" << endl;
        
        if (!cur) return;

        string tab(level * 2, ' ');
        cout << tab << '(' << cur->value << ')' << endl;
        preOrder(cur->left, level + 1);
        preOrder(cur->right, level + 1);
    }

    Node* minValueNode(Node* cur) {
        while (cur->left)
            cur = cur->left;
        return cur;
    }

    Node* deleteNode(Node* cur, int target) {
        if (!cur)
            return nullptr;

        if (target < cur->value) 
            cur->left = deleteNode(cur->left, target);
        else if (target > cur->value)
            cur->right = deleteNode(cur->right, target);
        else {
            if (!cur->left || !cur->right) {
                Node* toBeDeleted = cur->left ? cur->left : cur->right;
                
                if (!toBeDeleted) {
                    toBeDeleted = cur;
                    cur = nullptr;
                }
                else
                    *cur = *toBeDeleted;
                
                delete toBeDeleted;
                toBeDeleted = nullptr;
            }
            else {
                Node* temp = minValueNode(cur->right);
                cur->value = temp->value;
                cur->right = deleteNode(cur->right, temp->value);
            }
        }

        if (!cur)
            return nullptr;
        
        cur->height = max(getHeight(cur->left), getHeight(cur->right)) + 1;

        int balanceFactor = getBalanceFactor(cur);

        // Left-Left condition
        if (balanceFactor > 1 && getBalanceFactor(cur->left) >= 0)
            return rightRotate(cur);
        // Left-Right condition
        if (balanceFactor > 1 && getBalanceFactor(cur->left) < 0) {
            cur->left = leftRotate(cur->left);
            return rightRotate(cur);
        }
        // Right-Right condition
        if (balanceFactor < -1 && getBalanceFactor(cur->right) <= 0)
            return leftRotate(cur);
        // Left-Right condition
        if (balanceFactor < -1 && getBalanceFactor(cur->right) > 0) {
            cur->right = rightRotate(cur->right);
            return leftRotate(cur);
        }

        return cur;
    }
};

int main() {
    AVL tree;
    int mode, value;

    do {
        cout << endl << "1. Print AVL tree"
             << endl << "2. Insert node"
             << endl << "3. Delete node"
             << endl << "4. exit" 
             << endl << "Choice: ";
        cin >> mode;

        switch (mode) {
            case 1:
                cout << endl;
                tree.preOrder(tree.root, 0);
                break;
            case 2:
                cout << "Insert value: ";
                cin >> value;
                tree.root = tree.insertNode(tree.root, value);
                break;
            case 3:
                cout << "Delete value: ";
                cin >> value;
                tree.root = tree.deleteNode(tree.root, value);
                break;
            case 4:
                break;
        }
    } while (mode != 4);
    
    return 0;
}