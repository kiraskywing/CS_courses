#include <stdio.h>
#include <stdbool.h>

int main()
{
    int cur = 0, t1 = 0, t2 = 0, res = 0;
    bool m1 = false;
    while (scanf("%d", &cur) != EOF)
    {
        m1 = false;
        if (t1 < t2)
        {
            t1 += cur;
            m1 = true;
        } 
        else t2 += cur;
    }

    if (m1) res = t1;
    else res = t2;
    
    printf("%dm%ds", res / 60, res % 60);
    return 0;
}