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
I char readc()
{
	char c;
	for (;((c=getchar())<'A'||c>'Z')&&(c<'a'||c>'z'););
	return c;
}
I int read1()
{
	R int x;R char c;
	for(;((c=getchar())<'0'||c>'9'););
	return c-'0';
}
#define MAXN 100011
int data[MAXN];
struct treenode_struct
{
	bool like;
	bool fan;
	int fa;
	int cnt;
	treenode_struct()
	{
		like=0;
		fan=0;
		cnt=0;
		fa=0;
	}
}treenode[MAXN];
struct node
{
	int to,nxt;
}nodes[MAXN];
int cnt=0,head[MAXN];
void addedge(int from,int to)
{
	nodes[cnt].to=to;
	nodes[cnt].nxt=head[from];
	head[from]=cnt;
	cnt++;
}
LL data[MAXN];
void pushup(LL rt)
{
	treenode[rt].cnt=treenode[rt<<1].val+treenode[rt<<1|1].val;
}
void update(LL i,LL l,LL r)
{
	treenode[i].like=!treenode[i].like;
	
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
    pushup(rt);   	
}
LL query(LL ll,LL rr,LL l,LL r,LL rt)
{  
    if(ll<=l&&r<=rr)
        return treenode[rt].val;  
    LL m=(l+r)>>1;  
    pushdown(rt,m-l+1,r-m);   
    LL ans=0;  
    if(ll<=m) ans+=query(ll,rr,l,m,rt<<1);  
    if(rr>m) ans+=query(ll,rr,m+1,r,rt<<1|1);  
    return ans;  
} 

int main()
{
 	freopen("866.in","r",stdin);
 	freopen("866.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=n;data[i]=read1(),i++);
	
	
	
	
	fclose(stdin);
	fclose(stdout);
 	return 0;
}