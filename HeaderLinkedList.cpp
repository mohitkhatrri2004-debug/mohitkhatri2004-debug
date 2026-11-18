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
    Node* head;     // head points to HEADER node
    Node* tail;     // tail points to last data node

public:

    List(){

        // Creating the header node
        head = new Node(0);

        // Header does not contain actual data
        head->next = NULL;

        // Initially there is no data node
        tail = NULL;
    }

    void push_front(int val){

        Node* newNode = new Node(val);

        // New node comes after header
        newNode->next = head->next;

        // Header now points to new node
        head->next = newNode;

        // If list was empty
        if(tail == NULL){
            tail = newNode;
        }
    }

    void push_back(int val){

        Node* newNode = new Node(val);

        if(tail == NULL){

            // List is empty
            head->next = newNode;
            tail = newNode;

        }else{

            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertAtPosition(int val, int pos){

        if(pos < 0) return;

        // Position 0 means first data node
        if(pos == 0){
            push_front(val);
            return;
        }

        Node* temp = head;

        // Move to node before required position
        for(int i = 0; i < pos - 1; i++){

            if(temp->next == NULL){
                return;
            }

            temp = temp->next;
        }

        Node* newNode = new Node(val);

        newNode->next = temp->next;
        temp->next = newNode;

        // If inserted at end
        if(newNode->next == NULL){
            tail = newNode;
        }
    }

    void pop_front(){

        // No data node
        if(head->next == NULL) return;

        Node* temp = head->next;

        // Header skips the first data node
        head->next = temp->next;

        // If only one node existed
        if(temp == tail){
            tail = NULL;
        }

        temp->next = NULL;

        delete(temp);
    }

    void pop_back(){

        // Empty list
        if(head->next == NULL) return;

        // Only one data node
        if(head->next == tail){

            delete(tail);

            head->next = NULL;
            tail = NULL;

            return;
        }

        Node* temp = head;

        // Find node before tail
        while(temp->next != tail){
            temp = temp->next;
        }

        temp->next = NULL;

        delete(tail);

        tail = temp;
    }

    void deleteFromPosition(int pos){

        if(pos < 0) return;

        // Position 0 = first data node
        if(pos == 0){
            pop_front();
            return;
        }

        Node* temp = head;

        // Move to node before the node to delete
        for(int i = 0; i < pos - 1; i++){

            if(temp->next == NULL){
                return;
            }

            temp = temp->next;
        }

        // Node to delete
        Node* todelete = temp->next;

        // Invalid position
        if(todelete == NULL){
            return;
        }

        temp->next = todelete->next;

        // If last node was deleted
        if(todelete == tail){
            tail = temp;
        }

        todelete->next = NULL;

        delete(todelete);
    }

    void searchInList(int val){

        // Start from first ACTUAL data node
        Node* temp = head->next;

        int i = 0;

        while(temp != NULL){

            if(temp->data == val){

                cout << "Node found at : " << i << endl;

                return;
            }

            temp = temp->next;
            i++;
        }

        cout << "Node Not Found" << endl;
    }

    void sortList(){

        // Start from first actual data node
        Node* temp = head->next;

        while(temp != NULL){

            Node* current = head->next;

            while(current != NULL && current->next != NULL){

                if(current->data > current->next->data){

                    swap(current->data, current->next->data);
                }

                current = current->next;
            }

            temp = temp->next;
        }
    }

    void display(){

        // Do NOT display header
        Node* temp = head->next;

        while(temp != NULL){

            cout << temp->data << " -> ";

            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

int main(){

    List ll;

    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(0);

    ll.push_back(1);
    ll.push_back(4);

    ll.insertAtPosition(5,2);

    ll.pop_front();

    ll.pop_back();

    ll.deleteFromPosition(1);

    ll.searchInList(3);

    ll.sortList();

    ll.display();

    return 0;
}