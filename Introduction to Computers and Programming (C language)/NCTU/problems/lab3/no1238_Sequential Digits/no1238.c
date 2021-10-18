#include <stdio.h>
#include <stdbool.h>

void helper(bool digits[], int res, int start, bool used, int low, int high);

int main(void)
{
    int times, low, high;
    scanf("%d", &times);
    while (times--)
    {
        bool digits[10] = {false};
        scanf("%d %d", &low, &high);
        helper(digits, 0, 1, false, low, high);
        puts("");
    }
    
    return 0;
}

void helper(bool digits[], int res, int start, bool used, int low, int high)
{
    if (res > high)
        return;
    
    if (res >= low && res <= high)
        printf("%d ", res);
    
    for (int i = start; i < 10; i++)
    {
        if (!used || digits[i - 1])
        {
            digits[i] = true;
            helper(digits, res * 10 + i, i + 1, true, low, high);
            digits[i] = false;
        }
    }
}