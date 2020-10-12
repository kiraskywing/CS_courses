#include <stdio.h>

int main()
{
    int money = 0;
    int b1, b2, b3, b4;
    printf("Enter a dollar amount: ");
    scanf("%d", &money);

    b1 = money / 20;
    money %= 20;
    b2 = money / 10;
    money %= 10;
    b3 = money / 5;
    money %= 5;
    b4 = money;

    printf("$20 bills: %d\n", b1);
    printf("$10 bills: %d\n", b2);
    printf("$5 bills: %d\n", b3);
    printf("$1 bills: %d\n", b4);

    return 0;
}