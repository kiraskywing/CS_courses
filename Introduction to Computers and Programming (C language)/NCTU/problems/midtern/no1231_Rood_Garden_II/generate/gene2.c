#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int R = 100, C = 100, N = 1000000, max_d = 49;
    
    // printf("Generating garden...\n");
    printf("%d %d %d\n", R, C, N);
    srand(time(NULL));
    int di, ri, ci;
    while(N--){
        di = (((rand() % max_d) / 2) * 2) + 1;
        ri = rand() % R;
        ci = (rand() % 2) ? 0 : (C - 1);
        printf("%d %d %d\n", di, ri, ci);
    }
    
    return 0;
}