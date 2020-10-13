#include <stdio.h>

int main()
{
    int y1 = 0, m1 = 0, d1 = 0, y2 = 0, m2 = 0, d2 = 0;
    scanf("(%d,%d,%d) (%d,%d,%d)", &y1, &m1, &d1, &y2, &m2, &d2);

    if (y1 < y2) printf("Alice");
    else if (y1 > y2) printf("Bob");
    else
    {
        if (m1 < m2) printf("Alice");
        else if (m1 > m2) printf("Bob");
        else
            {
                if (d1 < d2) printf("Alice");
                else printf("Bob");
            }
    }

    return 0;
}
