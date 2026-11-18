#include<bits/stdc++.h>
using namespace std;
#define max 20

int Queue[max];
int front = -1;
int rear = -1;

int isFull(){
    return rear == max-1;
}

int isEmpty(){
    return (front == -1 || front > rear);
}

void push(int val){
    if(isFull()){
        cout << "Queue is full" << endl;
        return;
    }else{
        if(front == -1){
            front = 0;
        }

        rear++;

        Queue[rear] = val;
        cout << val << " pushed into queue" << endl;
    }
}

int pop(){
    if(isEmpty()){
        cout << "Queue is Empty" << endl;
        return -1;
    }else{
        int pop_val = Queue[front];
        front++;
        return pop_val;
    }
}

void peek(){
    if(isEmpty()){
        cout << "Queue is Empty" << endl;
        return;
    }
    cout << Queue[front] << " is peek element" << endl;
}

void display(){
    if(isEmpty()){
        cout << "Queue is Empty" << endl;
        return;
    }
    for(int i=front;i<=rear;i++){
        cout << Queue[i] << " ";
    }
    cout << endl;
}
int main(){
    push(10);
    push(20);
    push(30);
    display();
    peek();
    display();
    pop();
    display();
    peek();

    return 0;
}