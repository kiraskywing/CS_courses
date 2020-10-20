#include <stdio.h>

int main()
{
    int n = 0, temp = 0;
    float a = 1.63, b = 2.38, c = 3.52, d = 4.80, e = 5.66, f = 6.41, total = 0.0;
    scanf("%d", &n);
    
    if (n <= 120) total += (n * a);
    else
    {
        temp = n - 120;
        total += 120 * a;
    }
    
    if (n > 120 && n <= 330) total += (temp * b);
    else if (n > 330)
    {
        temp = n - 330;
        total += (330 - 120) * b;
    }
    
    if (n > 330 && n <= 500) total += (temp * c);
    else if (n > 500)
    {
        temp = n - 500;
        total += (500 - 330) * c;
    }

    if (n > 500 && n <= 700) total += (temp * d);
    else if (n > 700)
    {
        temp = n - 700;
        total += (700 - 500) * d;
    }

    if (n > 700 && n <= 1000) total += (temp * e);
    else if (n > 1000) total += ((1000 - 700) * e + (n - 1000) * f);

    printf("%.0f", total);     // 四捨五入到整數
    
    return 0;
}