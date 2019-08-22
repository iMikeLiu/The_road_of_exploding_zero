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
struct juzhen
{
	long long m[101][101];
};
juzhen a,e;
LL n,p;
const LL ha= 1e9+7;
juzhen cheng (juzhen a,juzhen b)
{
	juzhen c;
	memset(c.m,0,sizeof(c.m));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				c.m[i][j]=c.m[i][j]%ha+a.m[i][k]*b.m[k][j]%ha;
	return c;
}
juzhen pow (juzhen a,LL b)
{
	juzhen ans=e;
	while(b)
	{
		if(b&1)
			ans=cheng(ans,a);
		a=cheng(a,a);
		b>>=1;
	}
	return ans;
}

int main()
{
 	freopen("3390.in","r",stdin);
// 	freopen("3390.out","w",stdout);
	cin>>n>>p;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>a.m[i][j];
	for(int i=0;i<n;i++)
		e.m[i][i]=1;    
	juzhen ans=pow(a,p);
	for(int i=0;i<n;i++,putchar('\n'))
		for(int j=0;j<n;j++)
			cout<<ans.m[i][j]%ha<<" ";


	fclose(stdin);
	fclose(stdout);
 	return 0;
}
