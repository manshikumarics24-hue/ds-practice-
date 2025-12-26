#include <stdio.h>
#include <stdlib.h>

// ---------- for stack ---------- //
struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;
struct node *front = NULL;
struct node *rear = NULL;

void push(int val)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = top;
    top = newnode;
    printf("item %d pushed successfully!\n",val);
}

void pop()
{
    struct node *temp;

    if (top == NULL)
    {
        printf("stack underflow\n");
    }
    else
    {
        temp = top;
        printf("popped elements is %d\n", temp->data);
        top = top->next;
        free(temp);
    }
}

void displaystack()
{
    if (top == NULL)
    {
        printf("empty list!!!\n");
        return;
    }

    struct node *temp = top;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// ---------- for queue ---------- //
void enqueue(int value)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newnode;
        printf("element %d entered in stack:\n", value);
        return;
    }

    rear->next = newnode;
    rear = newnode;
    printf("element %d entered in Queue:\n", value);
}

void dequeue()
{
    struct node *temp;

    if (front == NULL)
    {
        printf("queue underflow\n");
        return;
    }

    temp = front;
    printf("element %d removed from queue:\n", temp->data);
    front = front->next;
    free(temp);

    if (front == NULL)
        rear = NULL;
}

void displayqueue()
{
    struct node *temp = front;
    printf("Queue: ");

    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, data;

    while (1)
    {
        printf("\n---- stack and queue ----");
        printf("\n1.Push\n2.Pop\n3.Enqueue\n4.Dequeue\n5.Display Stack\n6.Display Queue\n7.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &data);
            push(data);
            break;

        case 2:
            pop();
            break;

        case 3:
            printf("Enter value: ");
            scanf("%d", &data);
            enqueue(data);
            break;

        case 4:
            dequeue();
            break;

        case 5:
            displaystack();
            break;

        case 6:
            displayqueue();
            break;

        case 7:
            exit(0);

        default:
            printf("Enter valid choice!!\n");
        }
    }

    return 0;
}
