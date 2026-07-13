#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
}
*head;

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
printf("\n");
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

void insspecific(int s,int val)
{
    struct Node* newnode = malloc(sizeof(struct Node));
    newnode ->data = val;
    struct Node* temp = head -> next;
    while(temp -> data != s && temp -> next != NULL)
    {
        temp = temp -> next;
    }
    if (temp-> data == s)
    {
        newnode ->next = temp -> next;
        temp ->next = newnode;
    }
    else{
        printf("Element not found! \n");
    }
    display();
}

void del(int val)
{
    struct Node* temp = head-> next, *prev;
    while(temp->data != val && temp->next != NULL)
    {
        prev = temp;
        temp = temp-> next;
    }
    if (temp->data== val){
        prev -> next = temp-> next;
        free(temp);
    }
    else{
        printf("Element not found! \n");
    }
    display();
}

void search(int val)
{
    struct Node* temp = head -> next;
    while(temp->data != val && temp->next != NULL){
        temp = temp -> next;
    }
    if(temp->data == val){
        printf("Element found ! \n",temp);
    }else{
        printf("Element not found! \n");
    }
}


int main() {
    int choice = 0, s , val;
    //linkedlist declaration
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

    // user choice display
    while(choice != 7){
    printf("\n1.Insert First\n2.Insert Last\n3.Insert After Specified Element\n4.Delete\n5.Search\n6.Display\n7.Exit\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
    
    //switch case
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
        del(val);

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
        break;

        default:
        printf("Invalid choice..");
    }
}
}
