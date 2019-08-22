#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<map>
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
	R LL x;R bool f;R char c;
	for (f=0; (c=getchar())<'0'||c>'9'; f=c=='-');
	for (x=c-'0'; (c=getchar())>='0'&&c<='9'; x=(x<<3)+(x<<1)+c-'0');
	return f?-x:x;
}
int main()
{
 	freopen("1664.in","r",stdin);
// 	freopen("1664.out","w",stdout);
    int n,t=0,d=0,m=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
		if(read())
		{
			if(m>0)
				d-=pow(2,m-1);
			d=max(d,0);
			t++,d++;
			m=0;
			if(d>=3)
				t++;
			if(d>=7)
				t++;
			if(d>=30)
				t++;
			if(d>=120)
				t++;
			if(d>=365)
				t++;
		}
		else
			m++;
	}		
    printf("%d",t);

	fclose(stdin);
	fclose(stdout);
 	return 0;
}
