#include<stdio.h>
int main()
{	int n,i,x[400],y[400];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{	scanf("%d %d",&x[i],&y[i]);
	}
	float sum=0;
	for(i=0;i<n;i++)
	{	sum-=x[i]*y[(i+1)%n]-x[(i+1)%n]*y[i];
	}
	if(sum<0)
		sum*=-1;
	printf("%.1f\n",sum/2);
	return 0;
} 
