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
#define debugg(x,a) cerr<<"\tdebug;"<<(x)<<":"<<#a<<"="<<(a)<<endl
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
I U LL read()
{
	R U LL x;R bool f;R char c;
	for (f=0; (c=getchar())<'0'||c>'9'; f=c=='-');
	for (x=c-'0'; (c=getchar())>='0'&&c<='9'; x=(x<<3)+(x<<1)+c-'0');
	return f?-x:x;
}
U LL gcd(U LL a, U LL b)
{
	return b==0?a:gcd(b,a%b);
}
U LL qpow(U LL a,U LL b,U LL k)
{
	U LL r=1;
	while(b)
	{
		if(b&1)
			r=(r*a)%k;
		b>>=1;
		a=(a*a)%k;
	}
	return r;
}
U LL qpow(U LL a,U LL b)
{
	U LL r=1;
	while(b)
	{
		if(b&1)
			r=(r*a);
		b>>=1;
		a=(a*a);
	}
	return r;
}
I LL qmul(LL x,LL y,LL ha)
{
	return (x*y-(LL)(((L double)x*y)/ha)*ha)%ha;
}
map<U LL,U LL>mapp;
int main()
{
 	freopen("851.in","r",stdin);
// 	freopen("851.out","w",stdout);
	int n=read();
	while(n--)
	{
		U LL a=read(),b=read(),p=read(),e=read();
		p=qpow(p,e);
		debug(p);
		if(a%p==0&&b){puts("-1");continue;}
		mapp.clear();
		bool flag=true;
		R U LL cnt=0,t=1,s,x;
		for(R U LL d=gcd(a,p);d!=1;d=gcd(a,p))
		{
			debug(d);
			if(b%d)
			{
				puts("-1");
				flag=false;
				break;
			}
			cnt++;
			b/=d;
			p/=d;
			t=qmul(t,a/b,p);
			if(b==t)
			{
				printf("%lld\n",cnt);
				flag=false;
				break;
			}				
		} 
		
		
		R U LL m=ceil(sqrt(p));
		R U LL now=b%p,f=qpow(a,m,p);
		mapp[now]=0;
		for(R U LL i=1;i<=m;i++)
		{
			now=qmul(now,a,p);
			mapp[now]=i;
		}
		now=1;
		for(R U LL i=1;i<=m;i++)
		{
			now=(now*f)%p;
			if(mapp[now])
			{
				R U LL ans=(qmul(i,m,p)-mapp[now]+cnt)%p;
				printf("%lld\n",(ans+p)%p);
				flag=false;
				break;
			}
		}
		if(flag)
			puts("-1");
	}
	fclose(stdin);
	fclose(stdout);
 	return 0;
}