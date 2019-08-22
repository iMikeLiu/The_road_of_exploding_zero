#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<map>
#include<queue>
#define debuglog(x) cerr<<"\tdebug:"<<#x<<endl
#define debug(x) cerr<<"\tdebug:"<<#x<<"="<<x<<endl
#define debugg(x,y) cerr<<"\tdebug;"<<x<<":"<<#y<<"="<<y<<endl
#define debugzu(x,a,b) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++)cerr<<x[i]<<" ";fprintf(stderr,"\n");
#define debugerzu(x,a,b,c,d) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++,fprintf(stderr,"\n\t"))for(int j=c;j<d;j++)cerr<<x[i][j]<<" ";fprintf(stderr,"\n");
#define R register
#define LL long long
#define I inline
using namespace std;
#define MAXN 111
int cheese[MAXN][MAXN];
int n,k;
int ans[MAXN][MAXN];
int dfs(int x,int y)
{
	if(ans[x][y]!=-1)
		return ans[x][y];
	ans[x][y]=cheese[x][y];
	for(int i=max(1,x-k);i<x;i++)
        if(cheese[i][y]>cheese[x][y])
            ans[x][y] = max(ans[x][y],dfs(i,y)+cheese[x][y]);
    for(int i=max(1,y-k);i<y;i++)
        if(cheese[x][i]>cheese[x][y])
            ans[x][y] = max(ans[x][y],dfs(x,i)+cheese[x][y]);
    for(int i=x+1;(i<=n&&i<=x+k);i++)
        if(cheese[i][y]>cheese[x][y])
            ans[x][y]=max(ans[x][y],dfs(i,y)+cheese[x][y]);
    for(int i=y+1;(i<=n&&i<=y+k);i++)
        if(cheese[x][i]>cheese[x][y])
            ans[x][y]=max(ans[x][y],dfs(x,i)+cheese[x][y]);
	return ans[x][y];
}
int main()
{
 	freopen("1078.in","r",stdin);
// 	freopen("1078.out","w",stdout);
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		if(n==-1&&k==-1)
			break ;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&cheese[i][j]);
		memset(ans,-1,sizeof(ans));
		cout<<dfs(1,1)<<endl;
	}
	fclose(stdin);
	fclose(stdout);
 	return 0;
}

