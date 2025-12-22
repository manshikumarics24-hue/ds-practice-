#include<stdio.h>
#include<stdlib.h>

#define MAX 3
int stack[3];
int top=-1;
void push(int v){
    if(top==MAX-1){
        printf("stack is overflow");

    }else{
        stack[++top]=v;
        printf("%d is pushed in stack",v);

    }
}
void pop(){
    if(top==-1){
        printf("stack is underflow");
    }else{
        int p=stack[top];
        printf("%d is popped from stack",p);
        top--;
    }
}
void display(){
if(top==-1){
    printf("stack is empty");
}else{
    for(int i=top;i>=0;i--){
        printf("%d\n",stack[i]);
    }
}
}
int main(){
    int c;
    while(1){
        printf("\n1.push\n2.pop\n3.display\n4.exit\n");
        printf("enter choice:");
        scanf("%d",&c);
    
    switch(c){
        case 1:
        printf("enter value to be pushed");
        int a;
        scanf("%d",&a);
        push(a);
        break;
        case 2:
        pop();
        break;
        case 3:
        display();
        break;
        case 4:
        exit(0);
        break;
        default:
        printf("please enter valid choice");
        break;
    }
    }
    return 0;
}
