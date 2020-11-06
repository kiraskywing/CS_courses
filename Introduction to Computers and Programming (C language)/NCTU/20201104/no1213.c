#include <stdio.h>

void initialize(int arr[], int temp[], int n);
void dfs(int arr[], int temp[], int n, int count);

int main(void)
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        int arr[n], temp[n];
        initialize(arr, temp, n);
        dfs(arr, temp, n, 0);
    }
    
    return 0;
}

void initialize(int arr[], int temp[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = 0; 
        temp[i] = 0;
    }
}

void dfs(int arr[], int temp[], int n, int count)
{
    if (count == n)
    {
        for (int j = 0; j < count; j++)
            printf("%d", temp[j]);
        printf("\n");
        return;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            temp[count] = i + 1;
            arr[i] = 1;
            dfs(arr, temp, n, count + 1);
            arr[i] = 0;
            temp[count] = 0;
        }
    }
}