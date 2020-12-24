#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct treeNode
{
    int val;
    struct treeNode *left, *right;
};

typedef struct treeNode TreeNode;
typedef TreeNode* TreeNodePtr;

void insertNode(TreeNodePtr *root, int value);
void inOrder(TreeNodePtr root);
void preOrder(TreeNodePtr root);
void postOrder(TreeNodePtr root);

int main(void)
{
    int i = 0, item = 0;
    TreeNodePtr root = NULL;

    srand(time(NULL));
    printf("The numbers being placed in the tree are: \n");
    for (int i = 1; i <= 10; i++)
    {
        item = rand() % 15;
        printf(" %d", item);
        insertNode(&root, item);
    }

    printf("\n\nThe preOrder traversal is: \n");
    preOrder(root);

    printf("\n\nThe inOrder traversal is: \n");
    inOrder(root);

    printf("\n\nThe postOrder traversal is: \n");
    postOrder(root);

    return 0;
}

void insertNode(TreeNodePtr *root, int value)
{
    if (!*root)
    {
        *root = (TreeNodePtr) malloc(sizeof(TreeNode));
        if (*root)
        {
            (*root)->val = value;
            (*root)->left = (*root)->right = NULL;
        }
        else
            printf("%d is not inserted. No memory available.\n", value);
        
        return;
    }
    
    if (value < (*root)->val)
        insertNode(&((*root)->left), value);
    else if (value > (*root)->val)
        insertNode(&((*root)->right), value);
    else
        printf("dup ");
}

void inOrder(TreeNodePtr root)
{
    if (!root)
        return;
    
    inOrder(root->left);
    printf("%d ", root->val);
    inOrder(root->right);
}
void preOrder(TreeNodePtr root)
{
    if (!root)
        return;
    
    printf("%d ", root->val);
    inOrder(root->left);
    inOrder(root->right);
}
void postOrder(TreeNodePtr root)
{
    if (!root)
        return;
    
    inOrder(root->left);
    inOrder(root->right);
    printf("%d ", root->val);
}