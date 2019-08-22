#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<string>
using namespace std;
int r=0,c=0,data[110][110]={0},q[110][110]={0};
int step=0,t=0,ans=0; 
const int fangwei[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int dfs(int x,int y)
{
	if(q[x][y])return q[x][y];step=0;//ºÙ÷¶ 
	for(int i=0;i<4;i++)//4∑ΩœÚÀ—À˜ 
	{
		int x1,y1;
		x1=x+fangwei[i][0];
		y1=y+fangwei[i][1];
		if(data[x1][y1]<data[x][y]&&x1>=0&&x1<c&&y1>=0&&y1<r)
		{
			t=dfs(x1,y1);
			if(t>step)step=t;
		}
	}
	q[x][y]=step+1;  
    return q[x][y];  
}
int main()
{
	freopen("1434.in","r",stdin);
//	freopen("1434.out","w",stdout);
	scanf("%d%d",&r,&c);
	for(int a=0;a<r;a++)
	{
		for(int b=0;b<c;b++)
		{
			scanf("%d",&data[b][a]);
		}
	}
	for(int a=0;a<=r;a++)
	{
		for(int b=0;b<=c;b++)
		{
			int aaa=dfs(a,b); 
			if(aaa>ans)ans=aaa; 
		}
	}
	cout<<ans<<endl;
}
