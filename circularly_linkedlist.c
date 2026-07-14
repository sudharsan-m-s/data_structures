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
    display();
    printf("\n");
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

void insspecific(int s, int val)
{
    struct Node *newnode = malloc(sizeof(struct Node));
    newnode -> data = val;
    struct Node *temp = head -> next;
    while(temp-> next != head -> next && temp-> data != s)
    {
        temp = temp -> next;
    }
    if (temp -> data == s)
    {
        newnode -> next = temp -> next;
        temp ->  next = newnode;
        display();
        printf("\n");
    }
    else {
        printf("Element not found!");
        printf("\n");
    }
}
void delete(int val)
{
    struct Node *temp = head -> next , *prev;
    while(temp-> next != head -> next && temp-> data != val)
    {
        prev = temp;
        temp = temp -> next;
    }
    if (temp-> data == val)
    {
        prev -> next = temp -> next;
        free(temp);
        display();
        printf("\n");
    }
    else{
        printf("Element not found!");
    }

}

void search (int val)
{
    struct Node *temp = head -> next;
    while (temp -> next != head -> next && temp -> data != val)
    {
        temp =temp -> next;
    }
    if (temp ->data == val)
    {
        printf("Element found!");
        printf("\n");
    }
    else{
        printf("Element not found!");
        printf("\n");
    }
}

int main()
{
    int choice = 0, s, val;
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
    while (choice != 7)
    {
    printf("\n1.Insert First\n2.Insert Last\n3.Insert After Specified Element\n4.Delete\n5.Search\n6.Display\n7.Exit\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
    
    switch (choice){
        case 1:
        printf("Enter value to be inserted: ");
        scanf("%d",&val);
        insfirst(val);
        break;

        case 2:
        printf("Enter value to be inserted: ");
        scanf("%d",&val);
        inslast(val);
        break;

        case 3:
        printf("Enter the specifying element: ");
        scanf("%d",&s);
        printf("Enter value to be inserted: ");
        scanf("%d",&val);
        insspecific(s,val);
        break;

        case 4:
        printf("Enter value to be deleted: ");
        scanf("%d",&val);
        delete(val);
        break;

        case 5:
        printf("Enter value to be searched: ");
        scanf("%d",&val);
        search(val);
        break;

        case 6:
        display();
        break;

        case 7:
        printf("Exiting...");
        break;

        default:
        printf("Invalid choice..");
    }
}
}

