#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100


char stack[MAX];
int top = -1;


void push(char value) {
    if (top < MAX - 1) {
        stack[++top] = value;
    } else {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
}


char pop() {
    if (top != -1) {
        return stack[top--];
    } else {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
}


char peek() {
    if (top != -1) {
        return stack[top];
    }
    return '\0'; 
}


int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void infixToPostfix(const char *infix, char *postfix) {
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];


        if (isalnum(ch)) {
            postfix[j++] = ch;
        }

        else if (ch == '(') {
            push(ch);
        }
  
        else if (ch == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop();
        }
        else {
            while (top != -1 && precedence(peek()) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; 
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter a valid parenthesized infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = '\0'; 
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}