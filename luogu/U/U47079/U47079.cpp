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
I int read()
{
	R int x;R bool f;R char c;
	for (f=0; (c=getchar())<'0'||c>'9'; f=c=='-');
	for (x=c-'0'; (c=getchar())>='0'&&c<='9'; x=(x<<3)+(x<<1)+c-'0');
	return f?-x:x;
}
#define MAXN 100000
LL a[MAXN],b[MAXN];
bool cmp1(LL a,LL b){return a>b;}
bool cmp2(LL a,LL b){return a<b;}


int main()
{
 	freopen("U47079.in","r",stdin);
// 	freopen("U47079.out","w",stdout);
	LL t=read();
	while(t--)
	{
		LL n=read(),m=read();
		for(LL i=0;i<n;a[i]=read(),i++);
		for(LL i=0;i<m;b[i]=read(),i++);
		sort(a,a+n,cmp1);
		sort(b,b+m,cmp2);
		LL ans=0;
		for(LL i=0,tmp=a[i]-b[i],nn=min(n,m);i<nn;i++,ans+=tmp,tmp=a[i]-b[i])
			if(tmp<0)
				break;
		cout<<ans;putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
 	return 0;
}