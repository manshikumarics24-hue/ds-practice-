#include<stdio.h>
#include <stdlib.h>
#define SIZE 4
int queue[SIZE];
int front=-1,rear=-1;
void insert(int value){
    if(rear==SIZE-1){
        printf("queue is overflow!");
    }else{
        if (front == -1)
            front = 0;
        queue[++rear]=value;
        printf("%d is inserted in queue\n",value);
    }
}
void delete(){
    if(front==-1||front>rear){
        printf("Queue is empty.cannot dequeue!");
    }else{
        printf("%d is deleted fromQueue\n",queue[front]);
        front++;
    }
}
void display(){
    if(front==-1||front>rear){
        printf("Queue is empty.");
}else{
    printf("QUEUE ELEMENTS ARE!\n");
    for(int i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
}
}
int main(){
    int c,value;
    while(1){
        printf("\n1.insert\n2.delte\n3.display\n4.exit\n");
        printf("enter choice:");
        scanf("%d",&c);
        switch(c){
            case 1:
            printf("enter value to be inserted\n");
            scanf("%d",&value);
            insert(value);
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            break;
            default:
            printf("please enter valid choice\n");
            break;
        }
        
    }
}