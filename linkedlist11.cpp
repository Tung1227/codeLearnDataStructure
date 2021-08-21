#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *createNode(int data){
    Node *n = new Node();
    n->data = data;
    n->next = n;
    return n;
}
Node *addTail(Node *node,int data){
    Node *temp = node;
    while(temp->next!=node){
        temp = temp->next;
    }
    Node *add = createNode(data);
    add->next = node;
    temp->next = add;
    return node;
}
void printList(Node *node, int k){
    Node *temp = node;
    for(int i = 0; i < k;i++){
        temp = temp->next;
    }
    cout << temp->data << " ";
    Node *temp2 = temp->next;
    while(temp2 != temp){
        cout << temp2->data << " ";
        temp2 = temp2->next;
    }
}
int main(){
    int n, k, data;
    cin >> n;
    cin >> data;
    Node *node = createNode(data);
    Node* temp = node;
    for(int i = 1; i < n; i++){
        cin >> data;
        temp = addTail(temp,data);
    }
    cin >> k;
    printList(node,k);
    }
