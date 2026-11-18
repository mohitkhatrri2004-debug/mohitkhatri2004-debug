#include<bits/stdc++.h>
using namespace std;
#define max 100

char stackArr[max];
int top = -1;

void push(char ch){
    stackArr[++top] = ch;
}

char pop(){
    return stackArr[top--];
}

int precedence(char ch){
    if(ch == '^') return 3;
    else if(ch == '*' || ch == '/') return 2;
    else if(ch == '+' || ch == '-') return 1;
    else return 0;
}

void reverseString(char str[]){
    int i,j;
    char temp;

    for(i = 0, j = strlen(str)-1; i < j; i++, j--){
        swap(str[i],str[j]);
    }
}

void infixToPrefix(char infix[], char prefix[]){
    int i, j=0;
    char ch;

    reverseString(infix);

    for(i=0; infix[i] != '\0'; i++){
        if(infix[i] == '('){
            infix[i] = ')';
        }else if(infix[i] == ')'){
            infix[i] = '(';
        }
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

            if(top != -1){
                pop();
            }
        }
        else{
            while(top != -1 && stackArr[top] != '(' && precedence(stackArr[top]) > precedence(ch)){
                prefix[j++] = pop();
            }
            push(ch);
        }
    }
    while(top != -1){
        prefix[j++] = pop();
    }
    prefix[j] = '\0';

    reverseString(prefix);
}
int main(){
    char infix[max], prefix[max];

    cout << "Enter an infix expression : ";
    cin >> infix;

    infixToPrefix(infix, prefix);

    cout << "Prefix expression : " << prefix << endl;
    return 0;
}