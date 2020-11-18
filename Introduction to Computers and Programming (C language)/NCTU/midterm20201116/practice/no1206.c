#include <stdio.h>
#include <math.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int arr[2][n];
    for (int i = 0; i < n; i++)
        scanf("%d %d", &arr[0][i], &arr[1][i]);
    
    float res = 0.0;
    for (int i = 0; i < n; i++)
        res += (arr[0][i] * arr[1][(i + 1) % n] - arr[0][(i + 1) % n] * arr[1][i]);

    printf("%.1f", fabs(res) / 2);

    return 0;
}