#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node
{
    char name[30];
    int level;
    bool checked;
    struct node *parent;
    struct node *child;
};

struct node *ptr[30];
int idx = 1;

void Dong_init(void);
struct node* list_check(char *s);
void connect(struct node *c, struct node *p);
void update_level(struct node *cur);
void judge(struct node *cur);

int main(void)
{
    int n;
    scanf("%d", &n);
    Dong_init();
    char s1[30] = "", s2[30] = "";
    
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s", s1, s2);
        struct node *n1 = list_check(s1);
        struct node *n2 = list_check(s2);
        connect(n1, n2);
    }

    for (int i = 1; i < idx; i++)
        update_level(ptr[i]);
    for (int i = 1; i < idx; i++)
        judge(ptr[i]);

    return 0;
}

void Dong_init(void)
{
    ptr[0] = (struct node *) malloc(sizeof(struct node));
    strcpy(ptr[0]->name, "Dong");
    ptr[0]->level = 0;
    ptr[0]->checked = true;
    ptr[0]->parent = NULL;
    ptr[0]->child = NULL;
}

struct node* list_check(char *s)
{
    if (strcmp(s, "Dong") == 0)
        return ptr[0];
    for (int i = 1; i < idx; i++)
    {
        if (strcmp(s, ptr[i]->name) == 0)
            return ptr[i];
    }

    struct node *new = malloc(sizeof(struct node));
    strcpy(new->name, s);
    new->checked = false;
    new->parent = NULL;
    new->child = NULL;
    
    ptr[idx] = new;
    idx++;
    return ptr[idx - 1];
}

void connect(struct node *c, struct node *p)
{
    c->parent = p;
    p->child = c;

    if (c->checked)
    {
        p->checked = true;
        p->level = c->level + 1;
    }
    else if (p->checked)
    {
        c->checked = true;
        c->level = p->level - 1;
    }
}

void update_level(struct node *cur)
{
    struct node *temp;
    
    temp = cur;
    while (temp->checked && temp->child && !temp->child->checked)
    {
        temp->child->checked = true;
        temp->child->level = temp->level - 1;
        temp = temp->child;
    }
    temp = cur;
    while (temp->checked && temp->parent && !temp->parent->checked)
    {
        temp->parent->checked = true;
        temp->parent->level = temp->level + 1;
        temp = temp->parent;
    }
}

void judge(struct node *cur)
{
    if (!cur->checked)
        printf("%s %s\n", cur->name, "unknown");
    else
    {
        if (cur->level > 0)
            printf("%s %s\n", cur->name, "elder");
        else
            printf("%s %s\n", cur->name, cur->level == 0 ? "same" : "younger");
    }
}