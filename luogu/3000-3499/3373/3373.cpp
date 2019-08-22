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
	LL mul;
	treenode_struct()
	{
		val=0;
		add=0;
		mul=1;
	}
}treenode[MAXN<<1];
LL data[MAXN];
int ha;
void pushup(LL rt)
{
	treenode[rt].val=(treenode[rt<<1].val+treenode[rt<<1|1].val)%ha;
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
	if(ll<=m) 
		update(ll,c,l,m,rt<<1);
	else
		update(ll,c,m+1,r,rt<<1|1);
	pushup(rt);
}
void pushdown(LL rt,LL ln,LL rn)
{
	treenode[rt<<1].val=(treenode[rt].add*ln+treenode[rt].mul*treenode[rt<<1].val)%ha;  
	treenode[rt<<1|1].val=(treenode[rt].add*rn+treenode[rt].mul*treenode[rt<<1|1].val)%ha;  

	treenode[rt<<1].mul=(treenode[rt<<1].mul*treenode[rt].mul)%ha;
	treenode[rt<<1|1].mul=(treenode[rt<<1|1].mul*treenode[rt].mul)%ha;
	
	
	treenode[rt<<1].add=(treenode[rt<<1].add*treenode[rt].mul+treenode[rt].add)%ha;  
	treenode[rt<<1|1].add=(treenode[rt<<1|1].add*treenode[rt].mul+treenode[rt].add)%ha;  

	treenode[rt].add=0;
	treenode[rt].mul=1; 
}  
void updatequjian_add(LL ll,LL rr,LL c,LL l,LL r,LL rt)
{
	if(ll<= l && r <= rr)
	{  
		treenode[rt].val=(treenode[rt].val+(c)*(r-l+1))%ha;
		treenode[rt].add=(treenode[rt].add+(c))%ha;
        return ;   
    }
    LL m=(l+r)>>1;  
    pushdown(rt,m-l+1,r-m);  
    if(ll<=m)
		updatequjian_add(ll,rr,c,l,m,rt<<1);  
    if(rr>m)
		updatequjian_add(ll,rr,c,m+1,r,rt<<1|1);   
    pushup(rt);
}
void updatequjian_mul(LL ll,LL rr,LL c,LL l,LL r,LL rt)
{
	if(ll<=l&&r<=rr)
	{  
		treenode[rt].val=treenode[rt].val*(c)%ha;
		treenode[rt].mul=treenode[rt].mul*(c)%ha;
		treenode[rt].add=treenode[rt].add*(c)%ha;
        return ;   
    }
    LL m=(l+r)>>1;  
    pushdown(rt,m-l+1,r-m);  
    if(ll<=m)
		updatequjian_mul(ll,rr,c,l,m,rt<<1);  
    if(rr>m)
		updatequjian_mul(ll,rr,c,m+1,r,rt<<1|1);   
    pushup(rt);
}
LL query(LL ll,LL rr,LL l,LL r,LL rt)
{  
    if(ll<=l&&r<=rr)
        return treenode[rt].val;  
    LL m=(l+r)>>1;  
    pushdown(rt,m-l+1,r-m);    
    LL ans=0;  
    if(ll<=m)
		ans+=query(ll,rr,l,m,rt<<1);  
    if(rr>m)
		ans+=query(ll,rr,m+1,r,rt<<1|1);  
    return ans%ha;
} 




int main()
{
 	freopen("3373.in","r",stdin);
// 	freopen("3373.out","w",stdout);
	int n,m;
	scanf("%d%d%d",&n,&m,&ha);
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
			
			updatequjian_mul(l,r,t,1,n,1);
		}
		else if(a==2)
		{
			int l,r,t;
			scanf("%d%d%d",&l,&r,&t);
			
			updatequjian_add(l,r,t,1,n,1);
		}
		else if(a==3)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			printf("%lld\n",query(l,r,1,n,1)%ha);
		}
	}

	fclose(stdin);
	fclose(stdout);
 	return 0;
}
