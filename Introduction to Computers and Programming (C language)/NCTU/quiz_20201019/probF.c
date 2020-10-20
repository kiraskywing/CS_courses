#include <stdio.h>

int main()
{
    int a0, a1, a2, a3, a4, a5, a6, a7, a8;
    int b0, b1, b2, b3, b4, b5, b6, b7, b8;
    int r1, r2;
    scanf("%d%d%d%d%d%d%d%d%d", &a0, &a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8);
    scanf("%d%d%d%d%d%d%d%d%d", &b0, &b1, &b2, &b3, &b4, &b5, &b6, &b7, &b8);

    if (a0 == b0) r1 += 1;
    if (a1 == b1) r1 += 1;
    if (a2 == b2) r1 += 1;
    if (a3 == b3) r1 += 1;
    if (a4 == b4) r1 += 1;
    if (a5 == b5) r1 += 1;
    if (a6 == b6) r1 += 1;
    if (a7 == b7) r1 += 1;
    if (a8 == b8) r1 += 1;
    
    int restA, restB;
    restA = 45 - (a0 + a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8);
    restB = 45 - (b0 + b1 + b2 + b3 + b4 + b5 + b6 + b7 + b8);

    r2 = 9 - r1 - (restA == restB ? 0 : 1);
    
    printf("%dA%dB", r1, r2);

    return 0;
}