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





int main()
{
 	freopen("317.in","r",stdin);
// 	freopen("317.out","w",stdout);
	int n;
	scanf("%d",&n);
	int m=sqrt(n+0.5);
	long long ans=0;
	for(int i=2;i<=m;i++)
		while(n%i==0)
			ans+=n,n/=i;
	if(n>1) 
		ans+=n;
	ans++;
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
 	return 0;
}


