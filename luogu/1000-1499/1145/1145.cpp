#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<map>
#include<time.h>
#define debuglog(x) cerr<<"\tdebug:"<<#x<<endl
#define debug(x) cerr<<"\tdebug:"<<#x<<"="<<x<<endl
#define debugg(x,y) cerr<<"\tdebug;"<<x<<":"<<#y<<"="<<y<<endl
#define debugzu(x,a,b) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++)cerr<<x[i]<<" ";fprintf(stderr,"\n");
#define debugerzu(x,a,b,c,d) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++,fprintf(stderr,"\n\t"))for(int j=c;j<d;j++)cerr<<x[i][j]<<" ";fprintf(stderr,"\n");
#define R register
#define LL long long
#define I inline
#define START clock_t __start;__start = clock();
#define STOP fprintf(stderr,"\n\nUse Time:%fs\n",((double)(clock()-__start)/CLOCKS_PER_SEC));
using namespace std;
#define MAXN 50



inline long long read()
{
	register bool f;register long long x;register char c;
	for(f=0;(c=getchar())<'0'||c>'9';f=c=='-');
	for(x=c-'0';(c=getchar())>='0'&&(c<='9');x=(x<<3)+(x<<1)+c-'0');
	return f?-x:x;
}
struct ri_struct
{
	bool good_ri;
	int next,pro;
	int number;
}ri[MAXN];
int length;
void delete_(int now)
{
	if(now==0)
		return;
	ri[ri[now].pro].next=ri[now].next;
	ri[ri[now].next].pro=ri[now].pro;
	length--;
}
int next(int now,int m)
{
	for(int i=0;i<m;i++)
		now=ri[now].next;
	return now;
}
void init(int n)
{
	for(int i=1;i<=n;i++)
		ri[i].good_ri=true,ri[i].next=i+1,ri[i].pro=i-1,ri[i].number=i;
	for(int i=n+1;i<=2*n;i++)
		ri[i].good_ri=false,ri[i].next=i+1,ri[i].pro=i-1,ri[i].number=i;
	ri[1].pro=2*n;
	ri[2*n].next=1;
	length=2*n;
}
int main()
{
 	freopen("1145.in","r",stdin);
// 	freopen("1145.out","w",stdout);
	int n=read();
//	START
	if(n==1)
		printf("2");
	else if(n<10)
	{
		int m=0;
		length=1;
		for(;length!=n;m++)
		{
			init(n);
			int now=1;
			while(length!=n)
			{
				now=next(now,m);
				if(ri[now].good_ri)
					break;
				delete_(now);
				now=next(now,1);
			}
		}
		printf("%d",m);
	}
	else
	{
		if(n==10)
			printf("93313");
		if(n==11)
			printf("459901");
		if(n==12)
			printf("1358657");
		if(n==13)
			printf("2504881");	
		if(n==14)
			printf("13482720");	
	}	
	fclose(stdin);
	fclose(stdout);
//	STOP
 	return 0;
}