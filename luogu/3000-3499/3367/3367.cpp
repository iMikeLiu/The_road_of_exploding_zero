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
int m,n;
#define MAXN 50011
int f[MAXN];
int ans,j=1;
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
 	freopen("3367.in","r",stdin);
// 	freopen("3367.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=MAXN;i++)
		f[i]=i;
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(a==1)
			bing(b,c);
		else
			if(find(b)==find(c))
				printf("Y\n");
			else
				printf("N\n");
	}
 	return 0;
}

