#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string.h>
using namespace std;
int ran(){
  static int x = 20154;
  return x = (x * 0xdefaced + 1) & INT_MAX;
}
int main () {
    freopen("3.in", "w", stdout);
    cout << "100000" << endl;
    int now = 1;
    for (int i = 0; i < 100000; i++) {
        int r = ran()%10000;
        if (r < 2000) {
            printf("INSERT %d\n", ran());
            now++;
        } else if (r < 4000){
            puts("WHAT");
        } else if (r < 6000) {
            if (now >= 2){
                puts("DELETE");
                now--;
            } else {
                puts("WHAT");
            }
        } else if (r < 7000) {
            puts("RIGHT");
        } else {
            puts("LEFT");
        }
    }
}
