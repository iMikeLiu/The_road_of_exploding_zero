#include<iostream>
#include<cstdio>
using namespace std;
int count,ans,old,now;
int main()
{
	freopen("1969.in","r",stdin);
	scanf("%d",&count);
	old=0; 
	for(int i=0;i<count;i++)
	{
		scanf("%d",&now);
		if(now>old)
		{
			ans+=now-old;
		}
		old=now;
	}
	cout<<ans;
	
	return 0;
}
