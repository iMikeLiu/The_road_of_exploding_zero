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
#define MAXN 10011
#define MAXM 2011
#define MAXK 10011
struct point_struct
{
	int up,down;
}point[MAXN];
int low[MAXN],high[MAXN];
bool pipe[MAXN];
int f[MAXN][MAXM];


int main()
{
 	freopen("1941.in","r",stdin);
// 	freopen("1941.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&point[i].up,&point[i].down);
	for(int i=1;i<=n;i++)
		low[i]=1,high[i]=m;
	for(int i=1;i<=k;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		pipe[a]=true;
		low[a]=b+1;
		high[a]=c-1;
	}
	memset(f,0x3f,sizeof(f));
//	debug(n);debug(m);debug(k);
	for(int i=1; i<=m;i++) 
		f[0][i]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=point[i].up+1;j<=m+point[i].up;j++)
			f[i][j]=min(f[i-1][j-point[i].up]+1,f[i][j-point[i].up]+1);
		for(int j=m+1;j<=m+point[i].up;j++)
			f[i][m]=min(f[i][m],f[i][j]);
		for(int j=1;j<=m-point[i].down;j++)
			f[i][j]=min(f[i][j],f[i-1][j+point[i].down]);
		for(int j=1;j<low[i];j++)
			f[i][j]=f[0][0];
		for(int j=high[i]+1;j<=m;j++)
			f[i][j]=f[0][0];
	}
	int ans=f[0][0];
	for(int j=1;j<=m;++j)
		ans=min(ans,f[n][j]);
//	debug(ans);
//	debugerzu(f,0,n+1,0,m+1)
//	debugzu(f[n],1,m+1);
	if(ans<f[0][0]) 
		printf("1\n%d\n",ans);
	else
	{
		int i,j;
		for(i=n;i>=1;i--)
		{
			for(j=1;j<=m;j++)
				if(f[i][j]<f[0][0])
					break;
			if(j<=m)
				break;
		}
		int ans=0;
        for(int j=1;j<=i;++j)
            if(pipe[j]) 
				ans++;
        printf("0\n%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
 	return 0;
}
