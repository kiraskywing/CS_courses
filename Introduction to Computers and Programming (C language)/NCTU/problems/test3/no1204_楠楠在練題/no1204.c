#include <stdio.h>

int main(void)
{
    int probs[101] = {0};
    int n, times, cur;
    scanf("%d %d", &n, &times);
    while (n--)
    {
        scanf("%d", &cur);
        probs[cur] = 1;
    }

    while (times--)
    {
        scanf("%d", &cur);
        printf("%s\n", probs[cur] ? "YES" : "NO");
    }
    
    return 0;
}