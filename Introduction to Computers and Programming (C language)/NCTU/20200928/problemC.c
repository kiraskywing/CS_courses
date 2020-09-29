#include <stdio.h>

int main()
{
    int x, y;
    scanf("(%d,%d)", &x, &y);
    y = -x;
    x = 2 * x + 6;
    printf("(%d,%d)", x, y);
    return 0;
}

