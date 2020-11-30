#include <stdio.h>

void dfs(int visited[], int n, int start, int temp[], int used);

int main(void)
{
    int times;
    scanf("%d", &times);

    while (times--)
    {
        int n;
        scanf("%d", &n);
        int visited[n + 1], temp[n];
        for (int i = 1; i <= n; i++)
            visited[i] = 0;

        dfs(visited, n, 1, temp, 0);
    }
    
    return 0;
}

void dfs(int visited[], int n, int start, int temp[], int used)
{
    if (used == n)
    {
        for (int i = 0; i < n; i++)
            printf("%d", temp[i]);
        printf("\n");
        return;
    }

    for (int i = start; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            temp[used] = i;
            dfs(visited, n, 1, temp, used + 1);
            visited[i] = 0;
            temp[used] = 0;
        }
    }
}