#include<stdlib.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *createNode(int data){
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
}

void insertAtfront(struct Node **head,int data){
    struct Node *newnode=createNode(data);

    if(*head==NULL){
        *head=newnode;
        return;
    }

    struct Node *temp=*head;

    if(temp!=NULL){
        newnode->next=temp;
    }

    temp->prev=newnode;
    *head=newnode;

}
void insertAtend(struct Node **head,int data){
    struct Node *newnode=createNode(data);

    if(*head==NULL){
        *head=newnode;
        return;
    }

    struct Node *temp=*head;

    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=newnode;
    newnode->prev=temp;

}
void Deletefromfront(struct Node **head){
    if(*head==NULL){
        printf("\n list is empty");
        return;
    }
     struct Node*temp=*head;
    if((*head)->next==NULL){
        *head=NULL;
        free(temp);
        return;
    }

    *head=temp->next;

    if(*head!=NULL){
        (*head)->prev=NULL;
    }

    free(temp);
}
void Deletefromend(struct Node **head){
     if(*head==NULL){
        printf("\n list is empty");
        return;
    }
     struct Node*temp=*head;
    if((*head)->next==NULL){
        *head=NULL;
        free(temp);
        return;
    }

    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->prev->next=NULL;
    free(temp);
}
void printlist(struct Node **head) {
    if (*head == NULL) {
        printf("\nList is empty");
        return;
    }

    struct Node *temp = *head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node *head = NULL;
    int choice, value;

    while (1) {
        printf("\n\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from End\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertAtfront(&head, value);
                break;

            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtend(&head, value);
                break;

            case 3:
                printf("Deleting from front...\n");
                Deletefromfront(&head);
                break;

            case 4:
                printf("Deleting from end...\n");
                Deletefromend(&head);
                break;

            case 5:
                printf("Displaying the list:\n");
                printlist(&head);
                break;

            case 6:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}