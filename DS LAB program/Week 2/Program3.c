#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int front=-1;
int rear=-1;
int main(){
    int ele;
    int arr[MAX];
    int choice;
    while(1){
    printf("Enter the choice:\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
               printf("Enter the element to be inserted:\n");
               scanf("%d",&ele);
               insert(arr,ele);
                break;
        case 2: delete(arr);
                break;
        case 3: display(arr);
                break;
        case 4: exit(0);
        
         default:printf("Invalid choice\n");
    }
 }
}
void insert(int arr[],int val){
    if(rear==MAX-1){
        printf("Queue is over flow\n");
    }
    else if(rear==-1 && front==-1){
          front=0;
          rear=0;
    }
    else{
        rear++;
    }
    arr[rear]=val;
    printf("Insertion completed\n");
        
}
void delete(int arr[]){
    if(front==-1|| front>rear){
        printf("Queue is empty\n");
    }
    else{
        front++;
        printf("Deletion completed\n");
    }
}
void display(int arr[]){
    if(front==-1 || front>rear){
        printf("Queue is empty\n");
    }
    else{
    for(int i=front;i<=rear;i++){
        printf("%d ",arr[i]);
    }
    }
    printf("\n");
}
