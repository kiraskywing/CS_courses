#include <stdio.h>

int sol_check;

void helper(int nums[], int res[], int len, int target, int start, int used);

int main(void)
{
    int times;
    scanf("%d", &times);
    while (times--)
    {
        int target, nums[10], cur = 20, len = 0, res[101];
        scanf("%d", &target);

        while (cur != 0)
        {
            scanf("%d", &cur);
            nums[len++] = cur;
        }
        len--;

        sol_check = 0;
        helper(nums, res, len, target, 0, 0);
        printf("%s\n", sol_check ? "finish" : "no solution");
    }

    return 0;
}

void helper(int nums[], int res[], int len, int target, int start, int used)
{
    if (target == 0)
    {
        sol_check = 1;
        for (int i = 0; i < used; i ++)
            printf("%d ", res[i]);
        printf("\n");
        return;
    }

    if (target < 0)
        return;
    
    for (int i = start; i < len; i++)
    {
        res[used] = nums[i];
        helper(nums, res, len, target - nums[i], i, used + 1);
        res[used] = 0;
    }
}