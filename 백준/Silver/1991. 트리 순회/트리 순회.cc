#include <bits/stdc++.h>
using namespace std;

struct Node { 
    char left, right; 
    void setChildren(char l, char r) { left=l; right=r; };
};
char parent, lchild, rchild;
vector<Node> tree(27, Node{});
int N;

void pre_order(char root);
void in_order(char root);
void post_order(char root);

int main() {
    cin >> N;
    while(N-- && cin >> parent >> lchild >> rchild)
        tree[parent-'A'].setChildren(lchild, rchild);

    pre_order('A');
    cout << endl;

    in_order('A');
    cout << endl;

    post_order('A');
    cout << endl;
}

void pre_order(char root) {
    Node &node = tree[root-'A'];
    cout << root;
    if(node.left!='.') pre_order(node.left);
    if(node.right!='.') pre_order(node.right);
}

void in_order(char root) {
    Node &node = tree[root-'A'];
    if(node.left!='.') in_order(node.left);
    cout << root;
    if(node.right!='.') in_order(node.right);
}

void post_order(char root) {
    Node &node = tree[root-'A'];
    if(node.left!='.') post_order(node.left);
    if(node.right!='.') post_order(node.right);
    cout << root;
}