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
int q[MAXN];
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
	if(fx==fy)
		return;
	f[fy]=fx;
}

int main()
{
 	freopen("1892.in","r",stdin);
// 	freopen("1892.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++)
		f[i]=i;
	for(int i=0;i<m;i++)
	{
		char c;
		int a,b;
		scanf("\n%c%d%d",&c,&a,&b);
		if(c=='F')
			bing(a,b);
		else
		{
			
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(q[i]==1)
			ans++;
	}
	cout<<ans;
 	return 0;
}

