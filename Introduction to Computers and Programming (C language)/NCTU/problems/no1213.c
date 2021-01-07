#include <stdio.h>

void dfs(int visited[], int res[], int n, int count);

int main(void)
{
    int times, n;
    scanf("%d", &times);
    while (times--)
    {
        scanf("%d", &n);
        int res[n], visited[n];
        for (int i = 0; i < n; i++)
            visited[i] = 0;
        
        dfs(visited, res, n, 0);
    }
    
    return 0;
}

void dfs(int visited[], int res[], int n, int count)
{
    if (count == n)
    {
        for (int i = 0; i < n; i++)
            printf("%d", res[i]);
        puts("");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            res[count] = i + 1;
            dfs(visited, res, n, count + 1);
            visited[i] = 0;
        }
    }
}