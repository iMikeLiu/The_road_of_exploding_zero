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
#define MAXN 100010
int f[MAXN];
int dp[MAXN];
bool dfs(int x)
{
	int &ans=dp[x];
	if(ans!=-1)
		return ans;
	if(x<10)
		return ans=1;
	int maxn=-1,minn=10,xx=x;
	while(xx)
	{
		if(xx%10!=0)
			minn=min(minn,xx%10);
		maxn=max(maxn,xx%10);
		xx/=10;
	}
	if(!dfs(x-minn))
		return ans=1;
	if(!dfs(x-maxn))
		return ans=1;
	return ans=0;
}
int main()
{
 	freopen("319.in","r",stdin);
// 	freopen("319.out","w",stdout);
	memset(dp,-1,sizeof(dp));
	int t=read();
	while(t--)
	{
		int n=read(),k=read(),m=read();
		f[1]=0;
		for(int i=2;i<n;i++)
			f[i]=(f[i-1]+k)%i;
		f[n]=(f[n-1]+m)%n;
		f[n]++;
 		dfs(f[n]);
		cout<<(dp[f[n]]?"TAK\n":"NIE\n");
	}
	fclose(stdin);
	fclose(stdout);
 	return 0;
}