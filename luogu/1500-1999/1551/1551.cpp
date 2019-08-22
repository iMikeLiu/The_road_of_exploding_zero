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
	int m,n,p;
 	freopen("1551.in","r",stdin);
// 	freopen("1551.out","w",stdout);
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		bing(a,b);
	}
	for(int i=0;i<p;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(find(a)==find(b))
			printf("Yes\n");
		else
			printf("No\n");
	}
 	return 0;
}

