/*
Feature: 使用doubly linked list

step1. 開一個pointer array記錄每個人的資訊, 按照input順序排列; 把Dong放在index = 0
step2. 用list_check檢查人名是否已記錄在pointer array, 找到就回傳該人對應pointer; 沒有就建立新node, 將其pointer記錄在array並回傳
step3. 將parent和child按照關係連接, 若和Dong有搭上關係, 更新rank
step4. traverse所有人, 更新每個人的rank
step5. 按照pointer array輸出結果
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node
{
    char name[30];
    int rank;
    bool checked;    // 是否與Dong搭上關係
    struct node *parent;
    struct node *child;
};

struct node *ptr[30];    // for step1.
int idx = 1;             // Dong放在index = 0, 因此從index = 1開始排

void Dong_init(void);    // create Dong's node
struct node* list_check(char *s);    // for step2.
void connect(struct node *c, struct node *p);    // for step3.
void update_rank(struct node *cur);    // for step4.
void judge(struct node *cur);    // for step5

int main(void)
{
    Dong_init();    // step1
    
    int n;
    scanf("%d", &n);
    char s1[30] = "", s2[30] = "";
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s", s1, s2);
        struct node *n1 = list_check(s1);    // step2
        struct node *n2 = list_check(s2);    // step2
        connect(n1, n2);                     // step3
    }

    for (int i = 1; i < idx; i++)
        update_rank(ptr[i]);                 // step4
    for (int i = 1; i < idx; i++)
        judge(ptr[i]);                       // step5
    
    free(ptr[0]);    // 把Dong佔的memory釋放

    return 0;
}

void Dong_init(void)
{
    ptr[0] = (struct node*) malloc(sizeof(struct node));
    strcpy(ptr[0]->name, "Dong");
    ptr[0]->rank = 0;          // 以Dong為0, elder's rank > 0, younger's rank < 0
    ptr[0]->checked = true;    // 自己和自己有關係
    ptr[0]->parent = NULL;
    ptr[0]->child = NULL;
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
    new->checked = false;    // 還未與Dong確認關係, initialized as false
    new->parent = NULL;
    new->child = NULL;
    
    ptr[idx] = new;          // 放入pointer array
    idx++;                   // 更新unique name數量
    return ptr[idx - 1];     // 回傳該人pointer
}

void connect(struct node *c, struct node *p)
{
    // parent, child互接
    c->parent = p;
    p->child = c;

    if (c->checked)    // child和Dong有搭上關係
    {
        p->checked = true;
        p->rank = c->rank + 1;    // parent's rank is higher
    }
    else if (p->checked)    // parent和Dong有搭上關係
    {
        c->checked = true;
        c->rank = p->rank - 1;    // child's rank is lower
    }
}

void update_rank(struct node *cur)
{
    struct node *temp;
    
    // 自己和Dong有搭上關係, 讓子孫都和Dong搭上關係
    temp = cur;
    while (temp->checked && temp->child && !temp->child->checked)
    {
        temp->child->checked = true;
        temp->child->rank = temp->rank - 1;
        temp = temp->child;
    }
    
    // 自己和Dong有搭上關係, 讓長輩都和Dong搭上關係
    temp = cur;
    while (temp->checked && temp->parent && !temp->parent->checked)
    {
        temp->parent->checked = true;
        temp->parent->rank = temp->rank + 1;
        temp = temp->parent;
    }
}

void judge(struct node *cur)
{
    if (!cur->checked)    // 沒關係
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