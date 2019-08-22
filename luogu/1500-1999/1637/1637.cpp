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
#define START clock_t __start;__start = clock();
#define STOP fprintf(stderr,"\n\nUse Time:%fs\n",((double)(clock()-__start)/CLOCKS_PER_SEC));

#define MAXN 30001
using namespace std;
I LL read()
{
	R LL x;R bool f;R char c;
	for (f=0; (c=getchar())<'0'||c>'9'; f=c=='-');
	for (x=c-'0'; (c=getchar())>='0'&&c<='9'; x=(x<<3)+(x<<1)+c-'0');
	return f?-x:x;
}
struct data
{
	int num,pos;
}st[MAXN];
int n,cnt;
int sum[MAXN<<2],num[MAXN],bigger[MAXN],smaller[MAXN];
long long ans;
inline void push_up(int root)
{
	sum[root]=sum[root<<1]+sum[root<<1|1];
}
inline void update(int root,int l,int r,int pos)
{
	if(l==r && l==pos)
	{
		sum[root]++;
		return;
	}
	int mid=(l+r)>>1;
	if(mid>=pos)
		update(root<<1,l,mid,pos);
	if(mid<pos)
		update(root<<1|1,mid+1,r,pos);
	push_up(root);
}

inline int query(int root,int l,int r,int ll,int rr)
{
    if(ll<=l && r<=rr)
		return sum[root];
    int mid=(l+r)>>1,total=0;
    if(mid>=ll)
		total+=query(root<<1,l,mid,ll,rr);
    if(mid<rr)
		total+=query(root<<1|1,mid+1,r,ll,rr);
    return total; 
}

inline bool cmp(const data &a,const data &b)
{
    return a.num<b.num;
}
int main()
{
	freopen("1637.in","r",stdin);
//	freopen("1637.out","w",stdout);	
	n=read();
	for(int i=1;i<=n;i++)
		st[i].num=read(),st[i].pos=i;
	sort(st+1,st+n+1,cmp);
	for(int i=1;i<=n;i++) 
	{
		if(st[i].num>st[i-1].num)
			cnt++;
		num[st[i].pos]=cnt; 
	}
	for(int i=1;i<=n;i++)
	{
		if(num[i]>1)
			smaller[i]=query(1,1,n,1,num[i]-1);
		update(1,1,n,num[i]);
	}
	memset(sum,0,sizeof(sum));
	for(int i=n;i>=1;i--)
	{
		if(num[i]<n)
			bigger[i]=query(1,1,n,num[i]+1,n);
		update(1,1,n,num[i]);
	}
	for(int i=1;i<=n;i++)
		ans+=(bigger[i]*smaller[i]);
	printf("%lld",ans);
	return 0;
}
