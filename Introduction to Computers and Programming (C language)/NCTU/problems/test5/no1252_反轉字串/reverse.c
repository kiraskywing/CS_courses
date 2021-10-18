#include<stdio.h>
int main()
{	int t,n,i;
	char s[100][100];
	scanf("%d",&t);
	while(t>0)
	{	scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%s",s[i]);
		for(i=n-1;i>=0;i--)
			printf("%s ",s[i]);	
		t--;
		puts("");
	}
	return 0;
} 
