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
ll fen[MAXN];




int main()
{
 	freopen("1982.in","r",stdin);
// 	freopen("1982.out","w",stdout);
	ll n,p;
	cin>>n>>p;
	for(int i=0;i<n;i++)
		cin>>num[i];
	fen[0]=te[0]=num[0];
	for(int i=1;i<n;i++)
		te[i]=max(num[i],te[i-1]+num[i]);
	for(int i=1;i<n;i++)
		te[i]=max(te[i-1],te[i]);
//	debugzu(te,0,n);		
	ll ans;	
	fen[1]=te[0]+te[0];
	ans=fen[0];
	bool flag;
	flag=false;
	for(int i=2;i<n;i++)
	{
		if(te[i-1]+fen[i-1]<0&&fen[i-1]>0)
			flag=true;
		if(flag)
			fen[i]=(fen[i-1]%p+te[i-1])%p;
		else
			fen[i]=max(fen[i-1]+te[i-1],fen[i-1]);	
		ans=max(ans,fen[i]);
	}
	if(flag)
		cout<<fen[n-1]%p<<endl;
	else
		cout<<ans%p<<endl;
	fclose(stdin);
	fclose(stdout);
 	return 0;
}
