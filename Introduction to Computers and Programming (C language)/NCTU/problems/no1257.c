#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Node
{
    char name[30];
    bool related;
    int rank, n_elder, n_younger;
    struct Node *elders[30], *youngers[30];
};

struct Node* search_add(char *s, struct Node *list[], int *count);
void connect(struct Node *child, struct Node *parent);
void update_rank(struct Node *p, int rank);
void judge(struct Node *list[], int count);
void clear_list(struct Node *list[], int count);

int main(void)
{
    int n, count = 0;
    scanf("%d", &n);
    
    struct Node *list[30];
    search_add("Dong", list, &count);
    char S[30] = "", T[30] = "";

    while (n--)
    {
        scanf("%s %s", S, T);
        struct Node *child = search_add(S, list, &count);
        struct Node *parent = search_add(T, list, &count);
        connect(child, parent);
    }

    update_rank(list[0], 0);
    judge(list, count);
    clear_list(list, count);

    return 0;
}

struct Node* search_add(char *s, struct Node *list[], int *count)
{
    for (int i = 0; i < *count; i++)
    {
        if (strcmp(list[i]->name, s) == 0)
            return list[i];
    }

    struct Node *new = (struct Node*) malloc(sizeof(struct Node));
    strcpy(new->name, s);
    new->related = false;
    new->n_elder = new->n_younger = 0;
    
    list[(*count)++] = new;
    return new;
}

void connect(struct Node *child, struct Node *parent)
{
    child->elders[child->n_elder++] = parent;
    parent->youngers[parent->n_younger++] = child;
}

void update_rank(struct Node *p, int rank)
{
    if (p->related)
        return;
    
    p->related = true;
    p->rank = rank;

    for (int i = 0; i < p->n_elder; i++)
        update_rank(p->elders[i], rank + 1);
    for (int i = 0; i < p->n_younger; i++)
        update_rank(p->youngers[i], rank - 1);
}

void judge(struct Node *list[], int count)
{
    for (int i = 1; i < count; i++)
    {
        if (!list[i]->related)
            printf("%s %s\n", list[i]-> name, "unknown");
        else
        {
            if (list[i]->rank == 0)
                printf("%s %s\n", list[i]->name, "same");
            else
                printf("%s %s\n", list[i]->name, list[i]->rank > 0 ? "elder" : "younger");
        }
    }
}

void clear_list(struct Node *list[], int count)
{
    for (int i = 0; i < count; i++)
        free(list[i]);
}