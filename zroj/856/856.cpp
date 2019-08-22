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
bool check(int *a,int n)
{
	int last_0=0;
	for(;last_0<n&&(a[last_0]==0);last_0++);
	for(int i=last_0;i<n;i=last_0)
	{
		for(last_0=i+1;last_0<n&&(a[last_0]==0);last_0++);
		if(a[i]==a[last_0])
			return false;
	}
	return true;
}
#define MAXN 511

int a[MAXN];
int solve(int *a,int n,int cnt)
{
	if(cnt==n)
		return check(a,n);
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]!=0)
		{
			int buf=a[i];
			a[i]=0;
			if(check(a,n))
				ans=(ans+solve(a,n,cnt+1))%998244353;
			a[i]=buf;
		}
	}
	return ans%=998244353;
}

int main()
{
 	freopen("856.in","r",stdin);
 	freopen("856.out","w",stdout);
	int n=read();
	for(int i=0;i<n;a[i]=read(),i++);
	if(check(a,n))
		printf("%d",solve(a,n,0));
	else
		printf("0");
	

	fclose(stdin);
	fclose(stdout);
 	return 0;
}