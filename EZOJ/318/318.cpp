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
using namespace std;
typedef struct 
{
	int i,j;
}point;
typedef struct 
{
	int i,j,lu,zuoyou;
}pointp;
char data[111][111]={'#'};
point fang[4]={{1,0},{-1,0},{0,1},{0,-1}};
pointp duilie[10000000];
int head=0,tail=0;
int bfs()
{
	while(head>tail)
	{
		if(data[duilie[tail].i][duilie[tail].j]=='E')
			return tail;
		for(int i=0;i<4;i++)
		{
			int ii=duilie[tail].i+fang[i].i;
			int jj=duilie[tail].j+fang[i].j;
			if(data[ii][jj]==' '||data[ii][jj]=='E')
			{
				duilie[head].i=ii;
				duilie[head].j=jj;
				duilie[head].zuoyou=duilie[tail].zuoyou;
				duilie[head].lu=duilie[tail].lu+1;
				head++;
				if(fang[i].i!=0)
					duilie[head].zuoyou++;
			}
		}
		tail++;
	}
	if(data[duilie[tail].i][duilie[tail].j]=='E')
		return tail;
	return 0;
}




int main()
{
 	freopen("318.in","w",stdin);
 	freopen("318.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		double r;int n,m;
		cin>>r>>n>>m;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				scanf("%c",&data[i][j]);
				if(data[i][j]=='S')
				{
					duilie[head].i=i;
					duilie[head].j=j;
					duilie[head].lu=0;
					duilie[head].zuoyou=0;
					head++;
				}
			}
		}
		int ansp=bfs();
		int lu=duilie[ansp].lu;
		int zuoyou=duilie[ansp].zuoyou;
		printf("%.5f\n",(lu-zuoyou)/(r-zuoyou));
	}

	fclose(stdin);
	fclose(stdout);
 	return 0;
}


