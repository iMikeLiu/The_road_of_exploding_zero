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
#define MAXN 88
I LL read()
{
	R LL x;R bool f;R char c;
	for (f=0; (c=getchar())<'0'||c>'9'; f=c=='-');
	for (x=c-'0'; (c=getchar())>='0'&&c<='9'; x=(x<<3)+(x<<1)+c-'0');
	return f?-x:x;
}
int n, m;
__int128 game[MAXN][MAXN];

__int128 f[MAXN][MAXN];
__int128 solve(__int128 a[])
{
    memset(f,0,sizeof(f));
    for(int len=0;len<=m;++len)
        for(int i=1;i+len<=m;++i)
            f[i][i+len]=max(2*f[i+1][i+len]+2*a[i],2*f[i][i+len-1]+2*a[i+len]);
    return f[1][m];
}
inline void output(__int128 x)
{
    if(x>9)
        output(x/10);
    putchar(x%10+'0');
}
int main()
{
 	freopen("1005.in","r",stdin);
// 	freopen("1005.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            game[i][j]=read();
	__int128 ans=0;	
    for(int i=1;i<=n;i++)
        ans+=solve(game[i]);
    output(ans);

	fclose(stdin);
	fclose(stdout);
 	return 0;
}