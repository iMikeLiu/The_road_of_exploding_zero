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
#define MAXN 1011
#define MAXM 10011
int point [MAXN];
struct edge
{
	edge e;
	lianbiao *next;
}biao[MAXM<<1];
lianbiao *head=biao *e[MAXN];

void addEdge(edge *e[], int x, int y)
{
    *ecnt = (edge){y, e[x]}, e[x] = ecnt++;
    *ecnt = (edge){x, e[y]}, e[y] = ecnt++;
}



int main()
{
 	freopen("3387.in","r",stdin);
// 	freopen("3387.out","w",stdout);
	int n,m;
	for(int i=0;i<n;i++)
		scanf("%d",&point[i]);
	


	fclose(stdin);
	fclose(stdout);
 	return 0;
}
