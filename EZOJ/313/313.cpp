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
int f[2][4001][2],a[4001],inf=2e9;
int main()
{
 	freopen("313.in","r",stdin);
// 	freopen("313.out","w",stdout);
    int n=read(),m=read();
    for (int i=1;i<=n;i++)
		a[i]=read();
    int now=0,nxt=1;
    f[0][0][0]=0;
    f[0][0][1]=-inf;
    for(int i=1;i<=n;i++)
    {
        f[nxt][0][1]=-inf;
        for (int j=0;j<=m;j++)
        {
            f[nxt][j][0]=max(f[now][j][0],f[now][j][1]);
            if(j)
				f[nxt][j][1]=max(f[now][j-1][0],f[now][j-1][1]+a[i]);
        }
        memset(f[now],0,sizeof(f[now]));
        swap(now,nxt);
    }
	int ans=f[now][m][0];
    memset(f,0,sizeof(f));
    f[0][0][0]=-inf;
    f[0][0][1]=0;	
    now=0,nxt=1;
    for(int i=1;i<=n;i++)
    {
        f[nxt][0][1]=-inf;
        for(int j=0;j<=m;j++)
        {
            f[nxt][j][0]=max(f[now][j][0],f[now][j][1]);
            if(j)
				f[nxt][j][1]=max(f[now][j-1][0],f[now][j-1][1]+a[i]);
        }
        memset(f[now],0,sizeof(f[now]));
        swap(now,nxt);
    }
    ans=max(ans,f[now][m][1]);
    cout<<ans;

	fclose(stdin);
	fclose(stdout);
 	return 0;
}