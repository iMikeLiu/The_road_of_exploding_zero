#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<map>
#define debug(x) cerr<<"\tdebug:"<<#x<<"="<<x<<endl
#define debugg(x,y) cerr<<"\tdebug;"<<x<<":"<<#y<<"="<<y<<endl
#define debugzu(x,a,b) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++)cerr<<x[i]<<" ";fprintf(stderr,"\n");
#define debugerzu(x,a,b,c,d) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++,fprintf(stderr,"\n\t"))for(int j=c;j<d;j++)cerr<<x[i][j]<<" ";fprintf(stderr,"\n");
#define R register
#define LL long long
#define I inline
using namespace std;
I LL read()
{
	R LL x;R bool f;R char c;
	for (f=0; (c=getchar())<'0'||c>'9'; f=c=='-');
	for (x=c-'0'; (c=getchar())>='0'&&c<='9'; x=(x<<3)+(x<<1)+c-'0');
	return f?-x:x;
}
#define MAXN 100011
#define MAXM 100011
struct node 
{
	int id,a;
}f[MAXN];
struct boot
{
	int s,d,id;
}q[MAXM];
bool cmp_node(node a,node b)
{
	return a.a>b.a;
}
bool cmp_boot(boot a,boot b)
{
	return a.s>b.s;
}
bool ans[MAXM];
int nxt[MAXN],pre[MAXN];
int main()
{
	freopen("4265.in","r",stdin);
// 	freopen("4265.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=n;i++)
		f[i].a=read(),f[i].id=i;
	for(int i=1;i<=m;i++)
		q[i].s=read(),q[i].d=read(),q[i].id=i;
	sort(f+1,f+n+1,cmp_node);
	sort(q+1,q+m+1,cmp_boot);
	for(int i=1;i<=n;i++)
		nxt[i]=i+1,pre[i]=i-1;
	int dmax=0,tp=1;
	for(int i=1;i<=m;i++)
	{
		for(int j=tp;j<=n;j++)
		{
			if(f[j].a<=q[i].s)
			{
				tp=j;
				break;
			}
			nxt[pre[f[j].id]]=nxt[f[j].id];
			pre[nxt[f[j].id]]=pre[f[j].id];
			dmax=max(dmax,nxt[f[j].id]-pre[f[j].id]);
		}
		ans[q[i].id]=(dmax<=q[i].d);
	}
	int cnt=0;
	for(int i=1;i<=m;i++)
		if(!ans[i])
			cnt++;
	printf("%d",cnt-1);
	fclose(stdin);
	fclose(stdout);
 	return 0;
}
