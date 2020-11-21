#include <stdio.h>

int main(void)
{
    int s;
    scanf("%d", &s);
    printf("%d %d", s / 60, s % 60);
    return 0;
}