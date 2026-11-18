#include<bits/stdc++.h>
using namespace std;
#define max 5

int queueArr[max];
int front = -1;
int rear = -1;

bool isEmpty(){
    return (front == -1 || front > rear);
}

bool isFull(){
    return rear == max-1;
}

void push(int val){
    if(isFull()){
        cout << "Queue overload! Can't push " << val << endl;
        return; 
    }
    if(front == -1){
        front = 0;
    }
    rear++;
    queueArr[rear] = val;
    cout << val << " pushed to queue" << endl;
}

int pop(){
    if(isEmpty()){
        cout << "queue is empty" << endl;
        return -1;
    }
    cout << queueArr[front] << " deleted from queue" << endl;
    int poped_val = queueArr[front];
    front++;
    return poped_val;
}

void peek(){
    if(isEmpty()){
        cout << "queue is empty" << endl;
        return;
    }
    cout << queueArr[front] << endl;
}

void display(){
    if(isEmpty()){
        cout << "queue is empty" << endl;
        return;
    }
    for(int i=front;i<=rear;i++){
        cout << queueArr[i] << " ";
    }
    cout << endl;
}
int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    display();
    pop();
    pop();
    display();
    peek();
    return 0;
}