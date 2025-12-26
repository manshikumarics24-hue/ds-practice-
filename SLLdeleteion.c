#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node* head=NULL;
void createlist(int data){
    
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof( struct node));
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
void deleteatfirst(){
    struct node *temp;
    if(head==NULL){
        printf("List is empty\n");
    }else{
        temp=head;
        head=head->next;
        free(temp);
        printf("First node deleted\n");
        }
}
void deleteatpos(int key){
    struct node *temp,*prev;
    if(head==NULL){
        printf("List is empty\n");}
        else if(head->data==key){
            temp=head;
            head=head->next;
            free(temp);
            printf("Node with data %d deleted\n",key);
        }else{
            prev=head;
            temp=head->next;
            while(temp!=NULL&&temp->data!=key){
                prev=temp;
                temp=temp->next;
            }
            if(temp==NULL){
                printf("node with data%d not found\n",key);
            }else{
                prev->next=temp->next;
                free(temp);
                printf("Node with data %d deleted\n",key);
            }
        }      
}
void deleteatend(){
    struct node *temp,*prev;
    if(head==NULL){
        printf("List is empty\n");}
        else if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Last node deleted\n");}
        else{
            prev=head;
            temp=head->next;
            while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
            }
            prev->next=NULL;
            free(temp);
            printf("Last node deleted\n");

        }
}
void display(){
    struct node *temp;
     if(head==NULL){
        printf("List is empty\n");}
        else{
            temp=head;
            while(temp!=NULL){
                printf("%d->",temp->data);
                temp=temp->next;

            }
        }
}
int main(){
    int c,data;
    while(1){
        printf("\n1.Create List\n2.Delete at first\n3.Delete at position\n4.Delete at end\n5.Display\n6.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&c);
        switch(c){
            case 1:
                printf("Enter data to create list:");
                scanf("%d",&data);
                createlist(data);
                break;
            case 2:
                deleteatfirst();
                break;
            case 3:
                printf("Enter data of node to delete:");
                scanf("%d",&data);
                deleteatpos(data);
                break;
            case 4:
                deleteatend();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}