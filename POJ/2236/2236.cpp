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
#define MAXN 1011
long long f[MAXN];
long long x[MAXN],y[MAXN];
bool ok[MAXN];
inline long long getd(long long a,long long b)
{
	long long yy=y[a]-y[b];
	long long xx=x[a]-x[b];
	return xx*xx+yy*yy;
}
int  find(int x)
{
	if(x==f[x])
		return f[x];
	f[x]=find(f[x]);
	return f[x];
}
void bing(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	if(fx==fy)
		return ;
	f[fy]=fx;
}
int main()
{
	int n,d;
	freopen("2236.in","r",stdin);
//	freopen("2236.out","r",stdout);
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
		ok[i]=false;
	}
	for(int i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	char c;
	while(scanf("%c",&c)!=EOF)
	{
		if(c=='S')
		{
			long long a,b;
			scanf("%d%d",&a,&b);
			if(find(a)==find(b))
				printf("SUCCESS\n");
			else
				printf("FAIL\n");
		}
		if(c=='O')
		{
			long long a,fa;
			scanf("%d",&a);
			ok[a]=true;
			fa=find(a);
			for(int i=1;i<=n;i++)
			{
				if((getd(a,i)<=d*d)&&ok[i])
				{
					//printf("bing %d %d\n",a,i);
					bing(a,i);
				}
				else
				{
					//printf("d=%d\n",getd(a,i));
				}
			}	
		}
	}
}
