#include <stdio.h>

int main()
{
    int year, month, day, res = 0;
    scanf("%d %d %d", &year, &month, &day);

    res += (day - 1);
    res += (year + (year - 1) / 4 + (year - 1) / 400 - (year - 1) / 100);
    
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 1; i < month; i++) 
        res += days[i - 1];
    
    if (month > 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)) 
        res += 1;
    
    printf("%d", res % 7);
    return 0;
}