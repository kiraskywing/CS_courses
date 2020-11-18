#include <stdio.h>

int sol_check;
void dfs(int arr[], int visited[], int target, int count, int start, int remain);

int main(void)
{
    int times;
    scanf("%d", &times);

    while (times--)
    {
        int target, cur = 1000, arr[1000] = {0}, visited[1000] = {0}, count = 0;
        
        scanf("%d", &target);
        while (cur)
        {
            scanf("%d", &cur);
            arr[count] = cur;
            count++;
        }
        count--;
        
        sol_check = 0;
        dfs(arr, visited, target, count, 0, 20);
        
        if (sol_check)
            printf("finish\n");
        else
            printf("no solution\n");
    }
    
    return 0;
}

void dfs(int arr[], int visited[], int target, int count, int start, int remain)
{
    if (remain >= 0 && start <= count && target == 0)
    {
        for (int i = 0; i < count; i++)
            printf("%c", (visited[i] == 1 ? 'O' : 'X'));
        printf("\n");
        
        sol_check = 1;
        return;
    }
    if (target < 0 || start == count || remain == 0)
        return;

    for (int i = start; i < count; i++)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            dfs(arr, visited, target - arr[i], count, i + 1, remain - 1);
            visited[i] = 0;
        }
    }
}