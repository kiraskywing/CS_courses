#include<stdio.h>
int queue[10000],bot=0,top=0;
struct vertex
{	int edge[100];
	int degree;
	int explored;
	int path;
	int id;
}v[100];
void enqueue(int id)
{	queue[top]=id;
	top=(top+1)%10000;
}
int dequeue()
{	int tmp=queue[bot];
	bot=(bot+1)%10000;
	return tmp; 
}
int main()
{	int i,edgenum,vertexnum,a,b,s,t;
	scanf("%d%d",&vertexnum,&edgenum);
	for(i=0;i<vertexnum;i++)
	{	v[i].id=i;
		v[i].degree=0;
		v[i].explored=0;
		v[i].path=-1;
	}	
	for(i=0;i<edgenum;i++)
	{	scanf("%d%d",&a,&b);
		v[a].edge[v[a].degree]=b;
		v[a].degree++;
		v[b].edge[v[b].degree]=a;
		v[b].degree++;
	}
	scanf("%d%d",&s,&t);
	v[s].path=0;
	v[s].explored=1;
	enqueue(s);
	
	while(bot!=top)
	{	int now=dequeue();
		if(now==t)
			break;
		
		for(i=0;i<v[now].degree;i++)
		{	if(!v[v[now].edge[i]].explored)
			{	enqueue(v[now].edge[i]);
				v[v[now].edge[i]].explored=1;
				v[v[now].edge[i]].path=v[now].path+1;
			}		
		}	
	}
	if(v[t].path<0)
	{	printf("Oops\n");
	}		
	else
	{	printf("%d\n",v[t].path);
	}
	return 0;
} 
