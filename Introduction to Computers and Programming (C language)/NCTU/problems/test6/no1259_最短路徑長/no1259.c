#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Vertex
{
    int val;
    int n_neighbor;
    int *neighbors;
    bool visited;
};

struct QNode
{
    int val, steps;
    struct QNode *next;
};

void create_graph(struct Vertex *vertices[], int n_v, int n_e);
void connect(struct Vertex *vertices[], int v1, int v2);
void get_res(struct Vertex *vertices[]);
struct QNode* AddNode(int val, int steps);
void clear_vertices(struct Vertex *vertices[], int n_v);

int main(void)
{
    int n_v, n_e;
    scanf("%d %d", &n_v, &n_e);
    struct Vertex *vertices[n_v];
    
    create_graph(vertices, n_v, n_e);
    get_res(vertices);

    clear_vertices(vertices, n_v);

    return 0;
}

void create_graph(struct Vertex *vertices[], int n_v, int n_e)
{
    for (int i = 0; i < n_v; i++)
    {
        vertices[i] = (struct Vertex*) malloc(sizeof(struct Vertex));
        vertices[i]->val = i;
        vertices[i]->n_neighbor = 0;
        vertices[i]->neighbors = (int *) malloc(sizeof(int) * (n_v - 1));
        vertices[i]->visited = false;
    }

    int v1, v2;
    for (int i = 0; i < n_e; i++)
    {
        scanf("%d %d", &v1, &v2);
        connect(vertices, v1, v2);
    }
}
void connect(struct Vertex *vertices[], int v1, int v2)
{
    vertices[v1]->neighbors[vertices[v1]->n_neighbor++] = v2;
    vertices[v2]->neighbors[vertices[v2]->n_neighbor++] = v1;
}

void get_res(struct Vertex *vertices[])
{
    int start, end;
    scanf("%d %d", &start, &end);

    struct QNode *head = AddNode(start, 0);
    struct QNode *tail = head;

    while (head)
    {
        if (head->val == end)
        {
            printf("%d\n", head->steps);
            return;
        }

        struct Vertex *cur = vertices[head->val];
        int n = cur->n_neighbor;
        cur->visited = true;
        
        for (int i = 0; i < n; i++)
        {
            int neighbor = cur->neighbors[i];
            if (!vertices[neighbor]->visited)
            {
                tail->next = AddNode(neighbor, head->steps + 1);
                tail = tail->next;
            }
        }

        struct QNode *prev = head;
        head = head->next;
        free(prev);
    }

    puts("Oops");
}

struct QNode* AddNode(int val, int steps)
{
    struct QNode *new = (struct QNode*) malloc(sizeof(struct QNode));
    new->val = val;
    new->steps = steps;
    new->next = NULL;
    return new;
}

void clear_vertices(struct Vertex *vertices[], int n_v)
{
    for (int i = 0; i < n_v; i++)
        free(vertices[i]);
}