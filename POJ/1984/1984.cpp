#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<string>
#include<cstdlib>
#include<map>
using namespace std;

#define MAXN  40011
#define MAXM  40011
#define MAXK 10011
#define ll long long 
struct point_type{ll x,y;};
struct edge_type{ll fr,to,le;char f;};
struct ans_type{int f1,f2,n,count;};

edge_type edge[MAXM];
point_type point[MAXN];

ll f[MAXN];

ans_type ans_in[MAXK];
ll ans_out[MAXK];
inline ll abss(ll a){return a>=0?a:-a;}
int find(int x)
{
	if(x==f[x])
		return f[x];
	int fx=f[x];
	f[x]=find(f[x]);
	point[x].x+=point[fx].x;
	point[x].y+=point[fx].y;
	return f[x];
}
void bing(int x,int y,int xx,int yy)
{
	int fx=find(x);
	int fy=find(y);
	if(fx==fy)
		return ;
	f[fy]=fx;
	point[fy].x=point[x].x-point[y].x- xx;
	point[fy].y=point[x].y-point[y].y-yy;
}
inline bool cmp(ans_type a,ans_type b)
{
	return a.n<b.n;
}
int main()
{
	int n,m;
	freopen("1984.in","r",stdin);
//	freopen("1984.out","w",stdout);
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=0;i<=n;i++)
			f[i]=i,point[i].x=point[i].y=0;
		for(int i=1;i<=m;i++)
			scanf("%d%d%d %c",&edge[i].fr,&edge[i].to,&edge[i].le,&edge[i].f);
		int k;
		scanf("%d",&k);
		for(int i=0;i<k;i++)
			scanf("%d%d%d",&ans_in[i].f1,&ans_in[i].f2,&ans_in[i].n),ans_in[i].count=i;
		sort(ans_in,ans_in+k,cmp);
		int nn=1;
		for(int i=0;i<k;i++)
		{
			int f1=ans_in[i].f1;
			int f2=ans_in[i].f2;
			int n=ans_in[i].n;
			int count=ans_in[i].count;
			for(;nn<=n;nn++)
			{
				if(edge[nn].f=='E')
					bing(edge[nn].fr,edge[nn].to,edge[nn].le,0);
				if(edge[nn].f=='W')
					bing(edge[nn].fr,edge[nn].to,-edge[nn].le,0);
				if(edge[nn].f=='N')
					bing(edge[nn].fr,edge[nn].to,0,edge[nn].le);
				if(edge[nn].f=='S')
					bing(edge[nn].fr,edge[nn].to,0,-edge[nn].le);
			} 
			int ff1=find(f1);
			int ff2=find(f2);
			if(ff1!=ff2)
				ans_out[count]=-1;
			else
				ans_out[count]=abss(point[f1].x-point[f2].x)+abss(point[f1].y-point[f2].y);
		}
		for(int i=0;i<k;i++)
			printf("%lld\n",ans_out[i]);
	}
}
