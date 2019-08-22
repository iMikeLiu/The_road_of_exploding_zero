#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<map>
#include<ctime>
#include<queue>
#define debuglog(x) cerr<<"\tdebug:"<<#x<<endl
#define debug(x) cerr<<"\tdebug:"<<#x<<"="<<(x)<<endl
#define debugg(x,y) cerr<<"\tdebug;"<<(x)<<":"<<#y<<"="<<(y)<<endl
#define debugzu(x,a,b) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++)cerr<<x[i]<<" ";fprintf(stderr,"\n");
#define debugerzu(x,a,b,c,d) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++,fprintf(stderr,"\n\t"))for(int j=c;j<d;j++)cerr<<x[i][j]<<" ";fprintf(stderr,"\n");
#define R register
#define L long
#define LL long long
#define I inline
#define U unsigned
#define START clock_t __start=clock();
#define STOP fprintf(stderr,"\n\nUse Time:%fs\n",((double)(clock()-__start)/CLOCKS_PER_SEC));
using namespace std;
I LL read()
{
	R LL x;R bool f;R char c;
	for (f=0; (c=getchar())<'0'||c>'9'; f=c=='-');
	for (x=c-'0'; (c=getchar())>='0'&&c<='9'; x=(x<<3)+(x<<1)+c-'0');
	return f?-x:x;
}
map <string,int> mapp;
#define MAXN 200011
#define INF 0x3f3f3f3f

typedef pair<int, int> heapnode;
struct edge_struct{int v,nxt,w;};
int head[MAXN],dis[MAXN];
edge_struct edge[MAXN*100];
int cnt;
inline void addedge(int from, int to, int weight)
{
    edge[cnt].w = weight;
    edge[cnt].v = to;
    edge[cnt].nxt = head[from];
    head[from] = cnt++;
}

int dijkstra(int u)
{
	priority_queue<heapnode,vector<heapnode>,greater<heapnode> >heap;
	dis[u]=0;
	heap.push(make_pair(0,u));
	while(!heap.empty())
	{
		pair<int,int>T=heap.top();heap.pop();
		if(T.first!=dis[T.second])
			continue;
		for(int i=head[T.second];i!=-1;i=edge[i].nxt)
		{
			int eiv=edge[i].v;
			if(dis[eiv]>dis[T.second]+edge[i].w)
			{
				dis[eiv]=dis[T.second]+edge[i].w;
				heap.push(make_pair(dis[eiv],eiv));
			}
		}
	}
}


int main()
{
 	freopen("324.in","r",stdin);
// 	freopen("324.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		string a;
		cin>>a;
		mapp.insert(pair<string,int>(a,i));
	}
	for(int i=0; i<=n; i++)
        head[i]=-1,dis[i]=INF;
    cnt = 0;
	for(int i=0;i<m;i++)
	{
		string a,b;
		cin>>a>>b;
		int w=read();
		addedge(mapp[a],mapp[b],w);
		addedge(mapp[b],mapp[a],w);
	}
	dijkstra(mapp["Ryuuguu"]);
	cout<<dis[mapp["Furude"]];
	

	fclose(stdin);
	fclose(stdout);
 	return 0;
}