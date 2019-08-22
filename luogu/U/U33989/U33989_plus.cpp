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
#define MAXN 100011
struct treenode_struct
{
	double val;
	double add;
	treenode_struct()
	{
		val=1;
		add=1;
	}
}treenode[MAXN<<1];
double data[MAXN];
void pushup(int rt)
{
	treenode[rt].val=treenode[rt<<1].val*treenode[rt<<1|1].val;
}
void build(int l,int r,int rt)
{
	if(l==r)
	{
		treenode[rt].val=data[l];
		return ;
	}
	int m=(l+r)>>1;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
	pushup(rt);
}
void update(int ll,double c,int l,int r,int rt)
{
	if(l==r)
	{
		treenode[rt].val*=(1-c);
		return;
	}
	int m=(l+r)>>1;
	if(ll<=m) update(ll,c,l,m,rt<<1);
	else update(ll,c,m+1,r,rt<<1|1);
	pushup(rt);
}
void pushdown(int rt,int ln,int rn)
{  
	if(treenode[rt].add!=1)
	{ 
		treenode[rt<<1].add*=treenode[rt].add;  
		treenode[rt<<1|1].add*=treenode[rt].add;  
        treenode[rt<<1].val*=treenode[rt].add*ln;  
        treenode[rt<<1|1].val*=treenode[rt].add*rn;  
        treenode[rt].add=1;  
    }
}  
void updatequjian(int ll,int rr,double c,int l,int r,int rt)
{
	if(ll<= l && r <= rr)
	{  
		treenode[rt].val*=(1-c)*(r-l+1);
		treenode[rt].add*=(1-c);
        return ;   
    }
    int m=(l+r)>>1;  
    pushdown(rt,m-l+1,r-m);  
    if(ll<=m) updatequjian(ll,rr,c,l,m,rt<<1);  
    if(rr>m) updatequjian(ll,rr,c,m+1,r,rt<<1|1);   
    pushup(rt);//更新本节点信息   	
}
double query(int ll,int rr,int l,int r,int rt)
{  
    if(ll<=l&&r<=rr)
        return treenode[rt].val;  
    int m=(l+r)>>1;  
    //下推标记，否则Sum可能不正确  
    pushdown(rt,m-l+1,r-m);   
    //累计答案  
    int ans=1;  
    if(ll<=m) ans*=query(ll,rr,l,m,rt<<1);  
    if(rr>m) ans*=query(ll,rr,m+1,r,rt<<1|1);  
    return ans;  
}   




int main()
{
 	freopen("U33989.in","r",stdin);
// 	freopen("U33989.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lf",&data[i]);
	build(1,n,1);
	for(int i=0;i<m;i++)
	{
		int a;
		scanf("%d",&a);
		if(a)
		{
			int l,r;
			double t;
			scanf("%d%d%lf",&l,&r,&t);
			updatequjian(l,l,t,1,n,1);
		}
		else
		{
			int l,r;
			double ans=1;
			scanf("%d%d",&l,&r);
			printf("%.6lf\n",query(l,r,1,n,1));
		}
	}	


	fclose(stdin);
	fclose(stdout);
 	return 0;
}
