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
int n;
bool check(long long x)
{
	//cout<<x<<" ";
	if(x==1)
		return false;
    for(int i=2;i*i<=x;i++) 
    	if(x%i==0) 
    		return false; 
    return true; 	
}
void dfs(int nn,int m)
{
	if(nn==n)
	{
		printf("%d\n",m);
		return;
	}
	int mm=m*10;
	for(int i=1;i<=9;i++)
	{
		if(check(mm+i))
		{
			dfs(nn+1,mm+i);
		}
	}
}

int main()
{
 	freopen("1218.in","r",stdin);
// 	freopen("1218.out","w",stdout);
	scanf("%d",&n);
	dfs(0,0);
 	return 0;
}

