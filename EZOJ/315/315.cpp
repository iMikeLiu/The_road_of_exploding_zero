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
struct edge
{
	int to,next;
}edges[MAXN<<1];
int head[MAXN<<1],cnt,now;
I void add(int from,int to)
{
	cnt++;
	edges[cnt].next=head[from];
	edges[cnt].to=to;
	head[from]=cnt;
}
int vis[MAXN<<1],match[MAXN<<1];
bool dfs(int u)
{
	for(int i=head[u],to;i>0;i=edges[i].next)
		if(vis[to=edges[i].to]!=now)
			if((vis[to]=now,true)&&(!match[to]||dfs(match[to])))
				return match[to]=u,1;
	return 0;
}
int main()
{
 	freopen("315.in","r",stdin);
// 	freopen("315.out","w",stdout);
	int n=read();
	for(int i=1,j,k;i<=n;add(read(),i+n),add(read(),i+n),i++);
	int ans=0;
	now=1;
	for(int i=1;i<=10000;i++,now++)
		if(dfs(i))
			ans++;
		else
			break;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
 	return 0;
}