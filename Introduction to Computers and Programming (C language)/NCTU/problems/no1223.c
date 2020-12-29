#include <stdio.h>

void helper(int num, int start, int buff, int end);

int main(void)
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        helper(n, 1, 2 ,3);
        printf("finish\n");
    }
    
    return 0;
}

void helper(int num, int start, int buff, int end)
{
    if (num > 1)
        helper(num - 1, start, end, buff);
    printf("Move ring %d from %c to %c\n", num, 'A' + start - 1, 'A' + end - 1);
    if (num > 1)
        helper(num - 1, buff, start, end);
}