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
int n;
double price=0,d1,d2,c,p1,maxs;
struct jia
{
	double pn;
	double dn;
}z[7];
bool cmp(jia x,jia y)
{
	return x.dn<y.dn;
}
void start(int now,double sh)
{
	int minn;
	double minp=10000000000;
	for(int i=now+1;i<=n;i++)
	{
		if(z[i].dn>z[now].dn+maxs)
			break;
		if(z[i].pn<minp)
		{
			minp=z[i].pn;
			minn=i;
		}
	}
	if(z[now].pn<=minp&&z[now].dn+maxs>=d1)
	{
		price+=((d1-z[now].dn)/d2-sh)*z[now].pn;
		printf("%.2lf\n",price);
		exit(0);
	}
	if(minp==10000000000)
	{
		printf("No Solution\n");
		exit(0);
	}
	if(z[now].pn<minp)
	{
			price+=(c-sh)*z[now].pn;
			sh=c-(z[minn].dn-z[now].dn)/d2;
	}   
	else
	{
		price+=((z[minn].dn-z[now].dn)/d2-sh)*z[now].pn;
		sh=0.0;
	}
	start(minn,sh);
}


int main()
{
 	freopen("1016.in","r",stdin);
//	freopen("1016.out","w",stdout);
	cin>>d1>>c>>d2>>p1>>n;
	z[0].dn=0;
	z[0].pn=p1;
	for(int i=1;i<=n;i++)
		cin>>z[i].dn>>z[i].pn;
	maxs=c*d2;
	sort(z+1,z+n+1,cmp);
	start(0,0.0);	

	fclose(stdin);
	fclose(stdout);
 	return 0;
}