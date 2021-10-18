#include<stdio.h>
void f(int low,int high,int ans)
{	int value=ans%10+1;
	if(value>9) return;
	ans=ans*10+value;
	if(ans>=low)
	{	if(ans<=high)
		{	printf("%d ",ans);
		}
		else
		{	return;
		}
	}
	f(low,high,ans);
}
int main()
{	int i,low,high,t;
	scanf("%d",&t);
	while(t>0)
	{	scanf("%d%d",&low,&high);
		for(i=1;i<10;i++)
			f(low,high,i);
		puts("");
		t--;	
	}	
	return 0;
}
