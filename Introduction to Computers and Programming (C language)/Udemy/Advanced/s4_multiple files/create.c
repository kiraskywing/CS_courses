#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

struct Node* createNode(int val)
{
    struct Node *new = (struct Node *) malloc(sizeof(struct Node));
    if (!new)
    {
        puts("Memory was not allocated");
        return NULL;
    }
    
    new->value = val;
    new->next = NULL;
    return new;
}