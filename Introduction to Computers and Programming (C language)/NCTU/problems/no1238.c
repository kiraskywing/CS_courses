#include <stdio.h>

void helper(int cur, int start, int low, int high, int digits[], int head);

int main(void)
{
    int times;
    scanf("%d", &times);

    while (times--)
    {
        int low, high, digits[10] = {0};
        scanf("%d %d", &low, &high);
        helper(0, 1, low, high, digits, 0);
        printf("\n");
    }

    return 0;
}

void helper(int cur, int start, int low, int high, int digits[], int head)
{
    if (cur >= low && cur <= high)
        printf("%d ", cur);

    if (cur > high || start == 10 || (head == 1 && digits[start - 1] == 0))
        return;
    
    for (int i = start; i < 10; i++)
    {
        if (head == 0 || (digits[i - 1] == 1 && digits[i] == 0))
        {
            digits[i] = 1;
            helper(cur * 10 + i, i + 1, low, high, digits, 1);
            digits[i] = 0;
        }
    }
}