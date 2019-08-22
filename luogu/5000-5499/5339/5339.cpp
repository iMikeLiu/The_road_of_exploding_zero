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
#define p 998244353
U LL qpow(U LL a,U LL b)
{
	U LL r=1;
	while(b)
	{
		if(b&1)
			r=(r*a)%p;
		b>>=1;
		a=(a*a)%p;
	}
	return r;
}
int f[1010][300];
LL sum[300],func[1010],inv[1010];
int cnt[1010];



int main()
{
 	freopen("5339.in","r",stdin);
// 	freopen("5339.out","w",stdout);
    int n=read(),a=read(),b=read(),c=read(),d=read();
    func[0]=1;
    f[0][0]=1;
    for(int i=1;i<=n;++i)
    {
        func[i]=func[i-1]*i%p;
        f[i][0]=1;
        for(int j=1;j<=i/4;++j)
        {
            sum[j-1]=(sum[j-1]+f[i-4][j-1])%p;
            f[i][j]=sum[j-1];
        }
    }
    inv[n]=qpow(func[n],p-2);
    for(int i=n-1;i>=0;--i)
        inv[i]=inv[i+1]*(i+1)%p;
    int k=min(a,min(b,min(c,d))),ans=0;
    for(int i=0,tot=n;i<=k&&i<=n/4;i++,a--,b--,c--,d--,tot-=4)
    {
        memset(cnt,0,sizeof(cnt));
        long long op=0;
        for(int aa=0;aa<=a;++aa)
            for(int bb=0;bb<=b;++bb)
                cnt[aa+bb]=(cnt[aa+bb]+inv[aa]*inv[bb])%p;
        for(int cc=0;cc<=c;++cc)
            for(int dd=0;dd<=d&&cc+dd<=tot;++dd)
                op=(op+cnt[tot-cc-dd]*inv[cc]%p*inv[dd])%p;
		op=op*func[tot]%p;
        if(i&1)
            ans=(ans+p-op*f[n][i]%p)%p;
		else
            ans=(ans+op*f[n][i]%p)%p;
    }
    printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
 	return 0;
}