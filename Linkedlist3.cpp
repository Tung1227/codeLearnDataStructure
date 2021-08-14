#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *createNode(int data){
    Node *node = new Node;
    node->data = data;
    node->next = NULL;
    return node;
}

Node *addNode(Node *node, int data){
    Node *temp = createNode(data);
    node->next = temp;
    return temp;
}

void printList(Node *node){
    Node *temp = node;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}
Node *deleteHead(Node* node){
    Node *Head = node;
    Head = Head->next;
    delete(node);
    return Head; 
}

Node *deleteTail(Node *node){
    Node *temp = node;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node *Tail = temp->next;
    temp->next = NULL;
    delete(Tail);
    return node;
}
Node *deleteNode(Node *node, int k){
    Node *temp = node;
    for(int i = 0; i < k-1; i++)
    {
        temp = temp->next;
    }
    Node *preNode = temp->next;
    temp->next = preNode->next;
    delete(preNode);
    return node; 
}
 
int main(){
    int n,data,x,k;
    cin >> n;
    cin >> data;
    Node *node = createNode(data);
    Node *temp = node;
    for(int i = 0; i < n-1; i++){
        cin >> data;
        temp = addNode(temp,data);
    }
    cin >> k;
    if(k == 0) node = deleteHead(node );
    else if(k == n) node = deleteTail(node);
    else node = deleteNode(node,k);
    printList(node);

}