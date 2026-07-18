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

void insspecific(int s, int val)
{
    struct Node *newnode = malloc(sizeof(struct Node));
    newnode -> data = val;
    struct Node *temp = head -> next;
    if (temp == NULL)
    {
        printf("Empty is list");
        free(newnode);
    }else{
        while(temp-> next != NULL && temp -> data != s)
        {
            temp = temp -> next;
        }
        if(temp != NULL)
        {
            newnode -> next = temp -> next;
            newnode -> prev = temp;
            if (temp->next != NULL)
            {
            temp->next->prev = newnode;
            }
            temp -> next = newnode;
            display();
            printf("\n"); 
        }
        else{
            printf("Element not found!");
            free(newnode);
        }
    }
}

void del(int val)
{
    struct Node *temp = head -> next;
    if (temp == NULL)
    {
        printf("Empty list!");
    }else {
    while(temp != NULL && temp-> data != val)
    {
        temp = temp-> next;
    }
    if(temp != NULL)
    {
        temp -> prev -> next = temp -> next;
        if (temp-> next != NULL)
        {
            temp -> next -> prev = temp -> prev;
        }
        free(temp);
        display();
        printf("\n");
    }
    else{
        printf("Element not found");
    }
}
}

void search (int val)
{
    struct Node *temp = head -> next;
    if(temp == NULL)
    {
        printf("List is empty");
    }else{
    while(temp!= NULL && temp-> data != val)
    {
        temp = temp -> next;
    }
    if(temp!=NULL)
    {
        printf("The element %d found!",val);
    }else{
        printf("Element not found");
    }
}
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
    insspecific(3,8);
    del(3);
    search(5);
}