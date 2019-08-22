#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<map>
#include<queue>
#define debuglog(x) cerr<<"\tdebug:"<<#x<<endl
#define debug(x) cerr<<"\tdebug:"<<#x<<"="<<x<<endl
#define debugg(x,y) cerr<<"\tdebug;"<<x<<":"<<#y<<"="<<y<<endl
#define debugzu(x,a,b) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++)cerr<<x[i]<<" ";fprintf(stderr,"\n");
#define debugerzu(x,a,b,c,d) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++,fprintf(stderr,"\n\t"))for(int j=c;j<d;j++)cerr<<x[i][j]<<" ";fprintf(stderr,"\n");
#define R register
#define LL long long
#define I inline
using namespace std;
I LL read()
{
	R LL x;R bool f;R char c;
	for (f=0; (c=getchar())<'0'||c>'9'; f=c=='-');
	for (x=c-'0'; (c=getchar())>='0'&&c<='9'; x=(x<<3)+(x<<1)+c-'0');
	return f?-x:x;
}
char mapp[1005][1005];
int n,m,cnt,ex,ey,ans=-1;
int dx[]={0,1,0,-1},dy[]={1,0,-1,0},vis[1005][1005];
struct did
{
	int x,y,f,l,t;	
	bool operator <(did a) const
	{
		return t<a.t;
	}
	bool operator >(did a) const
	{
		return t>a.t;
	}
};
priority_queue<did,vector<did>,greater<did> >q;
int tag[1005][1005][2][2];
struct diddd
{
	int x,y;
}sukima[2000005];
inline void bfs()
{
	int js=0;
	while(!q.empty())
	{
		js++;
		int nx=q.top().x,ny=q.top().y,nt=q.top().t,nf=q.top().f,nl=q.top().l;
		q.pop();
		if(nx==ex&&ny==ey)
		{
			ans=nt;
			return;
		}
		for(int i=0;i<=3;i++)
		{
			int xx=nx+dx[i],yy=ny+dy[i],tt=nt+1,ff=nf,lll=nl;
			if(xx>=1&&xx<=n&&yy>=1&&yy<=m)
			{
				int bj=0,flag=0; 
				if((nl&&mapp[xx][yy]!='X')||((mapp[xx][yy]=='2'||mapp[xx][yy]=='3')&&nf)||mapp[xx][yy]=='0'||mapp[xx][yy]=='E')
					bj=1;
				else if(mapp[xx][yy]=='4')
					bj=ff=1;
				else if(mapp[xx][yy]=='5')
					tt+=5,bj=lll=1,flag=1;
				else if(mapp[xx][yy]=='2')
					tt+=3,bj=1;
				else if(mapp[xx][yy]=='3') 
					tt+=8,bj=1;
				else if(mapp[xx][yy]=='X'&&!tag[xx][yy][lll][ff])
				{
					tt++;
					for(int j=1;j<=cnt;j++)
					if(!(sukima[j].x==xx&&sukima[j].y==yy)&&!tag[sukima[j].x][sukima[j].y][lll][ff])
					{
						q.push(did{sukima[j].x,sukima[j].y,ff,lll,tt});
						tag[sukima[j].x][sukima[j].y][lll][ff]=1;
					}
					tt--;bj=1;
				}
				if(bj&&!tag[xx][yy][lll][ff]) 
					q.push(did{xx,yy,ff,lll,tt}),tag[xx][yy][lll][ff]=1;
				if(flag)
					q.push(did{xx,yy,ff,0,tt-5}),tag[xx][yy][lll][ff]=1;
			} 
		}   
	}
}




int main()
{
 	freopen("4872.in","r",stdin);
// 	freopen("4872.out","w",stdout);
	 scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			mapp[i][j]=getchar();
			while(!isdigit(mapp[i][j])&&!isalpha(mapp[i][j]))
				mapp[i][j]=getchar();
			switch(mapp[i][j])
			{
				case 'S':
					q.push(did{i,j,0,0,0});
					break;
				case 'E':
					ex=i;
					ey=j;
					break;
				case 'X':
					sukima[++cnt].x=i;
					sukima[cnt].y=j;
					break;
			}
		}
	}
    bfs();
    if(ans!=-1)
		cout<<ans<<endl;
    else
		cout<<"We want to live in the TouHou World forever"<<endl;
	fclose(stdin);
	fclose(stdout);
 	return 0;
}
