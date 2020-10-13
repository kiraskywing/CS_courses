#include <stdio.h>

int main()
{
    int x = 0, x2 = 0, y = 0, y2 = 0;
    scanf("(%d,%d) (%d,%d)", &x, &y, &x2, &y2);

    if (x == x2 || y == y2) printf("D");
    else
    {
        float slope = ((x2 - x) * 1.0)/((y2 - y) * 1.0);

        if (slope == 1 || slope == -1) printf("D");
        else printf("S");
    }

    return 0;
}
