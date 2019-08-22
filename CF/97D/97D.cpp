#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<map>
#include<bitset>
#define debug(x) cerr<<"\tdebug:"<<#x<<"="<<x<<endl
#define debugg(x,y) cerr<<"\tdebug;"<<x<<":"<<#y<<"="<<y<<endl
#define debugzu(x,a,b) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++)cerr<<x[i]<<" ";fprintf(stderr,"\n");
#define debugerzu(x,a,b,c,d) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++,fprintf(stderr,"\n\t"))for(int j=c;j<d;j++)cerr<<x[i][j]<<" ";fprintf(stderr,"\n");
#define R register
#define LL long long
#define I inline
using namespace std;
bitset <23000> a,b,c,e;



int main()
{
 	freopen("97D.in","r",stdin);
// 	freopen("97D.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	getchar();
	for(int i=0;i<n;i++,getchar())
		for(int j=0;j<m;j++)
		{
			char s=getchar();
			(s=='#'?b:a).set(i*m+j);
			(s=='E'?e.set(i*m+j):0);
		}
	c=a;
	for(int i=0;i<k;i++)
	{
		char s=getchar();
		if(c==e)
		{
			printf("%d\n",i);
			return 0;
		}
		if(s=='U') c = ( (c>>m)&a) | (c&(b<<m));
		else if(s=='L') c = ((c>>1)&a) | (c&(b<<1));
		else if(s=='D') c = ((c<<m)&a) | (c&(b>>m));
		else if(s=='R') c = ((c<<1)&a) | (c&(b>>1));
	}
	if(c==e)
		printf("%d\n",k);
	else
		printf("%d\n",-1);
	


	fclose(stdin);
	fclose(stdout);
 	return 0;
}
