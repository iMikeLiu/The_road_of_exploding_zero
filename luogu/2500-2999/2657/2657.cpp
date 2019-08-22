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
LL f[15][15],p[15];
#define F(i,j,n) for(int i=j;i<=n;i++)
#define D(i,j,n) for(int i=j;i>=n;i--)
inline LL calc(int n)
{
	if (!n)
		return 0;
	LL ret=0;int x=1,pre=1000,now;
	while(p[x]<=n)
		x++;
	for(int i=1;i<x;i++) 
		for(int j=1;j<=9;j++)
			ret+=f[j][i];
	for(int i=x;i>=1;i--)
	{
		now=n/p[i-1];
		if (i==x)
		{
			for(int j=1;j<now;j++)
				if(abs(pre-j)>=2)
					ret+=f[j][i];
		}
		else if(i==1)
		{
			for(int j=0;j<=now;j++)
				if(abs(pre-j)>=2)
					ret+=f[j][i];
		}
		else
			for(int j=0;j<now;j++)
				if (abs(pre-j)>=2) 
					ret+=f[j][i];

		if(abs(pre-now)<2)
			break;
		pre=now;
		n%=p[i-1];
	}
	return ret;
}

int main()
{
 	freopen("2657.in","r",stdin);
// 	freopen("2657.out","w",stdout);
	int a=read(),b=read();
	p[0]=1;
	for(int i=1;i<=10;p[i]=p[i-1]*10,i++);
	for(int i=0;i<=9;f[i][1]=1,i++);
	for(int i=2;i<=10;i++) 
		for(int j=0;j<=9;j++)
			for(int k=0;k<=9;k++)
				if(abs(j-k)>=2)
					f[j][i]+=f[k][i-1];
	printf("%lld\n",calc(b)-calc(a-1));

	fclose(stdin);
	fclose(stdout);
 	return 0;
}