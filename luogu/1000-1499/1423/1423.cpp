#include<cstdio>
#include<iostream>
using namespace std;
double now=0,in=0,mi=2;
int ans=0;
int main()
{
	freopen("1423.in","r",stdin);
	cin>>in;
	while(now<=in)
	{
		ans++;
		now=now+mi;
		mi=mi*0.98;	
	}
	cout<<ans;
}
