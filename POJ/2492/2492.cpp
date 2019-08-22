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
int g[MAXN];
int find(int x)
{
	if(f[x]==x)
		return x;
	int fx=f[x];
	f[x]=find(f[x]);
	g[x]=(g[fx]+g[x])%2;
	return f[x];
}
void bing(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	if(fx==fy)
		return;
	f[fy]=fx;
    g[fy] = (1 + g[x] + g[y])%2;  
}


int main()
{
 	freopen("2492.in","r",stdin);
// 	freopen("2492.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int a,b;
		bool flag=true;
		scanf("%d%d",&a,&b);
		for(int j=1;j<=a;j++)
		{
			f[j]=j;
			g[j]=0;
		}
		for(int j=1;j<=b;j++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if(flag)
			{
				int fx=find(x);
				int fy=find(y);
				if(fx==fy)
				{
					if(g[x]==g[y])
					{
						flag=false;	
					}
				}
				else
					bing(x,y);
			}
		}
		printf("Scenario #%d:\n",i);
		if(flag)
			printf("No suspicious bugs found!\n\n");	
		else
			printf("Suspicious bugs found!\n\n");
	}
	return 0;
}

