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
#define MAXN 100010
struct node
{
	int x,h;
}a[MAXN];
bool cmp(node a,node b)
{
	return a.x<b.x;
}



int main()
{
 	freopen("316.in","r",stdin);
// 	freopen("316.out","w",stdout);
	int n=read();
	for(int i=0;i<n;a[i].x=read(),a[i].h=read(),i++);
	sort(a,a+n,cmp);
	int ans=2,en=a[0].x;
	for(int i=1;i<n-1;i++)
	{
		if(a[i].x-a[i].h>en)
		{
			ans++;
			en=a[i].x;
			continue;
		}
		if(a[i].h+a[i].x<a[i+1].x)
		{
			ans++;
			en=a[i].h+a[i].x;
			continue;
		}
		en=a[i].x;
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
 	return 0;
}