#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 50
char nullstr[] = "";
char del4[] = ".";
char del6[] = ":";

int IP4(char S[LEN]){
	int ans = 1, del_cnt = 0, total_len = strlen(S);
	// check trailing .
	if(S[total_len - 1] == del4[0])	return 0;
	char * tmp = strsep(&S, del4);
	while(total_len > 0){
		//printf("[%s]\n", tmp);
		del_cnt++;
		if(tmp != NULL){
			int tmp_len = strlen(tmp);
			if(tmp_len > 3){
				ans = 0;
				break;
			}
			total_len -= tmp_len;
			// check if token is 10-base number
			int i, tmp_int, char_is_valid = 1;
			for(i = 0; i < tmp_len; i++){
				tmp_int = (int)tmp[i];
				if(!(tmp_int >= 48 && tmp_int <= 57)){
					char_is_valid = 0;
					break;
				}
			}
			if(char_is_valid){
				tmp_int = atoi(tmp);
				// out ot range
				if(tmp_int < 0 || tmp_int > 255){
					ans = 0;
					break;
				}
				// token = 0
				else if(tmp_int == 0){
					if(tmp[0] != '0' || tmp[1] != '\0'){
						ans = 0;
						break;
					}
				}
				// check leading 0
				else{
					if(tmp[0] == '0'){
						ans = 0;
						break;
					}
				}
			}
			else{
				ans = 0;
				break;
			}
		}
		total_len--;
		tmp = strsep(&S, del4);
	}
	return (del_cnt == 4) ? ans : 0;
}

int IP6(char S[LEN]){
	int ans = 1, del_cnt = 0, total_len = strlen(S);
	// check trailing :
	if(S[total_len - 1] == del6[0])	return 0;
	char * tmp = strsep(&S, del6);
	while(total_len > 0){
		//printf("[%s]\n", tmp);
		del_cnt++;
		if(tmp != NULL){
			int tmp_len = strlen(tmp);
			if(tmp_len > 4){
				ans = 0;
				break;
			}
			total_len -= tmp_len;
			// check if token is 16-base number
			int i, tmp_int, char_is_valid = 1;
			for(i = 0; i < tmp_len; i++){
				tmp_int = (int)tmp[i];
				if(!(tmp_int >= 48 && tmp_int <= 57) && !(tmp_int >= 65 && tmp_int <= 70) && !(tmp_int >= 97 && tmp_int <= 102)){
					char_is_valid = 0;
					break;
				}
			}
			if(!char_is_valid){
				ans = 0;
				break;
			}
		}
		total_len--;
		tmp = strsep(&S, del6);
	}
	return (del_cnt == 8) ? ans : 0;
}

int main(){
	int N, T, valid;
	char S[LEN], A1[] = "Valid IP", A2[] = "QAQ";
	scanf("%d", &N);
	while(N--){
		memset(S, 0, LEN);
		scanf("%d", &T);
		scanf("%s", S);
		valid = (T == 4) ? IP4(S) : IP6(S);
		printf("%s\n", valid ? A1 : A2);
	}
	return 0;
}
