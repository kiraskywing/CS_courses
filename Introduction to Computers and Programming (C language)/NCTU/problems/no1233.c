#include <stdio.h>

void helper(int nums[], int visited[], int start, int target, int len, int remain, int *sol_check);

int main(void)
{
    int times;
    scanf("%d", &times);
    while (times--)
    {
        int target, cur = 1000, nums[10000], visited[10000], len = 0;
        scanf("%d", &target);
        while (cur)
        {
            scanf("%d", &cur);
            visited[len] = 0;
            nums[len++] = cur;
        }
        len--;

        int sol_check = 0;
        helper(nums, visited, 0, target, len, 20, &sol_check);  
        printf("%s\n", sol_check ? "finish" : "no solution");
    }
    
    return 0;
}

void helper(int nums[], int visited[], int start, int target, int len, int remain, int *sol_check)
{
    if (target == 0)
    {
        *sol_check = 1;
        for (int i = 0; i < len; i++)
            printf("%c", visited[i] ? 'O' : 'X');
        puts("");
        return;
    }
    
    if (target < 0 || !remain)
        return;
    
    for (int i = start; i < len; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            helper(nums, visited, i + 1, target - nums[i], len, remain - 1, sol_check);
            visited[i] = 0;
        }
    }
}