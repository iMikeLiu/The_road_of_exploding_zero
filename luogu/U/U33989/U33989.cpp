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
#define MAXN 100011
double data[MAXN];




int main()
{
 	freopen("U33989.in","r",stdin);
// 	freopen("U33989.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lf",&data[i]);
	for(int i=0;i<m;i++)
	{
		int a;
		scanf("%d",&a);
		if(a)
		{
			int l,r;
			double t;
			scanf("%d%d%lf",&l,&r,&t);
			for(int i=l;i<=r;i++)
				data[i]*=t;
		}
		else
		{
			int l,r;
			double ans=1;
			scanf("%d%d",&l,&r);
			for(int i=l;i<=r;i++)
				ans*=(1-data[i]);
			printf("%.6lf\n",ans);
		}
	}
	


	fclose(stdin);
	fclose(stdout);
 	return 0;
}
