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
char a[2003],b[2003];
int k,la,lb;
int f[2003][2003];

int main()
{
 	freopen("1279.in","r",stdin);
// 	freopen("1279.out","w",stdout);
	cin>>a>>b>>k;
	la=strlen(a),lb=strlen(b);
	for(int i=1;i<=la;i++)
		f[i][0]=i*k;
	for(int i=1;i<=lb;i++)
		f[0][i]=i*k;
	for(int i=1;i<=la;i++)
		for(int j=1;j<=lb;j++)
			f[i][j]=min(min(f[i-1][j],f[i][j-1])+k,f[i-1][j-1]+abs(a[i-1]-b[j-1]));
	cout<<f[la][lb];
	fclose(stdin);
	fclose(stdout);
 	return 0;
}