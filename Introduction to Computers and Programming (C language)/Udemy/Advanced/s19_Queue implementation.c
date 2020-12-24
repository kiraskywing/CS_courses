#include <stdio.h>
#include <stdlib.h>

struct QNode
{
    int key;
    struct QNode *next;
};

struct Queue
{
    struct QNode *front, *rear;
};

struct QNode* newNode(int k)
{
    struct QNode *temp = (struct QNode*) malloc(sizeof(struct QNode));
    temp->key = k;
    temp->next = NULL;
    return temp;
};

struct Queue* createQueue()
{
    struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
};

void enQueue(struct Queue *q, int k)
{
    struct QNode *temp = newNode(k);

    if (!q->rear)
    {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = q->rear->next;
}

struct QNode *deQueue(struct Queue *q)
{
    if (!q->front)
        return NULL;
    
    struct QNode *temp = q->front;
    q->front = q->front->next;

    if (!q->front)
        q->rear = NULL;
    
    return temp;
};

int main(void)
{
    struct Queue *q = createQueue();
    struct QNode *cur = NULL;
    enQueue(q, 1);
    enQueue(q, 2);
    cur = deQueue(q);
    if (cur)
        printf("Dequeued item: %d\n", cur->key);
    cur = deQueue(q);
    if (cur)
        printf("Dequeued item: %d\n", cur->key);
    enQueue(q, 3);
    enQueue(q, 4);
    enQueue(q, 5);
    cur = deQueue(q);
    if (cur)
        printf("Dequeued item: %d\n", cur->key);
    
    return 0;
}