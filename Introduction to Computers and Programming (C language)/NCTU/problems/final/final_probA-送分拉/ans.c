#include <stdio.h>
#include <string.h>
int cmp(char *a, char *b) {
    int lena = strlen(a);
    int lenb = strlen(b);
    if (lena != lenb) return 1;
    for (int i = 0; i < lena; i++) {
        if (toupper(a[i]) != toupper(b[i])) return 1;
    }
    return 0;

}
int main () {
    freopen("hd.in", "r", stdin);
    freopen("hd.out", "w", stdout);
    char a[101], b[101];
    gets(a);
    int T = atoi(a);
    while(T--) {
        gets(a);
        gets(b);
        puts(cmp(a, b) == 0 ? "Pass" : "Fail");

    }
}
