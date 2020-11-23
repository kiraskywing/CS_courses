#include <stdio.h>
#define LEN 9

int dic[LEN] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int visited[LEN];
int low, high, digits;

void init(void);
void helper(int start, int value, int used);

int main(void)
{
    int times;
    scanf("%d", &times);

    while (times--)
    {
        scanf("%d %d", &low, &high);
        
        init();
        helper(0, 0, 0);
        printf("\n");
    }

    return 0;
}

void init(void)
{
    digits = 0;
    int temp = high;
    while (temp)
    {
        digits++;
        temp /= 10;
    }
    
    for (int i = 0; i < LEN; i++)
        visited[i] = 0;
}

void helper(int start, int value, int used)
{
    if (value >= low && value <= high)
        printf("%d ", value);
    if (value > high || used > digits || start == LEN)
        return;
    

    for (int i = start; i < LEN; i++)
    {
        if (visited[i] == 0 && (used == 0 || visited[i - 1] == 1))
        {
            visited[i] = 1;
            helper(i + 1, value * 10 + dic[i], used + 1);
            visited[i] = 0;
        }
        else
            break;
    }
}