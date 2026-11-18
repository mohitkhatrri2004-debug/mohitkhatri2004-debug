#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* top = NULL;

bool isEmpty(){
    return top == NULL;
}

void push(int val){
    Node* newNode = new Node;

    newNode->data = val;
    newNode->next = top;
    top = newNode;

    cout << val << " pushed into stack" << endl;
}

void pop(){
    if(isEmpty()){
        cout << "Stack underflow" << endl;
        return;
    }

    Node* temp = top;

    cout << temp->data << " poped from stack" << endl;

    top = top->next;
    delete temp;
}

void peek(){
    if(isEmpty()){
        cout << "Stack underflow" << endl;
        return;
    }
    cout << "Top element : " << top->data << endl;
}

void display(){
    if(isEmpty()){
        cout << "Stack underflow" << endl;
        return;
    }
    Node* temp = top;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    display();
    peek();
    pop();
    display();
    return 0;
}