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
#define MAXN 100005
long long a[MAXN];



int main()
{
 	freopen("5178.in","r",stdin);
// 	freopen("5178.out","w",stdout);
	int t=read();
	while(t--)
	{
		LL ans=0,n=read(),k=read(),st=1,en=2;
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		sort(a+1,a+1+n);
		a[n+1]=a[n]+2*k;
		while(st<n)
			if(a[en]-a[st]<=k)
				en++;
			else
				ans+=en-st-1,st++;			
		printf("%lld\n",ans);
	}
	
	
	

	fclose(stdin);
	fclose(stdout);
 	return 0;
}