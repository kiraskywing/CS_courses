#include <stdio.h>

int main(void)
{
    int n0, n1, n2, n3, n4, n5, n6, n7, n8;
    int m0, m1, m2, m3, m4, m5, m6, m7, m8;
    int a = 0;
    scanf("%d %d %d %d %d %d %d %d %d\n", &n0, &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8);
    scanf("%d %d %d %d %d %d %d %d %d\n", &m0, &m1, &m2, &m3, &m4, &m5, &m6, &m7, &m8);

    if (n0 == m0)
        a++;
    if (n1 == m1)
        a++;
    if (n2 == m2)
        a++;
    if (n3 == m3)
        a++;
    if (n4 == m4)
        a++;
    if (n5 == m5)
        a++;
    if (n6 == m6)
        a++;
    if (n7 == m7)
        a++;
    if (n8 == m8)
        a++;
    
    int r1 = 45 - (n0 + n1 + n2 + n3 + n4 + n5 + n6 + n7 + n8);
    int r2 = 45 - (m0 + m1 + m2 + m3 + m4 + m5 + m6 + m7 + m8);
    
    printf("%dA%dB", a, 9 - a - (r1 == r2 ? 0 : 1));

    return 0;
}