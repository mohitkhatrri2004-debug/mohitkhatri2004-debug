#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};
class List{
    Node* head;
    Node* tail;
public:
    List(){
        head = new Node(0);

        head->next = NULL;

        tail = NULL;
    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if(tail == NULL){
            head->next = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    void push_front(int val){
        Node* newNode = new Node(val);
        if(tail == NULL){
            head->next = newNode;
            tail = newNode;
        }else{
            newNode->next = head->next;
            head->next = newNode;
        }
    }
    void insertInList(int val,int pos){
        Node* newNode = new Node(val);
        Node* temp = head->next;
        for(int i=0;i<pos-1;i++){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;

        if(newNode->next == NULL){
            tail = newNode;
        }
    }
    void pop_back(){
        if(tail == NULL) return;

        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        Node* todelete = temp->next;
        temp->next = todelete->next;
        delete todelete;
        tail = temp;
    }
    void pop_front(){
        if(tail == NULL) return;

        Node* temp = head->next;
        head->next = head->next->next;
        temp->next = NULL;
        delete temp;
    }
    void display(){
        Node* temp = head->next;
        while(temp != NULL){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL";
    }
};
int main(){
    List ll;
    ll.push_front(0);
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.insertInList(4,4);
    ll.pop_back();
    ll.pop_front();
    ll.display();
    return 0;
}