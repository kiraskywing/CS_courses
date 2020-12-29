#include <stdio.h>

int sol_check;

void helper(int nums[], int visited[], int start, int target, int len, int remain);

int main(void)
{
    int times;
    scanf("%d", &times);
    while (times--)
    {
        int target, cur = 1000, nums[101], visited[101] = {0}, len = 0;
        scanf("%d", &target);
        while (cur != 0)
        {
            scanf("%d", &cur);
            nums[len++] = cur;
        }
        len--;

        sol_check = 0;
        helper(nums, visited, 0, target, len, 20);
        printf("%s", (sol_check != 0 ? "finish\n" : "no solution\n"));
    }
    
    return 0;
}

void helper(int nums[], int visited[], int start, int target, int len, int remain)
{
    if (target == 0)
    {
        sol_check = 1;
        for (int i = 0; i < len; i++)
            printf("%c", (visited[i] == 1 ? 'O' : 'X'));
        printf("\n");
        return;
    }
    
    if (start == len || target < 0 || remain == 0)
        return;
    
    for (int i = start; i < len; i++)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            helper(nums, visited, i + 1, target - nums[i], len, remain - 1);
            visited[i] = 0;
        }
    }
}