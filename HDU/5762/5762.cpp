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
typedef struct 
{
	LL x,y;
}point;
#define MAXN 100011
#define MAXM 100011
point points[MAXN];
bool fuck[MAXM*2];



int main()
{
 	freopen("5762.in","r",stdin);
// 	freopen("5762.out","w",stdout);
	LL t=read();
	while(t--)
	{
		LL n=read(),m=read();
		memset(fuck,0,sizeof(fuck));
		for(LL i=0;i<n;points[i].x=read(),points[i].y=read(),i++);
		bool flag=true;
		for(LL i=0;i<n&&flag;i++)
			for(LL j=0;j<i&&flag;j++)
			{
				LL l=abs(points[i].x-points[j].x)+abs(points[i].y-points[j].y);
				if(fuck[l])
					printf("YES\n"),flag=false;
				fuck[l]=true;
			}
		if(flag)
			printf("NO\n");
			
	}
	fclose(stdin);
	fclose(stdout);
 	return 0;
}