#include <stdio.h>
#include <stdlib.h>

int main(){
    /********************
    *   Input R, C, N   *
    ********************/
    int R, C, N;
    scanf("%d%d%d", &R, &C, &N);
    
    /********************************************************
    *   Initialize 2D array                                 *
    *       gard[r_i][c_i]  : whether (r_i, c_i) is watered *
    *                         1: yes                        *    
    *                         0: no                         *
    ********************************************************/
    int **gard = calloc(R, sizeof(int*));
    int i, j;
    for(i = 0; i < R; i++){
        gard[i] = calloc(C, sizeof(int));
    }
    
    /************************************
    *   Input D_i, r_i, c_i             *
    *   Fill **gard                     *
    *************************************
    *   In each step, we fill **gard    *
    *   between (r1, c1) to (r2, c2).   *
    *************************************
    *   di : Di / 2                     *
    ************************************/
    int Di, ri, ci;
    int r1, c1, r2, c2, di;
    int tmp_r, tmp_c;
    while(N--){
        scanf("%d%d%d", &Di, &ri, &ci);
        // set r1, c1, r2, c2
        di = Di / 2;
        r1 = ((ri - di) < 0) ? 0 : (ri - di);
        c1 = ((ci - di) < 0) ? 0 : (ci - di);
        r2 = ((ri + di) >= R) ? (R - 1) : (ri + di);
        c2 = ((ci + di) >= C) ? (C - 1) : (ci + di);
        
        // fill **gard
        for(tmp_r = r1; tmp_r <= r2; tmp_r++){
            for(tmp_c = c1; tmp_c <= c2; tmp_c++){
                gard[tmp_r][tmp_c] = 1;
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
