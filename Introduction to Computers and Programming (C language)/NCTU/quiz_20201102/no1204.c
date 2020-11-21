#include <stdio.h>

int main(void)
{
    int arr[101] = {0};
    int t1, t2, cur;
    scanf("%d %d", &t1, &t2);
    
    while (t1--)
    {
        scanf("%d", &cur);
        arr[cur] = 1;
    }

    while (t2--)
    {
        scanf("%d", &cur);
        if (arr[cur])
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}