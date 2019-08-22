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
#define MAXN 1000011
struct treenode_struct
{
	LL val;
	LL add;
	treenode_struct()
	{
		val=0;
		add=0;
	}
}treenode[MAXN<<1];
LL data[MAXN];
void pushup(LL rt)
{
	treenode[rt].val=treenode[rt<<1].val+treenode[rt<<1|1].val;
}
void build(LL l,LL r,LL rt)
{
	if(l==r)
	{
		treenode[rt].val=data[l];
		return ;
	}
	LL m=(l+r)>>1;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
	pushup(rt);
}
void update(LL ll,LL c,LL l,LL r,LL rt)
{
	if(l==r)
	{
		treenode[rt].val+=c;
		return;
	}
	LL m=(l+r)>>1;
	if(ll<=m) update(ll,c,l,m,rt<<1);
	else update(ll,c,m+1,r,rt<<1|1);
	pushup(rt);
}
void pushdown(LL rt,LL ln,LL rn)
{  
	if(treenode[rt].add)
	{ 
		treenode[rt<<1].add+=treenode[rt].add;  
		treenode[rt<<1|1].add+=treenode[rt].add;  
        treenode[rt<<1].val+=treenode[rt].add*ln;  
        treenode[rt<<1|1].val+=treenode[rt].add*rn;  
        treenode[rt].add=0;  
    }
}  
void updatequjian(LL ll,LL rr,LL c,LL l,LL r,LL rt)
{
	if(ll<= l && r <= rr)
	{  
		treenode[rt].val+=(c)*(r-l+1);
		treenode[rt].add+=(c);
        return ;   
    }
    LL m=(l+r)>>1;  
    pushdown(rt,m-l+1,r-m);  
    if(ll<=m) updatequjian(ll,rr,c,l,m,rt<<1);  
    if(rr>m) updatequjian(ll,rr,c,m+1,r,rt<<1|1);   
    pushup(rt);//更新本节点信息   	
}
LL query(LL ll,LL rr,LL l,LL r,LL rt)
{  
    if(ll<=l&&r<=rr)
        return treenode[rt].val;  
    LL m=(l+r)>>1;  
    //下推标记，否则Sum可能不正确  
    pushdown(rt,m-l+1,r-m);   
    //累计答案  
    LL ans=0;  
    if(ll<=m) ans+=query(ll,rr,l,m,rt<<1);  
    if(rr>m) ans+=query(ll,rr,m+1,r,rt<<1|1);  
    return ans;  
} 

int main()
{
 	freopen("3368.in","r",stdin);
// 	freopen("3368.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&data[i]);
	build(1,n,1);
	for(int i=0;i<m;i++)
	{
		int a;
		scanf("%d",&a);
		if(a==1)
		{
			int l,r,t;
			scanf("%d%d%d",&l,&r,&t);
			updatequjian(l,r,t,1,n,1);
		}
		else
		{
			int l;
			scanf("%d",&l);
			printf("%lld\n",query(l,l,1,n,1));
		}
	}

	fclose(stdin);
	fclose(stdout);
 	return 0;
}
