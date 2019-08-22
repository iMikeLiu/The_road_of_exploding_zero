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
#include<queue>
using namespace std;
const int dx[]={0,1,0,-1};//сробвСио
const int dy[]={1,0,-1,0};
struct point
{
    int x,y,turn;
}_begin,_end,p;
queue<point> q;
int n,m,_map[101][101];
bool used[101][101]; 

int main()
{
    freopen("158.in","r",stdin);
//    freopen("158.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&_map[i][j]);
    scanf("%d%d%d%d",&_begin.x,&_begin.y,&_end.x,&_end.y);
    
    q.push(_begin);
    q.front().turn=0;  
    while(!q.empty())
    {
        for(int i=0;i<4;i++)
        {
            p.x=q.front().x+dx[i];  
            p.y=q.front().y+dy[i];            
			while(p.x>0&&p.x<=n&&p.y>0&&p.y<=m&&!_map[p.x][p.y]) 
            {
                if(!used[p.x][p.y])
                {
                    if(p.x==_end.x&&p.y==_end.y)
                    {
                        printf("%d\n",q.front().turn);
                        return 0;  
                    }  
                    used[p.x][p.y]=1;  
                    p.turn=q.front().turn+1;  
                    q.push(p);  
                }
                p.x+=dx[i];
                p.y+=dy[i];
            }  
        }  
        q.pop();
    }
}

