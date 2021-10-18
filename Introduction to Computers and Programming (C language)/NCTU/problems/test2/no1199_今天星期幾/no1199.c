#include <stdio.h>

int main(void)
{
    int year, month, day;
    scanf("%d %d %d", &year, &month, &day);

    // 0年12月31日 = 星期日

    int res = 0;
    res += day % 7;
    res += ((year - 1) + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7;
    
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 1; i < month; i++)
        res += days[i - 1] % 7;
    
    if (month > 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
        res++;

    printf("%d", res % 7);

    return 0;
}