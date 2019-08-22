#include<cstdio>
#include<iostream>
using namespace std;
int in=0;
long long int ans=0;
double z=0;
int main()
{
	freopen("1035.in","r",stdin);
	cin>>in;
	while(z<=in)
	{
		ans++;
		z=z+1.0/ans;
	}
	cout<<ans;
} 
