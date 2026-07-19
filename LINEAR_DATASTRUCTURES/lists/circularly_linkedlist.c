#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*head;

void display()
{
    struct Node *temp = head ->next;
    if (temp == NULL)
    {
        printf("List is empty \n");
        return;
    }
    do
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    } while (temp != head->next);
    
printf("(back to %d)\n",temp->data);

printf("\n");
}

void insfirst(int val)
{
    struct Node *newnode = malloc(sizeof(struct Node));
    newnode -> data = val;
    if (head -> next == NULL)
    {
        head -> next = newnode;
        newnode -> next = newnode;
    }
    else{
        struct Node *temp = head -> next;
        while(temp -> next != head -> next)
        {
            temp = temp -> next;
        }
        temp -> next = newnode;
        newnode -> next = head -> next;
        head->next = newnode;
    }
    printf("\n");
    display();
}

void inslast(int val)
{
    struct Node *newnode = malloc(sizeof(struct Node));
    newnode -> data = val;
    if (head -> next == NULL)
    {
        head -> next = newnode;
        newnode -> next = newnode;
    }
    else{
        struct Node *temp = head -> next;
        while (temp -> next != head -> next){
            temp = temp -> next;
        }
        temp -> next = newnode;
        newnode -> next = head -> next;
    }
    display();
    printf("\n");
}

void circularly_linked()
{
    head = malloc(sizeof(struct Node));
    struct Node *first = malloc(sizeof(struct Node));
    first -> data = 10;
    head -> next = first;
    struct Node *second = malloc(sizeof(struct Node));
    second -> data = 20;
    first -> next = second;
    struct Node *third = malloc(sizeof(struct Node));
    third -> data = 30;
    second -> next = third;
    third -> next = first;
    display();
    insfirst(5);
    inslast(100);
}