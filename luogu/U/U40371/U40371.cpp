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
const LL ha=1000000007;
int main()
{
 	freopen("U40371.in","r",stdin);
 	freopen("U40371.out","w",stdout);
	int t=read();
	for(int iii=0;iii<t;iii++)
	{
		LL l[5],r[5],b[5],ans=1;
		for(int i=1;i<=4;i++)
			l[i]=read(),r[i]=read(),b[i]=r[i]-l[i]+1,ans=ans*b[i]%ha;
		ans=ans-(max(0ll,(min(r[1],r[2])-max(l[1],l[2])+1))*1ll*b[3]%ha*b[4]%ha)-
				(max(0ll,(min(r[2],r[3])-max(l[2],l[3])+1))*1ll*b[1]%ha*b[4]%ha)-
				(max(0ll,(min(r[3],r[4])-max(l[3],l[4])+1))*1ll*b[1]%ha*b[2]%ha)-
				(max(0ll,(min(r[4],r[1])-max(l[4],l[1])+1))*1ll*b[2]%ha*b[3]%ha);
		ans%=ha;
		ans=ans+(max(0ll,min(r[1],min(r[2],r[3]))-max(l[1],max(l[2],l[3]))+1)*1ll*b[4]%ha)+
				(max(0ll,min(r[1],min(r[2],r[4]))-max(l[1],max(l[2],l[4]))+1)*1ll*b[3]%ha)+
				(max(0ll,min(r[1],min(r[3],r[4]))-max(l[1],max(l[3],l[4]))+1)*1ll*b[2]%ha)+
				(max(0ll,min(r[2],min(r[3],r[4]))-max(l[2],max(l[3],l[4]))+1)*1ll*b[1]%ha);
		ans%=ha;
		ans=ans+(max(0ll,min(r[1],r[2])-max(l[1],l[2])+1)*1ll*max(0ll,min(r[3],r[4])-max(l[3],l[4])+1)%ha)+
				(max(0ll,min(r[2],r[3])-max(l[2],l[3])+1)*1ll*max(0ll,min(r[1],r[4])-max(l[1],l[4])+1)%ha);
		ans%=ha;
		ans=ans-max(0ll,min(min(r[1],r[2]),min(r[3],r[4]))-max(max(l[1],l[2]),max(l[3],l[4]))+1)*1ll*3;
		ans=(ans%ha+ha)%ha;
		printf("%d\n",(int)ans);
	}
	

	fclose(stdin);
	fclose(stdout);
 	return 0;
}
