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
I LL qmul(LL x,LL y,LL ha)
{
	return (x*y-(LL)(((L double)x*y)/ha)*ha)%ha;
}
const int ha=1e9+7;
#define MAXN 111
U LL cuo[MAXN];
I U LL get_cuo(U LL x)
{
	return x==1?0:cuo[x]==0?(cuo[x]=qmul((x-1),(get_cuo(x-1)+get_cuo(x-2)),ha)):cuo[x];
}

int main()
{
 	freopen("853.in","r",stdin);
// 	freopen("853.out","w",stdout);
	U LL n=read(),q=read(),kkk;
	cuo[1]=0;
	cuo[2]=1;
	printf("%lld\n",kkk=get_cuo(n));
	bool flag=false;
	for(int i=1;i<=q;i++)
	{
		int p=read(),v=read();
		flag|=(p==v);
		if(flag)
			printf("0\n");
		else
			printf("%lld\n",(kkk/=(n-1)));
			
	}
	fclose(stdin);
	fclose(stdout);
 	return 0;
}