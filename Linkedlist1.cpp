#include<iostream>
using namespace std;

struct Linkedlist1
{
    int data;
    Linkedlist1 *next;
};  
Linkedlist1 *createNode(int data){
    Linkedlist1 *temp = new Linkedlist1;
    temp->next = NULL;
    temp->data = data;
    return temp;
}

Linkedlist1 *addNode(Linkedlist1 *node, int data){
    Linkedlist1 *temp = createNode(data);
    node->next = temp;
    return temp;
}
void printList(Linkedlist1 *node){
    Linkedlist1 *temp = node;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main(){
    int n, data;
    cin >> n;
    cin >> data;
    Linkedlist1 *node = createNode(data);
    Linkedlist1 *temp = node;
    for(int i = 1; i < n; i++)
    {
        cin >> data;
        temp = addNode(temp,data);
    }
    printList(node);
    return 0;
}