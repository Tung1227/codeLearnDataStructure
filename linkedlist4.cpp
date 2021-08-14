
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
    if(k == 0) cout << node->data;
    else{
        for(int i = 0; i < k; i++){
            node = node->next;
        }
        cout << node->data;
    }
}