#include<iostream>
#include<cstdio>
using namespace std;
long long int x,n,ans=0;
int main ()
{
	freopen("1424.in","r",stdin); 
	cin>>x>>n;
	for(long long int a=x;a<=x+n-1;a++)
	{
		if(a%7==0||a%7==6)
		{
		}
		else
		{
			ans=ans+250;
		}
	}
	cout<<ans;
}
