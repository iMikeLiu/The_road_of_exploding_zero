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
#define MAXN 400011
int w[MAXN];
int b[MAXN];



int main()
{
 	freopen("855.in","r",stdin);
 	freopen("855.out","w",stdout);
	int n=read();
	bool flag=true;
	for(int i=1;i<=n-1;b[i]=read(),flag&=(b[i]==i),i++);
	for(int i=1;i<=n;w[i]=read(),i++);
	if(flag==1)
	{
		for(int i=1;i<=n;i++)
		{
			int ans=0;
			for(int j=1,maxx=0;j<i;j++,ans+=maxx,maxx=0)
				for(int k=j;k<=i;k++)
					maxx=max(maxx,w[k]);
			ans+=w[i];
			for(int j=i+1,maxx=0;j<=n;j++,ans+=maxx,maxx=0)
				for(int k=i;k<=j;k++)
					maxx=max(maxx,w[k]);		
			printf("%d ",ans);
		}
	}
	else
	{
		
	}
	
	
	

	fclose(stdin);
	fclose(stdout);
 	return 0;
}