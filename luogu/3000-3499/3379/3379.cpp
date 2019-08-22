#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<map>
#define debuglog(x) cerr<<"\tdebug:"<<#x<<endl
#define debug(x) cerr<<"\tdebug:"<<#x<<"="<<x<<endl
#define debugg(x,y) cerr<<"\tdebug;"<<x<<":"<<#y<<"="<<y<<endl
#define debugzu(x,a,b) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++)cerr<<x[i]<<" ";fprintf(stderr,"\n");
#define debugerzu(x,a,b,c,d) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++,fprintf(stderr,"\n\t"))for(int j=c;j<d;j++)cerr<<x[i][j]<<" ";fprintf(stderr,"\n");
#define R register
#define LL long long
#define I inline
using namespace std;
#define MAXN 500011
struct edge_struct
{
	int t,nxt;
}edge[MAXN<<1];
int head[MAXN<<1],tot;
void add(int x,int y)
{
	edge[tot].t=y;
	edge[tot].nxt=head[x];
	head[x]=tot++;
}
int deep[MAXN];
int fa[MAXN][22];
void dfs(int f,int father)
{
	deep[f]=deep[father]+1;
	fa[f][0]=father;
	for(int i=1;(1<<i)<=deep[f];i++)
		fa[f][i]=fa[fa[f][i-1]][i-1];
	for(int i=head[f];i!=-1;i=edge[i].nxt)
		if(edge[i].t!=father)
			dfs(edge[i].t,f);
}
int lca(int x,int y)
{
	if(deep[x]>deep[y])
		swap(x,y);
	for(int i=20;i>=0;i--)
		if(deep[x]<=deep[y]-(1<<i))
			y=fa[y][i];
	if(x==y)
		return x;
	for(int i=20;i>=0;i--)
		if(fa[x][i]==fa[y][i])
			continue;
		else
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}


int main()
{
 	freopen("3379.in","r",stdin);
// 	freopen("3379.out","w",stdout);
	memset(head,-1,sizeof(head));
	int n,m,s;
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	dfs(s,0);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",lca(a,b));
	}

	fclose(stdin);
	fclose(stdout);
 	return 0;
}
