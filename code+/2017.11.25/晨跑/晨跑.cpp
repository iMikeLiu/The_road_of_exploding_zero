#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<string>
#include<cstdlib>
#include<map>
using namespace std;
long long a,b,c;
long long lcm(long long m,long long n)
{
	long long r;
	if(m<n)
		swap(m,n);
	while((r=m%n)!=0)
		m=n,n=r;
	return n;
}
long long gcd(long long a,long long b)
{
	 return a * b / lcm(a,b); 
}

int main()
{
// 	freopen("³¿ÅÜ.in","r",stdin);
// 	freopen("³¿ÅÜ.out","w",stdout);
	cin>>a>>b>>c;
	cout<<gcd(gcd(a,b),c);
 	return 0;
}

