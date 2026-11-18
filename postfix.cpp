#include <iostream>
#include <cctype>
using namespace std;

#define MAX 100

char stack[MAX];
int top = -1;

// Push function
void push(char ch)
{
    stack[++top] = ch;
}

// Pop function
char pop()
{
    return stack[top--];
}

// Precedence function
int precedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

// Infix to Postfix
void infixToPostfix(char infix[], char postfix[])
{
    int i, j = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        // If operand
        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }

        // If opening bracket
        else if (ch == '(')
        {
            push(ch);
        }

        // If closing bracket
        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j++] = pop();
            }

            // Remove '(' from stack
            pop();
        }

        // If operator
        else
        {
            while (top != -1 &&
                   stack[top] != '(' &&
                   precedence(stack[top]) >= precedence(ch))
            {
                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1)
    {
        postfix[j++] = pop();
    }

    // End the postfix string
    postfix[j] = '\0';
}

// Main function
int main()
{
    char infix[MAX], postfix[MAX];

    cout << "Enter an infix expression: ";
    cin >> infix;

    infixToPostfix(infix, postfix);

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}