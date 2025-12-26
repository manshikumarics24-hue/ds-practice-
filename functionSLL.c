#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head1=NULL;
struct node *head2=NULL;
void insert1(int data){
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    if(head1==NULL){
        head1=newnode;
    }else{
        temp=head1;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void insert2(int data){
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    if(head2==NULL){
        head2=newnode;
    }else{
        temp=head2;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void display1(){ 
    struct node *temp;
    if(head1==NULL){
        printf("List is empty\n");
    }else{
        temp=head1;
        while(temp!=NULL){
            printf("%d->",temp->data);
            temp=temp->next;
        }
        
    }
}
void display2(){
    struct node *temp;
    if(head2==NULL){
        printf("List is empty\n");
    }else{
        temp=head2;
        while(temp!=NULL){
            printf("%d->",temp->data);
            temp=temp->next;
        }
        
    }
}
void sort1(){
    int temp;
    struct node *i,*j;
    for(i=head1;i!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next){
            if(i->data>j->data){
                temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
        }
    }
    printf("First list sorted\n");
}
void sort2(){
   int temp;
    struct node *i,*j;
    for(i=head2;i!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next){
            if(i->data>j->data){
                temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
        }
    }
    printf("second list sorted\n");
}
void reverse1(){
    struct node *prev=NULL,*curr=head1,*next;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head1=prev;
    printf("First list reversed\n");
}
void reverse2(){
    struct node *prev=NULL,*curr=head2,*next;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head2=prev;
    printf("second list reversed\n");
}
void concatenate(){
    struct node *temp;
    if(head1==NULL){
        head1=head2;
    }else{
        temp=head1;
        while(temp->next!=NULL){
            temp=temp->next;

        }
        temp->next=head2;
    }
    head2=NULL;
    printf("Lists concatenated\n");
    }
int main(){
    int c,data;
    while(1){
    printf("1.Insert in List 1\n2.Insert in List 2\n3.Display List 1\n4.Display List 2\n5.Sort List 1\n6.Sort List 2\n7.Reverse List 1\n8.Reverse List 2\n9.Concatenate Lists\n10.Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&c);
    switch(c){
        case 1:
        printf("Enter data to insert in List 1: ");
        scanf("%d",&data);
        insert1(data);
        break;
        case 2:
        printf("Enter data to insert in List 2: ");
        scanf("%d",&data);
        insert2(data);
        break;
        case 3:
        display1();
        break;
        case 4:
        display2();
        break;
        case 5:
        sort1();
        break;
        case 6:
        sort2();
        break;
        case 7:
        reverse1();
        break;
        case 8:
        reverse2();
        break;
        case 9:
        concatenate();
        break;
        case 10:
        exit(0);
        default:
        printf("Invalid choice\n");    
    }

}
    return 0;
}

