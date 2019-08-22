#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<map>
#define debug(x) cerr<<"\tdebug:"<<#x<<"="<<x<<endl
#define debugg(x,y) cerr<<"\tdebug;"<<x<<":"<<#y<<"="<<y<<endl
#define debugzu(x,a,b) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++)cerr<<x[i]<<" ";fprintf(stderr,"\n");
#define debugerzu(x,a,b,c,d) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++,fprintf(stderr,"\n\t"))for(int j=c;j<d;j++)cerr<<x[i][j]<<" ";fprintf(stderr,"\n");
#define R register
#define LL long long
#define I inline
using namespace std;
#define MAXN 10000011
int father[MAXN],nearfather[MAXN],time[MAXN];
bool flag[MAXN];
int find(int x,int cnt)
{
	if(flag[x])
		return x;
	if(time[x]==cnt)
		return nearfather[x];
	time[x]=cnt;
	return nearfather[x]=find(father[x],cnt);
}



int main()
{
 	freopen("4092.in","r",stdin);
// 	freopen("4092.out","w",stdout);
	int n,q;
	scanf("%d%d", &n, &q);
	for(int i=0,u,v;i<n-1;i++)
		scanf("%d%d",&u,&v),father[v]=u;
	int cnt=1;
	flag[1]=true;father[1]=1;
	for(int i=0;i<n;i++)
		 time[i]=nearfather[i]=1;
	for(int i=0;i<q;i++)
	{
		char c;int u;
		scanf("\n%c%d",&c,&u);
		if(c=='C')
		{
			if(!flag[u])
				flag[u]=1,cnt++;
		}
		else
			printf("%d\n",find(u,cnt));
	}
	fclose(stdin);
	fclose(stdout);
 	return 0;
}
