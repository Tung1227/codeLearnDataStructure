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
DouList *addNode(DouList *dou, int k, int data){
    Node *temp = dou->head;
    Node *add = createNode(data);
    for(int i = 0; i < k-1; i++){
        temp = temp->next;
    }
    add->next = temp->next;
    add->pre = temp;
    temp->next = add;
    return dou;
}
int main(){
    int n,data, x, k;
    cin >> n;
    cin >> data;
    DouList *dou = createList(data);
    for(int i = 1; i < n; i++){
        cin >> data;
        addTail(dou,data);
    }
    cin >> k;
    cin >> x;
    if(k == 0) dou = addHead(dou,x);
    else if(k == n) dou = addTail(dou,x);
    else dou = addNode(dou,k,x);
    printList(dou->head);
}