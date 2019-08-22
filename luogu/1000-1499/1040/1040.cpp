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
int n,v[39],f[47][47],i,j,k,root[49][49];
void print(int l,int r)
{
	if(l>r)
		return;
	if(l==r)
	{
		printf("%d ",l);
		return;
	}
	printf("%d ",root[l][r]);
	print(l,root[l][r]-1);
	print(root[l][r]+1,r);
}


int main()
{
 	freopen("1040.in","r",stdin);
// 	freopen("1040.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",&v[i]);
	for(int i=1; i<=n; i++)
	{
		f[i][i]=v[i];
		f[i][i-1]=1;
	}
	for(int i=n; i>=1; i--)
		for(j=i+1; j<=n; j++)
			for(k=i; k<=j; k++)
				if(f[i][j]<(f[i][k-1]*f[k+1][j]+f[k][k])) 
					f[i][j]=f[i][k-1]*f[k+1][j]+f[k][k],root[i][j]=k;
	printf("%d\n",f[1][n]);
	print(1,n);

	fclose(stdin);
	fclose(stdout);
 	return 0;
}