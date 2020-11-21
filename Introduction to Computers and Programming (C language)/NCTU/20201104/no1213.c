#include <stdio.h>

void init(int temp[], int visited[], int n);
void helper(int temp[], int visited[], int n, int count);

int main(void)
{
    int times, n;
    scanf("%d", &times);
    while (times--)
    {
        scanf("%d", &n);
        int count = 0, temp[n], visited[n];
        init(temp, visited, n);
        helper(temp, visited, n, count);
    }

    return 0;
}

void init(int temp[], int visited[], int n)
{
    for (int i = 0; i < n; i++)
    {
        temp[i] = 0;
        visited[i] = 0;
    }
}

void helper(int temp[], int visited[], int n, int count)
{
    if (count == n)
    {
        for (int i = 0; i < n; i++)
            printf("%d", temp[i]);
        printf("\n");
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i] != 1)
        {
            visited[i] = 1;
            temp[count] = i + 1;
            helper(temp, visited, n, count + 1);
            temp[count] = 0;
            visited[i] = 0;
        }
    }
}