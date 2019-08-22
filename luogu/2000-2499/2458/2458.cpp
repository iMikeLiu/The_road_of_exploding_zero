#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<map>
#define debug(x) cerr<<"\tdebug:"<<#x<<"="<<x<<endl
#define debugg(x,y) cerr<<"\tdebug;"<<x<<":"<<#y<<"="<<y<<endl
#define debugzu(x,edge,b) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=edge;i<b;i++)cerr<<x[i]<<" ";fprintf(stderr,"\n");
#define debugerzu(x,edge,b,c,d) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=edge;i<b;i++,fprintf(stderr,"\n\t"))for(int j=c;j<d;j++)cerr<<x[i][j]<<" ";fprintf(stderr,"\n");
#define R register
#define LL long long
#define I inline
using namespace std;
#define MAXN 10011
const int INF = 1e9;
struct edge_{int to,next;}edge[MAXN<<1];
int n,head[MAXN],cnt,val[MAXN],dp[3][MAXN];
void link(int u,int v)
{
    edge[++cnt]=(edge_){v,head[u]};
    head[u]=cnt;
}
void dfs(int u,int fa)
{
	int sum=0;
	dp[2][u]=val[u];
	for(int e=head[u];e;e=edge[e].next)
	{
		int v=edge[e].to;
		if(v==fa)
			continue;
		dfs(v,u);
		sum+=min(dp[1][v],dp[2][v]);
		dp[2][u]+=min(min(dp[0][v],dp[1][v]),dp[2][v]);		
	}
	dp[0][u]=sum;
	dp[1][u]=INF;	
    for (int e=head[u];e;e=edge[e].next)
    {
        int v=edge[e].to;
        if (v==fa) 
			continue;
        dp[1][u]=min(dp[1][u],sum-min(dp[1][v],dp[2][v])+dp[2][v]);
    }
}

int main()
{
 	freopen("2458.in","r",stdin);
// 	freopen("2458.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int u,k,v;
		scanf("%d",&u);
		scanf("%d",&val[u]);
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
			scanf("%d",&v),link(u,v),link(v,u);		
	}
	dfs(1,0);
    printf("%d\n",min(dp[1][1],dp[2][1]));
	fclose(stdin);
	fclose(stdout);
 	return 0;
}
