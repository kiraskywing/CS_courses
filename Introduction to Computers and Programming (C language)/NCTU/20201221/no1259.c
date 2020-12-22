/*
Feature: 使用BFS, implement queue by linked list

step1. 開一個pointer array記錄所有node, node資訊有編號, 幾個鄰居, 鄰居編號
step2. 記錄互相鄰居關係
step3. 使用BFS來取得答案
step4. 歸還不再使用記憶體
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int val;           // 編號
    int nei_len;       // 鄰居數量
    int *neighbors;    // 所有鄰居編號
};

struct Queue
{
    int val;               // 編號
    int step;              // 對應路徑長
    struct Queue *next;    // 下一個編號
};

void create_graph(struct Node *nodes[], int n_num, int e_num);  // for step1
void connect(struct Node *nodes[], int n1, int n2);             // for step2
void judge(struct Node *nodes[], int n_num);                    // for step3
struct Queue* AddNode(int val);                                 // for step3
void clear_nodes(struct Node *nodes[], int n_num);              // for step4

int main(void)
{
    int n_num, e_num;
    scanf("%d %d", &n_num, &e_num);
    struct Node *nodes[n_num];            // step1
    create_graph(nodes, n_num, e_num);    // step1 & 2
    judge(nodes, n_num);                  // step3
    
    clear_nodes(nodes, n_num);            // step4

    return 0;
}

void create_graph(struct Node *nodes[], int n_num, int e_num)
{
    // 先將所有node建立, 記錄在pointer array
    for (int i = 0; i < n_num; i++)
    {
        struct Node *new = (struct Node *) malloc(sizeof(struct Node));
        new->val = i;
        new->nei_len = 0;
        new->neighbors = (int *) malloc(sizeof(int) * (n_num - 1));    // 最大鄰居數量 = 總數量減去自己
        nodes[i] = new;
    }

    int n1, n2;
    for (int i = 0; i < e_num; i++)
    {
        scanf("%d %d", &n1, &n2);
        connect(nodes, n1, n2);    // n2是n1的鄰居
        connect(nodes, n2, n1);    // n1是n2的鄰居
    }
}

void connect(struct Node *nodes[], int n1, int n2)
{
    // 記錄鄰居編號, 更新鄰居數量
    int len = (nodes[n1]->nei_len)++;
    nodes[n1]->neighbors[len] = n2;
}

struct Queue* AddNode(int val)
{
    struct Queue *new = (struct Queue*) malloc(sizeof(struct Queue));
    new->val = val;
    return new;
}

void judge(struct Node *nodes[], int n_num)
{
    int start, end;
    scanf("%d %d", &start, &end);

    if (start == end)    // 處理case: start等於end
    {
        printf("%d\n", 0);
        return;
    }
    
    // start node放入Queue
    struct Queue *head = AddNode(nodes[start]->val);
    head->step = 0;
    struct Queue *tail = head;
    
    bool visited[n_num];    // 記錄走過的node
    for (int i = 0; i < n_num; i++)
        visited[i] = false;

    while (head)    // 還有候選的node存在
    {
        // 取出front node
        int value = head->val;
        int steps = head->step;
        int len = nodes[value]->nei_len;
        
        if (value == end)   // front node是終點, 輸出路徑長, 離開function
        {
            printf("%d\n", steps);
            return;
        }

        // front node不是終點, 記錄拜訪過, 將所有鄰居插入Queue尾端
        visited[value] = true;
        for (int i = 0; i < len; i++)
        {
            int idx = nodes[value]->neighbors[i];
            if (!visited[idx])    // 沒拜訪過才插入Queue
            {
                tail->next = AddNode(idx);
                tail = tail->next;
                tail->step = steps + 1;    // 下個node的路徑長為目前的+1
            }
        }
        
        struct Queue *prev = head;
        head = head->next;    // 進到下一個候選node
        free(prev);    // 不會再用到目前的node, 釋放memory
    }
    
    puts("Oops");    // 能拜訪的node都用完了還是沒到終點
}


void clear_nodes(struct Node *nodes[], int n_num)
{
    for (int i = 0; i < n_num; i++)
    {
        free(nodes[i]->neighbors);
        free(nodes[i]);
    }
}