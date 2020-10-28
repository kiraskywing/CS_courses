#include <stdio.h>

int main()
{
    int len = 0, times = 0;
    scanf("%d %d", &len, &times);

    int arr[len];
    for (int i = 0; i < len; i++)
        scanf("%d", &arr[i]);

    int cur;
    for (int i = 0; i < times; i++)
    {
        scanf("%d", &cur);
        for (int j = 0; j < len; j++)
        {
            if (arr[j] == cur)
            {
                printf("%d\n", j);
                break;
            }   
        }
    }
    
    return 0;
}