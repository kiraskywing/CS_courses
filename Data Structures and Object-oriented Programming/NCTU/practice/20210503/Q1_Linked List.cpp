#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
};

class LinkedList {
public:
    Node *root;
    int len;
    LinkedList() : root(nullptr), len(0) {}
    void push(int);
    void insert(int, int);
    int find(int);
    void remove(int);
    void print();
};

void LinkedList::push(int x){
	Node* node = new Node(x);
    if (len == 0) 
        root = node;
    else {
        Node* cur = root;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = node;
    }
    len++;
}

void LinkedList::insert(int pos, int x){
    if (pos < 0 || pos > len) {
        cout << "insert fail" << endl;
        return;
    }

    Node* i_node = new Node(x);
    if (len == 0) {
        root = i_node;
    }
    else {
        Node* dummy = new Node(-1);
        dummy->next = root;
        
        Node* cur = dummy;
        for(int i = 0; i < pos; i++)
            cur = cur->next;
        
        i_node->next = cur->next;
        cur->next = i_node;

        if (pos == 0)
            root = i_node;
        dummy->next = nullptr;
        delete dummy;
    }
    len++;
}

int LinkedList::find(int x){
	if (len == 0)
        return -1;
    
    int pos = 0;
    Node* cur = root;
    while (cur && cur->val != x) {
        pos++;
        cur = cur->next;
    }
    if (!cur) return -1;
    return (cur->val == x ? pos : -1);
}

void LinkedList::remove(int pos){
	if (len == 0 || pos >= len || pos < 0) {
        cout << "remove fail" << endl;
        return;
    }

    Node* dummy = new Node(-1);
    dummy->next = root;
    Node* cur = dummy;
    for (int i = 0; i < pos; i++) {
        cur = cur->next;
    }
    Node* target = cur->next;
    cur->next = target->next;

    target->next = nullptr;
    delete target;
    
    if (pos == 0)
        root = dummy->next;
    
    dummy->next = nullptr;
    delete dummy;
    len--;
    
    if (len == 0)
        root = nullptr;
}

void LinkedList::print(){
    if(root == nullptr)
        return;

    Node *cur = root;
    while(cur->next != nullptr){
        cout << cur->val << ", ";
        cur = cur->next;
    }
    cout << cur->val << endl;
}

int main(){
    LinkedList mylist;
    
    int n, a, b;
    cin >> n;
    char c;
    for(int i = 0; i < n; i++){
        cin >> c;
        if(c == 'p'){
            cin >> a;
            mylist.push(a);
        }else if(c == 'i'){
            cin >> a >> b;
            mylist.insert(a, b);
        }else if(c == 'r'){
            cin >> a;
            mylist.remove(a);
        }else if(c == 'f'){
            cin >> a;
            cout << mylist.find(a) << endl;
        }else if(c == '?'){
            mylist.print();
        }
    }
    return 0;
}