#include <stdio.h>

int main()
{
    int a1, b1, a2, b2, r1, r2;
    scanf("%d %d", &a1, &b1);
    scanf("%d %d", &a2, &b2);

    if (a1 == a2) r1 += 1;
    if (b1 == b2) r1 += 1;
    if (a1 == b2) r2 += 1;
    if (a2 == b1) r2 += 1;

    printf("%dA%dB", r1, r2);

    return 0;
}