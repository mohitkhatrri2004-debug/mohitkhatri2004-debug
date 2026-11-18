#include<bits/stdc++.h>
using namespace std;
#define max 5

int queueArr[max];
int front = -1;
int rear = -1;

bool isEmpty(){
    return front == -1 ;
}

bool isFull(){
    return (rear+1) % max == front;
}

//push
void push(int val){
    if(isFull()){
        cout << "Queue is full" << endl;
        return;
    }
    if(front == -1){
        front = 0;
        rear = 0;
    }else{
        rear = (rear + 1) % max;
    }
    queueArr[rear] = val;
    cout << val << " inserted" << endl;
}

//pop()
void pop(){
    if(isEmpty()){
        cout << "Queue is Empty" << endl;
        return;
    }
    cout << queueArr[front] << " deleted" << endl;

    if(front == rear){
        front = -1;
        rear = -1;
    }else{
        front = (front + 1) % max;
    }
}

//peek()
void peek(){
    if(isEmpty()){
        cout << "Queue is empty" << endl;
        return;
    }
    cout << queueArr[front] << endl;
}

//display()
void display(){
    if(isEmpty()){
        cout << "Queue is Empty" << endl;
        return;
    }
    int i = front;

    while(true){
        cout << queueArr[i] << " ";

        if(i == rear){
            break;
        }

        i = (i+1) % max;
    }
    cout << endl;
}
int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    display();
    pop();
    pop();
    display();
    push(60);
    push(70);
    display();
    peek();
    return 0;
}