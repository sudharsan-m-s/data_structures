#include <stdio.h>

int n = 5, size = 6;
int array[6] = {1, 2, 3, 4, 5};

void insert(int pos, int value) {
    int i;

    if (n < size && pos <= n) 
    {
        for (i = n - 1; i >= pos; i--)
        {
            array[i + 1] = array[i];
        }
        array[pos] = value;
        n= n + 1;
    } else 
    {
        printf("List is full or invalid position\n");
    }
}

void delete(int value) {
    int i, pos = -1;

    if (n == 0) {
        printf("List is Empty\n");
        return;
    }

    for (i = 0; i < n; i++) 
    {
        if (array[i] == value) 
        {
            pos = i;
            break;
        }
    }

    if (pos == -1) 
    {
        printf("Element not found\n");
        return;
    }

    for (i = pos; i < n - 1; i++)
       array[i] = array[i + 1];

    n--;
}

void search(int value) {
    int i;

    if (n == 0) {
        printf("List is Empty\n");
        return;
    }

    for (i = 0; i < n; i++) {
        if (array[i] == value) {
            printf("Element found at position %d\n", i);
            return;
        }
    }

    printf("Element not found\n");
}

void display() {
    int i;

    if (n == 0) {
        printf("List is Empty\n");
        return;
    }

    printf("Array: ");
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void array_list() {
    int choice = 0, pos, value;

    while (choice != 5) {
        printf("\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter position and value: ");
                scanf("%d%d", &pos, &value);
                insert(pos, value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete(value);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}