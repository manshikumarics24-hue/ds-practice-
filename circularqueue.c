#include<stdio.h>
#include<stdlib.h>
#define SIZE 4
int queue[SIZE];
int front=-1;
int rear=-1;
void insert(int value){
    if((front==0 && rear==SIZE -1)||(rear+1)%SIZE==front){
        printf("queue is overflow.cannot insert more !");
    }else{
        if(front==-1)
          front=0;
        rear=(rear+1)%SIZE;
        queue[rear]=value;
        printf("%d is inserted in queue\n",value);
    }
}
void del(){
    if(front==-1){
        printf("Queue is unedrflow.cannot delete elemnts !");

    }else{
         printf("%d is delted from Queue\n",queue[front]);
        if(front==rear)
         front=rear=-1;
        else
        front=(front+1)%SIZE;


    }
}
void display(){
    if(front==-1){
        printf("Queue is Empty!\n");
    }else{
        int i=front;
        while(1){
            printf("%d\t",queue[i]);
            if(i==rear)
                break;
                i=(i+1)%SIZE;
            
        }
    }
}
int main(){
    int c,value;
    while(1){
        printf("\n1.insert\n2.del\n3.display\n4.exit\n");
        printf("enter choice:");
        scanf("%d",&c);
        switch(c){
            case 1:
            printf("enter a elements:\n");
            scanf("%d",&value);
            insert(value);
            break;
            case 2:
            del();
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
    return 0;
}