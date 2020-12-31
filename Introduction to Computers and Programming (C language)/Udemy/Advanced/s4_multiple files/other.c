#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "create.h"

void deletePosition(struct Node **head, struct Node **tail)
{
    int pos, count = 1;

    if (!head)
    {
        puts("List is empty");
        return;
    }
    
    printf("Enter the position of value to be deleted: ");
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
        prev->next = cur->next;
        free(cur);
        *head = dummy->next;
        if (!(*tail))
            *tail = prev->next;
        puts("Element deleted");
    }
    else
        puts("Position is out of range");
    free(dummy);
}

void updateValue(struct Node *head)
{
    int oldval, newval;

    if (!head)
    {
        puts("List is empty");
        return;
    }
    
    printf("Enter the value to be updated: ");
    scanf("%d", &oldval);
    printf("Enter the new value: ");
    scanf("%d", &newval);
    
    while (head)
    {
        if (head->value == oldval)
        {
            head->value = newval;
            puts("Updated Successfully");
            return;
        }
        head = head->next;
    }
    
    puts("Value not found in List");
}

void search(struct Node *head)
{
    int key, pos = 0;

    if (!head)
    {
        puts("List is empty");
        return;
    }
    
    printf("Enter the value to search ");
    scanf("%d", &key);
    while (head)
    {
        pos++;
        if (head->value == key)
        {
            printf("Element %d found at %d position\n", key, pos);
            return;
        }
        head = head->next;
    }
    
    printf("Element %d not found in list\n", key);
}

void display(struct Node *head)
{
    if (!head)
    {
        puts("List is empty");
        return;
    }
    while (head)
    {
        printf("%d ", head->value);
        head = head->next;
    }
    puts("");
}