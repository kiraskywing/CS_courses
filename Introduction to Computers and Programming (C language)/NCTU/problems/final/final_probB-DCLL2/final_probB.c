#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int val;
    struct Node *left, *right;
};

struct Node *tail = NULL;

void AddNode(int val);
void Del(void);

int main(void)
{
    AddNode(1);

    int times;
    scanf("%d", &times);
    while (times--)
    {
        char op[7];
        scanf("%s", op);
        if (strcmp(op, "WHAT") == 0)
            printf("%d\n", tail->val);
        else if (strcmp(op, "INSERT") == 0)
        {
            int val;
            scanf("%d", &val);
            AddNode(val);
        }
        else if (strcmp(op, "LEFT") == 0)
            tail = tail->left;
        else if (strcmp(op, "RIGHT") == 0)
            tail = tail->right;
        else if (strcmp(op, "DELETE") == 0)
            Del();
    }

    return 0;
}

void AddNode(int val)
{
    struct Node *head, *new = (struct Node*) malloc(sizeof(struct Node));
    new->val = val;

    if (!tail)
        head = tail = new;
    else
        head = tail->right;

    tail->right = new;
    new->left = tail;

    new->right = head;
    head->left = new;
}

void Del(void)
{
    struct Node *prev = tail->left;
    struct Node *cur = tail;
    tail = tail->right;

    prev->right = tail;
    tail->left = prev;
    free(cur);
}
