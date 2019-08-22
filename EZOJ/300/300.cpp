#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<queue>
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
I char reads()
{
	char c;
	for (;!((c=getchar())=='.'||c=='#'););;
	return c;	
}
#define MAXN 60
bool mapp[MAXN][MAXN];
int f[MAXN][MAXN],d[MAXN][MAXN][MAXN][MAXN];
struct node{int x,y;};
int x,y;
I int gd(int x1,int y1,int x2,int y2)
{
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
I bool check(int i,int j,int x,int y,int r)
{
	int d1=gd(i-1,j-1,x,y);
	int d2=gd(i-0,j-1,x,y);
	int d3=gd(i-1,j-0,x,y);
	int d4=gd(i-0,j-0,x,y);
	return ((d1>=r&&d2>=r&&d3>=r&&d4>=r)||(d1<=r&&d2<=r&&d3<=r&&d4<=r));
}
I void bfs()
{
	queue<node> q;
	q.push(node{0,0});
	f[0][0]=1;
	while(!q.empty())
	{
		node tmp=q.front();
		int xx=tmp.x,yy=tmp.y;
		q.pop();
		for(int i=0;i<=x;i++)
			for(int j=0;j<=y;j++)
				if(f[i][j]==0&&(d[xx][yy][i][j]))
					f[i][j]=f[xx][yy]+1,q.push(node{i,j});
	}	
}
int main()
{
	freopen("300.in","r",stdin);
//	freopen("300.out","w",stdout);
	x=read(),y=read();
	for(int xx=1;xx<=x;xx++)
		for(int yy=1;yy<=y;yy++)
			mapp[xx][yy]=(reads()=='.'?0:1);
//	debugerzu(mapp,0,n,0,m);
	for(int r=1,nn=min(x,y);r<=nn;r++)
		for(int xx=0;xx<=x;xx++)
			for(int yy=0;yy<=y;yy++)
			{
				if(xx-r>=0&&yy-r>=0)
				{
					bool flag=true;
					for(int i=xx-r+1;i<=xx&&flag;i++)
						for(int j=yy-r+1;j<=yy&&flag;j++)
							if(mapp[i][j])
								flag&=check(i,j,xx,yy,r*r);
					d[xx][yy-r][xx-r][yy]|=flag;
					d[xx-r][yy][xx][yy-r]|=flag;
				}
				if(xx-r>=0&&yy+r<=y)
				{
					bool flag=true;
					for(int i=xx-r+1;i<=xx&&flag;i++)
						for(int j=yy+1;j<=yy+r&&flag;j++)
							if(mapp[i][j])
								flag&=check(i,j,xx,yy,r*r);
					d[xx][yy+r][xx-r][yy]|=flag;
					d[xx-r][yy][xx][yy+r]|=flag;
				}				
				if(xx+r<=x&&yy-r>=0)				
				{
					bool flag=true;
					for(int i=xx+1;i<=xx+r&&flag;i++)
						for(int j=yy-r+1;j<=yy&&flag;j++)
							if(mapp[i][j])
								flag&=check(i,j,xx,yy,r*r);
					d[xx][yy-r][xx+r][yy]|=flag;
					d[xx+r][yy][xx][yy-r]|=flag;
				}
				if(xx+r<=x&&yy+r<=y)
				{
					bool flag=true;
					for(int i=xx+1;i<=xx+r&&flag;i++)
						for(int j=yy+1;j<=yy+r&&flag;j++)
							if(mapp[i][j])
								flag&=check(i,j,xx,yy,r*r);
					d[xx][yy+r][xx+r][yy]|=flag;
					d[xx+r][yy][xx][yy+r]|=flag;
				}
			}
	bfs();
//	debugerzu(mapp,0,x,0,y); 
//	debugerzu(f,0,x,0,y); 
//	debugerzu(d[0][0],0,x,0,y); 
	if(f[x][y]>0)
		cout<<f[x][y]-1;
	else
		cout<<-1;
	fclose(stdin);
	fclose(stdout);
 	return 0;
}

