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
#define ha 1000000007;
long long jz[3][3],tmp[3][3],ans[3],base[3][3];
long long n;
void zc()
{
    tmp[0][0]=base[0][0];
    tmp[0][1]=base[0][1];
    tmp[1][0]=base[1][0];
    tmp[1][1]=base[1][1];
    base[0][0]=(tmp[0][0]*tmp[0][0]+tmp[0][1]*tmp[1][0])%ha;
    base[0][1]=(tmp[0][0]*tmp[0][1]+tmp[0][1]*tmp[1][1])%ha;
    base[1][0]=(tmp[1][0]*tmp[0][0]+tmp[1][1]*tmp[1][0])%ha;
    base[1][1]=(tmp[1][0]*tmp[0][1]+tmp[1][1]*tmp[1][1])%ha;
}
void jc()
{
    tmp[0][0]=jz[0][0];
    tmp[0][1]=jz[0][1];
    tmp[1][0]=jz[1][0];
    tmp[1][1]=jz[1][1];
    jz[0][0]=(tmp[0][0]*base[0][0]+tmp[0][1]*base[1][0])%ha;
    jz[0][1]=(tmp[0][0]*base[0][1]+tmp[0][1]*base[1][1])%ha;
    jz[1][0]=(tmp[1][0]*base[0][0]+tmp[1][1]*base[1][0])%ha;
    jz[1][1]=(tmp[1][0]*base[0][1]+tmp[1][1]*base[1][1])%ha;
}
void ksm()
{
    long long t=n;
    while(t>0)
    {
        if (t&1) 
        {
            jc();
        }
        zc();
        t>>=1;
    }
} 
int main()
{
 	freopen("1962.in","r",stdin);
// 	freopen("1962.out","w",stdout);
    jz[0][0]=jz[1][1]=1;jz[1][0]=jz[0][1]=0;
    base[0][0]=base[0][1]=base[1][0]=1;base[1][1]=0;
    ans[0]=ans[1]=1;
    cin>>n;
    n-=2;
    ksm();
    cout<<(jz[0][0]+jz[0][1])%ha;
	fclose(stdin);
	fclose(stdout);
 	return 0;
}
