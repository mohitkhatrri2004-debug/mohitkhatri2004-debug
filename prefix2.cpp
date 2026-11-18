#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

#define MAX 100

char stackArr[MAX];
int top = -1;

// Push function
void push(char ch)
{
    stackArr[++top] = ch;
}

// Pop function
char pop()
{
    return stackArr[top--];
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

// Reverse function
void reverseString(char str[])
{
    int i, j;
    char temp;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Infix to Prefix function
void infixToPrefix(char infix[], char prefix[])
{
    int i, j = 0;
    char ch;

    // Step 1: Reverse infix expression
    reverseString(infix);

    // Step 2: Swap brackets
    for (i = 0; infix[i] != '\0'; i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';

        else if (infix[i] == ')')
            infix[i] = '(';
    }

    // Step 3: Scan the reversed expression
    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        // If operand
        if (isalnum(ch))
        
        {
            prefix[j++] = ch;
        }

        // If opening bracket
        else if (ch == '(')
        {
            push(ch);
        }

        // If closing bracket
        else if (ch == ')')
        {
            while (top != -1 && stackArr[top] != '(')
            {
                prefix[j++] = pop();
            }

            if (top != -1)
                pop(); // Remove '('
        }

        // If operator
        else
        {
            while (top != -1 &&
                   stackArr[top] != '(' &&
                   precedence(stackArr[top]) > precedence(ch))
            {
                prefix[j++] = pop();
            }

            push(ch);
        }
    }

    // Step 4: Pop remaining operators
    while (top != -1)
    {
        prefix[j++] = pop();
    }

    prefix[j] = '\0';

    // Step 5: Reverse the result
    reverseString(prefix);
}

int main()
{
    char infix[MAX], prefix[MAX];

    cout << "Enter an infix expression: ";
    cin >> infix;

    infixToPrefix(infix, prefix);

    cout << "Prefix expression: " << prefix << endl;

    return 0;
}