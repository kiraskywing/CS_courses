#include <stdio.h>

int main(){
    // read R, C, N
    int R, C, N;
    scanf("%d%d%d", &R, &C, &N);
    
    // initialize garden
    int i, j;
    int garden[102][102];
    for(i = 0; i < R + 2; i++){
        for(j = 0; j < C + 2; j++){
            garden[i][j] = 0;
        }
    }
    
    // read waterer
    for(i = 0; i < N; i++){
        int ri, ci;
        scanf("%d%d", &ri, &ci);
        garden[ri][ci] = 1;
        garden[ri][ci + 1] = 1;
        garden[ri][ci + 2] = 1;
        garden[ri + 1][ci] = 1;
        garden[ri + 1][ci + 1] = 1;
        garden[ri + 1][ci + 2] = 1;
        garden[ri + 2][ci] = 1;
        garden[ri + 2][ci + 1] = 1;
        garden[ri + 2][ci + 2] = 1;
    }
    
    // check
    /*
    for(i = 1; i <= R; i++){
        for(j = 1; j <= C; j++){
            printf("%d ", garden[i][j]);
        }
        printf("\n");
    }
    */
    
    // count
    int count = 0;
    for(i = 1; i <= R; i++){
        for(j = 1; j <= C; j++){
            count += ((garden[i][j])?0:1);
        }
    }
    printf("%d\n", count);
    
    return 0;
}