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
#define ll long long
ll powmod(ll n,ll times,ll ha)
{
	ll tmp=1;
	while (times)
	{
		if (times & 1) 
			tmp = (long long)tmp * n % ha;
		n = (long long)n * n % ha;
		times >>= 1;
	}
	return tmp;
}
ll ny(ll n,ll ha)
{
	return  powmod(n,ha-2,ha);
}
ll work(ll n,ll m,ll ha)
{
	if (m > n) 
		return 0;
	ll tmp = 1;
	for (ll i=1; i<=m; ++i)
		tmp = (ll)tmp * (n - i + 1) % ha;
	for (ll i=1; i<=m; ++i)
		tmp = (ll)tmp * ny(i, ha) % ha;
	return tmp;
}
ll C(ll n, ll m, ll ha)  
{
	if (n == 0 && m == 0) 
		return 1;
	if (m == 0) 
		return 1;
	if (n < ha)
		return work(n, m, ha);
	return (ll)C(n%ha, m%ha, ha) * C(n/ha, m/ha, ha) % ha;
}

int main()
{
// 	freopen("3807.in","r",stdin);
// 	freopen("3807.out","w",stdout);
	int test;
	cin >> test;
	for(int i=0;i<test;i++)
	{
		ll n,m,p;
		cin >> n >> m >> p;
		cout << C(n + m, m, p) << endl;
	}
	fclose(stdin);
	fclose(stdout);
 	return 0;
}
