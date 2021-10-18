#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 50

struct node{
    char name[LEN];
    int child_cnt, parent_cnt, gen;
    int child[2*LEN], parent[2*LEN];
};
struct node *family;

int check_exist(int person_cnt, char target[LEN]){
    int i = 0;
    for(i; i < person_cnt; i++){
        if(strncmp(target, family[i].name, LEN) == 0)
            return i;
    }
    return -1;
}

void set_gen(int id){
    int i, target, cur_gen = family[id].gen;
    // set child
    for(i = 0; i < family[id].child_cnt; i++){
        target = family[id].child[i];
        if(family[target].gen == 999){
            family[target].gen = cur_gen - 1;
            set_gen(target);
        }
    }
    // set parent
    for(i = 0; i < family[id].parent_cnt; i++){
        target = family[id].parent[i];
        if(family[target].gen == 999){
            family[target].gen = cur_gen + 1;
            set_gen(target);
        }
    }
    return;
}

int main(){
    int N;
    char S[LEN], T[LEN];
    scanf("%d", &N);
    int max_person = 2 * N;
    char name_list[max_person][LEN];
    
    int person_cnt = 1, Sid, Tid;
    family = calloc(sizeof(struct node), max_person);
    // set Dong
    char *dong = "Dong";
    strncpy(family[0].name, dong, LEN);
    family[0].child_cnt = 0;
    family[0].parent_cnt = 0;
    family[0].gen = 0;
    
    while(N--){
		memset(S, 0, LEN);
		memset(T, 0, LEN);
        scanf("%s %s", S, T);
        //printf("[%s][%s]\n", S, T);
        // set struct
        Sid = check_exist(person_cnt, S);
        Tid = check_exist(person_cnt, T);
        if(Sid < 0){
            Sid = person_cnt++;
            strncpy(family[Sid].name, S, LEN);
            family[Sid].child_cnt = 0;
            family[Sid].parent_cnt = 0;
            family[Sid].gen = 999;
        }
        if(Tid < 0){
            Tid = person_cnt++;
            strncpy(family[Tid].name, T, LEN);
            family[Tid].child_cnt = 0;
            family[Tid].parent_cnt = 0;
            family[Tid].gen = 999;
        }
        family[Sid].parent[family[Sid].parent_cnt] = Tid;
        family[Sid].parent_cnt++;
        family[Tid].child[family[Tid].child_cnt] = Sid;
        family[Tid].child_cnt++;
    }
    // set generation of all node
    set_gen(0);
    /*
    // test all node
    int i, j;
    for(i = 0; i < person_cnt; i++){
        printf("[%2d] %s\n", i, family[i].name);
        printf("\tC:");
        for(j = 0; j < family[i].child_cnt; j++)
            printf(" %s", family[family[i].child[j]].name);
        printf("\n\tP:");
        for(j = 0; j < family[i].parent_cnt; j++)
            printf(" %s", family[family[i].parent[j]].name);
        printf("\n----------\n");
    }
    */
    int i;
    for(i = 1; i < person_cnt; i++){
        printf("%s ", family[i].name);
        if(family[i].gen == 999)    printf("unknown\n");
        else if(family[i].gen > 0)  printf("elder\n");
        else if(family[i].gen == 0) printf("same\n");
        else                        printf("younger\n");
    }
    return 0;
}