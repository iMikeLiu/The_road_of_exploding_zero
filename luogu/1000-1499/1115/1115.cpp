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
#define MAXN 1000005
#define ll long long 
ll num[MAXN];
ll te[MAXN];




int main()
{
 	freopen("1115.in","r",stdin);
 	freopen("1115.out","w",stdout);
	ll n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>num[i];
	te[0]=num[0];
	for(int i=1;i<n;i++)
		te[i]=max(num[i],te[i-1]+num[i]);
	for(int i=1;i<n;i++)
		te[i]=max(te[i-1],te[i]);
	//debugzu(te,0,n);		
	cout<<te[n-1];
 	return 0;
}
