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
#define MAXN 1000011
struct treenode_struct
{
	LL max;
	treenode_struct()
	{
		max=0;
	}
}treenode[MAXN<<1];
LL data[MAXN];
void pushup(LL rt)
{
	treenode[rt].max=max(treenode[rt<<1].max,treenode[rt<<1|1].max);
}
void build(LL l,LL r,LL rt)
{
	if(l==r)
	{
		treenode[rt].max=data[l];
		return ;
	}
	LL m=(l+r)>>1;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
	pushup(rt);
}
LL query(LL ll,LL rr,LL l,LL r,LL rt)
{  
    if(ll<=l&&r<=rr)
        return treenode[rt].max;  
    LL m=(l+r)>>1;  
    LL ans=0;  
    if(ll<=m)
		ans=max(ans,query(ll,rr,l,m,rt<<1));  
    if(rr>m)
		ans=max(ans,query(ll,rr,m+1,r,rt<<1|1));  
    return ans;  
} 




int main()
{
 	freopen("865.in","r",stdin);
// 	freopen("865.out","w",stdout);
	int m=read()-1,n=0;
	while((data[++n]=read())!=-1);n--;
	build(1,n,1);
	for(int i=1;(i+m)<=n;i++)
		printf("%d\n",query(i,i+m,1,n,1));

	fclose(stdin);
	fclose(stdout);
 	return 0;
}
