#include<stdio.h>
#include<string.h>
int main()
{	int n,i,a,b;
	char s[10][100];
	scanf("%d",&n);
	char command[4];
	for(i=0;i<n;i++)
		scanf("%s",&s[i]);
	while(scanf("%s%d%d",&command,&a,&b)!=EOF)
	{	if(!strcmp("add",command))
		{	char tmp[100];
			strcpy(tmp,s[b]);
			strcat(s[a],tmp);
			printf("%s\n",s[a]);
		}
		else if(!strcmp("sub",command))
		{	char tmp[100]="";
			char *token;
			token=strtok(s[a],s[b]);
			while(token!=NULL)
			{	strcat(tmp,token);
				token=strtok(NULL,s[b]);
				
				
			}
			strcpy(s[a],tmp);
			printf("%s\n",s[a]);
		}
		else if(!strcmp("eq",command))
		{	if(strcmp(s[a],s[b]))
			{	printf("different\n");
			}
			else
				printf("same\n");
		}
		else
		{	printf("Oops\n");
		} 
	}
	
		
	return 0;
} 
