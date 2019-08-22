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




int d[105][105][2];
int main()
{
 	freopen("6570.in","r",stdin);
// 	freopen("6570.out","w",stdout);
	int n=read(),c=read();
    for(int i=1;i<=n;i++)
    {
    	int a=read();
    	d[a][0][0]=1;
    	for(int j=1;j<=c;j++)
    	{
    		if(j!=a)
    		{
    			if(d[j][0][0]>0)
    				d[j][a][1]=max(d[j][a][1],d[j][0][0]+1);
    			if(d[a][j][1]>0)
    				d[a][j][0]=max(d[a][j][0],d[a][j][1]+1);
    			if(d[j][a][0]>0)
    				d[j][a][1]=max(d[j][a][1],d[j][a][0]+1);
			}
		}
	}
	int maxn=0;
	for(int i=1;i<=c;i++)
		for(int j=1;j<=c;j++)
			if(i!=j)
				maxn=max(maxn,max(d[i][j][0],d[i][j][1]));
	printf("%d\n",maxn);	
	fclose(stdin);
	fclose(stdout);
 	return 0;
}