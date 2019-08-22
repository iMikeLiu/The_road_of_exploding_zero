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
#define MAXN 30011
int f[MAXN],dis[MAXN],cnt[MAXN];
int find(int x)
{
	if(f[x]==x)
		return x;
	int fx=f[x];
	f[x]=find(f[x]);
	dis[x]+=dis[fx];
	return f[x];
}
void bing(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	if(fx==fy)
		return;
	f[fx]=fy;
	dis[fx]+=cnt[fy];  
    cnt[fy]+=cnt[fx];  
}


int main()
{
 	freopen("1988.in","r",stdin);
// 	freopen("1988.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=MAXN;i++)
		f[i]=i,dis[i]=0,cnt[i]=1;
	for(int i=0;i<n;i++)
	{
		char c;
		scanf(" %c",&c);
		if(c=='M')
		{
			int a,b;
			scanf("%d%d",&a,&b);
			bing(a,b);
		}
		else
		{
			int a;
			scanf("%d%d",&a);
			find(a);  
			printf("%d\n",dis[a]);
		}
	} 
	return 0;
}

