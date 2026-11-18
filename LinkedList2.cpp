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
        head = NULL;
        tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            return;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }
    void push_back(int val){
        Node* newNode = new Node(val);
        
        if(head == NULL){
            head = tail = newNode;
            return;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    void insertInList(int val,int pos){
        Node* newNode = new Node(val);
        if(pos < 0) return;

        if(pos == 0){
            push_front(val);
            return;
        }else{
            Node* temp = head;
            for(int i=0;i<pos-1;i++){
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        if(newNode->next == NULL){
            tail = newNode;
        }
    }
    void pop_front(){
        if(head == NULL) return;

        Node*temp = head;
        head = head->next;
        temp->next = NULL;
        delete(temp);
    }
     void pop_back(){
        if(head == NULL) return;

        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        temp->next = NULL;
        delete(tail);
        tail = temp;
    }
    void deleteFromList(int pos){
        if(pos< 0) return;

        if(pos == 0){
            pop_front();
            return;
        }

        Node* temp = head;
        for(int i=0;i<pos-1;i++){
            temp = temp->next;
        }
        Node* todelete = temp->next;
        temp->next = todelete->next;
        delete todelete;
    }
    void searchInList(int val){
        Node* temp = head;
        int i =0 ;
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
    void sortList(){
        Node* temp = head;
        while(temp != NULL){
            Node* current = head;
                while(current != NULL && current->next != NULL){
                    if(current->data > current->next->data){
                        swap(current->data,current->next->data);
                    }
                    current =current->next;
                }
                temp = temp->next;
        }
    }
    void display(){
        Node* temp = head;
        while(temp!= NULL){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL";
    }
};
int main(){
    List ll;
    ll.push_front(2);
    ll.push_front(4);
    ll.push_front(0);
    ll.push_back(3);
    ll.push_back(1);
    ll.insertInList(5,5);
    ll.pop_front();
    ll.pop_back();
    ll.deleteFromList(1);
    ll.searchInList(1);
    ll.sortList();
    ll.display();
    return 0;
}