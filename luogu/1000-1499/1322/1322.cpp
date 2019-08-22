#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<map>
#define debuglog(x) cerr<<"\tdebug:"<<#x<<endl
#define debug(x) cerr<<"\tdebug:"<<#x<<"="<<x<<endl
#define debugg(x,y) cerr<<"\tdebug;"<<x<<":"<<#y<<"="<<y<<endl
#define debugzu(x,a,b) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++)cerr<<x[i]<<" ";fprintf(stderr,"\n");
#define debugerzu(x,a,b,c,d) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++,fprintf(stderr,"\n\t"))for(int j=c;j<d;j++)cerr<<x[i][j]<<" ";fprintf(stderr,"\n");
#define R register
#define LL long long
#define I inline
using namespace std;
int x=0;
LL dfs()
{
	LL n,now=0;
	char cmd[10];
	x++;
	while(1)
	{
		scanf("%s%lld",cmd,&n);
		if(cmd[0]=='R')
			 ((char)getchar()),now+=(n*dfs());
		else if(cmd[0]=='F')
			now+=n;
		else if(cmd[0]=='B')
			now-=n;
		else if(cmd[0]==']'||cmd[0]==0)
			break;
		cmd[0]=0;n=0;
	}
	x--;
	return now;
}
inline LL myabs(LL n){return n>0?n:(-n);}
int main()
{
 	freopen("1322.in","r",stdin);
// 	freopen("1322.out","w",stdout);
	cout<<myabs(dfs());
	fclose(stdin);
	fclose(stdout);
 	return 0;
}
