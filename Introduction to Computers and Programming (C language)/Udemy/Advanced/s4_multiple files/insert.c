#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "create.h"

void insertNodeAtTheBeginning(struct Node **head, struct Node **tail)
{
    int val = 0;

    printf("Enter the value for the node: ");
    scanf("%d", &val);
    struct Node *new = createNode(val);
    
    if (!(*head))
    {
        *head = *tail = new;
        (*head)->next = (*tail)->next = NULL;
    }
    else
    {
        new->next = *head;
        *head = new;
    }

    puts("----INSERTED----");
}

void insertNodeAtTheEnd(struct Node **head, struct Node **tail)
{
    int val = 0;

    printf("Enter the value for the Node: ");
    scanf("%d", &val);
    struct Node *new = createNode(val);
    
    if (!(*tail))
    {
        *head = *tail = new;
        (*head)->next = (*tail)->next = NULL;
    }
    else
    {
        (*tail)->next = new;
        *tail = new;
        (*tail)->next = NULL;
    }

    puts("----INSERTED----");
}

void insertNodeAtPosition(struct Node **head, struct Node **tail)
{
    int pos, val, count = 1;

    printf("Enter the value for the Node: ");
    scanf("%d", &val);
    struct Node *new = createNode(val);
    printf("Enter the position ");
    scanf("%d", &pos);
    
    struct Node *dummy = createNode(-1);
    dummy->next = *head;
    struct Node *prev = dummy;
    struct Node *cur = dummy->next;
    
    while (cur && count < pos)
    {
        prev = prev->next;
        cur = cur->next;
        count++;
    }
    
    if (count == pos)
    {
        prev->next = new;
        new->next = cur;
        *head = dummy->next;
        if (!(*tail))
            *tail = *head;
        puts("----INSERTED----");
    }
    else
    {
        puts("Position is out of range");
        free(new);
    }
    free(dummy);
}