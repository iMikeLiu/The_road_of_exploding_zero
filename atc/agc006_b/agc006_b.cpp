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
#define MAXN 100011
int a[MAXN];



int main()
{
 	freopen("agc006_b.in","r",stdin);
// 	freopen("agc006_b.out","w",stdout);
    int n=read(),x=read(),t=1;
    if(x==1||x==2*n-1)
		return printf("No\n"),0;
    printf("Yes\n");
    for(int i=1;i<n-1;i++)
    {
        while(t==x||t==x-1||t==x+1)
			t++;
        printf("%d\n",t++);
    }
    printf("%d\n%d\n%d\n",x-1,x,x+1);
    for(int i=1;i<n-1;i++)
    {
        while(t==x||t==x-1||t==x+1)
			t++;
        printf("%d\n",t++);
    }
	fclose(stdin);
	fclose(stdout);
 	return 0;
}