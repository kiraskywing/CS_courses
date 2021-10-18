#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int R, C, N, max_d = 99;
    // printf("R C N max_d = ");
    scanf("%d%d%d%d", &R, &C, &N, &max_d);
    max_d = (max_d > 0 && max_d < 100) ? max_d : 99;
    max_d = (max_d % 2) ? max_d : (max_d - 1);
    // printf("[Comfirmed] max_d = %d\n", max_d);
    
    // printf("Generating garden...\n");
    printf("%d %d %d\n", R, C, N);
    srand(time(NULL));
    int di, ri, ci;
    while(N--){
        di = (((rand() % max_d) / 2) * 2) + 1;
        ri = rand() % R;
        ci = rand() % C;
        printf("%d %d %d\n", di, ri, ci);
    }
    
    return 0;
}