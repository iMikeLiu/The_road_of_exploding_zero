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
int n,m,f[210][210],a[210][210];




int main()
{
 	freopen("1006.in","r",stdin);
// 	freopen("1006.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
		cin>>a[i][j];
    f[1][2]=a[1][2]+a[2][1];
	for (int i=4;i<n+m;++i)
		for (int j=min(i-2,n);j>=1;--j)
			for (int k=min(i-1,n);k>j;--k)
			{
				if (j>1)
					f[j][k]=max(f[j][k],f[j-1][k]);
				if (j>1&&k>1)
					f[j][k]=max(f[j][k],f[j-1][k-1]);
				if (k-1>j)
					f[j][k]=max(f[j][k],f[j][k-1]);
				f[j][k]+=a[j][i-j]+a[k][i-k];
			}
    cout<<f[n-1][n];
	fclose(stdin);
	fclose(stdout);
 	return 0;
}
