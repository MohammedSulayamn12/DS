#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *CreateNode(int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtfirst(struct Node** head,int data){
    struct Node *newNode = CreateNode(data);
    newNode->next = *head;
    *head = newNode;
}
void insertAtEnd(struct Node** head,int data){
    struct Node *newNode = CreateNode(data);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}
void insertAtPosition(struct Node** head,int data,int position){
   struct Node *newNode = CreateNode(data);
    if(position==0){
        insertAtfirst(head,data);
        return;
    }
    struct Node *temp=*head; 
    for(int i=0;i<position-1 && temp!=NULL;i++){
        temp=temp->next;
    }
  
    if(temp==NULL){
        printf("Position out of range\n");
        free(newNode);
        return;
    }
    if(position>0){
    newNode->next=temp->next;
    temp->next=newNode;
    }
}
void deletefromFirst(struct Node** head){
    if(*head==NULL){
        printf("List is empty\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}
void deletefromend(struct Node** head){
    if(*head==NULL){
        printf("List is empty\n");
        return;
    }
    if((*head)->next==NULL){
        free(*head);
        *head=NULL;
        return;
    }
    struct Node *temp = *head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
}
void deleteAtPosition(struct Node** head, int position){
    if(*head==NULL){
        printf("List is empty\n");
        return;
    }
    if(position==0){
        deletefromFirst(head);
        return;
    }
    struct Node *temp=*head;
    for(int i=0;i<position-1 && temp!=NULL;i++){
        temp=temp->next;
    }
    if(temp==NULL || temp->next==NULL){
        printf("Position out of range\n");
        return;
    }
    struct Node *nextNode = temp->next->next;
    free(temp->next);
    temp->next = nextNode;
}
void Print(struct Node* head){
    struct Node *temp = head;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct Node* head=NULL;
    int choice,data,position;
    
    while(1){
        printf("\n Choose an operation:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at specfic position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete at specific position\n");
        printf("7. Display list\n");
        printf("8. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
                   printf("Enter data to insert at beginning:");
                   scanf("%d",&data);
                   insertAtfirst(&head,data);
                   break;
            case 2: printf("Enter data to insert at end:");
                    scanf("%d",&data);
                    insertAtEnd(&head,data);
                    break;
            case 3: printf("Enter data and position to insert:");
                    scanf("%d%d",&data,&position);
                    insertAtPosition(&head,data,position);
                    break;
            case 4: printf("Deleting node from beginning\n");
                    deletefromFirst(&head);
                    break;
            case 5: printf("Deleting node from end\n");
                    deletefromend(&head);
                    break;
            case 6: printf("Enter position to delete node:");
                    scanf("%d",&position);
                    deleteAtPosition(&head,position);
                    break;
            case 7: printf("Linked List contents:\n");
                    Print(head);
                    break;
            case 8: printf("Exiting...\n");
                    exit(0);
            default: printf("Invalid choice\n");
    }
}
}
