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
#define MAXN 2011
char a[MAXN],b[MAXN];
I LL read()
{
	R LL x;R bool f;R char c;
	for (f=0; (c=getchar())<'0'||c>'9'; f=c=='-');
	for (x=c-'0'; (c=getchar())>='0'&&c<='9'; x=(x<<3)+(x<<1)+c-'0');
	return f?-x:x;
}
LL dp[MAXN][MAXN];
int main()
{
 	freopen("2453.in","r",stdin);
// 	freopen("2453.out","w",stdout);
	scanf("%s%s",a,b);
	LL _d=read(),_r=read(),_c=read(),_i=read(),_t=read();
//	debug(_d);debug(_r);debug(_c);debug(_i);debug(_t);
	int a_len=strlen(a),b_len=strlen(b);
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=1;
	for(int i=0;i<=a_len;i++)
	{
		for(int j=0;j<=b_len;j++)
		{
			dp[i+1][j]=min(dp[i+1][j],dp[i][j]+_d);
			if(a[i]==b[j])
				dp[i+1][j+1]=min(dp[i+1][j+1],_c+dp[i][j]);
			dp[i][j+1]=min(dp[i][j+1],_i+dp[i][j]);
			dp[i+1][j+1]=min(dp[i+1][j+1],_r+dp[i][j]);
			if(a[i]==b[j+1]&&a[i+1]==b[j])
				dp[i+2][j+2]=min(dp[i+2][j+2],dp[i][j]+_t);
		}
		dp[a_len][b_len]=min(dp[a_len][b_len],dp[i][b_len]+_d*(a_len-i)-1);
	}
	cout<<dp[a_len][b_len];
//	debugerzu(dp,0,a_len+1,0,a_len+1);
	fclose(stdin);
	fclose(stdout);
 	return 0;
}
