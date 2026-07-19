#include <stdio.h>

#include "array_list.h"
#include "singly_linkedlist.h"
#include "doubly_linkedlist.h"
#include "circularly_linked.h"

int main()
{
    int ch;

    do
    {
        printf("\n===== LINEAR DATA STRUCTURES =====\n");
        printf("1. Array\n");
        printf("2. Singly Linked List\n");
        printf("3. Doubly Linked List\n");
        printf("4. Circular Linked List\n");
        printf("5. Exit\n");

        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                array_list();
                break;

            case 2:
                singly_linked();
                break;

            case 3:
                doubly_linked();
                break;

            case 4:
                circularly_linked();
                break;

            case 5:
                printf("Thank you!\n");
                break;

            default:
                printf("Invalid choice");
        }

    }while(ch!=5);

    return 0;
}



