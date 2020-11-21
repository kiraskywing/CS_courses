#include <stdio.h>

int main(void)
{
    int y1, y2, m1, m2, d1, d2;
    scanf(" (%d ,%d ,%d ) (%d ,%d ,%d )", &y1, &m1, &d1, &y2, &m2, &d2);
    
    if (y1 > y2)
        printf("Bob");
    else if (y2 > y1)
        printf("Alice");
    else
    {
        if (m1 > m2)
            printf("Bob");
        else if (m2 > m1)
            printf("Alice");
        else
        {
            if (d1 > d2)
                printf("Bob");
            else if (d2 > d1)
                printf("Alice");
        }
    }
    
    return 0;
}