#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<string.h>
using namespace std;

#define INT_MAX 2147483647
#define FALSE 0
#define TRUE 1
#define OK 1
#define MAX_VERTEX_NUM 10000

typedef int Status;
typedef struct ArcNode
{
	int adjvex;
	struct ArcNode *nextarc;
	int info;
}ArcNode;

typedef struct VNode
{
	int data;
	ArcNode *firstarc;
}VNode, Adjlist[MAX_VERTEX_NUM];

typedef struct 
{
	Adjlist vertices;
	int vexnum,arcnum;
}MGraph;

int U[60000],V[60000],W[60000];
int first[30000];
int next1[30000];
long long int dis[100000];
int final[10000];

Status initial(MGraph &G)
{
	int m,k=0,p=0;
	memset(W,INT_MAX,sizeof(W));
	memset(first,-1,sizeof(first));
	memset(next1,-1,sizeof(next1));

	for (int i=1;i<=G.vexnum;i++)
	{
		G.vertices[i].data=i;
	}

	for (int i=1;i<=G.arcnum;i++)
	{
		cin>>U[i]>>V[i]>>W[i];
		if (U[i]>V[i])
			swap(U[i],V[i]);
		next1[i]=first[U[i]];
		first[U[i]]=i;
	}
	return OK;
}

int getelem(MGraph &G, int V0,int t)
{
	int m=0,v=0;
	if (V0>t)
		swap(V0,t);
	v=first[V0];
	for (;V[v]!=t;v=next1[v])
	{
		if (v==-1)
			return INT_MAX;
	}
	return W[v]; 
}

int ShortestPath_DIJ(MGraph &G, int V0, int t)
{
	int min=0,v=0,l=0,m=0,k=0,i=0;
	memset(final,FALSE,sizeof(final));
	memset(dis,INT_MAX,sizeof(dis));
	for (int v=1;v<=G.vexnum;v++)
	{
		dis[v]=getelem(G,V0,v);
	}
	final[V0]=TRUE;

	for (int k=0;k<G.vexnum-1;++k)
	{
		int MinNum=V0;
		for (i=1;i<=G.vexnum;++i)
		{
			if (final[i]==FALSE && (dis[i]<dis[MinNum]))
			{
				MinNum=i;
			}
		}
		if (MinNum==t)
			return dis[t];
		final[MinNum]=TRUE;
		for (i=1;i<G.vexnum;++i)
		{
			if (!final[i])
			{
				int l=getelem(G,MinNum,i);
				if (l+dis[MinNum]<dis[i])
				{
					dis[i]=l+dis[MinNum];
				}
			}
		}
	}
	return dis[t];
}

int main()
{
	MGraph G;
	int n,m,s,t;
	cin>>n>>m>>s>>t;
	G.vexnum=n;
	G.arcnum=m;
	initial(G);
	if (s==t)
		cout<<"0"<<endl;
	else 
		cout<<ShortestPath_DIJ(G,s,t)<<endl;
	return 0;
}