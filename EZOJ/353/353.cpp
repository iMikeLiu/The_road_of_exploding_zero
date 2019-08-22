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
#define MAXN 10011
#define MAXK 111
struct edge_struct{
	int nxt,to;
}edge[MAXN];
int head[MAXN],f[MAXN][MAXK],cnt;
void addedge(int u,int v)
{
	edge[++cnt].nxt=head[u];
	edge[cnt].to=v;
	head[u]=cnt;
	edge[++cnt].nxt=head[v];
	edge[cnt].to=u;
	head[v]=cnt;	
}
int dfs(int u,int fa,int k)
{
	f[u][0]=1;
	int ans=0;
	for(int i=head[u];i;i=edge[i].nxt)
	{
		if(edge[i].to==fa)
			continue;
		ans+=dfs(edge[i].to,u,k);
		for(int j=0;j<k;++j)
			ans+=f[edge[i].to][j]*f[u][k-1-j];
        for(int j=1;j<=k;++j)
			f[u][j]+=f[edge[i].to][j-1];
	}
	return ans;
}
int main()
{
 	freopen("353.in","r",stdin);
// 	freopen("353.out","w",stdout);
	int n=read(),k=read();
	for(int i=0;i<n-1;addedge(read(),read()),i++);
	printf("%d\n",dfs(1,0,k));
	fclose(stdin);
	fclose(stdout);
 	return 0;
}