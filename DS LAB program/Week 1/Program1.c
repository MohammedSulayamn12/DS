#include<stdio.h>
#include<stdlib.h>

#define MAX 100
int top = -1;

void push(int Stack[], int val);
void pop(int Stack[]);
void Display(int Stack[]);

int main() {
    int ele, choice;
    int Stack[MAX];
    
    while(1) {
        printf("\nEnter the Choice:\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter the Element:\n");
                scanf("%d", &ele);
                push(Stack, ele);
                break;
            case 2:
                pop(Stack);
                break;
            case 3:
                Display(Stack);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}

void push(int Stack[], int val) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        top++;
        Stack[top] = val;
        printf("Element %d pushed to stack\n", val);
    }
}

void pop(int Stack[]) {
    if (top == -1) {
        printf("Stack underflow\n");
    } else {
        printf("Element %d popped from stack\n", Stack[top]);
        top--;
    }
}

void Display(int Stack[]) {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d ", Stack[i]);
        }
        printf("\n");
    }
}