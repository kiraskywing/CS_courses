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
        di = max_d;
        ri = (rand() % 2) ? 0 : (R - 1);
        ci = rand() % C;
        printf("%d %d %d\n", di, ri, ci);
    }
    
    return 0;
}
