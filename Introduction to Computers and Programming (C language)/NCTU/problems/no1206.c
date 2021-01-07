#include <stdio.h>
#include <math.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int x[n], y[n], res = 0;
    
    for (int i = 0; i < n; i++)
        scanf("%d %d", &x[i], &y[i]);

    for (int i = 0; i < n; i++)
        res += x[i] * y[(i + 1) % n] - x[(i + 1) % n] * y[i];
    
    printf("%.1f", fabs(res / 2.0));
    
    return 0;
}