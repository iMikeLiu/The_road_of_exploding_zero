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
#define MAXN 10011
int f[MAXN];
struct _product
{
	int p,d;
}prod[MAXN];
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
		return ;
	f[fx]=fy;	
}
inline bool cmp(_product a,_product b)
{
	return a.p>b.p;
}
int main()
{
    freopen("1456.in","r",stdin);
//    freopen("1456.out","w",stdout);
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<=MAXN;i++)
			f[i]=i;
		long long ans=0;
		for(int i=0;i<n;i++)
			scanf("%d%d",&prod[i].p,&prod[i].d);
		sort(prod,prod+n,cmp);
		for(int i=0;i<n;i++)
		{
			int fd=find(prod[i].d);
			if(fd!=0)
			{
				f[fd]=fd-1;
				ans+=prod[i].p;	
			}
		}
		printf("%d\n",ans);	
		
	}
    return 0;
}

