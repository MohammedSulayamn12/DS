#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int front = -1;
int rear = -1;

void Insertion(int circularqueue[], int val);
void Deletion(int circularqueue[]);
void Display(int circularqueue[]);

int main() {
    int ele;
    int choice;
    int circularqueue[MAX];
    
    while (1) {
        printf("\nEnter the choice:\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter the element to be inserted:\n");
                scanf("%d", &ele);
                Insertion(circularqueue, ele);
                break;
            case 2:
                Deletion(circularqueue);
                break;
            case 3:
                Display(circularqueue);
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice\n");
        }
    }
}

void Insertion(int circularqueue[], int val) {
    if ((rear == MAX - 1 && front == 0) || (rear + 1 == front)) {
        printf("Queue is full\n");
        return;
    } else {
        if (front == -1 && rear == -1) {
            rear = front = 0;
        } else if (rear == MAX - 1 && front != 0) {
            rear = 0;
        } else {
            rear++;
        }
        circularqueue[rear] = val;
    }
}

void Deletion(int circularqueue[]) {
    if (front == -1) {
        printf("\nQueue is underflow\n");
        return;
    }
    
    printf("Deleted element: %d\n", circularqueue[front]);
    
    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

void Display(int circularqueue[]) {
    if (front == -1) {
        printf("\nQueue is empty\n");
        return;
    }
    
    printf("Queue elements are: ");
    int i = front;
    while (1) {
        printf("%d ", circularqueue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
