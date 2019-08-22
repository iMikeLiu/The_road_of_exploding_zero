#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<map>
#define debuglog(x) cerr<<"\tdebug:"<<#x<<endl
#define debug(x) cerr<<"\tdebug:"<<#x<<"="<<x<<endl
#define debugg(x,y) cerr<<"\tdebug;"<<x<<":"<<#y<<"="<<y<<endl
#define debugzu(x,a,b) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++)cerr<<x[i]<<" ";fprintf(stderr,"\n");
#define debugerzu(x,a,b,c,d) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++,fprintf(stderr,"\n\t"))for(int j=c;j<d;j++)cerr<<x[i][j]<<" ";fprintf(stderr,"\n");
#define R register
#define LL long long
#define I inline
using namespace std;
struct edge_struct
{
	int u,v,w;
}edge[200005];
int fa[5005],n,m,ans,cnt;
bool cmp(edge_struct a,edge_struct b)
{
	return a.w<b.w;
}
inline int find(int x)
{
	while(x!=fa[x])
		x=fa[x]=fa[fa[x]];
	return x;
}
void kruskal()
{
	for(int i=0;i<m;i++)
	{
		int fu=find(edge[i].u),fv=find(edge[i].v);
		if(fu==fv)
			continue;
		ans+=edge[i].w;
		fa[fu]=fv;
		if(++cnt==n-1)
			break;
	}
}




int main()
{
 	freopen("3366.in","r",stdin);
// 	freopen("3366.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=0;i<m;i++)
		scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
	sort(edge,edge+m,cmp);
	kruskal();
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
 	return 0;
}
