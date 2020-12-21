#include <stdio.h>
#include <stdlib.h>

int* create(int len);
void clear_ptrs(int *ptr[], int n);

int main(void)
{
    int n, len;
    scanf("%d", &n);
    int *ptr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &len);
        ptr[i] = create(len);
    }

    int times, i_1, i_2;
    scanf("%d", &times);
    while (times--)
    {
        scanf("%d %d", &i_1, &i_2);
        printf("%d\n", *(ptr[i_1] + i_2));
    }

    clear_ptrs(ptr, n);

    return 0;
}

int* create(int len)
{
    int *p = (int *) malloc(len * sizeof(int));
    for (int i = 0; i < len; i++)
        scanf("%d", p + i);
    return p;
}

void clear_ptrs(int *ptr[], int n)
{
    for (int i = 0; i < n; i++)
        free(ptr[i]);
}