#include <stdio.h>
#include <stdbool.h>
#include "linkedlist.h"
#include "create.h"
#include "insert.h"
#include "other.h"

int main(void) 
{
    struct Node *head = NULL, *tail = NULL;
    int ch = 0;

    while (true)
    {
        printf("\n---------------------------------");
        printf("\n   Operations on a linked list");
        printf("\n---------------------------------");
        printf("\n1. Insert node at beginning");
        printf("\n2. Insert node at end");
        printf("\n3. Insert node at a specific position");
        printf("\n4. Delete Node from any Position");
        printf("\n5. Update Node Value");
        printf("\n6. Search Element in the linked list");
        printf("\n7. Display List");
        printf("\n8. Exit");
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\n   Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
		case 1:
		    insertNodeAtTheBeginning(&head, &tail);
		    break;
		case 2:
		    insertNodeAtTheEnd(&head, &tail);
		    break;
		case 3:
		    insertNodeAtPosition(&head, &tail);
		    break;
		case 4:
		    deletePosition(&head, &tail);
		    break;
		case 5:
		    updateValue(head);
		    break;
		case 6:
		    search(head);
		    break;
		case 7:
		    display(head);
		    break;
		case 8:
		    printf("\n...Exiting...\n");
		    return 0;
		default:
		    printf("\n...Invalid Choice...\n");
		    break;
		}
    }
    return 0;
 }