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
#define MAXM 5011
struct PA
{
	int p,a;
}data[MAXM];
bool cmp(PA a,PA b)
{
	return a.p<b.p;
}
int main()
{
 	freopen("1208.in","r",stdin);
// 	freopen("1208.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
		scanf("%d%d",&data[i].p,&data[i].a);
	sort(data,data+m,cmp);
	int ans=0;
	int milk=0;
	for(int i=0;milk<n;i++)
		if((milk+data[i].a)>n)
			ans+=(n-milk)*data[i].p,milk=n;
		else
			milk+=data[i].a,ans+=data[i].p*data[i].a;
	printf("%d",ans);
 	return 0;
}

