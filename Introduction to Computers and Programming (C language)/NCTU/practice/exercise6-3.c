#include <stdio.h>

int main()
{
    int i, j;
    for (i = 5, j = i - 1; i > 0, j > 0; --i, j = i - 1)
        printf("%d %d\n", i, j);
    return 0;
}

// condition判斷只讀到 j > 0, 系統有給warning