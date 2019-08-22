#include <iostream>
#include <cstdio>
using namespace std;
int a,b,ans=0;
int find(int shuju,int find)
{
	int ans=0,a;
	while(shuju>0)
	{
		a=shuju%10;
		if(a==find)
		{
			ans++;
		}
		shuju=shuju/10;
	}
	return ans;
}
int main()
{
	//freopen("1908.in","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++)
	{
		ans=ans+find(i,b);
	}
	cout<<ans;
	return 0;
} 
