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
#define MAXN 400010
#define MAXM 900010
#define INF 2147483647000000
struct edge
{
 	LL u,v,d;
 	LL next;
}g[MAXN<<1];
LL cnt,head[MAXN],bz[MAXN][19],maxi[MAXN][19],mini[MAXN][19],deep[MAXN];
I void addedge(LL u,LL v,LL d)
{
 	g[++cnt].u=u,g[cnt].v=v,g[cnt].d=d,g[cnt].next=head[u],head[u]=cnt;
 	g[++cnt].u=v,g[cnt].v=u,g[cnt].d=d,g[cnt].next=head[v],head[v]=cnt;
}

I void dfs(LL u,LL fa)
{
 	bz[u][0]=fa;
 	for(LL i=head[u];i;i=g[i].next)
 	{
 	 	LL v=g[i].v;
 	 	if(v==fa)
			continue;
 	 	deep[v]=deep[u]+1ll;
 	 	maxi[v][0]=g[i].d;
 	 	mini[v][0]=-INF;
 	 	dfs(v,u);
 	}
}
LL n;
I void cal()
{
 	for(LL i=1;i<=18;++i)
 	 	for(LL j=1;j<=n;++j)
 	 	{
 	 	 	bz[j][i]=bz[bz[j][i-1]][i-1];
 	 	 	maxi[j][i]=max(maxi[j][i-1],maxi[bz[j][i-1]][i-1]);
 	 	 	mini[j][i]=max(mini[j][i-1],mini[bz[j][i-1]][i-1]);
 	 	 	if(maxi[j][i-1]>maxi[bz[j][i-1]][i-1])
				mini[j][i]=max(mini[j][i],maxi[bz[j][i-1]][i-1]);
 	 	 	else if(maxi[j][i-1]<maxi[bz[j][i-1]][i-1])
				mini[j][i]=max(mini[j][i],maxi[j][i-1]);
 	 	}
}
I LL LCA(LL x,LL y)
{
 	if(deep[x]<deep[y])
		swap(x,y);
 	for(LL i=18;i>=0;--i)
 	 	if(deep[bz[x][i]]>=deep[y])
 	 	 	x=bz[x][i];
 	if(x==y)
		return x;
 	for(LL i=18;i>=0;--i)
 	 	if(bz[x][i]^bz[y][i])
 	 	 	x=bz[x][i],y=bz[y][i];
 	return bz[x][0];
}

I LL qmax(LL u,LL v,LL maxx)
{
 	LL ans=-INF;
 	for(LL i=18;i>=0;--i)
 	{
 	 	if(deep[bz[u][i]]>=deep[v])
 	 	{
 	 	 	if(maxx!=maxi[u][i])
				ans=max(ans,maxi[u][i]);
 	 	 	else 
				ans=max(ans,mini[u][i]);
 	 	 	u=bz[u][i];
 	 	}
 	}
 	return ans;
}
LL m;
edge a[MAXM<<1];
I bool cmp(edge x,edge y)
{
 	return x.d<y.d;
}
LL father[MAXN];
I LL get_f(LL x)
{
 	return (x==father[x])?x:father[x]=get_f(father[x]);
}
bool B[MAXM<<1];
int main()
{
 	freopen("4180.in","r",stdin);
// 	freopen("4180.out","w",stdout);
	n=read(),m=read();
 	for(LL i=1;i<=m;a[i].u=read(),a[i].v=read(),a[i].d=read(),i++);
 	sort(a+1,a+m+1,cmp);
 	for(LL i=1;i<=n;++i)
 	 	father[i]=i;
 	LL c=0ll;
 	for(LL i=1;i<=m;++i)
 	{
 	 	LL Father_u=get_f(a[i].u);
 	 	LL Father_v=get_f(a[i].v);
 	 	if(Father_u!=Father_v)
 	 	{
 	 	 	c+=a[i].d;
 	 	 	father[Father_u]=Father_v;
 	 	 	addedge(a[i].u,a[i].v,a[i].d);
 	 	 	B[i]=true;
 	 	}
 	}
 	mini[1][0]=-INF;
 	deep[1]=1;
 	dfs(1,-1);
 	cal();
 	LL ans=INF;
 	for(LL i=1;i<=m;++i)
 	 	if(!B[i])
 	 	{
 	 	 	LL lca=LCA(a[i].u,a[i].v);
 	 	 	ans=min(ans,c-max(qmax(a[i].u,lca,a[i].d),qmax(a[i].v,lca,a[i].d))+a[i].d);
 	 	}
 	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
 	return 0;
}