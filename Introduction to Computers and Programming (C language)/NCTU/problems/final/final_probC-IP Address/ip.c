#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 50

char input[LEN];
int sub[4];
char substr[LEN];
int ip_cnt;

void print_id(){
	ip_cnt++;
	printf("%.*s.", sub[1], input);
	printf("%.*s.", sub[2] - sub[1], input + sub[1]);	
	printf("%.*s.", sub[3] - sub[2], input + sub[2]);	
	printf("%.*s ", (int)strlen(input) - sub[3], input + sub[3]);	
	return;
}

void print_now(){
	int index = 1;
	int i;
	printf("sub = %d %d %d %d [", sub[0], sub[1], sub[2], sub[3]);
	for(i = 0; i < strlen(input); i++){
		if(i > 0 && sub[index] == i){	
			printf(".");
			index++;
		}
		printf("%c", input[i]);
	}
	printf("]\n");
	return;
}

int isvalid(){
	int valid = 0;
	int subint = atoi(substr);
	if(subint == 0 && substr[1] == '\0')	valid = 1;
	else if(subint > 0 && subint <= 255 && substr[0] != '0')	valid = 1;
	return valid;
}

void solve(){
	//print_now();
	int rest_len = strlen(input);
	int sub_num = sub[0];
	rest_len -= (sub_num == 0) ? 0 : sub[sub_num];
	/********************
	*	check length	*
	********************/
	if(rest_len < (4 - sub_num) || rest_len > 3 * (4 - sub_num))	return;
	/********************************
	*	check if substring is valid	*
	********************************/
	int pre_i = (sub_num > 1) ? sub[sub_num - 1] : 0;
	int cur_i = sub[sub_num];
	if(sub_num > 0){
		memset(substr, 0, LEN);
		memcpy(substr, &input[pre_i], cur_i - pre_i);
		if(!isvalid())	return;
	}
	/********************************************
	*	check last substring when sub_num == 3	*
	********************************************/
	if(sub[0] == 3){
		memset(substr, 0, LEN);
		memcpy(substr, &input[cur_i], strlen(input) - cur_i);
		if(isvalid())	print_id();
	}
	/****************************
	*	split next substring	*
	****************************/
	else{
		sub[0]++;
		int i;
		for(i = 1; i <= 3; i++){
			if(cur_i + i > strlen(input))	break;
			sub[sub[0]] = cur_i + i;
			solve();
		}
		sub[sub[0]] = 0;
		sub[0]--;
	}
	return;
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		/****************
		*	Initialize	*
		****************/
		int i;
		for(i = 0; i < 4; i++){
			sub[i] = 0;
		}
		memset(input, 0, LEN);
		ip_cnt = 0;
		/********************
		*	Input and solve	*
		********************/
		scanf("%s", input);
		solve();
		if(!ip_cnt)	printf("QAQ\n");
		else		printf("\n");
	}
	return 0;
}
