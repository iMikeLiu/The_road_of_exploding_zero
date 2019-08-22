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
#define MAXN 100011
int a[MAXN];
int dis[MAXN];
int n,m,w;
bool can(int x)
{
	memset(dis,0,sizeof(dis));
	int i,p,hs=m;
	for(i=1;i<=n;++i)
	{
		dis[i]+=a[i]+dis[i-1]-a[i-1];
		p=x-dis[i];
		if(p>0)
		{
			if(p>hs)
				return false;
			hs-=p;
			dis[i]+=p;
			if(i+w<=n)
				dis[i+w]-=p;
		}
	}
	return true;
}


int main()
{
 	freopen("460C.in","r",stdin);
// 	freopen("460C.out","w",stdout);
	n=read(),m=read(),w=read();
	int mm=0;
	a[0]=0;
    a[0] = 0;
    for(int i=1;i<=n;i++)
        mm=max(mm,a[i]=read());
	int l=1,r=mm+m,ans=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(can(mid))
			ans=mid,l=mid+1;
		else
			r=mid-1;
	}
    printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
 	return 0;
}