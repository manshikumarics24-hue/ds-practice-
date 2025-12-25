#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node* head=NULL;
void createlist(int data){
    struct node *temp,*newnode;
newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=data;
newnode->next=NULL;
if (head==NULL){
    head=newnode;
}else{
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;}

    temp->next=newnode;

    
}}
void insertatbeginning(int data){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data = data;

    if(head==NULL){
        newnode->next=NULL;
        head=newnode;
    }else{
    newnode->next=head;
    head=newnode;


}}

void insertatpos(int data, int pos){
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;

    // Case 1: insert at beginning
    if(pos == 1){
        newnode->next = head;
        head = newnode;
        return;
    }

    // Move temp to previous node
    temp = head;
    for(int i = 1; i < pos - 1; i++){
        if(temp == NULL){
            printf("Invalid position\n");
            free(newnode);
            return;
        }
        temp = temp->next;
    }

    // If position is greater than list length
    if(temp == NULL){
        printf("Invalid position\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}


void atend(int data){
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        
        
    }

}
void display(){
    struct node *temp;
temp=head;
if (head == NULL)
    {
        printf("List is empty\n");
        
    }  else{

      while(temp!=NULL){
        printf("%d->",temp->data);
      
        temp=temp->next;
      }
    }
}
int main(){
    int c,data,pos;/*
    printf("enter no. of nodes:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter data for node %d:");
        scanf("%d",&data);
        createlist(data);
    }*/
        while(1){
            printf("\n--- MENU ---\n");
        printf("1. insert at beginning:\n");
        printf("2. insert at postion:\n");
        printf("3.atend:\n");
        printf("4. display:\n");
        printf("5. Exit:\n");
        printf("Enter choice: ");
        scanf("%d", &c);

        switch (c)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertatbeginning(data);
                break;

            case 2:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &pos);
                insertatpos(data, pos);
                break;

            case 3:
                printf("enter data:");
                scanf("%d",&data);
                atend(data);
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
                    }

        
         
    
   
