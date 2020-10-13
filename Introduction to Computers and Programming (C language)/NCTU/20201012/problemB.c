#include <stdio.h>

int main()
{
    int year = 0, a1 = 365, a2 = 366;
    scanf("%d", &year);

    if (year % 100 != 0 && year % 4 == 0) printf("%d", a2);
    else if (year % 400 == 0) printf("%d", a2);
    else printf("%d", a1);

    return 0;
}
