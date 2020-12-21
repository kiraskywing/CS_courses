#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    int n_len;
    int *neighbor;
};

void create_graph(struct node *nodes[], int n_num, int e_num);
void connect(struct node *nodes[], int n1, int n2);
void judge(struct node *nodes[]);

int main(void)
{
    int n_num, e_num;
    scanf("%d %d", &n_num, &e_num);
    struct node *nodes[n_num];
    create_graph(nodes, n_num, e_num);
    judge(nodes);

    return 0;
}

void create_graph(struct node *nodes[], int n_num, int e_num)
{
    for (int i = 0; i < n_num; i++)
    {
        struct node *new = malloc(sizeof(struct node));
        new->val = i;
        new->n_len = 0;
        new->neighbor = NULL;
        nodes[i] = new;
    }

    int n1, n2;
    for (int i = 0; i < e_num; i++)
    {
        scanf("%d %d", &n1, &n2);
        connect(nodes, n1, n2);
        connect(nodes, n2, n1);
    }
}

void connect(struct node *nodes[], int n1, int n2)
{
    nodes[n1]->n_len++;
    int len = nodes[n1]->n_len;
    nodes[n1]->neighbor = realloc(nodes[n1]->neighbor, len * sizeof(int));
    nodes[n1]->neighbor[len - 1] = n2;
}

void judge(struct node *nodes[])
{
    
}