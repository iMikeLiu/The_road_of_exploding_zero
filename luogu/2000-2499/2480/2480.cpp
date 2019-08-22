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
#define STALLT clock_t __start=clock();
#define STOP fprintf(stderr,"\n\nUse Time:%fs\n",((double)(clock()-__start)/CLOCKS_PELL_SEC));
using namespace std;
I LL read()
{
	R LL x;R bool f;R char c;
	for (f=0; (c=getchar())<'0'||c>'9'; f=c=='-');
	for (x=c-'0'; (c=getchar())>='0'&&c<='9'; x=(x<<3)+(x<<1)+c-'0');
	return f?-x:x;
}
const LL YL=999911659,N=4e4,pr[4]={2,3,4679,35617};
LL f[N],fac[N],res[4],x,y,t;
LL qpow(LL b,LL k,LL p)
{
	LL a=1;
	for(;k;k>>=1,b=b*b%p)
		if(k&1)a=a*b%p;
	return a;
}
LL C(LL n,LL m,LL p)
{
	return n<m?0:fac[n]*qpow(fac[m]*fac[n-m],p-2,p)%p;
}
LL lucas(LL n,LL m,LL p)
{
	return m?C(n%p,m%p,p)*lucas(n/p,m/p,p)%p:1;
}
void exgcd(LL a,LL b)
{
	if(b)
		exgcd(b,a%b),t=x,x=y,y=t-a/b*y;
}
int main()
{
 	freopen("2480.in","r",stdin);
// 	freopen("2480.out","w",stdout);
	fac[0]=1;
	LL n,g,m,p=0,i,j,ans=0;
	scanf("%lld%lld",&n,&g);
	if(!(g%YL))
		return puts("0"),0;
	m=sqrt(n);
	for(i=1;i<=m;++i)
		if(!(n%i))
			f[++p]=i,f[++p]=n/i;
	p-=f[p-1]==f[p];
	for(i=0;i<4;++i)
	{
		for(j=1;j<pr[i];++j)
			fac[j]=fac[j-1]*j%pr[i];
		for(j=1;j<=p;++j)
			res[i]=(res[i]+lucas(n,f[j],pr[i]))%pr[i];
		x=1;y=0;
		exgcd(m=(YL-1)/pr[i],pr[i]);
		ans=(ans+res[i]*(x%pr[i]+pr[i])*m)%(YL-1);
	}
	printf("%lld\n",qpow(g,ans,YL));
	fclose(stdin);
	fclose(stdout);
 	return 0;
}