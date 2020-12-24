/*
建立一個pointer array儲存每個item的address
使用qsort的時候, 是交換item的address, 不用搬動struct內的element
理論上會比較有效率?
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item
{
    int rank, price;
    char name[11];
};

void init_list(struct item *list[], int n);
int buy(struct item *list[], int n, int budget, char res[][11], int *count);
int rank_cmp(const void *a, const void *b);
int name_cmp(const void *a, const void *b);
void clear_ptrs(struct item *list[], int n);

int main(void)
{
    int times, budget, n;
    scanf("%d", &times);

    while (times--)
    {
        scanf("%d %d", &budget, &n);
        
        struct item *list[n];
        init_list(list, n);
        qsort(list, n, sizeof(struct item*), rank_cmp);
        
        char res[n][11];
        int count = 0;
        int spent = buy(list, n, budget, res, &count);
        qsort(res, count, sizeof(char) * 11, name_cmp);
        
        printf("%d ", spent);
        for (int i = 0; i < count; i++)
            printf("%s ", res[i]);
        puts("");

        clear_ptrs(list, n);
    }

    return 0;
}

void init_list(struct item *list[], int n)
{
    for (int i = 0; i < n; i++)
    {
        struct item *new = (struct item*) malloc(sizeof(struct item));
        scanf("%d %d %s", &new->rank, &new->price, new->name);
        list[i] = new;
    }
}

int buy(struct item *list[], int n, int budget, char res[][11], int *count)
{
    int remain = budget;
    for (int i = 0; i < n; i++)
    {
        if (remain >= list[i]->price)
        {
            strcpy(res[*count], list[i]->name);
            (*count)++;
            remain -= list[i]->price;
        }
    }
    return budget - remain;
}

int rank_cmp(const void *a, const void *b)    // 這裡type轉換要處理好
{
    struct item **x = (struct item**) a;      // Origin: de-ref array address -> access array element 
    struct item **y = (struct item**) b;      // Here: de-ref array address -> access the address of struct 
    return (*y)->rank - (*x)->rank;           //       de-ref the address of struct -> access struct
}                                             //       thus, we need to use double pointer

int name_cmp(const void *a, const void *b)
{
    char *x = (char*) a;
    char *y = (char*) b;
    return strcmp(x, y);
}

void clear_ptrs(struct item *list[], int n)
{
    for (int i = 0; i < n; i++)
        free(list[i]);
}