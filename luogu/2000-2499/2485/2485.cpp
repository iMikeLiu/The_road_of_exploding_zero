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
LL qpow(LL a,LL b,LL k)
{
	LL r=1;
	while(b)
	{
		if(b&1)
			r=(r*a)%k;
		b>>=1;
		a=(a*a)%k;
	}
	return r;
}
LL exgcd(LL a,LL b,LL &x,LL &y)
{
	if(b==0)
	{
		x=1,y=0;
		return a;
	}
	R LL gcd=exgcd(b,a%b,x,y);
	R LL z=x;
	x=y;
	y=z-y*(a/b);
	return gcd;
}

map<int,int>mapp;
int main()
{
 	freopen("2485.in","r",stdin);
// 	freopen("2485.out","w",stdout);
	LL t=read(),k=read();
	if(k==1)
		while(t--)
		{
			R LL y=read(),z=read(),p=read();
			cout<<qpow(y,z,p)<<endl;
		}
	else if(k==2)
		while(t--)
		{
			R LL a=read(),b=read(),p=read(),x=0,y=0;
			R LL gcd=exgcd(a,p,x,y);
			if(b%gcd)
				printf("Orz, I cannot find x!\n");
			else
			{
				R LL temp=p/gcd;
				cout<<(((x*b/gcd)%temp+temp)%temp)<<endl;
			}
		}
	else if(k==3)
		while(t--)
		{
			R LL y=read(),z=read(),p=read();
			R LL m=ceil(sqrt(p));
			if(y%p==0&&z){printf("Orz, I cannot find x!\n");continue;}
			mapp.clear();
			R LL now=z%p,f=qpow(y,m,p);
			mapp[now]=0;
			for(R LL i=1;i<=m;i++)
			{
				now=(now*y)%p;
				mapp[now]=i;
			}
			now=1;
			R LL flag=1;
			for(R LL i=1;i<=m;i++)
			{
				now=(now*f)%p;
				if(mapp[now])
				{
					R LL ans=(i*m-mapp[now])%p;
					printf("%lld\n",(ans+p)%p);
					flag=0;
					break;
				}
			}
			if(flag)
				puts("Orz, I cannot find x!");			
		}
	fclose(stdin);
	fclose(stdout);
 	return 0;
}