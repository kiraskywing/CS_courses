#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int times, num;
    scanf("%d", &times);

    const int ints[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const char *romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    while (times--)
    {
        scanf("%d", &num);
        for (int i = 0; i < 13 && num > 0; i++)
        {
            int t2 = num / ints[i];
            while (t2--)
                printf("%s", romans[i]);
            num %= ints[i];
        }
        puts("");
    }

    return 0;
}