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
#define MAXN 200011
struct edge_struct
{
	int to,nxt;
};
edge_struct edge[MAXN];
int head[MAXN],cnt_edge;
I void add_edge(int u,int v)
{
	edge[cnt_edge].to=v;
	edge[cnt_edge].nxt=head[u];
	head[u]=cnt_edge++;
}
struct tree_struct
{
	int tag,w,lc,rc;
};
tree_struct tree[MAXN];
int num=1;
void build(int rt,int l,int r)
{
	tree[rt].tag=-1;
	if(l==r)
	{
		tree[rt].w=1;
		return;
	}
	int mid=(l+r)>>1;
	tree[rt].lc=++num;
	build(tree[rt].lc,l,mid);
	tree[rt].rc=++num;
	build(tree[rt].rc,mid+1,r);
	tree[rt].w=tree[tree[rt].rc].w+tree[tree[rt].lc].w;
}
I void pushdown(int rt,int l,int r)
{
	int mid=(l+r)>>1;
	tree[tree[rt].lc].w=tree[rt].tag*(mid-l+1);
	tree[tree[rt].lc].tag=tree[rt].tag;
	tree[tree[rt].rc].w=tree[rt].tag*(r-mid);
	tree[tree[rt].rc].tag=tree[rt].tag;
	tree[rt].tag=-1;
}
I void update(int rt,int l,int r,int ll,int rr,int v)
{
	if(l==ll&&r==rr)
	{
		tree[rt].w=v*(r-l+1);
		tree[rt].tag=v;
		return;
	}
	if(tree[rt].tag!=-1)
		pushdown(rt,l,r);
	int mid=(r+l)>>1;
	if(rr<=mid)
		update(tree[rt].lc,l,mid,ll,rr,v);
	else if(ll>mid)
		update(tree[rt].rc,mid+1,r,ll,rr,v);
	else
		update(tree[rt].lc,l,mid,ll,mid,v),update(tree[rt].rc,mid+1,r,mid+1,rr,v);
	tree[rt].w=tree[tree[rt].lc].w+tree[tree[rt].rc].w;
}
int query(int rt,int l,int r,int ll,int rr)
{
	if(l==ll&&r==rr)
		return tree[rt].w;
	if(tree[rt].tag!=-1)
		pushdown(rt,l,r);
	int mid=(r+l)>>1,ans=0;
	if(rr<=mid)
		ans+=query(tree[rt].lc,l,mid,ll,rr);
	else if(ll>mid)
		ans+=query(tree[rt].rc,mid+1,r,ll,rr);
	else
		ans+=(query(tree[rt].lc,l,mid,ll,mid)+query(tree[rt].rc,mid+1,r,mid+1,rr));
	return ans;
}
int son[MAXN],tot[MAXN],fa[MAXN],top[MAXN],id[MAXN],val[MAXN],bval[MAXN],d[MAXN];
int dfs1(int rt,int f,int l)
{
	d[rt]=l;
	fa[rt]=f;
	tot[rt]=1;
	int maxs=-20011217;
	for(int i=head[rt];i!=-1;i=edge[i].nxt)
	{
		tot[rt]+=dfs1(edge[i].to,rt,l+1);
		if(tot[edge[i].to]>maxs)
		{
			maxs=tot[edge[i].to];
			son[rt]=edge[i].to;
		}
	}
	return tot[rt];
}
int cnt_sp=0;
void dfs2(int rt,int firs)
{
	id[rt]=++cnt_sp;
	top[rt]=firs;
	if(!son[rt])
		return;
	dfs2(son[rt],firs);
	for(int i=head[rt];i!=-1;i=edge[i].nxt)
	{
		if(id[edge[i].to])
			continue;
		dfs2(edge[i].to,edge[i].to);
	}
}
int n;
I void chang(int x,int y,int v)
{
	while(top[x]!=top[y])
	{
		if(d[top[x]]<d[top[y]])
			swap(x,y);
		update(1,1,n,id[top[x]],id[x],v);
		x=fa[top[x]];
	}
	if(d[x]>d[y])
		swap(x,y);
	update(1,1,n,id[x],id[y],v);
}
I int sum(int x,int y)
{
	int ans=0;
	while (top[x]!=top[y])
	{   
		if (d[top[x]]<d[top[y]])
			swap(x,y);
		ans+=query(1,1,n,id[top[x]],id[x]);
		x=fa[top[x]];
	}
    if (d[x]>d[y])
		swap(x,y);
    ans+=query(1,1,n,id[x],id[y]);
	return ans;
}
I void tchange(int x,int v)
{
	update(1,1,n,id[x],id[x]+tot[x]-1,v);
}
I int tsum(int x)
{
	return tot[x]-query(1,1,n,id[x],id[x]+tot[x]-1);
}
int main()
{
 	freopen("2146.in","r",stdin);
// 	freopen("2146.out","w",stdout);
	memset(head,-1,sizeof(head));
	n=read();
	for(int i=2;i<=n;i++)
		add_edge(read()+1,i);
	dfs1(1,1,1);
	dfs2(1,1);
	build(1,1,n);
	for(int i=0,m=read();i<m;i++)
	{
		string caozuo;
		cin>>caozuo;
		int p=read()+1;
		if(caozuo=="install")
		{
			printf("%d\n",sum(p,1));
			chang(p,1,0);
		}
		else if(caozuo=="uninstall")
		{
			printf("%d\n",tsum(p));
			tchange(p,1);
		}
	}
	fclose(stdin);
	fclose(stdout);
 	return 0;
}