#include <stdio.h>

int main(void)
{
    int x1, y1, x2, y2;
    scanf("(%d,%d) (%d,%d)", &x1, &y1, &x2, &y2);
    if (x1 == x2 || y1 == y2 || (y2 - y1) == (x2 - x1) || (y2 - y1) == (x1 - x2))
        printf("D");
    else
        printf("S");

    return 0;
}