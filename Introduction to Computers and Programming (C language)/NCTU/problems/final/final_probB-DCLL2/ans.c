#include <stdio.h>
#include <string.h>
struct node {
    int val;
    struct node *left, *right;
};
struct node *tp;
char com[10];
int main () {
    freopen("3.in","r",stdin);
    freopen("3.out","w",stdout);
    tp = (struct node *) malloc(sizeof(struct node));
    tp->val = 1;
    tp->left = tp->right = tp;
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%s", com);
        if (com[0] == 'W') {
            printf("%d\n", tp->val);
        } else if (com[0] == 'I') {
            int a;
            struct node *tmp, *next;
            scanf("%d", &a);
            tmp = (struct node *) malloc(sizeof(struct node));
            tmp -> val = a;
            next = tp -> right;
            tmp -> right = next;
            tmp -> left = tp;
            tp -> right = tmp;
            next -> left = tmp;
        } else if (com[0] == 'D') {
            struct node *pre, *next;
            pre = tp -> left;
            next = tp -> right;
            pre -> right = next;
            next -> left = pre;
            free(tp);
            tp = next;
        } else if (com[0] == 'R') {
            tp = tp->right;
        } else {
            tp = tp->left;
        }
    }
}
