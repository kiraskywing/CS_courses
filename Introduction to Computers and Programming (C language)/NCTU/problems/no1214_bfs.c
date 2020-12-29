#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct QNode
{
    int i, j, steps;
    struct QNode *next;
};

struct QNode* AddNode(int i, int j, int steps);

int main(void)
{
    int m, n, s_i, s_j;
    scanf("%d %d", &m, &n);
    int arr[m][n];
    bool visited[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = false;
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == -2)
            {
                s_i = i;
                s_j = j;
            }
        }
    }

    int di[] = {-1, 1, 0 ,0}, dj[] = {0, 0, 1, -1};
    struct QNode *head = AddNode(s_i, s_j, 0);
    struct QNode *tail = head;
    visited[s_i][s_j] = true;

    while (head)
    {
        if (arr[head->i][head->j] == -3)
        {
            printf("%d", head->steps);
            break;
        }
        
        for (int k = 0; k < 4; k++)
        {
            int i2 = head->i + di[k];
            int j2 = head->j + dj[k];
            if (0 <= i2 && i2 <= m - 1 && 0 <= j2 && j2 <= n - 1 && !visited[i2][j2] && (arr[i2][j2] == 0 || arr[i2][j2] == -3))
            {
                visited[i2][j2] = true;
                tail->next = AddNode(i2, j2, head->steps + 1);
                tail = tail->next;
            }
        }

        struct QNode *prev = head;
        head = head->next;
        free(prev);
    }

    return 0;
}

struct QNode* AddNode(int i, int j, int steps)
{
    struct QNode *new = (struct QNode*) malloc(sizeof(struct QNode));
    new->i = i;
    new->j = j;
    new->steps = steps;
    new->next = NULL;
    return new;
};
