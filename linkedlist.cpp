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
        if(head==NULL){
            head = tail = newNode;
            return;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertAtPosition(int val,int pos){
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
    }

    void pop_front(){
        if(head == NULL) return;

        Node* temp = head;
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

    void deleteFromPosition(int pos){
        if(pos < 0) return;

        if(pos == 0){
            pop_front();
            return;
        }else{
            Node* temp = head;
            for(int i=0;i<pos-1;i++){
                temp = temp->next;
            }
            Node* todelete = temp->next;
            temp->next = todelete->next;
            delete(todelete);
        }
    }
    void searchInList(int val){
        Node* temp = head;
        int i=0;
        while(temp != NULL){
            if(temp->data == val){
            cout << "Node found at : " << i << endl;
            return;
        }
            temp = temp->next;
            i++;
        }
        cout << "Node Not Found";
    }
    void sortList(){
        Node* temp = head;
        
        while(temp != NULL){
            Node* current = head;
        while(current != NULL && current->next != NULL){
            if(current->data > current->next->data){
                swap(current->data,current->next->data);
            }
            current = current->next;
        }
        temp = temp->next;
    }
}
    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL";
    }
};
int main(){
    List ll;
    // ll.push_front(2);
    // ll.push_front(3);
    // ll.push_front(0);
    ll.push_back(1);
    ll.push_back(4);
    // ll.insertAtPosition(5,2);
    // ll.pop_front();
    // ll.pop_back();
    // ll.deleteFromPosition(1);
    // ll.searchInList(3);
    // ll.sortList();
    ll.display();
    return 0;
}