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
void InsertAfterNode(Node* givenNode,int value){
        Node* newNode = new Node(value);

        newNode->next = givenNode->next;

        newNode->prev = givenNode;

        if(givenNode != NULL){
            givenNode->next->prev = newNode;
        }

        givenNode->next = newNode;
}
void display( Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL";
    cout << endl;
}
int main(){
    Node* head = new Node(10);

    head->next = new Node(20);
    head -> next -> prev = head;

    head->next->next = new Node(30);
    head->next->next->prev = head->next;

    head->next->next->next = new Node(40);
    head->next->next->next ->prev = head->next->next;

    cout << "Linked list before Insertion : ";
    display(head);

    InsertAfterNode(head->next,5);

    cout << "Linked list after Insertion : ";
    display(head);
     return 0;
}
