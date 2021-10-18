#include <stdio.h>

int len;

void gene_pare(char str[25], int pos, int left, int right){
//	printf("pos = %d : %s\n", pos, str);
	if(pos == len){
		printf("%s\n", str);
		return;
	}
	if(left < (len / 2)){
		str[pos] = '(';
		gene_pare(str, pos + 1, left + 1, right);
	}
	if(left > right){
		str[pos] = ')';
		gene_pare(str, pos + 1, left, right + 1);
	}
	return;
}

int main(){
	int N;
	scanf("%d", &N);
	
	len = 2 * N;
	char str[25] = "";
	gene_pare(str, 0, 0, 0);
	return 0;
}
