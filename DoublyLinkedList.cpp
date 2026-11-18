#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};
class List{
    Node* head;
    Node* tail;
public:
    List(){
        head = NULL;
        tail = NULL;
    }

    void push_back(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
            return;
        }else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            return;
        }else{
            newNode->next = head;
            newNode->prev = NULL;
            head = newNode;
        }
    }

    void insertInList(int val,int pos){

        if(pos < 0) return;

        if(pos == 0){
            push_front(val);
            return;
        }
            Node* newNode = new Node(val);
            Node* temp = head;
            for(int i=0;i<pos-1;i++){
                temp = temp->next;
            }
            newNode->next = temp->next;
            newNode->prev = temp;
            
            if(temp->next != NULL){
                temp->next->prev = newNode;
            }else{
                tail = newNode;
            }
        
        temp->next = newNode;
    }
    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL";
    }
};
int main(){
    List ll;
    ll.push_front(-1);
    ll.push_back(0);
    ll.push_back(1);
    ll.push_back(2);
    ll.insertInList(2,16);
    ll.display();
    return 0;
}