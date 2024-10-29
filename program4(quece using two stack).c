#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum size of the stacks


int stack1[MAX];
int top1 = -1; 

int stack2[MAX];
int top2 = -1; 


void push1(int item) {
    if (top1 == MAX - 1) {
        printf("Stack 1 Overflow\n");
        return;
    }
    stack1[++top1] = item;
}


int pop2() {
    if (top2 == -1) {
        printf("Stack 2 Underflow\n");
        return -1; 
    }
    return stack2[top2--];
}


void transfer() {
    while (top1 != -1) {
        stack2[++top2] = stack1[top1--]; 
    }
}


void enqueue(int item) {
    push1(item);
}

int dequeue() {
    if (top2 == -1) {
        if (top1 == -1) {
            printf("Queue is empty\n");
            return -1; 
        transfer();
    }
    return pop2();
}


void display() {

    for (int i = top2; i >= 0; i--) {
        printf("%d -> ", stack2[i]);
    }
    

    for (int i = 0; i <= top1; i++) {
        printf("%d -> ", stack1[i]);
    }
    
    printf("NULL\n");
}


int main() {
    int choice, data;

    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                data = dequeue();
                if (data != -1) {
                    printf("Dequeued: %d\n", data);
                }
                break;
            case 3:
                printf("Queue contents: ");
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
