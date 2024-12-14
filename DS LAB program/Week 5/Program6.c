#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int data) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void insertAtBeginning(struct Node **head, int data) {
    struct Node *newnode = createNode(data); // Correctly assign data
    newnode->next = *head;
    *head = newnode;
}

void concat(struct Node **head1, struct Node *head2) {
    if (*head1 == NULL) {
        *head1 = head2;
        return;
    }

    struct Node *temp = *head1;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
}

void sort(struct Node *head) {
    struct Node *temp, *current;
    int t;
    current = head;

    while (current != NULL) {
        temp = head;
        while (temp->next != NULL) {
            if (temp->data > temp->next->data) {
                t = temp->data;
                temp->data = temp->next->data;
                temp->next->data = t;
            }
            temp = temp->next;
        }
        current = current->next;
    }
}

void reverse(struct Node **head) {
    struct Node *temp = NULL;
    while (*head != NULL) {
        struct Node *current = *head;
        *head = (*head)->next;
        current->next = temp;
        temp = current;
    }
    *head = temp;
}

void displayLinkedList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *list1 = NULL;
    struct Node *list2 = NULL;

    insertAtBeginning(&list1, 1);
    insertAtBeginning(&list1, 2);
    insertAtBeginning(&list1, 3);
    insertAtBeginning(&list2, 4);
    insertAtBeginning(&list2, 5);
    insertAtBeginning(&list2, 6);

    printf("Linked List 1: ");
    displayLinkedList(list1);
    printf("Linked List 2: ");
    displayLinkedList(list2);

    printf("After Sorting:\n");
    sort(list1);
    sort(list2);
    printf("Linked List 1: ");
    displayLinkedList(list1);
    printf("Linked List 2: ");
    displayLinkedList(list2);

    printf("After Concatenation:\n");
    concat(&list1, list2);
    printf("Linked List 1: ");
    displayLinkedList(list1);

    printf("After Reversing:\n");
    reverse(&list1);
    printf("Linked List 1: ");
    displayLinkedList(list1);

    return 0;
}
