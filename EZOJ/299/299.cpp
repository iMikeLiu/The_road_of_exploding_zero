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
class bigint
{
	public:
		bigint();
		bigint(int);
		void print();
		friend bigint operator+(const bigint& x,const bigint& y);
		bigint operator * (int b);
		void operator = (int b);
	private:
		int s[1000];
};
bigint::bigint()
{
	memset(s,0,sizeof(s));
	s[0]=1;
}
bigint::bigint(int x)
{
	memset(s,0,sizeof(s));
	s[0]=1;
	s[1]=x;
	while (s[s[0]]>9)
	{
		s[s[0]+1]=s[s[0]]/10;
		s[s[0]++]%=10;
	}
}
void bigint::print()
{
	int i;
	for (i=s[0];i>0;--i)
		printf("%d",s[i]);
}
bigint operator+(const bigint& x,const bigint& y)
{
	bigint t;
	int i,h=0;
	if (x.s[0]>y.s[0])
		t.s[0]=x.s[0];
	else
		t.s[0]=y.s[0];
	for (i=1;i<=t.s[0];++i)
		h=h/10+x.s[i]+y.s[i],t.s[i]=h%10;
	while(h>9)
		h/=10,t.s[++t.s[0]]=h%10;
	return t;
}
bigint bigint::operator*(int b)
{
	int i,x=0;
	bigint t;
	t.s[0]=s[0];
	for (i=1;i<=s[0];++i)
		x=x/10+s[i]*b,t.s[i]=x%10;
	while (x>9)
		x/=10,t.s[++t.s[0]]=x%10;
	return t;
}
void bigint::operator=(int b)
{
	memset(s,0,sizeof(s));
	s[0]=1;s[1]=b;
	while (s[s[0]]>9)
		s[s[0]+1]=s[s[0]]/10,s[s[0]++]%=10;
}
bigint f[51][51];


int main()
{
 	freopen("299.in","r",stdin);
// 	freopen("299.out","w",stdout);
	int n=read(),k=read();
	if(k>n)
	{
		cout<<0<<endl;
		return 0;
	}
	f[0][0]=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<=k;j++)
		{
			f[i+1][j]=f[i][j]+f[i+1][j];
			if(j<k)
				f[i+1][j+1]=f[i][j]*(n-j)+f[i+1][j+1];
		}
	f[n][k].print();

	fclose(stdin);
	fclose(stdout);
 	return 0;
}