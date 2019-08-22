#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
using namespace std;
int n,k;
int dat[22];
int ans=0;
//int buf[22]={0};
bool used[22]={false};
bool check(int x)
{
	int a=sqrt(x);
	for(int i=2;i<=a;i++)
	{
		if(x%i==0)
			return false;
	}
	return true;
}
void dfs(int x,int count ,int he)
{
	if(count>=k)
	{
		if(check(he))
		{
			ans++;
//printf("YES %d ",he);
		}
//for (int i=0;i<k;i++) printf("%d ",buf[i]);
//cout<<endl;
		return;
	}
	for(int i=x;i<n;i++)
	{
		if(!used[i])
		{
			used[i]=true;
//buf[count]=dat[i];
			dfs(i,count+1,he+dat[i]);
			used[i]=false;
		}
	}
}

int main()
{
 	freopen("1036.in","r",stdin);
// 	freopen("1036.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&dat[i]);
	}
	dfs(0,0,0);
	cout<<ans;
	
	



 	return 0;
}

