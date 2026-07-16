#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next, *prev;
}*first ;

void display()
{
    struct Node *temp = first;
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

int main()
{
    first = malloc(sizeof(struct Node));
    first -> data = 10;
    first -> prev = NULL;
    struct Node *second = malloc(sizeof(struct Node));
    first -> next = second;
    second -> prev = first;
    second -> data = 20;
    second -> next = NULL;
    display();
}