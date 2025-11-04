#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return -1;
    }
}

void infixToPostfix(char* infix, char* postfix) {
    char stack[MAX];
    int top = -1;
    int j = 0;
    
    for (int i = 0; infix[i]; i++) {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || 
            (infix[i] >= 'A' && infix[i] <= 'Z')) {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(') {
            stack[++top] = infix[i];
        }
        else if (infix[i] == ')') {
            while (top > -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            if (top > -1 && stack[top] == '(') {
                top--;
            }
        }
        else if (isOperator(infix[i])) {
            while (top > -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
    }
    while (top > -1) {
        postfix[j++] = stack[top--];
    }
    
    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    
    printf("Enter infix expression: ");
    scanf("%s", infix);
    
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    
    return 0;
}
A