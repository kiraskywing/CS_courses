#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string.h>
using namespace std;
int ran(){
  static int x = 2017122;
  return x = (x * 0xdefaced + 1) & INT_MAX;
}
char lib[] = "asdzxcqwertyfghvbnmjkluiop    ZXCASDQWEVBNFGHRTYMJKLUIOP 1234567890!@#$%^&*(){}<>:[];,.?";
int len_lib = strlen(lib);
int main () {
    freopen("hd.in", "w", stdout);
    cout << 100 << endl;
    char sa[105], sb[105];
    for (int i = 0; i < 100; i++) {

        if (ran()%10000>5000) {
            int len = ran()%99+1;
            for (int i = 0; i < len; i++) {
                sa[i] = lib[ran()%len_lib];
            }
            sa[len] = '\0';
            puts(sa);
            puts(sa);
        } else {
            int len = ran()%99+1;
            for (int i = 0; i < len; i++) {
                sa[i] = lib[ran()%len_lib];
                sb[i] = lib[ran()%len_lib];
            }
            sa[len] = '\0';
            sb[len] = '\0';
            puts(sa);
            puts(sb);
        }
    }
}
