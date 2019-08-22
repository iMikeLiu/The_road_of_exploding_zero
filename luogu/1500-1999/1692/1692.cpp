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
int n,m,ans,ansf[105];
bool book[105][105],flag[105];
void dfs(int a,int b)
{
    if(++b+n-a<=ans)
		return;
    for(int i=1;i<a;i++)
		if(flag[i]&book[i][a])
			return;
    flag[a]=1;
	for(int i=a+1;i<=n;i++)
		dfs(i,b);
    if(b>ans)
	{
		ans=b;
		for(int i=1;i<=n;i++)
			ansf[i]=flag[i];
	}
    flag[a]=0;
}
int main()
{
 	freopen("1692.in","r",stdin);
//	freopen("1692.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1,a,b;i<=m;i++)
		scanf("%d%d",&a,&b),book[a][b]=book[b][a]=1;
    for(int i=1;i<=n;i++)
		dfs(i,0);
    printf("%d\n",ans);
    for(int i=1;i<=n;i++)
		printf("%d ",ansf[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

