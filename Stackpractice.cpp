#include<bits/stdc++.h>
#define max 5
using namespace std;

int Queue[max];
int front = -1;
int rear = -1;

bool isfull(){
    return rear == max-1;
}

bool isempty(){
    return(front == -1 || front > rear);
}

void enqueue(int val){
    if(isfull()){
        cout << "Queue overflow! Can't Enqueue" << endl;
    }else{
        if(front == -1){
            front = 0;
        }
            rear++;
            Queue[rear] = val;
            cout << val << " pushed to queue" << endl;
    }
}
int dequeue(){
    if(isempty()){
        cout << "Queue UnderFlow! Nothing to pop" << endl;
        return -1;
    }else{
        int poped_val = Queue[front];
        front++;
        return poped_val;
    }
}
int peek(){
    if(isempty()){
        cout << "Queue is empty! Nothing to delete" << endl;
        return -1;
    }else{
        return Queue[front];
    }
}
void display(){
    if(isempty()){
        cout << "Queue is empty!" << endl;
    }else{
        for(int i=front;i<=rear;i++){
            cout << Queue[i] << " ";
        }
    }
    cout << endl;
}
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    cout << peek() << endl;
    dequeue();
    display();
    return 0;
}