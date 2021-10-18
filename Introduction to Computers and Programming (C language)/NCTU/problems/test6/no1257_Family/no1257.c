#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct person
{
    char name[30];
    bool related;
    int rank, n_elder, n_younger;
    struct person *elders[60], *youngers[60];
};

struct person* SearchAdd(char *p, struct person *list[], int *count);
void connect(struct person *c, struct person *p);
void update_rank(struct person *p, int rank);
void judge(struct person *list[], int count);
void clear_list(struct person *list[], int count);

int main(void)
{
    int n;
    scanf("%d", &n);
    struct person *list[n * 2];
    int count = 0;
    SearchAdd("Dong", list, &count);

    while (n--)
    {
        char child[30], parent[30];
        scanf("%s %s", child, parent);
        struct person *c = SearchAdd(child, list, &count);
        struct person *p = SearchAdd(parent, list, &count);
        connect(c, p);
    }
    
    update_rank(list[0], 0);
    judge(list, count);
    clear_list(list, count);

    return 0;
}

struct person* SearchAdd(char *p, struct person *list[], int *count)
{
    for (int i = 0; i < *count; i++)
    {
        if (strcmp(list[i]->name, p) == 0)
            return list[i];
    }

    struct person *new = (struct person*) malloc(sizeof(struct person));
    strcpy(new->name, p);
    new->related = false;
    new->n_elder = new->n_younger = 0;
    list[(*count)++] = new;
    
    return new;
}

void connect(struct person *c, struct person *p)
{
    c->elders[c->n_elder++] = p;
    p->youngers[p->n_younger++] = c;
}

void update_rank(struct person *p, int rank)
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

void judge(struct person *list[], int count)
{
    for (int i = 1; i < count; i++)
    {
        printf("%s ", list[i]->name);
        if (!list[i]->related)
            puts("unknown");
        else
        {
            if (list[i]->rank > 0)
                puts("elder");
            else if (list[i]->rank < 0)
                puts("younger");
            else
                puts("same");
        }
    }
}

void clear_list(struct person *list[], int count)
{
    for (int i = 1; i < count; i++)
        free(list[i]);
}