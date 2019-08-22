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
/*
f[x][j][0/1]表示x子节点和本身中，选j个，当前节点是否打折(0/1)
方程式
f[x][j+k][0]=min(f[x][j+k][0],f[u][k][0]+f[x][j][0])
f[x][j+k][1]=min(f[x][j+k][1],f[u][k][1]+f[x][j][1])
f[x][j+k][1]=min(f[x][j+k][1],f[u][k][0]+f[x][j][1])
*/
#define MAXN 5011
int num=0,head[MAXN],w[MAXN],h[MAXN],now[MAXN];
LL f[MAXN][MAXN][2];
struct
{
	int next,to;
}data[MAXN<<1];
void init(int x,int y)
{
	data[++num].next=head[x];
	data[num].to=y;
	head[x]=num;
}
void dfs(int x)
{
	now[x]=1;
	f[x][0][0]=0;f[x][1][0]=w[x];f[x][1][1]=h[x];
	for(int i=head[x];i;i=data[i].next)
	{
		dfs(data[i].to);
		for(int j=now[x];j>=0;j--)
			for(int k=0; k<=now[data[i].to]; k++)
				f[x][j+k][0]=min(f[x][j+k][0],f[data[i].to][k][0]+f[x][j][0]),
				f[x][j+k][1]=min(f[x][j+k][1],f[data[i].to][k][1]+f[x][j][1]),
				f[x][j+k][1]=min(f[x][j+k][1],f[data[i].to][k][0]+f[x][j][1]);
		now[x]+=now[data[i].to]; 
	}
}


int main()
{
 	freopen("815C.in","r",stdin);
// 	freopen("815C.out","w",stdout);
	int n=read(),m=read();
	h[1]=(w[1]=read())-(h[1]=read());
	memset(f,0x3f,sizeof(f));
	for(int i=2;i<=n;h[i]=(w[i]=read())-read(),init(read(),i),i++);
	dfs(1);
	for(int i=n;i>=0;i--)
		if(f[1][i][0]<=m||f[1][i][1]<=m)
			return printf("%d",i),0;

	fclose(stdin);
	fclose(stdout);
 	return 0;
}