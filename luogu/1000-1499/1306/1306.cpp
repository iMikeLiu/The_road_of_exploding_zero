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
#define mem(p) memset(&p,0,sizeof(p))
inline LL gcd(LL a,LL b)
{
	return b?gcd(b,a%b):a;
}
const LL ha=1e8;
struct mat
{
	LL a[3][3],r,c;
};
inline mat mul(mat a,mat b)
{
	mat p;
	mem(p);
	for(int i=0;i<a.r;i++)
		for(int j=0;j<b.c;j++)
			for(int k=0;k<a.c;k++)
				p.a[i][j]=(a.a[i][k]*b.a[k][j]+p.a[i][j])%ha;
	p.r=a.r;
	p.c=b.c;
	return p;
}
inline LL fast(LL k)
{
	mat ans,p;
	mem(p),mem(ans);
	p.r=p.c=2;
	p.a[0][0]=p.a[0][1]=p.a[1][0]=1;
	ans.r=1,ans.c=2;
	ans.a[0][0]=ans.a[0][1]=1;
	while(k)
	{
		if(k&1)
			ans=mul(ans,p);
		p=mul(p,p);
		k>>=1;
	}
	return ans.a[0][0];
}	
int main()
{
 	freopen("1306.in","r",stdin);
// 	freopen("1306.out","w",stdout);
	long long n,m;
    cin>>n>>m;
    n=gcd(n,m);//求最大公约数
	if(n<=2)
		cout<<1;
	else
		cout<<fast(n-2);
	fclose(stdin);
	fclose(stdout);
 	return 0;
}
