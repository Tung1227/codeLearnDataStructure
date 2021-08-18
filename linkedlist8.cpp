#include<iostream>
using namespace std;

struct Node{
    int data;
    Node*next;
    Node *pre;
};

struct DouList{
    Node *head;
    Node *tail;
};

Node *createNode(int data){
    Node *node = new Node();
    node->data = data;
    node->next = NULL;
    node->pre = NULL;
    return node;
}
DouList *createList(int x){
    DouList *dou = new DouList();
    dou->head = new Node();
    dou->head->data = x;
    dou->head->next = NULL;
    dou->head->pre = NULL;
    dou->tail = dou->head;
    return dou;
}
void printList(Node *node){
    Node *temp = node;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}
DouList *addHead(DouList *dou, int data){
    Node *Head = createNode(data);
    Head->pre = NULL;
    Head->next = dou->head;
    dou->head->pre = Head;
    dou->head = Head;
    return dou;
}
DouList *addTail(DouList *dou, int data){
    Node *tail = createNode(data);
    tail->pre = dou->tail;
    dou->tail->next = tail;
    dou->tail = tail;
    return dou;
}
int main(){
    int n;
    cin >> n;
    DouList *dou = createList(1);
    for(int i = 2; i <= n; i++){
        addHead(dou,i);
        addTail(dou,i);
    }
    printList(dou->head);
}