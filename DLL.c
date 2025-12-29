#include <stdio.h>
#include <stdlib.h>

/* Structure definition */
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

/* Create a doubly linked list (Insert at end) */
void create(int value)
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
        return;
    }

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;
}

/* Insert a new node to the LEFT of a given node */
void insert_left(int key, int value)
{
    struct node *temp = head, *newnode;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Key not found!\n");
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;

    newnode->next = temp;
    newnode->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = newnode;
    else
        head = newnode;

    temp->prev = newnode;

    printf("Node inserted to the left of %d\n", key);
}

/* Delete the node based on a specific value */
void delete_value(int key)
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Value not found!\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Node deleted successfully\n");
}

/* Display the list */
void display()
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    printf("Doubly Linked List:\n");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* Main function */
int main()
{
    int choice, value, key;

    while (1)
    {
        printf("\n---- Doubly Linked List Menu ----\n");
        printf("1. Create list (Insert at end)\n");
        printf("2. Insert to left of a node\n");
        printf("3. Delete by value\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            create(value);
            break;

        case 2:
            printf("Enter key value: ");
            scanf("%d", &key);
            printf("Enter new value: ");
            scanf("%d", &value);
            insert_left(key, value);
            break;

        case 3:
            printf("Enter value to delete: ");
            scanf("%d", &key);
            delete_value(key);
            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }
}
