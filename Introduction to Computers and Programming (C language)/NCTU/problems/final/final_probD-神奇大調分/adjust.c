#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long long int power(long long int a,long long int b)
{	if(b>1)
	{	long long int tmp=power(a,b/2);
		if(b%2==0)
			return (tmp*tmp)%10000;
		else
			return (a*((tmp*tmp)%10000))%10000;	
	}	
	else if(b==1)
		return a%10000;
	else
		return 1;		
}
int main()
{	char c[10000],n[10];
	int k;
	gets(n);
	k=atoi(n);
	while(k>0)
	{	gets(c);
		long long int ans=0;
		char *token,*command;
		command=strtok(c," ");
		if(!strcmp(command,"sum"))
		{	token=strtok(NULL," ");
			while(token!=NULL)
			{	ans+=(long long)atoi(token);
				ans=ans%10000;
				token=strtok(NULL," ");
			}
		}
		else if(!strcmp(command,"sub"))
		{	token=strtok(NULL," ");
			ans=2*(long long)atoi(token);
			while(token!=NULL)
			{	ans-=(long long)atoi(token);
				ans=ans%10000;
				token=strtok(NULL," ");
			}
		}
		else if(!strcmp(command,"pow"))
		{	token=strtok(NULL," ");
			long long int tmp[2];
			tmp[0]=(long long)atoi(token);
			int i=0;
			while(token!=NULL)
			{	if(i>0)
				{	tmp[1]=(long long)atoi(token);
					ans=power(tmp[0],tmp[1]);
					tmp[0]=ans;	
				}
				token=strtok(NULL," ");
				i++;
			}
		}
		if(ans<0)
			ans+=10000;
		printf("%lld\n",ans);
		k--;
	}
	return 0;
} 
