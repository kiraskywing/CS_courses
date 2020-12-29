#include <stdio.h>

int main(void)
{
    int times;
    scanf("%d", &times);
    while (times--)
    {
        int shift;
        char ch;
        scanf("%d", &shift);
        getchar();

        while ((ch = getchar()) != '\n')
            putchar('a' + (26 + (ch - 'a' - shift)) % 26);

        putchar(ch);
    }

    return 0;
}