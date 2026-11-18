#include<bits/stdc++.h>
#define max 100
using namespace std;

int stackArr[max];
int top = -1;

//push function
void push(char ch){
    stackArr[top] = ch;
}

//pop function
char pop(){
    return stackArr[top--];
}

//precedence function
int precedence(char ch){
    if(ch == '^') return 3;
    else if(ch == '*' || ch == '/') return 2;
    else if(ch == '+' || ch == '-') return 1;
    else return 0;
}

//Reverse function
void reverseString(char str[]){
    int i,j;
    for(i=0, j = strlen(str)-1; i<j; i++, j--){
        swap(stackArr[i], stackArr[j]);
    }
}
//infixToPrefix
void infixToPrefix(char infix[], char prefix[]){
    int i,j = 0;
    char ch;

    for(i = 0; infix[i] != '\0'; i++){
        if(infix[i] == '(')
            infix[i] = ')';
        else if(infix[i] == ')')
            infix[i] = '(';
    }

    for(i = 0; infix[i] != '\0'; i++){

        ch = infix[i];

        if(isalnum(ch)){
            prefix[j++] = ch;
        }else if(ch == '('){
            push(ch);
        }else if(ch == ')'){
            while(top != -1 && stackArr[top] != '('){
                prefix[j++] = pop();
            }
            if(top != -1)
                pop();
        }else{
            while(top != -1 && stackArr[top] != ')' && precedence(stackArr[top]))
        }
    }
}
int main(){

    return 0;
}