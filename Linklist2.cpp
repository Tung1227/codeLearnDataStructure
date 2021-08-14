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
Node *insertHead(Node* node,  int x){
    Node *Head = new Node;
    Head->data = x;
    Head->next = node;
    return Head; 
}

Node *insertTail(Node *node, int x){
    Node *Tail = new Node;
    Tail->data = x;
    Tail->next = NULL;
    Node *temp = node;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = Tail;
    return node;
}
Node *insertNode(Node *node, int x, int k){
    Node *inNode = createNode(x);
    Node *temp = node;
    for(int i = 0; i < k-1; i++)
    {
        temp = temp->next;
    }
    inNode->next = temp->next;
    temp->next = inNode;
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
    cin >> x; 
    if(k == 0) node = insertHead(node , x);
    else if(k == n) node = insertTail(node,x);
    else node = insertNode(node,x,k);
    printList(node);

}