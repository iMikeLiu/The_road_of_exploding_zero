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


int main()
{
 	freopen("T42830.in","r",stdin);
// 	freopen("T42830.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		LL a,b,A,B;
		scanf("%lld%lld",&A,&B);
		a=sqrt(A);
        b=sqrt(B);
        if(a*a<A)
			a++;
        LL res = 0;
        if(a>b)
			res=0;
        else
			res=((b-a+1)>>1)+((a&1)&&(b&1));
		printf((res&1?"Yes\n":"No\n"));
	}

	fclose(stdin);
	fclose(stdout);
 	return 0;
}