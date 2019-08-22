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
 	freopen("2524.in","r",stdin);
// 	freopen("2524.out","w",stdout);
	j=1;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)
			break;
		for(int i=1;i<=n;i++)
			f[i]=i;
		ans=0;
		for(int i=1;i<=m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			bing(a,b);
		}
		for(int i=1;i<=n;i++)
		{
		//	printf("f[%d]=%d",i,f[i]);
			if(f[i]==i)
				ans++;
		}
		printf("Case %d: %d\n",j,ans);
		j++;
	}
	return 0;
}

