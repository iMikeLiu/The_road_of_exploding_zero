#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<string>
using namespace std;
int n,r;
int a[40]={0};
int b[40]={0};
void dfs(int rr)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		if(b[i]==0&&a[rr-1]<i)
		{
			a[rr]=i;
			if(rr==r)
			{
				for(j=1;j<=r;j++)
				{
					printf("%3d",a[j]);
				}
				printf("\n");
			}
			else
			{
				b[i]=1;
				dfs(rr+1);
				b[i]=0;
			}
		}
	}
}
int main()
{
	freopen("1157.in","r",stdin);
//	freopen("1157.out","w",stdout);
	cin>>n>>r;
	dfs(1);
	
	
	return 0;
}
