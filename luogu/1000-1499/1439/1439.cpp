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
int a[100001],b[100001],mapp[100001],f[100001];




int main()
{
 	freopen("1439.in","r",stdin);
// 	freopen("1439.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),mapp[a[i]]=i;
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]),f[i]=0x7fffffff;
	int len=0;
	f[0]=0;
	for(int i=1;i<=n;i++)
	{
		int l=0,r=len,mid;
		if(mapp[b[i]]>=f[len])
			f[++len]=mapp[b[i]];
		else
		{
			while(l<r)
			{
				mid=(l+r)>>1;
				if(f[mid]>mapp[b[i]])
					r=mid;
				else
					l=mid+1;
			}
			f[l]=min(mapp[b[i]],f[l]);
		}
	}
	printf("%d",len);


	fclose(stdin);
	fclose(stdout);
 	return 0;
}
