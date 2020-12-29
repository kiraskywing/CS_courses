#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int val;
    struct Node *right, *left;
};

struct Node *head = NULL, *tail = NULL;
void AddNode(int val);

int main(void)
{
    AddNode(1);
    int times;
    scanf("%d", &times);
    while (times--)
    {
        char input[7] = "";
        scanf("%s", input);

        if (strcmp(input, "WHAT") == 0)
            printf("%d\n", tail->val);
        else if (strcmp(input, "INSERT") == 0)
        {
            int val;
            scanf("%d", &val);
            AddNode(val);
        }
        else if (strcmp(input, "LEFT") == 0)
            tail = tail->left;
        else if (strcmp(input, "RIGHT") == 0)
            tail = tail->right;
    }

    return 0;
}

void AddNode(int val)
{
    struct Node *new = (struct Node*) malloc(sizeof(struct Node));
    new->val = val;

    if (!head)
        head = tail = new;
    else
        head = tail->right;

    new->right = head;
    new->left = tail;

    head->left = new;
    tail->right = new;

    head = new;
}
