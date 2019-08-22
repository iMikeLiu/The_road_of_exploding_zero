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
#define MAXN 2011
LL h[MAXN],n;
LL s[MAXN],m;
bool cmp(LL a,LL b)
{
	return a>=b;
}
LL f[MAXN][MAXN];

int main()
{
 	freopen("1324.in","r",stdin);
// 	freopen("1324.out","w",stdout);
	n=read(),m=read();
	memset(f,0x3f,sizeof(f));
	for(LL i=1;i<n;h[i]=read(),i++);
	for(LL i=1;i<m;s[i]=read(),i++);
	sort(h+1,h+n+1,cmp);
	sort(s+1,s+m+1,cmp);
	f[0][0]=0;
	for(LL i=1;i<n;i++)
		f[i][0]=f[i-1][0]+h[i];
	for(LL i=1;i<m;i++)
		f[0][i]=f[0][i-1]+s[i];
	for(LL i=1;i<n;i++)
		for(LL j=1;j<m;j++)
			f[i][j]=min(f[i][j],min(f[i-1][j]+h[i]*(j+1),f[i][j-1]+s[j]*(i+1)));
	cout<<f[n-1][m-1];
	
	fclose(stdin);
	fclose(stdout);
 	return 0;
}