#include <stdio.h>
#include <stdlib.h>

int pow2(int n){
    return n ? (2 * pow2(n-1)) : 1;
}

void fill(int **arr, int len, int ri, int ci, int fill_len, int fill_num){
    // fill the number into 1x1 block
	if(fill_len == 1){
        arr[ri][ci] = fill_num;
        return;
    }
	// split the an nxn block into 4 (n/2)x(n/2) blocks
    int next_fill_len = fill_len / 2;
    fill(arr, len,                 ri,                 ci, next_fill_len, fill_num);
    fill(arr, len,                 ri, ci + next_fill_len, next_fill_len, fill_num + next_fill_len * next_fill_len);
    fill(arr, len, ri + next_fill_len,                 ci, next_fill_len, fill_num + 2 * next_fill_len * next_fill_len);
    fill(arr, len, ri + next_fill_len, ci + next_fill_len, next_fill_len, fill_num + 3 * next_fill_len * next_fill_len);
    return;
}

int main(){
    int n, target;
    scanf("%d%d", &n, &target);
    // calculate the edge's length of the map
	int len = pow2(n);
	//printf("%d\n", len);
    
	// initialize 2d array
    int i, j;
    int **arr = calloc(len, sizeof(int *));
    for (i = 0; i < len; i++){
        arr[i] = calloc(len, sizeof(int));
    }
    
	// fill number in the map
    fill(arr, len, 0, 0, len, 1);
    
	// print the numbered map and find target
	int tar_r, tar_c;
    for(i = 0; i < len; i++){
        for(j = 0; j < len; j++){
			printf("%d ", arr[i][j]);
			if(arr[i][j] == target){
				tar_r = i + 1;
				tar_c = j + 1;
			}
        }
        printf("\n");
    }
	// print target location
	printf("%d %d\n", tar_r, tar_c);
	return 0;
}
