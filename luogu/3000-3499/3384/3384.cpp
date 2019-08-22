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
#define L long#include <iostream>
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
#define MAXN 500001
struct node{
	LL to,next;
}e[500001];
LL rt,ha;
LL head[500001],dep[500001],sum[500001],a[500001];
LL tot,num,n,m,lazy[500001],fa[500001],l[500001];
LL ch[500001],top[500001],size[500001],son[500001];
void build(int root,int l,int r)
{
	if(l==r)
	{
		sum[root]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(root<<1,l,mid);
	build(root<<1|1,mid+1,r);
	sum[root]=sum[root<<1]+sum[root<<1|1];sum[root]%=ha;
	return ;
}

void push(int root,int l,int r)
{
	int mid=(l+r)>>1;
	lazy[root<<1]+=lazy[root];lazy[root<<1]%=ha;
	lazy[root<<1|1]+=lazy[root];lazy[root<<1|1]%=ha;
	sum[root<<1]+=lazy[root]*(mid-l+1);sum[root<<1]%=ha;
	sum[root<<1|1]+=lazy[root]*(r-mid);sum[root<<1|1]%=ha;
	lazy[root]=0;
	return ;
}

void update(int root,int left,int right,int l,int r,LL k)
{
	if(l<=left&&r>=right)
	{
		sum[root]+=k*(right-left+1);sum[root]%=ha;
		lazy[root]+=k;lazy[root]%=ha;
		return;
	}
	if(left>r||right<l)
		return;
	int mid=(left+right)>>1;
	if(lazy[root])
		push(root,left,right);
	if(mid>=l)
		update(root<<1,left,mid,l,r,k);
	if(mid<r)
		update(root<<1|1,mid+1,right,l,r,k);
	sum[root]=(sum[root<<1|1]+sum[root<<1])%ha;
	return;
}

LL query(int root,int left,int right,int l,int r)
{
	if(l<=left&&r>=right)
		return sum[root]%ha;
	if(left>r||right<l)
		return 0;
	int mid=(left+right)>>1;
	if(lazy[root])
		push(root,left,right);
	LL a=0,b=0;
	if(mid>=l)
		a=query(root<<1,left,mid,l,r);
	if(mid<r) 
		b=query(root<<1|1,mid+1,right,l,r);
	return (a%ha+b%ha)%ha;
}


void dfs1(int x)
{
	size[x]=1;
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
		if(!dep[v])
		{
			dep[v]=dep[x]+1;
			fa[v]=x;
			dfs1(v);
			size[x]+=size[v];
			if(size[v]>size[son[x]])
				son[x]=v;
		}
	}
}

void dfs2(int x,int t)
{
	l[x]=++tot;a[tot]=ch[x];top[x]=t;
	if(son[x])dfs2(son[x],t);
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v!=fa[x]&&v!=son[x])
			dfs2(v,v);
	}
	return ;
}

LL cal1(int x,int y)//查询路径值
{
	LL maxx=0;
	int fx=top[x],fy=top[y];
	while(fx!=fy)
	{
		if(dep[fx]<dep[fy])
			swap(x,y),swap(fx,fy);
		maxx+=query(1,1,tot,l[fx],l[x]);
		x=fa[fx];
		fx=top[x];
	}
	if(l[x]>l[y])
		swap(x,y);
	maxx+=query(1,1,tot,l[x],l[y]);
	return maxx;
}

void cal2(int x,int y,int v)//维护路径加值
{
	int fx=top[x],fy=top[y];
	while(fx!=fy)
	{
		if(dep[fx]<dep[fy])
			swap(x,y),swap(fx,fy);
		update(1,1,tot,l[fx],l[x],v);
		x=fa[fx],fx=top[x];
	}
	if(l[x]>l[y])
		swap(x,y);
	update(1,1,tot,l[x],l[y],v);
}
void add(int from,int to)
{
	num++;
	e[num].to=to;
	e[num].next=head[from];
	head[from]=num;
}
int main()
{
 	freopen("3384.in","r",stdin);
// 	freopen("3384.out","w",stdout);
	n=read(),m=read(),rt=read(),ha=read();
	for(int i=1;i<=n;i++)
		ch[i]=read(),ch[i]%=ha;
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		add(x,y),add(y,x);
	}
	dep[rt]=1;
	fa[rt]=1;
	dfs1(rt);
	dfs2(rt,rt);
	build(1,1,n);
	while(m--)
	{
		int coazuo=read();
		if(coazuo==1)
		{
			int x=read(),y=read(),z=read();
			cal2(x,y,z%ha);
		}
		if(coazuo==2)
			printf("%lld\n",cal1(read(),read())%ha);
		if(coazuo==3)
		{
			int x=read(),y=read();
			update(1,1,n,l[x],l[x]+size[x]-1,y%ha);
		}
		if(coazuo==4)
		{
			int x=read();
			printf("%lld\n",query(1,1,n,l[x],l[x]+size[x]-1)%ha);
		}
	}
	fclose(stdin);
	fclose(stdout);
 	return 0;
}
}
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
#define MAXN 500001
struct edge_struct
{
	int to,nxt;
};
edge_struct edge[MAXN];
int head[MAXM],cnt;
I void add_edge(int u,v)
{
	
}



int main()
{
 	freopen("3384.in","r",stdin);
// 	freopen("3384.out","w",stdout);
	

	fclose(stdin);
	fclose(stdout);
 	return 0;
}