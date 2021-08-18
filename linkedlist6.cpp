
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
 
int main(){
    int n,data,k;
    cin >> n;
    cin >> data;
    Node *node = createNode(data);
    Node *temp = node;
    for(int i = 0; i < n-1; i++){
        cin >> data;
        temp = addNode(temp,data);
    }
    cin >> k;
    temp = node;
    for(int i = 0; i < k; i++){
        temp = temp->next;
    }
    Node *node2 = createNode(temp->data);
    temp = node;
    Node *temp2 = node2;
    while(temp != NULL){
        if(temp->data <= node2->data){
            temp2 = addNode(temp2,temp->data);
        }
        temp = temp->next;
    }
    printList(node2->next);
}