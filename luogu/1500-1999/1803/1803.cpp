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
#define MAXN 1000000
typedef struct
{
	int a,b;
}time;
time data[MAXN];
bool cmp(time a,time b){return a.b<b.b;}

int main()
{
 	freopen("1803.in","r",stdin);
// 	freopen("1803.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d%d",&data[i].a,&data[i].b);
	sort(data,data+n,cmp);
	int ans=0,end=0;
	for(int i=0;i<n;i++)
		if(end<=data[i].a)//遍历所有比赛的时间 
            end=data[i].b,ans++;
    printf("%d",ans);
 	return 0;
}

