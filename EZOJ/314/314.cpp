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
#include<ctime>
#define debuglog(x) cerr<<"\tdebug:"<<#x<<endl
#define debug(x) cerr<<"\tdebug:"<<#x<<"="<<(x)<<endl
#define debugg(x,y) cerr<<"\tdebug;"<<(x)<<":"<<#y<<"="<<(y)<<endl
#define debugzu(x,a,b) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++)cerr<<x[i]<<" ";fprintf(stderr,"\n");
#define debugerzu(x,a,b,c,d) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++,fprintf(stderr,"\n\t"))for(int j=c;j<d;j++)cerr<<x[i][j]<<" ";fprintf(stderr,"\n");
#define R register
#define L long
#define LL long long
#define I inline
#define U unsigned
#define START clock_t __start=clock();
#define STOP fprintf(stderr,"\n\nUse Time:%fs\n",((double)(clock()-__start)/CLOCKS_PER_SEC));
using namespace std;
I LL read()
{
	R LL x;R bool f;R char c;
	for (f=0; (c=getchar())<'0'||c>'9'; f=c=='-');
	for (x=c-'0'; (c=getchar())>='0'&&c<='9'; x=(x<<3)+(x<<1)+c-'0');
	return f?-x:x;
}
#define MAXN 310
int mapp[MAXN][MAXN];
bool vis[MAXN][MAXN];
struct node
{
	friend bool operator < (node a,node b){return a.h>b.h;}
	node(int xx,int yy,int hh){x=xx,y=yy,h=hh;}
	int x,y,h;
};
priority_queue<node> q;
int fang[][2]={{-1,0},{1,0},{0,-1},{0,1}};
int main()
{
 	freopen("314.in","r",stdin);
// 	freopen("314.out","w",stdout);
	int m=read(),n=read();
	for(int i=1;i<=n;i++)for(int j=1;j<=m;mapp[i][j]=read(),j++);
	for(int i=1;i<=n;q.push(node(i,1,mapp[i][1])),q.push(node(i,m,mapp[i][m])),vis[i][1]=vis[i][m]=true,i++)
	for(int i=2;i<m;q.push(node(1,i,mapp[1][i])),q.push(node(n,i,mapp[n][i])),vis[1][i]=vis[n][i]=true,i++);
	int ans=0;
	while(!q.empty())
	{
		node tmp=q.top();
		q.pop();
		for(int i=0;i<4;i++)
		{
			int tx=tmp.x+fang[i][0],ty=tmp.y+fang[i][1];
			if(vis[tx][ty]||tx<1||ty<1||tx>n||ty>m)
				continue;
			if(tmp.h>mapp[tx][ty])
				ans+=tmp.h-mapp[tx][ty],mapp[tx][ty]=tmp.h;
			vis[tx][ty]=true;
			q.push(node(tx,ty,mapp[tx][ty]));
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
 	return 0;
}