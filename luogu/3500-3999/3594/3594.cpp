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
#include<queue>
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
#define MAXN 2000005
LL a[MAXN],pre[MAXN],t[MAXN];




int main()
{
 	freopen("3594.in","r",stdin);
// 	freopen("3594.out","w",stdout);
	LL n=read(),p=read(),d=read();
	for(int i=1;i<=n;i++)
 	 	a[i]=read();
	for(int i=1;i<=n;i++)
 	 	pre[i]=pre[i-1]+a[i];
 	std::deque<int> q;
	for(int i=d;i<=n;i++)
 	 	t[i]=pre[i]-pre[i-d];
 	LL ans=d;
 	q.push_back(d);
 	LL last=1;
 	for(int i=d+1;i<=n;i++)
 	{
 	 	while(!q.empty()&&t[i]>t[q.back()])
			q.pop_back();
 	 	q.push_back(i);
 	 	while(!q.empty()&&q.front()-d+1<last)
			q.pop_front();
 	 	while(!q.empty()&&pre[i]-pre[last-1]-t[q.front()]>p)
 	 	{
 	 	 	last++;
 	 	 	while(!q.empty()&&q.front()-d+1<last)
				q.pop_front();
 	 	}
 	 	ans=max(ans,i-last+1);
 	}
 	cout<<ans;
	
	
	
	

	fclose(stdin);
	fclose(stdout);
 	return 0;
}