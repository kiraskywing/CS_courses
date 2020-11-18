#include <stdio.h>

void helper(int n, int src, int buff, int dest);

int main(void)
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        helper(n, 1, 2, 3);
        printf("finish\n");
    }

    return 0;
}

void helper(int n, int src, int buff, int dest)
{
    if (n > 1)
        helper(n - 1, src, dest, buff);
    printf("Move ring %d from %c to %c\n", n, 'A' + src - 1, 'A' + dest - 1);
    if (n > 1)
        helper(n - 1, buff, src, dest);
}