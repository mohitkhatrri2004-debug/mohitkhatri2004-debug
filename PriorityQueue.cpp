#include<bits/stdc++.h>
using namespace std;
#define max 5

int data[max];
int priority[max];
int size = 0;

bool isEmpty(){
    return size == 0;
}

bool isFull(){
    return size == max;
}

void enqueue(int val, int p){
    if(isFull()){
        cout << "Priority Queue is Full" << endl;
        return;
    }
    data[size] = val;
    priority[size] = p;
    size++;

    cout << val << " inserted with priority " << p << endl;
}
int highestPriorityIndex(){
    int idx = 0;

    for(int i=0;i<size;i++){
        if(priority[i] < priority[idx]){
            idx = i;
        }
    }
    return idx;
}

void dequeue(){
    if(isEmpty()){
        cout << "Priority queue is empty" << endl;
        return;
    }
    int idx = highestPriorityIndex();
    cout << data[idx] << " removed from the queue" << endl;

    for(int i=idx;i<size-1;i++){
        data[i] = data[i+1];
        priority[i] = priority[i+1];
    }

    size--;
}
void peek(){
    if(isEmpty()){
        cout << "Priority queue is empty" << endl;
        return;
    }
    int idx = highestPriorityIndex();
    cout << "Highest priority element : " << data[idx] << ", priority " << priority[idx] << endl;
}
void display(){
    if(isEmpty()){
        cout << "Priority queue is empty" << endl;
        return;
    }
    for(int i=0;i<size;i++){
        cout << "(" << data[i] << ", P=" <<priority[i] << ")";
    }
    cout << endl;
}
int main(){
    enqueue(10,3);
    enqueue(20,5);
    enqueue(30,6);
    enqueue(40,7);
    display();
    peek();
    dequeue();
    dequeue();
    display();
    peek();
    return 0;
}