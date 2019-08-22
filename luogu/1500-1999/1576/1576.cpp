#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<string>
using namespace std;
#define maxn 2010
#define maxm maxn*maxn
const double aaaa=1000000000.0;
int n,m;
int to[maxm],next1[maxm],head[maxm],zhidao[maxm],total;
double dis[maxm],wei[maxm];
void addedge(int u,int v, double j)
{
	total++;
	to[total]=v;
	wei[total]=1.0-j;
	next1[total]=head[u];
	head[u]=total;
}
void dijskitra(int x)
{
	for(int i=1;i<=n;i++)dis[i]=aaaa;
	memset(zhidao,0,sizeof(zhidao));
	dis[x]=100.0;
	for(int ti=0;ti<n;ti++)
	{
		int dj=-1;
		for(int i=1;i<=n;i++)
			if(!zhidao[i]&&(dj==-1||dis[i]<dis[dj]))
				dj=i;
		if(dj==-1)
			break;
		zhidao[dj]=true;
		for(int e=head[dj];e;e=next1[e])
			dis[to[e]]=min(dis[to[e]],(double)dis[dj]/wei[e]);
	}
}
int main()
{
	freopen("1576.in","r",stdin);
// 	freopen("1576.out","w",stdout);
 	scanf("%d%d",&n,&m);
 	for(int i=0;i<m;i++)
 	{
 		int u,v,j;
 		scanf("%d%d%d",&u,&v,&j);
 		addedge(u,v,j/100.0);
 		addedge(v,u,j/100.0);
 	}
	 int u,v;
	 scanf("%d%d",&u,&v);
	 dijskitra(u);
	 printf("%.8lf",dis[v]);
 	return 0;
}

