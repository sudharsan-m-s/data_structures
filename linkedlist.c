#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
}*head;

void display()
{
    struct Node* temp = head -> next;
    while (temp != NULL)
{
    printf("%d", temp->data);

    if (temp->next != NULL)
        printf(" -> ");

    temp = temp->next;
}
}

void insfirst(int val)
{
    struct Node* newnode = malloc(sizeof(struct Node));
    newnode ->data =  val;
    newnode ->next = head ->next;
    head -> next = newnode;
    display();
}

void inslast(int val)
{
    struct Node* newnode =  malloc(sizeof(struct Node));
    newnode -> data = val;
    struct Node* temp = head-> next;
    while(temp->next != NULL){
        temp = temp -> next;
    }
    temp -> next = newnode;
    newnode -> next = NULL;
    display();
}


int main() {
    head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* first = (struct Node*)malloc(sizeof(struct Node));
    head->next = first;
    first->data = 10;
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    first->next = second;
    second->data = 20;
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    second->next = third;
    third->data = 30;
    third->next =  NULL;
    insfirst(100);
    printf("\n");
    inslast(200);

    
    return 0;
}
