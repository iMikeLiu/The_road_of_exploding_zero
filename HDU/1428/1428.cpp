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
#define MAXN 55
int mp[MAXN][MAXN];
int n;
struct node
{
	int x,y;
	node(int a,int b)
	{
		x=a;
		y=b;	
	}
};
int fang[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
LL mp_l[MAXN][MAXN];
LL ans[MAXN][MAXN];
void spfa()
{
	queue <node> q;
	q.push(node(n,n));
	while(!q.empty())
	{
		node now=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			int x=now.x+fang[i][0],y=now.y+fang[i][1];
			if(!(x>n||y>n||x<1||y<1))
				if(mp_l[x][y]>mp_l[now.x][now.y]+mp[x][y])
					mp_l[x][y]=mp_l[now.x][now.y]+mp[x][y],q.push(node(x,y));
		}
		
	}
		
}
LL get_ans(int x,int y)
{
	if(ans[x][y]!=-1)
		return ans[x][y];
	LL t=0;
	for(int i=0;i<4;i++)
	{
		int xx=x+fang[i][0],yy=y+fang[i][1];
		if(!(xx>n||yy>n||xx<1||yy<1))
			if(mp_l[xx][yy]<mp_l[x][y])
				t+=get_ans(xx,yy);
	}
	return ans[x][y]=t;
}
int main()
{
 	freopen("1428.in","r",stdin);
// 	freopen("1428.out","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		memset(mp_l,0x3f,sizeof(mp_l));
		memset(ans,-1,sizeof(ans));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&mp[i][j]);
		mp_l[n][n]=mp[n][n];
		spfa();
		ans[n][n]=1;
		cout<<get_ans(1,1)<<endl;
	}
	fclose(stdin);
	fclose(stdout);
 	return 0;
}
//ACS712

