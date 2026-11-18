#include<bits/stdc++.h>
using namespace std;
#define max 5

int Dequeue[max];
int front = -1;
int rear = -1;

bool isEmpty(){
    return front == -1;
}

bool isFull(){
    return (front == 0 && rear == max-1) || (front == rear+1);
}

//push at front
void insertFront(int val){
    if(isFull()){
        cout << "Queue is full" << endl;
        return;
    }
    if(front == -1){
        front = rear = 0;
    }else if(front == 0){
        front = max-1;
    }else{
        front--;
    }

    Dequeue[front] = val;
    cout << val << " inserted at front" << endl;
}
//push at rear
void insertRear(int val){
    if(isFull()){
        cout << "Queue is full" << endl;
        return;
    }
    if(front == -1){
        front = rear = 0;
    }else if(rear == max-1){
        rear = 0;
    }else{
        rear++;
    }

    Dequeue[rear] = val;
    cout << val << " inserted at rear" << endl;
}
void deleteFront(){
    if(isEmpty()){
        cout << "Queue is empty" << endl;
        return;
    }
    cout << Dequeue[front] << " deleted from front" << endl;
    if(front == rear){
        front = rear = -1;
    }else if(front == max-1){
        front = 0;
    }else{
        front++;
    }
}
void deleteRear(){
    if(isEmpty()){
        cout << "Queue is empty" << endl;
        return;
    }
    cout << Dequeue[rear] << " deleted from front" << endl;
    if(front == rear){
        front = rear = -1;
    }else if(rear == 0){
        rear = max-1;
    }else{
        rear--;
    }
}
void getFront(){
    if(isEmpty()){
        cout << "Queue `is empty" << endl;
        return;
    }
    cout << "Front is : " << Dequeue[front] << endl; 
}
void getRear(){
    if(isEmpty()){
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Rear is : " << Dequeue[rear] << endl; 
}
void display(){
    if(isEmpty()){
        cout << "Queue is empty" << endl;
        return;
    }
    int i = front;

    while(true){
        cout << Dequeue[i] << " ";
        
        if(i == rear){
            break;
        }

        i = (i+1) % max;
    }
    cout << endl;
}
int main(){
        insertRear(20);
    insertRear(30);
    insertRear(40);

    display();

    insertFront(10);

    display();

    insertFront(5);

    display();

    deleteFront();

    display();

    deleteRear();

    display();

    getFront();
    getRear();
    return 0;
}