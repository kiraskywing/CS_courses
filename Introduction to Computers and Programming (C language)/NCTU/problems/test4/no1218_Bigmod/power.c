#include<stdio.h>
int c;
long long int power(unsigned int a,unsigned int b)
{	if(b>1)
	{	if(b%2==0)
		{	long long int tmp=power(a,b/2);
			return (tmp*tmp)%c;
		}
		else
		{	return (power(a,b/2)*power(a,b/2+1))%c;
		}
	}	
	else
	{	if(b==1)
			return a%c;	
		else
			return 1;
	}
		
			
} 
int main()
{	unsigned int a,b;
	while(scanf("%u%u%d",&a,&b,&c)!=EOF)	
	//scanf("%u%u%d",&a,&b,&c);
		printf("%lld\n",power(a,b));
	return 0;	
} 
