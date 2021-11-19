#include <stdio.h>
#include <math.h>

int main(void)
{
    // Round to integer: 對input小數點第一位四捨五入
    printf("Round 3.14 to integer using %%.0f: %.0f\n", 3.14);
    printf("Round 3.54 to integer using %%.0f: %.0f\n", 3.54);
    printf("round(3.14) in math.h: %f\n", round(3.14));
    printf("round(3.54) in math.h: %f\n", round(3.54));
    puts("");

    // Round up to integer: 得到大於等於input最小整數
    printf("ceil(3.54) in math.h: %f\n", ceil(3.54));
    printf("ceil(-3.54) in math.h: %f\n", ceil(-3.54));
    puts("");

    // Round down to integer: 得到小於等於input最小整數
    printf("floor(3.54) in math.h: %f\n", floor(3.54));
    printf("floor(-3.54) in math.h: %f\n", floor(-3.54));

    return 0;
}