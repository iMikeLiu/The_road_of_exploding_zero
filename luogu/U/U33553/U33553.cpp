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
#define MAXN 30011
struct feiji
{
	int fa,d_to_fa;
}feijis[MAXN];
int num[MAXN];
void init()
{
	for(int i=0;i<MAXN;i++)
		feijis[i].fa=i,feijis[i].d_to_fa=0,num[i]=1;
}
int getfa(int i)
{
	if(feijis[i].fa==i)
		return i;
	int fi=getfa(feijis[i].fa);
	feijis[i].d_to_fa+=feijis[feijis[i].fa].d_to_fa;	
	return feijis[i].fa=fi;
}
void bing(int a,int b)
{
	int fa=getfa(a),fb=getfa(b);
	if(fa==fb)
		return;
	feijis[fa].d_to_fa+=num[fb];
	feijis[fa].fa=fb;
	num[fb]+=num[fa];
	num[fa]=0;
}
int find(int a,int b)
{
	int fa=getfa(a),fb=getfa(b);
	if(fa!=fb)
		return -1;
	return abs(feijis[a].d_to_fa-feijis[b].d_to_fa)-1;
}
char readc()
{
	R char c;
	for(;((c=getchar())<'a'||c>'z')&&(c<'A'||c>'Z'););
	return c;
}
I LL read()
{
	R LL x;R bool f;R char c;
	for (f=0; (c=getchar())<'0'||c>'9'; f=c=='-');
	for (x=c-'0'; (c=getchar())>='0'&&c<='9'; x=(x<<3)+(x<<1)+c-'0');
	return f?-x:x;
}
int main()
{
 	freopen("U33553.in","r",stdin);
// 	freopen("U33553.out","w",stdout);
	init();
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		if(readc()=='M')
			bing(read(),read());
		else
			printf("%d\n",find(read(),read()));
	}

	fclose(stdin);
	fclose(stdout);
 	return 0;
}
