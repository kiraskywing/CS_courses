#include <stdio.h>
#include <stdlib.h>

void clear_list(int *list[], int n);

int main(void)
{
    int n, k;
    scanf("%d", &n);
    int *list[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &k);
        list[i] = (int*) malloc(sizeof(int) * k);
        for (int j = 0; j < k; j++)
            scanf("%d", &list[i][j]);
    }

    int times, i, j;
    scanf("%d", &times);
    while (times--)
    {
        scanf("%d %d", &i, &j);
        printf("%d\n", list[i][j]);
    }

    clear_list(list, n);

    return 0;
}

void clear_list(int *list[], int n)
{
    for (int i = 0; i < n; i++)
        free(list[i]);
}