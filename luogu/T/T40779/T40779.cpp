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
string cmd;
char dir[100000];
struct zidianshu
{
	int txt[100];
	int mowei;
	bool dir;
}tree[1000];
int dangqian=1;
int total=0;
inline int chuli(char a)
{
	return a;
}
bool add(char* str)
{
	int now=1;
	while(*str)
	{
		int word=chuli(*str);
		if(word=='/')
		{
			printf("\t\tdir\n");
			tree[now].dir=true;
		}
		printf("\t\tNow adding:%c\n",*str);
		if(!tree[now].txt[word])//路径不存在
		{
			printf("\t\tNow adding new road:%c to %c\n",*(str-1),*str);
			tree[now].txt[word]=++dangqian;//新分配	
		}
		now= tree[now].txt[word];//下一步
		tree[now].mowei=true;
		str++;
	}
	if(tree[now].mowei!=0)
		return 0;
	tree[now].mowei=++total;
	return 1;
}
int find(char* str)
{
	int now=1;
	while(*str)
	{ 
		int word=chuli(*str);
		printf("\t\tNow finding:%c\n",*str);
		if(!tree[now].txt[word])//路径不存在
			return 0;
		now= tree[now].txt[word];//下一步 
		str++;
	}
	return now;
}
int main()
{
 	freopen("T40779.in","r",stdin);
// 	freopen("T40779.out","w",stdout);
	while(cin>>cmd)
	{
		int cnt=0;
		int start=0;
		char c;
		for (;((c=getchar())<'A'||c>'Z')&&(c<'a'||c>'z')&&c!='/';);
		dir[cnt++]=c;
		while((dir[cnt++]=getchar())!='\n');
		cnt--;
		dir[cnt-1]=0;
		if(dir[0]=='/')
			start=1;
		debug(cmd);
		debugzu((dir+start),0,cnt);
		if(cmd=="mkdir")
			add((char*)dir+start);
		if(cmd=="dog")
		{
			int now=find(dir+start);
			if(tree[now].dir==true||tree[now].mowei==true)
				printf("Yes\n");
			else
				printf("No\n");
				
		}
		
	}
	fclose(stdin);
	fclose(stdout);
 	return 0;
}
