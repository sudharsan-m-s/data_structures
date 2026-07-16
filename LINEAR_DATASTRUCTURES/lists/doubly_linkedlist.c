#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next, *prev;
}*head ;

void display()
{
    struct Node *temp = head -> next;
    while (temp != NULL)
    {
        printf("%d",temp->data);
        if (temp -> next != NULL)
        {
            printf(" <-> ");
        }
        temp = temp-> next;
    }
    printf("\n");
}

void insfirst(int val)
{
    struct Node *newnode = malloc(sizeof(struct Node));
    newnode -> data = val;
    struct Node *temp = head -> next;
    if (temp == NULL)
    {
        head -> next = newnode;
        newnode -> prev = head;
        newnode -> next = NULL;
    }
    else{
        newnode -> next = head ->next;
        temp -> prev = newnode ;
        newnode -> prev = head;
        head -> next = newnode;
    }
    display();
    printf("\n");
}

void inslast(int val)
{
    struct Node *newnode = malloc(sizeof(struct Node));
    newnode -> data = val;
    struct Node *temp = head -> next;
    if (temp == NULL)
    {
        head -> next = newnode;
        newnode -> prev = head;
        newnode -> next = NULL;
    }
    else{
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        newnode -> next = NULL;
        newnode -> prev = temp;
        temp -> next = newnode;
    }
    display();
    printf("\n");
}

int main()
{
    head = malloc(sizeof(struct Node));
    head -> next =NULL;
    head -> prev =NULL;
    insfirst(5);
    insfirst(4);
    insfirst(3);
    inslast(6);
    inslast(7);
}