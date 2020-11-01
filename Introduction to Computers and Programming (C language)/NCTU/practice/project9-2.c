#include <stdio.h>

int check(int x, int y, int n);

int main(void)
{
    int x = 6, y = 2, n = 5;
    
    printf("%s", check(x, y, n) ? "Yes" : "No");
    return 0;
}

int check(int x, int y, int n)
{
    return (0 <= x && x < n - 1 && 0 <= y && y < n - 1);
}