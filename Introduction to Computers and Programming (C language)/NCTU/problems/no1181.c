#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    float total = 0.0;

    if (n > 1000)
        total = (n - 1000) * 6.41 + (1000 - 700) * 5.66 + (700 - 500) * 4.80 + (500 - 330) * 3.52 + (330 - 120) * 2.38 + 120 * 1.63;
    else if (n > 700)
        total = (n - 700) * 5.66 + (700 - 500) * 4.80 + (500 - 330) * 3.52 + (330 - 120) * 2.38 + 120 * 1.63;
    else if (n > 500)
        total = (n - 500) * 4.80 + (500 - 330) * 3.52 + (330 - 120) * 2.38 + 120 * 1.63;
    else if (n > 330)
        total = (n - 330) * 3.52 + (330 - 120) * 2.38 + 120 * 1.63;
    else if (n > 120)
        total = (n - 120) * 2.38 + 120 * 1.63;
    else
        total = n * 1.63;
    
    printf("%.0f", total);

    return 0;
}