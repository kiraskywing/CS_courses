#ifndef INSERT_H_INCLUDED
#define INSERT_H_INCLUDED

struct Node;
void insertNodeAtTheBeginning(struct Node **head, struct Node **tail);
void insertNodeAtTheEnd(struct Node **head, struct Node **tail);
void insertNodeAtPosition(struct Node **head, struct Node **tail);

#endif