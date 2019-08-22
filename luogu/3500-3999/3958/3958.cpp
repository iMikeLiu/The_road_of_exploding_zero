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
	for(f=0;(c=getchar())<'0'||c>'9';f=c=='-');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';x=(x<<3)+(x<<1)+c-'0');
	return f?-x:x;
}
struct hole_struct
{
	LL x,y,z;
};
#define MAXN 1011
I L double dis(hole_struct a,hole_struct b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));}
hole_struct a[MAXN];
int fa[MAXN];
int find(int x)
{
	if(x==fa[x])
		return fa[x];
	return fa[x]=find(fa[x]);
}
int main()
{
 	freopen("3958.in","r",stdin);
// 	freopen("3958.out","w",stdout);
	int t=read();
	while(t--)
	{
		LL  n=read(),h=read(),r=read();
		for(int i=0;i<=n;i++)
			fa[i]=i;
		fa[MAXN]=MAXN;
		for(int i=1;i<=n;i++)
		{
			a[i].x=read();a[i].y=read();a[i].z=read();
			if(a[i].z+r>=h)
                fa[find(i)]=find(MAXN);
            if(a[i].z-r<=0) 
                fa[find(i)]=find(0);
            for(int w=1;w<i;w++)
                if(dis(a[i],a[w])<=2*r)
                    fa[find(i)]=find(w);
		}
		if(find(0)==find(MAXN))
			printf("Yes\n");
		else
			printf("No\n");
	}
	fclose(stdin);
	fclose(stdout);
 	return 0;
}