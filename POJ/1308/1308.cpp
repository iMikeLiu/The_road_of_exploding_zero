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
#define MAXN 50011
int f[MAXN];
bool used[MAXN]={false};
int ans,j;
int find(int x)
{
	if(f[x]==x)
		return x;
	f[x]=find(f[x]);
	return f[x];
}
void bing(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	f[fy]=fx;
}
int main()
{
	bool flag;
 	freopen("1308.in","r",stdin);
// 	freopen("1308.out","w",stdout);
	j=1;
	flag = true;
	while(flag)
	{
		int a,b,fa,fb;
		ans=0;
		bool flag2=true;
		for(int i=1;i<=MAXN;i++)
		{
			f[i]=i;
			used[i]=false;
		}
		while(scanf("%d%d",&a,&b)!=EOF)
		{
			if(a==-1&&b==-1)
			{
				flag=false;
				break;
			}
			if(a==0&&b==0)
				break;
				
			if(flag2)
			{
				used[a]=used[b]=true;
				fa=find(a);
				fb=find(b);
				if(fa==fb)
				{
					flag2=false;
				}
				else
				{
					bing(a,b);
				}
			}
		}
		
		if(flag==false)
		{
			break;
		}
		
		if(flag2)
		{
			for(int i=1;i<=MAXN;i++)
			{
				//printf("f[%d]=%d",i,f[i]);
				if(f[i]==i&&used[i]==true)
					ans++;
			}
			
			if(ans>1)
			{
				flag2=false;
			}
		}
		
		if(flag2==true)
			printf("Case %d is a tree.\n",j);
		else
			printf("Case %d is not a tree.\n",j);
		j++;
	}
	return 0;
}

