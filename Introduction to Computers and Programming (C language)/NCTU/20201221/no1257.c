/*
Feature: 用struct記錄個人資訊並與他人串接, 最後用DFS更新長幼順序

step1. 開一個pointer array記錄每個人的資訊, 按照input順序排列; 把Dong放在index = 0
step2. 用list_check檢查人名是否已記錄在pointer array, 找到就回傳該人對應pointer; 沒有就建立新node, 將其pointer記錄在array並回傳
step3. 將parent和child按照關係連接
step4. 從Dong為起點進行DFS, traverse所有和Dong相接的人並更新related, rank
step5. 按照pointer array輸出結果
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node
{
    char name[30];                // 人名長度小於30
    int rank;
    bool related;
    int n_elder, n_younger;       // 記錄長輩數, 子孫數
    struct node *elders[30];      // 0 < N < 30
    struct node *youngers[30];    // 因此一個人的長輩或子孫數量不會超過30人
};

struct node *ptr[30];    // for step1, input人數不超過30人
int idx = 1;             // Dong放在index = 0, 因此從index = 1開始排

void Dong_init(void);    // create Dong's node
struct node* list_check(char *s);    // for step2
void connect(struct node *c, struct node *p);    // for step3
void update_rank(struct node *cur, int rank);    // for step4
void judge(struct node *cur);    // for step5

int main(void)
{
    Dong_init();    // step1
    
    int n;
    scanf("%d", &n);
    char s1[30] = "", s2[30] = "";           // 人名長度小於30
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s", s1, s2);
        struct node *n1 = list_check(s1);    // step2
        struct node *n2 = list_check(s2);    // step2
        connect(n1, n2);                     // step3
    }

    update_rank(ptr[0], 0);                  
    // step4, 以Dong為rank = 0, elder's rank > 0, younger's rank < 0
    
    for (int i = 1; i < idx; i++)
        judge(ptr[i]);                       // step5
    
    free(ptr[0]);    // 把Dong佔的memory釋放

    return 0;
}

void Dong_init(void)
{
    ptr[0] = (struct node*) malloc(sizeof(struct node));
    strcpy(ptr[0]->name, "Dong");
    ptr[0]->related = false;
    ptr[0]->n_elder = 0;
    ptr[0]->n_younger = 0;
}

struct node* list_check(char *s)
{
    // traverse pointer array, 尋找該人是否已記錄在array, 找到就return該人對應pointer
    if (strcmp(s, "Dong") == 0)
        return ptr[0];
    for (int i = 1; i < idx; i++)
    {
        if (strcmp(s, ptr[i]->name) == 0)
            return ptr[i];
    }

    // 不在array, 建一個新node
    struct node *new = (struct node*) malloc(sizeof(struct node));
    strcpy(new->name, s);
    new->related = false;    // 還未與Dong確認關係, initialized as false
    new->n_elder = 0;
    new->n_younger = 0;
    
    ptr[idx] = new;          // 放入pointer array
    idx++;                   // 更新unique name數量
    return ptr[idx - 1];     // 回傳該人pointer
}

void connect(struct node *c, struct node *p)
{
    // parent, child互接, 並更新各自elder和younger數量
    c->elders[c->n_elder++] = p;
    p->youngers[p->n_younger++] = c;
}

void update_rank(struct node *cur, int rank)
{
    if (cur->related)    // 遞迴出口, 造訪過就離開
        return;
    
    cur->related = true;
    cur->rank = rank;
    
    for (int i = 0; i < cur->n_elder; i++)    // DFS, 往長輩方向, 長輩rank = 目前rank + 1
        update_rank(cur->elders[i], rank + 1);

    for (int i = 0; i < cur->n_younger; i++)    // DFS, 往子孫方向, 子孫rank = 目前rank - 1
        update_rank(cur->youngers[i], rank - 1);
}

void judge(struct node *cur)
{
    if (!cur->related)    // 沒關係
        printf("%s %s\n", cur->name, "unknown");
    else                  // 有關係, 照rank大小處理輸出
    {
        if (cur->rank > 0)
            printf("%s %s\n", cur->name, "elder");
        else
            printf("%s %s\n", cur->name, cur->rank == 0 ? "same" : "younger");
    }
    
    free(cur);    // 判斷完可以丟了
}