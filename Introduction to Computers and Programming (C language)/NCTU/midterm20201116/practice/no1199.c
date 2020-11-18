#include <stdio.h>

int main(void)
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    // 0年12月31日 = 星期日

    int res = 0;
    res += c % 7;
    res += ((a - 1) + (a - 1) / 4 - (a - 1) / 100 + (a - 1) / 400) % 7;
    
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 1; i < b; i++)
        res += days[i - 1] % 7;
    
    if (b > 2 && ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0))
        res++;

    printf("%d", res % 7);

    return 0;
}