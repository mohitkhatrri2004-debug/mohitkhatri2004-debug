#include<bits/stdc++.h>
using namespace std;

#define max 5

int Stack[max];
int top = -1;

bool isfull(){
    return top == max-1;
}

bool isempty(){
    return top == -1;
}

void push(int val){
    if(isfull()){
        cout << "Stack overflow! cannot push " << val << endl;
    }else{
        top++; 
        Stack[top] = val;
        cout << val << " Pushed to stack" << endl;
    }
}

int pop(){
    if(isempty()){
        cout << "Stack is underflow, Nothing to pop" << endl;
        return -1;
    }else{
        int poped_val = Stack[top];
        top--;
        return poped_val;
    }
}

int display(){
    if(isempty()){
        cout << "Stack is empty" << endl;
    }else{
        for(int i=top;i>=0;i--){
            cout << Stack[i] << " ";
        }
    }
    cout << endl;
}

int peek(){
    if(isempty()){
        return -1;
    }else{
        return Stack[top];
    }
}

int main(){
    push(10);
    push(20);
    push(30);

    display();
    cout << "Top element is " << peek() << endl;;
    cout << "Poped element is " << pop() << endl;
    display();
    return 0;
}