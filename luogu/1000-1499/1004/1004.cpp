#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<map>
#define debug(x) cerr<<"\tdebug:"<<#x<<"="<<x<<endl
#define debugg(x,y) cerr<<"\tdebug;"<<x<<":"<<#y<<"="<<y<<endl
#define debugzu(x,a,b) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++)cerr<<x[i]<<" ";fprintf(stderr,"\n");
#define debugerzu(x,a,b,c,d) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++,fprintf(stderr,"\n\t"))for(int j=c;j<d;j++)cerr<<x[i][j]<<" ";fprintf(stderr,"\n");
#define R register
#define LL long long
#define I inline
using namespace std;
int n;
int a[12][12]={0};
int f[12][12][12][12]={0};


int main()
{
 	freopen("1004.in","r",stdin);
// 	freopen("1004.out","w",stdout);
	scanf("%d",&n);
	while(1)
	{
		int x,y,v;
        scanf("%d%d%d",&x,&y,&v);
		if(!x&&!y&&!v)
			break;
		a[x][y]=v;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				for(int l=1;l<=n;l++)
				{
					f[i][j][k][l]=max(f[i-1][j][k-1][l],max(f[i-1][j][k][l-1],max(f[i][j-1][k-1][l],f[i][j-1][k][l-1])))+a[i][j]+a[k][l];
					if(i==k&&j==l)
						f[i][j][k][l]-=a[i][j];
				}
	printf("%d",f[n][n][n][n]);
	fclose(stdin);
	fclose(stdout);
 	return 0;
}
