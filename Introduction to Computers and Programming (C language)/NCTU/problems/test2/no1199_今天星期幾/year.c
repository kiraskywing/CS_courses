#include<stdio.h> 
int max(int a,int b)
{	return (a>b)?a:b;
}
int min(int a,int b)
{	return (a<b)?a:b;
}
int main()
{	int y,m,d,i;
	int ans=3;
	scanf("%d%d%d",&y,&m,&d);
	int ly[12]={31,29,31,30,31,30,31,31,30,31,30,31};
	int ny[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	for(i=max(y,2020)-1;i>=min(y,2020);i--)
	{	if(i%400==0||(i%4==0&&i%100!=0))
		{	ans+=(y>2020)?366:-366;	
		} 
		else
		{	ans+=(y>2020)?365:-365;	
		}
	}
	for(i=m-2;i>=0;i--)
	{	if(y%400==0||(y%4==0&&y%100!=0))
		{	ans+=ly[i];
		} 
		else
		{	ans+=ny[i];
		}
	}
	ans=(ans+d-1)%7;
	if(ans<0)
		ans+=7;
	printf("%d\n",ans);	
	return 0;
}
