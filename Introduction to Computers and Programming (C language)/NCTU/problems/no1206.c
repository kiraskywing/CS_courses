#include <stdio.h>
#include <math.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    
    int pos_x[n], pos_y[n];
    for (int i = 0; i < n; i++)
        scanf("%d %d", &pos_x[i], &pos_y[i]);
    
    float res;
    for (int i = 0; i < n; i++)
        res += pos_x[i] * pos_y[(i + 1) % n] - pos_x[(i + 1) % n] * pos_y[i];
    
    printf("%.1f", fabs(res) / 2.0);

    return 0;
}