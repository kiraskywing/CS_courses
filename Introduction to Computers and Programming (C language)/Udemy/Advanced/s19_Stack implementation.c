#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* link;
};

struct Node* top;

void push(int data)
{
    struct Node *temp = malloc(sizeof(struct Node));
    if (temp)
    {
        temp->data = data;
        temp->link = top;
        top = temp;
    }
}

int isEmpty(void)
{
    return top == NULL;
}

int pop(void)
{
    struct Node *temp;
    int val;
    
    if (top)
    {
        temp = top;
        val = temp->data;
        top = top->link;
        temp->link = NULL;
        free(temp);
        return val;
    }
    
    return 0;
}

void display(void)
{
    struct Node *temp;
    
    if (top)
    {
        temp = top;
        while (temp)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        puts("");
    }
}

int main(void)
{
    push(1);
    push(2);
    push(3);
    push(4);

    display();

    pop();
    pop();

    display();
    
    return 0;
}