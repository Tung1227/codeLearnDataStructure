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
DouList *deletenNode(DouList *dou, int k){
    Node *temp = dou->head;
    for(int i = 0 ; i < k-1; i++){
        temp = temp->next;
    }
    Node *d = temp->next;
    temp->next = d->next;
    d->next->pre = temp;
    delete(d);
    return dou;
}
DouList *deleteHead(DouList *dou){
    Node *temp = dou->head;
    dou->head = dou->head->next;
    delete(temp);
    return dou;
}
DouList *deleteTail(DouList *dou){
    Node *temp = dou->tail;
    dou->tail = temp->pre;
    dou->tail->next = NULL;
    delete(temp);
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
    if(k == 0) dou = deleteHead(dou);
    else if(k == n-1) dou = deleteTail(dou);
    else dou = deletenNode(dou,k);
    printList(dou->head);
}