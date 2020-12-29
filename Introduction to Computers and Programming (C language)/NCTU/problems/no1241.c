#include <stdio.h>

void helper(char res[], int left_used, int right_used, int len);

int main(void)
{
    int len;
    scanf("%d", &len);
    char res[len * 2];
    helper(res, 0, 0, len * 2);

    return 0;
}

void helper(char res[], int left_used, int right_used, int len)
{
    if (left_used > len / 2 || right_used > left_used)
        return;

    if (left_used + right_used == len)
    {
        for (int i = 0; i < len; i++)
            printf("%c", res[i]);
        printf("\n");
        return;
    }

    res[left_used + right_used] = '(';
    helper(res, left_used + 1, right_used, len);

    res[left_used + right_used] = ')';
    helper(res, left_used, right_used + 1, len);
}
