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
using namespace std;
inline int min(int a,int b)
{
	if(a>b)
		return b;
	return a;
}
int main()
{
 	freopen("1909.in","r",stdin);
// 	freopen("1909.out","w",stdout);
	int n;
	scanf("%d",&n);
	int ans=0xeffffff;
	for(int i=0;i<3;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		ans=min(ans,ceil(n*1.0/a)*b);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
 	return 0;
}


