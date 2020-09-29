#include <stdio.h>

int main()
{
    int in_sec = 0, out_sec = 0, out_min = 0;
    scanf("%d", &in_sec);
    out_min = in_sec / 60;
    out_sec = in_sec % 60;
    printf("%d %d", out_min, out_sec);
    return 0;
}
