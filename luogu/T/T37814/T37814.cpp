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
int n,a,b,num,m;
long double c[1010],d[2010],e[2010],cc[1010];
inline long double solve(long double i)
{
    long double ans=0;
	for(int x=0;x<=n;x++)
		ans+=c[x]*pow(i,x);
    return ans;
}
inline long double solv(long double i)
{
    long double ans=0;
    for(int x=0;x<n;x++)
		ans+=cc[x]*pow(i,x);
    return ans;
}
inline void clac(int i)
{
    long double l=i,r=i+1;
    while(l+(1e-15)<r)
	{
        long double mid=(l+r)/2;
        if(solv(mid)*d[num-1]<=0)
			r=mid;
        else 
			l=mid;
    }
    e[++m]=solve(l);
}




int main()
{
 	freopen("T37814.in","r",stdin);
// 	freopen("T37814.out","w",stdout);
    cin>>n;
    for(int x=0;x<=n;x++)
		scanf("%Lf",&c[x]);
    for(int x=0;x<n;x++)
		cc[x]=c[x+1]*(x+1);
    cin>>a>>b;
    d[0]=solv(a);num++;//if(!d[0])e[++m]=solve(a);
    for(int x=a+1;x<=b;x++)
	{
        d[num]=solv((long double)x);
        if(d[num]*d[num-1]<=0)
			clac(x-1);
        num++;
    }
	sort(e+1,e+m+1);
    if(!m)
		cout<<"Poor OIers";
    else
        for(int x=1;x<=m;x++)
			printf("%.2Lf ",e[x]);

	fclose(stdin);
	fclose(stdout);
 	return 0;
}
