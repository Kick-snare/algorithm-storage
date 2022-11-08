#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node *left, *right;
    Node(int val, Node* l=nullptr, Node* r=nullptr) : value(val), left(l), right(r) {}
};

void addChild(Node* root, int num) {
    Node* node = root;
    while(true)
        if(num > node->value)
            if(node->right) node = node->right;
            else {
                node->right = new Node(num);
                return;
            }
        else
            if(node->left) node = node->left;
            else {
                node->left = new Node(num);
                return;
            }
}

void post(Node *node) {
    if(node->left) post(node->left);
    if(node->right) post(node->right);
    cout << node->value << endl;
}

int main() {
    int num;
    cin >> num;
    Node* root = new Node(num);
    while(cin >> num)
        addChild(root, num);

    post(root);
}

