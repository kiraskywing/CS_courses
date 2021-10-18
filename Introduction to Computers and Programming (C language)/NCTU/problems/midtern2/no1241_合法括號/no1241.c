#include <stdio.h>

void helper(char res[], int left_used, int right_used, int count, int n);

int main(void)
{
    int n;
    scanf("%d", &n);
    char res[n * 2];
    helper(res, 0, 0, 0, n);

    return 0;
}

void helper(char res[], int left_used, int right_used, int count, int n)
{
    if (left_used > n || right_used > left_used)
        return;

    if (count == 2 * n)
    {
        for (int i = 0; i < count; i++)
            printf("%c", res[i]);
        puts("");
        return;
    }

    res[count] = '(';
    helper(res, left_used + 1, right_used, count + 1, n);

    res[count] = ')';
    helper(res, left_used, right_used + 1, count + 1, n);
}
