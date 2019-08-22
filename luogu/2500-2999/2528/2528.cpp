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
long long f[30][300];
int ans[30];



int main()
{
 	freopen("2528.in","r",stdin);
// 	freopen("2528.out","w",stdout);
	int n=read(),t=read();
	if(t==0)
	{
		cout<<1<<endl;
		for(int i=1;i<=n;printf("%d ",i),i++);
		return 0;
	}
    f[1][0]=f[2][0]=f[2][1]=1;
	for(int i=3;i<=n;i++)
		for(int j=0;j<=i*(i-1)/2;j++)
			for(int k=0;k<i;k++)
				if(j>=k)
					f[i][j]+=f[i-1][j-k];
	cout<<f[n][t]<<endl;
	int p=0;
	for(int i=1;i<=n;i++)
		ans[i]=i;
	for(int i=n-1;i>=1;i--)
		for(int j=n;j>i;j--)
		{
			p++;
			swap(ans[i],ans[j]);
			if(p==t)
			{
				for(int i=1;i<=n;i++)
					cout<<ans[i]<<' ';
				return 0;
			}
		}
	fclose(stdin);
	fclose(stdout);
 	return 0;
}