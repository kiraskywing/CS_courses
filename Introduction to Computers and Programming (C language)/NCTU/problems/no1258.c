#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item
{
    char name[11];
    int rank, price;
};

void list_to_buy(struct Item *items[], int n);
int cmp_rank(const void *a, const void *b);
int buy(struct Item *items[], char res[][11], int n, int budget, int *count);
int cmp_name(const void *a, const void *b);
void clear_items(struct Item *items[], int n);

int main(void)
{
    int times;
    scanf("%d", &times);

    while (times--)
    {
        int budget, n;
        scanf("%d %d", &budget, &n);
        struct Item *items[n];
        
        list_to_buy(items, n);
        qsort(items, n, sizeof(struct Item*), cmp_rank);

        char res[n][11];
        int count = 0;
        int spent = buy(items, res, n, budget, &count);

        qsort(res, count, sizeof(char) * 11, cmp_name);

        printf("%d ", spent);
        for (int i = 0; i < count; i++)
            printf("%s ", res[i]);
        puts("");

        clear_items(items, n);
    }
    
    return 0;
}

void list_to_buy(struct Item *items[], int n)
{
    for (int i = 0; i < n; i++)
    {
        items[i] = (struct Item*) malloc(sizeof(struct Item));
        scanf("%d %d %s", &items[i]->rank, &items[i]->price, items[i]->name);
    }
}

int cmp_rank(const void *a, const void *b)
{
    return (*(struct Item**)b)->rank - (*(struct Item**)a)->rank;
}

int buy(struct Item *items[], char res[][11], int n, int budget, int *count)
{
    int remain = budget;
    for (int i = 0; i < n; i++)
    {
        if (remain >= items[i]->price)
        {
            remain -= items[i]->price;
            strcpy(res[(*count)++], items[i]->name);
        }
    }

    return budget - remain;
}

int cmp_name(const void *a, const void *b)
{
    return strcmp((char *)a, (char *)b);
}

void clear_items(struct Item *items[], int n)
{
    for (int i = 0; i < n; i++)
        free(items[i]);
}