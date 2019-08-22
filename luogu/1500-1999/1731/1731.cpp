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
int n,m,best=0x7fffff,vmin[25],smin[25];
void dfs(int i,int ri,int hi,int s,int v)
{
	for (int r=m-i+1;r<=ri-1;r++)
		for (int h=hi-1;h>=m-i+1;h--)
		{
			if(i==1)
				s=r*r;
			if(s+2*r*h+smin[i+1]<best&&v+r*r*h+vmin[i+1]<=n&&v+r*r*h*(m-i+1)>=n)
				if(i==m)
					best=s+2*r*h;
				else
					dfs(i+1,r,h,s+2*r*h,v+r*r*h);
		}
}
int main()
{
 	freopen("1731.in","r",stdin);
// 	freopen("1731.out","w",stdout);
	scanf("%d%d",&n,&m);
    for (int i=1;i<=m;vmin[m-i+1]=vmin[m-i+2]+i*i*i,smin[m-i+1]=smin[m-i+2]+2*i*i,i++);
	dfs(1,sqrt((n-vmin[2])/m)+1,(n-vmin[2])+1,0,0);
	cout<<best;
	fclose(stdin);
	fclose(stdout);
 	return 0;
}