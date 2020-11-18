#include <stdio.h>

int main(void)
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if ((a + b > c) && (b + c > a) && (c + a) > b)
    {
        int A = a*a, B = b*b, C = c*c;
        if ((A + B == C) || (C + B == A) || (A + C == B))
            printf("right triangle");
        else if ((A + B > C) && (C + B > A) && (A + C > B))
            printf("acute triangle");
        else
            printf("obtuse triangle");
    }
    else
        printf("OOPS");

    return 0;
}