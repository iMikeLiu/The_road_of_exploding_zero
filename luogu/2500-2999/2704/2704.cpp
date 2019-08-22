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
#define MAXN 111
int po[MAXN];
int cann[MAXN];
int f[101][1101][1101];
#define popcount __builtin_popcount
inline char getc(){char a;scanf("\n%c",&a);return a;};



int main()
{
 	freopen("2704.in","r",stdin);
// 	freopen("2704.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int cases=1<<m;
	for(int i=1;i<=n;i++)
		for(int j=m-1;j>=0;j--)
			if(getc()=='H')
				po[i]+=(1<<j);
//	debugzu(shanpo,1,n+1);
	int okcases=0;
	for(int i=0;i<cases;i++)
		if(!((i&(i<<2))||(i&(i<<1))))
			cann[++okcases]=i;
	for(int i=1;i<=okcases;i++)
	{
		if(!(cann[i]&po[1]))
			f[1][0][cann[i]]=popcount(cann[i]);
		if(!(cann[i]&po[2]))
			f[2][0][cann[i]]=popcount(cann[i]);
	}		
	for(int i=1;i<=okcases;i++)
		for(int j=1;j<=okcases;j++)
			if(!((cann[i]&po[1])||(cann[j]&po[2])||(cann[i]&cann[j])))
				f[2][cann[i]][cann[j]]=popcount(cann[i])+popcount(cann[j]);	

	for(int i=3;i<=n;i++)
		for(int j=1;j<=okcases;j++)
			if(!(cann[j]&po[i]))
				for(int k=1;k<=okcases;k++)
					if(!((cann[k]&po[i-1])||(cann[j]&cann[k])))
						for(int l=1;l<=okcases;l++)
							if(!((cann[l]&po[i-2])||(cann[k]&cann[l])||(cann[j]&cann[l])))
								f[i][cann[k]][cann[j]]=max(f[i][cann[k]][cann[j]],f[i-1][cann[l]][cann[k]]+popcount(cann[j]));
	int maxx=0;
	for(int i=1;i<=okcases;i++)
		for(int j=1;j<=okcases;j++)
			maxx=max(f[n][cann[i]][cann[j]],maxx);
	printf("%d\n",maxx);
				
	fclose(stdin);
	fclose(stdout);
 	return 0;
}
