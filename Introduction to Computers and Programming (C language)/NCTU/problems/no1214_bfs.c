#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int i, j, steps;
    struct Node *next;
};

void init_arr(int *arr, int *visited, int m, int n, int *i_start, int *j_start);
void bfs(int *arr, int *visited, int m, int n, int i_start, int j_start);
int pos_valid(int i, int j, int *arr, int *visited, int m, int n);
struct Node* AddNode(int i, int j, int steps);

int main(void)
{
    int m, n;
    scanf("%d %d", &m, &n);
    int arr[m][n], visited[m][n], i_start, j_start;
    init_arr(&arr[0][0], &visited[0][0], m, n, &i_start, &j_start);
    bfs(&arr[0][0], &visited[0][0], m, n, i_start, i_start);
    
    return 0;
}

void init_arr(int *arr, int *visited, int m, int n, int *i_start, int *j_start)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            *(visited + i * n + j) = 0;
            scanf("%d", arr + i * n + j);
            if (*(arr + i * n + j) == -2)
            {
                *i_start = i;
                *j_start = j;
            }
        }
    }
}

void bfs(int *arr, int *visited, int m, int n, int i_start, int j_start)
{
    struct Node *head = AddNode(i_start, j_start, 0);
    struct Node *tail = head;
    *(visited + i_start * n + j_start) = 1;

    int di[] = {-1, 1, 0, 0}, dj[] = {0, 0, 1, -1};

    while (head)
    {
        int i = head->i, j = head->j, steps = head->steps;
        if (*(arr + i * n + j) == -3)
        {
            printf("%d", steps);
            return;
        }

        for (int k = 0; k < 4; k++)
        {
            int i2 = i + di[k], j2 = j + dj[k];
            if (pos_valid(i2, j2, arr, visited, m, n))
            {
                *(visited + i2 * n + j2) = 1;
                tail->next = AddNode(i2, j2, steps + 1);
                tail = tail->next;
            }
        }

        struct Node *prev = head;
        head = head->next;
        free(prev);
    }
}

int pos_valid(int i, int j, int *arr, int *visited, int m, int n)
{
    if (i < 0 || i > m - 1 || j < 0 || j > n - 1)
        return 0;
    if (*(visited + i * n + j) || *(arr + i * n + j) == -1)
        return 0;
    return 1;
}

struct Node* AddNode(int i, int j, int steps)
{
    struct Node *new = (struct Node*) malloc(sizeof(struct Node));
    new->i = i;
    new->j = j;
    new->steps = steps;
    new->next = NULL;
    return new;
}