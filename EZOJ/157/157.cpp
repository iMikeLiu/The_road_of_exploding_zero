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
int a[1111][1111]={1};
int q[1000000][3];
int f[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int main()
{
 	freopen("157.in","r",stdin);
 	freopen("157.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
		a[i][0]=a[0][i]=1,q[i][2]=1;
	for(int i=0;i<1000000;i++)
		q[i][2]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%1d",&a[i][j]);
	int x1,x2,y1,y2;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	int head=0,tail=0;
	q[head][0]=x1;
	q[head][1]=y1;
	for(;;)
	{
		for(int i=0;i<4;i++)
		{
			int x3=q[tail][0]+	f[i][0];
			int y3=q[tail][1]+	f[i][1];
			if(a[x3][y3]==0&&x3>=0&&y3>=0)
			{
				head++;
				if(head>1000000-10)
					head=0;
				q[head][0]=x3;
				q[head][1]=y3;
				a[x3][y3]=1;
				q[head][2]=q[tail][2]+1;
				if(x3==x2&&y3==y2)
				{
					cout<<q[tail][2];
					return 0;
				}
			}	
		}
		tail++;
	}
 	return 0;
}
