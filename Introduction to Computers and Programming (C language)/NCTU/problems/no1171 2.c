#include <stdio.h>

int main(void)
{
    int x, y;
    scanf("(%d,%d)", &x, &y);
    y -= (x + y);
    x += (x + 6);
    printf("(%d,%d)", x, y);
    return 0;
}