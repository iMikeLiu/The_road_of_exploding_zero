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
#define inf 0x3fffffff
int fx[4] = {-1, 0, 1, 0};
int fy[4] = {0, -1, 0, 1};
int f[110][110];
int mp[110][110];
int m, n, ans = inf;
void dfs(int x, int y, int sum, bool mofa)
{
    if(x<1||y<1||x>m||y>m)
		return;
	if(!mp[x][y])
		return;
	if(sum>=f[x][y])
		return;
	f[x][y]=sum;
	if(x==m&&y==m)
	{
		if(sum<ans)
			ans=sum;
		return;
	}
	for(int i=0;i<4;++i)
	{
		int xx=x+fx[i];
		int yy=y+fy[i];
		if(mp[xx][yy])
		{
			if(mp[xx][yy]==mp[x][y])
			dfs(xx,yy,sum,false);
			else
				dfs(xx,yy,sum+1,false);
		}
		else if(!mp[xx][yy]&&!mofa)
		{
			mp[xx][yy]=mp[x][y];
			dfs(xx,yy,sum+2,true);
			mp[xx][yy]=0;
		}
	}
}
int main()
{
	freopen("3956.in","r",stdin);
//	freopen("3956.out","w",stdout);
	memset(f,0x7f,sizeof(f));
	cin>>m>>n;
	for(int i=1;i<=n;++i)
	{
		int x,y,c;
		cin>>x>>y>>c;
		mp[x][y]=c+1;
	}
	dfs(1,1,0,false);
	if(ans==inf)
		cout<<-1;
	else
		cout<<ans;
	return 0;
}
