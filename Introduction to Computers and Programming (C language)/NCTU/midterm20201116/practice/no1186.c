#include <stdio.h>

int main(void)
{
    int x1, y1, x2, y2;
    scanf("%d %d\n", &x1, &y1);
    scanf("%d %d\n", &x2, &y2);

    int a = 0, b = 0;
    if (x1 == x2)
        a++;
    if (y1 == y2)
        a++;
    if (x1 == y2)
        b++;
    if (y1 == x2)
        b++;
    
    printf("%dA%dB", a, b);

    return 0;
}