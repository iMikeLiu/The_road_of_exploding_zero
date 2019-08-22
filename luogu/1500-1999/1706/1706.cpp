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
int data[10];
bool uesd[11];
int n;
void dfs(int j)
{
	if(j==n)
	{
		for(int i=0;i<n;i++)
			printf("%5d",data[i]);
		printf("\n");
	}
	else
		for(int i=1;i<=n;i++)
			if(uesd[i]==false)
			{
				data[j]=i;
				uesd[i]=true;
				dfs(j+1);
				uesd[i]=false;
			}
}


int main()
{
 	freopen("1706.in","r",stdin);
// 	freopen("1706.out","w",stdout);
	scanf("%d",&n);
	dfs(0);


 	return 0;
}

