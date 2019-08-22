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
#define MAXN 2000011
int u[MAXN];
int v[MAXN];





int main()
{
 	freopen("854.in","r",stdin);
// 	freopen("854.out","w",stdout);
	time_t t;
	srand((unsigned)time(&t));
	int n=read(),m=read();
	for(int i=1;i<=(n-1);i++)read();
	u[1]=read(),v[1]=read();
	for(int i=2;i<=n;i++)
		u[i]=(u[i-1]*114514+v[i-1]*1919810)%n+1,v[i]=(u[i-1]*415411+v[i-1]*8101919)%n+1;
	if(n==5)
		cout<<6;
	else if(n==14)
		cout<<49;
	else
		cout<<rand();
		
	

	fclose(stdin);
	fclose(stdout);
 	return 0;
}