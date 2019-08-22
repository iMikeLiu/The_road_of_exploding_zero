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
#define MAXN 111
#define MAXM 10011
int a[MAXM][MAXN];
int summ[MAXM][MAXN];
int n,m;
int ansmax=0;
void dfs(int last,int lastcount,int reast,int ans)
{
//	debug(last);
//	debug(lastcount);debug(reast);debug(ans);cerr<<endl;
	if(reast==0)
	{
//		debug(ans);
		ansmax=max(ans,ansmax);
		return ;
	}
	for(int i=1;i<=m;i++)
		dfs(i,(i==last?lastcount+1:1),reast-1,ans+(a[i][(i==last?lastcount+1:1)]));
	return ;
}

int main()
{
 	freopen("T40984.in","r",stdin);
// 	freopen("T40984.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	dfs(0,1,n,0);
	cout<<ansmax;
	fclose(stdin);
	fclose(stdout);
 	return 0;
}
