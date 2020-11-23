#include <stdio.h>

int sol_check;

void helper(int arr[], int temp[], int target, int start, int used, int len);

int main(void)
{
    int N;
    scanf("%d", &N);
    int target, cur, arr[10], temp[100], len;

    while (N--)
    {
        scanf("%d", &target);
        cur = -1, sol_check = 0, len = 0;
        
        while (cur != 0)
        {
            scanf("%d", &cur);
            arr[len++] = cur;
        }
        len--;

        helper(arr, temp, target, 0, 0, len);
        if (sol_check)
            printf("finish\n");
        else
            printf("no solution\n");
    }

    return 0;
}

void helper(int arr[], int temp[], int target, int start, int used, int len)
{
    if (target == 0)
    {
        sol_check = 1;
        for (int i = 0; i < used; i++)
            printf("%d ", temp[i]);
        printf("\n");
        return;
    }
    else if (target < 0 || start == len)
        return;
    
    for (int i = start; i < len; i++)
    {
        temp[used] = arr[i];
        helper(arr, temp, target - arr[i], i, used + 1, len);
        temp[used] = 0;
    }
}