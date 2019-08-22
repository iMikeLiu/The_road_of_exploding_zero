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
int a[10000011];
int fa[10000011];
int find(int x)
{
	if(!fa[x]||fa[x]==x)
		return fa[x]=x;
	return fa[x]=find(fa[x]);
}




int main()
{
 	freopen("2054.in","r",stdin);
// 	freopen("2054.out","w",stdout);
	int n=read(),m=read(),p=read(),q=read();
	for(int i=m;i;i--)
	{
		int x=((long long)i*p+q)%n+1;
		int y=((long long)i*q+p)%n+1;
		if(x>y)
			swap(x,y);
		for(int j=find(x);j<=y;j=find(j))
			a[j]=i,fa[j]=j+1;
	}
	for(int i=1;i<=n;i++)
		printf("%d\n",a[i]);
	fclose(stdin);
	fclose(stdout);
 	return 0;
}