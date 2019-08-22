#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<map>
#define debuglog(x) cerr<<"\tdebug:"<<#x<<endl
#define debug(x) cerr<<"\tdebug:"<<#x<<"="<<x<<endl
#define debugg(x,y) cerr<<"\tdebug;"<<x<<":"<<#y<<"="<<y<<endl
#define debugzu(x,a,b) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++)cerr<<x[i]<<" ";fprintf(stderr,"\n");
#define debugerzu(x,a,b,c,d) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++,fprintf(stderr,"\n\t"))for(int j=c;j<d;j++)cerr<<x[i][j]<<" ";fprintf(stderr,"\n");
#define R register
#define LL long long
#define I inline
using namespace std;
const int N = 20;

int n;
int a[N];
int f[1 << N];
int h[1 << N];
int s[1 << N];
int g[N][1 << N];

void dfs(R int x,R int S,R int i,R int Max)
{
    if(x==n)
	{
        if((1<<Max)<i)
			return ;
        f[i|S]=(f[i|S]+f[i]*g[Max][S])%1000000007;
        if((1<<Max)==S)
			f[i|S]=(f[i|S]+f[i])%1000000007;
        return ;
    }
    if((i&(1<<x))==0)
		dfs(x+1,S|(1<<x),i,x);
    dfs(x+1,S,i,Max);
}




int main()
{
 	freopen("4871.in","r",stdin);
// 	freopen("4871.out","w",stdout);
	R int S;
	scanf("%d",&n);
	S=(1<<n)-1;
	for(int i=0;i<n;i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for(int i = 1; i <= S; i++)
		for(int j = 0; j < n; j++)
			if(i & (1 << j))
			{
				s[i] = s[i ^ (1 << j)] + a[j];
				break;
			}
	g[0][0]=1;
	for(int i=0;i<n;i++)
		for(int j=1;j<(1<<i);j++)
			if(s[j]==a[i])
				g[i][j|(1<<i)]=1+(j-(j&-j)==0);
	f[0] = 1;
	for(int i = 0; i < S; i++) 
		dfs(0, 0, i, 0);
	printf("%d\n", f[S]);

	fclose(stdin);
	fclose(stdout);
 	return 0;
}
