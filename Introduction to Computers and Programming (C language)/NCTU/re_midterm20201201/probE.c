#include <stdio.h>

int sol_check;

void helper(int arr[], int visited[], int start, int len, int target, int remain);

int main(void)
{
    int times;
    scanf("%d", &times);

    while (times--)
    {
        int target, cur = 100, arr[10000] = {0}, visited[10000] = {0}, len = 0;
        scanf("%d", &target);
        while (cur != 0)
        {
            scanf("%d", &cur);
            arr[len++] = cur;
        }
        len--;

        sol_check = 0;
        helper(arr, visited, len - 1, len, target, 20);
        printf("%s", sol_check != 0 ? "finish\n" : "no solution\n");
    }

    return 0;
}

void helper(int arr[], int visited[], int start, int len, int target, int remain)
{
    if (target == 0)
    {
        sol_check = 1;
        for (int i = 0; i < len; i++)
            printf("%c", (visited[i] == 1 ? 'O' : 'X'));
        printf("\n");
        return;
    }

    if (target < 0 || remain == 0)
        return;

    for (int i = start; i >= 0; i--)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            helper(arr, visited, i - 1, len, target - arr[i], remain - 1);
            visited[i] = 0;
        }
    }
}
