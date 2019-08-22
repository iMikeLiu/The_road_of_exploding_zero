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
//0 0Õ¨¿‡ 1≥‘∏∏∞÷∞÷ 2±ª∞÷∞÷≥‘
#define MAXN 50011
int f[MAXN];
int g[MAXN];
int find (int x)
{
	if(x==f[x])
		return x;
	int fx=f[x];
	f[x]=find(f[x]);
	g[x]=(g[fx]+g[x])%3;
	return f[x];
}
int bing(int x,int y,int a)
{
	int fx=find(x);
	int fy=find(y);
	if(fx==fy)
	{
		if((g[x]-g[y]+3)%3==a-1)
            return 0;
        return 1;
	}
	f[fx]=fy;
	g[fx]=(-g[x]+a-1+g[y]+3)%3;
	return 0;
}

int main()
{
    freopen("1182.in","r",stdin);
//    freopen("1182.out","w",stdout);
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<=n;i++)
    	f[i]=i,g[i]=0;
    int ans=0;
    for(int i=0;i<k;i++)
    {
    	int d,x,y;
    	scanf("%d%d%d",&d,&x,&y);
    	if(x>n||y>n)
    	{
    		ans++;
    		continue;
		}
    	if(d==2&&x==y)
    	{
    		ans++;
			continue;
    	}
    	ans+=bing(x,y,d);
	}
	printf("%d",ans);
    return 0;
}

