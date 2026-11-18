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
        }else{
            newNode->next = head;
            head->prev = newNode;
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
        temp->next = newNode;
        newNode->prev = temp;

        if(newNode->next != NULL){
            newNode->next->prev = newNode->next;
        }else{
            tail = newNode;
        }
    }
    void pop_back(){
        if(head == NULL) return;

        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        temp->next = NULL;
        tail->next = NULL;
        tail->prev = NULL;
        delete tail;
        tail = temp;
    }
    void pop_front(){
        if(head == NULL) return;

        Node* temp = head;
        
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
    }
    void deleteFromList(int pos){
        Node* temp = head;
        for(int i=0;i<pos-1;i++){
            temp = temp->next;
        }
        Node* todelete = temp->next;
        temp->next = todelete->next;
        todelete->next->prev = temp;
        delete todelete;
    }
    void searchInList(int val){
        Node* temp = head;
        int i=0;
        bool found = false;
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
        Node* temp = head;
        while(temp!=NULL){
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL";
    }

};
int main(){
    List ll;
    ll.push_back(0);
    ll.push_back(1);
    ll.push_back(2);
    ll.push_front(-1);
    ll.insertInList(15,2);
    ll.pop_back();
    ll.pop_front();
    ll.deleteFromList(1);
    ll.searchInList(1);
    ll.display();
    return 0;
}