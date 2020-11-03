#include <stdio.h>
#include <math.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    
    int pos[2][n];
    for (int i = 0; i < n; i++)
        scanf("%d %d", &pos[0][i], &pos[1][i]);
    
    int temp = 0;
    for (int i = 0; i < n; i++)
        temp += ((pos[0][i] * pos[1][(i + 1) % n]) - (pos[1][i] * pos[0][(i + 1) % n]));

    printf("%.1f", fabs(temp / 2.0));

    return 0;
}