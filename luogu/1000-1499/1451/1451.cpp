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
int data[1000][1000];
int q[1000000][2];
int f[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void doone(int x,int y)
{
	int head=1,tail=0;
	q[head][0]=x;q[head][1]=y;
	do
	{
		tail++;
		for(int i=0;i<4;i++)
		{
			int xx=q[tail][0]+f[i][0];
			int yy=q[tail][1]+f[i][1];
			if(xx<0|yy<0)
				continue;
			if(!data[xx][yy])
				continue;
			head++;
			data[xx][yy]=0;
			q[head][0]=xx;q[head][1]=yy;
		}
	}while(head!=tail);
}

int main()
{
	int n,m,ans=0;
 	freopen("1451.in","r",stdin);
// 	freopen("1451.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			scanf("%1d",&data[i][j]);
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if(data[i][j])
				doone(i,j),ans++;
	cout<<ans;

 	return 0;
}

