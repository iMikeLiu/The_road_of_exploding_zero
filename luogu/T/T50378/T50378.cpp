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
int ss[20],tt[20];



int main()
{
 	freopen("T50378.in","r",stdin);
//	freopen("T50378.out","w",stdout);
	int t=read();
	while(t--)
	{
		int l=read(),r=read();
		int s=read();
		for(int i=0;i<s;ss[i]=read(),i++);
		debugzu(ss,0,s);
		int t=read();
		for(int i=0;i<t;tt[i]=read(),i++);
		debugzu(tt,0,t);
		LL ans=0;
		for(int i=l;i<=r;i++)
		{
			char buf[100];
			sprintf(buf,"%d",i);
			bool flag=true;
			for(int j=0;buf[j]&&flag;j++)
			{
				for(int k=0;k<s&&flag;k++)
					if(buf[j]==ss[k])
						flag=false;
				for(int k=0;k<t&&flag;k++)
					if(buf[j]==tt[k])
						flag=false;		
			}
			if(flag)
				ans+=i;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
 	return 0;
}