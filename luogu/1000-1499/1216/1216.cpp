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
#define  MAXR 1011
int in[MAXR][MAXR];
int ans[MAXR][MAXR];


int main()
{
 	freopen("1216.in","r",stdin);
// 	freopen("1216.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<=i;j++)
			scanf("%d",&in[i][j]);
	(ans[0][0]=in[0][0]);
	for(int i=1;i<n;i++)
		for(int j=0;j<=i;j++)
			ans[i][j]=max(ans[i-1][j],ans[i-1][j-1])+in[i][j];
	int anss=0;
	for(int i=0;i<n;i++)
		anss=max(anss,ans[n-1][i]);
	cout<<anss;
	fclose(stdin);
	fclose(stdout);
 	return 0;
}
