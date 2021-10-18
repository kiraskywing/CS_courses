#include <stdio.h>
#include <stdlib.h>

int main(){
    /********************
    *   Input R, C, N   *
    ********************/
    int R, C, N;
    scanf("%d%d%d", &R, &C, &N);
    
    /********************************************************
    *   Initialize two 2D array                             *
    *       dist[r_i][c_i]  : max D_i of (r_i, c_i)         *
    *       gard[r_i][c_i]  : whether (r_i, c_i) is watered *
    *                         1: yes                        *    
    *                         0: no                         *
    ********************************************************/
    int **dist = calloc(R, sizeof(int*));
    int **gard = calloc(R, sizeof(int*));
    int i, j;
    for(i = 0; i < R; i++){
        dist[i] = calloc(C, sizeof(int));
        gard[i] = calloc(C, sizeof(int));
    }
    
    /****************************
    *   Input D_i, r_i, c_i     *
    ****************************/
    int Di, ri, ci;
    while(N--){
        scanf("%d%d%d", &Di, &ri, &ci);
        if(Di > dist[ri][ci]){
            dist[ri][ci] = Di;
        }
    }
    
    /************************************
    *   In each step, we fill **gard    *
    *   between (r1, c1) to (r2, c2).   *
    *************************************
    *   di : Di / 2                     *
    ************************************/
    int r1, c1, r2, c2, di;
    int tmp_r, tmp_c;
    for(i = 0; i < R; i++){
        for(j = 0; j < C; j++){
            // skip if no waterer
            if(dist[i][j] == 0){
                continue;
            }
            
            // set r1, c1, r2, c2
            di = dist[i][j] / 2;
            r1 = ((i - di) < 0) ? 0 : (i - di);
            c1 = ((j - di) < 0) ? 0 : (j - di);
            r2 = ((i + di) >= R) ? (R - 1) : (i + di);
            c2 = ((j + di) >= C) ? (C - 1) : (j + di);
            
            // fill **gard
            for(tmp_r = r1; tmp_r <= r2; tmp_r++){
                for(tmp_c = c1; tmp_c <= c2; tmp_c++){
                    gard[tmp_r][tmp_c] = 1;
                }
            }
        }
    }
    
    /************************
    *   Count non-watered   *
    ************************/
    int cnt = 0;
    for(i = 0; i < R; i++){
        for(j = 0; j < C; j++){
            //printf("%d ", gard[i][j]);
            if(!gard[i][j]){
                cnt++;
            }
        }
        //printf("\n");
    }
    printf("%d\n", cnt);
    
    return 0;
}
