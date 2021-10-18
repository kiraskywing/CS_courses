#include <stdio.h>
#include <stdlib.h>

int main(){
    /********************
    *   Input R, C, N   *
    ********************/
    int R, C, N;
    scanf("%d%d%d", &R, &C, &N);
    
    /*****************************************************
    *   Initialize two 2D array                          *
    *       max1[r_i][c_i]  : 1st max D_i of (r_i, c_i)  *
    *       max2[r_i][c_i]  : 2nd max D_i of (r_i, c_i)  *
    *       max3[r_i][c_i]  : 3rd max D_i of (r_i, c_i)  *
    *       gard[r_i][c_i]  : water time on (r_i, c_i)	 *
    ******************************************************/
    int **max1 = calloc(R, sizeof(int*));
    int **max2 = calloc(R, sizeof(int*));
    int **max3 = calloc(R, sizeof(int*));
    int **gard = calloc(R, sizeof(int*));
    int i, j, k;
    for(i = 0; i < R; i++){
        max1[i] = calloc(C, sizeof(int));
        max2[i] = calloc(C, sizeof(int));
        max3[i] = calloc(C, sizeof(int));
        gard[i] = calloc(C, sizeof(int));
    }
    
    /****************************
    *   Input D_i, r_i, c_i     *
    ****************************/
    int Di, ri, ci;
    while(N--){
        scanf("%d%d%d", &Di, &ri, &ci);
        if(Di > max1[ri][ci]){
            max3[ri][ci] = max2[ri][ci];
            max2[ri][ci] = max1[ri][ci];
			max1[ri][ci] = Di;
        }
		else if(Di > max2[ri][ci]){
            max3[ri][ci] = max2[ri][ci];
            max2[ri][ci] = Di;
        }
		else if(Di > max3[ri][ci]){
            max3[ri][ci] = Di;
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
            for(k = 0; k < 3; k++){
				switch(k){
					case 0:	di = max1[i][j];	break;
					case 1:	di = max2[i][j];	break;
					case 2:	di = max3[i][j];	break;
				}

				// skip if no waterer
				if(!di){
					break;
				}

				// set r1, c1, r2, c2
				di /= 2;
            	r1 = ((i - di) < 0) ? 0 : (i - di);
            	c1 = ((j - di) < 0) ? 0 : (j - di);
            	r2 = ((i + di) >= R) ? (R - 1) : (i + di);
            	c2 = ((j + di) >= C) ? (C - 1) : (j + di);
            
				// fill **gard
            	for(tmp_r = r1; tmp_r <= r2; tmp_r++){
                	for(tmp_c = c1; tmp_c <= c2; tmp_c++){
                    	gard[tmp_r][tmp_c] = (gard[tmp_r][tmp_c] > 2) ? 3 : (gard[tmp_r][tmp_c] + 1);
                	}
            	}
			}
		
            
        }
    }
    
    /************************
    *   Count well-grown	*
	*	water time = 1 or 2	*
    ************************/
    int cnt = 0;
    for(i = 0; i < R; i++){
        for(j = 0; j < C; j++){
            //printf("%d ", gard[i][j]);
            if(gard[i][j] == 1 || gard[i][j] == 2){
                cnt++;
            }
        }
        //printf("\n");
    }
    printf("%d\n", cnt);
    
    return 0;
}
