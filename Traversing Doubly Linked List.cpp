#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* prev;
        Node* next;

    Node(int value){
        data = value;
        prev = NULL;
        next = NULL;
    }
};
int main(){
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth= new Node(40);

    first->prev = NULL;
    first->next = second;

    second->prev = first;
    second->next = third;

    third->prev = second;
    third->next = fourth;

    fourth->prev = third;
    fourth->next = NULL;

    Node* temp = first;
    
    while(temp != NULL){
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL";
    return 0;
}