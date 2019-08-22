#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<map>
#include<ctime>
#include<queue>
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

LL read()
{
	R LL x;R bool f;R char c;
	for(f=0;(c=getchar())<'0'||c>'9';f=c=='-');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';x=(x<<3)+(x<<1)+c-'0');
	return f?-x:x;
}


struct edge_struct
{
	int v,w,nxt;
}edge[500010];
int head[100010],cnt=0;
void addedge(int u,int v,int w)
{
    edge[++cnt].v=v;
    edge[cnt].w=w;
    edge[cnt].nxt=head[u];
    head[u]=cnt;
}
int dis[100010];
struct node
{
	int u,d;
    bool operator <(const node& rhs) const
	{
        return d>rhs.d;
    }
};
void dijkstra(int s)
{
	dis[s]=0;
	priority_queue<node> q;
	q.push((node){s,0});
	while(!q.empty())
	{
		node now=q.top();q.pop();
		if(now.d!=dis[now.u])
			continue;
		for(int i=head[now.u];i;i=edge[i].nxt)
			if(dis[now.u]+edge[i].w<dis[edge[i].v])
				q.push((node){edge[i].v,(dis[edge[i].v]=edge[i].w+dis[now.u])});
	}
}
int main()
{
 	freopen("3371.in","r",stdin);
// 	freopen("3371.out","w",stdout);
	int n=read(),m=read(),s=read();
	for(int i=1;i<=n;i++)
		dis[i]=2147483647;
	for(int i=1;i<=m;i++)
	{
		int X=read(),Y=read(),Z=read();
        addedge(X,Y,Z);
	}
	dijkstra(s);
	for(int i=1;i<=n;i++)
		printf("%d ",dis[i]);
	fclose(stdin);
	fclose(stdout);
 	return 0;
}