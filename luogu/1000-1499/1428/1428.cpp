#include<iostream>
#include<cstdio>
using namespace std;
int data[110],zhi,ans;
int  main()
{
	freopen("1428.in","r",stdin);
	cin>>zhi;
	for(int a=0;a<zhi;a++)
	{
		ans=0;
		cin>>data[a];
		for(int b=0;b<a;b++)
		{
			if(data[a]>data[b])
			{
				ans++;
			}
		}
		cout<<ans<<" ";
	}
}
