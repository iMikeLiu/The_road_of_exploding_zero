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
#define MAXN 111
char data[MAXN][MAXN];
char ans[MAXN][MAXN];
int fangxiang[][2]{{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
I char readc()
{
	char c;
	for(;((c=getchar())<'a'||c>'z')&&(c<'A'||c>'Z'););
	return c;
}
char mubiao[]={"yizhong"};
bool dfs(int num,int fang,int i,int j)
{
	if(num==6)
	{
		if(data[i][j]==mubiao[num])
		{
			ans[i][j]=mubiao[num];
			return true;
		}
		else
			return false;
	}
	if((data[i][j]==mubiao[num])&&dfs(num+1,fang,i+fangxiang[fang][0],j+fangxiang[fang][1]))
	{
		ans[i][j]=mubiao[num];
		return true;
	}
	else
		return false;
}


int main()
{
 	freopen("1101.in","r",stdin);
 //	freopen("1101.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			data[i][j]=readc(),ans[i][j]='*';
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(data[i][j]=='y')
				for(int k=0;k<8;k++)
					dfs(0,k,i,j);
	for(int i=0;i<n;i++,printf("\n"))
		for(int j=0;j<n;j++)
			printf("%c",ans[i][j]);
	fclose(stdin);
	fclose(stdout);
 	return 0;
}

