#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int R = 100, C = 100, N = 1000, max_d = 25;
    
    // printf("Generating garden...\n");
    printf("%d %d %d\n", R, C, N);
    srand(time(NULL));
    int di, ri, ci, type;
    while(N--){
        di = (((rand() % max_d) / 2) * 2) + 1;
        type = rand() % 2;
        ri = rand() % (R / 2);
        ci = rand() % (C / 2);
        
        ri = type ? ri : (R - 1 - ri);
        ci = type ? ci : (C - 1 - ci);
        printf("%d %d %d\n", di, ri, ci);
    }
    
    return 0;
}
