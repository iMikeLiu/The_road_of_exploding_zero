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
#define MAXN 80011
struct caozuo
{
	char c;
	int k;
}data[MAXN];
bool movee[MAXN]={false};

struct lianbiaobook
{
	int father,book;
}book[MAXN];
int lianbiaohead=0;
int now; //保存当前father，跳转 
int save[MAXN];//保存now 
bool didmove[MAXN]={false};

int main()
{
 	freopen("312.in","r",stdin);
// 	freopen("312.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("\n%c",&data[i].c);
		if(data[i].c!='s')
			scanf("%d",&data[i].k);
		if(data[i].c=='t')
			movee[data[i].k]=true;
	}
	for(int i=1;i<=n;i++)
	{
		if(movee[i])
			save[i]=now;
		if(data[i].c=='a')
		{
			lianbiaohead++;
			book[lianbiaohead].book=data[i].k;
			book[lianbiaohead].father=now;
			now=lianbiaohead; 
		}
		else if(data[i].c=='s')
		{
			now=book[now].father;
		}
		else if(data[i].c=='t'&&!didmove[i])
			didmove[i]=true,now=save[data[i].k];
		if(now==0)
			printf("-1\n");
		else
			printf("%d\n",book[now].book);		
	}

	fclose(stdin);
	fclose(stdout);
 	return 0;
}


