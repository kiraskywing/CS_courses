#include <stdio.h>

int main()
{
    int n, cur, s1 = 0, s2 = 0;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &cur);
        if (cur > s1)
        {
            s2 = s1;
            s1 = cur;
        }
        else if (cur > s2) s2 = cur;
    }

    printf("%d", s2);
    return 0;
}