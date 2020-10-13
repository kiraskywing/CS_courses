#include <stdio.h>

int main()
{
    int a = 0, b = 0, c = 0;
    scanf("%d %d %d", &a, &b, &c);
    if (((a + b) > c) && ((a + c) > b) && ((b + c) > a))
    {
        int a2 = a * a, b2 = b * b, c2 = c * c;
        if ((a2 == b2 + c2) || (b2 == a2 + c2) || (c2 == a2 + b2)) printf("right triangle");
        else if ((a2 > b2 + c2) || (b2 > a2 + c2) || (c2 > a2 + b2)) printf("obtuse triangle");
        else printf("acute triangle");
    }
    else printf("OOPS");

    return 0;
}
