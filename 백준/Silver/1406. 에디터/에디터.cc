#include <iostream>
#include <string>
using namespace std;

struct Node {
    char c;
    Node* next;
    Node* before;
};

void linkNode(Node* &node, char c){
    Node* newNode = new Node;
    newNode->c = c;
    node->next = newNode;
    newNode->before = node; 
}

void printNode(Node* node){
    while(node->before) node = node->before;
    while(node->next){
        cout << node->c;
        node = node->next;
    } 
    cout << endl;
}

int main(){
    int n;
    string str;
    cin >> str >> n;

    Node* head = new Node;
    Node* csr = head;

    for(auto c : str){
        linkNode(csr, c);
        csr = csr->next;
    }
    linkNode(csr, ' ');
    csr = csr->next;

    head = head->next;
    head->before = nullptr;

    for(int i=0;i<n;i++){
        // printNode(csr);
        // cout << "csr -> " << csr->c <<endl;

        char pg;
        cin >> pg;

        if(pg == 'L'){
            if(!csr->before) continue;
            csr = csr->before;

        } else if (pg == 'D'){
            if(!csr->next) continue;
            csr = csr->next;

        } else if (pg == 'B'){
            if(!csr->before) continue;
            if(!csr->before->before){
                csr->before->next = nullptr;
                csr->before = nullptr;
                continue;
            }
            csr->before = csr->before->before;
            csr->before->next = csr;
                
            
        } else if (pg == 'P'){
            char c;
            cin >> c;

            Node* newNode = new Node;
            newNode->c = c;

            if(!csr->before){
                newNode->next = csr;
                csr->before = newNode;

            }else{
                newNode->before = csr->before;
                newNode->next = csr;
                csr->before->next = newNode;
                csr->before = newNode;
            }
            
        } else break;
    }

    printNode(csr);

}
