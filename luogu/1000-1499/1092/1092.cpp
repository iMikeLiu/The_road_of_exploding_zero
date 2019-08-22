#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<map>
#include<ctime>
#define debuglog(x) cerr<<"\tdebug:"<<#x<<endl
#define debug(x) cerr<<"\tdebug:"<<#x<<"="<<(x)<<endl
#define debugg(x,y) cerr<<"\tdebug;"<<(x)<<":"<<#y<<"="<<(y)<<endl
#define debugzu(x,a,b) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++)cerr<<x[i]<<" ";fprintf(stderr,"\n");
#define debugerzu(x,a,b,c,d) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++,fprintf(stderr,"\n\t"))for(int j=c;j<d;j++)cerr<<x[i][j]<<" ";fprintf(stderr,"\n");
#define R register
#define L long
#define LL long long
#define I inline
#define U unsigned
#define START clock_t __start=clock();
#define STOP fprintf(stderr,"\n\nUse Time:%fs\n",((double)(clock()-__start)/CLOCKS_PER_SEC));
using namespace std;
I LL read()
{
	R LL x;R bool f;R char c;
	for (f=0; (c=getchar())<'0'||c>'9'; f=c=='-');
	for (x=c-'0'; (c=getchar())>='0'&&c<='9'; x=(x<<3)+(x<<1)+c-'0');
	return f?-x:x;
}
#define maxn 30
int a[maxn],b[maxn],c[maxn];
int num[maxn],next_[maxn],n,cnt;
char s1[maxn],s2[maxn],s3[maxn];
bool used[maxn];
bool panduan()
{
	for(int i=n-1,x=0;i>=0;i--)
	{
		int A=num[a[i]],B=num[b[i]],C=num[c[i]];
		if((A+B+x)%n!=C)
			return false;
		x=(A+B+x)/n;
	}
	return true;
}
bool canprune()
{
	if(num[a[0]]+num[b[0]]>=n)
		return true;
	for(int i=n-1;i>=0;i--)
	{
		int A=num[a[i]],B=num[b[i]],C=num[c[i]];
		if(A==-1||B==-1||C==-1)
			continue;
		if((A+B)%n!=C&&(A+B+1)%n!=C)
			return true;
	}
	return false;
}
void print()
{
	for(int i=0;i<n;i++)
		printf("%d ",num[i]);
	exit(0);
}
void dfs(int x) 
{
	if(canprune()==true)
		return;
	if(x==n)
	{
		if(panduan()==true)
			print();
		return;
	}
	for(int i=n-1;i>=0;i--)
		if(used[i]==false)
		{
			num[next_[x]]=i;
			used[i]=true;
			dfs(x+1);
			num[next_[x]]=-1;
			used[i]=false;
		}
	return;
}
inline int id(char c)
{
	return c-'A';
}
void getnext(int x)
{
	if(used[x]==false)
	{
		used[x]=true;
		next_[cnt++]=x;
	}
	return;
}
int main()
{
 	freopen("1092.in","r",stdin);
// 	freopen("1092.out","w",stdout);
	scanf("%d",&n);
	scanf("%s%s%s",s1,s2,s3);
	for(int i=0;i<n;i++)
	{
		a[i]=id(s1[i]);
		b[i]=id(s2[i]);
		c[i]=id(s3[i]);
		num[i]=-1;
	}
	for(int i=n-1;i>=0;i--)
	{
		getnext(a[i]);
		getnext(b[i]);
		getnext(c[i]);
	}
	for(int i=0;i<n;i++)
		used[i]=false;
	dfs(0);

	fclose(stdin);
	fclose(stdout);
 	return 0;
}