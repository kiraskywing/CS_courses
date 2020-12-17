#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int value;
    struct node *next;
};

struct node* createNode(int);
void insertNodeAtTheBeginning(void);
void insertNodeAtTheEnd(void);
void insertNodeAtPosition(void);
void deletePosition(void);
void search(void);
void updateValue(void);
void display(void);

struct node *newnode, *dummy, *cur, *prev, *temp;
struct node *head = NULL, *tail = NULL;

int main(void) 
{
    int ch = 0;

    while (true)
    {
        printf("\n---------------------------------");
        printf("\n   Operations on a linked list");
        printf("\n---------------------------------");
        printf("\n1. Insert node at beginning");
        printf("\n2. Insert node at end");
        printf("\n3. Insert node at a specific position");
        printf("\n4. Delete Node from any Position");
        printf("\n5. Update Node Value");
        printf("\n6. Search Element in the linked list");
        printf("\n7. Display List");
        printf("\n8. Exit");
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\n   Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
		case 1:
		    insertNodeAtTheBeginning();
		    break;
		case 2:
		    insertNodeAtTheEnd();
		    break;
		case 3:
		    insertNodeAtPosition();
		    break;
		case 4:
		    deletePosition();
		    break;
		case 5:
		    updateValue();
		    break;
		case 6:
		    search();
		    break;
		case 7:
		    display();
		    break;
		case 8:
		    printf("\n...Exiting...\n");
		    return 0;
		default:
		    printf("\n...Invalid Choice...\n");
		    break;
		}
    }
    return 0;
 }

struct node* createNode(int val)
{
    struct node *new = (struct node *) malloc(sizeof(struct node));
    if (!new)
    {
        puts("Memory was not allocated");
        return NULL;
    }
    
    new->value = val;
    new->next = NULL;
    return new;
}

void insertNodeAtTheBeginning(void)
{
    int val = 0;

    printf("Enter the value for the node: ");
    scanf("%d", &val);
    newnode = createNode(val);
    
    if (!head)
    {
        head = tail = newnode;
        head->next = NULL;
        tail->next = NULL;
    }
    else
    {
        temp = head;
        head = newnode;
        head->next = temp;
    }

    puts("----INSERTED----");
}

void insertNodeAtTheEnd(void)
{
    int val = 0;

    printf("Enter the value for the Node: ");
    scanf("%d", &val);
    newnode = createNode(val);
    
    if (!tail)
    {
        head = tail = newnode;
        head->next = NULL;
        tail->next = NULL;
    }
    else
    {
        tail->next = newnode;
        tail = newnode;
        tail->next = NULL;
    }

    puts("----INSERTED----");
}

void insertNodeAtPosition(void)
{
    int pos, val, count = 1;

    printf("Enter the value for the Node: ");
    scanf("%d", &val);
    newnode = createNode(val);
    printf("Enter the position ");
    scanf("%d", &pos);
    
    dummy = createNode(-1);
    dummy->next = head;
    prev = dummy;
    cur = dummy->next;
    
    while (cur && count < pos)
    {
        prev = prev->next;
        cur = cur->next;
        count++;
    }
    
    if (count == pos)
    {
        prev->next = newnode;
        newnode->next = cur;
        head = dummy->next;
        if (!tail)
            tail = head;
        puts("----INSERTED----");
    }
    else
    {
        puts("Position is out of range");
        free(newnode);
    }
    free(dummy);
}


void deletePosition(void)
{
    int pos, count = 1;

    if (!head)
    {
        puts("List is empy");
        return;
    }
    
    printf("Enter the position of value to be deleted: ");
    scanf("%d", &pos);
    
    dummy = createNode(-1);
    dummy->next = head;
    prev = dummy;
    cur = dummy->next;
    
    while (cur && count < pos)
    {
        prev = prev->next;
        cur = cur->next;
        count++;
    }
    
    if (count == pos)
    {
        prev->next = cur->next;
        free(cur);
        head = dummy->next;
        if (!tail)
            tail = head;
        puts("Element deleted");
    }
    else
        puts("Position is out of range");
    free(dummy);
}

void updateValue(void)
{
    int oldval, newval;

    if (!head)
    {
        puts("List is empty");
        return;
    }
    
    printf("Enter the value to be updated: ");
    scanf("%d", &oldval);
    printf("Enter the new value: ");
    scanf("%d", &newval);
    for (cur = head; cur; cur = cur->next)
    {
        if (cur->value == oldval)
        {
            cur->value = newval;
            puts("Updated Successfully");
            return;
        }
    }
    
    puts("Value not found in List");
}

void search(void)
{
    int key, pos = 0;

    if (!head)
    {
        puts("List is empty");
        return;
    }
    
    printf("Enter the value to search ");
    scanf("%d", &key);
    for (cur = head; cur; cur = cur->next)
    {
        pos++;
        if (cur->value == key)
        {
            printf("Element %d found at %d position\n", key, pos);
            return;
        }
    }
    
    printf("Element %d not found in list\n", key);
}

void display(void)
{
    if (!head)
    {
        puts("List is empty");
        return;
    }
    for (cur = head; cur; cur = cur -> next)
        printf("%d ", cur -> value);
    puts("");
}