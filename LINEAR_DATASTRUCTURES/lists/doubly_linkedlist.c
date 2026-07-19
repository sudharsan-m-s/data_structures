#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next; 
    struct Node *prev;
}*head ;

void dll_display()
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

void dll_insfirst(int val)
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

void dll_inslast(int val)
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

void dll_insspecific(int s, int val)
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

void dll_del(int val)
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

void dll_search (int val)
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
void dll_doubly_linked()
{
    head = malloc(sizeof(struct Node));
    head -> prev = NULL;
    head -> next = NULL;
    int choice = 0, s, val;
    while(choice != 7)
    {
        printf("\n1.Insert First\n2.Insert Last\n3.Insert After Specified Element\n4.Delete\n5.Search\n6.Display\n7.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter value to be inserted: ");
            scanf("%d",&val);
            dll_insfirst(val);
            break;

            case 2:
            printf("Enter value to be inserted: ");
            scanf("%d",&val);
            dll_inslast(val);
            break;

            case 3:
            printf("Enter the searching element: ");
            scanf("%d",&s);
            printf("Enter value to be inserted: ");
            scanf("%d",&val);
            dll_insspecific(s,val);
            break;

            case 4:
            printf("Enter the element to be deleted: ");
            scanf("%d",&val);
            dll_del(val);
            break;

            case 5:
            printf("Enter the element to be searched: ");
            scanf("%d",&val);
            dll_search(val);
            break;

            case 6:
            printf("Doubly-Linked List : ");
            dll_display();
            break;

            case 7:
            printf("Exiting...");
            break;

            default :
            printf("Invalid Choice");

        }
    }
}