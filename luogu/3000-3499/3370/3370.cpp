#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<map>
#define debug(x) cerr<<"\tdebug:"<<#x<<"="<<x<<endl
#define debugg(x,y) cerr<<"\tdebug;"<<x<<":"<<#y<<"="<<y<<endl
#define debugzu(x,a,b) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++)cerr<<x[i]<<" ";fprintf(stderr,"\n");
#define debugerzu(x,a,b,c,d) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++,fprintf(stderr,"\n\t"))for(int j=c;j<d;j++)cerr<<x[i][j]<<" ";fprintf(stderr,"\n");
#define R register
#define LL long long
#define I inline
using namespace std;
#define MAXM 1511
char s[MAXM];
#define MAXN 10011
#define BASE 131
#define HA 712110022320020711
#define HA2 320020711
unsigned LL haxi(char s[])
{
    int len=strlen(s);
    unsigned LL ans=0;
    for (int i=0;i<len;i++)
		ans=(ans*(unsigned LL)BASE+(unsigned LL)s[i])%HA+233317;
    return ans;
}
unsigned LL f[MAXN];


int main()
{
 	freopen("3370.in","r",stdin);
// 	freopen("3370.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%s",s),(f[i]=haxi(s));
    sort(f,f+n);
	int ans=1;
    for(int i=0;i<n-1;i++)
        if(f[i]!=f[i+1])
			ans++;
    printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
 	return 0;
}
