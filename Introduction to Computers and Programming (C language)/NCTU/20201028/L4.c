#include <stdio.h>

int main()
{
    int len = 0, times = 0;
    scanf("%d %d", &len, &times);

    int arr[len];
    for (int i = 0; i < len; i++)
        scanf("%d", &arr[i]);

    int cur, left, right, mid;
    for (int i = 0; i < times; i++)
    {
        scanf("%d", &cur);
        left = 0, right = len - 1;
        while (left + 1 < right)
        {
            mid = (left + right) / 2;
            if (arr[mid] > cur)
                right = mid;
            else
                left = mid;
        }
        if (arr[right] == cur)
            printf("%d\n", right);
        else
            printf("%d\n", left);
    }
    
    return 0;
}