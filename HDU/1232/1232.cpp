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
#define MAXN 1011
int father[MAXN];
int init(int n)
{
    int i;
	for(i=1;i<=n;i++)
		father[i]=i;
	return n;
}
int find(int x)
{
	while(father[x]!=x)
		x=father[x];
	return x;
}
void bing(int a,int b)
{
    int temp_a,temp_b;
	temp_a=find(a);
	temp_b=find(b);
	if(temp_a!=temp_b)
		father[temp_a]=temp_b;
}
int getans(int n)
{
    int i,sum=0;
    for(i=1;i<=n;++i)
        if(father[i]==i)
            ++sum;
    return sum;
}
int main()
{
 	freopen("1232.in","r",stdin);
// 	freopen("1232.out","w",stdout);
	int n,m;
	while(init(n=read()))
	{
		for(int i=0,m=read();i<m;bing(read(),read()),i++);
		printf("%d\n",getans(n)-1);
	}

	fclose(stdin);
	fclose(stdout);
 	return 0;
}