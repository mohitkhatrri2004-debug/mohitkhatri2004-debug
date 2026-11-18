#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

bool isEmpty(){
    return front == NULL;
}

void enqueue(int val){
    Node* newNode = new Node();

    newNode->data = val;
    newNode->next = NULL;
    
    if(isEmpty()){
        front = rear = newNode;
    }else{
        rear->next = newNode;
        rear = newNode;
    }
    cout << val << " inserted into queue" << endl;
}

void dequeue(){
    if(isEmpty()){
        cout << "Queue underflow" << endl;
        return;
    }
    Node* temp = front;

    cout << temp->data << " is dequeeued from queue" << endl;

    front = front->next;

    if(front == NULL){
        rear = NULL;
    }
    delete temp;
}

void peek(){
    if(isEmpty()){
        cout << "Queue underflow" << endl;
        return;
    }
    cout << "Front element : " << front->data << endl;
}

void display(){
    if(isEmpty()){
        cout << "Queue underflow" << endl;
        return;
    }
    Node* temp = front;

    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    dequeue();
    dequeue();
    display();
    peek();
    return 0;
}