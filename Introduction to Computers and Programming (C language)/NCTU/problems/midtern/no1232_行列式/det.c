#include<stdio.h>

long long int det(int n,long long int a[11][11])
{	if(n==2)
	{	
		return a[1][1]*a[0][0]-a[0][1]*a[1][0];
	} 
	else
	{	int i,j,k;
		long long int sum=0;
		int sign=1;
		for(k=0;k<n;k++)
		{	long long int b[11][11];
			for(i=0;i<n-1;i++)
			{	for(j=0;j<n-1;j++)
				{	if(k>j)
						b[i][j]=a[i+1][j];
					else
						b[i][j]=a[i+1][j+1];
				}
			}
			if(k%2!=0)
				sign=-1;
			else
				sign=1;	
			sum=(sum+sign*a[0][k]*det(n-1,b))%100000007;
		}
		return sum;
	}
}
int main()
{	int n,i,j;
	long long int a[11][11];
	while(scanf("%d",&n)!=EOF)
	{	for(i=0;i<n;i++)
		{	for(j=0;j<n;j++)
			{	scanf("%lld",&a[i][j]);
			}
		}
		long long sum=det(n,a);
		if(sum<0)sum+=100000007;
		printf("%lld\n",sum);
	}
} 
