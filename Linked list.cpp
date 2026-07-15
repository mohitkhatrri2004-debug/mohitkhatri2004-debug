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
        head = tail = NULL;
    }
    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }else{
            newNode -> next = head;
            head = newNode;
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if(tail == NULL){
            head = tail = newNode;
        }else{
            tail -> next = newNode;
            tail = newNode;
        }
    }

    void pop_front(){
        if(head == NULL) return;
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }

    void pop_back(){
        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }
    
    void insert(int val,int pos){
        if(pos < 0) return;

        if(pos == 0){
            push_front(val);
            return;
        }

        Node* temp = head;
        for(int i=0;i<pos-1;i++){
            temp = temp->next;
        }
        Node* newNode = new Node(val);
        newNode->next =  temp->next;
        temp->next = newNode;
    }

    int search(int key){
        Node* temp = head;
        int idx = 0;
        while(temp->next != NULL){
            if(temp->data == key){
                cout << "Key Found at : " << idx << endl;
            }
            temp = temp->next;
            idx++;
        }
    }
    void reverseLL(){
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    void printLL(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp -> data << " ";
            temp = temp -> next;
        }
        cout << endl;
    }
};
int main(){
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);

    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);

    // ll.pop_front();
    // ll.pop_back();
    // ll.insert(67,2);
    ll.printLL();
    // ll.search(67);
    ll.reverseLL();
    ll.printLL();
    return 0;
}