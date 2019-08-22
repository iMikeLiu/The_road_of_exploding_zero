#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<map>
#include<queue>
#define debuglog(x) cerr<<"\tdebug:"<<#x<<endl
#define debug(x) cerr<<"\tdebug:"<<#x<<"="<<x<<endl
#define debugg(x,y) cerr<<"\tdebug;"<<x<<":"<<#y<<"="<<y<<endl
#define debugzu(x,a,b) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++)cerr<<x[i]<<" ";fprintf(stderr,"\n");
#define debugerzu(x,a,b,c,d) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++,fprintf(stderr,"\n\t"))for(int j=c;j<d;j++)cerr<<x[i][j]<<" ";fprintf(stderr,"\n");
#define R register
#define LL long long
#define I inline
using namespace std;
I LL read()
{
	R char c;R bool f;R LL x;
	for(f=0;(c=getchar())<'0'||c>'9';f=c=='-');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';x=(x<<3)+(x<<1)+c-'0');
	return f?-x:x;  	
}
#define MAXN 211
int data[MAXN];
int length;
struct lianbiao_struct
{
	int val;
	int next;
	int front;	
}lianbiao[MAXN];
void reset()
{
	lianbiao[0].val=-1;
	lianbiao[0].front=-1;
	length=0;
}
int push(int x)
{
	length++;
	lianbiao[length].val=x;
	lianbiao[length].next=-1;
	lianbiao[length-1].next=length;
	lianbiao[length].front=length-1;
	return length;
}
void update(int point,int x)
{
	lianbiao[point].val=x;
}
void delate(int point)
{
	lianbiao[lianbiao[point].front].next=lianbiao[point].next;
	lianbiao[lianbiao[point].next].front=lianbiao[point].front;
}
int main()
{
 	freopen("1390.in","r",stdin);
// 	freopen("1390.out","w",stdout);
	int t=read();
	while(t--)
	{
		int n=read();
		for(int i=0;i<n;i++)
			data[i]=read();
			
		
		
	}
	fclose(stdin);
	fclose(stdout);
 	return 0;
}
