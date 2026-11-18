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
class CList{
    Node* head;
    Node* tail;
public:
    CList(){
        head = tail = NULL;
    }
    void push_front(int val){
    Node* newNode = new Node(val);

    if(tail == NULL){
        head = tail = newNode;
        tail->next = head;
    }else{
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
}
    void insertAtTail(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            tail->next = head;
        }else{
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }
    void deleteAtList(){
        if(head == NULL) return;

        if(head == tail){
            delete head;
            head = tail = NULL;
        }

        Node* temp = head;
        head = head->next;
        tail->next = head;
        temp->next = NULL;
        delete temp;
    }

    void deleteAtTail(){
        if(head == NULL) return;

        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }

        temp->next = head;
        tail->next = NULL;
        delete tail;
        tail = temp;
    }
    void search(int val){
        if(head == NULL) return;
        bool found = false;
        int i=0;
        Node* temp = head;
        while(temp != NULL){
            if(temp->data == val){
                cout << "Found at : " << i << endl;
                found = true;
                break;
            }
            temp = temp->next;
            i++;
        }
        if(!found){
            cout << "Not Found\n";
        }
    }
    void display(){
        if(head == NULL) return;

        cout << head->data << " -> ";
        Node* temp = head->next;

    while(temp != head){
        cout << temp->data << " -> " ;
        temp = temp->next; 
    }
    cout << temp->data << endl;
    }
};
int main(){
    CList cl;
    cl.push_front(2);
    cl.push_front(1);
    cl.push_front(0);
    cl.insertAtTail(3);
    cl.deleteAtList();
    cl.deleteAtTail();
    cl.search(2);
    cl.display();
    return 0;
}