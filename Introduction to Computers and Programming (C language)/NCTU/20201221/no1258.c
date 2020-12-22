#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct item
{
    int rank, price;
    char name[11];
};

void init_list(struct item list[], int n);
int buy(struct item list[], int n, int budget, char res[][11], int *count);
int rank_cmp(const void *a, const void *b);
int name_cmp(const void *a, const void *b);

int main(void)
{
    int times, budget, n;
    scanf("%d", &times);

    while (times--)
    {
        scanf("%d %d", &budget, &n);
        
        struct item list[n];
        init_list(list, n);
        qsort(list, n, sizeof(struct item), rank_cmp);
        
        char res[n][11];
        int count = 0;
        int spent = buy(list, n, budget, res, &count);
        qsort(res, count, sizeof(char) * 11, name_cmp);
        
        printf("%d ", spent);
        for (int i = 0; i < count; i++)
            printf("%s ", res[i]);
        puts("");
    }

    return 0;
}

void init_list(struct item list[], int n)
{
    for (int i = 0; i < n; i++)
        scanf("%d %d %s", &list[i].rank, &list[i].price, list[i].name);
}

int buy(struct item list[], int n, int budget, char res[][11], int *count)
{
    int remain = budget;
    for (int i = 0; i < n; i++)
    {
        if (remain >= list[i].price)
        {
            strcpy(res[*count], list[i].name);
            (*count)++;
            remain -= list[i].price;
        }
    }
    return budget - remain;
}

int rank_cmp(const void *a, const void *b)
{
    struct item *x = (struct item*) a;
    struct item *y = (struct item*) b;
    return y->rank - x->rank;
}

int name_cmp(const void *a, const void *b)
{
    char *x = (char*) a;
    char *y = (char*) b;
    return strcmp(x, y);
}